// -*- lsst-c++ -*-

/* 
 * This file is part of cpp-chess.h
 *
 * Copyright (c) 2020 GUILHERME VASCONCELOS, JOHN VICTOR
 * Distributed under the MIT License (license terms at https://opensource.org/licenses/MIT)
 * 
 */

#include <iostream>
#include <sstream>
#include "board.h"
#include "pieces.h"

Board::Board() {
    for(int i=0; i<8; ++i) {
        NullPiece piece;
        this->pieces.push_back(std::vector<Piece>(8, piece));
    }
}

void Board::showBoard() {
    std::stringstream ss;
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            ss << this->pieces.at(i).at(j).getName() << " " << std::flush;
        }
        ss << std::endl;
    }
    std::cout << ss.str() << std::flush;
}

void Board::place(Piece piece, char positionY, int positionX) {
    this->pieces.at(8 - positionX).at((int)positionY - 97) = piece;
}

void Board::setPieces(std::vector<std::vector<Piece>> pieces) {
    this->pieces = pieces;
}

void Board::hardPlace(Piece piece, int positionX, int positionY) {
    this->pieces.at(positionX).at(positionY) = piece;
}

Piece Board::get(char positionY, int positionX) {
    return this->pieces.at(8 - positionX).at((int)positionY - 97);
}

Piece Board::hardGet(int positionX, int positionY) {
    return this->pieces.at(positionX).at(positionY);
}