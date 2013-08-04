class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        int pc = 1;
        int nc = 0;
        bool flag = true;
        vector<int> one;
        while(!q.empty())
        {
            pc--;
            TreeNode* cur = q.front();
            q.pop();
            one.push_back(cur->val);
            if(cur->left)
    		{
                q.push(cur->left);
				nc++;
			}
            if(cur->right)
            {
				q.push(cur->right);
				nc++;
			}
            if(!pc)
            {
                pc = nc;
                nc = 0;
                if(!flag)
                    reverse(one.begin(), one.end());      
                ret.push_back(one);
                one.clear();
                flag = !flag;
            }
        }
        
        return ret;
    }
};