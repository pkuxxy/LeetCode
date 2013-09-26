#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<ctime>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
};
Node* findNext(Node* root, Node* target)
{
	if(!root && !target)
		return NULL;
	Node* pre = NULL;
	stack<Node*> s;
	Node* cur = root;
	while(!s.empty() || cur)
	{
		if(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = s.top();
			s.pop();
			if(pre == target)
				return cur;
			pre = cur;
			cur = cur->right;
		}
	}
	return NULL;
}
int main() {

	getchar();
	return 0;
}