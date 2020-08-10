#!/usr/bin/python
# -*- coding: utf-8 -*-

from collections import namedtuple
from queue import PriorityQueue
from queue import Queue
Item = namedtuple("Item", ['index', 'value', 'weight'])

def expandLeastDicrepancy(items, n, C):
    que = PriorityQueue()
    count = 0

    items = sorted(items, key=lambda item: -item.value/item.weight)
    minValue = findMinValue(items, n, C)
    relax = relaxation(items, C)
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