
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"
#include "NumBoard.hpp"

void testBoard(Board & b, Reportable & r) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");

    r.report(b);
}

void testNumBoard(NumBoard & b, Reportable & r) {
    std::cout << b.getTitle() << std::endl;
    b.addNum("item 1");
    b.addNum("item 2");

    r.report(b);
}

int main() {

    Board b1;

    ReportStdout r1;
    ReportFile r2("report.txt");
    testBoard(b1, r1);

    NumBoard b2;
    testNumBoard(b2, r1);
    testBoard(b2, r2);

    return 0;
}

