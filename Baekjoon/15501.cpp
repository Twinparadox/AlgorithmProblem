#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> input(N);
	int start = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
		if (input[i] == arr[0])
		{
			start = i;
		}
	}

	bool check = false;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != input[(start + i) % N])
		{
			check = true;
			break;
		}
	}
	if (check == false)
	{
		cout << "good puzzle";
	}
	else
	{
		reverse(input.begin(), input.end());
		start = (N - 1) - start;
		check = false;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] != input[(start + i) % N])
			{
				check = true;
				break;
			}
		}
		if (check == false)
		{
			cout << "good puzzle";
		}
		else
		{
			cout << "bad puzzle";
		}
	}
}