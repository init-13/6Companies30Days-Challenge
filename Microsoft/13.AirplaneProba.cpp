class Solution {
public:
    /*
    Suppose the first passenger sits on

    Seat 1 => 1/n
    Seat 2 => 1/n * f(n-2)
    Seat 3 => 1/n * f(n-3)
    ..
    ..
    ..
    Seat n-1 => 1/n * f(1)

    Summation => F(n) = 1/n(1+F(1)....F(n-1))

    */
    double nthPersonGetsNthSeat(int n) {
          if(n==1)
            return 1;
        else
            return 0.5;
    }
};
