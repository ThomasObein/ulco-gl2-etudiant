#include <catch2/catch.hpp>

#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/Board.hpp>

TEST_CASE("showTask") {
    Task t {1, "Task 1"};
    std::string result = showTask(t);
    REQUIRE(result == "1. Task 1");
}

TEST_CASE("showTask 2") {
    Task t {19, "Nettoyer la tâche"};
    std::string result = showTask(t);
    REQUIRE(result == "19. Nettoyer la tâche");
}


TEST_CASE("show board") {
    Board b;
    b.addTodo("addTodo test 1");
    b.addTodo("addTodo test 2");

    std::string result = showBoard(b); 

    std::string output = "Todo:\n1. addTodo test 1\n2. addTodo test 2\nDone:\n";

    REQUIRE (result == output);  
}