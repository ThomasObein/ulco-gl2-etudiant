#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <iostream>

int main() {

    Task t {1, "TODO"};
    std::cout << showTask(t) << std::endl;
    
    return 0;
}

