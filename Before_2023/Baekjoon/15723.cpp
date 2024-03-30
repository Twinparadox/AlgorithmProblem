#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 1e7 + 1, SIZE = 26;
int n;
vector<vector<int> > graph;
void Floyd()
{
	for (int k = 0; k < SIZE; k++)
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;

	graph = vector<vector<int> >(SIZE, vector<int>(SIZE, INF));
	for (int i = 0; i < SIZE; i++)
		graph[i][i] = 0;

	cin.ignore();
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		int v1 = str[0] - 'a', v2 = str[5] - 'a';
		graph[v1][v2] = 1;
	}

	Floyd();

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		int v1 = str[0] - 'a', v2 = str[5] - 'a';
		if (graph[v1][v2] != INF)
			cout << "T\n";
		else
			cout << "F\n";
	}
}