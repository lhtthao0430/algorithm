#include <iostream>
using namespace std;
void DFS(long long a[100][100], long long N, long long i, long long check[], long long trace[]) {
	long long j;
	if (!check[i]) {
		check[i] = 1;
		for (j = 1; j <= N; j++)
			if (a[i][j] && !check[j]) {
				trace[j] = i;
				DFS(a, N, j, check, trace);
			}
	}
}

void main() {
	long long N, M, S, G, i, j, x, y;
	long long a[100][100], trace[100], check[100];
	cin >> N >> M >> S >> G;
	for (i = 0; i <= N; i++) {
		trace[i] = 0;
		check[i] = 0;
		for (j = 0; j <= N; j++)
			a[i][j] = 0;
	}
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	DFS(a, N, S, check, trace);
	if (trace[G] == 0)
		cout << false;
	else {
		i = G;
		cout << G << " ";
		while (trace[i] != S) {
			cout << trace[i] << " ";
			i = trace[i];
		}
		cout << S;
	}
	system("pause");
}