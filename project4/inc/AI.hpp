#pragma once
#include "Player.hpp"

class AI : public Player
{
    Coordinates findBestMove(Board& board);
    int minimax(Board& board, int depth, bool isMax, int x, int y, char player, int alpha, int beta);
    int evaluateBoard(const Board& board, int xCoordinate, int yCoordinate, char currentPlayer) const;
    int evaluateVertically(const Board& board, int xCoordinate, int yCoordinate, char currentPlayer) const;
    int evaluateHorizontally(const Board& board, int xCoordinate, int yCoordinate, char currentPlayer) const;
    int evaluateDiagonally(const Board& board, int xCoordinate, int yCoordinate, char currentPlayer) const;
    int evaluateAntidiagonally(const Board& board, int xCoordinate, int yCoordinate, char currentPlayer) const;

public:

    AI() = default;
    explicit AI(char sign);
    Coordinates move(Board& board);

};
