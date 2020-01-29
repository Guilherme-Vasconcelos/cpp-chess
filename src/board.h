// -*- lsst-c++ -*-

/* 
 * This file is part of cpp-chess.h
 *
 * Copyright (c) 2020 GUILHERME VASCONCELOS, JOHN VICTOR
 * Distributed under the MIT License (license terms at https://opensource.org/licenses/MIT)
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "pieces.h"

/**
 * Board class contains necessary methods to deal
 * with boards, setting pieces, etc.
 */
class Board {
private:
    /**
     * currentFen stores the current FEN value 
     * It is a std::string type with the current game's FEN
     * setter: setFenPosition (see below)
     * getter: getCurrentFen (see below)
     */
    std::string currentFen;
public:
    Board();

    /**
     * 8x8 matrix of Pieces to represent the chess board
     * setter: place (see below)
     * getter: get (see below)
     */
    std::vector<std::vector<Piece>> pieces;

    /**
     * Method used to show the current board. Example:
     *     Board.showBoard();
     * @return void
     */
    void showBoard();

    /**
     * Method used to place a piece at the board instance (using algebraic notation)
     * Example:
     *     Board.place(bishop, "h1");
     * @param piece Piece (or any derived class, such as Bishop) instance
     * @param position std::string (using algebraic notation) representing where you want to place the piece
     * @return void
     */
    void place(Piece piece, std::string position);

    /**
     * Method used to find out which piece is at a given position (using algebraic notation)
     * Example: 
     *     Board.get("a1").getName();
     * @param position std::string (using algebraic notation) representing the position to analyze
     * @return Piece (or any derived class) instance that is in the given position
     */
    Piece get(std::string position);

    /**
     * Method used to set a custom FEN position
     * Example: 
     *     Board.setFenPosition("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
     * @param fen a std::string representing the FEN you want to set
     * @return void
     */
    void setFenPosition(std::string fen);

    /**
     * Method used to get the current position's FEN
     * Example: 
     *     Board.getCurrentFen();
     * @return std::string with current position's FEN
     */
    std::string getCurrentFen();
};

#endif
