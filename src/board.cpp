#include <iostream>
#include <sstream>
#include "board.h"
#include "pieces.h"

Board::Board() {
    for(int i=0; i<8; ++i) {
        Piece piece;
        this->piece.push_back(std::vector<Piece>(8, piece));
    }
}

void Board::showBoard() {
    std::stringstream ss;
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            ss << this->piece.at(i).at(j).getName() << "   " << std::flush;
        }
        ss << std::endl;
    }
    std::cout << ss.str() << std::flush;
}