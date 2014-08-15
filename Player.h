//This file is for a Player
#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <string>
#include "defs.h"
class Card;
class Game;
class Player
{
public:
  enum CardBucket { CARD_IN_HAND, CARD_IN_STOVE, CARD_ON_BOARD, CARD_NONE };

public:
  Player(int id, const std::wstring& name, Game* game): id_(id),name_(name),game_(game) {}
  u8 get_id() { return id_; }
  u8 get_crystal() { return cur_crystal_; }
  //return position
  u8 card_position(Card* card, CardBucket* cb);
  //hook functions
  void round_start();
  void round_over();
  //Specified Actions
  bool action(Card* c1, Card* c2); //On Board Excluded
  bool put_on_board(Card* c1);
private:
  u8 id_;
  std::wstring name_;
  Game* game_;
  //Cards Skills Weapon
  std::vector<Card*> cards_in_hand_;
  std::vector<Card*> cards_on_board_;
  std::vector<Card*> cards_stove_;
  Card* cards_weapon_;
  Card* cards_hero_skill_;
  // Status
  u8 cur_crystal_;
  u8 max_crystal_;
  //Player is just another card
  Card* player_;
};
 
#endif
