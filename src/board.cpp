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
#include <memory>
#include <map>

#include "board.h"
#include "pieces.h"

Board::Board(std::string currentFen) {
    for(int i=0; i<8; ++i) {
        std::vector<Piece*> newVector;
        for(int j=0; j<8; ++j) {
            NullPiece *piece = new NullPiece;
            newVector.push_back(piece);
        }
        this->pieces.push_back(newVector);
    }
    this->currentFen = currentFen;
    this->setFenPosition(currentFen);
}

void Board::clearBoard() {
    this->setFenPosition("8/8/8/8/8/8/8/8");
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            delete(this->pieces.at(i).at(j));
        }
    }
}

void Board::showBoard() {
    std::stringstream ss;
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            ss << this->pieces.at(i).at(j)->getName() << " " << std::flush;
        }
        ss << std::endl;
    }
    std::cout << ss.str() << std::flush;
}

void Board::place(Piece *piece, std::string position) {
    delete(this->pieces.at(8 - (position[1] - '0')).at((int)position[0] - 97));
    this->pieces.at(8 - (position[1] - '0')).at((int)position[0] - 97) = piece;
}

Piece* Board::get(std::string position) {
    return this->pieces.at(8 - (position[1] - '0')).at((int)position[0] - 97);
}

void Board::setFenPosition(std::string fen) {
    std::vector<Piece*> row;
    std::vector<std::vector<Piece*>> pieces;

    for(size_t i = 0; i < fen.size(); ++i) {
        if(fen[i] == '/') {
            pieces.push_back(row);
            row.clear();
        } else if((int)fen[i] >= 48 && (int)fen[i] <= 57) {
            int ia = fen[i] - '0';
            for(int j=0; j<ia; ++j) {
                NullPiece *nPiece = new NullPiece;
                row.push_back(nPiece);
            }
        } else {
            std::string s(1, fen[i]);
            if(s == "P") {
                Pawn *newPiece = new Pawn(Color::white);
                row.push_back(newPiece);
            } else if(s == "p") {
                Pawn *newPiece = new Pawn(Color::black);
                row.push_back(newPiece);
            } else if(s == "R") {
                Rook *newPiece = new Rook(Color::white);
                row.push_back(newPiece);
            } else if(s == "r") {
                Rook *newPiece = new Rook(Color::black);
                row.push_back(newPiece);
            } else if(s == "B") {
                Bishop *newPiece = new Bishop(Color::white);
                row.push_back(newPiece);
            } else if(s == "b") {
                Bishop *newPiece = new Bishop(Color::black);
                row.push_back(newPiece);
            } else if(s == "N") {
                Knight *newPiece = new Knight(Color::white);
                row.push_back(newPiece);
            } else if(s == "n") {
                Knight *newPiece = new Knight(Color::black);
                row.push_back(newPiece);
            } else if(s == "Q") {
                Queen *newPiece = new Queen(Color::white);
                row.push_back(newPiece);
            } else if(s == "q") {
                Queen *newPiece = new Queen(Color::black);
                row.push_back(newPiece);
            } else if(s == "K") {
                King *newPiece = new King(Color::white);
                row.push_back(newPiece);
            } else if(s == "k") {
                King *newPiece = new King(Color::black);
                row.push_back(newPiece);
            }
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
    std::string updatedFen;
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            
        }
    }
    //this->currentFen = updatedFen;
    return this->currentFen;
}

void Board::move(std::string initialLocation, std::string finalLocation) {
    // @TODO: currently, this method moves whatever is in initialLocation and moves it
    // to finalLocation without checking if it's a legal move. In the future, implement
    // in each Piece derived class a vector of current legal squares to move, and this
    // method move, before actually moving the piece, will first check if the desired move
    // is in piece.legalSquares.
    Piece *pieceToMove = this->get(initialLocation);
    pieceToMove->updateLegalSquares(initialLocation, this->pieces);
    bool isLegal = false;
    for(size_t i=0; i<pieceToMove->legalSquares.size(); ++i) {
        if(pieceToMove->legalSquares[i] == finalLocation) {
            isLegal = true;
            break;
        }
    }
    if(pieceToMove->isNullPiece()) {
        throw std::invalid_argument("Invalid argument: \"" + initialLocation + "\" position contains instance of NullPiece (i.e. contains no piece)");
    } else if(!isLegal) {
        throw std::invalid_argument("Invalid argument: Target square \"" + finalLocation + "\" does not belong to Piece.legalMoves (i.e. move not allowed)");
    }
    NullPiece *nPiece = new NullPiece();
    //std::vector<int> positionRowColumn;
    //positionRowColumn.push_back(8 - (initialLocation[1] - '0'));
    //positionRowColumn.push_back((int)initialLocation[0] - 97);
    //delete(this->pieces.at(positionRowColumn[0]).at(positionRowColumn[1]));
    this->place(pieceToMove, finalLocation);
    this->place(nPiece, initialLocation);
    // this->updateCurrentFen(this->getCurrentFen());
}
