#include <stack>
using namespace std;
class Queue {
	stack<int> s1;
	stack<int> s2;
	int size = 0;
public:
	// Push element x to the back of queue.
	void push(int x) {
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.push(x);
		size++;
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		s1.pop();
		size--;
	}

	// Get the front element.
	int peek(void) {
		return s1.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return size == 0;
	}
};