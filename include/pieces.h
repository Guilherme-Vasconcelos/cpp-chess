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
#include <vector>

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
     * the vector below will store the legal squares that a piece can go
     * for example, a pawn on a2 can either go to a3 or a4
     * so legalSquares for that pawn would be {"a3", "a4"}
     */
    std::vector<std::string> legalSquares;

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

    /**
     * This method will be used internally to update the legal
     * squares where the piece can move.
     * @param piecePosition a string with the piece position (e.g "a3", "g5")
     * @return void
     */
    void updateLegalSquares(std::string piecePosition);

    /**
     * Used to convert algebraic notation to a vector containing x, y coordinates
     * e.g convertAlgebraicToInt("a8") returns the std::vector {0, 0}
     * Notice that the board matrix left-top position is 0, 0, then each row
     * increases the x-coordinate by 1 and each column increases the y-coordinate by 1
     * @param algebraicPosition a string with the position to convert
     * @return std::vector<int> with two elements: row and column
     */
    std::vector<int> convertAlgebraicToInts(std::string algebraicPosition);

    virtual ~Piece() {};
};

/**
 * class Rook inherits from Piece
 * and is used to instance rooks
 */
class Rook: public Piece {
public:
    Rook(Color color);
    void updateLegalSquares(std::string piecePosition);
    std::vector<std::string> legalSquares;
};

/**
 * class Bishop inherits from Piece
 * and is used to instance bishops
 */
class Bishop: public Piece {
public:
    Bishop(Color color);
    void updateLegalSquares(std::string piecePosition);
    std::vector<std::string> legalSquares;
};

/**
 * class Knight inherits from Piece
 * and is used to instance knights
 */
class Knight: public Piece {
public:
    Knight(Color color);
    void updateLegalSquares(std::string piecePosition);
    std::vector<std::string> legalSquares;
};

/**
 * class King inherits from Piece
 * and is used to instance kings
 */
class King: public Piece {
public:
    King(Color color);
    void updateLegalSquares(std::string piecePosition);
    std::vector<std::string> legalSquares;
};

/**
 * class Queen inherits from Piece
 * and is used to instance queens
 */
class Queen: public Piece {
public:
    Queen(Color color);
    void updateLegalSquares(std::string piecePosition);
    std::vector<std::string> legalSquares;
};

/**
 * class Pawn inherits from Piece
 * and is used to instance pawns
 */
class Pawn: public Piece {
public:
    Pawn(Color color);
    void updateLegalSquares(std::string piecePosition);
    std::vector<std::string> legalSquares;
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
