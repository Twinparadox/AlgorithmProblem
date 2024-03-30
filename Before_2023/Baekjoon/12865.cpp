#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<pair<int, int> > arr(N);
	vector<int> bags(K + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < N; i++)
		for (int j = K; j >= arr[i].first; j--)
			if (bags[j - arr[i].first] + arr[i].second > bags[j])
				bags[j] = bags[j - arr[i].first] + arr[i].second;

	int max = 0;
	for (int i = 0; i <= K; i++)
		if (max < bags[i])
			max = bags[i];

	cout << max;
}