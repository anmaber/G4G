#include "Player.hpp"
#include <iostream>

Player::Player(char sign)
    : sign_(sign)
{}

char Player::getSign() const
{
    return sign_;
}

Coordinates Player::move(Board &board)
{
    Coordinates coordinates = Coordinates(0,0);
    do
    {
       coordinates = setCoordinates(board.getSize());

    }while(!board.putOnBoard(coordinates.x,coordinates.y,getSign()));

    return coordinates;
}

Coordinates Player::setCoordinates(int max)
{
    int x=0,y=0;
    std::cout<<"Row: ";
    std::cin >> x;
    while(x < 0 || x >= max)
    {
        std::cout<<"invalid input, give row number again: ";
        std::cin >> x;
    }

    std::cout<<"Column: ";
    std::cin >> y;
    while(y < 0 || y >= max)
    {
        std::cout<<"invalid input, give column number again: ";
        std::cin >> y;
    }

    return Coordinates(x,y);
}

bool Player::operator == (const Player &p)
{
    return getSign() == p.getSign();
}
