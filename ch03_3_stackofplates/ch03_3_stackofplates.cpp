#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SetOfStacks {
public:
	void push(int input) {
		if (set.empty() || set[current].size() == MAX_CAPACITY) {
			current++;
			stack<int> s;
			s.push(input);
			set.push_back(s);
		}
		else {
			set[current].push(input);
		}
	}

	int pop() {
		if (current == -1 || set.size() == 0) {
			return INT_MIN;
		}

		if (set[current].empty()) {
			set.pop_back();
			current--;
		}

		if (current == -1) {
			return INT_MIN;
		}

		int val = set[current].top();
		set[current].pop();
		return val;
	}

	int stacksCount() {
		return set.size();
	}
private:
	vector<stack<int>> set;
	int MAX_CAPACITY = 3;
	int current = -1;
};
int main()
{
	SetOfStacks ss;
	ss.push(111);	ss.push(13);	ss.push(100);
	ss.push(31);	ss.push(51);	ss.push(71); 
	ss.push(16);	ss.push(1);

	cout << "Number of Stacks " << ss.stacksCount() << endl;
	
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;
	cout << ss.pop() << endl;

	/* << "\t" << ss.pop() << "\t" << ss.pop() << "\t" << ss.pop() << "\t"<< ss.pop() <<  endl;
	cout << ss.pop() << "\t" << ss.pop() << "\t" << ss.pop() << "\t" << ss.pop() << "\t" << ss.pop() << endl;*/

	return 0;
}
