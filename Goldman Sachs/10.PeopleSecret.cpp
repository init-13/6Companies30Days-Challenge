class Solution {
public:
// Keep count of how many new people are adding each day 
// people added = active(today-1) + people(today-delay) - people(today-forget)
// return the sum of people in last forget cycle. 
    int peopleAwareOfSecret(int n, int delay, int forget) {
          vector<long long> ans(n,0);
          long long MOD  = pow(10,9) + 7;
            ans[0] = 1;
            long long FIN = n==forget;//AND THIS IS TOO 
            long long act = 0;
          for (int i=1;i<n;i++){
            long long dplus, fminus;

              if((i-delay)<0) dplus = 0;
              else dplus = ans[i-delay] ;

              if((i-forget)<0) fminus = 0;
              else fminus = ans[i-forget];

            //THIS IS IMPORTANT
                act = (act + (dplus-fminus+MOD)%MOD + MOD)%MOD;
 

              ans[i] = act;
            if (i>=n-forget) FIN =( FIN+ans[i]%MOD)%MOD;
            
            cout<<ans[i]<<endl;

               
          }
          return FIN;
    }
};