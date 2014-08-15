#include "Game.h"
#include "Player.h"

void Game::start_game(Player* player_top, Player* player_bottom)
{
  players_[0] = player_top;
  players_[1] = player_bottom;
}
bool Game::game_over()
{
  return false;
}
void Game::round_start()
{
  for(int i = 0; i < PLAYERS_NUM; i++) {
    players_[i]->round_start();
  }
}
void Game::player_turn(int player_index)
{
  return;
}
void Game::round_over()
{
  for(int i = 0; i < PLAYERS_NUM; i++) {
    players_[i]->round_over();
  }
}
