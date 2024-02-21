import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import numpy as np
from myfibo import fibo_iterative

if __name__ == '__main__':

    xs = np.arange(0, 11, 1)
    ys = np.vectorize(fibo_iterative)(xs)

    fig, ax = plt.subplots()
    ax.plot(xs, ys)
    ax.set(xlabel='i', ylabel='fibo_iterative(i)')
    ax.grid()

    fig.savefig("output.png")
    plt.show()

