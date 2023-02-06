class Solution {
public:
/* From each point i we will store the count of slope from i to j(i+1->n) for each i(0->n-1)
    We will return the max of the count each ith case as ans 
*/

    int maxPoints(vector<vector<int>>& points) {

        
        int maxS=1,n=points.size();

        for(int i=0;i< n-1;i++){
                 map<double,int> mp;
                int temp=0;
                for(int j=i+1;j<n;j++)

                {double d = double(points[j][1]-points[i][1])/double(points[j][0]-points[i][0]);
 //cout<<d<<endl;
 if(points[j][0]==points[i][0]) d=abs(d);
                
                mp[d]++;


               // temp = max(mp[d],temp);
}
    for(auto itr: mp)
    maxS = max(itr.second+1,maxS) ;
               
        }

        return maxS;
    }
};