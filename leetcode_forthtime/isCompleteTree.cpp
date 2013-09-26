#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
struct BinaryTree
{
	BinaryTree* left;
	BinaryTree* right;
};
bool isComplete(BinaryTree* root)
{
	if(!root)
		return true;
	queue<BinaryTree*> q;
	q.push(root);
	bool leftmost = false;
	while(!q.empty())
	{
		BinaryTree* cur = q.front();
		q.pop();
		if(cur->left)
		{
			if(leftmost)
				return false;
			q.push(cur->left);
		}
		else
			leftmost = true;
		if(cur->right)
		{
			if(leftmost)
				return false;
			q.push(cur->right);
		}
		else
			leftmost = true;
	}
	return true;
}
int main()
{

	getchar();
}