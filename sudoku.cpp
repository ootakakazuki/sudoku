#include <bits/stdc++.h>
using namespace std;


int checkRow(vector<vector<char>>& board, char num, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return 0;
        }
    }
    return 1;
}
    
    
int checkCol(vector<vector<char>>& board, char num, int row)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == num)
            {
                return 0;
            }
        }
        return 1;
    }

    int checkBox(vector<vector<char>>& board, char num, int row, int col)
    {
        row = row - (row % 3);
        col = col - (col % 3);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[row + i][col + j] == num)
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    
    void    print(vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (col == 8) cout << board[row][col] << endl;
                else cout << board[row][col];
            }
        }
    }
    
    
    bool rec(vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.') continue;
                for (char num = '1'; num <= '9'; num++)
                {
                    if (checkRow(board, num, col) && checkCol(board, num, row) && checkBox(board, num, row, col))
                    {
                        board[row][col] = num;
                        if (rec(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                        
                    }
                }
                return false;
            }
        }
        return true;        
    }
    
    
    
    void sudoku(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        rec(board);
    }
    

int		main(void)
{

	vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	
	sudoku(board);
	print(board);
}

