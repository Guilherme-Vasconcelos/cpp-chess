// -*- lsst-c++ -*-

/* 
 * This file is part of cpp-chess.h
 *
 * Copyright (c) 2020 GUILHERME VASCONCELOS, JOHN VICTOR
 * Distributed under the MIT License (license terms at https://opensource.org/licenses/MIT)
 * 
 */

#include <iostream>

#include "pieces.h"
#include "board.h"

int main() {

    Board board("2bqnrk1/5p1p/5PpQ/3pP1P1/2pP1R2/2P3N1/6BP/1q4K1");
    // rook in f4 can move to e4
    board.showBoard();
    board.move("f4", "e4");
    board.showBoard();

    return 0;
}
