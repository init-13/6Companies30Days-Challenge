class Solution {
public:

    /*
    
    for eg: 101010110 fix frst 1 and find  1 00000000 -> 1 11111111 which is fib(len)

            now do it for all 1's encountered until the dublicate 1 encountered and we can't fix from there.

      Index -> 8 7 6 5 4 3 2 1 0
      binary-> 1 0 1 0 1 0 1 1 0

      ans = fib(8) + fib(6) + fib(4) + fib(2) + fib(1)

      if loop finish encountered add 1 for the original number in the ans fib[0]

    
    */
    
    int findIntegers(int n) {
        int DP[32];
        DP[0] = 1;
        DP[1] = 2;

        for(int i=2;i<32;i++) DP[i] = DP[i-1]+ DP[i-2];
        
        int curr = 30, flag = 0,ans =0;
        cout<<curr;
        while(curr>-1){
            if(n&(1<<curr))  {ans+=DP[curr]; if(flag) return ans; flag = 1; }
            else flag = 0;

            curr--;
        }

        return ans+1;
       
    }
};