class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0)
            return false;
        
        long long y=0, xcopy=x;
        while(x>0){
            y = y*10 + x%10;
            x /= 10;
        }
        
        return y==xcopy;
        
    }
};
