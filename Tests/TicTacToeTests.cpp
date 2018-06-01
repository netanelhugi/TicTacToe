#include "Board.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Tests/doctest.h"

/**
 * to run the tests, put this file to parent folder "../"
 * instead of main.cpp
 */

TEST_CASE("testing board size") {
    CHECK(Board(1) == "\n." );
	CHECK(Board(2) == "\n...\n...\n..." );
}