#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
int getTwo(vector<int>& num)
{
	int ones = 0;
	int twos = 0;
	int not3 = 0;
	for(int i = 0; i < num.size(); i++)
	{
		twos |= ones&num[i];
		ones ^= num[i];
		not3 = ~(ones & twos);
		ones &= not3;
		twos &= not3;
	}
	return twos;
}
int main(int argc, char *argv[], char *env[]) 
{ 
	int a[] = {1,2,1,2,1};
	vector<int> num(a, a+5);
	cout<<getTwo(num)<<endl;
	getchar();
} 