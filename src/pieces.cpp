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

void Rook::updateLegalSquares(std::string piecePosition) {
    std::vector<int> positionsRowColumn;
    positionsRowColumn = this->convertAlgebraicToInts(piecePosition);
    // CODE THE LOGIC TO UPDATE THE LEGAL SQUARES BELOW
    // if movement is legal then: this->legalSquares.push_back(movement)
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

void Bishop::updateLegalSquares(std::string piecePosition) {
    std::vector<int> positionsRowColumn;
    positionsRowColumn = this->convertAlgebraicToInts(piecePosition);
    // CODE THE LOGIC TO UPDATE THE LEGAL SQUARES BELOW
    // if movement is legal then: this->legalSquares.push_back(movement)
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

void Knight::updateLegalSquares(std::string piecePosition) {
    std::vector<int> positionsRowColumn;
    positionsRowColumn = this->convertAlgebraicToInts(piecePosition);
    // CODE THE LOGIC TO UPDATE THE LEGAL SQUARES BELOW
    // if movement is legal then: this->legalSquares.push_back(movement)
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

void King::updateLegalSquares(std::string piecePosition) {
    std::vector<int> positionsRowColumn;
    positionsRowColumn = this->convertAlgebraicToInts(piecePosition);
    // CODE THE LOGIC TO UPDATE THE LEGAL SQUARES BELOW
    // if movement is legal then: this->legalSquares.push_back(movement)
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

void Queen::updateLegalSquares(std::string piecePosition) {
    std::vector<int> positionsRowColumn;
    positionsRowColumn = this->convertAlgebraicToInts(piecePosition);
    // CODE THE LOGIC TO UPDATE THE LEGAL SQUARES BELOW
    // if movement is legal then: this->legalSquares.push_back(movement)
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

void Pawn::updateLegalSquares(std::string piecePosition) {
    std::vector<int> positionsRowColumn;
    positionsRowColumn = this->convertAlgebraicToInts(piecePosition);
    // CODE THE LOGIC TO UPDATE THE LEGAL SQUARES BELOW
    // if movement is legal then: this->legalSquares.push_back(movement)
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
