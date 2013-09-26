#include<iostream>
#include<vector>
#include<string>
#include<string.h>
//#include<queue>
using namespace std;
string getMatch(int n)
{
	if(n <= 0)
		return "";
	int size = 1<<n;
	vector<string> vec(size);
	char tmp[15];
	for(int i = 0; i < size; i++)
	{
		vec[i] = itoa(i+1, tmp, 10);
	}
	while(n--)
	{
		int begin = 0;
		int end = size-1;
		while(begin < end)
		{
			vec[begin] = "(" + vec[begin] + ", " + vec[end] + ")";
			vec.pop_back();
			begin++;
			end--;
		}
		size /= 2;
	}
	return vec[0];
}
int main()
{
	cout<<getMatch(3)<<endl;
	//priority_queue<int, vector<int>, less<int>> q;
	getchar();
}