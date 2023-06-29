#ifndef KING_h
#define KING_h

#include "GameFigure.h"

class King : public GameFigure
{
public:
    King(char FigureColor);
    ~King();
private:
    virtual char GetFigure();
    bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
};
#endif