#include<iostream>
using namespace std;

struct TreeNode {
    int val;  
    TreeNode*left; 
    TreeNode*right; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* root){
    if(root->val ==0  || root->val == 1 ){
        return root->val ==1;
    }else if(root-> val==2){
        return helper(root->left) || helper(root->right);
    }else if( root->val == 3){
        return helper(root->left) && helper(root->right);
    }

    return false;
}

bool evaluateTree(TreeNode* root){
    return helper(root);
}

int main(){
    // Creating Nodes
    TreeNode* root = new TreeNode(2);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node1_right = new TreeNode(1);

   // Linking Nodes to Form the Tree
    root->left = node1;
    root->right = node3;
    node3->left = node0;
    node3->right = node1_right;

    cout<< evaluateTree(root)<<endl;
}