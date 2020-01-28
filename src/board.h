// -*- lsst-c++ -*-

/* 
 * This file is part of cpp-chess.h
 *
 * Copyright (c) 2020 GUILHERME VASCONCELOS, JOHN VICTOR
 * Distributed under the MIT License (license terms at https://opensource.org/licenses/MIT)
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "pieces.h"

class Board {
private:
    std::vector<std::vector<Piece>> pieces;
public:
    Board();
    void showBoard();
    void place(Piece piece, char positionY, int positionX);
    void hardPlace(Piece piece, int positionX, int positionY);
    void setPieces(std::vector<std::vector<Piece>> pieces);
};

#endif