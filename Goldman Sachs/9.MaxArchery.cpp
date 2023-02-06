class Solution {
public:
    /*
     Simple Bottom up Backtracking. 
     Either win/Lose

     Remember to balance number of arrows left.
    */
    int maxSC = 0;
    void helper(vector<int>&fin,vector<int>&ans,int i,int sc,int numArr,vector<int>& aliceArrows){
            if(!numArr || i==aliceArrows.size()){ if(sc>maxSC) {fin = ans; fin[0]+=numArr; maxSC = sc;} return;}

            if(numArr>aliceArrows[i]){
            ans[i] = aliceArrows[i]+1;
            helper(fin,ans,i+1,sc+i,numArr-1-aliceArrows[i],aliceArrows);
            ans[i] = 0;}

            helper(fin,ans,i+1,sc,numArr,aliceArrows);

    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n=aliceArrows.size();
        vector<int>ans(n,0),curr(n,0);

        helper(ans,curr,0,0,numArrows,aliceArrows);
        //cout<<maxSC;
        return ans;
    }
};