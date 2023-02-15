class Solution {
public:
/*
store the current dividend to ans.size() map so as to know where to repeat when it is encountered again
make sure to increase map[n]++ if it is currently at "." or "0" as first timme only . is added and after that 0 is added without using . first time

now imitate division

while(n!=0 || n encountered in map)
if n<d
    keep flag if "." is used or not and add 0 after that
    keep flag if 1 zero is used and add 0 to ans after that
else 
    make flag = 0
    and store floor(n/d) to ans
    n % = d

if reoc encountered
    now add "(" at map[n] and end with ")"

*/
    string fractionToDecimal(int numerator, int denominator) {
       long n = numerator,d = denominator;
       if(n==0) return "0";

        map<long,int> reoc;
        string ans = ((n<0)^(d<0))?"-":"";
        n = abs(n);
        d = abs(d);
        //cout<<n<<d;
        ans+=to_string((long)(n/d));
        n%=d;
        int dec = 0,exU = 0;
        int RE = 0;
        while(n!=0){
            if(reoc.find(n)!=reoc.end())
                {RE = reoc[n];  //cout<<n<<" "<<reoc[n]<<ans<<endl;
                break;}
            //cout<<n<<" "<<ans.size()<<endl;
            reoc[n] = ans.size();

            if(n<d){
                if(!dec) {ans+="."; dec=1;exU=1;}
                else {if(!exU) exU = 1; else ans+="0";}

                n*=10;
            }

            else{

                exU = 0;
                ans+=to_string((long)(n/d));
                n%=d;
            }

        }
        if(RE){
            if(ans[RE]=='.' || ans[RE]=='0') RE++;

            string pans = "";

            for(int i=0;i<ans.size();i++){
                if(RE==i)pans+="(";
                pans+=ans[i];
                
                
            }

            return pans+")";
        }
        return ans;

    }
};