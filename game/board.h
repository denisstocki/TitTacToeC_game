// /****************************
// Maciej Gębala (CC BY-NC 4.0)
// Plansza ver. 0.1
// 2023-03-30
// ****************************/

#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

// Variable holding current state of the board
int board[5][5];

// Variable holding all possible winning states of the board
const int win[28][4][2] = { 
  { {0,0}, {0,1}, {0,2}, {0,3} },
  { {1,0}, {1,1}, {1,2}, {1,3} },
  { {2,0}, {2,1}, {2,2}, {2,3} },
  { {3,0}, {3,1}, {3,2}, {3,3} },
  { {4,0}, {4,1}, {4,2}, {4,3} },
  { {0,1}, {0,2}, {0,3}, {0,4} },
  { {1,1}, {1,2}, {1,3}, {1,4} },
  { {2,1}, {2,2}, {2,3}, {2,4} },
  { {3,1}, {3,2}, {3,3}, {3,4} },
  { {4,1}, {4,2}, {4,3}, {4,4} },
  { {0,0}, {1,0}, {2,0}, {3,0} },
  { {0,1}, {1,1}, {2,1}, {3,1} },
  { {0,2}, {1,2}, {2,2}, {3,2} },
  { {0,3}, {1,3}, {2,3}, {3,3} },
  { {0,4}, {1,4}, {2,4}, {3,4} },
  { {1,0}, {2,0}, {3,0}, {4,0} },
  { {1,1}, {2,1}, {3,1}, {4,1} },
  { {1,2}, {2,2}, {3,2}, {4,2} },
  { {1,3}, {2,3}, {3,3}, {4,3} },
  { {1,4}, {2,4}, {3,4}, {4,4} },
  { {0,1}, {1,2}, {2,3}, {3,4} },
  { {0,0}, {1,1}, {2,2}, {3,3} },
  { {1,1}, {2,2}, {3,3}, {4,4} },
  { {1,0}, {2,1}, {3,2}, {4,3} },
  { {0,3}, {1,2}, {2,1}, {3,0} },
  { {0,4}, {1,3}, {2,2}, {3,1} },
  { {1,3}, {2,2}, {3,1}, {4,0} },
  { {1,4}, {2,3}, {3,2}, {4,1} }
};

// Variable holding all possible losing states of the board
const int lose[48][3][2] = {
  { {0,0}, {0,1}, {0,2} }, { {0,1}, {0,2}, {0,3} }, { {0,2}, {0,3}, {0,4} }, 
  { {1,0}, {1,1}, {1,2} }, { {1,1}, {1,2}, {1,3} }, { {1,2}, {1,3}, {1,4} }, 
  { {2,0}, {2,1}, {2,2} }, { {2,1}, {2,2}, {2,3} }, { {2,2}, {2,3}, {2,4} }, 
  { {3,0}, {3,1}, {3,2} }, { {3,1}, {3,2}, {3,3} }, { {3,2}, {3,3}, {3,4} }, 
  { {4,0}, {4,1}, {4,2} }, { {4,1}, {4,2}, {4,3} }, { {4,2}, {4,3}, {4,4} }, 
  { {0,0}, {1,0}, {2,0} }, { {1,0}, {2,0}, {3,0} }, { {2,0}, {3,0}, {4,0} }, 
  { {0,1}, {1,1}, {2,1} }, { {1,1}, {2,1}, {3,1} }, { {2,1}, {3,1}, {4,1} }, 
  { {0,2}, {1,2}, {2,2} }, { {1,2}, {2,2}, {3,2} }, { {2,2}, {3,2}, {4,2} }, 
  { {0,3}, {1,3}, {2,3} }, { {1,3}, {2,3}, {3,3} }, { {2,3}, {3,3}, {4,3} }, 
  { {0,4}, {1,4}, {2,4} }, { {1,4}, {2,4}, {3,4} }, { {2,4}, {3,4}, {4,4} }, 
  { {0,2}, {1,3}, {2,4} }, { {0,1}, {1,2}, {2,3} }, { {1,2}, {2,3}, {3,4} }, 
  { {0,0}, {1,1}, {2,2} }, { {1,1}, {2,2}, {3,3} }, { {2,2}, {3,3}, {4,4} }, 
  { {1,0}, {2,1}, {3,2} }, { {2,1}, {3,2}, {4,3} }, { {2,0}, {3,1}, {4,2} }, 
  { {0,2}, {1,1}, {2,0} }, { {0,3}, {1,2}, {2,1} }, { {1,2}, {2,1}, {3,0} }, 
  { {0,4}, {1,3}, {2,2} }, { {1,3}, {2,2}, {3,1} }, { {2,2}, {3,1}, {4,0} }, 
  { {1,4}, {2,3}, {3,2} }, { {2,3}, {3,2}, {4,1} }, { {2,4}, {3,3}, {4,2} }
};

