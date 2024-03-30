#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr;
	int tmp, cnt = 0, size;
	while (1)
	{
		cin >> tmp;
		if (tmp == -1)
			break;
		else if (tmp == 0)
		{
			size = arr.size();
			for (int i = 0; i < size; i++)
				for (int j = i + 1; j < size; j++)
					if (arr[i] == arr[j] * 2 || arr[j] == arr[i] * 2)
						cnt++;
			cout << cnt << '\n';
			cnt = 0;
			arr.clear();
		}
		else
			arr.push_back(tmp);
	}
}
