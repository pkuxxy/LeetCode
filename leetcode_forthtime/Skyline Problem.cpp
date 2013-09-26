#include<iostream>
#include<vector>
#include<string>
#include<string.h>
//#include<queue>
using namespace std;
struct Strip
{
	int x;
	int h;
	Strip(int x, int h)
	{
		this->x = x;
		this->h = h;
	}
};
struct Block
{
	int lx;
	int rx;
	int h;
	Block(int l, int h, int r)
	{
		lx = l;
		rx = r;
		this->h = h;
	}
};
vector<Strip> mergeSkyline(vector<Strip>& s1, vector<Strip>& s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int i = 0;
	int j = 0;
	int curh1 = 0;
	int curh2 = 0;
	vector<Strip> ret;
	while(i < len1 && j < len2)
	{
		if(s1[i].x < s2[j].x)
		{
			int h = max(s1[i].h, curh2);
			ret.push_back(Strip(s1[i].x, h));
			curh1 = s1[i].h;
			i++;
		}
		else if(s1[i].x > s2[j].x)
		{
			int h = max(s2[j].h, curh1);
			ret.push_back(Strip(s2[j].x, h));
			curh2 = s2[j].h;
			j++;
		}
		else
		{
			int h = max(s1[i].h, s2[j].h);
			ret.push_back(Strip(s1[i].x, h));
			curh1 = s1[i].h;
			curh2 = s2[j].h;
			i++;
			j++;
		}
	}
	while(i < s1.size())
	{
		ret.push_back(Strip(s1[i].x, s1[i].h));
		i++;
	}
	while(j < s2.size())
	{
		ret.push_back(Strip(s2[j].x, s2[j].h));
		j++;
	}
	vector<Strip>::iterator iter = ret.begin()+1;
	while(iter != ret.end())
	{
		if(iter->h == (iter-1)->h)
			iter = ret.erase(iter);
		else
			iter++;
	}
	return ret;
}
vector<Strip> findSkyline(vector<Block>& b, int l, int r)
{
	if(l == r)
	{
		vector<Strip> ret;
		ret.push_back(Strip(b[l].lx, b[l].h));
		ret.push_back(Strip(b[l].rx, 0));
		return ret;
	}
	int mid = l+(r-l)/2;
	vector<Strip> s1 = findSkyline(b, l, mid);
	vector<Strip> s2 = findSkyline(b, mid+1, r);
	return mergeSkyline(s1, s2);
}
int main()
{
	vector<Block> b;
	b.push_back(Block(1,11,5));
	b.push_back(Block(2,6,7));
	b.push_back(Block(3,13,9));
	b.push_back(Block(12,7,16));
	b.push_back(Block(14,3,25));
	b.push_back(Block(19,18,22));
	//priority_queue<int, vector<int>, less<int>> q;
	vector<Strip> skyline = findSkyline(b, 0, b.size()-1);
	for(int i = 0; i < skyline.size(); i++)
	{
		cout<<skyline[i].x<<" "<<skyline[i].h<<" ";
	}
	getchar();
}