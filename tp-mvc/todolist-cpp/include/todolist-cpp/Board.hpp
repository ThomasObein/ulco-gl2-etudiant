#pragma once

#include <todolist-cpp/Task.hpp>
#include <iostream>
#include <list>

class Board {
    private:
        int _nextId;
    public:
        std::list<Task> _todo;
        std::list<Task> _done;

        Board() : _nextId(1) {};

        void addTodo(const std::string & desc);
        void toDone(int id);
};