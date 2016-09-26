#include <iostream>
#include <stack>
using namespace std;
typedef struct _node
{
	int height;
	int idx;
}node;

int n, view[100002];
node arr[100002];

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].height;
		arr[i].idx = i;
		view[i] = -1;
	}

	stack<node> s;
	int cnt = 1, bot = 0;
	for (int i = 1; i <= n; i++)
	{
		if (view[i] != -1)
			continue;
		if (s.empty())
		{
			bot = arr[i].height;
			s.push(arr[i]);
		}
		else if (arr[i].height <= s.top().height)
			s.push(arr[i]);
		else if (arr[i].height>s.top().height)
		{
			while (!s.empty() && !(arr[i].height <= s.top().height))
			{
				if (arr[i].height <= s.top().height)
					s.push(arr[i]);
				else
				{
					view[s.top().idx] = i;
					s.pop();
				}
			}
			if (s.empty())
				s.push(arr[i]);
			else
				s.push(arr[i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (view[i] == -1)
			cout << "0" << endl;
		else
			cout << view[i] << endl;
	}
}