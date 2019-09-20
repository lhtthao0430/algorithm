#include <iostream>
using namespace std;

void Shift(int a[], int l, int r) {
	int x, i, j;
	i = l; j = 2 * i;
	x = a[i];
	while (j <= r) {
		if (j < r)
			if (a[j] < a[j + 1])
				j++;
		if (a[j] <= x)
			return;
		else {
			a[i] = a[j];
			i = j;
			j = 2 * i;
			a[i] = x;
		}
	}
}

void CreateHeap(int a[], int N) {
	int l;
	l = N / 2;
	while (l >= 0) {
		Shift(a, l, N);
		l--;
	}
}

void HeapSort(int a[], int N) {
	int r;
	CreateHeap(a, N);
	r = N - 1;
	while (r > 0) {
		swap(a[0], a[r]);
		r--;
		Shift(a, 0, r);
	}
}

int main() {
	int N, i, a[100];
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> a[i];
	HeapSort(a, N);
	for (i = 0; i < N; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}