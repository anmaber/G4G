#pragma once
#include "Board.hpp"

struct Coordinates
{
    int x;
    int y;
    Coordinates(int X, int Y)
        : x(X),
          y(Y)
    {}
};

class Player
{
    char sign_;
    Coordinates setCoordinates(int max);

public:
    Player(char sign);
    Player() = default;
    virtual Coordinates move(Board& board);
    bool operator == (const Player& p);
    char getSign() const;

    virtual ~Player(){}
};
