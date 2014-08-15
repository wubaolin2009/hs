//This file is for a Card, basic
#ifndef CARD_H_
#define CARD_H_

#include <vector>
#include <string>
#include "defs.h"

class Game;
class Player;

class Card
{
public:
  enum AttackType{ 
    CARD_ATTACK_TYPE_PHYSIC,
    CARD_ATTACK_TYPE_SPELL_SINGLE,
    CARD_ATTACK_TYPE_SPELL_AOE,
    CARD_ATTACK_TYPE_HERO_SKILL
  };
public:
  //Card can only be spawned by CardSpawn class
  Card(Player*, const std::wstring& name, u8 hp, u8 attack, u8 cry_consum,u8 id,u8 card_id);

  //Get the status
  u8 get_hp(u8* max_hp); //returns cur_hp
  u8 get_player_id();

  //Interfaces for the actions
  //When returns false, meaning the action can't be putted into the target
  virtual bool can_attack(Game* game, Card* target);
  virtual bool can_kill(Game* game, Card* target);
  virtual AttackType attack_type();
  
  virtual bool canInvoke(Game* game);
  virtual void onInvoke(Game* game); //When Put on the board
  virtual void onDeath(Game* game); //It died

  //Should Invoked after it Dead
  virtual void onDeathFromAlien(Game* game, Card* death);
  virtual void onDeathFromEnemy(Game* game, Card* death);

  virtual void onAttack(Game* game, Card* target); //Attack others
  virtual void onAttacked(Game* game, Card* source); //Be attacked
  virtual void AttackFinish(Game* game, Card* target); //Attack Action Finished
  
  virtual void onTurnStart(Game* game);
  virtual void onTurnEnd(Game* game);

  int get_id() { return id_; }
  Player* get_player() { return player_; }
private: //helper function

private:
  Player* player_;
  int id_;
  int card_id_; //card_id_ can be the same when player owner more than one, but id_ is used to uniquelly indentify the card
  std::wstring name_;
  int cur_hp_,pending_hp_;
  u8 max_hp_,pending_max_hp_;
  u8 attack_,pending_attack_;
  u8 crystal_consum_;
};

#endif
