#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
	int N, ans = 0;
	cin >> N;
	while (N--)
	{
		string str;
		stack<char> st;
		cin >> str;

		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			char c = str[i];

			if (st.size() > (len - i))
				break;
			if (st.size() == 0)
				st.push(c);
			else if (st.top() == c)
				st.pop();
			else
				st.push(c);
		}

		if (st.size() == 0)
			ans++;
	}
	cout << ans;
}