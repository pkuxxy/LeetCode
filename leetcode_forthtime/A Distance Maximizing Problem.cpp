// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int maxDis(int h[], int n)
{
    if(!h || n <= 0)
        return 0;
    vector<int> begin;
    vector<int> bindex;
    vector<int> end;
    vector<int> eindex;
    int minh = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(h[i] < minh)
        {
            begin.push_back(h[i]);
            bindex.push_back(i);
            minh = h[i];
        }
    }
    int maxh = INT_MIN;
    for(int i = n-1; i >= 0; i--)
    {
        if(h[i] > maxh)
        {
            end.push_back(h[i]);
            eindex.push_back(i);
            maxh = h[i];
        }
    }
    reverse(end.begin(), end.end());
    reverse(eindex.begin(), eindex.end());
    int maxl = 0;
    int i = 0;
    int j = 0;
	while(i < begin.size() && j < end.size())
    {
        if(begin[i] >= end[j])
        {
            i++;
            continue;
        }
        maxl = max(maxl, eindex[j] - bindex[i]);
        j++;
    }
    return maxl;
}
int main() {
    int h[] = {4,3,5,2,1,3,2,3};
    cout <<maxDis(h,8)<< endl;
    getchar();
    return 0;
}