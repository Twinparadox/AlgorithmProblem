#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N, T;
vector<int> weight;
vector<int> ball;
vector<vector<bool> > dp;
void measure(int curN, int curWeight)
{
	if (curN > N)
		return;

	bool flag = dp[curN][curWeight];
	if (flag)
		return;

	dp[curN][curWeight] = true;

	measure(curN + 1, curWeight + weight[curN]);
	measure(curN + 1, curWeight);
	measure(curN + 1, abs(curWeight - weight[curN]));
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	weight = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
		cin >> weight[i];

	cin >> T;
	ball = vector<int>(T, 0);
	for (int i = 0; i < T; i++)
		cin >> ball[i];

	dp = vector<vector<bool> >(N + 1, vector<bool>(N * 500 + 1, false));

	measure(0, 0);

	for (int i = 0; i < T; i++)
	{
		if (ball[i] > N * 500)
			cout << "N ";
		else if (dp[N][ball[i]])
			cout << "Y ";
		else
			cout << "N ";
	}
}