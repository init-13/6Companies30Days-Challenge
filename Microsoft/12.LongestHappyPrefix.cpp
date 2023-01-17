class Solution {
    /*
    
        KMP LPS building(start form i=0 j=1 match increment both else do i = lps[i-1] until j=size())

        See KMP algorithm

        Print s.substr(0,lps.back());

    */
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(),0);
        int i=0,j=1;

        while(j<s.size()){

            if(s[j]==s[i]){ lps[j++] = ++i; }

            else {if(i==0) j++; else i=lps[i-1];}

        }

        //cout<<endl;

        return s.substr(0,lps.back());
    }
};