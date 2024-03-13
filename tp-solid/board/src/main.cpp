
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"

void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");
    ReportStdout r;
    r.report(b);

    ReportFile rf("report.txt");
    rf.report(b);
}

int main() {

    Board b1;
    testBoard(b1);

    return 0;
}

