// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
const int MAX_SUM = 10;
void printMove(int coin[], int p[][MAX_SUM], int n)
{
    int i = 0;
    int j = n-1;
    bool myturn = true;
    while(i <= j)
    {
        cout<<(myturn? "I:\t" : "You:\t");
        int p1 = p[i+1][j];
        int p2 = p[i][j-1];
        if(p1 <= p2)
        {
            cout<<i+1<<"("<<coin[i]<<")";
            i++;
        }
        else
        {
            cout<<j+1<<"("<<coin[j]<<")";
            j--;
        }
        myturn = !myturn;
        cout<<endl;
    }
}
int getMaxCoins(int coin[], int n)
{
    int p[MAX_SUM][MAX_SUM] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = i; k < n; j++,k++)
        {
            int a = (j+2<n)? p[j+2][k]:0;
            int b = (j+1<n && k-1 >= 0)?p[j+1][k-1]:0;
            int c = (k-2 >= 0) ? p[j][k-2]:0;
            p[j][k] = max(coin[j] + min(a, b),coin[k] + min(b, c));
        }
    }
    printMove(coin, p, n);
    return p[0][n-1];
}
int main() {
    int coin[] = { 3, 2, 2, 3, 1, 2};
    cout << getMaxCoins(coin, 6) << endl;
    
    return 0;
}