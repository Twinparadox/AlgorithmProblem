#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	for (int i = 1000; i < 10000; i++)
	{
		int dec, dodec, hexdec;

		int tmp = i, sum = 0;
		while (tmp > 0)
		{
			sum += tmp % 10;
			tmp /= 10;
		}
		dec = sum;

		tmp = i, sum = 0;
		while (tmp > 0)
		{
			sum += tmp % 12;
			tmp /= 12;
		}
		dodec = sum;

		if (dec != dodec)
			continue;

		tmp = i, sum = 0;
		while (tmp > 0)
		{
			sum += tmp % 16;
			tmp /= 16;
		}
		hexdec = sum;

		if (dec == hexdec)
			cout << i << '\n';
	}
}