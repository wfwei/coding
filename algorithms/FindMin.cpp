#include "stdio.h"
#include "stdlib.h"
// 旋转有序数组找最小值
int getMaxIdx(int *A, int len){
	int low=0, high=len-1, mid;
	while(low<high){
	    mid = low + (high-low + 1)/2;
		if(A[mid]>A[low])
			low = mid;
		else
			high = mid-1;
	}
	return low;
}

int getMin(int *A, int len){
	if(A==NULL)
		return 0;
	int maxIdx = getMaxIdx(A, len);
	int minIdx = (maxIdx + 1)%len;
	return A[minIdx];
}

//// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = getMin(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == NULL)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main()
{
	// 典型输入，单调升序的数组的一个旋转
    int array1[] = {3, 4, 5, 1, 2};
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = {3, 4, 5, 1, 1, 2};
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = {3, 4, 5, 1, 2, 2};
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = {1, 0, 1, 1, 1};
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = {1, 2, 3, 4, 5};
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = {2};
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入NULL
    Test(NULL, 0, 0);

	system("pause");
}
