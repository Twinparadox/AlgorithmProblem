#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
	char arr[10000];
	stack<char> st;
	int len;
	int c;

	cin >> c;
	while (c)
	{
		cin >> arr;
		len = (int)strlen(arr);

		st.push(arr[0]);
		for (int i = 1; i < len; i++)
		{
			if (!st.empty())
			{
				if (st.top() == '(' && arr[i] == ')')
					st.pop();
				else if (st.top() == '{' && arr[i] == '}')
					st.pop();
				else if (st.top() == '[' && arr[i] == ']')
					st.pop();
				else
					st.push(arr[i]);
			}
			else
				st.push(arr[i]);
		}
		if (st.empty())
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
			while (!st.empty())
			{
				st.pop();
			}
		}
		c--;
	}
	return 0;
}
