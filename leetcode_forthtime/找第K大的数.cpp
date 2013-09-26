#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int getKthNum(vector<int>& num, int s, int e, int k)
{
	if(s > e || k-1 > e || k < 0)
		return INT_MIN;
	int tmp = num[s];
	int i = s;
	int j = e;
	while(i < j)
	{
		while(i < j && num[j] >= tmp)
			j--;
		if(i < j)
			num[i] = num[j];
		while(i < j && num[i] < tmp)
			i++;
		if(i < j)
			num[j] = num[i];
	}
	num[i] = tmp;
	if(i == k-1)
		return k;
	else if(i < k-1)
		return getKthNum(num, s+i+1, e, k);
	else
		return getKthNum(num, s, i-1, k);
}
int main() {
	int a[]={4,6,1,2,3,9,8,7,5,10};
	vector<int> num(a, a+10);
	cout<<getKthNum(num, 0, 9, 5);
	getchar();
	return 0;
}