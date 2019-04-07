#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct user
{
	vector<int> card;
	int su;
	int idx;
};
bool compare(const struct user a, const struct user b)
{
	if (a.su > b.su)
		return true;
	else if (a.su == b.su)
		return a.idx > b.idx;
	else
		return false;
}
int main(void)
{
	int N, deckSize = 5;
	cin >> N;

	vector<struct user> arr(N, { vector<int>(deckSize),0,0 });
	for (int i = 0; i < N; i++)
	{
		int tmp;
		for (int j = 0; j < deckSize; j++)
		{
			cin >> tmp;
			arr[i].card[j] = tmp;
			arr[i].idx = i + 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int first = 0; first < deckSize; first++)
		{
			if (arr[i].su == 9)
				break;
			for (int second = first + 1; second < deckSize; second++)
			{
				if (arr[i].su == 9)
					break;
				for (int third = second + 1; third < deckSize; third++)
				{
					int sum = arr[i].card[first] + arr[i].card[second] + arr[i].card[third];
					if (arr[i].su < (sum % 10))
						arr[i].su = (sum % 10);
					if (arr[i].su == 9)
						break;
				}
			}
		}
	}

	sort(arr.begin(), arr.end(), compare);
	cout << arr[0].idx;
}