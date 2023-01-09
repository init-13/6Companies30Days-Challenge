class Solution {
public:
    //Every Slide the sum-last integer is added to before sum and the last*size-1 is subtracted
    // we keep on doing that find the max
    // beware to start from back and keep updating the curr slide sum
    int maxRotateFunction(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);

        int ans = 0,curr;
        for(int i=0;i<nums.size();i++)ans+=i*nums[i];
        curr = ans;
        for(int i=nums.size()-1;i>-1;i--) {
            curr = curr+sum- nums[i]*nums.size();
            ans = std::max(ans,curr);
}
        return ans;
    }
};