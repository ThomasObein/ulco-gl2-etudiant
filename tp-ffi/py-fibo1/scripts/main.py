import mypackage.myfibo as mf

if __name__ == '__main__':
    
    for i in range(0, 11):
        print(f"fibo_naive({i}) = {mf.fibo_naive(i)}")

    for i in range(0, 11):
        print(f"fibo_iterative({i}) = {mf.fibo_iterative(i)}")

