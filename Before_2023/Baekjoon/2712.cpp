#include <iostream>
#include <string>
#define KGLB 2.2046
#define LBKG 0.4536
#define LG 0.2642
#define GL 3.7854
using namespace std;
int main(void)
{
	int t;
	double n, result = 0;
	string s;
	cin >> t;
	cout.precision(4);
	while (t--)
	{
		cin >> n >> s;
		if (s == "kg")
			result = KGLB*(double)n, cout << fixed << result << " lb\n";
		else if (s == "lb")
			result = LBKG*(double)n, cout << fixed << result << " kg\n";
		else if (s == "l")
			result = LG*(double)n, cout << fixed << result << " g\n";
		else
			result = GL*(double)n, cout << fixed << result << " l\n";
	}
}
