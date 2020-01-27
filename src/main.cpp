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

    Bishop bishop;
    Queen queen;
    King king;
    Pawn pawn;

    board.piece.at(0).at(0) = bishop;
    board.piece.at(0).at(1) = king;
    board.piece.at(0).at(1) = queen;
    board.piece.at(0).at(2) = pawn;

    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            std::cout << board.piece.at(i).at(j).getName() << "   " << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}