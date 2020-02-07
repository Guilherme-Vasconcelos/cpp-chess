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

    Board board;
    Rook rook(Color::white);
    board.showBoard();

    board.move("a1", "h3");

    board.showBoard();
    rook.updateLegalSquares("h3", board.pieces);
    for(int i=0; i<7; ++i) {
        std::cout << rook.legalSquares[i] << std::endl;
    }

    return 0;
}
