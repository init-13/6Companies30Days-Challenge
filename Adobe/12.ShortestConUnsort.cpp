class Solution {
public:
/*
Find the largest and the smallest index out of place.
index out of place for ending: last number where the number is smaller than the largest till now
index out of place for starinig:last number where the number is larger than the smallest till now from right.

- - - - (st <--) - - - (-->end) - - - 
*/
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = -1,minsf=nums.back(),maxsf = nums[0];

        for(int i=0;i<nums.size();i++){
            

            
            if(nums[i]<maxsf) end = i;
            if(nums[nums.size()-i-1]>minsf) start = nums.size()-i-1;

            minsf = min(minsf,nums[nums.size()-i-1]);
            maxsf = max(maxsf,nums[i]);
                
        }

        return end-start+1;
    }
};