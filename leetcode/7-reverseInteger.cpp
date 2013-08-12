class Solution {
public:
    // 没有考虑溢出
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign=1, res=0;
        if(x<0)
            x=-x, sign=-1;
        while(x>0){
            res = res*10+x%10;
            x/=10;
        }
        if(sign<0)
            res = -res;
        return res;
    }
};
