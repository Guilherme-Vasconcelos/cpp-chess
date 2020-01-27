#ifndef PIECES_H
#define PIECES_H

#include <iostream>

class Piece {
protected:
    std::string name;
    bool nullPiece;
    bool whitePiece;
public:
    Piece();
    int positionX;
    int positionY;
    std::string getName();
    bool isWhitePiece();
    bool isNullPiece();
    virtual ~Piece() {};
};

class Rook: public Piece {
public:
    Rook(bool whitePiece);
    bool isWhitePiece();
};

class Bishop: public Piece {
public:
    Bishop(bool whitePiece);
    bool isWhitePiece();
};

class Knight: public Piece {
public:
    Knight(bool whitePiece);
    bool isWhitePiece();
};

class King: public Piece {
public:
    King(bool whitePiece);
    bool isWhitePiece();
};

class Queen: public Piece {
public:
    Queen(bool whitePiece);
    bool isWhitePiece();
};

class Pawn: public Piece {
public:
    Pawn(bool whitePiece);
    bool isWhitePiece();
};

class NullPiece: public Piece {
public:
    NullPiece();
};

#endif