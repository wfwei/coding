class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return findMedianSortedArrays(A, 0, m-1, B, 0, n-1, (m+n)/2);
        
    }
    
private:
    
    double findMedianSortedArrays(int A[], int as, int ae, int B[], int bs, int be, int mid){
        
        if(ae<as)
            return B[(be+bs)/2];
        if(be<bs)
            return A[(ae+as)/2];

        int amid = (as+ae)/2;
        int bmid = findClosest(B, bs, be, A[amid]);
        
        int sc = amid + bmid;
        
        if(sc<mid)
            return findMedianSortedArrays(A, amid+1, ae, B, bmid+1, be, mid-sc);
        else if(sc>mid)
            return findMedianSortedArrays(B, bs, bmid-1, A, as, amid-1, mid);
        else
            return A[amid];        
    }
    
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
        if(A[low]>val && low>s)
            return low-1;
        else
            return low;
        
    }
};