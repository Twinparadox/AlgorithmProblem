#include <iostream>
using namespace std;
int main(void)
{
	int arr[10], size = 0, tmp;
	bool dif = false;
	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		if (size == 0)
			arr[size++] = tmp % 42;
		else
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[j] == tmp % 42)
				{
					dif = true;
					break;
				}
				else
					dif = false;
			}
			if (!dif)
				arr[size++] = tmp % 42;
		}
	}
	cout << size;
}
