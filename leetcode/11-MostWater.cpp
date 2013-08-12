class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start=0, end=height.size()-1;
        int maxVol = 0;
        while(start < end){
            maxVol = max(maxVol, min(height[end], height[start]) * (end-start));
            if(height[start]>height[end])
                end --;
            else
                start ++;
        }
        return maxVol;
    }
};
