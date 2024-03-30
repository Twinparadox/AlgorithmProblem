#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	string arr[3];
	string color[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	long long sum = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] == color[j])
			{
				if (i == 0)
					sum += j * 10;
				else if (i == 1)
					sum += j;
				else
					sum *= pow(10, j);
			}
		}
	}
	cout << sum;
}
