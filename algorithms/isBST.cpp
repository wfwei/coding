#include "stdio.h"
#include "stdlib.h"
// 判断一个数字序列是BST后序遍历的结果
// 认为没有重复元素
bool isBST(int *A, int s, int e){
	if(A==NULL)
		return 0;
	bool bst = true;
	int root = A[e], ls, le, rs, re;
	rs = e; re = e-1;
	while(A[rs-1]>root && rs>s)
		rs --;
	ls =rs; le = rs-1;
	while(A[ls-1]<root && ls>s)
		ls --;
	if(ls>s)
		bst = false;
	if(bst && le>=ls)
		bst = isBST(A, ls, le);
	if(bst && re>=rs)
		bst = isBST(A, rs, re);
	return bst;
}

//// ====================测试代码====================
void Test(char* testName, int sequence[], int length, bool expected)
{
	if(testName != NULL)
		printf("%s begins: ", testName);

	if(isBST(sequence, 0, length-1) == expected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	int data[] = {4, 8, 6, 12, 16, 14, 10};
	Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
	int data[] = {4, 6, 7, 5};
	Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
	int data[] = {1, 2, 3, 4, 5};
	Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
	int data[] = {5, 4, 3, 2, 1};
	Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
	int data[] = {5};
	Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
	int data[] = {7, 4, 6, 5};
	Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
	int data[] = {4, 6, 12, 8, 16, 14, 10};
	Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
	Test("Test8", NULL, 0, false);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	system("pause");
}