class Solution {
public:
	//https://en.wikipedia.org/wiki/Digital_root
	//digit root,�ܶ����ʣ����Կ���wiki����
	int addDigits(int num) {
		return num - 9 * ((num - 1) / 9);
		//return 1+((num-1)%9);
	}
};