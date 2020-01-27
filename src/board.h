#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "pieces.h"

class Board {
public:
    Board();
    void showBoard();
    std::vector<std::vector<Piece>> piece;
};

#endif