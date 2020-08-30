#include<iostream>
#include<cmath>

using namespace std;

int arr[20][20];
int n;
int visit[20];
int cnt = 0;
int minn = 1000000007;

void combination(int num, int pos) {
	if (num == n / 2) {
		int a = 0, b = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (visit[i] && visit[j])
					a += (arr[i][j] + arr[j][i]);
				else if (!visit[i] && !visit[j])
					b += (arr[i][j] + arr[j][i]);
			}
		}
		if (minn > abs(a - b))
			minn = abs(a - b);

		return;
	}
	else {
		for (int i = pos; i < n; i++) {
			visit[i] = 1;
			combination(num + 1, i + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	combination(0, 0);
	cout << minn << endl;

	return 0;
}