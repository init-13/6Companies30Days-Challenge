class Solution {
public:
    /*
    Sort them according to capital
    start from least cap
    push the profits in priority Q until large cap required
    then Add the top Profits to w until k 

    repeat above 2 until end of array

    relinquish the remaining k with the projects in PQ still;
    */
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> INC;

        for(int i=0;i<n;i++)
        INC.push_back({capital[i],profits[i]});

        sort(INC.begin(),INC.end());

        priority_queue<int> PQ;
        int i=0;
        while(k && i<n){

            if(INC[i].first<=w) PQ.push(INC[i++].second);

            else {

                if(PQ.empty()) return w;

                w+=PQ.top();
                PQ.pop();
                k--;
            
            }

            
        }

        while(!PQ.empty() && k--){
                w+=PQ.top();
                PQ.pop();

        }
        return w;
    }
};