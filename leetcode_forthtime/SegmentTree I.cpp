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
	int sum;
};
vector<SegmentTree> st;
void build(vector<int>& nums, int l, int r, int p)
{
	st[p].l = l;
	st[p].r = r;
	if(r - l == 1)
	{
		st[p].sum = nums[l];
	}
	else
	{
		int mid = l + (r-l)/2;
		build(nums, l, mid, 2*p);
		build(nums, mid, r, 2*p+1);
		st[p].sum = st[2*p].sum + st[2*p+1].sum;
	}
}
void updatesum(int l, int r, int p)
{
	if(r-l <= 1)
		return;
	st[p].sum = st[2*p].sum + st[2*p+1].sum;
}
void add(int l, int r, int ll, int rr, int p, int target)
{
	if(l == ll && r == rr)
	{
		st[p].sum += target;
		return;
	}
	int mid = l + (r-l)/2;
	if(rr <= mid)
	{
		add(l, mid, ll, rr, p*2, target);
	}
	else if(ll >= mid)
		add(mid, r, ll, rr, p*2+1, target);
	else
	{
		add(l, mid, ll, mid, p*2, target);
		add(mid, r, mid, rr, p*2+1, target);
	}
	updatesum(l, r, p);
}
int getsum(int l, int r, int a, int b, int p)
{
	if((l == a && r == b) || r - l == 1)
		return st[p].sum;
	int mid = l + (r-l)/2;
	if(b <= mid)
		return getsum(l, mid, a, b, 2*p);
	else if(a >= mid)
		return getsum(mid, r, a, b, 2*p+1);
	else
		return getsum(l, mid, a, mid, 2*p)+getsum(mid, r, mid, b, 2*p+1);
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
	build(nums, 0, n, 1);
	int q, opcode, a, b;
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		cin>>opcode>>a>>b;
		if(opcode == 1)
		{
			add(0, n, a-1, a, 1, b);
		}
		else
		{
			cout<<getsum(0, n, a-1, b, 1)<<endl;
		}
	}
    getchar();
    return 0;
}