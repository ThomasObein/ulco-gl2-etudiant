
#include <Board.hpp>

#include <catch2/catch.hpp>

class BoardTest : public Board {
    public:
        BoardTest(int i, int j) : Board(i, j) {}
};

TEST_CASE( "init, 1" ) {
    Board b;
    REQUIRE( b.getI() == 0 );
    REQUIRE( b.getJ() == 0 );
}

TEST_CASE( "init, 2" ) {
    BoardTest b(1,2);
    REQUIRE( b.getI() == 1 );
    REQUIRE( b.getJ() == 2 );
}

TEST_CASE( "tryGoLeft, ok" ) {
    BoardTest b(7,3);
    b.tryGoLeft();
    REQUIRE( b.getI() == 7 );
    REQUIRE( b.getJ() == 2 );
}

TEST_CASE( "tryGoRight, ok" ) {
    BoardTest b(7,2);
    b.tryGoRight();
    REQUIRE( b.getI() == 7 );
    REQUIRE( b.getJ() == 3 );
}

TEST_CASE( "tryGoUp, ok" ) {
    BoardTest b(7,3);
    b.tryGoUp();
    REQUIRE( b.getI() == 7 );
    REQUIRE( b.getJ() == 3 );
}


TEST_CASE( "tryGoDown, ok" ) {
    BoardTest b(7,3);
    b.tryGoDown();
    REQUIRE( b.getI() == 8 );
    REQUIRE( b.getJ() == 3 );
}
