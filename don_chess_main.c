// Don's Array Chess Project
// don_chess_main.c
//
// This program allows the user to play a game of Chess
//
// This program was written by Donald Danilo from 20.12.2024 to 21.12.2024
//
// Description
// This program allows the user to play a simple game of chess with another person via
// the use of a 2D array struct coupled with user commands in the terminal. This program
// utilises three files (don_chess_main.c, don_chess_functions.c and don_chess_header.h).
//
// Limitations
// This program will only trigger stalemate when one player cannot make a move, it
// will not trigger due to other conditions such as too many king moves or
// move repetition.

// Header File
#include "don_chess_header.h"

// Main function
int main(void) {
    struct board board[BOARD_LENGTH][BOARD_HEIGHT];
    setup(board);
    start_game();
    game_loop(board);

    return 0;
}
