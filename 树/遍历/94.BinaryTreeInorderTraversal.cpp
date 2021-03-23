// 中序遍历左-根-右
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
void inorder(TreeNode* root,vector<int> &res){
    if(!root) return;
    inorder(root->left,res);
    res.emplace_back(root->val);
    inorder(root->right,res);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root,res);
    return res;
}

// 迭代 4 ms 8.1MB
#include<stack>
#include<algorithm>
// 左-根-右
vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> res;
    stack<TreeNode*> sk;
    while(root||!sk.empty()){
        while(root){
            sk.emplace(root);
            root = root->left;
        }
        root = sk.top();
        sk.pop();
        res.emplace_back(root->val);
        root = root->right;
    }
    return res;
}