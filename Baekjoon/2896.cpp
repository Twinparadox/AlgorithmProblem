#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	double fruit[3], ratio[3], make[3], list[3], min;
	cout.precision(9);
	for (int i = 0; i < 3; i++)
		cin >> fruit[i];
	for (int i = 0; i < 3; i++)
		cin >> ratio[i], list[i] = make[i] = (double)fruit[i] / (double)ratio[i];
	if (fruit[0] < ratio[0] || fruit[1] < ratio[1] || fruit[2] < ratio[2])
		cout << fruit[0] << " " << fruit[1] << " " << fruit[2] << " ";
	else
	{
		sort(list, list + 3);
		min = list[0];
		for (int i = 0; i < 3; i++)
			cout << (double)(fruit[i] - min*ratio[i]) << " ";
	}
}
