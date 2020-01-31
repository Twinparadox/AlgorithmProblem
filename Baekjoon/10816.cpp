#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	map<int, int> plusCard;
	map<int, int> minusCard;

	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] >= 0)
		{
			if (!plusCard.count(arr[i]))
				plusCard[arr[i]] = 1;
			else
				plusCard[arr[i]] = plusCard[arr[i]] + 1;
		}
		else
		{
			if (!minusCard.count(-arr[i]))
				minusCard[-arr[i]] = 1;
			else
				minusCard[-arr[i]] = minusCard[-arr[i]] + 1;
		}
	}

	cin >> M;
	vector<int> own(M);
	for (int i = 0; i < M; i++)
	{
		cin >> own[i];
		if (own[i] >= 0)
		{
			if (plusCard.count(own[i]))
				cout << plusCard[own[i]] << ' ';
			else
				cout << "0 ";
		}
		else
		{
			if (minusCard.count(-own[i]))
				cout << minusCard[-own[i]] << ' ';
			else
				cout << "0 ";
		}
	}
}