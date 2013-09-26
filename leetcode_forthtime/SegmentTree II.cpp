// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <vector>
using namespace std;
struct SegmentTree
{
	int l;
	int r;
	int num;
};
vector<SegmentTree> st;
void build(vector<int>& nums, int l, int r, int p)
{
	st[p].l = l;
	st[p].r = r;
	if(l == r)
	{
		st[p].num = nums[l];
		return;
	}
	else
	{
		int mid = l + (r-l)/2;
		build(nums, l, mid, 2*p);
		build(nums, mid+1, r, 2*p+1);
	}
}
void add(int l, int r, int ll, int rr, int p, int target)
{
	if(l == r)
	{
		st[p].num += target;
	}
	else
	{
		int mid = l+(r-l)/2;
		if(rr <= mid)
			add(l, mid, ll, rr, 2*p, target);
		else if(ll > mid)
			add(mid+1, r, ll, rr, 2*p+1, target);
		else
		{
			add(l, mid, ll, mid, 2*p, target);
			add(mid+1, r, mid+1, rr, 2*p+1, target);
		}
	}
}
int getnum(int l, int r, int tp, int p)
{
	if(l == r)
	{
		return st[p].num;
	}
	int mid = l + (r-l)/2;
	if(tp <= mid)
	{
		return getnum(l, mid, tp, 2*p);
	}
	else if(tp > mid)
		return getnum(mid+1, r, tp, 2*p+1);
}
int main() {
    int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
	{
		cin>>nums[i];
	}
	st.resize(3*n);
	build(nums, 0, n-1, 1);
	int q, opcode, a, b, x;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		cin>>opcode;
		if(opcode == 1)
		{
			cin>>a>>b>>x;
			add(0, n-1, a-1, b-1, 1, x);
		}
		else
		{
			cin>>a;
			cout<<getnum(0, n-1, a-1, 1)<<endl;
		}
	}
    getchar();
    return 0;
}