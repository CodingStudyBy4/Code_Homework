#include<iostream>

using namespace std;

int arr[1000000];

int main()
{
	int n, b, c;
	long long int total;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;

	total = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] < b)
			arr[i] = 0;
		else
			arr[i] -= b;

		total++;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i]) {
			if (arr[i] % c == 0)
				total += (arr[i] / c);
			else {
				total += (arr[i] / c);
				total++;
			}
		}
	}

	cout << total;
	return 0;
}