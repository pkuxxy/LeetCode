#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
	vector<vector<string> > ret;
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
			vector<string> sol;
			for(int i = 0; i < n; i++)
			{
				string row(n,'.');
				row[board[i]] = 'Q';
				sol.push_back(row);
			}
			ret.push_back(sol);
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
    vector<vector<string> > solveNQueens(int n) {
		ret.clear();
        if(!n)
			return ret;
		vector<int> board(n,0);
		place(0, n, board);
		return ret;
    }
};
int main()
{
	int n = 1;
	Solution sol;
	sol.solveNQueens(n);
	getchar();
}