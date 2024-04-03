#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hpp>

#include <iostream>
#include <sstream>
#include <string>

int main() {
    Board b;
    std::string input, cmd, rst;
    while (true)
    {
        std::cout << showBoard(b) << std::endl;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::getline(iss, cmd, ' ');
        std::getline(iss, rst);
            
        if (cmd == "add" and rst != "") {
            b.addTodo(rst);
        }
        else if (cmd == "done" and rst != "") {
            try {
                b.toDone(stoi(rst));
            }
            catch (...) {
                std::cout << "invalid id" << std::endl;
            }
        }

        std::cout << showBoard(b) << std::endl;
    }
    
    
    return 0;
}

