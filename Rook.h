#ifndef Rook_h
#define Rook_h
#include "GameFigure.h"


class Rook : public GameFigure
{
public:
    Rook(char FigureColor);
    ~Rook();
private:
    virtual char GetFigure();
    bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
};
#endif