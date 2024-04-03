#include <todolist-cpp/View.hpp>

std::string showTask(const Task & task) {
    return std::to_string(task._id) + ". " + task._name;
}

std::string showBoard(const Board & board) {
    std::string output;

    output += "Todo:\n";
    for (const Task & task : board._todo) {
        output += showTask(task) + "\n";
    }

    output += "Done:\n";
    for (const Task & task : board._done) {
        output += showTask(task) + "\n";
    }

    return output;
}