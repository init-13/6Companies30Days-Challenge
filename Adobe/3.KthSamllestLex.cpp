class Solution {
public:
 /*

 for each (k,n) find how many elements exist with prefix k under n

 set k over n and make all remaning as ans = 111..n times

 start if prefix k at highest place is less than n prefix add 100..n to ans
 if prefix k at highest place equals n prefix add how many numbers it exceeds+1 for 000

 now in main program count if aur required index is over or under prefix count

 if it is over prefix count decrease the prefixcount and increase the prefix by 1
 else check for next pdigit place prefix. and decrease prefix count;


 example

 (12,123) => 5

 12   3
 12  (1)
 
 at highest place 12==12 so 3+1 add

 return 5
 */
    int PREFIX(int k,int n){

        int kD = pow(10,(int)log10(k));
        int nD = pow(10,(int)log10(n));
        int ans = (pow(10,log10(nD/kD)) - 1)/9;

        //cout<<kD<<" "<<nD<<" "<<ans<<endl;
        if(k>n) return 0;

        else if(n/(nD/kD) > k ) ans += nD/kD;

        else if(n/(nD/kD) == k) ans += n%(nD/kD)+1;

        return ans;
    }
    int findKthNumber(int n, int k) {
        int curAns = 1;
        k = k-1;

        while(k){
            int numbers = PREFIX(curAns,n);
            if(numbers>k) {k--; curAns*=10;}
            else {k-=numbers; curAns++;}

        }
        return curAns;
        
    }
};