#include <todolist-cpp/Board.hpp>
#include <algorithm>

void Board::addTodo(const std::string & desc) {
    Task t{ _nextId, desc };
    _nextId++;

    _todo.push_back(t);
}

void Board::toDone(int id) {
    auto it = std::find_if(_todo.begin(), _todo.end(), [id](Task & task) {
        return task._id == id;
    });
    
    if (it != _todo.end()) {
        _done.push_back(*it);
        _todo.erase(it);
    }
}