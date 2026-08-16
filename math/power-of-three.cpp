class Solution {
public:
    bool isPowerOfThree(int n) {
        long x;
        int p = 0;
        while (x<=n){
            
            x = pow(3,p);
            if (x == n){
                return true;
            }
            p++;
        }
        return false;
    }
};