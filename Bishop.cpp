#include "Bishop.h"
#include "GameFigure.h"

//конструктор, принимающий одну переменную - является фигура белой или чёрной,
Bishop::Bishop(char FigureColor) : GameFigure(FigureColor) {}

//это деструктор который стирает фигуру при окончании игры
Bishop::~Bishop() {}

//GetFigure() виртуальная функция, которая возвращает буквы, для вывода фигур на доску, AreSquaresLegal функция отвечающее за перемещения.
char Bishop::GetFigure() {
    return 'B';
}
/* Она принимает координаты клетки, с которой идёт слон и координаты клетки, на которую идёт.
Проверяет, что они находятся на диагонали и между ними свободное пространство,то есть, что ход возможен
*/
bool Bishop::AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) {
    if ((DestRow2 - originRow2 == DestRow1 - originRow1) || (DestRow2 - originRow2 == originRow1 - DestRow1)) {
        // Убеждаемся, что все клетки пустые
        // offset - направление движения(влево или вправо, вниз - вверх).Остальные просто переменные для координат.
        int Row1Offset = (DestRow1 - originRow1 > 0) ? 1 : -1;
        int Row2Offset = (DestRow2 - originRow2 > 0) ? 1 : -1;
        int CheckRow1;
        int CheckRow2;
        for (CheckRow1 = originRow1 + Row1Offset, CheckRow2 = originRow1 + Row2Offset;
            CheckRow1 != DestRow1;
            CheckRow1 = CheckRow1 + Row1Offset, Row2Offset = CheckRow2 + Row2Offset)
        {
            if (GameBoard[CheckRow1][CheckRow2] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}
//GetFigure() AreCellLegal приватные потому что используются только в одноименных сpp файлах, где реализуются