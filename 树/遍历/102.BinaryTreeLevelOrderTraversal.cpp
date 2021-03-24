#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> out;
    queue<TreeNode*> treelist;
    if(root)
        treelist.push(root);
    vector<int> treeLevel;
    while(!treelist.empty()){
        
        int size = treelist.size();
        for(int i=0;i<size;i++){
            TreeNode * tmp = treelist.front();
            
            treeLevel.emplace_back(tmp->val);
            if(tmp->left) treelist.push(tmp->left);
            if(tmp->right) treelist.push(tmp->right);
            treelist.pop();
        }
        out.push_back(treeLevel);
        treeLevel.clear();
    }
    return out;
}