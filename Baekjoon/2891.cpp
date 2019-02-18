#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, S, R, retire = 0;
	cin >> N >> S >> R;
	vector<int> team(N + 1, 1);
	vector<int> broken(S);
	vector<int> spare(R);
	for (int i = 0; i < S; i++)
	{
		cin >> broken[i];
		team[broken[i]]--;
	}
	for (int i = 0; i < R; i++)
	{
		cin >> spare[i];
		team[spare[i]]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (team[i] == 0)
		{
			if (i == 0 && team[i + 1] == 2)
				team[i + 1]--, team[i]++;
			else if (i == N && team[i - 1] == 2)
				team[i - 1]--, team[i]++;
			else
			{
				if (team[i - 1] == 2)
					team[i - 1]--, team[i]++;
				else if (team[i + 1] == 2)
					team[i + 1]--, team[i]++;
			}
		}
	}

	for (int i = 1; i <= N; i++)
		if (team[i] == 0)
			retire++;
	cout << retire;
}