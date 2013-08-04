#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
	// ���ص�һ���հ׵�λ�ã����û�ҵ��ͷ��� (-1, -1)
	pair<int, int> findFirstEmpty(const vector< vector<char> >& board) 
	{
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (board[i][j] == '.') return make_pair(i, j);
		return make_pair(-1, -1);
	}

	// ��������� 9 �������Ƿ���Ч
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

	// �����ĳ��λ������һ����֮������ board �Ƿ���Ч��ֻ��Ҫ���ǵ�ǰ�С�
	// ��ǰ�к����������ָ�
	bool isValidBoard(const vector< vector<char> >& board, pair<int, int> pos) 
	{
		// ��鵱ǰ���Ƿ���Ч
		if (!isValid(board, pos.first, 0, pos.first, 8)) return false;
		// ��鵱ǰ���Ƿ���Ч
		if (!isValid(board, 0, pos.second, 8, pos.second)) return false;
		// ������ڵ����ָ��Ƿ���Ч
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
		// ������϶���Ч���򷵻� true
		return true;
	}

	// ���ӵ�ǰ���濪ʼ�Ƿ��ܹ��õ����պϷ���Ч�Ľ�
	bool solveSudoku(vector<vector<char> >& board) 
	{
		// ���û���ҵ��հ׵ĸ��ӣ�˵���Ѿ������ˣ��ɹ�����
		pair<int, int> pos = findFirstEmpty(board);
		if (pos.first == -1 && pos.second == -1)
			return true;
		// �������γ�������ǰ�������������� 1-9�����ж��ܷ�õ����еĽ�
		for (int i = 1; i <= 9; ++i) 
		{
			board[pos.first][pos.second] = i + '0';
			if (isValidBoard(board, pos) && solveSudoku(board))
				return true;
			// �ָ�ԭ��
			board[pos.first][pos.second] = '.';
		}
		return false;
	}
};