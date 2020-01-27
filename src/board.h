#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "pieces.h"

class Board {
public:
    std::vector<std::vector<Piece>> piece;
};

#endif