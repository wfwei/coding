#include<iostream>
using namespace std;
 
class Solution {
 
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        double res = findKLargest(A, 0, m-1, B, 0, n-1, (m+n+1)/2);
        if((m+n)%2==0){
          res += findKLargest(A, 0, m-1, B, 0, n-1, (m+n)/2+1);
          res /= 2;
        }
        return res;
    }
 
private:
    // find the k(>=1) largest in sorted array A and B
    double findKLargest(int A[], int as, int ae, int B[], int bs, int be, int k){
 
        if(ae<as)
            return B[bs+k-1];
        if(be<bs)
            return A[as+k-1];
 
        int amid = (as+ae)/2;
        int bmid = findClosest(B, bs, be, A[amid]);
 
 
        int sc = amid-as + 1;
        if(bmid>=bs)
          sc += bmid-bs+1;
 
        if(sc<k)
            return findKLargest(B, bmid+1, be, A, amid+1, ae, k-sc);
        else if(sc>k)
            return findKLargest(B, bs, bmid, A, as, amid-1, k);
        else
            return A[amid];
    }
 
    // use quick search to find val in sorted array A(from s to e ascend)
    // if found return the index
    // else return the index of value which is closest to val and  lower than val
    int findClosest(int A[], int s, int e, int val){
 
        int low=s, high=e;
        while(low<high){
            int mid = (low + high)/2;
            if(A[mid]==val)
                return mid;
            if(A[mid]>val)
                high = mid-1;
            else
                low = mid+1;
        }
        if(A[low]>val)
            return low-1;
        else
            return low;
    }
};
 
int main() {
  Solution sol;
  int A[] = {1,2}, m=0;
  int B[] = {3,4,5}, n=2;
  double res = sol.findMedianSortedArrays(A, m, B, n);
  cout << "result:" << res;
  return 0;
}
