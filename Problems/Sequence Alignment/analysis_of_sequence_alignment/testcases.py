import random
import itertools

def concat(l):
    s = ''
    for i in range(len(l)):
        s += l[i]
    return s

def worstTime(v):
    th = 300
    n = v
    m = v

    l = list(map(lambda l:concat(l), itertools.combinations_with_replacement('ATGC', v)))
    l = list(itertools.combinations_with_replacement(l, 2))
    t = len(l) + th
    print(th, t, m, n)
    for tt in range(th):
        x = ""
        y = ""
        for i in range(m):
            x += random.choice('ATGC')
            y += random.choice('ATGC')
        print(x)
        print(y)
    for tt in range(len(l)):
        print(l[tt][0])
        print(l[tt][1])


def time(v):
    th = 300
    t = 30000
    n = v
    m = v

    print(th, t, m, n)
    for tt in range(t):
        x = ""
        y = ""
        for i in range(m):
            x += random.choice('ATGC')
            y += random.choice('ATGC')
        print(x)
        print(y)

def operation(v):
    n = v
    m = v

    print(m, n)
    x = ""
    y = ""
    for i in range(m):
        x += random.choice('ATGC')
        y += random.choice('ATGC')
    print(x)
    print(y)

# operation(50)
# time(50)
worstTime(20)