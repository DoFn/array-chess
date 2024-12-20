// Don's Array Chess Project Header File
// don_chess_header.h
//
// This file acts as a header file for Don's Array Chess Project

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Constants
#define BOARD_HEIGHT 8
#define BOARD_LENGTH 8
#define WHITE_PAWN_ROW 1
#define BLACK_PAWN_ROW 6
#define VALID 1
#define INVALID 0
#define COMMAND_BISHOP 'B'
#define COMMAND_ROOK 'R'
#define COMMAND_KNIGHT 'K'
#define COMMAND_QUEEN 'Q'
#define BOTH '3'

// Enums
enum piece {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum colour {
    NONE = 0,
    WHITE,
    BLACK
};

enum movement_status {
    STATIC,
    MOBILE
};

enum game_status {
    ONGOING,
    WHITE_WIN,
    BLACK_WIN,
    TERMINATED
};

enum move_status {
    INVALID_MOVE,
    VALID_MOVE,
    SPECIAL_VALID_MOVE
};

enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UNKNOWN_DIRECTION
};

enum diagonals {
    UP_RIGHT,
    UP_LEFT,
    DOWN_RIGHT,
    DOWN_LEFT,
    UNKNOWN_DIAGONAL
};

// Structs
struct board {
    enum piece piece;
    enum colour colour;
    enum movement_status movement;
};

struct movement_indexes {
    int row_1;
    int row_2;
    int col_1;
    int col_2;
};

// Function Prototypes

// Setup functions
void setup (struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
void piece_setup (struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
void colour_setup (struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
// Print functions
void print_board (struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
void print_piece (enum piece piece, enum colour colour);
// Game intro functions
void start_game (void);
void tutorial (void);
// Gameplay loop functions
void game_loop (struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
struct movement_indexes scan_move (enum game_status *status_pointer, int turn);
int valid_move (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT], int turn);
int possible_move (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT], int turn);
int valid_move_pawn (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int valid_move_rook (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int valid_move_bishop (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int valid_move_queen (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int valid_move_king (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int valid_move_knight (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
void piece_place (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int turn_flip(int turn);
void print_turn (int turn);
void promotion (struct movement_indexes movement, struct board board[BOARD_LENGTH][BOARD_HEIGHT], enum game_status *game_status);
int check_check (struct board board[BOARD_LENGTH][BOARD_HEIGHT]);
int in_range (struct board board[BOARD_LENGTH][BOARD_HEIGHT], int row, int col);
void copyboard (struct board board_copy[BOARD_LENGTH][BOARD_HEIGHT], 
struct board board_paste[BOARD_LENGTH][BOARD_HEIGHT]);
int any_move (struct board board[BOARD_LENGTH][BOARD_HEIGHT], int colour);

