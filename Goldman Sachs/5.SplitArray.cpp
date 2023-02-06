class Solution {
public:
// Store the frequency of each integer
// now for each integer
// if integer is not used i.e freq[i]==0
// see if i is needed for another prev sequence 
// if yes then decrease the need count and inc for next i+1
// if not then start a new sequence and check if 3 min is satisfied
// return false if not satisfied

    bool isPossible(vector<int>& nums) {
        map<int,int> ct,
        req;

        for(int i: nums) ct[i]++;

        for(int i: nums){
            if(ct[i]!=0){

                if(req[i]>0){
                    req[i]--;
                    ct[i]--;
                    req[i+1]++;
                }

                else if(ct[i] && ct[i+1] && ct[i+2]){
                    ct[i]--;
                    ct[i+1]--;
                    ct[i+2]--;
                    req[i+3]++;
                }
                else return false;
            }
        }

        return true;
    }
};