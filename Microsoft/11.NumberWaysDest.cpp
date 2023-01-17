#define ll long long
/*
It's a variant of Dijkstra Algorithm

Maintain a "ways" arary where i tells us the number of ways of shortest path form 0 to ith

Make ways[0] = 1

now in the distance array if a shorter dist encountered from Node to 
nbrNode update the ways[nbrNode] to ways[Node]

if the same dist is encouter increment the ways[nbrNode] by ways[Node]

return the ways[N-1]
*/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

       vector< vector<pair<ll,ll>> > GR (n,vector<pair<ll,ll>>());
        int mod = 1e9 + 7;
        for(auto ed: roads){
            GR[ed[0]].push_back({ed[1],ed[2]});
            GR[ed[1]].push_back({ed[0],ed[2]});

        }

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll>  ways(n,0),
         dist(n,LONG_MAX);
        
        ways[0] = 1;
        dist[0] = 0;

        pq.push({0,0});

        while(pq.size()){

            ll Dist = pq.top().first;
            ll Node = pq.top().second;

            pq.pop();

            for(auto nbr : GR[Node]){

                ll nbNode = nbr.first;
                ll Cost = nbr.second;

                if(Dist + Cost < dist[nbNode]){
                    dist[nbNode] = Dist + Cost;
                    ways[nbNode] = ways[Node];
                    pq.push({dist[nbNode],nbNode});
                }

                else if (Dist + Cost == dist[nbNode])
                    ways[nbNode] = ( ways[nbNode] + ways[Node])% mod ;


            }
        }

        return  ways[n-1]%mod;
    }
};