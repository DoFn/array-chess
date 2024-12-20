// Don's Array Chess Project Function File
// don_chess_functions.c
//
// This file contains the user defined functions used in Don's Array Chess Project

// Header Files
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "don_chess_header.h"

// Function Implementations:


// Setup Functions

// This function sets the initial board state
void setup (struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    piece_setup(board);
    colour_setup(board);
}

// This function sets the initial piece placements
void piece_setup (struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    // First, set every unoccupied tile to movement
    int column_index = 0;
    int row_index = WHITE_PAWN_ROW + 1;
    while (row_index < BLACK_PAWN_ROW) {
        board[column_index][row_index].piece = EMPTY;
        column_index++;
        if (column_index == BOARD_LENGTH) {
            column_index = 0;
            row_index++;
        }
    }

    // Set pawn positions for white and black, using while loop.
    column_index = 0;
    while (column_index < BOARD_LENGTH) {
        board[column_index][WHITE_PAWN_ROW].piece = PAWN;
        board[column_index][BLACK_PAWN_ROW].piece = PAWN;
        column_index++;
    }
    // Next, set positions of other pieces.
    board[0][0].piece = ROOK;
    board[7][0].piece = ROOK;
    board[0][7].piece = ROOK;
    board[7][7].piece = ROOK;

    board[1][0].piece = KNIGHT;
    board[6][0].piece = KNIGHT;
    board[1][7].piece = KNIGHT;
    board[6][7].piece = KNIGHT;

    board[2][0].piece = BISHOP;
    board[5][0].piece = BISHOP;
    board[2][7].piece = BISHOP;
    board[5][7].piece = BISHOP;

    board[3][0].piece = QUEEN;
    board[4][0].piece = KING;
    board[3][7].piece = QUEEN;
    board[4][7].piece = KING;
}

// This function sets the initial piece colours and movement status to STATIC
void colour_setup (struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    int col_index = 0;
    int row_index = 0;
    while (row_index < BOARD_LENGTH) {
        if (row_index <= WHITE_PAWN_ROW) {
            board[col_index][row_index].colour = WHITE;
        } else if (row_index >= BLACK_PAWN_ROW) {
            board[col_index][row_index].colour = BLACK;
        } else {
            board[col_index][row_index].colour = NONE;
        }
        board[col_index][row_index].movement = STATIC;
        col_index++;
        if (col_index == BOARD_LENGTH) {
            col_index = 0;
            row_index++;
        }
    }
}


// Print Functions


// This function prints the current board state
void print_board (struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    int row_index = 7;
    int col_index = 0;
    printf("+---+---+---+---+---+---+---+---+\n");
    while (row_index >= 0) {
        printf("|");
        print_piece(board[col_index][row_index].piece, board[col_index][row_index].colour);
        col_index++;
        if (col_index == BOARD_LENGTH) {
            col_index = 0;
            row_index--;
            printf("|\n");
            printf("+---+---+---+---+---+---+---+---+\n");
        }
    }
}

// This function prints a piece
void print_piece (enum piece piece, enum colour colour) {
    switch (piece) {
        case PAWN:
            if (colour == WHITE) {
                printf("<P>");
            } else {
                printf("[p]");
            }
            break;
        case ROOK:
            if (colour == WHITE) {
                printf("<R>");
            } else {
                printf("[r]");
            }
            break;
        case KNIGHT:
            if (colour == WHITE) {
                printf("<H>");
            } else {
                printf("[h]");
            }
            break;
        case BISHOP:
            if (colour == WHITE) {
                printf("<B>");
            } else {
                printf("[b]");
            }
            break;
        case QUEEN:
            if (colour == WHITE) {
                printf("<Q>");
            } else {
                printf("[q]");
            }
            break;
        case KING:
            if (colour == WHITE) {
                printf("<K>");
            } else {
                printf("[k]");
            }
            break;
        case EMPTY:
            printf("   ");
            break;
    }
}


// Game Introduction Functions


