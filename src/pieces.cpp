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
#include "pieces.h"

Piece::Piece() {
    this->name = "-";
}

std::string Piece::getName() {
    return this->name;
}

std::vector<int> Piece::convertAlgebraicToInts(std::string algebraicPosition) {
    std::vector<int> vectorRowColumn;
    vectorRowColumn.push_back(8 - (algebraicPosition[1] - '0'));
    vectorRowColumn.push_back((int)algebraicPosition[0] - 97);
    return vectorRowColumn;
}

std::string Piece::convertIntsToAlgebraic(std::vector<int> positionRowColumn) {
    std::stringstream ss;
    ss << (char)('a' + positionRowColumn[1]);
    ss << (char)(8 - (positionRowColumn[0] - '0'));
    return ss.str();
}

Rook::Rook(Color color) {
    this->nullPiece = false;
    this->color = color;
    switch(color) {
        case Color::white:
            this->name = "R";
            break;
        case Color::black:
            this->name = "r";
            break;
    }
}

void Rook::updateLegalSquares(std::string piecePosition, std::vector<std::vector<Piece*>> pieces) {
    this->legalSquares.clear();
    std::vector<int> positionRowColumn;
    positionRowColumn = this->convertAlgebraicToInts(piecePosition);
    // Code guide:
    // Logic: if square is legal then: this->legalSquares.push_back(square)
    // A rook can either move on y-axis or on x-axis, but not on both
    // at the same time. Also, it can't jump over pieces and if there is
    // a piece from the opposite color at an available square 
    // then the rook can capture it. In the future, remember to code
    // castle rules.
    
    // remember, the rook's row is positionRowColumn[0]
    // and the rook's column is positionRowColumn[1]

    // checking for other pieces to the left of the rook
    // i.e. same row, but reducing the column to be checked
    for(int iterateToLeft=positionRowColumn[1]; iterateToLeft>-1; --iterateToLeft) {
        if(pieces[positionRowColumn[0]][iterateToLeft]->getName() == ".") {
            std::vector<int> vectorToPush;
            vectorToPush.push_back(positionRowColumn[0]);
            vectorToPush.push_back(iterateToLeft);
            this->legalSquares.push_back(convertIntsToAlgebraic(vectorToPush));
        }
    }
    for(int i=0; i<this->legalSquares.size(); ++i) {
        std::cout << legalSquares[i] << std::endl;
    }
    
}

Bishop::Bishop(Color color) {
    this->nullPiece = false;
    this->color = color;
    switch(color) {
        case Color::white:
            this->name = "B";
            break;
        case Color::black:
            this->name = "b";
            break;
    }
}

void Bishop::updateLegalSquares(std::string piecePosition, std::vector<std::vector<Piece*>> pieces) {
    this->legalSquares.clear();
    std::vector<int> positionRowColumn;
    positionRowColumn = this->convertAlgebraicToInts(piecePosition);
    // Code guide:
    // if square is legal then: this->legalSquares.push_back(square)
    // A bishop can move on diagonals. It can't jump over pieces and if there
    // is a piece from the opposite color at target square then the
    // bishop can capture it.
}

Knight::Knight(Color color) {
    this->nullPiece = false;
    this->color = color;
    switch(color) {
        case Color::white:
            this->name = "N";
            break;
        case Color::black:
            this->name = "n";
            break;
    }
}

void Knight::updateLegalSquares(std::string piecePosition, std::vector<std::vector<Piece*>> pieces) {
    this->legalSquares.clear();
    std::vector<int> positionRowColumn;
    positionRowColumn = this->convertAlgebraicToInts(piecePosition);
    // Code guide:
    // if square is legal then: this->legalSquares.push_back(square)
    // A knight can move two squares on one axis then one square
    // on the another axis. It can jump over pieces and if there is
    // a piece from the opposite color at the target square
    // then the knight can capture it.
}

King::King(Color color) {
    this->nullPiece = false;
    this->color = color;
    switch(color) {
        case Color::white:
            this->name = "K";
            break;
        case Color::black:
            this->name = "k";
            break;
    }
}

void King::updateLegalSquares(std::string piecePosition, std::vector<std::vector<Piece*>> pieces) {
    this->legalSquares.clear();
    std::vector<int> positionRowColumn;
    positionRowColumn = this->convertAlgebraicToInts(piecePosition);
    // Code guide:
    // if square is legal then: this->legalSquares.push_back(square)
    // a king can move in any direction (either y-axis, x-axis or diagonals),
    // but only one square at the time. It can't jump over pieces and if
    // there is a piece from the opposite color then the king can
    // capture it as long as the target piece is not defended.
    // In the future, remember to code castle rules.
}

Queen::Queen(Color color) {
    this->nullPiece = false;
    this->color = color;
    switch(color) {
        case Color::white:
            this->name = "Q";
            break;
        case Color::black:
            this->name = "q";
            break;
    }
}

void Queen::updateLegalSquares(std::string piecePosition, std::vector<std::vector<Piece*>> pieces) {
    this->legalSquares.clear();
    std::vector<int> positionRowColumn;
    positionRowColumn = this->convertAlgebraicToInts(piecePosition);
    // Code guide:
    // if square is legal then: this->legalSquares.push_back(square)
    // A queen can move in any direction (either y-axis, x-axis or diagonals)
    // and as many squares as possible (without jumping over pieces).
    // If there is a piece from the opposite color then the queen can capture it.
}

Pawn::Pawn(Color color) {
    this->nullPiece = false;
    this->color = color;
    switch(color) {
        case Color::white:
            this->name = "P";
            break;
        case Color::black:
            this->name = "p";
            break;
    }
}

void Pawn::updateLegalSquares(std::string piecePosition, std::vector<std::vector<Piece*>> pieces) {
    this->legalSquares.clear();
    std::vector<int> positionRowColumn;
    positionRowColumn = this->convertAlgebraicToInts(piecePosition);
    // Code guide:
    // if square is legal then: this->legalSquares.push_back(square)
    // A pawn can move two squares forward if it's its first movement.
    // Otherwise, it can only move one square forward as long as the target 
    // square is available. It can only move to an adjacent diagonal if there
    // is a piece from the opposite color there, since this is the only way
    // it can capture pieces. In the future, remember to code en passant and promotions.
}

NullPiece::NullPiece() {
    this->name = ".";
    this->nullPiece = true;
}

Color Piece::getColor() {
    return this->color;
}

bool Piece::isNullPiece() {
    return this->nullPiece;
}
