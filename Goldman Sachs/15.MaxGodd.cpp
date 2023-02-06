class Solution {
public:
/*
loop from 0 => 0000 to 2^m - 1 = 11111 
Where 1-> represent good people
for each check if valid can exist by testing only 1 and 0 statement of good people
return the max encountered.
*/
    int checkPos(int BS, vector<vector<int>>& statements){
        int pos=0,ans=0; //cout<<BS;
        for(int j=1;j<=BS;j*=2){ //cout<<j;
            if(BS&j){//cout<<1<<" ";
            for(int i=0;i<statements.size();i++)
                if((statements[pos][i]==0 && BS&(1<<i))||(statements[pos][i]==1 && !(BS&(1<<i)))) return 0;
                ans++;}
                //else cout<<0<<" ";
                pos++;
        }//cout<<endl;
        return ans;
    }

    int BAcount(int n){
        int c = 0;
        while(n){ n = n&(n-1); c++;}

        return c;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0,m = statements.size();

        for(int i=0;i<pow(2,m);i++){
          if(BAcount(i)>ans) ans = max(checkPos( i,statements),ans);
        }

        return ans;

    }
};