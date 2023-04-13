class Solution {
public:
/* k=4
1 2 3 4 5 6 7 
      x 5 6 7 1 2 3
        1 2 3 4 5 6
        
        after first kill 5->1 6->2 so  after returning we need to back change 
        
        1->5 
       return this (a-1+k)%n + 1   
       where a = ans(n-1,k)   */
    int helper(int n, int k) {return (n==1?0:(helper(n-1,k)+k)%n);}

    int findTheWinner(int n, int k) {

        return helper(n,k)+1;
    }
};