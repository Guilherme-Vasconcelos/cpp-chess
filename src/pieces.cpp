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