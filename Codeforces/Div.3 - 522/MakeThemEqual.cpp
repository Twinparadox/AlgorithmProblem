#include <iostream>
#include <set>
using namespace std;
int main(void)
{
	set<int> st;
	int min = 101, max = 0, ans, cur, ansMin = 0;
	int arr[101], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		st.insert(arr[i]);
	}

	if (st.size() > 3)
		cout << -1;
	else
	{
		ans = 101;
		for (cur = max; cur >= ansMin; cur--)
		{
			if ((max - cur != min + cur) && (max - cur != min) && (max != min + cur))
				continue;
			else
			{
				if (st.size() == 3)
				{
					int another;
					for (set<int>::iterator it = st.begin(); it != st.end(); it++)
						if (*it != max && *it != min)
							another = *it;

					if ((max - cur != another + cur) && (max - cur != another) && (max != another + cur))
						continue;
				}
				if (ans > cur)
					ans = cur;
			}
		}
		if (ans == 101)
			cout << -1;
		else
			cout << ans;
	}
}