class Solution {
public:
/*
store in the map => map[name][city] = {{m1,i1},{m2,i2},{m3,i3}}

search for clashing (name==name && city!=city) in the map and push index to set while traversing

*/
 vector<string> split(string str, string delim){
        vector<string> ans;
        size_t pos = 0;

        while((pos = str.find(delim) )!= string::npos){
            ans.push_back(str.substr(0,pos));
            str.erase(0,pos+delim.size());
        }

        ans.push_back(str);
        
        return ans;

    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        map<string,map<string,vector<pair<int,int>>>> lookup;
        set<int>included;
        for (int i=0;i<transactions.size();i++){
            string str = transactions[i];
            auto value = split(str,",");

            if(stoi(value[2])>1000) included.insert(i);
            
                if(lookup.find(value[0])!=lookup.end()){
                    for(auto itr: lookup[value[0]]) 
                    
                        if(itr.first!=value[3])
                    
                            for(auto pp: itr.second) 
                     
                                if(abs(pp.first-stoi(value[1]))<=60) {included.insert(i); included.insert(pp.second);}

                    
                }

                
            lookup[value[0]][value[3]].push_back({stoi(value[1]),i});

        }

        vector<string> ans;
        // cout<<lookup.size();
        // for(auto itr: lookup){
        //     cout<<itr.first<<"->";
        //     for(auto mpr: itr.second)
        //         {cout<<mpr.first<<"->";
        //         for(auto pp: mpr.second)
        //         cout<<pp.first<<","<<pp.second<<" ";
        //         cout<<endl;}
        //         cout<<endl;
        // }

        for(int i: included) ans.push_back(transactions[i]);

        return ans;

    }
};