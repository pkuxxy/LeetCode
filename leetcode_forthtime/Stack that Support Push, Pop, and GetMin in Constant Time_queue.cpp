// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <deque>
#include <queue>
using namespace std;
class QueueGetMin
{
private:
    deque<int> minq;
    queue<int> q;
public:
    void push_rear(int data)
    {
        q.push(data);
        while(!minq.empty() && minq.back() > data)
            minq.pop_back();
        minq.push_back(data);
    }
    bool pop_front()
    {
        if(q.empty())
            return false;
        if(q.front() == minq.front())
        {
            minq.pop_front();
        }
        q.pop();
        return true;
    }
    int getMin()
    {
        if(minq.empty())
            return INT_MIN;
        return minq.front();
    }
};
int main() {
    QueueGetMin q;
    q.push_rear(3);
    q.push_rear(1);
    q.push_rear(4);
    q.push_rear(2);
    q.push_rear(5);
    cout<<q.getMin()<<endl;
    q.pop_front();
    cout<<q.getMin()<<endl;
    q.pop_front();
    cout<<q.getMin()<<endl;
    q.pop_front();
    cout<<q.getMin()<<endl;
    q.pop_front();
    cout<<q.getMin()<<endl;
    q.pop_front();
    return 0;
}