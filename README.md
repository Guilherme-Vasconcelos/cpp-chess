### Features

- Creating Chess Board instance
- Moving pieces with algebriac notation
- Printing ASCII representation of the board's state
- Instance Board state from FEN

---

### Usage

- Instancing board and moving pieces
    ```cpp
    Board board;

    board.showBoard();

    board.move("e2", "e4");
    board.showBoard();

    board.move("c7", "c5");
    board.showBoard();
    ```

    ![image](https://user-images.githubusercontent.com/37747572/73504418-1c83ed80-43ae-11ea-8c5f-5ec617372809.png)

- Instancing board at specific position with FEN
    ```cpp
    Board board = Board("2bqnrk1/5p1p/5PpQ/3pP1P1/2pP1R2/2P3N1/6BP/1q4K1");
 
    board.showBoard();
    ```

    ![image](https://user-images.githubusercontent.com/37747572/73504888-a3859580-43af-11ea-9904-edacf0174385.png)
---

### Planned Features

- Check and Checkmate
- Invalidating illegal moves
- Castling
- En passant
- Check for draws
- Listing legal moves for a specific piece
- Generating image of the current Board state
- Getting PGN of current game
- Generate Game from PGN file/text
- Move times and game clock
- Stockfish analysis of current position and potential moves
- Python API
