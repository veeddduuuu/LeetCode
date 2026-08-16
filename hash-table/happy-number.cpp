class Solution {
private:
    int sum(int n){
        int x =0;
            
        while (n>0) {
            int num = n%10;
            x = x + num*num;
            n = n/10;
        }
        return x;

    }

public:
    bool isHappy(int n) {    
        int x;
        while (n>4){
            n = sum(n);
        }
        return (n==1);
        
    }
};