class Solution {
public:
/* Compute all distances combinations b/w points
    only 2 different distance should exist and 0 shouldn't exist
*/
    long long dis2(vector<int>&A,vector<int>&B){
        return pow((A[0]-B[0]),2)+pow((A[1]-B[1]),2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<long long> ans;

        ans.insert(dis2(p1,p2));
        ans.insert(dis2(p1,p3));
        ans.insert(dis2(p1,p4));
        ans.insert(dis2(p3,p2));
        ans.insert(dis2(p4,p2));
        ans.insert(dis2(p4,p3));

        return ans.find(0)==ans.end() && ans.size()==2;
    }
};