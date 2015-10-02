#include <vector>
using namespace std;
class Solution260
{
public:
	//分成两组，每组2*n+1个数，就成了single number 1;
	//这两个数肯定不相同，将所有数异或，找到结果中相反的最低位，根据此位将数据分为两组分别异或
	vector<int> singleNumber(vector<int>& nums)
	{
		int len = nums.size();
		int AxorB = 0;
		for (int i = 0; i<len; i++){
			AxorB ^= nums[i];
		}
		int mask = AxorB & (~(AxorB - 1));
		int A = 0;
		int B = 0;
		for (int i = 0; i<len; i++){
			if ((mask&nums[i]) == 0){
				A ^= nums[i];
			}
			else{
				B ^= nums[i];
			}
		}
		return vector<int>({ A, B });
	}
};