#include <iostream>
#include "pieces.h"

Piece::Piece() {
    this->name = "Undef.";
}

std::string Piece::getName() {
    return this->name;
}

Rook::Rook() {
    this->name = "Rook";
}

Bishop::Bishop() {
    this->name = "Bishop";
}

Knight::Knight() {
    this->name = "Knight";
}

King::King() {
    this->name = "King";
}

Queen::Queen() {
    this->name = "Queen";
}

Pawn::Pawn() {
    this->name = "Pawn";
}