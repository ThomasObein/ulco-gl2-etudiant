#pragma once

#include "Board.hpp"

class ReportFile {
    private:
        std::ofstream _ofs;
    public:
        ReportFile(const std::string& filename) : _ofs(filename) {};

        void report(const Board& board) {
            for (const std::string & item : board.getItems())
                _ofs << item << std::endl;
            _ofs << std::endl;
        }
};