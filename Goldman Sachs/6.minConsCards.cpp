class Solution {
public:
/* store the last occurence of an integer and compare it with the least till now when it
is encoutered again. 
return -1 if no two numbers are encounterd again*/
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> mp;
        int least = cards.size()+1;

        for(int i=0;i<cards.size();i++){
                if(mp.count(cards[i]))
                least = min(least,i-mp[cards[i]]+1);

                mp[cards[i]] = i;

        }
        return least==cards.size()+1?-1:least;
    }
};