#include "GameFigure.h"
#include "King.h"

King::King(char FigureColor) : GameFigure(FigureColor) {}

King::~King() {}

char King::GetFigure() {
    return 'K';
}

bool King::AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) {
    int Row1Delta = DestRow1 - originRow1;
    int Row2Delta = DestRow2 - originRow2;
    if (((Row1Delta >= -1) && (Row1Delta <= 1)) &&
        ((Row2Delta >= -1) && (Row2Delta <= 1)))
    {
        return true;
    }
    return false;
}