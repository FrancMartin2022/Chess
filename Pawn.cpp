#include "GameFigure.h"
#include "Pawn.h"


Pawn::Pawn(char FigureColor) : GameFigure(FigureColor) {}

Pawn::~Pawn() {}

char Pawn::GetFigure() {
    return 'P';
}

bool Pawn::AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) {
    GameFigure* Dest = GameBoard[DestRow1][DestRow2];
    if (Dest == 0) {
        // Конечная клетка свободна
        if (originRow2 == DestRow2) {
            if (GetColor() == 'W') {
                if (DestRow1 == originRow1 + 1 || (DestRow1 == originRow1 + 2 && !isMoved)) {
                    return true;
                }
            }
            else {
                if (DestRow1 == originRow1 - 1 || (DestRow1 == originRow1 - 2 && !isMoved)) {
                    return true;
                }
            }
        }
    }
    else {
        // Конечная клетка занята фигурой другого цвета
        if ((originRow2 == DestRow2 + 1 || (originRow2 == DestRow2 + 2 && !isMoved))
            || (originRow2 == DestRow2 - 1 || (originRow2 == DestRow2 - 2 && !isMoved))) {
            if (GetColor() == 'W') {
                if (DestRow1 == originRow1 + 1 || (DestRow1 == originRow1 + 2 && !isMoved)) {
                    return true;
                }
            }
            else {
                if (DestRow1 == originRow1 - 1 || (DestRow1 == originRow1 - 2 && !isMoved)) {
                    return true;
                }
            }
        }
    }
    return false;
}
