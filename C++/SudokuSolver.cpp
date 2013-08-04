#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
	// 返回第一个空白的位置，如果没找到就返回 (-1, -1)
	pair<int, int> findFirstEmpty(const vector< vector<char> >& board) 
	{
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (board[i][j] == '.') return make_pair(i, j);
		return make_pair(-1, -1);
	}

	// 检查连续的 9 个格子是否有效
	bool isValid(const vector< vector<char> >& board, int topX, int topY, int botX, int botY) 
	{
		vector<bool> occur(9, false);
		for (int row = topX; row <= botX; row++)
		{
			for (int col = topY; col <= botY; col++)
			{
				if ( isdigit(board[row][col]) )
				{
					if (occur[board[row][col]-'1']) return false;
					else occur[board[row][col]-'1'] = true;
				}
			}
		}
		return true;
	}

	// 检查往某个位置填入一个数之后整个 board 是否有效（只需要考虑当前行、
	// 当前列和所属的田字格）
	bool isValidBoard(const vector< vector<char> >& board, pair<int, int> pos) 
	{
		// 检查当前行是否有效
		if (!isValid(board, pos.first, 0, pos.first, 8)) return false;
		// 检查当前列是否有效
		if (!isValid(board, 0, pos.second, 8, pos.second)) return false;
		// 检查所在的田字格是否有效
		int blockRow, blockCol;
		for (blockRow = 0; blockRow < 3; ++blockRow)
		{
			bool flag = false;
			for (blockCol = 0; blockCol < 3; ++blockCol)
			{
				if (blockRow*3 <= pos.first && pos.first <= blockRow*3+2
					&& blockCol*3 <= pos.second && pos.second <= blockCol*3+2)
				{
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if (!isValid(board, blockRow*3, blockCol*3, blockRow*3+2, blockCol*3+2)) return false;
		// 如果以上都有效，则返回 true
		return true;
	}

	// 检查从当前局面开始是否能够得到最终合法有效的解
	bool solveSudoku(vector<vector<char> >& board) 
	{
		// 如果没有找到空白的格子，说明已经填满了，成功返回
		pair<int, int> pos = findFirstEmpty(board);
		if (pos.first == -1 && pos.second == -1)
			return true;
		// 否则依次尝试往当前格子中填入数字 1-9，并判断能否得到可行的解
		for (int i = 1; i <= 9; ++i) 
		{
			board[pos.first][pos.second] = i + '0';
			if (isValidBoard(board, pos) && solveSudoku(board))
				return true;
			// 恢复原样
			board[pos.first][pos.second] = '.';
		}
		return false;
	}
};