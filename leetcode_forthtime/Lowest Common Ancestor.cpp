Node* LCA(Node* root, Node* p, Node* q)
{
    if(!root || root == p || root == q))
        return root;
    Node* l = LCA(root->left, p, q);
    Node* r = LCA(root->right, p ,q);
    if(l && r)
        return root;
    else
        return l?l:r;
        
}