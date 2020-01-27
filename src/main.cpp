#include <iostream>
#include <vector>
#include "pieces.h"
#include "board.h"

int main()
{
    Board board;
    for(int i=0; i<8; ++i) {
        Piece piece;
        board.piece.push_back(std::vector<Piece>(8, piece));
    }

    std::cout << std::endl;
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            std::cout << board.piece.at(i).at(j).getName() << "   " << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}