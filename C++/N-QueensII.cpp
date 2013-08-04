#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
	int count;
	bool isValid(int row, int col, vector<int>& board)
	{
		for(int i = 0; i < row; i++)
		{
			int data = board[i];
			if(data == col || (row+col) == (i+data) || (row-col) == (i-data))
				return false;
		}
		return true;
	}
	void place(int index,int n, vector<int>& board)
	{
		if(index == n)
		{
			count++;
			return;
		}
		for(int i = 0; i < n; i++)
		{
			if(isValid(index, i, board))
			{
				board[index] = i;
				place(index+1, n, board);
			}
		}
	}
	int totalNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		count = 0;
		if(!n)
			return count;
		vector<int> board(n,0);
		place(0, n, board);
		return count;
	}
};