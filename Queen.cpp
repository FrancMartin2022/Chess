#include "GameFigure.h"
#include "Queen.h"

Queen::Queen(char FigureColor) : GameFigure(FigureColor) {}

Queen::~Queen() {}

char Queen::GetFigure() {
    return 'Q';
}

bool Queen::AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) {
    if (originRow1 == DestRow1) {
        // Убеждаемся, что все клетки пустые
        int Row2Offset = (DestRow2 - originRow2 > 0) ? 1 : -1;
        for (int CheckRow2 = originRow2 + Row2Offset; CheckRow2 != DestRow2; CheckRow2 = CheckRow2 + Row2Offset) {
            if (GameBoard[originRow1][CheckRow2] != 0) {
                return false;
            }
        }
        return true;
    }
    else if (DestRow2 == originRow2) {
        // Убеждаемся, что все клетки пустые
        int Row1Offset = (DestRow1 - originRow1 > 0) ? 1 : -1;
        for (int CheckRow = originRow1 + Row1Offset; CheckRow != DestRow1; CheckRow = CheckRow + Row1Offset) {
            if (GameBoard[CheckRow][originRow2] != 0) {
                return false;
            }
        }
        return true;
    }
    else if ((DestRow2 - originRow2 == DestRow1 - originRow1) || (DestRow2 - originRow2 == originRow1 - DestRow1)) {
        // Убеждаемся, что все клетки пустые
        int Row1Offset = (DestRow1 - originRow1 > 0) ? 1 : -1;
        int Row2Offset = (DestRow2 - originRow2 > 0) ? 1 : -1;
        int CheckRow;
        int CheckRow2;
        for (CheckRow = originRow1 + Row1Offset, CheckRow2 = originRow2 + Row2Offset;
            CheckRow != DestRow1;
            CheckRow = CheckRow + Row1Offset, CheckRow2 = CheckRow2 + Row2Offset)
        {
            if (GameBoard[CheckRow][CheckRow2] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}