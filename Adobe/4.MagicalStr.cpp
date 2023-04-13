class Solution {
public:
  /*
  
  Start from curr index
  if curr is 1 push back currele
  else pushback currele 2 times
  
  keep counting 1 and size<n
  
  */
    int magicalString(int n) {
        vector<int> s = {1,2,2};
       int curr_index = 2;
       int curr = 1;
       int ans = 1;

       while(s.size()<n){
           int num = s[curr_index++];

           
           s.push_back(curr); ans+=(curr==1);
           
           if(s.size()<n && num==2) {s.push_back(curr); ans+=(curr==1);}
           

           curr = (curr==1)?2:1;
       }

       return ans;

    }
};