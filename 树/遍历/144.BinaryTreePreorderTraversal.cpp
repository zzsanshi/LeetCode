// 前序遍历根-左-右
// HOT
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// 递归 4ms 8.2MB
void preorder(TreeNode* root,vector<int> &res){
    if(!root) return;
    res.emplace_back(root->val);
    preorder(root->left,res);
    preorder(root->right,res);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root,res);
    return res;
}

// 迭代 0ms 8.1MB
#include<stack>

vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> res;
    stack<TreeNode*> sk;
    sk.emplace(root);
    while(!sk.empty()){
        auto tmp = sk.top();
        sk.pop();
        res.push_back(tmp->val);
        if(tmp->right) sk.emplace(tmp->right);
        if(tmp->left) sk.emplace(tmp->left); 
    }
    return res;
}