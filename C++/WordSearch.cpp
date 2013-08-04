#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Point
{
public:
	int x;
	int y;
	Point(){};
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
static Point direct[4]; 
class Solution {
public:
	void init()
	{
		direct[0] = Point(0, -1);
		direct[1] = Point(0, 1);
		direct[2] = Point(-1, 0);
		direct[3] = Point(1, 0);
	}
	bool find(int index, Point p, vector<vector<char> > &board, int len1, int len2, string word, int len, vector<vector<bool> > &used)
	{
		if(index == len)
			return true;
		if(p.x < 0 || p.y < 0 || p.x >= len1 || p.y >= len2 || used[p.x][p.y] || board[p.x][p.y] != word[index])
			return false;
		used[p.x][p.y] = true;
		for(int i = 0; i < 4; i++)
		{

			if(find(index+1, Point(p.x + direct[i].x, p.y+direct[i].y), board, len1, len2, word, len, used))
				return true;

		}
		used[p.x][p.y] = false;
		return false;
	}
	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = word.size();
		if(!len)
			return true;
		int len1 = board.size();
		if(!len1)
			return false;
		int len2 = board[0].size();
		init();
		vector<vector<bool>> used(len1);
		for(int i = 0; i < len1; i++)
		{
			used[i] = vector<bool>(len2, false);
		}
		//vector<Point> ps;
		for(int i = 0; i < len1; i++)
		{
			for(int j = 0; j < len2; j++)
			{
				if(find(0, Point(i, j), board, len1, len2, word, len, used))
					return true;
				/*if(board[i][j] == word[0])
				ps.push_back(Point(i, j));*/
			}
		}
		return false;

	}
};
int main()
{
	vector<vector<char> > board(1);
	board[0].push_back('a');
	string word = "a";
	Solution sol;
	cout<<sol.exist(board,word);
	getchar();
}