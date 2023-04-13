class Solution {
public:
/*

[power] -- > (need x)
 |
 v
(need y)

so the player will need "min(x,y) - power" at current position

if need <=0 it can go fwd with 1, else it has to go fwd with need as it is req.

*/
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> DP (m, vector<int>(n,0));
        DP[m-1][n-1] = 1 - dungeon[m-1][n-1] <=0  ? 1 : 1 - dungeon[m-1][n-1]  ;

        for(int i=n-2;i>-1;i--)
        DP[m-1][i] = DP[m-1][i+1] - dungeon[m-1][i] <=0 ? 1 : DP[m-1][i+1] - dungeon[m-1][i];

        for(int i=m-2;i>-1;i--)
        DP[i][n-1] = DP[i+1][n-1] - dungeon[i][n-1] <=0 ? 1: DP[i+1][n-1] - dungeon[i][n-1] ;

        for(int i = m-2; i>-1; i--)
        for(int j = n-2; j>-1; j--)

        DP[i][j] = min(DP[i+1][j],DP[i][j+1]) - dungeon[i][j] <= 0 ? 1 :  min(DP[i+1][j],DP[i][j+1]) - dungeon[i][j] ;

        return DP[0][0];
        
    }
};