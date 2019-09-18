#include <iostream>
#include <queue>
using namespace std;

void BFS(long long a[100][100], long long N, long long M, long long S, long long G, long long trace[], long long check[100][100]){
	long long i, j;
	queue <long long> q;
	q.push(S);
	while (!q.empty()) {
		i = q.front();
		for (j = 0; j <= N; j++)
			if (a[i][j] && !check[i][j]) {
				check[i][j] = 1;
				trace[j] = i;
				if (j == G)
					return;
				q.push(j);
			}
		q.pop();
	}
}

void main() {
	long long N, M, S, G, i, j, x, y;
	long long a[100][100], check[100][100];
	long long trace[100];
	cin >> N >> M >> S >> G;
	for (i = 0; i <= N; i++) {
		trace[i] = 0;
		for (j = 0; j <= N; j++) {
			a[i][j] = 0;
			check[i][j] = 0;
		}
	}
	for (j = 0; j < M; j++){
		cin >> x >> y;
		a[x][y] = 1;
	}
	BFS(a, N, M, S, G, trace, check);
	if (trace[G] == 0)
		cout << false;
	else {
		i = G;
		while (trace[i] != S) {
			cout << trace[i] << " ";
			i = trace[i];
		}
		cout << S;
	}
	system("pause");
}