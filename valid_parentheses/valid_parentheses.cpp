#include "../common.h"

bool valid_parentheses(std::string s)
{
	stack<char> stk;
	for (int i = 0; i < s.length(); i++)
	{
		char input = s[i];
		if (input == '(' || input == '[' || input == '{')
		{
			stk.push(input);
		}
		else
		{
			char stackTop = stk.top();
			if (stackTop == '(' && input == ')')
			{
				stk.pop();
			}
			else if (stackTop == '{' && input == '}')
			{
				stk.pop();
			}
			else if (stackTop == '[' && input == ']')
			{
				stk.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return stk.empty();
}

int main()
{
	cout << valid_parentheses("([][]{}){}{") << endl;
}
