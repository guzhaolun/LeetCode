#include <queue>
using namespace std;
class Stack {
public:
	queue<int> q;
	int size = 0;
public:
	// Push element x onto stack.
	//添加一个新的都将旧的放到后面。push:O(n), pop:O(1), top:O(1)
	void push(int x) {
		q.push(x);
		size++;
		for (int i = 0; i < size - 1; i++)
		{
			int a = q.front();
			q.pop();
			q.push(a);
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		q.pop();
		size--;
	}

	// Get the top element.
	int top() {
		return q.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return size == 0;
	}
};