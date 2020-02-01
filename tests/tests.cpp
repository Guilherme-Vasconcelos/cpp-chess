// -*- lsst-c++ -*-

/* 
 * This file is part of cpp-chess.h
 *
 * Copyright (c) 2020 GUILHERME VASCONCELOS, JOHN VICTOR
 * Distributed under the MIT License (license terms at https://opensource.org/licenses/MIT)
 * 
 */
#include "pieces.h"
#include "board.h"
#include "catch.hpp"
Board boardInitialFen;

TEST_CASE( "Testing initial position", "[initialPosition]" ) {
    REQUIRE( boardInitialFen.getCurrentFen() == "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR" );
    REQUIRE( boardInitialFen.get("a1").getName() == "R" );
    REQUIRE( boardInitialFen.get("a1").getColor() == Color::white);
    REQUIRE( boardInitialFen.get("a8").getName() == "r" );
    REQUIRE( boardInitialFen.get("a8").getColor() == Color::black );
    REQUIRE( boardInitialFen.get("e1").getName() == "K" );
    REQUIRE( boardInitialFen.get("e1").getColor() == Color::white );
    REQUIRE( boardInitialFen.get("e8").getName() == "k" );
    REQUIRE( boardInitialFen.get("e8").getColor() == Color::black );
    REQUIRE( boardInitialFen.get("g1").getName() == "N" );
    REQUIRE( boardInitialFen.get("g1").getColor() == Color::white );
    REQUIRE( boardInitialFen.get("g8").getName() == "n" );
    REQUIRE( boardInitialFen.get("g8").getColor() == Color::black );
    REQUIRE( boardInitialFen.get("a3").getName() == "." );
    REQUIRE( boardInitialFen.get("f4").getName() == "." );
}