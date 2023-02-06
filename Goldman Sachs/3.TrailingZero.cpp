class Solution {
public:
/*

f(n) = 0 for n<5
f(n) = n/5 + f(n/5);

instances of 5 in repeats of n!

*/

    int trailingZeroes(int n) {
        if(n<5) return 0;

        return n/5 + trailingZeroes(n/5);
    }
};