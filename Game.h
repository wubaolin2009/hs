//This file is descripting a Game
//Including Two hero, Cards in hand or in board,etc
#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include <string>
#include "defs.h"

class Player;
class Card;

#define PLAYERS_NUM 2

class Game
{
public:
  void start_game(Player* player_top, Player* player_bottom);
  bool game_over();
  void round_start();
  void player_turn(int player_index);
  void round_over();
private:
  //Top player is indicated by index 0, bottom 1
  Player* players_[PLAYERS_NUM];
};

#endif
