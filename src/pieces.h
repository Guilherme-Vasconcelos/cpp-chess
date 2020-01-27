#ifndef PIECES_H
#define PIECES_H

#include <iostream>

class Piece {
protected:
    std::string name;
public:
    Piece();
    int positionX;
    int positionY;
    std::string getName();
};

class Rook: public Piece {
public:
    Rook();
};

class Bishop: public Piece {
public:
    Bishop();
};

class Knight: public Piece {
public:
    Knight();
};

class King: public Piece {
public:
    King();
};

class Queen: public Piece {
public:
    Queen();
};

class Pawn: public Piece {
public:
    Pawn();
};

#endif