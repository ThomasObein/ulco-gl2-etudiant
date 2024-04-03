#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hpp>

#include <iostream>

int main() {

    Task t {1, "TODO"};
    std::cout << showTask(t) << std::endl;

    Board b;
    b.addTodo("Rentrer à la maison");
    b.addTodo("Afficher un board");
    b.addTodo("Manger");
    b.addTodo("Dormir");

    b.toDone(2);

    std::cout << showBoard(b) << std::endl;
    
    return 0;
}

