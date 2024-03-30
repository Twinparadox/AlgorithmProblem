#include <iostream>
using namespace std;
int main(void)
{
	int P;
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		int N;
		double D, A, B, F, time = 0.0;
		cin >> N >> D >> A >> B >> F;

		time = D / (A + B);

		cout << N << ' ' << F * time << '\n';
	}
}