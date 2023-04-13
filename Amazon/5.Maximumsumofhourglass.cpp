class Solution {
    // Intuitive approach travel, calculate and compare
public:
    int maxSum(vector<vector<int>>& grid) {
        int M = grid.size(),N = grid[0].size();
        int ans  = 0;

        for(int i = 0;i<M-2;i++)
        for(int j =0;j<N-2;j++){
        int cursum = grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
        ans = max(ans, cursum);}

        return ans;


    }
};