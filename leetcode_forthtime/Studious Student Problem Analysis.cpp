// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
bool cmp(const string& a, const string& b)
{
    return a+b < b+a;
}
int main() {
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin>>words[i];
    sort(words.begin(), words.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        cout<<words[i];
    }
    return 0;
}