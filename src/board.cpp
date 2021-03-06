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

Board::Board(std::string currentFen) {
    for(int i=0; i<8; ++i) {
        NullPiece piece;
        this->pieces.push_back(std::vector<Piece>(8, piece));
    }
    this->currentFen = currentFen;
    this->setFenPosition(currentFen);
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

void Board::clearBoard() {
    this->setFenPosition("8/8/8/8/8/8/8/8");
}

void Board::place(Piece piece, std::string position) {
    this->pieces.at(8 - (position[1] - '0')).at((int)position[0] - 97) = piece;
}

Piece Board::get(std::string position) {
    return this->pieces.at(8 - (position[1] - '0')).at((int)position[0] - 97);
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

    for(size_t i = 0; i < fen.size(); ++i) {
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

std::string Board::getCurrentFen() {
    // @TODO: iterate through the whole board and update
    // the attribute this->currentFen accordingly.
    return this->currentFen;
}

void Board::move(std::string initialLocation, std::string finalLocation) {
    // @TODO: currently, this method moves whatever is in initialLocation and moves it
    // to finalLocation without checking if it's a legal move. In the future, implement
    // in each Piece derived class a vector of current legal squares to move, and this
    // method move, before actually moving the piece, will first check if the desired move
    // is in piece.legalSquares.
    Piece pieceToMove = this->get(initialLocation);
    //pieceToMove.updateLegalSquares();
    if(pieceToMove.isNullPiece()) {
        throw std::invalid_argument("Invalid argument: \"" + initialLocation + "\" position contains instance of NullPiece (i.e. contains no piece)");
    } // else if(finalLocation does not belong to pieceToMove.legalSquares [...]) { [...] }
    NullPiece nPiece = NullPiece();
    this->place(nPiece, initialLocation);
    this->place(pieceToMove, finalLocation);
    // this->updateCurrentFen(this->getCurrentFen());
}
