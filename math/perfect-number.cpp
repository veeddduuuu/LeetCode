class Solution {
public:
    bool checkPerfectNumber(int n) {
        if (n == 1){
            return false;
        }
        int sum = 1;
        int num = sqrt(n);
        for (int i = 2; i<=num; i++){
            if (n%i == 0){
                sum += i;
                if(n/i != i){
                    sum += n/i;
                }  
            }
        }
        return (n == sum);

    }
};