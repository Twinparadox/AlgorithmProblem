#include <iostream>
using namespace std;
int graph[100][100], n;
void Floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];

	Floyd();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << graph[i][j] << ' ';
		cout << '\n';
	}
}
