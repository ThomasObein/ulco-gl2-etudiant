#include <catch2/catch.hpp>

#include <todolist-cpp/Board.hpp>
#include <todolist-cpp/Task.hpp>

TEST_CASE("test addTodo") {
    Board b;
    b.addTodo("addTodo test");

    REQUIRE(b._todo.size() == 1);
    REQUIRE(b._done.size() == 0);
    Task t = b._todo.front();
    REQUIRE(t._id == 1);
    REQUIRE(t._name == "addTodo test");
}

TEST_CASE("test addTodo 2") {
    Board b;
    b.addTodo("addTodo test 1");
    b.addTodo("addTodo test 2");

    REQUIRE(b._todo.size() == 2);
    REQUIRE(b._done.size() == 0);
    Task t1 = b._todo.front();
    REQUIRE(t1._id == 1);
    REQUIRE(t1._name == "addTodo test 1");

    Task t2 = b._todo.back();
    REQUIRE(t2._id == 2);
    REQUIRE(t2._name == "addTodo test 2");
}

TEST_CASE("test toDone") {
    Board b;
    b.addTodo("addTodo test 1");
    b.addTodo("addTodo test 2");

    REQUIRE(b._todo.size() == 2);
    REQUIRE(b._done.size() == 0);

    b.toDone(2);

    REQUIRE(b._todo.size() == 1);
    REQUIRE(b._done.size() == 1);
    Task t1 = b._todo.front();
    REQUIRE(t1._id == 1);
    REQUIRE(t1._name == "addTodo test 1");

    Task t2 = b._done.back();
    REQUIRE(t2._id == 2);
    REQUIRE(t2._name == "addTodo test 2");
}
