#include <iostream>
using namespace std;
int main(void)
{
	int n, student, apple, sum = 0;
	cin >> n;
	while (n--)
	{
		cin >> student >> apple;
		sum += apple % student;
	}
	cout << sum;
}
