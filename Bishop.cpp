#include "Bishop.h"
#include "GameFigure.h"

//�����������, ����������� ���� ���������� - �������� ������ ����� ��� ������,
Bishop::Bishop(char FigureColor) : GameFigure(FigureColor) {}

//��� ���������� ������� ������� ������ ��� ��������� ����
Bishop::~Bishop() {}

//GetFigure() ����������� �������, ������� ���������� �����, ��� ������ ����� �� �����, AreSquaresLegal ������� ���������� �� �����������.
char Bishop::GetFigure() {
    return 'B';
}
/* ��� ��������� ���������� ������, � ������� ��� ���� � ���������� ������, �� ������� ���.
���������, ��� ��� ��������� �� ��������� � ����� ���� ��������� ������������,�� ����, ��� ��� ��������
*/
bool Bishop::AreCellLegal(int originRow1, int originRow2, int DestRow1, int DestRow2, GameFigure* GameBoard[8][8]) {
    if ((DestRow2 - originRow2 == DestRow1 - originRow1) || (DestRow2 - originRow2 == originRow1 - DestRow1)) {
        // ����������, ��� ��� ������ ������
        // offset - ����������� ��������(����� ��� ������, ���� - �����).��������� ������ ���������� ��� ���������.
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
//GetFigure() AreCellLegal ��������� ������ ��� ������������ ������ � ����������� �pp ������, ��� �����������