//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//double findKth(int a[], int m, int b[], int n, int k)
//{
//	if (n<m)
//		return findKth(b, n, a, m, k);
//	if (m == 0)
//		return b[k - 1];
//	if (k == 1)
//		return min(a[0], b[0]);
//	int pa = min(m, k / 2);
//	int pb = k - pa;
//	if (a[pa - 1] < b[pb - 1])
//		return findKth(a + pa, m - pa, b, n, k - pa);
//	else if (a[pa - 1] > b[pb - 1])
//		return findKth(a, m, b + pb, n - pb, k - pb);
//	else
//		return a[pa - 1];
//}
//double findMedianSortedArrays(int A[], int m, int B[], int n) {
//	/*int i = m / 2, j = n / 2;
//	double median_a = m % 2 == 0 ? (A[m / 2 - 1] + A[m / 2]) / 2.0 : A[m / 2];
//	double median_b = n % 2 == 0 ? (B[n / 2 - 1] + B[n / 2]) / 2.0 : B[n / 2];
//	
//	if (median_a == median_b)
//		return median_a;
//	if (m == 0)
//		return median_b;
//	if (n == 0)
//		return median_a;
//	if (i == 0)
//	{
//		if (m == 0)
//			return median_b;
//		else
//		if (n == 1)
//			return (median_a + median_b) / 2.0;
//		if (A[0] < median_b)
//			return n % 2 == 0 ? (A[0] < B[n / 2 - 1] ? B[n / 2 - 1] : A[0]) : ((A[0]<B[n / 2 - 1] ? B[n / 2 - 1] : A[0]) + B[n / 2]) / 2.0;
//		else
//			return n % 2 == 0 ? (A[0] > B[n / 2] ? B[n / 2] : A[0]) :( (A[0] < B[n / 2 + 1] ? A[0] : B[n / 2 + 1]) + B[n / 2]) / 2.0;
//	}
//	if (j == 0)
//	{
//		if (n == 0)
//			return median_a;
//		else
//		if (m == 1)
//			return (median_a + median_b) / 2.0;
//		if (B[0] < median_a)
//			return m % 2 == 0 ? (B[0] < A[m / 2 - 1] ? A[m / 2 - 1] : B[0]) :((B[0]<A[m / 2 - 1] ? A[m / 2 - 1] : B[0]) + A[m / 2]) / 2.0;
//		else
//			return m % 2 == 0 ? (B[0] > A[m / 2] ? A[m / 2] : B[0]) : ((B[0] < A[m / 2 + 1] ? B[0] : A[m / 2 + 1]) + A[m / 2]) / 2.0;
//	}
//	if (median_a < median_b)
//	{
//
//		return findMedianSortedArrays(&A[m / 2], m % 2 == 0 ? m / 2 : m / 2 + 1, &B[0], n % 2 == 0 ? n / 2 : n / 2 + 1);
//	}
//	else
//		return findMedianSortedArrays(&A[0], m % 2 == 0 ? m / 2 : m / 2 + 1, &B[n / 2], n % 2 == 0 ? n / 2 : n / 2 + 1);*/
//	//不要一开始在原始串中分割中值，应该找第k和第k+1大的数。否则处理的情况将非常多，就像我上面的解法。
//	int total = m + n;
//	if (total & 0x1)
//		return findKth(A, m, B, n, total / 2 + 1);
//	else
//		return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
//
//}
//
//int main()
//{
//	//int A[4] = { 1,2,3,4 };
//	//int B[7] = { 1, 2, 3, 4 ,5 ,6,7};
//	int A[2] = {1 ,2};
//	int B[4] = { 3,4 ,5,6};
//	double median=findMedianSortedArrays(A,2 ,B, 4);
//	cout << median << endl;
//	system("pause");
//	return 0;
//}