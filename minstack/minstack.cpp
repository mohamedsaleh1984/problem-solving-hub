#include <iostream>
#include <stack>
using namespace std;
//
//class MinStack {
//public:
//	int pop() {
//		int elem = S.top();
//		S.pop();
//		return elem;
//	}
//
//	void push(int elem) {
//		if (S.empty())
//			S.push(elem);
//		else
//		{
//			int top = S.top();
//			if (elem > top) {
//				stack<int> s2;
//				while (elem >  S.top()) {
//					int c = S.top();
//					S.pop();
//					s2.push(c);
//				}
//				S.push(elem);
//
//				while (!s2.empty())
//				{
//					int c = s2.top();
//					s2.pop();
//					S.push(c);
//				}
//			}
//			else
//			{
//				S.push(elem);
//			}
//		}
//
//	}
//
//private:
//	stack<int> S;
//};

class MinStack {
public:
	MinStack() {

	}

	void push(int elem) {
		if (S.empty()) {
			S.push(elem);
			return;
		}

		int top = S.top();
		if (elem > top) {
			stack<int> s2;
			while (elem > S.top()) {
				int c = S.top();
				S.pop();
				s2.push(c);
				if (S.size() == 0)
					break;
			}

			S.push(elem);

			while (!s2.empty())
			{
				int c = s2.top();
				s2.pop();
				S.push(c);
			}
			return;
		}
		else {
			S.push(elem);
		}
		
	}

	void pop() {
		if (!S.empty())
			S.pop();
	}

	int top() {
		if (S.empty())
			return NULL;
		return S.top();
	}

	int getMin() {
		return S.top();
	}
private:
	stack<int> S;
};

/*
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

*/
int main() {

	MinStack ms;
	ms.push(-2);
	ms.push(0);
	ms.push(-3);
	cout << ms.getMin() << endl;
	ms.pop();
	cout << ms.top() << endl;
	cout << ms.getMin() << endl;
	return 0;
}