class Solution {
public:
    bool isPalindrome(int x) {
        long long temp=x;
        long long rev=0;
        if(temp<0){
            return false;
        }
        while(temp!=0){
            int dig=temp%10;
            rev=rev*10+dig;
            temp/=10;
        }
        return rev==x;

        
    }
};