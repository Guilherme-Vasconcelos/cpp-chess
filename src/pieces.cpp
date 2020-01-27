#include <iostream>
#include "pieces.h"

Piece::Piece() {
    this->name = "-";
}

std::string Piece::getName() {
    return this->name;
}

Rook::Rook(bool whitePiece) {
    if(whitePiece) {
        this->name = "R";
    } else if(!whitePiece) {
        this->name = "r";
    }
    this->whitePiece = whitePiece;
}

Bishop::Bishop(bool whitePiece) {
    if(whitePiece) {
        this->name = "B";
    } else if(!whitePiece) {
        this->name = "b";
    }
    this->whitePiece = whitePiece;
}

Knight::Knight(bool whitePiece) {
    if(whitePiece) {
        this->name = "N";
    } else if(!whitePiece) {
        this->name = "n";
    }
    this->whitePiece = whitePiece;
}

King::King(bool whitePiece) {
    if(whitePiece) {
        this->name = "K";
    } else if(!whitePiece) {
        this->name = "k";
    }
    this->whitePiece = whitePiece;
}

Queen::Queen(bool whitePiece) {
    if(whitePiece) {
        this->name = "Q";
    } else if(!whitePiece) {
        this->name = "q";
    }
    this->whitePiece = whitePiece;
}

Pawn::Pawn(bool whitePiece) {
    if(whitePiece) {
        this->name = "P";
    } else if(!whitePiece) {
        this->name = "p";
    }
    this->whitePiece = whitePiece;
}

bool Rook::isWhitePiece() {
    return this->whitePiece;
}

bool Bishop::isWhitePiece() {
    return this->whitePiece;
}

bool Knight::isWhitePiece() {
    return this->whitePiece;
}

bool King::isWhitePiece() {
    return this->whitePiece;
}

bool Queen::isWhitePiece() {
    return this->whitePiece;
}

bool Pawn::isWhitePiece() {
    return this->whitePiece;
}