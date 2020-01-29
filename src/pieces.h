// -*- lsst-c++ -*-

/* 
 * This file is part of cpp-chess.h
 *
 * Copyright (c) 2020 GUILHERME VASCONCELOS, JOHN VICTOR
 * Distributed under the MIT License (license terms at https://opensource.org/licenses/MIT)
 * 
 */

#ifndef PIECES_H
#define PIECES_H

#include <iostream>

/**
 * class Color is used to define each piece's color (see class Piece below)
 */
enum class Color {white, black};

/**
 * class Piece is used as a base class for class Rook, Bishop, etc.
 */
class Piece {
protected:
    /**
     * name stores a letter that represents the piece
     * uppercase letters represent white pieces
     * and lowercase letters represent black pieces, following FEN's convention
     * P for pawn, K for king, Q for queen, R for rook, B for bishop, N for knight
     */
    std::string name;

    /**
     * Each position of the board must have a piece. Because of this,
     * we have a nullPiece attribute, which is used to check whether the object
     * belongs to class NullPiece or not. NullPieces do nothing, they are just
     * placeholders for empty board positions.
     */
    bool nullPiece;

    /**
     * Attribute color stores the piece's color (white or black)
     * it belongs to enum class Color, defined above
     */
    Color color;
public:
    Piece();
    int positionX;
    int positionY;

    /**
     * Method getName is used to get the name of the piece
     * Example:
     *     Bishop bishop = Bishop(Color::white);
     *     bishop.getName();
     * @return std::string
     */
    std::string getName();

    /**
     * Method getColor is used to get the color of a piece
     * Example:
     *     Queen queen = Queen(Color::black);
     *     queen.getColor();
     * @return Color
     */
    Color getColor();

    /**
     * Method isNullPiece is a getter for the attribute nullPiece
     * Example:
     *     King king = King(Color::white);
     *     kinng.isNullPiece();
     * @return bool
     */
    bool isNullPiece();

    virtual ~Piece() {};
};

/**
 * class Rook inherits from Piece
 * and is used to instance rooks
 */
class Rook: public Piece {
public:
    Rook(Color color);
};

/**
 * class Bishop inherits from Piece
 * and is used to instance bishops
 */
class Bishop: public Piece {
public:
    Bishop(Color color);
};

/**
 * class Knight inherits from Piece
 * and is used to instance knights
 */
class Knight: public Piece {
public:
    Knight(Color color);
};

/**
 * class King inherits from Piece
 * and is used to instance kings
 */
class King: public Piece {
public:
    King(Color color);
};

/**
 * class Queen inherits from Piece
 * and is used to instance queens
 */
class Queen: public Piece {
public:
    Queen(Color color);
};

/**
 * class Pawn inherits from Piece
 * and is used to instance pawns
 */
class Pawn: public Piece {
public:
    Pawn(Color color);
};

/**
 * class NullPiece inherits from Piece
 * and is used to instance nullPieces, which are
 * placeholders for empty positions at the chess board
 */
class NullPiece: public Piece {
public:
    NullPiece();
};

#endif