// This function introduces the user to the game
void start_game (void) {
    printf("Welcome To Don's Array Chess!\n\n");
    char command;
    printf("Enter i For Basic Information Or s To Skip: ");
    while (scanf(" %c", &command) != EOF && command != 's' && command != 'i' ) {
        printf("ERROR: INVALID INPUT\n");
        printf("Enter i For A Basic Tutorial Or s To Skip: ");
    }
    if (command == 'i') {
        tutorial();
    }
}

// This function explains how to operate the game to the user
void tutorial (void) {
    char command;
    printf("\nThis Game Operates Like A Normal Game Of Chess, Where Moves\n");
    printf("Are Specified Using The Format,\n");
    printf("(letter1) (number1) (letter2) (number2),\n");
    printf("Where letter1 and number1 Correspond To The Column And Row Of The Piece Being Moved,\n");
    printf("Whilst letter2 and number2 Correspond To The Column And Row Of Where The Piece Is Moving To\n");
    printf("Ensure These Letters Are Lowercase When Entering A Movement\n");
    printf("For Example, e 2 e 4\n");
    printf("Enter c to continue: ");
    while (scanf(" %c", &command) != EOF && command != 'c') {
        printf("ERROR: INVALID INPUT\n");
        printf("Enter c to continue: ");
    }
    if (command != 'c') {
        return;
    }
    printf("\nIn This Game, Pieces Are Denoted Using Letters, Whilst Their Colour\n");
    printf("Is Denoted By Using Brackets And Capitalisation\n");
    printf("These Can Be Interpreted As The Following, \n");
    printf("P - Pawn\n");
    printf("R - Rook\n");
    printf("H - Knight\n");
    printf("B - Bishop\n");
    printf("Q - Queen\n");
    printf("K - King\n");
    printf("<> - White\n");
    printf("[] - Black\n");
    printf("CAPITALS = White, lowercase = Black\n");
    printf("For Example <B> Denotes A White Bishop\n");
    printf("Enter c to continue: ");
    while (scanf(" %c", &command) != EOF && command != 'c') {
        printf("ERROR: INVALID INPUT\n");
        printf("Enter c to continue: ");
    }
    if (command != 'c') {
        return;
    }
    printf("\nAdditionally For Special Moves, Do The Following\n");
    printf("For En Passant, Specify Coordinates Normally\n");
    printf("For Castling, Specify The Movement Of The King And Not The Rook\n");
    printf("This Concludes The Tutorial, Enter s To Start ");
    while (scanf(" %c", &command) != EOF && command != 's') {
        printf("ERROR: INVALID INPUT\n");
        printf("Enter s to start: ");
    }
    if (command != 'c') {
        return;
    }
}


// Gameplay Loop Functions


// This function runs the game until a win/loss condition is encountered
void game_loop (struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    print_board(board);
    print_turn(WHITE);
    int turn = WHITE;
    int tracker = NONE;
    enum game_status status = ONGOING;
    enum game_status *status_pointer = &status;
    struct movement_indexes movement;
    int move_status;
    while (status == ONGOING) {
        movement = scan_move(status_pointer, turn);
        move_status = valid_move(movement, board, turn);
        if (move_status == VALID_MOVE) {
            piece_place(movement, board);
            promotion(movement, board, status_pointer);
            print_board(board);
            turn = turn_flip(turn);
            if (check_check(board) != NONE) {
                printf("Check\n");
                tracker = any_move(board, turn);
            } 
            if (tracker != NONE) {
                status = TERMINATED;
            } else {
                print_turn(turn);
            }
        } else {
            printf("ERROR: INVALID MOVE\n");
            print_turn(turn);
        }
    }

    // Handle end of game messages
    if (status == TERMINATED && tracker == NONE) {
        printf("INPUT TERMINATED: ENDING GAME\n");
    } else if (tracker == WHITE) {
        printf("mate, Black Wins\n");
    } else if (tracker == BLACK) {
        printf("mate, White Wins\n");
    }
}

