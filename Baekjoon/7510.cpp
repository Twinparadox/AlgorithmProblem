#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		vector<long long> arr(3);
		for (int j = 0; j < 3; j++)
			cin >> arr[j];

		sort(arr.begin(), arr.end());

		cout << "Scenario #" << i << ":\n";
		if (arr[2] * arr[2] == (arr[0] * arr[0] + arr[1] * arr[1]))
			cout << "yes\n\n";
		else
			cout << "no\n\n";
	}
}