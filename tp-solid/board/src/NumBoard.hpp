#pragma once

#include "Board.hpp"

class NumBoard : public Board {
    private: 
        int next_id;
    public:
        NumBoard() : next_id(1) {};
        void addNum(const std::string & task) {
            add(std::to_string(next_id) + ". " + task);
            ++next_id;
        }
};