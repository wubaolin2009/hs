#include <assert.h>
#include <stdio.h>
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "CardSpawn.h"

bool test_simple_attack()
{
  //There are two cards one is 1/2  the other is 1/2 all consume 1
  Game game;
  Player p1(0,L"top",&game);
  Player p2(1,L"bottom",&game);
  Card card_1(&p1,L"test_1_2",2,1,1,0,1);
  Card card_2(&p2,L"test_1_2",2,1,1,1,1);

  game.start_game(&p1,&p2);
  assert(game.game_over() == false);
  game.round_start();
  //Top attack bottom
  game.player_turn(0);
  assert(p1.action(&card_1,&card_2) == true);
  assert(p1.action(&card_2,&card_1) == false);
  //assert(p1.action(&card_1,NULL) == false);

  //printf("card1 %d card2 %d\n", card_1.get_hp(NULL), card_2.get_hp(NULL));
  assert(card_1.get_hp(NULL) == 1);
  assert(card_2.get_hp(NULL) == 1);
  game.player_turn(1);
  assert(p2.action(&card_2,&card_1) == true);
  assert(card_1.get_hp(NULL) == 0);
  assert(card_2.get_hp(NULL) == 0);
  game.round_over();
  //Round 1 over, Round 2 should something killed
}
  

int main(int argc, char** argv)
{
  test_simple_attack();
  return 0;
};
