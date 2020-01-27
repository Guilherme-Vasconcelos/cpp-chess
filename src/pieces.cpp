#include <iostream>
#include "pieces.h"

Piece::Piece() {
    this->name = "-";
}

std::string Piece::getName() {
    return this->name;
}

Rook::Rook(std::string color) {
    if(color == "white") {
        this->name = "R";
    } else if(color == "black") {
        this->name = "r";
    }
    this->color = color;
}

Bishop::Bishop(std::string color) {
    if(color == "white") {
        this->name = "B";
    } else if(color == "black") {
        this->name = "b";
    }
    this->color = color;
}

Knight::Knight(std::string color) {
    if(color == "white") {
        this->name = "N";
    } else if(color == "black") {
        this->name = "n";
    }
    this->color = color;
}

King::King(std::string color) {
    if(color == "white") {
        this->name = "K";
    } else if(color == "black") {
        this->name = "k";
    }
    this->color = color;
}

Queen::Queen(std::string color) {
    if(color == "white") {
        this->name = "Q";
    } else if(color == "black") {
        this->name = "q";
    }
    this->color = color;
}

Pawn::Pawn(std::string color) {
    if(color == "white") {
        this->name = "P";
    } else if(color == "black") {
        this->name = "p";
    }
    this->color = color;
}

std::string Rook::getColor() {
    return this->color;
}

std::string Bishop::getColor() {
    return this->color;
}

std::string Knight::getColor() {
    return this->color;
}

std::string King::getColor() {
    return this->color;
}

std::string Queen::getColor() {
    return this->color;
}

std::string Pawn::getColor() {
    return this->color;
}