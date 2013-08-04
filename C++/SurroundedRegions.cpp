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
	Point(){}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
Point path[4];
void init()
{
	path[0] = Point(0,-1);
	path[1] = Point(0,1);
	path[2] = Point(1,0);
	path[3] = Point(-1,0);
}
class Solution {
public:
	void solve(vector<vector<char>> &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		init();
		int len1 = board.size();
		if(!len1)
			return;
		int len2 = board[0].size();
		queue<Point> q;
		for(int i = 0; i < len1; i++)
		{
			if(board[i][0] == 'O')
			{
				board[i][0] = 'D';
				q.push(Point(i,0));
			}
			if(board[i][len2-1] == 'O')
			{
				board[i][len2-1] = 'D';
				q.push(Point(i,len2-1));
			}
		}
		for(int i = 0; i < len2; i++)
		{
			if(board[0][i] == 'O')
			{
				board[0][i] = 'D';
				q.push(Point(0,i));
			}
			if(board[len1-1][i] == 'O')
			{
				board[len1-1][i] = 'D';
				q.push(Point(len1-1,i));
			}
		}
		while(!q.empty())
		{
			Point p = q.front();
			q.pop();
			for(int i = 0; i < 4; i++)
			{
				int x = p.x + path[i].x;
				int y = p.y + path[i].y;
				if(x < 0 || x >= len1 || y < 0 || y >= len2 || board[x][y] != 'O')
					continue;
				board[x][y] = 'D';
				q.push(Point(x,y));
			}
		}
		for(int i = 0; i < len1; i++)
		{
			for(int j = 0; j < len2; j++)
			{
				if(board[i][j] == 'X')
					continue;
				board[i][j] = (board[i][j] == 'O' ? 'X':'O');
			}
		}
	}
};