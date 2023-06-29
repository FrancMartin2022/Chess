#ifndef Horse_h
#define Horse_h
#include "GameFigure.h"


class Horse : public GameFigure
{
public:
    Horse(char FigureColor);
    ~Horse();
private:
    virtual char GetFigure();
    bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
};
#endif