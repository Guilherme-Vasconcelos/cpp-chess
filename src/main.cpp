#include <iostream>
#include <vector>
#include "pieces.h"
#include "board.h"

int main() {

    Board board;
    
    Queen queen = Queen(true);

    board.place(queen, 'h', 4);
    board.showBoard();

    return 0;
}