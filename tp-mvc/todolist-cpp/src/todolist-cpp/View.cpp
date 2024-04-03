#include <todolist-cpp/View.hpp>

std::string showTask(const Task & task) {
    return std::to_string(task._id) + ". " + task._name;
}