#ifndef Queen_h
#define Queen_h
#include "GameFigure.h"


class Queen : public GameFigure
{
public:
    Queen(char FigureColor);
    ~Queen();
private:
    virtual char GetFigure();
    bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
};
#endif