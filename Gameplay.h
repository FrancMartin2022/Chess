#ifndef Gameplay_h
#define Gameplay_h

#include "Board.h"
#include "GameFigure.h"
#include <iostream>
using namespace std;

class Gameplay
{
public:
    Gameplay();
    void Begin();
    void GetNextStep(GameFigure* GameBoard[8][8]);
    void AlternateStep();
    bool GameOver();
private:
    Board GameBoardX;
    char PlayerStep;
};
#endif