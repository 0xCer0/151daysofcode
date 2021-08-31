// Given a 2d array arr[][] with each row representing a pair representing entry and exit time of a car in a parking lot, the task is to calculate the maximum number of cars that can be parked at the same time.

// Examples:
// Input: arr[][] = {{1012, 1136}, {1317, 1417}, {1015, 1020}}
// Output: 2
// Explanation:
// 1st car entered at 10:12 and exits at 11:36 and 3rd car entered at 10:15 and exits at 10:20.
// Therefore, 1st and 3rd car are present at the same time.

#include <bits/stdc++.h>
using namespace std;

int maxCars(int arr[][2], int N)
{

	pair<int, bool> a[2 * N];
	for (int i = 0; i < N; i++) {
		a[2 * i] = { arr[i][0], true };
		a[2 * i + 1] = { arr[i][1], false };
	}

	sort(a, a + 2 * N);

	int curMax = 0;

	int maxFinal = 0;

	for (int i = 0; i < 2 * N; ++i) {

		if (a[i].second) {
			curMax++;
		}

		else {
			if (curMax > maxFinal) {
				maxFinal = curMax;
			}
			curMax--;
		}
	}

	cout << maxFinal;
}

int main()
{
	
	int arr[][2] = { { 1012, 1136 },
					{ 1317, 1412 },
					{ 1015, 1020 } };

	int N = sizeof(arr) / sizeof(arr[0]);

	maxCars(arr, N);

	return 0;
}
