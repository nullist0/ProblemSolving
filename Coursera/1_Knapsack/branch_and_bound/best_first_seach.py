#!/usr/bin/python
# -*- coding: utf-8 -*-

from collections import namedtuple
from queue import PriorityQueue
from queue import Queue
Item = namedtuple("Item", ['index', 'value', 'weight'])

def expandBestFirst(items, n, C):
    que = PriorityQueue()
    count = 0

    items = sorted(items, key=lambda item: -item.value/item.weight)
    relax = relaxation(items, C)
    minValue = findMinValue(items, n, C)

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
    print("best",count)
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

def relaxation(sItems, C):
    if(len(sItems) == 0):
        return 0.0
    relaxation = 0.0
    weight = 0.0

    for index in range(len(sItems)):
        item = sItems[index]
        if weight + item.weight > C:
            relaxation += (C - weight)/item.weight * item.value
            break
        if weight + item.weight <= C:
            relaxation += item.value
            weight += item.weight
    return relaxation