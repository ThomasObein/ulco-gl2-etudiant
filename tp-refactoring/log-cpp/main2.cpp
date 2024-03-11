#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;

int add3(int n) {
    return n+3;
}

int mul2(int n) {
    return n*2;
}

int mycompute(logFunc_t fnc, int v0) {
    fnc("add3 " + std::to_string(v0));
    const int v1 = add3(v0);
    fnc("mul2 " + std::to_string(v1));
    const int v2 = add3(v1);
    return v2;
}

int main() {
    std::cout << "this is log-cpp" << std::endl;

    const int res = mycompute([](const std::string& str) -> void {
        std::cout << str << std::endl;
    }, 18);
    std::cout << res << std::endl;

    std::ofstream myfile("log2.txt");
    const int res2 = mycompute([&myfile](const std::string& str) -> void {
        myfile << str << std::endl;
    }, 18);
    std::cout << res2 << std::endl;

    return 0;
}

