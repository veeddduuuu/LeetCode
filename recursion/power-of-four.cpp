class Solution {
public:
    bool isPowerOfFour(int n) {
       long x;
        int p = 0;
        while (x<=n){
            
            x = pow(4,p);
            if (x == n){
                return true;
            }
            p++;
        }
        return false; 
    }
};