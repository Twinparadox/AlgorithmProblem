#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct team
{
	int id;
	int submit;
	int last;
	vector<int> problem;
	int sum;
};
bool compare(struct team a, struct team b)
{
	if (a.sum > b.sum)
		return true;
	else if (a.sum == b.sum)
	{
		if (a.submit < b.submit)
			return true;
		else if (a.submit == b.submit)
		{
			if (a.last < b.last)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		vector<struct team> arr(n);

		for (int i = 0; i < n; i++)
		{
			arr[i].id = i + 1;
			arr[i].submit = 0;
			arr[i].last = 0;
			arr[i].problem = vector<int>(k, 0);
			arr[i].sum = 0;
		}

		int tID, pID, score;
		for (int i = 0; i < m; i++)
		{
			cin >> tID >> pID >> score;
			if (arr[tID - 1].problem[pID - 1] < score)
				arr[tID - 1].problem[pID - 1] = score;
			arr[tID - 1].submit++;
			arr[tID - 1].last = i;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
				arr[i].sum += arr[i].problem[j];
		sort(arr.begin(), arr.end(), compare);

		int rank = 0;
		for (rank = 0; rank < n; rank++)
			if (arr[rank].id == t)
				break;
		cout << rank + 1 << '\n';
	}
}