#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string.h>

using namespace std;
char str[36];
//°è»ê¹ý (()[])() -> (())([])()
int main()
{
	stack<char>Stack;
	cin >> str;
	int mul = 1, sum = 0;
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] == '(')
		{
			Stack.push(str[i]);
			mul *= 2;
			if (str[i + 1] == ')')sum += mul;
		}
		else if (str[i] == '[')
		{
			Stack.push(str[i]);
			mul *= 3;
			if (str[i + 1] == ']')sum += mul;
		}
		else if (str[i] == ')')
		{
			if (!Stack.empty())
			{
				if (Stack.top() == '(') {
					Stack.pop();
					mul /= 2;
				}
			}
			else { Stack.push(str[i]); }
		}
		else if (str[i] == ']' )
		{
			if (!Stack.empty())
			{
				if (Stack.top() == '[') {
					Stack.pop();
					mul /= 3;
				}
			}
			else { Stack.push(str[i]); }
		}
	}
	if (Stack.empty())cout << sum << "\n";
	else cout << 0 << "\n";
}