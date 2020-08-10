#!/usr/bin/python3
# -*- coding: utf-8 -*-

import random

class ConstraintStore:
    def __init__(self, node_count, edges):
        self.edges = edges
        self.constraint = set(edges)
        self.neighborOf = [set() for _ in range(node_count)]
        # self.constraintByNode = [set() for _ in range(node_count)]
        self.node_count = node_count

        for edge in edges:
            self.neighborOf[edge[0]].add(edge[1])
            self.neighborOf[edge[1]].add(edge[0])

        # for con in self.constraint:
        #     self.constraintByNode[con[0]].add(con)
        #     self.constraintByNode[con[1]].add(con)
        
    def prepare(self, run_size):
        # self.constraint = set(self.edges)
        self.color = [None for _ in range(self.node_count)]
        self.newColor = 0
        self.notColoredNeighborOf = [set(range(self.node_count)) for _ in range(self.node_count)]

        self.size = run_size
        self.colorDist = [0] * self.size
        self.domainSet = [set(range(self.size)) for _ in range(self.node_count)]

        self.neighborColorDist = [[0 for _ in range(self.size)] for _ in range(self.node_count)]

    def cut(self, size):
        # print('cut', size, self.color)
        self.size = size
        self.newColor = size
        # self.colorDist = self.colorDist[:self.size]
        self.domainSet = [set(filter(lambda x: x < self.size, self.domainSet[n])) for n in range(self.node_count)]

        self.neighborColorDist = [self.neighborColorDist[n][:self.size] for n in range(self.node_count)]

    def push(self, node, color):
        if color in self.domainSet[node]:
            # print('push', node, color)
            self.color[node] = color
            self.colorDist[color] += 1

            if color == self.newColor:
                self.newColor += 1
            
            # propagation
            # prune
            self.domainSet[node] = set([color])
            for n in self.neighborOf[node]:
                self.notColoredNeighborOf[n].remove(node)
                self.domainSet[n].discard(color)
                self.neighborColorDist[n][color] += 1
            # feasibility check
            for n in range(self.node_count):
                if len(self.domainSet[n]) == 0 and self.color[n] == None:
                    return False
                if self.color[n] == self.size:
                    return False
            return True
        else:
            return False

    def reset(self, node):
        self.domainSet[node] = set(range(self.size))
        # propagation
        # prune
        for n in self.neighborOf[node]:
            self.notColoredNeighborOf[n].add(node)

            if self.color[n] in self.domainSet[node]:
                self.domainSet[node].remove(self.color[n])

    def pop(self, node, usedColor):
        if self.color[node] == None and len(usedColor) == 0:
            self.reset(node)
        else:
            color = self.color[node]
            self.color[node] = None
            
            # propagation
            self.domainSet[node] = set(range(self.size)) - usedColor

            # new color constraint
            self.colorDist[color] -= 1

            if color < self.size:
                if self.colorDist[self.newColor - 1] == 0:
                    self.newColor -= 1
            # prune
            for n in self.neighborOf[node]:
                self.notColoredNeighborOf[n].add(node)

                if color < self.size: # size constraint
                    self.neighborColorDist[n][color] -= 1
                    
                    if self.neighborColorDist[n][color] == 0 and self.color[n] == None:
                        self.domainSet[n].add(color)

                if self.color[n] in self.domainSet[node]:
                    self.domainSet[node].remove(self.color[n])


    def propagate(self):
        def prune(domain, color, edge):
            flag = False
            if color[edge[0]] in domain[edge[1]]:
                domain[edge[1]].remove(color[edge[0]])
                flag = True
            if color[edge[1]] in domain[edge[0]]:
                domain[edge[0]].remove(color[edge[1]])
                flag = True
            return flag

        def feasibility_check(domain, color, edge):
            if color[edge[0]] == None and color[edge[1]] == None:
                return len(domain[edge[0]]) * len(domain[edge[1]]) > 0 and len(domain[edge[0]] | domain[edge[1]]) >= 2
            elif color[edge[0]] != None and color[edge[1]] == None:
                return len(domain[edge[0]]) > 0
            elif color[edge[0]] == None and color[edge[1]] != None:
                return len(domain[edge[1]]) > 0
            else:
                return color[edge[0]] != color[edge[1]]

        remain = set()

        for c in self.constraint:
            if not feasibility_check(self.domainSet, self.color, c):
                print('failed with', c, self.domainSet[c[0]], self.domainSet[c[1]])
                return False
            if prune(self.domainSet, self.color, c):
                remain.add(c)
        
        while len(remain) > 0:
            c = remain.pop()
            if not feasibility_check(self.domainSet, self.color, c):
                print('failed with', c, self.domainSet[c[0]], self.domainSet[c[1]])
                return False
            if prune(self.domainSet, self.color, c):
                remain.add(c)

        return True

