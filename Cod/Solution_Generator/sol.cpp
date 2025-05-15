#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;


//char face_color[6] = { 'R', 'O', 'W', 'Y', 'G', 'B' };
char cub[6][9];

string final_moves = "";

void getPainted(string configuratie_initiala)
{
    int p = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = configuratie_initiala[p];
            p++;
        }
    }
}

string getScramble(char cub[6][9])
{
    string scramble = "";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            scramble += cub[i][j];

        }
    }
    return scramble;
}

void PrintCube(char cub[6][9]) {
    int p = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {

            if (p == 3) {
                cout << endl;
                p = 0;
            }
            cout << cub[i][j] << " ";
            p++;
        }
        cout << endl;
    }
}

void PrintCubev2(char cub[6][9]) {
    int p = 0;
    cout << "        ";
    for (int j = 0; j < 9; j++)
    {

        if (p == 3) {
            cout << endl;
            cout << "        ";
            p = 0;
        }
        cout << cub[5][j] << " ";
        p++;
    }
    cout << endl;
    cout << endl;
    for (int j = 0; j < 9; j = j + 3)
    {
        cout << cub[2][j] << " " << cub[2][j + 1] << " " << cub[2][j + 2] << "   " << cub[0][j] << " " << cub[0][j + 1] << " " << cub[0][j + 2] << "   " << cub[4][j] << " " << cub[4][j + 1] << " " << cub[4][j + 2] << "   " << cub[1][j] << " " << cub[1][j + 1] << " " << cub[1][j + 2] << endl;
    }
    for (int j = 0; j < 9; j++)
    {

        if (p == 3) {
            cout << endl;
            cout << "        ";
            p = 0;
        }
        cout << cub[3][j] << " ";
        p++;
    }
    cout << endl;
    cout << endl;
}

void CheckifSolved(char cub[6][9])
{
    int OK = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (cub[i][j] != cub[i][j + 1])
            {
                OK = 0;
            }
        }
    }
    if (OK == 1)
    {
        cout << "Cube Solved!" << endl;
    }
    else
    {
        cout << "Cube still unsolved!" << endl;
    }
}

int howManyMoves(string moves)
{
    return moves.length();
}

//cube movemenets : Tested (BUNE)

