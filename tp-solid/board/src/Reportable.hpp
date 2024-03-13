#pragma once

#include "Board.hpp"

class Reportable {
    public:
        virtual ~Reportable() = default;
        virtual void report(const Board& board) = 0;
};