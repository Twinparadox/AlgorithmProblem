#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string arr[5];
	int size[5], max = 0, i, cnt = 0;
	for (i = 0; i < 5; i++)
	{
		getline(cin, arr[i]);
		size[i] = arr[i].size();
		if (max < size[i])
			max = size[i];
	}
	for (i = 0; i < max; i++)
		for(cnt=0;cnt<5;cnt++)
			if (size[cnt] > i)
				cout << arr[cnt][i];
}
