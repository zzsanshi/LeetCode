// 后序遍历左-右-根
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
// 递归 0ms 8.3MB
void postorder(TreeNode* root,vector<int> &res){
    if(!root) return;
    postorder(root->left,res);
    postorder(root->right,res);
    res.emplace_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root,res);
    return res;
}

// 迭代 4 ms 8.2MB
#include<stack>
#include<algorithm>
// 左-右-根 --》 根-右-左 反转
vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> res;
    stack<TreeNode*> sk;
    sk.emplace(root);
    while(!sk.empty()){
        auto tmp = sk.top();
        sk.pop();
        res.push_back(tmp->val);
        if(tmp->left) sk.emplace(tmp->left); 
        if(tmp->right) sk.emplace(tmp->right);
    }
    reverse(res.begin(),res.end());
    return res;
}