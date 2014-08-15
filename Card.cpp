#include <algorithm>
#include <assert.h>
#include "Card.h"
#include "Player.h"
#include "Game.h"


using namespace std;

Card::Card(Player* player, const wstring& name, u8 hp, u8 attack, u8 cry_consuming, u8 id, u8 card_id): player_(player),id_(id),card_id_(card_id), name_(name), cur_hp_(hp), max_hp_(hp), attack_(attack), crystal_consum_(cry_consuming) {}

u8 Card::get_hp(u8* max_hp)
{
  if(max_hp) *max_hp = max_hp_;
  return cur_hp_;
}
u8 Card::get_player_id()
{
  return player_->get_id();
}

//The default implementation of cards behavior
bool Card::can_attack(Game* game, Card* target)
{
  return target && 
    get_player_id() != target->get_player_id();
}
bool Card::can_kill(Game* game, Card* target)
{
  assert(target);
  return attack_ >= target->cur_hp_;
}
Card::AttackType Card::attack_type()
{
  return CARD_ATTACK_TYPE_PHYSIC;
}
bool Card::canInvoke(Game* game)
{
  Player::CardBucket cb;
  player_->card_position(this,&cb);
  return cb == Player::CARD_IN_HAND && player_->get_crystal() >= crystal_consum_;
}
void Card::onInvoke(Game* game) //When Put on the boar
{
  return;
}
void Card::onDeath(Game* game) //It die
{
  return;
}
void Card::onDeathFromAlien(Game* game, Card* death)
{
  return;
}
void Card::onDeathFromEnemy(Game* game, Card* death)
{
  return;
}
void Card::onAttack(Game* game, Card* target) //Attack other
{
  return;
}
void Card::onAttacked(Game* game, Card* source) //Be attacke
{
  u8 attack = source->attack_;
  pending_hp_ = cur_hp_ - attack;
  pending_attack_ = attack_;
  pending_max_hp_ = max_hp_;
}
void Card::AttackFinish(Game* game, Card* target)
{
  this->cur_hp_ = pending_hp_;
  this->max_hp_ = pending_max_hp_;
  this->attack_ = pending_attack_;
  if(target) {
    target->cur_hp_ = target->pending_hp_;
    target->max_hp_ = target->pending_max_hp_;
    target->attack_ = target->pending_attack_;
  }
}
void Card::onTurnStart(Game* game)
{
  return;
}
void Card::onTurnEnd(Game* game)
{
  return;
}