/**
 * @brief SETBOARD function - is used to create default board
 * 
 */
void setBoard() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      board[i][j] = 0;
    }
  }
}

/**
 * @brief PRINTBOARD function - is used to print 
 * current state of the board
 * 
 */
void printBoard() {
  printf("  1 2 3 4 5\n");

  for (int i = 0; i < 5; i++) {
    printf("%d", i + 1);

    for (int j = 0; j < 5; j++ ) {
      switch(board[i][j]) {
        case 0: 
          printf(" -"); 
          break;
        case 1: 
          printf(" X"); 
          break;
        case 2: 
          printf(" O"); 
          break;
      }
    }

    printf("\n");
  }

  printf("\n");
}

/**
 * @brief isWon function - is used to check if a given 
 * player had set up a winning position anywhere on the board
 * 
 * @param player 
 * @return true 
 * @return false 
 */
bool isWon (int player) {
  bool result = false;

  for (int i = 0; i < 28; i++) {
    if ((board[win[i][0][0]][win[i][0][1]] == player) 
      && (board[win[i][1][0]][win[i][1][1]] == player) 
      && (board[win[i][2][0]][win[i][2][1]] == player) 
      && (board[win[i][3][0]][win[i][3][1]] == player) 
    ){
      result = true;
    }
  }

  return result;
}

/**
 * @brief isLost function - is used to check if a given
 * player had set up a losing position anywhere on the board
 * 
 * @param player 
 * @return true 
 * @return false 
 */
bool isLost (int player) {
  bool result = false;

  for (int i = 0; i < 48; i++) {
    if ((board[lose[i][0][0]][lose[i][0][1]] == player) 
      && (board[lose[i][1][0]][lose[i][1][1]] == player) 
      && (board[lose[i][2][0]][lose[i][2][1]] == player) 
    ){
      result = true;
    }
  }

  return result;
}

/**
 * @brief EVALUATEHeuristic function - is used to count current heuristic on the board
 * 
 * @param player 
 * @return int 
 */
int evaluateHeuristic (int player) {
  if (isWon(player) == true) {
    return INT_MAX;
  }

  if (isWon(3-player) == true) {
    return INT_MIN;
  }
  
  int empties1 = 0;
  int empties2 = 0;

  for (int i = 0; i < 28; i++) {
    if ((board[win[i][0][0]][win[i][0][1]] != (2)) 
      && (board[win[i][1][0]][win[i][1][1]] != (2)) 
      && (board[win[i][2][0]][win[i][2][1]] != (2)) 
      && (board[win[i][3][0]][win[i][3][1]] != (2)) 
    ) {
      empties1++;
    }
  }

  for (int i = 0; i < 28; i++) {
    if ((board[win[i][0][0]][win[i][0][1]] != (1)) 
      && (board[win[i][1][0]][win[i][1][1]] != (1)) 
      && (board[win[i][2][0]][win[i][2][1]] != (1)) 
      && (board[win[i][3][0]][win[i][3][1]] != (1)) 
    ) {
      empties2++;
    }
  }

  return empties1 - empties2;
}

/**
 * @brief MINIMAX function - is used to find recurisvely heuristic opinion of a move 
 * that has been currently made. It counts with a given depth.
 * 
 * @param depth 
 * @param player 
 * @param alpha 
 * @param beta 
 * @return int 
 */
