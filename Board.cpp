#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    for (int RowX = 0; RowX < 8; ++RowX) {
        for (int RowY = 0; RowY < 8; ++RowY) {
            HeadGameBoard[RowX][RowY] = 0;
        }
    }
    // � Board �� ������� ����������� ������(� ������ for), � ������� Print ������������� �����
    // ��������� ������ ������
    // rowX � rowY �����, ����� ������ �� �������
    for (int RowY = 0; RowY < 8; ++RowY) {
        HeadGameBoard[6][RowY] = new Pawn('B');
    }
    HeadGameBoard[7][0] = new Rook('B');
    HeadGameBoard[7][1] = new Horse('B');
    HeadGameBoard[7][2] = new Bishop('B');
    HeadGameBoard[7][3] = new King('B');
    HeadGameBoard[7][4] = new Queen('B');
    HeadGameBoard[7][5] = new Bishop('B');
    HeadGameBoard[7][6] = new Horse('B');
    HeadGameBoard[7][7] = new Rook('B');
    // ��������� ����� ������
    for (int RowY = 0; RowY < 8; ++RowY) {
        HeadGameBoard[1][RowY] = new Pawn('W');
    }
    HeadGameBoard[0][0] = new Rook('W');
    HeadGameBoard[0][1] = new Horse('W');
    HeadGameBoard[0][2] = new Bishop('W');
    HeadGameBoard[0][3] = new King('W');
    HeadGameBoard[0][4] = new Queen('W');
    HeadGameBoard[0][5] = new Bishop('W');
    HeadGameBoard[0][6] = new Horse('W');
    HeadGameBoard[0][7] = new Rook('W');
}

Board::~Board() {
    for (int RowX = 0; RowX < 8; ++RowX) {
        for (int RowY = 0; RowY < 8; ++RowY) {
            delete HeadGameBoard[RowX][RowY];
            HeadGameBoard[RowX][RowY] = 0;
        }
    }
}

void Board::Print()
{
    using namespace std;
    //CellWidth � CellHeight -������ � ������ ������ � �������
    const int CellWidth = 3;
    const int CellHeight = 2;
    cout << "   a  b  c  d  e  f  g  h" << endl;
    for (int RowX = 0; RowX < 8 * CellHeight + 1; ++RowX) {
        int CellRow = RowX / CellHeight;
        // �������� ����� �����
        if (RowX % CellHeight == 1) {
            cout << (char)('1' + 7 - CellRow);
        }
        else {
            cout << " ";
        }
        // �������� �����
        for (int RowY = 0; RowY < 8 * CellWidth + 1; ++RowY) {
            int CellRow2 = RowY / CellWidth;
            if (((RowX % CellHeight) == 1) && ((RowY % CellWidth) == 1 || (RowY % CellWidth) == 2)) {
                if (HeadGameBoard[7 - CellRow][CellRow2] == 0) {
                    cout << " ";
                }
                else if ((RowY % CellWidth) == 1) {
                    cout << HeadGameBoard[7 - CellRow][CellRow2]->GetColor();
                }
                else {
                    cout << HeadGameBoard[7 - CellRow][CellRow2]->GetFigure();
                }
            }
            else {
                if (RowY % CellWidth == 0 && RowX % CellHeight == 1) {
                    cout << '|';
                }
                else {
                    cout << '-';
                }
            }
        }
        // �������� ����� ������
        if (RowX % CellHeight == 1) {
            cout << (char)('1' + 7 - CellRow);
        }
        else {
            cout << " ";
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
}

bool Board::IfCheck(char FigureColor) {
    // ifCheck() ������� ������� ���������� ������
    int KingRow;
    int KingRow2;
    for (int RowX = 0; RowX < 8; ++RowX) {
        for (int RowY = 0; RowY < 8; ++RowY) {
            if (HeadGameBoard[RowX][RowY] != 0) {
                if (HeadGameBoard[RowX][RowY]->GetColor() == FigureColor) {
                    if (HeadGameBoard[RowX][RowY]->GetFigure() == 'K') {
                        KingRow = RowX;
                        KingRow2 = RowY;
                    }
                }
            }
        }
    }
    //  ������ for ��������, �� ������� �� ������ ��� ��� ���� ������� �������� �� ��������������� ������.
    for (int RowX = 0; RowX < 8; ++RowX) {
        for (int RowY = 0; RowY < 8; ++RowY) {
            if (HeadGameBoard[RowX][RowY] != 0) {
                if (HeadGameBoard[RowX][RowY]->GetColor() != FigureColor) {
                    if (HeadGameBoard[RowX][RowY]->IfLegalStep(RowX, RowY, KingRow, KingRow2, HeadGameBoard)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Board::CanMove(char FigureColor) {
    // canMove ���������, �������� �� �����-������ ��� ������, �� ���� ���������, ��� �� ����
    for (int RowX = 0; RowX < 8; ++RowX) {
        for (int RowY = 0; RowY < 8; ++RowY) {
            if (HeadGameBoard[RowX][RowY] != 0) {
                // ���� ��� ������ �������� ������, �������, ����� �� ��� ������� ���
                if (HeadGameBoard[RowX][RowY]->GetColor() == FigureColor) {
                    for (int MoveRow1 = 0; MoveRow1 < 8; ++MoveRow1) {
                        for (int MoveRow2 = 0; MoveRow2 < 8; ++MoveRow2) {
                            if (HeadGameBoard[RowX][RowY]->IfLegalStep(RowX, RowY, MoveRow1, MoveRow2, HeadGameBoard)) {
                                // ������ ��� � ��������� ���
                                GameFigure* qpTemp = HeadGameBoard[MoveRow1][MoveRow2];
                                HeadGameBoard[MoveRow1][MoveRow2] = HeadGameBoard[RowX][RowY];
                                HeadGameBoard[RowX][RowY] = 0;
                                bool bCanMove = !IfCheck(FigureColor);
                                HeadGameBoard[RowX][RowY] = HeadGameBoard[MoveRow1][MoveRow2];
                                HeadGameBoard[MoveRow1][MoveRow2] = qpTemp;
                                if (bCanMove) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}