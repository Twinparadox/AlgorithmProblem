#include <iostream>
#include <vector>
using namespace std;
vector<int> happy;
vector<int> loss;
vector<vector<int> > d;
int N, life = 100;
int dp(int i, int l)
{
	if (d[i][l])
		return d[i][l];

	int ans1 = d[i][l], ans2, ans;

	if (i == N)
		return 0;
	if (l - loss[i] > 0)
		ans1 = dp(i + 1, l - loss[i]) + happy[i];
	ans2 = dp(i + 1, l);

	ans = ans1 < ans2 ? ans2 : ans1;
	return ans;
}
int main(void)
{
	cin >> N;

	happy.resize(N);
	loss.resize(N);
	d.resize(N + 1, vector<int>(life + 1, 0));

	for (int i = 0; i < N; i++)
		cin >> loss[i];
	for (int i = 0; i < N; i++)
		cin >> happy[i];

	cout << dp(0, 100);
}