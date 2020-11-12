#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <utility> 
#include "board.h"

enum playerT{Human, Computer};
#define inf 1<<20

class Game
{
public:
    Game(unsigned int size);
	~Game();
    void Execute();
private:
    Game(const Game&);
 	Game& operator=(const Game&);
    void Init_Board();
    playerT Opponent(playerT);
    stateT Game_Over(Board*, int);
    stateS Alt_Move_Search(Board*, int);
    Node* GetUserMove(Board*);
    int Score(Node*, dir, int);
    int Estimate(Board*, int);
    void StartGame();
    bool Board_Full(Board*);
    void Make_Turn(unsigned int, unsigned int);
    int Minimax(playerT, Board*, unsigned int);
    int Alphabeta(playerT, Board*, unsigned int, int, int);
    void AltMove(Board*);
	unsigned int turnsTaken;
    playerT whoseTurn;
    Board* game_board;
    Node* minNode;
    Node* maxNode;
    Node* user_move;
    Scores_Set s_scores;
    bool gameIsOver;
    // how many player/computer marks are on the board currently?
    unsigned int mark_count_h;
    unsigned int mark_count_l;
    unsigned char winning_mark;
    // game parameters
    unsigned int board_size;
    const static unsigned int win_row = 4;
    const static unsigned int two = 2;
    const static unsigned int max_depth = 6;
};
#endif