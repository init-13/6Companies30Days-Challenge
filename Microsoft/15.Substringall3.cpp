class Solution {
public:
    /*
    when all a b c is found store the min of index to imin
    add number of prefixes from 0 to imin to count 
    update i as we are taking prefixes everytime
    */
    int numberOfSubstrings(string s) {
        int a,b,c,ans=0;
        a=b=c=-1;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a') a = i;
            else if(s[i]=='b') b=i;
            else c=i;
            
            ans =  ans+min(min(a,b),c)+1;

        }
        return ans;
    }
};