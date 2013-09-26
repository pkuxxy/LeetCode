#include<iostream>
#include<vector>
#include<string>
#include<string.h>
//#include<queue>
using namespace std;
void fixup(int a[], int i)	//插入后调整堆
{
	if(!a || i <= 0)
		return;
	int tmp = a[i];
	int j = (i-1)/2;
	while(j >= 0 && i != 0)	//i != 0是因为-1/2 = 0;
	{
		if(a[j] > tmp)
			break;
		a[i] = a[j];
		i = j;
		j = (i-1)/2;
	}
	a[i] = tmp;
}
void fixdown(int a[], int i, int n)
{
	if(!a || n <= 0 || i >= n)
		return;
	int tmp = a[i];
	int j = 2*i+1;
	while(j < n)
	{
		if(j+1 < n && a[j+1] > a[j])
			j++;
		if(a[j] < tmp)
			break;
		a[i] = a[j];
		i = j;
		j = 2*i+1;
	}
	a[i] = tmp;
}
void make_heap(int a[], int n)
{
	if(!a || n <= 0)
		return;
	for(int i = n/2-1; i >= 0; i--)
		fixdown(a, i, n);
}
void sort_heap(int a[], int n)
{
	make_heap(a, n);
	for(int i = n-1; i >= 1; i--)
	{
		swap(a[0],a[i]);
		fixdown(a, 0, i);
	}
}
int main()
{
	int a[]={2,4,8,9,5,1,6,7};
	vector<int> vec(a, a+8);
	//make_heap(a, 8);
	sort_heap(a, 8);
	for(int i = 0; i < 8; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<(-1/2)<<endl;
	//priority_queue<int, vector<int>, less<int>> q;
	getchar();
}