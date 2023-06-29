#include "GameFigure.h"

GameFigure::GameFigure(char FigureColor) : FigureColorX(FigureColor) {
    isMoved = false;
}
//GameFigure абстрактно представляет фигуру
GameFigure::~GameFigure() {}

char GameFigure::GetFigure()
{
    return 0;
}

char GameFigure::GetColor() {
    return FigureColorX;
}

bool GameFigure::IfLegalStep(int originRow1, int originRow2, int DestRow1, int  DestRow2, GameFigure* GameBoard[8][8]) {
    GameFigure* Dest = GameBoard[DestRow1][DestRow2];
    if ((Dest == 0) || (FigureColorX != Dest->GetColor())) {
        return AreCellLegal(originRow1, originRow2, DestRow1, DestRow2, GameBoard);
    }
    return false;
}
//IfLegalStep проверяет возможность хода на заданную клетку