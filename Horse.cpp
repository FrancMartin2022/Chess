#include "GameFigure.h"
#include "Horse.h"

Horse::Horse(char FigureColor) : GameFigure(FigureColor) {}

Horse::~Horse() {}

char Horse::GetFigure() {
    return 'N';
}

bool Horse::AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) {
    // Конечная клетка свободна или занята фигурой другого цвета
    if ((originRow2 == DestRow2 + 1) || (originRow2 == DestRow2 - 1)) {
        if ((originRow1 == DestRow1 + 2) || (originRow1 == DestRow1 - 2)) {
            return true;
        }
    }
    if ((originRow2 == DestRow2 + 2) || (originRow2 == DestRow2 - 2)) {
        if ((originRow1 == DestRow1 + 1) || (originRow1 == DestRow1 - 1)) {
            return true;
        }
    }
    return false;
}