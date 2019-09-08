#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
    Player();
    Player();
    Player(Player &&) = default;
    Player(const Player &) = default;
    Player &operator=(Player &&) = default;
    Player &operator=(const Player &) = default;
    ~Player();

    Vector2 <int> pos;
    Vector2 <int> dir;

private:
};

Player::Player()
{
}

Player::~Player()
{
}


#endif // !PLAYER_HPP