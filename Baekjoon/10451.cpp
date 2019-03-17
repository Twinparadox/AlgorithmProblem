#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<bool> check;
void sequence(int idx)
{
	if (check[idx] == false)
	{
		check[idx] = true;
		sequence(arr[idx]);
	}
	else
		return;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, cycle = 0;
		cin >> N;
		arr = vector<int>(N + 1, 0);
		check = vector<bool>(N + 1, false);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		for (int i = 1; i <= N; i++)
		{
			if (check[i] == false)
			{
				cycle++;
				sequence(i);
			}
		}

		cout << cycle << '\n';
	}
}