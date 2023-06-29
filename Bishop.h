#ifndef Bishop_h
#define Bishop_h
#include "GameFigure.h"


class Bishop : public GameFigure
{
public:
    Bishop(char FigureColor);
    ~Bishop();
private:
    virtual char GetFigure();
    bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
};
#endif