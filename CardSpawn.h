//For card generation

//TODO: Card Config
class CardConfig
{
public:
  void init();
  u8 get_next_card_id();
};
class Card;
class CardSpawn
{
public:
  void init();
  Card generate_cards(int number_cards, CardConfig* config);
};
