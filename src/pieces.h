#ifndef PIECES_H
#define PIECES_H

#include <iostream>

enum class Color {white, black};

class Piece {
protected:
    std::string name;
    bool nullPiece;
    Color color;
public:
    Piece();
    int positionX;
    int positionY;
    std::string getName();
    Color getColor();
    bool isNullPiece();
    virtual ~Piece() {};
};

class Rook: public Piece {
public:
    Rook(Color color);
};

class Bishop: public Piece {
public:
    Bishop(Color color);
};

class Knight: public Piece {
public:
    Knight(Color color);
};

class King: public Piece {
public:
    King(Color color);
};

class Queen: public Piece {
public:
    Queen(Color color);
};

class Pawn: public Piece {
public:
    Pawn(Color color);
};

class NullPiece: public Piece {
public:
    NullPiece();
};

#endif