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
public:
    Board();
    std::vector<std::vector<Piece>> pieces;
    void showBoard();
    void place(Piece piece, char positionY, int positionX);
    Piece get(char positionY, int positionX);
    void setFenPosition(std::string fen);
    const std::string initialFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    void move(Piece, char initialY, int initialX, char finalY, int finalX);
};

#endif
