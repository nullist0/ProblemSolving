from math import *

def w(n):
    return cos(pi* (2.0 / n)) + sin(pi * (2.0 / n)) * 1j

def eval(l, value):
    N = len(l)
    if N <= 1:
        return l
    
    even = []
    odd = []
    r = [0] * N
    for i in range(N):
        if i % 2 == 0:
            even += [l[i]]
        else:
            odd += [l[i]]

    evalE = eval(even, value ** 2)
    evalO = eval(odd, value ** 2)

    for j in range(int(N/2)):
        r[j] = evalE[j] + (value**j) * evalO[j]
        r[j+int(N/2)] = evalE[j] - (value**j) * evalO[j]
    return r

def FFT(l):
    return eval(l, w(len(l)))

def inverseFFT(l):
    return list(map(lambda x: round(x.real/len(l), 15) + round(x.imag/len(l), 15)*1j, eval(l, 1/w(len(l)))))

def convolution(a, b):
    N = len(a) + len(b)
    N = 2 ** (floor(log2(N))+1)
    
    A = FFT(a + [0] * (N - len(a)))
    B = FFT(b + [0] * (N - len(b)))
    C = [0] * N
    for i in range(N):
        C[i] = A[i] * B[i]
    return inverseFFT(C)

print(inverseFFT(FFT([0, 10, 0, -1])))
print(convolution([1, 0, 1], [1, 0, 1, 0]))