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
private:
    std::string color;
public:
    Rook(std::string color);
    std::string getColor();
};

class Bishop: public Piece {
private:
    std::string color;
public:
    Bishop(std::string color);
    std::string getColor();
};

class Knight: public Piece {
private:
    std::string color;
public:
    Knight(std::string color);
    std::string getColor();
};

class King: public Piece {
private:
    std::string color;
public:
    King(std::string color);
    std::string getColor();
};

class Queen: public Piece {
private:
    std::string color;
public:
    Queen(std::string color);
    std::string getColor();
};

class Pawn: public Piece {
private:
    std::string color;
public:
    Pawn(std::string color);
    std::string getColor();
};

#endif