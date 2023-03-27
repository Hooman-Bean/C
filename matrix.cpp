#include <iostream>

//#include <cilk/cilk.h>

using namespace std; //cilk_spawn cilk_sync; cilk_for


const int n = 3;

int** a; int** b; int** c; //These are n x n two dimensional arrays.

//return dot product of a[row][i..j] with b[i..j][col]
int dot(int row, int col, int i, int j) {

	for (int l = i, l < j, l++) {
		int t += a[row][l] * b[l][col];
	}
	return t;

}

void aTimesb() { //puts product of a[0..n-1][0..n-1] and b[0..n-1][0..n-1] into c

// based on slide 25 algorithm, but using parallel dot to increase(?) its parallelism
	parallel for (int x = 0, x <= n, x++) {
		parallel for (int y = 0, y <= n, y++) {
			c[x][y] = dot(x, y, 0, n);
		}

	}sync;
}


void init(int* arr[], int v) {

	for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) arr[r][c] = v;

}

int main() {

	a = new int* [n]; for (int r = 0; r < n; r++)a[r] = new int[n];

	b = new int* [n]; for (int r = 0; r < n; r++)b[r] = new int[n];

	c = new int* [n]; for (int r = 0; r < n; r++)c[r] = new int[n];

	init(a, 1); init(b, 2);


	aTimesb();


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) cout << c[i][j] << ' ';

		cout << endl;

	}

}