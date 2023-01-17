class Solution {
public:
/*

Find the GCD of nums Divide
find the first encountered divisor of that GCD in nums 
return number of elements larger that that divisor

*/
    int minOperations(vector<int> nums, vector<int>& numsDivide) {
        
        int G = 0;

        for(int i: numsDivide)
            
            G = __gcd(i,G);

        

        int minS = INT_MAX;
        for(int i: nums)
            if(G%i==0) minS = min(minS,i);
        

        if(minS==INT_MAX) return -1;

        int count=0;

        for(int i: nums) count+=(i<minS);

        return count;

    }
};