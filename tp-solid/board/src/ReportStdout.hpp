#pragma once

#include "Board.hpp"
#include "Reportable.hpp"

class ReportStdout : public Reportable {
    public:
        void report(const Board& board) override {
            for (const std::string & item : board.getItems())
                std::cout << item << std::endl;
            std::cout << std::endl;
        }
};