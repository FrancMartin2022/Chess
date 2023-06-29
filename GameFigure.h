#ifndef GameFigure_h
#define GameFigure_h

class GameFigure
{
public:
    GameFigure(char FigureColor);
    ~GameFigure();
    virtual char GetFigure();
    char GetColor();
    bool IfLegalStep(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]);
    bool isMoved;
private:
    virtual bool AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) = 0;
    char FigureColorX;
};
#endif 