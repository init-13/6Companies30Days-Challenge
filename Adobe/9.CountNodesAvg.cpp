/**
 pretty intuitive

 return the number the sub of the subtree

 check if avg == curr value inc the global ans count
 */
class Solution {
public:
    pair<int,int> SAT(int& ans, TreeNode* root){

        pair<int,int> lt ={0,0}, rt = {0,0};
        if(root->left) lt = SAT(ans,root->left);

        if(root->right)  rt = SAT(ans,root->right);

        if((int)((int)(lt.first+rt.first+root->val)/(int)(lt.second+rt.second+1))==root->val) ans+=1;

        return {lt.first+rt.first+root->val,lt.second+rt.second+1} ;
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        auto nul = SAT(ans,root);

        return ans;
        
    }
};