#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		unordered_set<char> unique;
		for(int i = 0; i < board.size(); i++)
		{
			unique.clear();
			for(int j = 0; j < board[i].size(); j++)
			{
				if(board[i][j] == '.')
					continue;
				if(unique.find(board[i][j]) != unique.end())
					return false;
				unique.insert(board[i][j]);
			}
			unique.clear();
			for(int j = 0; j < board.size(); j++)
			{
				if(board[j][i] == '.')
					continue;
				if(unique.find(board[j][i]) != unique.end())
					return false;
				unique.insert(board[j][i]);
			}
			unique.clear();
			int row = i/3;
			int col = i%3;
			for(int j = row*3; j < row*3+3; j++)
			{
				for(int k = col*3; k < col*3+3; k++)
				{
					if(board[j][k] == '.')
						continue;
					if(unique.find(board[j][k]) != unique.end())
						return false;
					unique.insert(board[j][k]);
				}
			}
		}
		return true;
	}
};