#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int searchLowBound(int A[], int n, int target) {
        int s=0, e=n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(A[mid]>=target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        if(s>=0 && s<n && A[s]==target)
            return s;
        else
            return -1;  // not found
    }

    int searchHighBound(int A[], int n, int target) {
        int s=0, e=n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(A[mid]>target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        if(e>=0 && e<n && A[e]==target)
            return e;
        else
            return -1;  // not found
    }

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s=-1, e=-1;
        s = searchLowBound(A, n, target);
        e = searchHighBound(A, n, target);

        vector<int> res;
        res.push_back(s);
        res.push_back(e);
        return res;
    }

};

int main(){
    int a[] = {5, 7, 7, 8, 8, 10};
    Solution sol;
    printf("%d=-1\n", sol.searchLowBound(a,6, 4));
    printf("%d=0\n", sol.searchLowBound(a,6, 5));
    printf("%d=-1\n", sol.searchLowBound(a,6, 6));
    printf("%d=1\n", sol.searchLowBound(a,6, 7));
    printf("%d=3\n", sol.searchLowBound(a,6, 8));
    printf("%d=-1\n", sol.searchLowBound(a,6, 9));
    printf("%d=5\n", sol.searchLowBound(a,6, 10));
    printf("%d=-1\n", sol.searchLowBound(a,6, 11));
    getchar();
    printf("%d=-1\n", sol.searchHighBound(a,6, 4));
    printf("%d=0\n", sol.searchHighBound(a,6, 5));
    printf("%d=-1\n", sol.searchHighBound(a,6, 6));
    printf("%d=2\n", sol.searchHighBound(a,6, 7));
    printf("%d=4\n", sol.searchHighBound(a,6, 8));
    printf("%d=-1\n", sol.searchHighBound(a,6, 9));
    printf("%d=5\n", sol.searchHighBound(a,6, 10));
    printf("%d=-1\n", sol.searchHighBound(a,6, 11));
    getchar();
    return 0;
}