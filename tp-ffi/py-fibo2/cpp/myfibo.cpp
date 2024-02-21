#include <cassert>

int fiboNaive(int n) {
    assert(n => 0);
    return n < 2 ? n : fiboNaive(n-1) + fiboNaive(n-2);
}

int fiboIterative(int n) {
    assert(n => 0);
    if (n == 0) return 0;
    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++) {
        int tmp = second;
        second = first + second;
        first = tmp;
    }
    return second;
}


#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m) {

    m.def("fibo_naive", &fiboNaive, "Recursive fibonacci");

    m.def("fibo_iterative", &fiboIterative, "Iterative fibonacci");

}

