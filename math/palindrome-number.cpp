class Solution {
public:
    bool isPalindrome(int x) {
        long reverse = 0;
        int original = x;
        while (x>0){
            int n = x%10;
            reverse = reverse*10 + n;
            x = x/10;
        }
        return (original == reverse);
    }
};