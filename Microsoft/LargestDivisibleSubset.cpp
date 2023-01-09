class Solution {
public:
    // new element must be a multiple of largest
    // sort the vector reverse and start from last
   // for each ith iterate from i+1 to n and add i if it is a multiple of largest add it to last.
   // print the largest vector of size
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int N = nums.size();
        vector<pair<int,int>> ans (N,pair<int,int>());

        ans[N-1] = make_pair(1,N);
        int maxS,las,Lmax=0,Llas=N-1;
        for(int i=N-2;i>-1;i--){
            maxS = 0;
            las = N;
            for(int k=i+1;k<N;k++){
                    if(nums[i]%nums[k]==0 && ans[k].first>maxS){
                        maxS = ans[k].first;
                        las = k;
                    }

                    ans[i]=make_pair(1+maxS,las);
                    if(ans[i].first>Lmax){Lmax = ans[i].first;Llas = i;}

            }
            
        }

        
        
        vector<int> Ans;
        
        while(Llas!=N){
            Ans.push_back(nums[Llas]);
                Llas = ans[Llas].second;
        }

        return Ans;
    }
};