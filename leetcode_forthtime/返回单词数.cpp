#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int getWords(string s)
{
	int len = s.size();
	if(!len)
		return 0;
	int count = 0;
	int begin = 0;
	for(int i = 0; i < len; i++)
	{
		if(s[i] == ' ')
		{
			if(i - begin > 0)
				count++;
			begin = i+1;
		}
	}
	return count;
}
int main()
{
	string s = " hello world   ";
	cout<<getWords(s)<<endl;
	getchar();
}