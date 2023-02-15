class Solution {
    /*
    
    FOR K INCREAING SEQUENCE (O(nk))

    check if their exist a number that is greater than the previsiouly k-1 filled  increasing sequence

    int arr[k] = {min,min1,min2....mink-1} INCREASING ORDER

    if(arr[curr]>mink-1) return true

    else replace where it should have existed . further elements witll reshuflle the min array.

    
    */
public:
    bool increasingTriplet(vector<int>& nums) {
        int Min = INT_MAX, Mid = INT_MAX;

        for(int i: nums)
            if(i<=Min) Min = i;
            else if(i<=Mid) Mid =i;
            else return true;
        
        return false;
    }
};