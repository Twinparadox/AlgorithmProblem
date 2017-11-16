#include <iostream>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n, tmp, min = 10000000, max = -10000000;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> tmp, min = min < tmp ? min : tmp, max = max < tmp ? tmp : max;
	cout << min << " " << max;
}