// This function scans user input for the movements on the chess board,
// and returns the appropriate indexes of these positions on the board. If user input
// is invalid this function will return an error message and loop until appropriate
// input is given
struct movement_indexes scan_move (enum game_status *status_pointer, int turn) {
    int status = INVALID;
    struct movement_indexes movement_indexes;

    char col1;
    char col2;
    int row1;
    int row2;

    // Scan user input until valid input is given, if EOF is inputted, set
    // status to TERMINATED using pointer
    while (status == INVALID) {
        if (scanf(" %c", &col1) == EOF) {
            *status_pointer = TERMINATED;
        } else if (scanf(" %d", &row1) == EOF) {
            *status_pointer = TERMINATED;
        } else if (scanf(" %c", &col2) == EOF) {
            *status_pointer = TERMINATED;
        } else if (scanf(" %d", &row2) == EOF) {
            *status_pointer = TERMINATED;
        }
        if (col1 <= 'h' && col2 <= 'h' && col1 >= 'a' && col2 >= 'a') {
            if (row1 <= 8 && row2 <= 8 && row1 >= 1 && row2 >= 1) {
                status = VALID;
            }
        }
        if (status != VALID) {
            printf("ERROR: INVALID INPUT\n");
            print_turn(turn);
        }
    }

    // Convert user commands into appropriate index values
    movement_indexes.col_1 = col1 - 'a';
    movement_indexes.col_2 = col2 - 'a';
    movement_indexes.row_1 = row1 - 1;
    movement_indexes.row_2 = row2 - 1;

    return movement_indexes;
}

// This function checks whether the requested move is valid
int valid_move (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT], int turn) {
    // First make sure that move is usually legal
    int status;
    status = possible_move(movements, board, turn);

    // If move is legal, create a copy of the board, execute move, and look for checks, then execute
    // move if all checks are allowed during this turn i.e. not moving into check
    if (status != INVALID_MOVE) {
        struct board prototype[BOARD_LENGTH][BOARD_HEIGHT];
        copyboard(board, prototype);
        piece_place(movements, prototype);
        if (check_check(prototype) != turn_flip(turn) && check_check(prototype) != NONE) {
            status = INVALID_MOVE;
        }
    }

    return status;
}

// This function checks whether the requested move is possible for a piece regardless of check
int possible_move (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT], int turn) {
    // Return early if player selected an empty tile, tile containing piece
    // that is not to move this turn, or player attempting to capture friendly
    // piece
    if (board[movements.col_1][movements.row_1].colour != turn) {
        return INVALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == board[movements.col_2][movements.row_2].colour) {
        return INVALID_MOVE;
    }

    // Assess validity of remaining moves using appropriate functions
    switch(board[movements.col_1][movements.row_1].piece) {
        case PAWN:
            return valid_move_pawn(movements, board);
        case ROOK:
            return valid_move_rook(movements, board);
        case BISHOP:
            return valid_move_bishop(movements, board);
        case QUEEN:
            return valid_move_queen(movements, board);
        case KING:
            return valid_move_king(movements, board);
        case KNIGHT:
            return valid_move_knight(movements, board);
    }
}

