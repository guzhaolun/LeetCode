#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

class Solution215
{
public:
	//O(nlgn);
	int findKthLargest(vector<int>& nums, int k) 
	{
		sort(nums.begin(), nums.end(),cmp);
		return nums[k - 1];
	}
	static bool cmp(int &a, int &b)
	{
		return a > b;
	}

	//divide and conquer���ÿ����е�partition����,ƽ�����Ӷ�O(n)
	int findKthLargest2(vector<int>& nums, int k)
	{
		int pivotIndex = 0;
		int size = nums.size();
		k = size - k+1;
		int left = 1, right = size - 1;
		if (nums.size() == 1)
			return nums[0];
		while (1)
		{
			//ʵ������left=temp1��right=temp2,�������temp1��temp2�ῴ�ż��һЩ��ÿ��ֻ�ø���һ��ֵ
			int temp1 = left, temp2 = right;
			pivotIndex = left - 1;
			int pivot = nums[pivotIndex];
			while (left <= right)
			{
				while (left<=right&&nums[left]<=pivot)
					left++;
				while (right >= left&&nums[right]>pivot)
					right--;
				if (left<right)
				{
					swap(nums[left], nums[right]);
					left++;
					right--;
				}
			}
			left--;
			if (left == pivotIndex)
			{
				k--;
				if (k == 0)
					return nums[left];
				left+=2;
				right = temp2;
				continue;
			}
			swap(nums[left], nums[pivotIndex]);
			if (left-pivotIndex+1 == k)
				return nums[left];
			else if (left - pivotIndex + 1>k)//ǰ�벿��
			{
				right = left-1;
				left = temp1;
				
			}
			else
			{
				k = k - left - 1+pivotIndex;//��벿��
				left = right+2;
				right = temp2;
			}
		}
	}

	//��С�ѣ�nlgk������Ϊɶ�������������
	int findKthLargest3(vector<int>& nums, int k)
	{
		priority_queue<int,vector<int>, greater<int> > heap;
		for (int i = 0; i < k; i++)
		{
			heap.push(nums[i]);
		}
		for (int i = k; i < nums.size(); i++)
		{
			//�ȶѶ���Ĳ��滻������������˵㣬��������ŵ�ʱ��һ������
			if (nums[i]>heap.top())
			{
				heap.push(nums[i]);
				heap.pop();
			}
		}
		return heap.top();
	}
};