/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
/*
Make Sure to cache the repeatetive calls
 Step 1 Find the peak of mounatain (Binary Search special condition)

 Step 2 Binary Search the 0 to peak for target , print if found
 step 3 Binary Search the peak+1 to size-1, print what is the result
*/
    int fbreak(MountainArray &mountainArr){

        int lb = 0;
        int ub = mountainArr.length()-1;
        while(lb<=ub){

            int mid = (lb+ub) / 2 ;
            int mmid = mountainArr.get(mid);
            int mmidp = mid==mountainArr.length()-1 ?INT_MIN: mountainArr.get(mid+1);
            int mmidm = mid==0?INT_MIN:mountainArr.get(mid-1);
            if(mid==mountainArr.length()-1 || mid==0 || (mmid>mmidp && mmid>=mmidm)) return mid;

            if(mmid>mmidp) ub = mid-1;
            else lb = mid+1;
            
        }

        return lb;


    }


    int BS(MountainArray &mountainArr,int l,int r, int target){

        while(l<=r){

                int mid = (l+r) / 2;

                int mmid = mountainArr.get(mid);

                if(mmid==target && (mid==0 ||  mountainArr.get(mid-1)<target)) return mid;

                if(mmid<target) l = mid+1;
                else r = mid-1;

        }

        return -1;
    }
    int BSrev(MountainArray &mountainArr,int l,int r, int target){

         while(l<=r){

                int mid = (l+r) / 2;

                 int mmid = mountainArr.get(mid);
                
                if(mmid==target && (mid==0 || mountainArr.get(mid-1)!=target)) return mid;

                if(mmid<=target) r = mid-1;
                else l = mid+1;

        }

        return -1;


    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int br = fbreak(mountainArr);

        int ff = BS(mountainArr,0,br,target);
        //int fs = BSrev(mountainArr,br+1,mountainArr.length()-1,target);

       return (ff!=-1)?ff:BSrev(mountainArr,br+1,mountainArr.length()-1,target);
    }
};