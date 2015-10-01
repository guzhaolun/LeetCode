class Solution {
public:
	//https://en.wikipedia.org/wiki/Digital_root
	//digit root,很多性质，可以看看wiki介绍
	int addDigits(int num) {
		return num - 9 * ((num - 1) / 9);
		//return 1+((num-1)%9);
	}
};