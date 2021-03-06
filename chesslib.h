/********************************************************************/
/*                            chesslib.h                            */
/*                   API for the chesslib.c library                 */
/*                                                                  */
/*                    by <cyberchiller@gmail.com>                   */
/*                                                                  */
/********************************************************************/

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#if defined(__MINGW32__) || defined(_WIN32)
# ifdef BUILD_CHESSLIB_DLL
#  define CHESSLIB_DLL __declspec(dllexport)
# else
#  define CHESSLIB_DLL __declspec(dllimport)
# endif
# ifndef UNICODE
#  define UNICODE
# endif
# ifndef _UNICODE
#  define _UNICODE
# endif
# include <windows.h>
#elif defined(__unix__) || defined(__gnu_linux__) || defined(__APPLE__)
# define KRED  "\x1B[31m"
# define KYEL  "\x1B[33m"
# define RESET "\033[0m"
# include <termcap.h>
# include <alloca.h>
#else
# error Non-compatible OS or compiler
#endif

#define MOS 17	/*this one controls the chess board size, don't mess with it*/
#define WHITE 2
#define BLACK 1
#define EMPTY 0
#define BANNER_SPEED 100 - R_SPEED
#define R_SPEED 80	/*speed of the animated banner, bigger value bigger speed; maximum value is 99*/
#define s_l 26	/*length of the filename string*/
#define ALL_CASTL_TRUE {true, true, true, true, true, true}
#define CSTL_LEFTROOK "l"
#define CSTL_RIGHTROOK "r"

typedef struct ch_template {
	char current ;	/*current piece letter, e for empty square*/
	char square[2];	/*current square on the board eg.A1,H4*/
	bool occ;	/*flag to check if square is occupied*/
	int c;	/*piece color, 0 if there is no piece, 1 for black, 2 for white*/
} ch_template;

typedef struct CastlingBool {
	bool WR_left;
	bool WR_right;
	bool BR_left;
	bool BR_right;
	bool KBlack;
	bool KWhite;
} CastlingBool;

typedef enum KingState {
	check,
	checkmate,
	safe,	/*King is safe (not threatened in his 3x3 vicinity*/
	safe_check	/*King is not allowed to move to certain squares*/
} KingState;

/*possible moves that each King can do after a check situation
 *for example WKingMoves = "A8 H4 B3"*/
extern char *WKingMoves;
extern char *BKingMoves;

/*if a castling situation is possible the value of this boolean is true*/
extern bool cstl_is_enabled;

/*prototypes for the main library*/
/*fill a ch_template[8][8] chess board, with chess pieces, recursively*/
void initChessboard(ch_template[][8], unsigned, char);

/*function to print the board at any given point in the game; second argument is
 *a character to determine the type of chessboard that will be printed (only works on Linux for now)*/
void printBoard(ch_template[][8], const char);

/*traverses the chessboard, finds and returns the piece that is capable 
 *to perform the move entered by the player if more than one piece can move
 *to the square entered by the player it finds and returns them both*/
char *findPiece(ch_template[][8], const char*, int);

/*move the piece if no other piece is in the way; also checks for pawn promotion*/
bool movePiece(ch_template[][8], char*, char[2], int);

/*checks if a move is valid based on whether the piece overlaps other pieces or not*/
bool piecesOverlap(ch_template[][8], const int, const int, const int , const int, const char);

/*check for validity of player input*/
bool validInput(const char*, int*);

/*create a string with the current date to be used as the log date_filename*/
void date_filename(char*, int);

/*write each player's moves to a log file*/
void write_to_log(int, FILE*, char*, char[]);

/*basic error printing function; writes output to stderr*/
void printError(int);

/*copies the input buffer to a string and return that string*/
char *getPlayerInput(void);

/*handles move conflict: whether two pieces of the same kind and color 
 *are able to move in the same square at the same round*/
char *pieceConflict(const char*, const char);

/*finds and saves the state of each King for the current round; see 
 *the KingState enum for all the states a King can have*/
void findKState(ch_template[][8], KingState*, KingState*);

/*takes care of all the moves that happen during castling; only call it if cstl_is_enabled is true*/
void setCastling(ch_template[][8], char*, int);

/*functions I created to adjust my own chess game*/
inline void clear_screen(void);
inline void clear_buffer(void);
inline void printBanner(const char*);
inline void printInstructions(void);
