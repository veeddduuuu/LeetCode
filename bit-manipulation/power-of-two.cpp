class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x;
        int p = 0;
        while (x<=n){
            
            x = pow(2,p);
            if (x == n){
                return true;
            }
            p++;
        }
        return false;

    }
};