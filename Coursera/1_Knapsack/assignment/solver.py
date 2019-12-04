#!/usr/bin/python
# -*- coding: utf-8 -*-

from collections import namedtuple
from queue import PriorityQueue
from queue import Queue
Item = namedtuple("Item", ['index', 'value', 'weight'])

def expandBest(items, n, C):
    count = 0
    que = PriorityQueue()
    (_, minValue, resConfig, relax) = relaxation(items, C)

    # Best Search
    # print(minValue ,resConfig, relax)
    que.put((-relax, (relax, [], Item(-1, 0, 0))))
    result = [minValue, resConfig]
    while not que.empty():
        count+=1
        (expect, config, current) = que.get()[1]

        # print(expect, config, current.index, current.value, current.weight)

        if current.index + 1 >= n:
            if(result[0] < current.value):
                result[0] = current.value
                result[1] = config
            continue

        i = items[current.index + 1]
        v = current.value
        w = current.weight
        #Take
        if w + i.weight <= C:
            que.put((-expect, (expect, config + [1], Item(i.index, v + i.value, w + i.weight))))

        #Doesn't take
        (index, minValue, resConfig, relax) = relaxation(items[(current.index+2):], C - current.weight)
        expect = current.value + relax
        if minValue > result[0]:
            result[0] = minValue
            result[1] = config + [0] + resConfig
        if expect > result[0]:
            que.put((-expect, (expect, config + [0], Item(i.index, v, w))))
    print("best1",count)
    return result

def expandBest2(items, n, C, factor):
    que = PriorityQueue()
    count = 0

    if factor != 1:
        items = list(map(lambda item: Item(item.index, item.value, item.weight / factor), items))
        C = C / factor
    items = sorted(items, key=lambda item: -item.value)
    minValue = findMinValue(items, n, C)
    items = sorted(items, key=lambda item: round(-item.value/item.weight, 6))
    (index, _, resConfig, relax) = relaxation(items, C)
    minValue = max([findMinValue(items, n, C), minValue], key=lambda v: v[0])

    # Best Search
    que.put((-relax, (relax, [0] * len(items), Item(0, 0, 0))))
    result = [minValue[0], minValue[1]]
    
    while not que.empty():
        count += 1
        (expect, config, current) = que.get()[1]
        if expect <= result[0]:
            continue
        nextIndex = current.index + 1
        currentIndex = current.index
        # print(expect, config, current.index, current.value, current.weight)

        if currentIndex >= n:
            if(result[0] < current.value):
                result[0] = current.value
                result[1] = config
            continue

        # Put to queue
        item = items[currentIndex]
        value = current.value
        weight = current.weight

        remain = C - weight
        minWeight = min(items[currentIndex:], key=lambda item: item.weight).weight
        if remain < minWeight:
            if value > result[0]:
                result[0] = value
                result[1] = config
            continue

        # Find new expectation
        newExpect = 0.0
        expConfig = [0] * n
        for index in range(nextIndex, n):
            if remain - items[index].weight > 0:
                newExpect += items[index].value
                remain -= items[index].weight
                expConfig[items[index].index] = 1
            else:
                if newExpect + value > result[0]:
                    result[0] = newExpect + value
                    result[1] = expConfig
                newExpect += remain/items[index].weight * items[index].value
                break
        newExpect += value

        # Take current
        if weight + item.weight <= C and expect > result[0]:
            config[item.index] = 1
            que.put((-expect, (expect, config[:], Item(nextIndex, value + item.value, weight + item.weight))))
            config[item.index] = 0

        # Doesn't take current
        if newExpect > result[0]:
            que.put((-newExpect, (newExpect, config[:], Item(nextIndex, value, weight))))
    print("best2",count)
    return (result[0], result[1])

def findMinValue(items, n, C):
    sums = []
    itemFirst = None
    itemLast = None
    for first in range(0, n):
        itemFirst = items[first]
        config = [0] * n
        sumList = [(0, 0)] * n
        if itemFirst.weight <= C:
            sumList[first] = (itemFirst.value, itemFirst.weight)
            config[itemFirst.index] = 1
        else:
            sumList = [(0, 0)] * n
        for last in range(first+1, n):
            itemLast = items[last]
            if sumList[last-1][1] + itemLast.weight <= C:
                sumList[last] = (sumList[last-1][0] + itemLast.value, sumList[last-1][1] + itemLast.weight)
                config[itemLast.index] = 1
            else:
                sumList[n-1] = sumList[last -1]
                break
        sums += [(sumList[n-1][0], config)]
    return max(sums, key=lambda s: s[0])

