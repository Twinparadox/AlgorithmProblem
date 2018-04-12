#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(void)
{
	char arr[31];
	stack<char> st;
	int tmp = 1, sum = 0;

	cin >> arr;
	for (int i = 0; arr[i]; i++)
	{
		if (arr[i] == '(')
		{
			tmp *= 2;
			st.push('(');
		}
		else if (arr[i] == '[')
		{
			tmp *= 3;
			st.push('[');
		}
		else if (arr[i] == ')')
		{
			if (arr[i - 1] == '(')
				sum += tmp;
			if (st.top() == '(')
				st.pop();
			tmp /= 2;
		}
		else
		{
			if (arr[i - 1] == '[')
				sum += tmp;
			if (st.top() == '[')
				st.pop();
			tmp /= 3;
		}
	}
	if (st.empty())
		cout << sum;
	else
		cout << 0;
}
