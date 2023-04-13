class Solution {
public:
/*
  The negative sign can be transfered to any element.
  if count of negative sighn is even return the sum as it is
  else exclude the minimum absolute value fron the sum.
*/
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int cnt = 0, MIN = INT_MAX;
        for(auto i : matrix)
         for(int j: i){
             ans += abs(j);
                cnt+=(j<0);
                
                if(abs(j)<MIN) MIN = abs(j);

                
                
             
         }
       // cout<<ans<<" "<<MIN<<" "<<cnt;
         return ans - (cnt%2)*2*MIN;
        
    }
};