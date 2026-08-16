class Solution {
public:
    bool isPerfectSquare(int num) {
        long pdt = 1;
        long i = 1;

        if (num == 1) return true;

        while (num>=pdt){
            pdt = i*i;
            if (pdt == num){
                return true;
            }
            i++;
        }
        return false;
    }
};