int minimax (int depth, int player, int alpha, int beta) {
    
    // Checking if we have already got into leaf or 
    // already won (lost) and calculating
    // heuristic of a current state on the board.
    if (depth == 0 
      || isWon(player) == true 
      || isWon(3 - player) == true 
      || isLost(player) == true 
      || isLost(3 - player) == true
    ) {
      return evaluateHeuristic(player);
    }

    if (player == 1) { 
        // Player of id equal to 1 algorithm.
        // Player 1 has the best heuristic when 
        // current heuristic is global MAX.
        int bestScore = INT_MIN;

        // Searching of all possible moves.
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 0) { 
                    // Making a move by player 1.
                    board[i][j] = 1; 

                    // Counting a heuristic opinion 
                    // of move that has been made.
                    int score = minimax(depth - 1, 2, alpha, beta);

                    // Setting board back to its initial state.
                    board[i][j] = 0; 

                    // Counting new bestScore and updating alpha param.
                    bestScore = MAX(bestScore, score);
                    alpha = MAX(alpha, score);

                    // Cancelling a move if it is already worse than 
                    // some that already have been considered.
                    if (beta <= alpha) { 
                        break;
                    }
                }
            }
        }

        return bestScore;

    } else { 
        // Player of id equal to 2 algorithm
        // Player 2 has the best heuristic when 
        // current heuristic is global MIN.
        int bestScore = INT_MAX;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 0) { 
                    // Making a move by player 2.
                    board[i][j] = 2; 

                    // Counting a heuristic opinion 
                    // of move that has been made.
                    int score = minimax(depth - 1, 1, alpha, beta);

                    // Setting board back to its initial state.
                    board[i][j] = 0; 

                    // Counting new bestScore and updating alpha param.
                    bestScore = MIN(bestScore, score);
                    beta = MIN(beta, score);

                    // Cancelling a move if it is already worse than 
                    // some that already have been considered.
                    if (beta <= alpha) { 
                        break;
                    }
                }
            }
        }

        return bestScore;
    }
}

/**
 * @brief GETMOVE function - is used to count current best move to make by computer
 * 
 * @param player 
 * @param depth 
 * @return int 
 */
int getMove (int player, int depth) {
    int bestMove = -1;
    int bestScore = INT_MIN;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 0) { 
                // Making a move by given player
                board[i][j] = player; 

                // Checking if a given player can create a 
                // winning state after this move. If yes then
                // we should return this move.
                if (isWon(player) == true) {
                  board[i][j] = 0;
                  return 10 * (i + 1) + j + 1;
                }

                // Checking if a given player can create a 
                // losing state after this move. If yes then
                // we should skip this move.
                if (isLost(player) == true) {
                  board[i][j] = 0;
		              continue;
                }

                // Making a move by given player's opponent
                board[i][j] = 3 - player;

                // Checking if a given player's opponent can create a 
                // winning state after this move. If yes then
                // we should block opponent's move by making it.
                if (isWon(3 - player) == true) {
                  board[i][j] = 0;
                  return 10 * (i + 1) + j + 1;
                }

                // Making a move by a given player again
                board[i][j] = player;

                // Getting move's heuristic opinion
                int score = minimax(depth, player, INT_MIN, INT_MAX); 

                // Setting board to its initial state with no any move.
                board[i][j] = 0; 

                // Checking if we have found a better move 
                // than the current best. If yes then we should
                // exchange these moves.
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = 10 * (i + 1) + j + 1;
                }
            }
        }
    }

    return bestMove;
}

/**
 * @brief SETMOVE function - is used to check and 
 * set move on the board
 * 
 * @param move 
 * @param player 
 * @return true 
 * @return false 
 */
bool setMove(int move, int player){
  int i = (move / 10) - 1;
  int j = (move % 10) - 1;

  if ((i < 0) 
    || (i > 4) 
    || (j < 0) 
    || (j > 4)
  ) {
    return false; 
  }

  if (board[i][j] != 0) {
    return false;
  }
    
  board[i][j] = player;

  return true;
}
