#include <iostream>
#include "pieces.h"

Piece::Piece() {
    this->name = "-";
}

std::string Piece::getName() {
    return this->name;
}

Rook::Rook(bool whitePiece) {
    this->nullPiece = false;
    if(whitePiece) {
        this->name = "R";
    } else if(!whitePiece) {
        this->name = "r";
    }
    this->whitePiece = whitePiece;
}

Bishop::Bishop(bool whitePiece) {
    this->nullPiece = false;
    if(whitePiece) {
        this->name = "B";
    } else if(!whitePiece) {
        this->name = "b";
    }
    this->whitePiece = whitePiece;
}

Knight::Knight(bool whitePiece) {
    this->nullPiece = false;
    if(whitePiece) {
        this->name = "N";
    } else if(!whitePiece) {
        this->name = "n";
    }
    this->whitePiece = whitePiece;
}

King::King(bool whitePiece) {
    this->nullPiece = false;
    if(whitePiece) {
        this->name = "K";
    } else if(!whitePiece) {
        this->name = "k";
    }
    this->whitePiece = whitePiece;
}

Queen::Queen(bool whitePiece) {
    this->nullPiece = false;
    if(whitePiece) {
        this->name = "Q";
    } else if(!whitePiece) {
        this->name = "q";
    }
    this->whitePiece = whitePiece;
}

Pawn::Pawn(bool whitePiece) {
    this->nullPiece = false;
    if(whitePiece) {
        this->name = "P";
    } else if(!whitePiece) {
        this->name = "p";
    }
    this->whitePiece = whitePiece;
}

NullPiece::NullPiece() {
    this->name = ".";
    this->whitePiece = false;
    this->nullPiece = true;
}

bool Piece::isWhitePiece() {
    return this->whitePiece;
}

bool Piece::isNullPiece() {
    return this->nullPiece;
}