/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

/*
1. Do the independent inorder traversal using the stack for both the trees
2. pop() the lowest element and push it into ans array.
3. hop into the next lowest element in from the popped stack.
*/
    void pushLeft(stack<TreeNode*>&s,TreeNode* curr){
        while(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
    }

    void pushArr(vector<int>&ans,stack<TreeNode*>&st){
            TreeNode* temp = st.top();
                ans.push_back(temp->val);

                st.pop();
                pushLeft(st,temp->right);

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;

        stack<TreeNode*> s1,s2;

        pushLeft(s1,root1);
        pushLeft(s2,root2);

        while(s1.size() && s2.size())

            if(s1.top()->val<s2.top()->val) pushArr(ans,s1);
            
            else pushArr(ans,s2);


        while(s1.size()) pushArr(ans,s1);
        while(s2.size()) pushArr(ans,s2);

        return ans;

    }
};