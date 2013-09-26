#include<iostream>
#include<vector>
#include<string>
#include<string.h>
//#include<queue>
using namespace std;
vector<int> values;
vector<int> tag;
void pushup(int p)
{
	values[p] = values[p<<1] + values[p<<1|1];
}
void build(int l, int r, int p)
{
	tag[p] = 0;
	if(l == r)
	{
		values[p] = 1;
		return;
	}
	int mid = l+(r-l)/2;
	build(l, mid, p*2);
	build(mid+1, r, p*2+1);
	pushup(p);
}
void pushdown(int p, int len)
{
	if(tag[p])
	{
		tag[p<<1] = tag[p<<1|1] = tag[p];
		values[p<<1] = tag[p]*(len - (len>>1));
		values[p<<1|1] = tag[p]*(len>>1);
		tag[p] = 0;
	}
}
void update(int l, int r, int p, int ql, int qr, int target)
{
	if(l == ql && r == qr)
	{
		tag[p] = target;
		values[p] = target*(qr - ql + 1);
		return;
	}
	pushdown(p, r-l+1);
	int mid = l+(r-l)/2;
	if(qr <= mid)
		update(l, mid, p*2, ql, qr, target);
	else if(ql > mid)
		update(mid+1, r, p*2+1, ql, qr, target);
	else
	{
		update(l, mid, p*2, ql, mid, target);
		update(mid+1, r, p*2+1, mid+1, qr, target);
	}
	pushup(p);
}
int query(int l, int r, int p, int ql, int qr)
{
	if(l == ql && r == qr)
	{
		return values[p];
	}
	pushdown(p, r-l+1);
	int mid = l+(r-l)/2;
	if(qr <= mid)
		return query(l, mid, p<<1, ql, qr);
	else if(ql > mid)
		return query(mid+1, r, p<<1|1, ql, qr);
	else
	{
		return query(l, mid, p<<1, ql, mid)+query(mid+1, r, p<<1|1, mid+1, qr);
	}
}
int main()
{
	int cases;
	cin>>cases;
	for(int i = 0; i < cases; i++)
	{
		int n,m;
		cin>>n>>m;
		values.resize(n*4);
		tag.resize(n*4);
		build(1, n, 1);
		for(int j = 0; j < m; j++)
		{
			int l,r,v;
			cin>>l>>r>>v;
			update(1, n, 1, l, r, v);
		}
		cout<<"Case "<<i+1<<": The total value of the hook is "<<query(1,n,1,1,n)<<"."<<endl;
	}

}