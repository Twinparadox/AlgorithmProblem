#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;
	vector<string> source(N);
	vector<string> dest(N);
	for (int i = 0; i < N; i++)
		cin >> source[i];
	for (int i = 0; i < N; i++)
		cin >> dest[i];

	for (int i = 0; i < N; i++)
	{
		bool isEyfa = true;
		for (int j = 0; j < M && isEyfa; j++)
			if (source[i][j] != dest[i][j * 2] || source[i][j] != dest[i][j * 2 + 1])
				isEyfa = false;
		if (!isEyfa)
		{
			cout << "Not Eyfa\n";
			return 0;
		}
	}
	cout << "Eyfa\n";
}