static void MoveU(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Orange -> Green

    cube_copy[3][0] = cub[4][0]; //array.setBlock(4, 0, cube_copy[3][0]); 
    cube_copy[3][1] = cub[4][1];
    cube_copy[3][2] = cub[4][2];

    //Green->Red
    cube_copy[2][0] = cub[3][0];
    cube_copy[2][1] = cub[3][1];
    cube_copy[2][2] = cub[3][2];

    //Red->Blue
    cube_copy[5][0] = cub[2][0];
    cube_copy[5][1] = cub[2][1];
    cube_copy[5][2] = cub[2][2];

    //Blue->Orange
    cube_copy[4][0] = cub[5][0];
    cube_copy[4][1] = cub[5][1];
    cube_copy[4][2] = cub[5][2];

    //Rotate Yellow
    cube_copy[1][0] = cub[1][6];
    cube_copy[1][1] = cub[1][3];
    cube_copy[1][2] = cub[1][0];
    cube_copy[1][3] = cub[1][7];
    cube_copy[1][5] = cub[1][1];
    cube_copy[1][6] = cub[1][8];
    cube_copy[1][7] = cub[1][5];
    cube_copy[1][8] = cub[1][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

} //GOOD

static void MoveD(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Orange -> Blue
    cube_copy[5][6] = cub[4][6];
    cube_copy[5][7] = cub[4][7];
    cube_copy[5][8] = cub[4][8];

    //Blue->Red
    cube_copy[2][6] = cub[5][6];
    cube_copy[2][7] = cub[5][7];
    cube_copy[2][8] = cub[5][8];

    //Red->Green
    cube_copy[3][6] = cub[2][6];
    cube_copy[3][7] = cub[2][7];
    cube_copy[3][8] = cub[2][8];

    //Green->Orange
    cube_copy[4][6] = cub[3][6];
    cube_copy[4][7] = cub[3][7];
    cube_copy[4][8] = cub[3][8];

    //Rotate White
    cube_copy[0][0] = cub[0][6];
    cube_copy[0][1] = cub[0][3];
    cube_copy[0][2] = cub[0][0];
    cube_copy[0][3] = cub[0][7];
    cube_copy[0][5] = cub[0][1];
    cube_copy[0][6] = cub[0][8];
    cube_copy[0][7] = cub[0][5];
    cube_copy[0][8] = cub[0][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

} //GOOD

static void MoveR(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Green -> Yellow
    cube_copy[1][2] = cub[3][2];
    cube_copy[1][5] = cub[3][5];
    cube_copy[1][8] = cub[3][8];

    //Yellow->Blue
    cube_copy[5][0] = cub[1][8];
    cube_copy[5][3] = cub[1][5];
    cube_copy[5][6] = cub[1][2];

    //Blue->White
    cube_copy[0][2] = cub[5][6];
    cube_copy[0][5] = cub[5][3];
    cube_copy[0][8] = cub[5][0];

    //White->Green
    cube_copy[3][2] = cub[0][2];
    cube_copy[3][5] = cub[0][5];
    cube_copy[3][8] = cub[0][8];

    //Rotate Orange
    cube_copy[4][0] = cub[4][6];
    cube_copy[4][1] = cub[4][3];
    cube_copy[4][2] = cub[4][0];
    cube_copy[4][3] = cub[4][7];
    cube_copy[4][5] = cub[4][1];
    cube_copy[4][6] = cub[4][8];
    cube_copy[4][7] = cub[4][5];
    cube_copy[4][8] = cub[4][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

} //GOOD /GOOD

static void MoveL(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Yellow -> Green
    cube_copy[3][0] = cub[1][0];
    cube_copy[3][3] = cub[1][3];
    cube_copy[3][6] = cub[1][6];

    //Green->White
    cube_copy[0][0] = cub[3][0];
    cube_copy[0][3] = cub[3][3];
    cube_copy[0][6] = cub[3][6];

    //White->Blue
    cube_copy[5][8] = cub[0][0];
    cube_copy[5][5] = cub[0][3];
    cube_copy[5][2] = cub[0][6];

    //Blue->Yellow
    cube_copy[1][0] = cub[5][8];
    cube_copy[1][3] = cub[5][5];
    cube_copy[1][6] = cub[5][2];

    //Rotate Red
    cube_copy[2][0] = cub[2][6];
    cube_copy[2][1] = cub[2][3];
    cube_copy[2][2] = cub[2][0];
    cube_copy[2][3] = cub[2][7];
    cube_copy[2][5] = cub[2][1];
    cube_copy[2][6] = cub[2][8];
    cube_copy[2][7] = cub[2][5];
    cube_copy[2][8] = cub[2][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void MoveF(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Yellow -> Orange
    cube_copy[4][0] = cub[1][6];
    cube_copy[4][3] = cub[1][7];
    cube_copy[4][6] = cub[1][8];

    //Orange->White
    cube_copy[0][0] = cub[4][6];
    cube_copy[0][1] = cub[4][3];
    cube_copy[0][2] = cub[4][0];

    //White->Red
    cube_copy[2][8] = cub[0][2];
    cube_copy[2][5] = cub[0][1];
    cube_copy[2][2] = cub[0][0];

    //Red->Yellow
    cube_copy[1][8] = cub[2][2];
    cube_copy[1][7] = cub[2][5];
    cube_copy[1][6] = cub[2][8];

    //Rotate Green
    cube_copy[3][0] = cub[3][6];
    cube_copy[3][1] = cub[3][3];
    cube_copy[3][2] = cub[3][0];
    cube_copy[3][3] = cub[3][7];
    cube_copy[3][5] = cub[3][1];
    cube_copy[3][6] = cub[3][8];
    cube_copy[3][7] = cub[3][5];
    cube_copy[3][8] = cub[3][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void MoveB(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Orange -> Yellow
    cube_copy[1][0] = cub[4][2];
    cube_copy[1][1] = cub[4][5];
    cube_copy[1][2] = cub[4][8];

    //Yellow->Red
    cube_copy[2][0] = cub[1][2];
    cube_copy[2][3] = cub[1][1];
    cube_copy[2][6] = cub[1][0];

    //Red->White
    cube_copy[0][6] = cub[2][0];
    cube_copy[0][7] = cub[2][3];
    cube_copy[0][8] = cub[2][6];

    //White->Orange
    cube_copy[4][8] = cub[0][6];
    cube_copy[4][5] = cub[0][7];
    cube_copy[4][2] = cub[0][8];

    //Rotate Blue
    cube_copy[5][0] = cub[5][6];
    cube_copy[5][1] = cub[5][3];
    cube_copy[5][2] = cub[5][0];
    cube_copy[5][3] = cub[5][7];
    cube_copy[5][5] = cub[5][1];
    cube_copy[5][6] = cub[5][8];
    cube_copy[5][7] = cub[5][5];
    cube_copy[5][8] = cub[5][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

//reverse movements : Untested

static void reverseMoveU(char cub[6][9])
{
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Green->Orange

    cube_copy[4][0] = cub[3][0];
    cube_copy[4][1] = cub[3][1];
    cube_copy[4][2] = cub[3][2];

    //Red->Green
    cube_copy[3][0] = cub[2][0];
    cube_copy[3][1] = cub[2][1];
    cube_copy[3][2] = cub[2][2];

    //Blue->Red
    cube_copy[2][0] = cub[5][0];
    cube_copy[2][1] = cub[5][1];
    cube_copy[2][2] = cub[5][2];

    //Orange->Blue
    cube_copy[5][0] = cub[4][0];
    cube_copy[5][1] = cub[4][1];
    cube_copy[5][2] = cub[4][2];

    //Rotate Yellow
    cube_copy[1][8] = cub[1][6];
    cube_copy[1][7] = cub[1][3];
    cube_copy[1][6] = cub[1][0];
    cube_copy[1][5] = cub[1][7];
    cube_copy[1][3] = cub[1][1];
    cube_copy[1][2] = cub[1][8];
    cube_copy[1][1] = cub[1][5];
    cube_copy[1][0] = cub[1][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void reverseMoveD(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Blue -> Orange
    cube_copy[4][6] = cub[5][6];
    cube_copy[4][7] = cub[5][7];
    cube_copy[4][8] = cub[5][8];

    //Red->Blue
    cube_copy[5][6] = cub[2][6];
    cube_copy[5][7] = cub[2][7];
    cube_copy[5][8] = cub[2][8];

    //Green->Red
    cube_copy[2][6] = cub[3][6];
    cube_copy[2][7] = cub[3][7];
    cube_copy[2][8] = cub[3][8];

    //Orange->Green
    cube_copy[3][6] = cub[4][6];
    cube_copy[3][7] = cub[4][7];
    cube_copy[3][8] = cub[4][8];

    //Rotate White
    cube_copy[0][8] = cub[0][6];
    cube_copy[0][7] = cub[0][3];
    cube_copy[0][6] = cub[0][0];
    cube_copy[0][5] = cub[0][7];
    cube_copy[0][3] = cub[0][1];
    cube_copy[0][2] = cub[0][8];
    cube_copy[0][1] = cub[0][5];
    cube_copy[0][0] = cub[0][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void reverseMoveR(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Yellow -> Green
    cube_copy[3][2] = cub[1][2];
    cube_copy[3][5] = cub[1][5];
    cube_copy[3][8] = cub[1][8];

    //Blue->Yellow
    cube_copy[1][8] = cub[5][0];
    cube_copy[1][5] = cub[5][3];
    cube_copy[1][2] = cub[5][6];

    //White->Blue
    cube_copy[5][0] = cub[0][8];
    cube_copy[5][3] = cub[0][5];
    cube_copy[5][6] = cub[0][2];

    //Green->White
    cube_copy[0][2] = cub[3][2];
    cube_copy[0][5] = cub[3][5];
    cube_copy[0][8] = cub[3][8];

    //Rotate Orange
    cube_copy[4][8] = cub[4][6];
    cube_copy[4][7] = cub[4][3];
    cube_copy[4][6] = cub[4][0];
    cube_copy[4][5] = cub[4][7];
    cube_copy[4][3] = cub[4][1];
    cube_copy[4][2] = cub[4][8];
    cube_copy[4][1] = cub[4][5];
    cube_copy[4][0] = cub[4][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void reverseMoveL(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Green -> Yellow
    cube_copy[1][0] = cub[3][0];
    cube_copy[1][3] = cub[3][3];
    cube_copy[1][6] = cub[3][6];

    //White->Green
    cube_copy[3][0] = cub[0][0];
    cube_copy[3][3] = cub[0][3];
    cube_copy[3][6] = cub[0][6];

    //Blue->White
    cube_copy[0][6] = cub[5][2];
    cube_copy[0][3] = cub[5][5];
    cube_copy[0][0] = cub[5][8];

    //Yellow->Blue
    cube_copy[5][8] = cub[1][0];
    cube_copy[5][5] = cub[1][3];
    cube_copy[5][2] = cub[1][6];

    //Rotate Red
    cube_copy[2][8] = cub[2][6];
    cube_copy[2][7] = cub[2][3];
    cube_copy[2][6] = cub[2][0];
    cube_copy[2][5] = cub[2][7];
    cube_copy[2][3] = cub[2][1];
    cube_copy[2][2] = cub[2][8];
    cube_copy[2][1] = cub[2][5];
    cube_copy[2][0] = cub[2][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void reverseMoveF(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Orange -> Yellow
    cube_copy[1][6] = cub[4][0];
    cube_copy[1][7] = cub[4][3];
    cube_copy[1][8] = cub[4][6];

    //White->Orange
    cube_copy[4][6] = cub[0][0];
    cube_copy[4][3] = cub[0][1];
    cube_copy[4][0] = cub[0][2];

    //Red->White
    cube_copy[0][0] = cub[2][2];
    cube_copy[0][1] = cub[2][5];
    cube_copy[0][2] = cub[2][8];

    //Yellow->Red
    cube_copy[2][8] = cub[1][6];
    cube_copy[2][5] = cub[1][7];
    cube_copy[2][2] = cub[1][8];

    //Rotate Green
    cube_copy[3][8] = cub[3][6];
    cube_copy[3][7] = cub[3][3];
    cube_copy[3][6] = cub[3][0];
    cube_copy[3][5] = cub[3][7];
    cube_copy[3][3] = cub[3][1];
    cube_copy[3][2] = cub[3][8];
    cube_copy[3][1] = cub[3][5];
    cube_copy[3][0] = cub[3][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}

static void reverseMoveB(char cub[6][9]) {
    char cube_copy[6][9];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube_copy[i][j] = cub[i][j];
        }
    }

    //Yellow -> Orange
    cube_copy[4][2] = cub[1][0];
    cube_copy[4][5] = cub[1][1];
    cube_copy[4][8] = cub[1][2];

    //Red->Yellow
    cube_copy[1][2] = cub[2][0];
    cube_copy[1][1] = cub[2][3];
    cube_copy[1][0] = cub[2][6];

    //White->Red
    cube_copy[2][0] = cub[0][6];
    cube_copy[2][3] = cub[0][7];
    cube_copy[2][6] = cub[0][8];

    //Orange->White
    cube_copy[0][8] = cub[4][2];
    cube_copy[0][7] = cub[4][5];
    cube_copy[0][6] = cub[4][8];

    //Rotate Blue
    cube_copy[5][8] = cub[5][6];
    cube_copy[5][7] = cub[5][3];
    cube_copy[5][6] = cub[5][0];
    cube_copy[5][5] = cub[5][7];
    cube_copy[5][3] = cub[5][1];
    cube_copy[5][2] = cub[5][8];
    cube_copy[5][1] = cub[5][5];
    cube_copy[5][0] = cub[5][2];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cub[i][j] = cube_copy[i][j];
        }
    }

}


//solving steps
void solveWhiteCross(char cub[6][9], string& moves)
{
    // variable initialization
    int correctWhiteEdgePieceCount = 0;
    bool isLeftEdgeSolved = false;
    bool isRightEdgeSolved = false;
    bool isTopEdgeSolved = false;
    bool isBottomEdgeSolved = false;

    if (cub[0][1] == 'W' && cub[3][7] == cub[3][4])
    {
        isTopEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (cub[0][3] == 'W' && cub[2][7] == cub[2][4])
    {
        isLeftEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (cub[0][5] == 'W' && cub[4][7] == cub[4][4])
    {
        isRightEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (cub[0][7] == 'W' && cub[5][7] == cub[5][4])
    {
        isBottomEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (cub[0][1] == 'W' && cub[3][7] != cub[3][4])
    {
        cout << "F F" << endl;
        MoveF(cub);
        MoveF(cub);
        moves = moves + "F F ";
    }

    if (cub[0][5] == 'W' && cub[4][7] != cub[4][4])
    {
        cout << "R R" << endl;
        MoveR(cub);
        MoveR(cub);
        moves = moves + "R R ";
    }

    if (cub[0][7] == 'W' && cub[5][7] != cub[5][4])
    {
        cout << "B B" << endl;
        MoveB(cub);
        MoveB(cub);
        moves = moves + "B B ";
    }

    if (cub[0][3] == 'W' && cub[2][7] != cub[2][4])
    {
        cout << "L L" << endl;
        MoveL(cub);
        MoveL(cub);
        moves = moves + "L L ";
    }


    while (correctWhiteEdgePieceCount != 4)
    {
        if (cub[1][1] == 'W')
        {
            const char current = cub[5][1];

            switch (current)
            {
            case 'B':
                cout << "B B" << endl;
                MoveB(cub);
                MoveB(cub);
                isBottomEdgeSolved = true;
                moves = moves + "B B ";
                break;
            case 'R':
                cout << "U' L L" << endl;
                reverseMoveU(cub);
                MoveL(cub);
                MoveL(cub);
                isLeftEdgeSolved = true;
                moves = moves + "U' L L ";
                break;
            case 'O':
                cout << "U R R" << endl;
                MoveU(cub);
                MoveR(cub);
                MoveR(cub);
                isRightEdgeSolved = true;
                moves = moves + "U R R ";
                break;
            case 'G':
                cout << "U U F F" << endl;
                MoveU(cub);
                MoveU(cub);
                MoveF(cub);
                MoveF(cub);
                isTopEdgeSolved = true;
                moves = moves + "U U F F ";
                break;
            default:
                cout << "ERROR:2216" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[1][3] == 'W')
        {
            const char current = cub[2][1];
            switch (current)
            {
            case 'B':
                cout << "U B B" << endl;
                MoveU(cub);
                MoveB(cub);
                MoveB(cub);
                isBottomEdgeSolved = true;
                moves = moves + "U B B ";
                break;

            case 'R':
                cout << "L L" << endl;
                MoveL(cub);
                MoveL(cub);
                isLeftEdgeSolved = true;
                moves = moves + "L L ";
                break;

            case 'O':
                cout << "U U R R" << endl;
                MoveU(cub);
                MoveU(cub);
                MoveR(cub);
                MoveR(cub);
                isRightEdgeSolved = true;
                moves = moves + "U U R R ";
                break;

            case 'G':
                cout << "U' F F" << endl;
                reverseMoveU(cub);
                MoveF(cub);
                MoveF(cub);
                isTopEdgeSolved = true;
                moves = moves + "U' F F ";
                break;

            default:
                cout << "ERROR:2257" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[1][5] == 'W')
        {
            const char current = cub[4][1];
            switch (current)
            {
            case 'B':
                cout << "U' B B" << endl;
                reverseMoveU(cub);
                MoveB(cub);
                MoveB(cub);
                isBottomEdgeSolved = true;
                moves = moves + "U' B B ";
                break;

            case 'R':
                cout << "U U L L" << endl;
                MoveU(cub);
                MoveU(cub);
                MoveL(cub);
                MoveL(cub);
                isLeftEdgeSolved = true;
                moves = moves + "U U L L ";
                break;

            case 'O':
                cout << "R R" << endl;
                MoveR(cub);
                MoveR(cub);
                isRightEdgeSolved = true;
                moves = moves + "R R ";
                break;

            case 'G':
                cout << "U F F" << endl;
                MoveU(cub);
                MoveF(cub);
                MoveF(cub);
                isTopEdgeSolved = true;
                moves = moves + "U F F ";
                break;

            default:
                cout << "ERROR:2296" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[1][7] == 'W')
        {
            const char current = cub[3][1];
            switch (current)
            {
            case 'B':
                cout << "U U B B" << endl;
                MoveU(cub);
                MoveU(cub);
                MoveB(cub);
                MoveB(cub);
                isBottomEdgeSolved = true;
                moves = moves + "U U B B ";
                break;

            case 'R':
                cout << "U L L" << endl;
                MoveU(cub);
                MoveL(cub);
                MoveL(cub);
                isLeftEdgeSolved = true;
                moves = moves + "U L L ";
                break;

            case 'O':
                cout << "U' R R" << endl;
                reverseMoveU(cub);
                MoveR(cub);
                MoveR(cub);
                isRightEdgeSolved = true;
                moves = moves + "U' R R ";
                break;

            case 'G':
                cout << "F F" << endl;
                MoveF(cub);
                MoveF(cub);
                isTopEdgeSolved = true;
                moves = moves + "F F ";
                break;

            default:
                cout << "ERROR:2336" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        // adding cases for second layer pieces
        else if (cub[3][3] == 'W')
        {
            const char current = cub[2][5];
            switch (current)
            {
            case 'B':
                cout << "D L D'" << endl;
                MoveD(cub);
                MoveL(cub);
                reverseMoveD(cub);
                isBottomEdgeSolved = true;
                moves = moves + "D L D' ";
                break;
            case 'R':
                cout << "L" << endl;
                MoveL(cub);
                isLeftEdgeSolved = true;
                moves = moves + "L ";
                break;
            case 'O':
                cout << "D D L D' D'" << endl;
                MoveD(cub);
                MoveD(cub);
                MoveL(cub);
                reverseMoveD(cub);
                reverseMoveD(cub);
                isRightEdgeSolved = true;
                moves = moves + "D D L D' D' ";
                break;
            case 'G':
                cout << "D' L D" << endl;
                reverseMoveD(cub);
                MoveL(cub);
                MoveD(cub);
                isTopEdgeSolved = true;
                moves = moves + "D' L D ";
                break;
            default:
                cout << "ERROR:2376" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[3][5] == 'W')
        {
            const char current = cub[4][3];
            switch (current)
            {
            case 'B':
                cout << "D' R' D" << endl;
                reverseMoveD(cub);
                reverseMoveR(cub);
                MoveD(cub);
                isBottomEdgeSolved = true;
                moves = moves + "D' R' D ";
                break;
            case 'R':
                cout << "D D R' D D" << endl;
                MoveD(cub);
                MoveD(cub);
                reverseMoveR(cub);
                MoveD(cub);
                MoveD(cub);
                isLeftEdgeSolved = true;
                moves = moves + "D D R' D D ";
                break;
            case 'O':
                cout << "R'" << endl;
                reverseMoveR(cub);
                isRightEdgeSolved = true;
                moves = moves + "R' ";
                break;
            case 'G':
                cout << "D R' D'" << endl;
                MoveD(cub);
                reverseMoveR(cub);
                reverseMoveD(cub);
                isTopEdgeSolved = true;
                moves = moves + "D R' D' ";
                break;
            default:
                cout << "ERROR:2412" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[5][3] == 'W')
        {
            const char current = cub[4][5];
            switch (current)
            {
            case 'B':
                cout << "D' R D" << endl;
                reverseMoveD(cub);
                MoveR(cub);
                MoveD(cub);
                isBottomEdgeSolved = true;
                moves = moves + "D' R D ";
                break;

            case 'R':
                cout << "D' D' R D D" << endl;
                reverseMoveD(cub);
                reverseMoveD(cub);
                MoveR(cub);
                MoveD(cub);
                MoveD(cub);
                isLeftEdgeSolved = true;
                moves = moves + "D' D' R D D ";
                break;

            case 'O':
                cout << "R" << endl;
                MoveR(cub);
                isRightEdgeSolved = true;
                moves = moves + "R ";
                break;

            case 'G':
                cout << "D R D'" << endl;
                MoveD(cub);
                MoveR(cub);
                reverseMoveD(cub);
                isTopEdgeSolved = true;
                moves = moves + "D R D' ";
                break;

            default:
                cout << "ERROR:2452" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[5][5] == 'W')
        {
            const char current = cub[2][3];
            switch (current)
            {
            case 'B':
                cout << "D L' D'" << endl;
                MoveD(cub);
                reverseMoveL(cub);
                reverseMoveD(cub);
                isBottomEdgeSolved = true;
                moves = moves + "D L' D' ";
                break;
            case 'R':
                cout << "L'" << endl;
                reverseMoveL(cub);
                isLeftEdgeSolved = true;
                moves = moves + "L' ";
                break;
            case 'O':
                cout << "D D L' D' D'" << endl; //test R' in loc de L'
                MoveD(cub);
                MoveD(cub);
                reverseMoveL(cub);
                reverseMoveD(cub);
                reverseMoveD(cub);
                isRightEdgeSolved = true;
                moves = moves + "D D L' D' D' ";
                break;
            case 'G':
                cout << "D' L' D" << endl;
                reverseMoveD(cub);
                reverseMoveL(cub);
                MoveD(cub);
                isTopEdgeSolved = true;
                moves = moves + "D' L' D ";
                break;
            default:
                cout << "ERROR:2488" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[2][3] == 'W')
        {
            const char current = cub[5][5];
            switch (current)
            {
            case 'B':
                cout << "B" << endl;
                MoveB(cub);
                isBottomEdgeSolved = true;
                moves = moves + "B ";
                break;

            case 'R':
                cout << "D' B D" << endl;
                reverseMoveD(cub);
                MoveB(cub);
                MoveD(cub);
                isLeftEdgeSolved = true;
                moves = moves + "D' B D ";
                break;

            case 'O':
                cout << "D  B  D'" << endl;
                MoveD(cub);
                MoveB(cub);
                reverseMoveD(cub);
                isRightEdgeSolved = true;
                moves = moves + "D B D' ";
                break;

            case 'G':
                cout << "D' D' B D D" << endl;
                reverseMoveD(cub);
                reverseMoveD(cub);
                MoveB(cub);
                MoveD(cub);
                MoveD(cub);
                isTopEdgeSolved = true;
                moves = moves + "D' D' B D D ";
                break;

            default:
                cout << "ERROR:2528" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[2][5] == 'W')
        {
            const char current = cub[3][3];
            switch (current)
            {
            case 'B':
                cout << "D D F' D' D'" << endl; //test cu F' in loc de L'
                MoveD(cub);
                MoveD(cub);
                reverseMoveF(cub);
                reverseMoveD(cub);
                reverseMoveD(cub);
                isBottomEdgeSolved = true;
                moves = moves + "D D F' D' D' ";
                break;

            case 'R':
                cout << "D F' D'" << endl;
                MoveD(cub);
                reverseMoveF(cub);
                reverseMoveD(cub);
                isLeftEdgeSolved = true;
                moves = moves + "D F' D' ";
                break;

            case 'O':
                cout << "D' F' D" << endl;
                reverseMoveD(cub);
                reverseMoveF(cub);
                MoveD(cub);
                isRightEdgeSolved = true;
                moves = moves + "D' F' D ";
                break;

            case 'G':
                cout << "F'" << endl;
                reverseMoveF(cub);
                isTopEdgeSolved = true;
                moves = moves + "F' ";
                break;

            default:
                cout << "ERROR:2568" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[4][3] == 'W')
        {
            const char current = cub[3][5];
            switch (current)
            {
            case 'B':
                cout << "D' D' F D D" << endl;
                reverseMoveD(cub);
                reverseMoveD(cub);
                MoveF(cub);
                MoveD(cub);
                MoveD(cub);
                isBottomEdgeSolved = true;
                moves = moves + "D' D' F D D ";
                break;

            case 'R':
                cout << "D F D'" << endl;
                MoveD(cub);
                MoveF(cub);
                reverseMoveD(cub);
                isLeftEdgeSolved = true;
                moves = moves + "D F D' ";
                break;

            case 'O':
                cout << "D' F D" << endl;
                reverseMoveD(cub);
                MoveF(cub);
                MoveD(cub);
                isRightEdgeSolved = true;
                moves = moves + "D' F D ";
                break;

            case 'G':
                cout << "F" << endl;
                MoveF(cub);
                isTopEdgeSolved = true;
                moves = moves + "F ";
                break;

            default:
                cout << "ERROR:2606" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (cub[4][5] == 'W')
        {
            const char current = cub[5][3];
            switch (current)
            {
            case 'B':
                cout << "B'" << endl;
                reverseMoveB(cub);
                isBottomEdgeSolved = true;
                moves = moves + "B' ";
                break;

            case 'R':
                cout << "D' B' D" << endl;
                reverseMoveD(cub);
                reverseMoveB(cub);
                MoveD(cub);
                isLeftEdgeSolved = true;
                moves = moves + "D' B' D ";
                break;

            case 'O':
                cout << "D B' D'" << endl;
                MoveD(cub);
                reverseMoveB(cub);
                reverseMoveD(cub);
                isRightEdgeSolved = true;
                moves = moves + "D B' D' ";
                break;

            case 'G':
                cout << "D D B' D D" << endl;
                MoveD(cub);
                MoveD(cub);
                reverseMoveB(cub);
                MoveD(cub);
                MoveD(cub);
                isTopEdgeSolved = true;
                moves = moves + "D D B' D D ";
                break;

            default:
                cout << "ERROR:2648" << endl;
                break;
            }
            correctWhiteEdgePieceCount++;
        }

        // Cases for first, third layered pieces
        // after the turn i must place the white piece here otherwise infinite loop
        else if (cub[3][1] == 'W')
        {
            if (!isTopEdgeSolved)
            {
                if (cub[1][7] == cub[2][4])
                {
                    cout << "F'" << endl;
                    reverseMoveF(cub);
                    moves = moves + "F' ";
                }
                else
                {
                    cout << "F" << endl;
                    moves = moves + "F ";
                    MoveF(cub);
                }

            }

            else if (!isRightEdgeSolved)
            {
                cout << "U'" << endl;
                reverseMoveU(cub);
                if (cub[1][5] == cub[3][4])
                {
                    cout << "R'" << endl;
                    moves = moves + "R' ";
                    reverseMoveR(cub);
                }
                else
                {
                    cout << "R" << endl;
                    moves = moves + "R ";
                    MoveR(cub);
                }
            }

            else if (!isLeftEdgeSolved)
            {
                cout << "U" << endl;
                moves = moves + "U ";
                MoveU(cub);
                if (!isLeftEdgeSolved)
                {
                    if (cub[1][3] == cub[3][4])
                    {
                        cout << "L" << endl;
                        moves = moves + "L ";
                        MoveL(cub);
                    }
                    else
                    {
                        cout << "L'" << endl;
                        moves = moves + "L' ";
                        reverseMoveL(cub);
                    }
                }
            }

            else if (!isBottomEdgeSolved)
            {
                cout << "U U" << endl;
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
                if (cub[1][1] == cub[2][4])
                {
                    cout << "B" << endl;
                    MoveB(cub);
                    moves = moves + "B ";
                }
                else
                {
                    cout << "B'" << endl;
                    reverseMoveB(cub);
                    moves = moves + "B' ";
                }
            }

            else
            {
                cout << "ERROR: else if (cub[3][1] == 'W')" << endl;
            }
        }

        else if (cub[3][7] == 'W')
        {
            if (cub[0][1] == cub[2][4])
            {
                cout << "F" << endl;
                MoveF(cub);
                moves = moves + "F ";
            }
            else
            {
                cout << "F'" << endl;
                reverseMoveF(cub);
                moves = moves + "F' ";
            }
        }

        else if (cub[5][1] == 'W')
        {
            if (!isBottomEdgeSolved)
            {
                if (cub[1][1] == cub[2][4])
                {
                    cout << "B" << endl;
                    MoveB(cub);
                    moves = moves + "B ";
                }
                else
                {
                    cout << "B'" << endl;
                    reverseMoveB(cub);
                    moves = moves + "B' ";
                }
            }

            else if (!isLeftEdgeSolved)
            {
                cout << "U'" << endl;
                moves = moves + "U' ";
                reverseMoveU(cub);
                if (cub[1][3] == cub[3][4])
                {
                    cout << "L" << endl;
                    MoveL(cub);
                    moves = moves + "L ";
                }
                else
                {
                    cout << "L'" << endl;
                    reverseMoveL(cub);
                    moves = moves + "L' ";
                }
            }

            else if (!isRightEdgeSolved)
            {
                cout << "U" << endl;
                moves = moves + "U ";
                MoveU(cub);
                if (!isRightEdgeSolved)
                {
                    if (cub[1][5] == cub[3][4])
                    {
                        cout << "R'" << endl;
                        reverseMoveR(cub);
                        moves = moves + "R' ";
                    }
                    else
                    {
                        cout << "R" << endl;
                        MoveR(cub);
                        moves = moves + "R ";
                    }
                }
            }

            else if (!isTopEdgeSolved)
            {
                cout << "U U" << endl;
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
                if (cub[1][7] == cub[2][4])
                {
                    cout << "F'" << endl;
                    reverseMoveF(cub);
                    moves = moves + "F' ";
                }
                else
                {
                    cout << "F" << endl;
                    MoveF(cub);
                    moves = moves + "F ";
                }
            }

            else
            {
                cout << "ERROR: else if (cub[5][1] == 'W') " << endl;
            }
        }

        else if (cub[5][7] == 'W')
        {
            if (cub[0][7] == cub[2][4])
            {
                cout << "B'" << endl;
                reverseMoveB(cub);
                moves = moves + "B' ";
            }
            else
            {
                cout << "B" << endl;
                moves = moves + "B ";
                MoveB(cub);
            }
        }

        else if (cub[2][1] == 'W')
        {
            if (!isLeftEdgeSolved)
            {
                if (cub[1][3] == cub[3][4])
                {
                    cout << "L" << endl;
                    MoveL(cub);
                    moves = moves + "L ";
                }
                else
                {
                    cout << "L'" << endl;
                    reverseMoveL(cub);
                    moves = moves + "L' ";
                }
            }

            else if (!isTopEdgeSolved)
            {
                cout << "U'" << endl;
                reverseMoveU(cub);
                moves = moves + "U' ";
                if (cub[1][7] == cub[2][4])
                {
                    cout << "F'" << endl;
                    reverseMoveF(cub);
                    moves = moves + "F' ";
                }
                else
                {
                    cout << "F" << endl;
                    moves = moves + "F ";
                    MoveF(cub);
                }
            }

            else if (!isBottomEdgeSolved)
            {
                cout << "U" << endl;
                MoveU(cub);
                moves = moves + "U ";
                if (cub[1][1] == cub[2][4])
                {
                    cout << "B" << endl;
                    MoveB(cub);
                    moves = moves + "B ";
                }
                else
                {
                    cout << "B'" << endl;
                    reverseMoveB(cub);
                    moves = moves + "B' ";
                }
            }

            else if (!isRightEdgeSolved)
            {
                cout << "U U" << endl;
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
                if (cub[1][5] == cub[3][4])
                {
                    cout << "R'" << endl;
                    reverseMoveR(cub);
                    moves = moves + "R' ";
                }
                else
                {
                    cout << "R" << endl;
                    moves = moves + "R ";
                    MoveR(cub);
                }
            }

            else
            {
                cout << "ERROR: else if (cub[2][1] == 'W')" << endl;
            }
        }

        else if (cub[2][7] == 'W')
        {
            if (cub[0][3] == cub[3][4])
            {
                cout << "L'" << endl;
                reverseMoveL(cub);
                moves = moves + "L' ";
            }
            else
            {
                cout << "L" << endl;
                MoveL(cub);
                moves = moves + "L ";
            }
        }

        else if (cub[4][1] == 'W')
        {
            if (!isRightEdgeSolved)
            {
                if (cub[1][5] == cub[3][4])
                {
                    cout << "R'" << endl;
                    reverseMoveR(cub);
                    moves = moves + "R' ";
                }
                else
                {
                    cout << "R" << endl;
                    MoveR(cub);
                    moves = moves + "R ";
                }
            }

            else if (!isTopEdgeSolved)
            {
                cout << "U" << endl;
                MoveU(cub);
                moves = moves + "U ";
                if (cub[1][7] == cub[2][4])
                {
                    cout << "F'" << endl;
                    reverseMoveF(cub);
                    moves = moves + "F' ";
                }
                else
                {
                    cout << "F" << endl;
                    moves = moves + "F ";
                    MoveF(cub);
                }
            }

            else if (!isBottomEdgeSolved)
            {
                cout << "U'" << endl;
                reverseMoveU(cub);
                moves = moves + "U' ";
                if (cub[1][1] == cub[2][4])
                {
                    cout << "B" << endl;
                    MoveB(cub);
                    moves = moves + "B ";
                }
                else
                {
                    cout << "B'" << endl;
                    reverseMoveB(cub);
                    moves = moves + "B' ";
                }
            }

            else if (!isLeftEdgeSolved)
            {
                cout << "U U" << endl;
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
                if (cub[1][3] == cub[3][4])
                {
                    cout << "L" << endl;
                    MoveL(cub);
                    moves = moves + "L ";
                }
                else
                {
                    cout << "L'" << endl;
                    reverseMoveL(cub);
                    moves = moves + "L' ";
                }
            }

            else
            {
                cout << "ERROR: else if (cub[4][1] == 'W') " << endl;
            }
        }

        else if (cub[4][7] == 'W')
        {
            if (cub[0][5] == cub[3][4])
            {
                cout << "R" << endl;
                MoveR(cub);
                moves = moves + "R ";
            }
            else
            {
                cout << "R'" << endl;
                reverseMoveR(cub);
                moves = moves + "R' ";
            }
        }

        correctWhiteEdgePieceCount = 0;

        if (cub[0][1] == 'W' && cub[3][7] == cub[3][4])
        {
            isTopEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }

        if (cub[0][3] == 'W' && cub[2][7] == cub[2][4])
        {
            isLeftEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }

        if (cub[0][5] == 'W' && cub[4][7] == cub[4][4])
        {
            isRightEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }

        if (cub[0][7] == 'W' && cub[5][7] == cub[5][4])
        {
            isBottomEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }
    }

    cout << endl;
    cout << "White Cross Solved!" << endl;
    cout << "---------------------------------" << endl;
}

void solveWhiteFace(char cub[6][9], string& moves)
{
    int whiteCornerCount = 0;
    bool isTopLeftSolved = false;
    bool isTopRightSolved = false;
    bool isBottomLeftSolved = false;
    bool isBottomRightSolved = false;


    if (cub[0][0] == cub[0][4] && cub[3][6] == cub[3][4] && cub[2][8] == cub[2][4])
    {
        ++whiteCornerCount;
        isTopLeftSolved = true;
    }

    if (cub[0][2] == cub[0][4] && cub[3][8] == cub[3][4] && cub[4][6] == cub[4][4])
    {
        ++whiteCornerCount;
        isTopRightSolved = true;
    }

    if (cub[0][6] == cub[0][4] && cub[2][6] == cub[2][4] && cub[5][8] == cub[5][4])
    {
        ++whiteCornerCount;
        isBottomLeftSolved = true;
    }

    if (cub[0][8] == cub[0][4] && cub[4][8] == cub[4][4] && cub[5][6] == cub[5][4])
    {
        ++whiteCornerCount;
        isBottomRightSolved = true;
    }

    while (whiteCornerCount < 4)
    {
        // 1 left directions
        if (cub[4][0] == 'W' && cub[1][8] == cub[3][4] && cub[3][2] == cub[2][4])
        {
            // L' U L
            reverseMoveL(cub);
            MoveU(cub);
            MoveL(cub);
            cout << "L' U L" << endl;
            ++whiteCornerCount;
            isTopLeftSolved = true;
            moves = moves + "L' U L ";
        }

        else if (cub[5][0] == 'W' && cub[1][2] == cub[4][4] && cub[4][2] == cub[3][4])
        {
            // F' U F
            reverseMoveF(cub);
            MoveU(cub);
            MoveF(cub);
            cout << "F' U F" << endl;
            ++whiteCornerCount;
            isTopRightSolved = true;
            moves = moves + "F' U F ";
        }

        else if (cub[2][0] == 'W' && cub[1][0] == cub[5][4] && cub[5][2] == cub[4][4])
        {
            // R' U R
            reverseMoveR(cub);
            MoveU(cub);
            MoveR(cub);
            cout << "R' U R" << endl;
            ++whiteCornerCount;
            isBottomRightSolved = true;
            moves = moves + "R' U R ";
        }

        else if (cub[3][0] == 'W' && cub[1][6] == cub[2][4] && cub[2][2] == cub[5][4])
        {
            // B' U B
            reverseMoveB(cub);
            MoveU(cub);
            MoveB(cub);
            cout << "B' U B" << endl;
            ++whiteCornerCount;
            isBottomLeftSolved = true;
            moves = moves + "B' U B ";
        }

        // 1 right directions
        else if (cub[2][2] == 'W' && cub[1][6] == cub[3][4] && cub[3][0] == cub[4][4])
        {
            // R U' R'
            MoveR(cub);
            reverseMoveU(cub);
            reverseMoveR(cub);
            cout << "R U' R'" << endl;
            ++whiteCornerCount;
            isTopRightSolved = true;
            moves = moves + "R U' R' ";
        }

        else if (cub[5][2] == 'W' && cub[1][0] == cub[2][4] && cub[2][0] == cub[3][4])
        {
            // F U' F'
            MoveF(cub);
            reverseMoveU(cub);
            reverseMoveF(cub);
            cout << "F U' F'" << endl;
            ++whiteCornerCount;
            isTopLeftSolved = true;
            moves = moves + "F U' F' ";
        }

        else if (cub[4][2] == 'W' && cub[1][2] == cub[5][4] && cub[5][0] == cub[2][4])
        {
            // L U' L'
            MoveL(cub);
            reverseMoveU(cub);
            reverseMoveL(cub);
            cout << "L U' L'" << endl;
            ++whiteCornerCount;
            isBottomLeftSolved = true;
            moves = moves + "L U' L' ";
        }

        else if (cub[3][2] == 'W' && cub[1][8] == cub[4][4] && cub[4][0] == cub[5][4])
        {
            // B U' B'
            MoveB(cub);
            reverseMoveU(cub);
            reverseMoveB(cub);
            cout << "B U' B'" << endl;
            ++whiteCornerCount;
            isBottomRightSolved = true;
            moves = moves + "B U' B' ";
        }
        //2 step l-r directions
        // if we couldn't do any algorithms above and still have white side
        // in third layer we should do move U or U'
        // turn U and checks the ifs above
        // if no correct piece then backtrack and turn U' check again
        // if no correct piece again then do U U and check

        else
        {
            MoveU(cub);
            moves = moves + "U ";
            // U case
            // 1 left directions
            if (cub[4][0] == 'W' && cub[1][8] == cub[3][4] && cub[3][2] == cub[2][4])
            {
                // L' U L
                reverseMoveL(cub);
                MoveU(cub);
                MoveL(cub);
                cout << "L' U L" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                moves = moves + "L' U L ";
                continue;

            }

            else if (cub[5][0] == 'W' && cub[1][2] == cub[4][4] && cub[4][2] == cub[3][4])
            {
                // F' U F
                reverseMoveF(cub);
                MoveU(cub);
                MoveF(cub);
                cout << "F' U F" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                moves = moves + "F' U F ";
                continue;

            }

            else if (cub[2][0] == 'W' && cub[1][0] == cub[5][4] && cub[5][2] == cub[4][4])
            {
                // R' U R
                reverseMoveR(cub);
                MoveU(cub);
                MoveR(cub);
                cout << "R' U R" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                moves = moves + "R' U R ";
                continue;

            }

            else if (cub[3][0] == 'W' && cub[1][6] == cub[2][4] && cub[2][2] == cub[5][4])
            {
                // B' U B
                reverseMoveB(cub);
                MoveU(cub);
                MoveB(cub);
                cout << "B' U B" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                moves = moves + "B' U B ";
                continue;
            }

            // 1 right directions
            else if (cub[2][2] == 'W' && cub[1][6] == cub[3][4] && cub[3][0] == cub[4][4])
            {
                // R U' R'
                MoveR(cub);
                reverseMoveU(cub);
                reverseMoveR(cub);
                cout << "R U' R'" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                moves = moves + "R U' R' ";
                continue;
            }

            else if (cub[5][2] == 'W' && cub[1][0] == cub[2][4] && cub[2][0] == cub[3][4])
            {
                // F U' F'
                MoveF(cub);
                reverseMoveU(cub);
                reverseMoveF(cub);
                cout << "F U' F'" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                moves = moves + "F U' F' ";
                continue;
            }

            else if (cub[4][2] == 'W' && cub[1][2] == cub[5][4] && cub[5][0] == cub[2][4])
            {
                // L U' L'
                MoveL(cub);
                reverseMoveU(cub);
                reverseMoveL(cub);
                cout << "L U' L'" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                moves = moves + "L U' L' ";
                continue;
            }

            else if (cub[3][2] == 'W' && cub[1][8] == cub[4][4] && cub[4][0] == cub[5][4])
            {
                // B U' B'
                MoveB(cub);
                reverseMoveU(cub);
                reverseMoveB(cub);
                cout << "B U' B'" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                moves = moves + "B U' B' ";
                continue;
            }

            reverseMoveU(cub);
            reverseMoveU(cub);
            moves = moves + "U' U' ";
            // U' case
            // 
            // 1 left directions
            if (cub[4][0] == 'W' && cub[1][8] == cub[3][4] && cub[3][2] == cub[2][4])
            {
                // L' U L
                reverseMoveL(cub);
                MoveU(cub);
                MoveL(cub);
                cout << "L' U L" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                moves = moves + "L' U L ";
                continue;
            }

            else if (cub[5][0] == 'W' && cub[1][2] == cub[4][4] && cub[4][2] == cub[3][4])
            {
                // F' U F
                reverseMoveF(cub);
                MoveU(cub);
                MoveF(cub);
                cout << "F' U F" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                moves = moves + "F' U F ";
                continue;
            }

            else if (cub[2][0] == 'W' && cub[1][0] == cub[5][4] && cub[5][2] == cub[4][4])
            {
                // R' U R
                reverseMoveR(cub);
                MoveU(cub);
                MoveR(cub);
                cout << "R' U R" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                moves = moves + "R' U R ";
                continue;
            }

            else if (cub[3][0] == 'W' && cub[1][6] == cub[2][4] && cub[2][2] == cub[5][4])
            {
                // B' U B
                reverseMoveB(cub);
                MoveU(cub);
                MoveB(cub);
                cout << "B' U B" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                moves = moves + "B' U B ";
                continue;
            }

            // 1 right directions
            else if (cub[2][2] == 'W' && cub[1][6] == cub[3][4] && cub[3][0] == cub[4][4])
            {
                // R U' R'
                MoveR(cub);
                reverseMoveU(cub);
                reverseMoveR(cub);
                cout << "R U' R'" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                moves = moves + "R U' R' ";
                continue;
            }

            else if (cub[5][2] == 'W' && cub[1][0] == cub[2][4] && cub[2][0] == cub[3][4])
            {
                // F U' F'
                MoveF(cub);
                reverseMoveU(cub);
                reverseMoveF(cub);
                cout << "F U' F'" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                moves = moves + "F U' F' ";
                continue;
            }

            else if (cub[4][2] == 'W' && cub[1][2] == cub[5][4] && cub[5][0] == cub[2][4])
            {
                // L U' L'
                MoveL(cub);
                reverseMoveU(cub);
                reverseMoveL(cub);
                cout << "L U' L'" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                moves = moves + "L U' L' ";
                continue;
            }

            else if (cub[3][2] == 'W' && cub[1][8] == cub[4][4] && cub[4][0] == cub[5][4])
            {
                // B U' B'
                MoveB(cub);
                reverseMoveU(cub);
                reverseMoveB(cub);
                cout << "B U' B'" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                moves = moves + "B U' B' ";
                continue;
            }

            // U' U' case
            reverseMoveU(cub);
            moves = moves + "U' ";
            // 1 left directions
            if (cub[4][0] == 'W' && cub[1][8] == cub[3][4] && cub[3][2] == cub[2][4])
            {
                // L' U L
                reverseMoveL(cub);
                MoveU(cub);
                MoveL(cub);
                cout << "L' U L" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                moves = moves + "L' U L ";
                continue;
            }

            else if (cub[5][0] == 'W' && cub[1][2] == cub[4][4] && cub[4][2] == cub[3][4])
            {
                // F' U F
                reverseMoveF(cub);
                MoveU(cub);
                MoveF(cub);
                cout << "F' U F" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                moves = moves + "F' U F ";
                continue;
            }

            else if (cub[2][0] == 'W' && cub[1][0] == cub[5][4] && cub[5][2] == cub[4][4])
            {
                // R' U R
                reverseMoveR(cub);
                MoveU(cub);
                MoveR(cub);
                cout << "R' U R" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                moves = moves + "R' U R ";
                continue;
            }

            else if (cub[3][0] == 'W' && cub[1][6] == cub[2][4] && cub[2][2] == cub[5][4])
            {
                // B' U B
                reverseMoveB(cub);
                MoveU(cub);
                MoveB(cub);
                cout << "B' U B" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                moves = moves + "B' U B ";
                continue;
            }

            // 1 right directions
            else if (cub[2][2] == 'W' && cub[1][6] == cub[3][4] && cub[3][0] == cub[4][4])
            {
                // R U' R'
                MoveR(cub);
                reverseMoveU(cub);
                reverseMoveR(cub);
                cout << "R U' R'" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                moves = moves + "R U' R' ";
                continue;
            }

            else if (cub[5][2] == 'W' && cub[1][0] == cub[2][4] && cub[2][0] == cub[3][4])
            {
                // F U' F'
                MoveF(cub);
                reverseMoveU(cub);
                reverseMoveF(cub);
                cout << "F U' F'" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                moves = moves + "F U' F' ";
                continue;
            }

            else if (cub[4][2] == 'W' && cub[1][2] == cub[5][4] && cub[5][0] == cub[2][4])
            {
                // L U' L'
                MoveL(cub);
                reverseMoveU(cub);
                reverseMoveL(cub);
                cout << "L U' L'" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                moves = moves + "L U' L' ";
                continue;
            }

            else if (cub[3][2] == 'W' && cub[1][8] == cub[4][4] && cub[4][0] == cub[5][4])
            {
                // B U' B'
                MoveB(cub);
                reverseMoveU(cub);
                reverseMoveB(cub);
                cout << "B U' B'" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                moves = moves + "B U' B' ";
                continue;
            }

            // we considered every case that includes third layer white piece
            // but what to do if there is no white piece in the third layer?
            // 
            // in up side of the cube
            // put the white face on top of the empty corner and 
            // do: R U' R OR L' U L' (according to its place)
            // TopLeft: R U R'
            // TopRight: L' U' L
            // BottomLeft: L' U L
            // BottomRight: R U' R'
            else
            {
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";

                if (cub[1][0] == 'W' && !isTopRightSolved)
                {
                    cout << "R U R'" << endl;
                    MoveR(cub);
                    MoveU(cub);
                    reverseMoveR(cub);
                    moves = moves + "R U R' ";
                }

                else if (cub[1][2] == 'W' && !isTopLeftSolved)
                {
                    cout << "L' U' L" << endl;
                    reverseMoveL(cub);
                    reverseMoveU(cub);
                    MoveL(cub);
                    moves = moves + "L' U' L ";
                }

                else if (cub[1][6] == 'W' && !isTopLeftSolved)
                {
                    cout << "L' U L" << endl;
                    reverseMoveL(cub);
                    MoveU(cub);
                    MoveL(cub);
                    moves = moves + "L' U L ";
                }

                else if (cub[1][8] == 'W' && !isTopRightSolved)
                {
                    cout << "R U' R'" << endl;
                    MoveR(cub);
                    reverseMoveU(cub);
                    reverseMoveR(cub);
                    moves = moves + "R U' R' ";
                }

                else if (cub[1][8] == 'W' && !isBottomLeftSolved)
                {
                    // L U L'
                    cout << "L U L'" << endl;
                    MoveL(cub);
                    MoveU(cub);
                    reverseMoveL(cub);
                    moves = moves + "L U L' ";
                }

                else if (cub[1][6] == 'W' && !isBottomRightSolved)
                {
                    // R' U' R
                    cout << "R' U' R" << endl;
                    reverseMoveR(cub);
                    reverseMoveU(cub);
                    MoveR(cub);
                    moves = moves + "R' U' R ";
                }

                else if (cub[1][2] == 'W' && !isBottomRightSolved)
                {
                    //R' U R
                    cout << "R' U R" << endl;
                    reverseMoveR(cub);
                    MoveU(cub);
                    MoveR(cub);
                    moves = moves + "R' U R ";
                }

                else if (cub[1][0] == 'W' && !isBottomLeftSolved)
                {
                    // L U' L'
                    cout << "L U' L'" << endl;
                    MoveL(cub);
                    reverseMoveU(cub);
                    reverseMoveL(cub);
                    moves = moves + "L U' L' ";
                }

                else if (cub[3][6] == 'W')
                {
                    cout << "L' U L" << endl;
                    reverseMoveL(cub);
                    MoveU(cub);
                    MoveL(cub);
                    moves = moves + "L' U L ";
                }

                else if (cub[3][8] == 'W')
                {
                    cout << "R U' R'" << endl;
                    MoveR(cub);
                    reverseMoveU(cub);
                    reverseMoveR(cub);
                    moves = moves + "R U' R' ";
                }

                else if (cub[5][6] == 'W')
                {
                    cout << "R' U R" << endl;
                    reverseMoveR(cub);
                    MoveU(cub);
                    MoveR(cub);
                    moves = moves + "R' U R ";
                }

                else if (cub[5][8] == 'W')
                {
                    cout << "L U' L'" << endl;
                    MoveL(cub);
                    reverseMoveU(cub);
                    reverseMoveL(cub);
                    moves = moves + "L U' L' ";
                }

                else if (cub[2][6] == 'W')
                {
                    cout << "B' U B" << endl;
                    reverseMoveB(cub);
                    MoveU(cub);
                    MoveB(cub);
                    moves = moves + "B' U B ";
                }

                else if (cub[2][8] == 'W')
                {
                    cout << "F U' F'" << endl;
                    MoveF(cub);
                    reverseMoveU(cub);
                    reverseMoveF(cub);
                    moves = moves + "F U' F'";
                }

                else if (cub[4][6] == 'W')
                {
                    cout << "F' U F" << endl;
                    reverseMoveF(cub);
                    MoveU(cub);
                    MoveF(cub);
                    moves = moves + "F' U F";
                }

                else if (cub[4][8] == 'W')
                {
                    cout << "B U' B'" << endl;
                    MoveB(cub);
                    reverseMoveU(cub);
                    reverseMoveB(cub);
                    moves = moves + "B U' B' ";
                }

                else if (cub[0][0] == 'W' && !isTopLeftSolved)
                {
                    cout << "L' U' L" << endl;
                    reverseMoveL(cub);
                    reverseMoveU(cub);
                    MoveL(cub);
                    moves = moves + "L' U' L ";
                }

                else if (cub[0][2] == 'W' && !isTopRightSolved)
                {
                    cout << "R U R'" << endl;
                    MoveR(cub);
                    MoveU(cub);
                    reverseMoveR(cub);
                    moves = moves + "R U R' ";
                }

                else if (cub[0][6] == 'W' && !isBottomLeftSolved)
                {
                    cout << "L U L'" << endl;
                    MoveL(cub);
                    MoveU(cub);
                    reverseMoveL(cub);
                    moves = moves + "L U L' ";
                }

                else if (cub[0][8] == 'W' && !isBottomRightSolved)
                {
                    cout << "R' U' R" << endl;
                    reverseMoveR(cub);
                    reverseMoveU(cub);
                    MoveR(cub);
                    moves = moves + "R' U' R";
                }

                else
                {
                    cout << "U" << endl;
                    MoveU(cub);
                    moves = moves + "U ";
                }
            }
        }
    }
    cout << endl;
    cout << "First Layer Solved !" << endl;
    cout << "---------------------------------" << endl;
}

void solveSecondLayer(char cub[6][9], string& moves)
{
    int correctPieces = 0;

    if (cub[3][5] == cub[3][4] && cub[4][3] == cub[4][4])
    {
        correctPieces++;
    }

    if (cub[3][3] == cub[3][4] && cub[2][5] == cub[2][4])
    {
        correctPieces++;
    }

    if (cub[5][5] == cub[5][4] && cub[2][3] == cub[2][4])
    {
        correctPieces++;
    }

    if (cub[5][3] == cub[5][4] && cub[4][5] == cub[4][4])
    {
        correctPieces++;
    }

    while (correctPieces != 4)
    {
        if (cub[3][1] == cub[3][4] && cub[1][7] != cub[1][4])
        {
            // decide to move left or right
            if (cub[1][7] == cub[2][4])//left  U' L' U L U F U' F'
            {
                cout << "U' L' U L U F U' F'" << endl;
                reverseMoveU(cub);
                reverseMoveL(cub);
                MoveU(cub);
                MoveL(cub);
                MoveU(cub);
                MoveF(cub);
                reverseMoveU(cub);
                reverseMoveF(cub);
                moves = moves + "U' L' U L U F U' F' ";
            }
            else if (cub[1][7] == cub[4][4])// right U R U' R' U' F' U F
            {
                cout << "U R U' R' U' F' U F" << endl;
                MoveU(cub);
                MoveR(cub);
                reverseMoveU(cub);
                reverseMoveR(cub);
                reverseMoveU(cub);
                reverseMoveF(cub);
                MoveU(cub);
                MoveF(cub);
                moves = moves + "U R U' R' U' F' U F ";
            }
            else
            {
                cout << "ERROR 1189 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else if (cub[5][1] == cub[5][4] && cub[1][1] != cub[1][4])
        {
            // decide to move left or right
            if (cub[1][1] == cub[4][4]) // left: U' L' U L U F U' F' from back
            {
                // U' R' U R U B' U' B'
                cout << "U' R' U R U B U' B'" << endl;
                reverseMoveU(cub);
                reverseMoveR(cub);
                MoveU(cub);
                MoveR(cub);
                MoveU(cub);
                MoveB(cub);
                reverseMoveU(cub);
                reverseMoveB(cub);
                moves = moves + "U' R' U R U B U' B' ";
            }
            else if (cub[1][1] == cub[2][4]) // right: U R U' R' U' F' U F from back
            {
                // U L U' L' U' B' U B
                cout << "U L U' L' U' B' U B" << endl;
                MoveU(cub);
                MoveL(cub);
                reverseMoveU(cub);
                reverseMoveL(cub);
                reverseMoveU(cub);
                reverseMoveB(cub);
                MoveU(cub);
                MoveB(cub);
                moves = moves + "U L U' L' U' B' U B ";
            }
            else
            {
                cout << "ERROR 1241 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else if (cub[2][1] == cub[2][4] && cub[1][3] != cub[1][4])
        {
            // decide to move left or right
            if (cub[1][3] == cub[5][4]) // left: U' L' U L U F U' F' from left
            {
                // U' B' U B U L U' L
                cout << "U' B' U B U L U' L'" << endl;
                reverseMoveU(cub);
                reverseMoveB(cub);
                MoveU(cub);
                MoveB(cub);
                MoveU(cub);
                MoveL(cub);
                reverseMoveU(cub);
                reverseMoveL(cub);
                moves = moves + "U' B' U B U L U' L' ";
            }
            else if (cub[1][3] == cub[3][4]) // right: U R U' R' U' F' U F from left
            {
                // U F U' F' U' L' U L
                cout << "U F U' F' U' L' U L" << endl;
                MoveU(cub);
                MoveF(cub);
                reverseMoveU(cub);
                reverseMoveF(cub);
                reverseMoveU(cub);
                reverseMoveL(cub);
                MoveU(cub);
                MoveL(cub);
                moves = moves + "U F U' F' U' L' U L ";
            }
            else
            {
                cout << "ERROR 1277 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else if (cub[4][1] == cub[4][4] && cub[1][5] != cub[1][4])
        {
            // decide to move left or right
            if (cub[1][5] == cub[3][4]) // left: U' L' U L U F U' F' from right
            {
                // U' F' U F U R U' R'
                cout << "U' F' U F U R U' R'" << endl;
                reverseMoveU(cub);
                reverseMoveF(cub);
                MoveU(cub);
                MoveF(cub);
                MoveU(cub);
                MoveR(cub);
                reverseMoveU(cub);
                reverseMoveR(cub);
                moves = moves + "U' F' U F U R U' R' ";
            }
            else if (cub[1][5] == cub[5][4]) // right: U R U' R' U' F' U F from right
            {
                // U B U' B' U' R' U R
                cout << "U B U' B' U' R' U R" << endl;
                MoveU(cub);
                MoveB(cub);
                reverseMoveU(cub);
                reverseMoveB(cub);
                reverseMoveU(cub);
                reverseMoveR(cub);
                MoveU(cub);
                MoveR(cub);
                moves = moves + "U B U' B' U' R' U R ";
            }
            else
            {
                cout << "ERROR 1313 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else
        {
            // check if there is 
            // "correct piece in wrong position"
            // make turns to do upper conditions correct if possible
            // if not there is/are piece(s) in the wrong position
            if (cub[2][1] == cub[3][4] && cub[1][3] != cub[1][4])
            {
                cout << "U' ";
                reverseMoveU(cub);
                moves = moves + "U' ";
            }

            else if (cub[5][1] == cub[2][4] && cub[1][1] != cub[1][4])
            {
                cout << "U' ";
                reverseMoveU(cub);
                moves = moves + "U' ";
            }

            else if (cub[4][1] == cub[5][4] && cub[1][5] != cub[1][4])
            {
                cout << "U' ";
                reverseMoveU(cub);
                moves = moves + "U' ";
            }

            else if (cub[3][1] == cub[4][4] && cub[1][7] != cub[1][4])
            {
                cout << "U' ";
                reverseMoveU(cub);
                moves = moves + "U' ";
            }

            else if (cub[2][1] == cub[5][4] && cub[1][3] != cub[1][4])
            {
                cout << "U ";
                MoveU(cub);
                moves = moves + "U ";
            }

            else if (cub[5][1] == cub[4][4] && cub[1][1] != cub[1][4])
            {
                cout << "U ";
                MoveU(cub);
                moves = moves + "U ";
            }

            else if (cub[4][1] == cub[3][4] && cub[1][5] != cub[1][4])
            {
                cout << "U ";
                MoveU(cub);
                moves = moves + "U ";
            }

            else if (cub[3][1] == cub[2][4] && cub[1][7] != cub[1][4])
            {
                cout << "U ";
                MoveU(cub);
                moves = moves + "U ";
            }

            else if (cub[2][1] == cub[4][4] && cub[1][3] != cub[1][4])
            {
                cout << "U U ";
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
            }

            else if (cub[5][1] == cub[3][4] && cub[1][1] != cub[1][4])
            {
                cout << "U U ";
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
            }

            else if (cub[4][1] == cub[2][4] && cub[1][5] != cub[1][4])
            {
                cout << "U U ";
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
            }

            else if (cub[3][1] == cub[5][4] && cub[1][7] != cub[1][4])
            {
                cout << "U U ";
                MoveU(cub);
                MoveU(cub);
                moves = moves + "U U ";
            }

            else
            {
                // we need to get the wrong positioned piece out of its place
                // we have to check every corner

                if (cub[3][5] != cub[1][4] && cub[4][3] != cub[1][4]
                    && !(cub[3][5] == cub[3][4] && cub[4][3] == cub[4][4]))
                {
                    // do the algo
                    // front-> saða parçayý koyma algoritmasý
                    // U R U' R' U' F' U F
                    cout << "U R U' R' U' F' U F" << endl;
                    MoveU(cub);
                    MoveR(cub);
                    reverseMoveU(cub);
                    reverseMoveR(cub);
                    reverseMoveU(cub);
                    reverseMoveF(cub);
                    MoveU(cub);
                    MoveF(cub);
                    moves = moves + "U R U' R' U' F' U F ";
                }

                else if (cub[3][3] != cub[1][4] && cub[2][5] != cub[1][4]
                    && !(cub[3][3] == cub[3][4] && cub[2][5] == cub[2][4]))
                {
                    // do the algo
                    // front-> sola parçayý koyma algoritmasý
                    // U' L' U L U F U' F'
                    cout << "U' L' U L U F U' F'" << endl;
                    reverseMoveU(cub);
                    reverseMoveL(cub);
                    MoveU(cub);
                    MoveL(cub);
                    MoveU(cub);
                    MoveF(cub);
                    reverseMoveU(cub);
                    reverseMoveF(cub);
                    moves = moves + "U' L' U L U F U' F' ";
                }
                // after this we will check from back

                else if (cub[5][3] != cub[1][4] && cub[4][5] != cub[1][4]
                    && !(cub[5][3] == cub[5][4] && cub[4][5] == cub[4][4]))
                {
                    // do the algo
                    // back-> sola parçayý koyma algoritmasý
                    // algorithm bellow has issue
                    cout << "U' R' U R U B U' B'" << endl;
                    reverseMoveU(cub);
                    reverseMoveR(cub);
                    MoveU(cub);
                    MoveR(cub);
                    MoveU(cub);
                    MoveB(cub);
                    reverseMoveU(cub);
                    reverseMoveB(cub);
                    moves = moves + "U' R' U R U B U' B' ";
                }

                else if (cub[5][5] != cub[1][4] && cub[2][3] != cub[1][4]
                    && !(cub[5][5] == cub[5][4] && cub[2][3] == cub[2][4]))
                {
                    // do the algo
                    // back-> saða parçayý koyma algoritmasý
                    cout << "U L U' L' U' B' U B" << endl;
                    MoveU(cub);
                    MoveL(cub);
                    reverseMoveU(cub);
                    reverseMoveL(cub);
                    reverseMoveU(cub);
                    reverseMoveB(cub);
                    MoveU(cub);
                    MoveB(cub);
                    moves = moves + "U L U' L' U' B' U B ";
                }

                else
                {
                    cout << "Error: 1474 you shouldn't be here!" << endl;
                }
            }
        }

    }

    cout << endl;
    cout << "Second Layer Solved!" << endl;
    cout << "---------------------------------" << endl;
}

void solveYellowCross(char cub[6][9], string& moves)
{

    int yellowCount = 0;

    if (cub[1][1] == 'Y')
    {
        yellowCount++;
    }
    if (cub[1][3] == 'Y')
    {
        yellowCount++;
    }
    if (cub[1][5] == 'Y')
    {
        yellowCount++;
    }
    if (cub[1][7] == 'Y')
    {
        yellowCount++;
    }

    if (yellowCount == 4)
    {
        cout << endl;
        cout << "Yellow Cross Already Solved!" << endl;
        cout << "---------------------------------" << endl;
        return;
    }

    if (yellowCount < 2)
    {
        cout << "F U R U' R' F'" << endl;
        MoveF(cub);
        MoveU(cub);
        MoveR(cub);
        reverseMoveU(cub);
        reverseMoveR(cub);
        reverseMoveF(cub);
        moves = moves + "F U R U' R' F' ";
    }

    if (cub[1][3] == 'Y' && cub[1][5] == 'Y')
    {
        cout << "F R U R' U' F'" << endl;
        MoveF(cub);
        MoveR(cub);
        MoveU(cub);
        reverseMoveR(cub);
        reverseMoveU(cub);
        reverseMoveF(cub);
        cout << endl;
        cout << "Yellow Cross Solved!" << endl;
        cout << "---------------------------------" << endl;
        moves = moves + "F R U R' U' F' ";
        return;

    }
    if (cub[1][1] == 'Y' && cub[1][7] == 'Y')
    {
        cout << "U F R U R' U' F'" << endl;
        MoveU(cub);
        MoveF(cub);
        MoveR(cub);
        MoveU(cub);
        reverseMoveR(cub);
        reverseMoveU(cub);
        reverseMoveF(cub);
        cout << endl;
        cout << "Yellow Cross Solved!" << endl;
        cout << "---------------------------------" << endl;
        moves = moves + "U F R U R' U' F' ";
        return;

    }
    if (cub[1][1] == 'Y' && cub[1][3] == 'Y')
    {
        cout << "F U R U' R' F'" << endl;
        MoveF(cub);
        MoveU(cub);
        MoveR(cub);
        reverseMoveU(cub);
        reverseMoveR(cub);
        reverseMoveF(cub);
        cout << endl;
        cout << "Yellow Cross Solved!" << endl;
        cout << "---------------------------------" << endl;
        moves = moves + "F U R U' R' F' ";
        return;
    }
    if (cub[1][1] == 'Y' && cub[1][5] == 'Y')
    {
        cout << "U' F U R U' R' F'" << endl;
        reverseMoveU(cub);
        MoveF(cub);
        MoveU(cub);
        MoveR(cub);
        reverseMoveU(cub);
        reverseMoveR(cub);
        reverseMoveF(cub);
        cout << endl;
        cout << "Yellow Cross Solved!" << endl;
        cout << "---------------------------------" << endl;
        moves = moves + "U' F U R U' R' F' ";
        return;
    }
    if (cub[1][3] == 'Y' && cub[1][7] == 'Y')
    {
        cout << "U F U R U' R' F'" << endl;
        MoveU(cub);
        MoveF(cub);
        MoveU(cub);
        MoveR(cub);
        reverseMoveU(cub);
        reverseMoveR(cub);
        reverseMoveF(cub);
        cout << endl;
        cout << "Yellow Cross Solved!" << endl;
        cout << "---------------------------------" << endl;
        moves = moves + "U F U R U' R' F' ";
        return;
    }
    if (cub[1][5] == 'Y' && cub[1][7] == 'W')
    {
        // do F  U  R  U'  R'  F' from back
        cout << "B U L U' L' B'" << endl;
        MoveB(cub);
        MoveU(cub);
        MoveL(cub);
        reverseMoveU(cub);
        reverseMoveL(cub);
        reverseMoveB(cub);
        cout << endl;
        cout << "Yellow Cross Solved!" << endl;
        cout << "---------------------------------" << endl;
        moves = moves + "B U L U' L' B' ";
        return;
    }

    cout << "U U F U R U' R' F'" << endl;
    MoveU(cub);
    MoveU(cub);
    MoveF(cub);
    MoveU(cub);
    MoveR(cub);
    reverseMoveU(cub);
    reverseMoveR(cub);
    reverseMoveF(cub);
    cout << endl;
    cout << "Yellow Cross Solved!" << endl;
    cout << "---------------------------------" << endl;
    moves = moves + "U U F U R U' R' F' ";
    return;
}

void solveYellowFace(char cub[6][9], string& moves)
{
    int yellCount = 0;
    if (cub[1][0] == 'Y')
    {
        yellCount++;
    }
    if (cub[1][2] == 'Y')
    {
        yellCount++;
    }
    if (cub[1][6] == 'Y')
    {
        yellCount++;
    }
    if (cub[1][8] == 'Y')
    {
        yellCount++;
    }
    while (yellCount != 4)
    {
        if (yellCount == 2)
        {
            if (cub[2][2] != 'Y')
            {
                if (cub[3][2] == 'Y')
                {
                    cout << "U ";
                    MoveU(cub);
                    moves = moves + "U ";
                }
                else if (cub[5][2] == 'Y')
                {
                    cout << "U' ";
                    moves = moves + "U' ";
                    reverseMoveU(cub);
                }
                else
                {
                    cout << "U U ";
                    MoveU(cub);
                    MoveU(cub);
                    moves = moves + "U U ";
                }
            }
            cout << "R U R' U R U U R'" << endl;
            MoveR(cub);
            MoveU(cub);
            reverseMoveR(cub);
            MoveU(cub);
            MoveR(cub);
            MoveU(cub);
            MoveU(cub);
            reverseMoveR(cub);
            moves = moves + "R U R' U R U U R'";
            yellCount = 0;

        }

        if (yellCount == 1)
        {
            if (cub[1][6] != 'Y')
            {
                if (cub[1][0] == 'Y')
                {
                    reverseMoveU(cub);
                    cout << "U' ";
                    moves = moves + "U' ";

                }
                else if (cub[1][8] == 'Y')
                {
                    MoveU(cub);
                    cout << "U ";
                    moves = moves + "U ";
                }
                else
                {
                    MoveU(cub);
                    MoveU(cub);
                    cout << "U U ";
                    moves = moves + "U U ";
                }
            }
            cout << "R U R' U R U U R'" << endl;
            MoveR(cub);
            MoveU(cub);
            reverseMoveR(cub);
            MoveU(cub);
            MoveR(cub);
            MoveU(cub);
            MoveU(cub);
            reverseMoveR(cub);
            moves = moves + "R U R' U R U U R' ";
        }

        if (yellCount == 0)
        {
            if (cub[2][2] != 'Y')
            {
                if (cub[3][2] == 'Y')
                {
                    cout << "U ";
                    MoveU(cub);
                    moves = moves + "U ";
                }
                else if (cub[5][2] == 'Y')
                {
                    cout << "U' ";
                    reverseMoveU(cub);
                    moves = moves + "U' ";
                }
                else
                {
                    cout << "U U ";
                    MoveU(cub);
                    MoveU(cub);
                    moves = moves + "U U ";
                }
            }
            cout << "R U R' U R U U R'" << endl;
            MoveR(cub);
            MoveU(cub);
            reverseMoveR(cub);
            MoveU(cub);
            MoveR(cub);
            MoveU(cub);
            MoveU(cub);
            reverseMoveR(cub);
            moves = moves + "R U R' U R U U R' ";
        }

        yellCount = 0;

        if (cub[1][0] == 'Y')
        {
            yellCount++;
        }
        if (cub[1][2] == 'Y')
        {
            yellCount++;
        }
        if (cub[1][6] == 'Y')
        {
            yellCount++;
        }
        if (cub[1][8] == 'Y')
        {
            yellCount++;
        }
    }

    cout << endl;
    cout << "Yellow face solved!" << endl;
    cout << "---------------------------------" << endl;
}

void solveYellowCorners(char cub[6][9], string& moves)
{
    int count = 0;
    if (cub[2][0] == cub[2][4])
    {
        count++;
    }
    if (cub[2][2] == cub[2][4])
    {
        count++;
    }
    if (cub[4][0] == cub[4][4])
    {
        count++;
    }
    if (cub[4][2] == cub[4][4])
    {
        count++;
    }
    while (count != 4)
    {
        if (count >= 2)
        {
            // solve using algos
            // check front back left right for near 2 correct blocks
            // reverse front and back
            // reverse left and right
            if (cub[3][0] == cub[3][4] && cub[3][2] == cub[3][4])
            {
                cout << "L' B L' F F L B' L' F F L L U'";
                reverseMoveL(cub);
                MoveB(cub);
                reverseMoveL(cub);
                MoveF(cub);
                MoveF(cub);
                MoveL(cub);
                reverseMoveB(cub);
                reverseMoveL(cub);
                MoveF(cub);
                MoveF(cub);
                MoveL(cub);
                MoveL(cub);
                reverseMoveU(cub);
                moves = moves + "L' B L' F F L B' L' F F L L U' ";
            }
            else if (cub[5][0] == cub[5][4] && cub[5][2] == cub[5][4])
            {
                cout << "R' F R' B B R F' R' B B R R U'";
                reverseMoveR(cub);
                MoveF(cub);
                reverseMoveR(cub);
                MoveB(cub);
                MoveB(cub);
                MoveR(cub);
                reverseMoveF(cub);
                reverseMoveR(cub);
                MoveB(cub);
                MoveB(cub);
                MoveR(cub);
                MoveR(cub);
                reverseMoveU(cub);
                moves = moves + "R' F R' B B R F' R' B B R R U' ";
            }
            else if (cub[2][0] == cub[2][4] && cub[2][2] == cub[2][4])
            {
                cout << "B' R B' L L B R' B' L L B B U'";
                reverseMoveB(cub);
                MoveR(cub);
                reverseMoveB(cub);
                MoveL(cub);
                MoveL(cub);
                MoveB(cub);
                reverseMoveR(cub);
                reverseMoveB(cub);
                MoveL(cub);
                MoveL(cub);
                MoveB(cub);
                MoveB(cub);
                reverseMoveU(cub);
                moves = moves + "B' R B' L L B R' B' L L B B U' ";
            }
            else if (cub[4][0] == cub[4][4] && cub[4][2] == cub[4][4])
            {
                cout << "F' L F' R R F L' F' R R F F U'";
                reverseMoveF(cub);
                MoveL(cub);
                reverseMoveF(cub);
                MoveR(cub);
                MoveR(cub);
                MoveF(cub);
                reverseMoveL(cub);
                reverseMoveF(cub);
                MoveR(cub);
                MoveR(cub);
                MoveF(cub);
                MoveF(cub);
                reverseMoveU(cub);
                moves = moves + "F' L F' R R F L' F' R R F F U' ";
            }
            // we should check for diagnols after near blocks
            else if ((cub[3][0] == cub[3][4] && cub[5][0] == cub[5][4]) ||
                (cub[3][2] == cub[3][4] && cub[5][2] == cub[5][4]))
            {
                cout << "R' F R' B B R F' R' B B R R U'";
                reverseMoveR(cub);
                MoveF(cub);
                reverseMoveR(cub);
                MoveB(cub);
                MoveB(cub);
                MoveR(cub);
                reverseMoveF(cub);
                reverseMoveR(cub);
                MoveB(cub);
                MoveB(cub);
                MoveR(cub);
                MoveR(cub);
                reverseMoveU(cub);
                moves = moves + "R' F R' B B R F' R' B B R R U' ";
            }
            else if ((cub[2][0] == cub[2][4] && cub[4][0] == cub[4][4]) ||
                (cub[2][2] == cub[2][4] && cub[4][2] == cub[4][4]))
            {
                cout << "F' L F' R R F L' F' R R F F U'";
                reverseMoveF(cub);
                MoveL(cub);
                reverseMoveF(cub);
                MoveR(cub);
                MoveR(cub);
                MoveF(cub);
                reverseMoveL(cub);
                reverseMoveF(cub);
                MoveR(cub);
                MoveR(cub);
                MoveF(cub);
                MoveF(cub);
                reverseMoveU(cub);
                moves = moves + "F' L F' R R F L' F' R R F F U' ";
            }
            else
            {
                cout << "ERROR: YOU SHOULDN'T BE HERE!" << endl;
            }
        }
        else
        {
            MoveU(cub);
            count = 0;
            if (cub[2][0] == cub[2][4])
            {
                count++;
            }
            if (cub[2][2] == cub[2][4])
            {
                count++;
            }
            if (cub[4][0] == cub[4][4])
            {
                count++;
            }
            if (cub[4][2] == cub[4][4])
            {
                count++;
            }
            if (count >= 2)
            {
                cout << "U ";
                moves = moves + "U ";
                continue;
            }
            MoveU(cub);
            count = 0;
            if (cub[2][0] == cub[2][4])
            {
                count++;
            }
            if (cub[2][2] == cub[2][4])
            {
                count++;
            }
            if (cub[4][0] == cub[4][4])
            {
                count++;
            }
            if (cub[4][2] == cub[4][4])
            {
                count++;
            }
            if (count >= 2)
            {
                cout << "U U ";
                moves = moves + "U U ";
                continue;
            }
            MoveU(cub);
            count = 0;
            if (cub[2][0] == cub[2][4])
            {
                count++;
            }
            if (cub[2][2] == cub[2][4])
            {
                count++;
            }
            if (cub[4][0] == cub[4][4])
            {
                count++;
            }
            if (cub[4][2] == cub[4][4])
            {
                count++;
            }
            if (count >= 2)
            {
                cout << "U' ";
                moves = moves + "U' ";
                continue;
            }
            cout << "Line 775 You shouldn't be here" << endl;
        }
        count = 0;
        if (cub[2][0] == cub[2][4])
        {
            count++;
        }
        if (cub[2][2] == cub[2][4])
        {
            count++;
        }
        if (cub[4][0] == cub[4][4])
        {
            count++;
        }
        if (cub[4][2] == cub[4][4])
        {
            count++;
        }
    }
    cout << endl;
    cout << endl;
    cout << "Third Layer's Corners are solved !" << endl;
    cout << "---------------------------------" << endl;
}

void solveYellowEdges(char cub[6][9], string& moves)
{
    // check if its already solved
    // if not solved :
    // we should decide which direction to move
    // 
    if (cub[3][1] == cub[3][4] && cub[2][1] == cub[2][4]
        && cub[4][1] == cub[4][4] && cub[5][1] == cub[5][4])
    {
        cout << "Cube is solved !" << endl;
        return;
    }
    int correctEdgeCount = 0;
    if (cub[3][1] == cub[3][4])
    {
        correctEdgeCount++;
    }
    if (cub[2][1] == cub[2][4])
    {
        correctEdgeCount++;
    }
    if (cub[4][1] == cub[4][4])
    {
        correctEdgeCount++;
    }
    if (cub[5][1] == cub[5][4])
    {
        correctEdgeCount++;
    }
    while (correctEdgeCount != 4)
    {
        if (cub[3][1] == cub[3][4])
        {
            // doing the algo from behind
            // if clockwise
            // B B U R L' B B R' L U B B
            // 
            // if counter clockwise
            // B B U' R L' B B R' L U' B B

            if (cub[2][1] == cub[5][4])
            {
                cout << "B B U R L' B B R' L U B B";
                MoveB(cub);
                MoveB(cub);
                MoveU(cub);
                MoveR(cub);
                reverseMoveL(cub);
                MoveB(cub);
                MoveB(cub);
                reverseMoveR(cub);
                MoveL(cub);
                MoveU(cub);
                MoveB(cub);
                MoveB(cub);
                moves = moves + "B B U R L' B B R' L U B B ";
            }
            else
            {
                cout << "B B U' R L' B B R' L U' B B";
                MoveB(cub);
                MoveB(cub);
                reverseMoveU(cub);
                MoveR(cub);
                reverseMoveL(cub);
                MoveB(cub);
                MoveB(cub);
                reverseMoveR(cub);
                MoveL(cub);
                reverseMoveU(cub);
                MoveB(cub);
                reverseMoveB(cub);
                moves = moves + "B B U' R L' B B R' L U' B B ";
            }

        }
        else if (cub[5][1] == cub[5][4])
        {
            // if clockwise
            // F F U L R' F F L' R U F F
            // 
            // if counter clockwise
            // F F U' L R' F F L' R U' F F

            if (cub[3][4] == cub[4][1]) // do clockwise
            {
                cout << "F F U L R' F F L' R U F F";
                MoveF(cub);
                MoveF(cub);
                MoveU(cub);
                MoveL(cub);
                reverseMoveR(cub);
                MoveF(cub);
                MoveF(cub);
                reverseMoveL(cub);
                MoveR(cub);
                MoveU(cub);
                MoveF(cub);
                MoveF(cub);
                moves = moves + "F F U L R' F F L' R U F F ";

            }
            else
            {
                cout << "F F U' L R' F F L' R U' F F";
                MoveF(cub);
                MoveF(cub);
                reverseMoveU(cub);
                MoveL(cub);
                reverseMoveR(cub);
                MoveF(cub);
                MoveF(cub);
                reverseMoveL(cub);
                MoveR(cub);
                reverseMoveU(cub);
                MoveF(cub);
                MoveF(cub);
                moves = moves + "F F U' L R' F F L' R U' F F ";
            }
        }
        else if (cub[2][1] == cub[2][4])
        {
            // if clockwise
            // R R U F B' R R F' B U R R
            // 
            // if counter clockwise
            // R R U' F B' R R F' B U' R R

            if (cub[4][1] == cub[3][4])
            {
                cout << "R R U F B' R R F' B U R R";
                MoveR(cub);
                MoveR(cub);
                MoveU(cub);
                MoveF(cub);
                reverseMoveB(cub);
                MoveR(cub);
                MoveR(cub);
                reverseMoveF(cub);
                MoveB(cub);
                MoveU(cub);
                MoveR(cub);
                MoveR(cub);
                moves = moves + "R R U F B' R R F' B U R R ";
            }
            else
            {
                cout << "R R U' F B' R R F' B U' R R";
                MoveR(cub);
                MoveR(cub);
                reverseMoveU(cub);
                MoveF(cub);
                reverseMoveB(cub);
                MoveR(cub);
                MoveR(cub);
                reverseMoveF(cub);
                MoveB(cub);
                reverseMoveU(cub);
                MoveR(cub);
                MoveR(cub);
                moves = moves + "R R U' F B' R R F' B U' R R ";
            }
        }
        else if (cub[4][1] == cub[4][4])
        {
            // if clockwise
            // L L U B F' L L B' F U L L
            // if counter clockwise
            // L L U' B F' L L B' F U' L L

            if (cub[3][1] == cub[2][4])
            {
                cout << "L L U B F' L L B' F U L L";
                MoveL(cub);
                MoveL(cub);
                MoveU(cub);
                MoveB(cub);
                reverseMoveF(cub);
                MoveL(cub);
                MoveL(cub);
                reverseMoveB(cub);
                MoveF(cub);
                MoveU(cub);
                MoveL(cub);
                MoveL(cub);
                moves = moves + "L L U B F' L L B' F U L L ";

            }
            else
            {
                cout << "L L U' B F' L L B' F U' L L";
                MoveL(cub);
                MoveL(cub);
                reverseMoveU(cub);
                MoveB(cub);
                reverseMoveF(cub);
                MoveL(cub);
                MoveL(cub);
                reverseMoveB(cub);
                MoveF(cub);
                reverseMoveU(cub);
                MoveL(cub);
                MoveL(cub);
                moves = moves + "L L U' B F' L L B' F U' L L ";
            }
        }
        else
        {
            // doesnt matter if you do clockwise or counter clockwise
            cout << "F F U L R' F F L' R U F F";
            MoveF(cub);
            MoveF(cub);
            MoveU(cub);
            MoveL(cub);
            reverseMoveR(cub);
            MoveF(cub);
            MoveF(cub);
            reverseMoveL(cub);
            MoveR(cub);
            MoveU(cub);
            MoveF(cub);
            MoveF(cub);
            moves = moves + "F F U L R' F F L' R U F F ";
        }
        correctEdgeCount = 0;
        if (cub[3][1] == cub[3][4])
        {
            correctEdgeCount++;
        }
        if (cub[2][1] == cub[2][4])
        {
            correctEdgeCount++;
        }
        if (cub[4][1] == cub[4][4])
        {
            correctEdgeCount++;
        }
        if (cub[5][1] == cub[5][4])
        {
            correctEdgeCount++;
        }
    }
    cout << endl;
    cout << endl;
    cout << "Cube is Solved!";
    cout << endl;

}


string procesareMiscari(const string& miscari)
{
    string rezultat;
    for (int i = 0; i < miscari.length(); i++)
    {
        if (miscari[i] == ' ') continue;
        if (i + 1 < miscari.length() && miscari[i + 1] == '\'')
        {
            switch (miscari[i])
            {
            case 'U': rezultat += '8'; break;
            case 'R': rezultat += '6'; break;
            case 'L': rezultat += '4'; break;
            case 'D': rezultat += '2'; break;
            case 'F': rezultat += '5'; break;
            case 'B': rezultat += '7'; break;
            default: rezultat += miscari[i]; break;
            }
            i++;
        }
        else {
            rezultat += miscari[i];
        }
    }
    return rezultat;
}

string optimizeSolution(const string& moves)
{
    string optimized;

    for (char move : moves)
    {
        if (!optimized.empty())
        {
            char lastMove = optimized.back();


            if ((lastMove == 'R' && move == '6') || (lastMove == '6' && move == 'R') ||
                (lastMove == 'L' && move == '4') || (lastMove == '4' && move == 'L') ||
                (lastMove == 'U' && move == '8') || (lastMove == '8' && move == 'U') ||
                (lastMove == 'D' && move == '2') || (lastMove == '2' && move == 'D') ||
                (lastMove == 'F' && move == '5') || (lastMove == '5' && move == 'F') ||
                (lastMove == 'B' && move == '7') || (lastMove == '7' && move == 'B')) {
                optimized.pop_back();
                continue;
            }
        }

        optimized.push_back(move);
    }

    return optimized;
}

int main() {


    ifstream fisier("/home/pit77olt/Desktop/Rubiks/Cod/Initial_config_reader/initial_config.txt");
    string configuratie;

    if (fisier.is_open()) {
        getline(fisier, configuratie); // citește prima linie
        fisier.close();
    }
    else {
        cout << "Nu pot deschide fisierul";
    }

    cout << "Configuratie citita: " << configuratie << endl;

 
    getPainted(configuratie);




    solveWhiteCross(cub, final_moves);

    solveWhiteFace(cub, final_moves);

    solveSecondLayer(cub, final_moves);

    solveYellowCross(cub, final_moves);

    solveYellowFace(cub, final_moves);

    solveYellowCorners(cub, final_moves);

    solveYellowEdges(cub, final_moves);


    PrintCubev2(cub);



    cout << "Rezolvare finala:" << endl;
    string solutie_procesata = procesareMiscari(final_moves);  //schimbare caractere pt citire mai usoara ulterior de catre motoare
    string solutie_optimizata = optimizeSolution(solutie_procesata);  //verifica potentiale optimizari 
    cout << solutie_optimizata << endl;
    cout << "Numar total de miscari: " << howManyMoves(solutie_optimizata);
    cout << endl;



    ofstream out("solutie_gen.txt");  // poți pune și calea completă dacă vrei
    if (out.is_open()) {
        out << solutie_optimizata;
        out.close();
        cout << "solution saved\n";
    }
    else {
        cout<< "eroare\n";
        return 1;
    }

    return 0;
}
