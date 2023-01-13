class Solution {
public:
   // Iterate recursively through all possible numbers from 1 to 9
   // choice pick it or not pick it
   // Always increase i to avoid duplicates results
   // check for base and edge conditions
    void help(vector<int>&curr,vector<vector<int>>&ans,int k,int tgt,int i){
       // cout<<k<<" "<<tgt<<" "<<i<<endl;
      
        if(k==0){if(tgt==0 && curr.size())ans.push_back(curr); return;}
        if(tgt<i || i==10) return;
        curr.push_back(i);
        help(curr,ans,k-1,tgt-i,i+1);
        curr.pop_back();

        help(curr,ans,k,tgt,i+1);

       // for(int ii=0;ii<inci.size();ii++) inci[ii].push_back(i);
        
        
       // for(vector<int> vi:dinci) if(vi.size()) inci.push_back(vi);

        //return inci;

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        help(curr,ans,k,n,1);
        return ans;
    }
};