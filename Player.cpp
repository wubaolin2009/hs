#include "Player.h"
#include "Game.h"
#include "Card.h"

using namespace std;
//helper function , get cards' index in vector, 0xff None
static u8 card_index_vector(Card* card, vector<Card*>& vec)
{
  u8 position = 0xff;
  for(int i = 0; i < vec.size(); i++) {
    if(card->get_id() == vec[i]->get_id()) {
      position = (u8)i;
    }
  }
  return position;
}

u8 Player::card_position(Card* card, Player::CardBucket* cb)
{
  //currently, we only compare card's pointer, since
  //Cards will be implemented via singleton
  CardBucket tmp_cb = CARD_NONE;
  u8 position = 0xff;
  position = card_index_vector(card,cards_stove_);
  if(position != 0xff)
      tmp_cb = CARD_IN_STOVE; 
  if(position == 0xff) {
    position = card_index_vector(card,cards_on_board_);
    if(position != 0xff) tmp_cb = CARD_ON_BOARD;
  }
  if(position == 0xff) {
    position = card_index_vector(card,cards_stove_);
    if(position != 0xff) tmp_cb = CARD_IN_STOVE;
  }
  if(cb) *cb = tmp_cb;
  return position;
}

void Player::round_start()
{
}
void Player::round_over()
{
}
bool Player::action(Card* c1, Card* c2)
{
  //c1 must belonging to player
  if(c1->get_player_id() != id_) return false;
  if(c1->can_attack(game_,c2) ) {
    c1->onAttack(game_, c2);
    if(c2) c2->onAttacked(game_,c1);
    if(c2) c2->onAttacked(game_,c1);
    c1->onAttacked(game_,c2);
    c1->AttackFinish(game_,c2);
    return true;
  }
  return false;
}
bool Player::put_on_board(Card* c1)
{
  return true;
}
