#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int a, b, m, tmp = 0;
	cin >> a >> b >> m;
	vector<int> arr(m);
	vector<int> ans;

	for (int i = 0; i < m; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
		tmp += arr[i] * pow(a, m - 1 - i);
	while (tmp > 0)
	{
		ans.push_back(tmp % b);
		tmp /= b;
	}

	int size = ans.size();
	for (int i = 0; i < size; i++)
		cout << ans[size - 1 - i] << ' ';

}