#include <iostream>
#include <queue>
using namespace std;

void BFS(long long a[100][100], long long N, long long S, long long G, long long trace[], long long check[]){
	long long i, j;
	queue <long long> q;
	q.push(S);
	while (!q.empty()) {
		i = q.front();
		check[i] = 1;
		for (j = 0; j <= N; j++)
			if (a[i][j] && !check[j]) {
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
	long long a[100][100];
	long long trace[100], check[100];
	cin >> N >> M >> S >> G;
	for (i = 0; i <= N; i++) {
		trace[i] = 0;
		check[i] = 0;
		for (j = 0; j <= N; j++)
			a[i][j] = 0;
	}
	for (j = 0; j < M; j++){
		cin >> x >> y;
		a[x][y] = 1;
	}
	BFS(a, N, S, G, trace, check);
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