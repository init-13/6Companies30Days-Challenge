class Solution {
public:
    /*
    for each word find of next word exist in 's' after first j position. increment ans if true.

    return ans

    */
    bool check(string &s, string &word)
    {
        int i=1;
        int j=s.find(word[0]);
        if(j==-1)
            return false;
        while(i<word.length())
        {
            j=s.find(word[i],j+1);
            if(j==-1)
                return false;
            i++;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0;
        for(auto word:words)
        {
            if(check(s,word))
                res++;
        }
        return res;
    }
};