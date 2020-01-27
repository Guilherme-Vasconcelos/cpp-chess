#ifndef PIECES_H
#define PIECES_H

#include <iostream>

class Piece {
protected:
    std::string name;
    std::string color;
public:
    Piece();
    int positionX;
    int positionY;
    std::string getName();
};

class Rook: public Piece {
public:
    Rook(std::string color);
    std::string getColor();
};

class Bishop: public Piece {
public:
    Bishop(std::string color);
    std::string getColor();
};

class Knight: public Piece {
public:
    Knight(std::string color);
    std::string getColor();
};

class King: public Piece {
public:
    King(std::string color);
    std::string getColor();
};

class Queen: public Piece {
public:
    Queen(std::string color);
    std::string getColor();
};

class Pawn: public Piece {
public:
    Pawn(std::string color);
    std::string getColor();
};

#endif