class Solution {
public:
 /* for each i store count of each unique distances from 0 to n except i.
    add count*(count-1) for each map values 

    
 */
    long long dis2(vector<int>&A, vector<int>&B){
        return pow((A[0]-B[0]),2) + pow((A[1]-B[1]),2);

    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0,n=points.size();
        
        for(int i=0;i<n;i++){
            map<long long,int> mp;

            for(int j=0;j<n;j++){ if(i==j) continue;
            mp[dis2(points[i],points[j])]++;// cout<<dis2(points[i],points[j]);
            
            }

            
            for(auto itr: mp) ans+=(itr.second*(itr.second-1));
        }

        return ans;

    }
};