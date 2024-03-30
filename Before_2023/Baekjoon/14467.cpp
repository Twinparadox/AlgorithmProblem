#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr(11, -1);
	int n, num, p, cnt = 0;
	cin >> n;
	while (n--)
	{
		cin >> num >> p;
		if (arr[num] == -1)
			arr[num] = p;
		else
			if (arr[num] != p)
				arr[num] = p, cnt++;
	}
	cout << cnt;
}