class Search:
    def __init__(self, node_count, edges):
        self.store = ConstraintStore(node_count, edges)
        self.node_count = node_count
    
    def next(self):
        if len(self.nextNodePull) == 0:
            return None
        # randomize
        m = {}
        for n in self.nextNodePull:
            key = (len(list(filter(lambda x: x <= self.store.newColor, self.store.domainSet[n]))), -len(self.store.notColoredNeighborOf[n]))
            if key in m.keys():
                m[key] += [n]
            else:
                m[key] = [n]
        node = random.choice(m[min(m.keys())])

        return node

    def run(self, size):
        self.nextNodePull = set(range(self.node_count))
        self.store.prepare(size)

        stack = [[self.next(), set()]]
        count = 0
        while len(stack) > 0:
            count += 1
            node, usedColor = stack[-1]
            if node == None:
                return self.store.color
            if self.store.color[node] != None:
                self.store.pop(node, usedColor)
            domain = set(filter(lambda x: x <= self.store.newColor, self.store.domainSet[node]))
            while len(domain) > 0:
                if self.store.color[node] != None:
                    self.store.pop(node, usedColor)
                domain = set(filter(lambda x: x <= self.store.newColor, self.store.domainSet[node]))

                l = {}
                for x in filter(lambda x: x < self.store.newColor, domain):
                    key = self.store.colorDist[x]
                    if key in l.keys():
                        l[key] += [x]
                    else:
                        l[key] = [x]
                if len(l.keys()) == 0 and self.store.newColor in domain:
                    color = self.store.newColor
                elif len(l.keys()) > 0:
                    color = random.choice(l[min(l.keys())])
                else:
                    break
                stack[-1][1].add(color)

                if self.store.push(node, color):
                    if node in self.nextNodePull:
                        self.nextNodePull.remove(node)
                    stack += [[self.next(), set()]]
                    break
            if node == stack[-1][0]:
                stack.pop()
                self.store.pop(node, set())
                self.nextNodePull.add(node)
        return None

    def simple_find(self, size, threshold):
        # size = self.node_count + 1
        self.nextNodePull = set(range(self.node_count))
        self.store.prepare(size)

        stack = [[self.next(), set()]]
        count = 0
        sol = []
        flag = self.node_count + 1
        while len(stack) > 0 and (threshold == None or count < threshold):
            # print(list(map(lambda x : (x[0], self.store.color[x[0]]), filter(lambda x: x[0] != None, stack))))
            node, usedColor = stack[-1]
            if node == None:
                if max(self.store.color) < flag:
                    sol = self.store.color[:]
                    flag = max(sol)
                self.store.cut(flag)
                stack.pop()
                node, usedColor = stack[-1]
            
            if self.store.color[node] != None:
                self.store.pop(node, usedColor)
            domain = set(filter(lambda x: x <= self.store.newColor, self.store.domainSet[node]))

            while len(domain) > 0:
                if next(filter(lambda x: x != None and x >= self.store.size, self.store.color), None) != None:
                    break
                if self.store.color[node] != None:
                    self.store.pop(node, usedColor)
                domain = set(filter(lambda x: x <= self.store.newColor, self.store.domainSet[node]))

                l = {}
                for x in filter(lambda x: x < self.store.newColor, domain):
                    key = 0
                    for n in self.store.notColoredNeighborOf[node]:
                        if self.store.neighborColorDist[n][x] == 0:
                            key += 1
                    # key = self.store.colorDist[x]
                    if key in l.keys():
                        l[key] += [x]
                    else:
                        l[key] = [x]
                if len(l.keys()) == 0 and self.store.newColor in domain:
                    color = self.store.newColor
                elif len(l.keys()) > 0:
                    color = random.choice(l[min(l.keys())])
                else:
                    break
                stack[-1][1].add(color)

                if self.store.push(node, color):
                    count += 1

                    if node in self.nextNodePull:
                        self.nextNodePull.remove(node)
                    stack += [[self.next(), set()]]
                    break
            if node == stack[-1][0]:
                stack.pop()
                self.store.pop(node, set())
                self.nextNodePull.add(node)
        return sol, threshold == None or count < threshold

    def find_solution(self, threshold):
        cache = self.run(self.node_count + 1)
        next_size = max(cache)
        while cache != None:
            sol = cache[:]
            cache = self.run(next_size)
        return sol
    
    def find_simple(self):
        threshold = self.node_count * 50
        size = self.node_count + 1
        sol, runAll = self.simple_find(size, threshold)
        size = max(sol)
        count = 0
        while not runAll:
            count += 1
            cache, runAll = self.simple_find(size, threshold)
            if cache != []:
                count = 0
                sol = cache
                size = max(sol)
            if count >= 10:
                break
        return sol

    def find_solution_binary(self):
        # obj = [True] * self.node_count
        cache = self.run(self.node_count + 1)
        sol = cache[:]
        high = max(sol) + 1
        low = 0
        mid = (high + low) // 2

        while high - low > 1:
            cache = self.run(mid)
            if cache == None:
                low = mid
                mid = (high + low) // 2
            else:
                sol = cache[:]
                high = max(sol) + 1
                mid = (high + low) // 2
        return sol