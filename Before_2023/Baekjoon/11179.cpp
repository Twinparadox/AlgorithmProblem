#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	int n, size, sum = 0;
	vector<int> arr;
	cin >> n;
	while (n >= 2)
	{
		arr.push_back(n % 2);
		n /= 2;
	}
	arr.push_back(n);
	size = arr.size();
	for (int i = 0; i < size; i++)
		sum += pow(2, size - i - 1)*arr[i];
	cout << sum;
}
