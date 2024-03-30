#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	int n, sum = 0, k, idx, i, size;
	cin >> n;
	for (k = 1; k <= 32; k++)
	{
		sum += pow(2, k);
		if (sum >= n)
			break;
	}
	
	idx = n - pow(2, k) + 1;
	vector<int> arr(k, 0);
	i = 0, size = arr.size();
	while (idx>0)
	{
		arr[size - 1 - i] = idx % 2;
		idx /= 2, i++;
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 1)
			cout << 7;
		else
			cout << 4;
	}
}
