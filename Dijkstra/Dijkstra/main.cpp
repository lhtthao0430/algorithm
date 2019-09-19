#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void Dijkstra(long long a[100][100], long long N, long long S, long long G, long long trace[], long long check[], long long len[]) {
	long long i, j;
	deque <long long> q;
	q.push_back(S);
	while (!q.empty()) {
		i = q.front();
		check[i] = 1;
		q.pop_front();
		for (j = 0; j <= N; j++)
			if (a[i][j] && !check[j]) {
				if (len[i] + a[j][j] < len[j]) {
					trace[j] = i;
					len[j] = len[i] + a[i][j];
				}
				if (q.empty() || a[i][j] <= a[i][q.front()])
					q.push_front(j);
				else if (a[i][j] >= a[i][q.back()])
					q.push_back(j);
			}
	}

}

void main() {
	long long N, M, S, G, i, j, x, y, z, maxValue;
	long long a[100][100];
	long long trace[100], check[100], len[100];
	cin >> N >> M >> S >> G;
	for (i = 0; i <= N; i++) {
		trace[i] = 0;
		check[i] = 0;
		for (j = 0; j <= N; j++)
			a[i][j] = 0;
	}
	maxValue = 0;
	for (j = 0; j < M; j++) {
		cin >> x >> y >> z;
		a[x][y] = z;
		maxValue += z;
	}

	for (i = 1; i <= N; i++)
		len[i] = maxValue;
	len[S] = 0;
	Dijkstra(a, N, S, G, trace, check, len);
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