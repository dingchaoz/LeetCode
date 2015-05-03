#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>> &);

int main()
{
    vector<char> row(9);
    vector<vector<char>> board(9);
    const int bRow = 9;
    const int bCol = 9;
    char b[9][9] = {{'.','.','4','.','.','.','6','3','.'},
                    {'.','.','.','.','.','.','.','.','.'},
                    {'5','.','.','.','.','.','.','9','.'},
                    {'.','.','.','5','6','.','.','.','.'},
                    {'4','.','3','.','.','.','.','.','1'},
                    {'.','.','.','7','.','.','.','.','.'},
                    {'.','.','.','5','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.'}};

    for (int i = 0; i < bRow; i++) {
        for (int j = 0; j < bCol; j++)
            row[j] = b[i][j];
        board[i] = row;
    }

    cout << isValidSudoku(board);

    return 0;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    char elem;
    int elemCountRow[10] = {0};
    int elemCountCol[10] = {0};
    // Check for Rows and Columns
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if ((elem = board[i][j]) != '.')
                if (++elemCountRow[elem-'1'] > 1)
                    return false;
            if ((elem = board[j][i]) != '.')
                if (++elemCountCol[elem-'1'] > 1)
                    return false;
        }
        for (int k = 0; k < 10; k++) {
            elemCountRow[k] = 0;
            elemCountCol[k] = 0;
        }
    }

    int elemCount[10] = {0};
    int i_ = 0, j_ = 0;
    // Check for Squares
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            i_ = j/3 + (i/3)*3;
            j_ = j%3 + (i%3)*3;
            if ((elem = board[i_][j_]) != '.')
                if (++elemCount[elem-'1'] > 1)
                    return false;
        }
        for (int k = 0; k < 10; k++)
            elemCount[k] = 0;
    }
    return true;
}
