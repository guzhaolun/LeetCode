#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <functional>
#include <stack>
using namespace std;

//c++ 里面的堆用priority_queue。
//每次都make_heap的话会超时。
class MinStack {
private:
	vector<int> s;
	int minval = INT_MAX;
	priority_queue<int, vector<int>, greater<int>> forMin;
public:
	void push(int x) {
		s.push_back(x);
		minval = min(minval, x);
		forMin.push(x);
	}

	void pop() {
		if (!s.empty())
		{
			if (s.back() == forMin.top())
				forMin.pop();
			s.pop_back();
			if (!forMin.empty())
				minval = forMin.top();
		}
	}

	int top() {
		return s.back();
	}

	int getMin() {
		return minval;
	}
};

//居然可以直接拿stack来实现。。
//就是只压栈比栈顶小的元素，但是时间上好像并没有提高，空间可能少点。
class MinStack {
private:
	std::stack<int> stack;
	std::stack<int> min_stack;
public:
	void push(int x) {
		stack.push(x);
		if (min_stack.empty() || ((!min_stack.empty()) && x <= min_stack.top())) {  //NOTE: 是“小于等于”，不是“小于”
			min_stack.push(x);
		}
	}

	void pop() {
		if (!stack.empty()) {
			if (stack.top() == min_stack.top())
				min_stack.pop();
			stack.pop();
		}
	}

	int top() {
		if (!stack.empty())
			return stack.top();
	}

	int getMin() {
		if (!min_stack.empty())
			return min_stack.top();
	}
};