int valid_move_pawn (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    int status = INVALID_MOVE;
    // Set status to VALID_MOVE if pawn is moving forward appropriately
    if (board[movements.col_1][movements.row_1].colour == WHITE && movements.col_1 == movements.col_2 
    && movements.row_1 == movements.row_2 - 1) {
        status = VALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == WHITE && movements.col_1 == movements.col_2 
    && movements.row_1 == movements.row_2 - 2 && board[movements.col_1][movements.row_1].movement == STATIC) {
        status = VALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == BLACK && movements.col_1 == movements.col_2 
    && movements.row_1 == movements.row_2 + 1) {
        status = VALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == BLACK && movements.col_1 == movements.col_2 
    && movements.row_1 == movements.row_2 + 2 && board[movements.col_1][movements.row_1].movement == STATIC) {
        status = VALID_MOVE;
    }

    // If status is valid but tile to move onto is not empty, return INVALID_MOVE as
    // moving forward is only valid for an empty tile. Otherwise return valid
    if (status == VALID_MOVE && board[movements.col_2][movements.row_2].piece != EMPTY) {
        return INVALID;
    } else if (status == VALID_MOVE) {
        return VALID;
    }

    // Set status to VALID_MOVE if pawn is moving diagonally appropriately
    if (board[movements.col_1][movements.row_1].colour == WHITE && movements.col_1 == movements.col_2 + 1 
    && movements.row_1 == movements.row_2 - 1) {
        status = VALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == WHITE && movements.col_1 == movements.col_2 - 1 
    && movements.row_1 == movements.row_2 - 1) {
        status = VALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == BLACK && movements.col_1 == movements.col_2 + 1 
    && movements.row_1 == movements.row_2 + 1) {
        status = VALID_MOVE;
    } else if (board[movements.col_1][movements.row_1].colour == BLACK && movements.col_1 == movements.col_2 - 1 
    && movements.row_1 == movements.row_2 + 1) {
        status = VALID_MOVE;
    }

    // If status is valid but tile to move onto is empty
    // set status to INVALID_MOVE and assess en passant
    if (status == VALID_MOVE && board[movements.col_2][movements.row_2].piece == EMPTY) {
        status = INVALID;
    }

    return status;
}

// This function checks whether the requested move is valid for a rook
int valid_move_rook (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    int direction = UNKNOWN_DIRECTION;
    int status = VALID_MOVE;
    // Find direction that rook is moving
    if (movements.col_1 == movements.col_2 && movements.row_1 > movements.row_2) {
        direction = DOWN;
    } else if (movements.col_1 == movements.col_2 && movements.row_1 < movements.row_2) {
        direction = UP;
    } else if (movements.col_1 > movements.col_2 && movements.row_1 == movements.row_2) {
        direction = LEFT;
    } else if (movements.col_1 < movements.col_2 && movements.row_1 == movements.row_2) {
        direction = RIGHT;
    }

    // Return if rook movement is not in a straight line
    if (direction == UNKNOWN_DIRECTION) {
        return INVALID_MOVE;
    }

    // Ensure that no piece is blocking the path of the rook
    int col_index = movements.col_1;
    int row_index = movements.row_1;
    while (col_index + row_index != movements.col_2 + movements.row_2) {
        if (board[col_index][row_index].piece != EMPTY && col_index + row_index != movements.col_1 + movements.row_1) {
            status = INVALID;
        }
        if (direction == DOWN) {
            row_index--;
        } else if (direction == UP) {
            row_index++;
        } else if (direction == LEFT) {
            col_index--;
        } else if (direction == RIGHT) {
            col_index++;
        }
    }
    return status;
}

// This function checks whether the requested move is valid for a bishop
int valid_move_bishop (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    // Make sure bishop is moving diagonally, else return INVALID_MOVE 
    if (fabs(movements.col_1) - fabs(movements.col_2) != fabs(movements.row_1) - fabs(movements.row_2) || 
    movements.col_1 == movements.col_2) {
        return INVALID_MOVE;
    }

    // Find diagonal bishop is moving along
    int diagonal = UNKNOWN_DIAGONAL;
    if (movements.col_1 > movements.col_2 && movements.row_1 > movements.row_2) {
        diagonal = DOWN_LEFT;
    } else if (movements.col_1 < movements.col_2 && movements.row_1 > movements.row_2) {
        diagonal = DOWN_RIGHT;
    } else if (movements.col_1 > movements.col_2 && movements.row_1 < movements.row_2) {
        diagonal = UP_LEFT;
    } else if (movements.col_1 < movements.col_2 && movements.row_1 < movements.row_2) {
        diagonal = UP_RIGHT;
    }

    // Ensure that no piece is blocking path of bishop
    int col_index = movements.col_1;
    int row_index = movements.row_1;
    int status = VALID_MOVE;
    while (row_index != movements.row_2) {
        if (board[col_index][row_index].piece != EMPTY && row_index != movements.row_1) {
            status = INVALID_MOVE;
        }
        if (diagonal == DOWN_LEFT) {
            col_index--;
            row_index--;
        } else if (diagonal == DOWN_RIGHT) {
            col_index++;
            row_index--;
        } else if (diagonal == UP_LEFT) {
            col_index--;
            row_index++;
        } else if (diagonal == UP_RIGHT) {
            col_index++;
            row_index++;
        }
    }
    return status;
}

