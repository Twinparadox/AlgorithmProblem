#include <iostream>
#include <stack>
using namespace std;
typedef struct _node
{
	int height;
	int idx;
}node;

int n, rec[500002];
node arr[500002];

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].height;
		arr[i].idx = i;
		rec[i] = -1;
	}

	stack<node> s;
	int cnt = 1, bot = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s.empty())
		{
			s.push(arr[i]);
		}
		else if (arr[i].height <= s.top().height)
		{
			rec[i] = s.top().idx;
			s.push(arr[i]);
		}
		else if (arr[i].height>s.top().height)
		{
			while (!s.empty() && !(arr[i].height <= s.top().height))
			{
				if (arr[i].height <= s.top().height)
				{
					rec[i] = s.top().idx;
					s.push(arr[i]);
				}
				else
					s.pop();
			}
			if (s.empty())
				s.push(arr[i]);
			else
			{
				rec[i] = s.top().idx;
				s.push(arr[i]);
			}
		}
		if (rec[i] == -1)
			cout << "0" << " ";
		else
			cout << rec[i] << " ";
	}
}