def expandStep(items, n, C):
    que = PriorityQueue()
    count = 0

    minWeight = min(items, key=lambda item: item.weight).weight
    items = sorted(items, key=lambda item: -item.weight)
    items = sorted(items, key=lambda item: -item.value)
    items = sorted(items, key=lambda item: item.value / (item.weight ** 2), reverse=True)
    minValue = findMinValue(items, n, C)
    print("min", minValue[0])
    items = sorted(items, key=lambda item: -item.value/item.weight)
    minValue = max([findMinValue(items, n, C), minValue], key=lambda v:v[0])
    (index, _, resConfig, relax) = relaxation(items, C)

    print("min", minValue[0])

    # Step Search
    que.put((0, relax, [0] * n, Item(0, 0, 0)))
    result = [minValue[0], minValue[1]]
    
    while not que.empty():
        count += 1
        pop = que.get()
        qcount = pop[0]
        expect = pop[1]
        config = pop[2]
        current = pop[3]
        
        nextIndex = current.index + 1
        currentIndex = current.index
        
        print(qcount, currentIndex, config)

        if expect <= result[0] or currentIndex >= n:
            if result[0] < current.value:
                result[0] = current.value
                result[1] = config
            continue

        # Put to queue
        item = items[currentIndex]
        value = current.value
        weight = current.weight

        remain = C - weight
        minWeight = min(items[currentIndex:], key=lambda item: item.weight).weight
        if remain < minWeight:
            if value > result[0]:
                result[0] = value
                result[1] = config
            continue
        
        # Take current
        if weight + item.weight <= C and expect > result[0]:
            config[item.index] = 1
            que.put((qcount, expect, config[:], Item(nextIndex, value + item.value, weight + item.weight)))
            config[item.index] = 0
        # Find new expectation
        newExpect = 0.0
        expConfig = [0] * n
        for index in range(nextIndex, n):
            if remain - items[index].weight > 0:
                newExpect += items[index].value
                remain -= items[index].weight
                expConfig[items[index].index] = 1
            else:
                if newExpect > result[0]:
                    result[0] = newExpect
                    result[1] = expConfig
                newExpect += remain/items[index].weight * items[index].value
                break
        newExpect += value
        # Doesn't take current
        if newExpect > result[0]:
            que.put((qcount + 1, newExpect, config[:], Item(nextIndex, value, weight)))
    print("step",count)
    return (result[0], result[1])

# least discrepancy search
def expandStepReviseConfig(items, n, C):
    que = PriorityQueue()
    count = 0

    items = sorted(items, key=lambda item: -item.value/item.weight)
    minValue = findMinValue(items, n, C)
    relax = relaxation(items, C)[3]
    # Step Search
    que.put((0, -relax, 0, Item(0, 0, 0), []))
    minConfig = []
    for i in range(len(minValue[1])):
        if minValue[1][i] == 1:
            minConfig += [i]
    result = [minValue[0], minConfig]

    minWeight = [0] * n
    minWeight[n-1] = items[n-1].weight
    for i in range(1, n):
        minWeight[n - i - 1] = min((minWeight[n - i], items[n - i - 1].weight))
    
    while not que.empty():
        count += 1
        (qcount, expect, _, current, config) = que.get()
        expect = -expect

        nextIndex = current.index + 1
        currentIndex = current.index

        # Put to queue
        value = current.value
        weight = current.weight

        remain = C - weight
        if expect <= result[0] or currentIndex >= n or remain < minWeight[currentIndex]:
            if result[0] < value:
                result[0] = value
                result[1] = config
            continue
        item = items[currentIndex]

        # Find new expectation
        newExpect = 0.0
        expConfig = []
        for index in range(nextIndex, n):
            if remain - items[index].weight > 0:
                newExpect += items[index].value
                remain -= items[index].weight
                expConfig += [items[index].index]
            else:
                if newExpect + value > result[0]:
                    result[0] = newExpect + value
                    result[1] = config + expConfig
                newExpect += remain/items[index].weight * items[index].value
                break
        newExpect += value

        # Take current
        if weight + item.weight <= C and expect > result[0]:
            que.put((qcount, -expect, ((expect - item.value)), Item(nextIndex, value + item.value, weight + item.weight), config+[item.index]))
        # Doesn't take current
        if newExpect > result[0]:
            que.put((qcount + 1, -newExpect, (newExpect - value), Item(nextIndex, value, weight), config))
    return (int(result[0]), list(map(lambda x: 1 if x in result[1] else 0, list(range(n)))))

def relaxation(sItems, C):
    if(len(sItems) == 0):
        return (0, 0, [], 0.0)

    minValue = 0
    relaxation = 0.0
    weight = 0.0

    resConfig = [0] * len(sItems)
    for index in range(len(sItems)):
        item = sItems[index]
        if weight + item.weight > C:
            relaxation += (C - weight)/item.weight * item.value
            break
        if weight + item.weight <= C:
            resConfig[index] = 1
            relaxation += item.value
            minValue += item.value
            weight += item.weight
    return (index, minValue, resConfig, relaxation)

def solve_it(input_data):
    # Modify this code to run your optimization algorithm

    # parse the input
    lines = input_data.split('\n')

    firstLine = lines[0].split()
    item_count = int(firstLine[0])
    capacity = int(firstLine[1])

    items = []

    for i in range(1, item_count+1):
        line = lines[i]
        parts = line.split()
        items.append(Item(i-1, int(parts[0]), int(parts[1])))

    # a trivial greedy algorithm for filling the knapsack
    # it takes items in-order until the knapsack is full
    # result = expandBest2(items, item_count, capacity, 1)
    # result = expandBest2(items, item_count, capacity, 2 ** 10)
    result = expandStepReviseConfig(items, item_count, capacity)
    value, taken = result[0], result[1]

    # prepare the solution in the specified output format
    output_data = str(value) + ' ' + str(1) + '\n'
    output_data += ' '.join(map(str, taken))
    return output_data

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        with open(file_location, 'r') as input_data_file:
            input_data = input_data_file.read()
        print(solve_it(input_data))
    else:
        print('This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)')

