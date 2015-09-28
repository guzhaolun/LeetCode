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

	//divide and conquer，用快排中的partition部分,平均复杂度O(n)
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
			//实际上用left=temp1和right=temp2,在下面更temp1和temp2会看着简洁一些，每次只用更新一个值
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
			else if (left - pivotIndex + 1>k)//前半部分
			{
				right = left-1;
				left = temp1;
				
			}
			else
			{
				k = k - left - 1+pivotIndex;//后半部分
				left = right+2;
				right = temp2;
			}
		}
	}

	//最小堆，nlgk，但是为啥比排序的慢。。
	int findKthLargest3(vector<int>& nums, int k)
	{
		priority_queue<int,vector<int>, greater<int> > heap;
		for (int i = 0; i < k; i++)
		{
			heap.push(nums[i]);
		}
		for (int i = k; i < nums.size(); i++)
		{
			//比堆顶大的才替换，加上这个快了点，跟上面快排的时间一样。。
			if (nums[i]>heap.top())
			{
				heap.push(nums[i]);
				heap.pop();
			}
		}
		return heap.top();
	}
};