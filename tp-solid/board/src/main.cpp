
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"
#include "NumBoard.hpp"

void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");
    ReportStdout r;
    r.report(b);

    ReportFile rf("report.txt");
    rf.report(b);
}

void testNumBoard(NumBoard & b) {
    std::cout << b.getTitle() << std::endl;
    b.addNum("item 1");
    b.addNum("item 2");
    ReportStdout r;
    r.report(b);

    ReportFile rf("report_num.txt");
    rf.report(b);
}

int main() {

    Board b1;
    testBoard(b1);

    NumBoard b2;
    testNumBoard(b2);
    testBoard(b2);

    return 0;
}

