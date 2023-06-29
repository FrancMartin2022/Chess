#ifndef Pawn_h
#define Pawn_h

#include "GameFigure.h"

class Pawn : public GameFigure
{
public:
    Pawn(char FigureColor);
    ~Pawn();
private:
    virtual char GetFigure();
    bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
};
#endif