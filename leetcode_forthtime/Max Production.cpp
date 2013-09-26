#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
int getMaxPro(int n)
{
	if(n <= 1)
		return n;
	vector<int> dp(n+1, 0);
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		dp[i] = i;
		for(int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], j*dp[i-j]);
		}
	}
	return dp[n];
}
int main()
{
	cout<<getMaxPro(8)<<endl;
	getchar();
}