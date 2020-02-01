# cpp-chess

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A (work in progress) C++ library with Unit Tests made for the board game Chess.

Could be used in the backend of your website for playing Chess, or your desktop client, or perhaps as the base for your Chess Engine.

---

## Index

- [Features](#features)
- [Installing and Setup](#setup)
- [Usage](#usage)
- [Making and running tests](#unit-tests)
- [Planned Features](#planned-features)

---

### Features

- Creating Chess Board instance
- Moving pieces with algebriac notation
- Printing ASCII representation of the board's state
- Instance Board state from FEN

---

### Setup

- Clone the project with [git](https://git-scm.com/):
    ```bash
    git clone https://github.com/Guilherme-Vasconcelos/cpp-chess.git
    ```

- Cd into the project's directory:
    ```bash
    cd cpp-chess
    ```

- Compile and run example located at [`examples/main.cpp`](examples/main.cpp):
    ```bash
    make example
    ```

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

### Unit Tests

**Creating and running Unit Tests**

- Tests are located in the [`tests`](tests) folder, and must be prefixed with `tests_`

- All test files must include the Catch2 Header file
    ```cpp
    #include "catch.hpp"
    ```

    > **Warning:** the `#define CATCH_CONFIG_MAIN` line must only be present on the [`tests_main.cpp`](tests/tests_main.cpp) file, [read more](https://github.com/catchorg/Catch2/blob/master/docs/slow-compiles.md)

- Documentation on writing tests using the [`Catch2`](https://github.com/catchorg/Catch2) library can be found [here](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#writing-tests)
    - Also look at other files already present at [`tests`](tests) for example usage

- After writing the tests they can be compiled and ran with
    ```
    make test
    ```

    - First time compiling and running tests will be very slow, since it needs to pre-compile the Catch2 library, but after compiling it once, running this will only compile the new tests you made, so it won't take as long

---

### Planned Features

- Check and Checkmate
- Invalidating illegal moves
- Castling
- En passant
- Check for draws
- Single-header file for ease of usage
- Listing legal moves for a specific piece
- Generating image of the current Board state
- Getting PGN of current game
- Generate Game from PGN file/text
- Move times and game clock
- Stockfish analysis of current position and potential moves
- Python API
