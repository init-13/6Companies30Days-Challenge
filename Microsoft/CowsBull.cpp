class Solution {

public:

    // First Calculate the digits at right position increment A
    // If not at right position store in two maps for secret and guess
    // for each remaning digit in guess add min(secret,guess)[digit] to B
    // return ans;
    string getHint(string secret, string guess) {
        map<char,int> sec,gue;
        int A=0,B=0;
        for(int i=0;i<secret.size();i++) if(secret[i]==guess[i]) A++;
        else{ sec[secret[i]]+=1; gue[guess[i]]+=1;}

        for(auto i: gue) B+=min(sec[i.first],i.second);

        return to_string(A)+"A"+to_string(B)+"B";
    }
};