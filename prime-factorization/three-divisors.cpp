class Solution {
public:
    bool isThree(int n) {
        int count = 0; 
        int num = sqrt(n);
        for (int i = 1; i<=num; i++){
            if (n%i == 0){
                count++;
                if (n/i!=i){
                    count++;
                }
            }
        }
        if (count == 3) return true;
        return false;
    }
};