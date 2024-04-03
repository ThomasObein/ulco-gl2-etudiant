#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test 1" ) {
    Task t {1, "TODO"};
    REQUIRE( t._id == 1 );
    REQUIRE( t._name == "TODO" );
}

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