// This function checks whether the requested move is valid for a queen
int valid_move_queen (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    if (valid_move_bishop(movements, board) == VALID_MOVE) {
        return VALID_MOVE;
    } else if (valid_move_rook(movements, board) == VALID_MOVE) {
        return VALID_MOVE;
    } else {
        return INVALID_MOVE;
    }
}

// This function checks whether the requested move is valid for a king
int valid_move_king (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    if (valid_move_queen(movements, board) == VALID_MOVE) {
        if (fabs(movements.row_1 - movements.row_2) <= 1 && fabs(movements.col_1 - movements.col_2) <= 1) {
            return VALID_MOVE;
        } else {
            return INVALID_MOVE;
        }
    }

    int status = INVALID;
    return status;
}

// This function checks whether the requested move is valid for a knight
int valid_move_knight (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    int status = INVALID_MOVE;
    if (fabs(movements.col_1 - movements.col_2) == 1 && fabs(movements.row_1 - movements.row_2) == 2) {
        status = VALID_MOVE;
    } else if (fabs(movements.col_1 - movements.col_2) == 2 && fabs(movements.row_1 - movements.row_2) == 1) {
        status = VALID_MOVE;
    }
    return status;
}

// This function will place a piece in another square, leaving its original square empty
// and removing the piece occupying its new square if it exists
void piece_place (struct movement_indexes movements, struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    board[movements.col_2][movements.row_2].piece = board[movements.col_1][movements.row_1].piece;
    board[movements.col_1][movements.row_1].piece = EMPTY;
    board[movements.col_2][movements.row_2].movement = MOBILE;
    board[movements.col_1][movements.row_1].movement = STATIC;
    board[movements.col_2][movements.row_2].colour = board[movements.col_1][movements.row_1].colour;
    board[movements.col_1][movements.row_1].colour = NONE;
}

// This function will switch the current turn when a move is executed
int turn_flip (int turn) {
    if (turn == WHITE) {
        turn = BLACK;
    } else {
        turn = WHITE;
    }
    return turn;
}

// This function will print a message prompting user input each turn
void print_turn (int turn) {
    if (turn == WHITE) {
        printf("White Move: ");
    } else {
        printf("Black Move: ");
    }
}

// This function checks whether a piece is to be promoted, and executes the promotion if so
void promotion (struct movement_indexes movement, struct board board[BOARD_LENGTH][BOARD_HEIGHT], 
enum game_status *game_status) {
    int status = INVALID;
    // Make sure promotion is valid
    if (board[movement.col_2][movement.row_2].colour == WHITE && movement.row_2 == 7) {
        status = VALID;
    } else if (board[movement.col_2][movement.row_2].colour == BLACK && movement.row_2 == 0) {
        status = VALID;
    }

    // Make sure unit is pawn, otherwise set to INVALID
    if (board[movement.col_2][movement.row_2].piece != PAWN) {
        status = INVALID;
    }

    // If promotion is valid, prompt user input for promotion until valid input
    // is given, then execute promotion
    if (status == VALID) {
        printf("Promotion Achieved! Format As Follows: R For Rook, K For Knight, B For Bishop, Q For Queen\n");
    }
    char promotion_command;
    while (status == VALID) {
        printf("Enter Promotion: ");
        status = INVALID;
        if (scanf(" %c", &promotion_command) == EOF) {
            *game_status = TERMINATED;
        } 

        if (promotion_command == COMMAND_BISHOP) {
            board[movement.col_2][movement.row_2].piece = BISHOP;
        } else if (promotion_command == COMMAND_ROOK) {
            board[movement.col_2][movement.row_2].piece = ROOK;
        } else if (promotion_command == COMMAND_KNIGHT) {
            board[movement.col_2][movement.row_2].piece = KNIGHT;
        } else if (promotion_command == COMMAND_QUEEN) {
            board[movement.col_2][movement.row_2].piece = QUEEN;
        } else {
            printf("ERROR: INVALID PROMOTION\n");
            status = VALID;
        }
    }
}

