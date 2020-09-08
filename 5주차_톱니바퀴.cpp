#include<iostream>
#include<string>

using namespace std;

int gear[4][8];

void clock(int arr[8]) {
	int tmp = arr[7];
	for (int i = 7; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;
}
void count_clock(int arr[8]) {
	int tmp = arr[0];
	for (int i = 0; i < 7; i++)
		arr[i] = arr[i + 1];
	arr[7] = tmp;
}
void rotate_gear(int num, int dir) {
	if (num == 1) {
		if (dir == 1) {//clockwise
			clock(gear[0]);
			if (gear[0][3] != gear[1][6]) {
				count_clock(gear[1]);
				if (gear[1][1] != gear[2][6]) {
					clock(gear[2]);
					if (gear[2][3] != gear[3][6])
						count_clock(gear[3]);
				}
			}
		}
		else {
			count_clock(gear[0]);
			if (gear[0][1] != gear[1][6]) {
				clock(gear[1]);
				if (gear[1][3] != gear[2][6]) {
					count_clock(gear[2]);
					if (gear[2][1] != gear[3][6])
						clock(gear[3]);
				}
			}
		}
	}
	else if (num == 2) {
		if (dir == 1) {
			clock(gear[1]);
			if (gear[1][3] != gear[2][6]) {
				count_clock(gear[2]);
				if (gear[2][1] != gear[3][6])
					clock(gear[3]);
			}
			if (gear[1][7] != gear[0][2])
				count_clock(gear[0]);
		}
		else {
			count_clock(gear[1]);
			if (gear[1][1] != gear[2][6]) {
				clock(gear[2]);
				if (gear[2][3] != gear[3][6])
					count_clock(gear[3]);
			}
			if (gear[1][5] != gear[0][2])
				clock(gear[0]);
		}
	}
	else if (num == 3) {
		if (dir == 1) {
			clock(gear[2]);
			if (gear[2][3] != gear[3][6])
				count_clock(gear[3]);
			if (gear[2][7] != gear[1][2]) {
				count_clock(gear[1]);
				if (gear[1][5] != gear[0][2])
					clock(gear[0]);
			}
		}
		else {
			count_clock(gear[2]);
			if (gear[2][1] != gear[3][6])
				clock(gear[3]);
			if (gear[2][5] != gear[1][2]) {
				clock(gear[1]);
				if (gear[1][7] != gear[0][2])
					count_clock(gear[0]);
			}
		}
	}
	else if (num == 4) {
		if (dir == 1) {
			clock(gear[3]);
			if (gear[3][7] != gear[2][2]) {
				count_clock(gear[2]);
				if (gear[2][5] != gear[1][2]) {
					clock(gear[1]);
					if (gear[1][7] != gear[0][2])
						count_clock(gear[0]);
				}
			}
		}
		else {
			count_clock(gear[3]);
			if (gear[3][5] != gear[2][2]) {
				clock(gear[2]);
				if (gear[2][7] != gear[1][2]) {
					count_clock(gear[1]);
					if (gear[1][5] != gear[0][2])
						clock(gear[0]);
				}
			}
		}
	}
}
int main()
{
	int n, num, dir;
	int score;
	string str;

	for (int i = 0; i < 4; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++)
			gear[i][j] = str[j] - '0';
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num >> dir;
		rotate_gear(num, dir);
	}
	score = gear[0][0] + 2 * gear[1][0] + 4 * gear[2][0] + 8 * gear[3][0];
	cout << score << endl;
	return 0;
}