class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max=-100000;
        int sum=0;
        int i=0;
        for(; i<n; i++){
            sum += A[i];
            if(sum>max)
                max = sum;
            if(sum<0)
                sum = 0;
        }
        return max;
    }
};
