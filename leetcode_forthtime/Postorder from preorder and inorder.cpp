#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
void postOrderFromPreAndInOrder(string preorder, string inorder)
{
	int len1 = preorder.size();
	int len2 = inorder.size();
	if(!len1 || len1 != len2)
		return;
	char root = preorder[0];
	int i = 0;
	for(; i < len2; i++)
	{
		if(inorder[i] == root)
			break;
	}
	postOrderFromPreAndInOrder(preorder.substr(1, i), inorder.substr(0,i));
	postOrderFromPreAndInOrder(preorder.substr(i+1), inorder.substr(i+1));
	cout<<root<<endl;
}
int main() {
	string pre = "GDAFEMHZ";
	string in = "ADEFGHMZ";
	postOrderFromPreAndInOrder(pre, in);
	getchar();
	return 0;
}