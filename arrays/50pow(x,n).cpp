// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
#include <vector>
using namespace std;

// in this algorithm, we are using the concept of binary exponentiation
// if x is even, then x^n = (x*x)^(n/2)
// if x is odd, then x^n = x*(x*x)^(n/2)


class Solution {
public:
    double myPow(double x, int n) {
        double ans= 1.0;
        long nn = n;
        if(n<0) nn= nn*(-1);
        while(nn>0){
            if(nn%2==1){
                ans = ans*x;
                nn= nn-1;
            }else{
                x= x*x;
                nn = nn/2;
            }
        } 
        if(n<0) ans = double(1.0)/ double(ans);
        return ans;
    }
};

int main()
{
    return 0;
}