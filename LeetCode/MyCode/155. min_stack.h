#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <functional>
#include <stack>
using namespace std;

//c++ ����Ķ���priority_queue��
//ÿ�ζ�make_heap�Ļ��ᳬʱ��
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

//��Ȼ����ֱ����stack��ʵ�֡���
//����ֻѹջ��ջ��С��Ԫ�أ�����ʱ���Ϻ���û����ߣ��ռ�����ٵ㡣
class MinStack {
private:
	std::stack<int> stack;
	std::stack<int> min_stack;
public:
	void push(int x) {
		stack.push(x);
		if (min_stack.empty() || ((!min_stack.empty()) && x <= min_stack.top())) {  //NOTE: �ǡ�С�ڵ��ڡ������ǡ�С�ڡ�
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
