#ifndef BOARD_h
#define BOARD_h

#include "GameFigure.h"
#include "Pawn.h"
#include "Rook.h"
#include "Horse.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include <iostream>

using namespace std;

class Board
{
public:
    Board();
    ~Board();
    void Print();
    bool IfCheck(char FigureColor);
    bool CanMove(char FigureColor);
    GameFigure* HeadGameBoard[8][8];
};
#endif