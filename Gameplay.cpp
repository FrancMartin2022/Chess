#include "Gameplay.h"
#include <iostream>
using namespace std;

Gameplay::Gameplay() : PlayerStep('W') {}

void Gameplay::Begin() {
    do {
        GetNextStep(GameBoardX.HeadGameBoard);
        AlternateStep();
    } while (!GameOver());
    GameBoardX.Print();
}
//��� ���������� ������� �������, �� ���� ������� �� ������ �����, �� ���� ��� ���� �������������� � ����������.
//����� ������ ���� �������� ���� ��������� �� ���, ����� �� ������ ������ ��� ���������, � ��� ������ ������� �����
//������� AlternateTurn ������ ������� ����
void Gameplay::GetNextStep(GameFigure* GameBoard[8][8]) {
    using namespace std;
    bool ValidStep = false;
    do {
        system("clear");
        GameBoardX.Print();
        // �������� ������ � ��������������� � �����������
        cout << "Move";
        if (PlayerStep == 'W')
            cout << "White: ";
        else
            //  StartRow1, StartRow2 � �.�.��������� ���������� ������.fromCell ����� ��� ����� ������, ����� ����� � ������������� � �����������.
            cout << "Black: ";
        string fromCell = "  ";
        cin >> fromCell;
        int StartRow1 = (fromCell.at(1) - '0') - 1;
        int StartRow2 = (int)fromCell.at(0) - 97;
        cout << "The final cell: ";
        string Cell = "  ";
        cin >> Cell;
        int EndRow1 = (Cell.at(1) - '0') - 1;
        int EndRow2 = (int)Cell.at(0) - 97;
        // ���������, ��� ���������� � ���������� ��������
        // � ��������� � �������� ������ ������
        if ((StartRow1 >= 0 && StartRow1 <= 7) &&
            (StartRow2 >= 0 && StartRow2 <= 7) &&
            (EndRow1 >= 0 && EndRow1 <= 7) &&
            (EndRow2 >= 0 && EndRow2 <= 7)) {
            // �������������� ��������
            GameFigure* FigureX = GameBoard[StartRow1][StartRow2];
            // ���������, ��� ������ ������� �����
            if ((FigureX != 0) && (FigureX->GetColor() == PlayerStep)) {
                // ��������� ������, �� ������� ������ ���� ������ ���
                if (FigureX->IfLegalStep(StartRow1, StartRow2, EndRow1, EndRow2, GameBoard)) {
                    // ������ ���
                    GameFigure* Temp = GameBoard[EndRow1][EndRow2];
                    GameBoard[EndRow1][EndRow2] = GameBoard[StartRow1][StartRow2];
                    GameBoard[StartRow1][StartRow2] = 0;
                    // ���������, ��� � �������� ������ ��� ����
                    if (!GameBoardX.IfCheck(PlayerStep)) {
                        delete Temp;
                        ValidStep = true;
                        FigureX->isMoved = true;
                    }
                    else { // ���������� ��������� ���
                        GameBoard[StartRow1][StartRow2] = GameBoard[EndRow1][EndRow2];
                        GameBoard[EndRow1][EndRow2] = Temp;
                    }
                }
            }
        }
        if (!ValidStep) {
            cout << "impossible!" << endl;
        }
    } while (!ValidStep);
}

void Gameplay::AlternateStep() {
    PlayerStep = (PlayerStep == 'W') ? 'B' : 'W';
}

bool Gameplay::GameOver() {
     // ���������, ��� ������� ����� ����� ������
     // ���� ���, �� � ��� ��� ��� ���
    bool CanMove(false);
    CanMove = GameBoardX.CanMove(PlayerStep);
    if (!CanMove) {
        if (GameBoardX.IfCheck(PlayerStep)) {
            AlternateStep();
            std::cout << "mate, ";
            if (PlayerStep == 'W')
                cout << "White";
            else
                cout << "Black";
            cout << " win!" << std::endl;
        }
        else {
            std::cout << "Pat!" << std::endl;
        }
    }
    return !CanMove;
}