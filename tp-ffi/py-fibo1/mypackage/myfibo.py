
def fibo_naive(n: int):
    assert n >= 0
    return n if n < 2 else fibo_naive(n-1) + fibo_naive(n-2)

def fibo_iterative(n: int):
    if n == 0:
        return 0
    first = 0
    second = 1
    for i in range(n - 1):
        tmp = second
        second = first + second
        first = tmp
    return second
    
        

