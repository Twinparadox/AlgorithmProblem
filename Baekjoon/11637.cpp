#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, arr[10], sum = 0, maj = -1, majIdx;
		cin >> n;	
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			if (maj < arr[i])
				maj = arr[i], majIdx = i;
		}
		sort(arr, arr + n);
		if (maj == arr[n - 2])
			cout << "no winner\n";
		else if (maj > (double)sum / 2)
			cout << "majority winner " << majIdx + 1 << '\n';
		else
			cout << "minority winner " << majIdx + 1 << '\n';
	}
}