// This function checks whether either king is in check, and returns the
// colour of the king in check or NONE if not applicable. Alternatively,
// function will return BOTH if both kings are checked
int check_check (struct board board[BOARD_LENGTH][BOARD_HEIGHT]) {
    int search = WHITE;
    int status = INVALID;
    int return_value = NONE;
    int col_index = 0;
    int row_index = 0;

    // Determine if white king in check
    while (board[col_index][row_index].piece != KING || board[col_index][row_index].colour != WHITE) {
        col_index++;
        if (col_index == BOARD_LENGTH) {
            col_index = 0;
            row_index++;
        }
    }
    if (status != VALID) {
        status = in_range(board, row_index, col_index);
    }
    if (status == VALID) {
        return_value = WHITE;
    }
    status = INVALID;

    col_index = 0;
    row_index = 0;
    // Determine if black king is in check
    while (board[col_index][row_index].piece != KING || board[col_index][row_index].colour != BLACK) {
        col_index++;
        if (col_index == BOARD_LENGTH) {
            col_index = 0;
            row_index++;
        }
    }
    if (status != VALID) {
        status = in_range(board, row_index, col_index);
    }
    if (status == VALID && return_value == NONE) {
        return_value = BLACK;
    } else if (status == VALID && return_value != NONE) {
        return_value = BOTH;
    }
    return return_value;
}

// This function checks whether a piece is in range of attacking another piece
int in_range (struct board board[BOARD_LENGTH][BOARD_HEIGHT], int row, int col) {
    int search = turn_flip(board[row][col].colour);
    int status = INVALID;
    struct movement_indexes movements;
    movements.row_1 = 0;
    movements.col_1 = 0;
    movements.row_2 = row;
    movements.col_2 = col;
    int move;
    while (movements.row_1 < BOARD_LENGTH) {
        move = possible_move(movements, board, search);
        if (move == VALID_MOVE) {
            status = VALID;
        }
        movements.col_1++;
        if (movements.col_1 == BOARD_LENGTH) {
            movements.col_1 = 0;
            movements.row_1++;
        }
    }
    return status;
}

// This function will copy one board onto another
void copyboard (struct board board_copy[BOARD_LENGTH][BOARD_HEIGHT], 
struct board board_paste[BOARD_LENGTH][BOARD_HEIGHT]) {
    int row = 0;
    int col = 0;
    while (row < BOARD_HEIGHT) {
        board_paste[row][col].piece = board_copy[row][col].piece;
        board_paste[row][col].colour = board_copy[row][col].colour;
        board_paste[row][col].movement = board_copy[row][col].movement;
        col++;
        if (col == BOARD_LENGTH) {
            col = 0;
            row++;
        }
    }
}

// This function will check whether a player can perform a move without their
// king being put in or remaining in check
int any_move (struct board board[BOARD_LENGTH][BOARD_HEIGHT], int colour) {
    struct movement_indexes movements;
    movements.col_1 = 0;
    movements.col_2 = 0;
    movements.row_1 = 0;
    movements.row_2 = 0;
    int status = colour;
    while (movements.row_2 != BOARD_LENGTH && status != NONE) {
        if (valid_move(movements, board, colour) == VALID) {
            status = NONE;
        } else {
            movements.col_1++;
            if (movements.col_1 == BOARD_LENGTH) {
                movements.col_1 = 0;
                movements.row_1++;
            } 
            if (movements.row_1 == BOARD_HEIGHT) {
                movements.row_1 = 0;
                movements.col_2++;
            }
            if (movements.col_2 == BOARD_LENGTH) {
                movements.col_2 = 0;
                movements.row_2++;
            }
        }
    }
    return status;
}