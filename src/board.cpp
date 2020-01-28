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
#include <vector>
#include <map>
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

Piece Board::get(char positionY, int positionX) {
    return this->pieces.at(8 - positionX).at((int)positionY - 97);
}

void Board::setFenPosition(std::string fen) {
    std::vector<Piece> row;
    std::vector<std::vector<Piece>> pieces;
    std::map<std::string, Piece> piecesMap;
    piecesMap["P"] = Pawn(Color::white);
    piecesMap["p"] = Pawn(Color::black);
    piecesMap["R"] = Rook(Color::white);
    piecesMap["r"] = Rook(Color::black);
    piecesMap["B"] = Bishop(Color::white);
    piecesMap["b"] = Bishop(Color::black);
    piecesMap["N"] = Knight(Color::white);
    piecesMap["n"] = Knight(Color::black);
    piecesMap["Q"] = Queen(Color::white);
    piecesMap["q"] = Queen(Color::black);
    piecesMap["K"] = King(Color::white);
    piecesMap["k"] = King(Color::black);
    for(int i=0; i<fen.size(); ++i) {
        if(fen[i] == '/') {
            pieces.push_back(row);
            row.clear();
        } else if((int)fen[i] >= 48 && (int)fen[i] <= 57) {
            int ia = fen[i] - '0';
            for(int j=0; j<ia; ++j) {
                NullPiece nPiece;
                row.push_back(nPiece);
            }
        } else {
            std::string s(1, fen[i]);
            row.push_back(piecesMap[s]);
        }
        if(i == fen.size() - 1) {
            pieces.push_back(row);
            row.clear();
        }
    }
    this->pieces = pieces;
}