#include<iostream>

using namespace std;

int arr[20][20], n;
int a[20][20];
int tmp[20], cnt;

int find_max() {
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
void move_line() {
	for (int i = 1; i < cnt; i++) {
		if (tmp[i - 1] == tmp[i]&&tmp[i-1]%2==0&&tmp[i]%2==0) {
			tmp[i - 1] = tmp[i] * 20 + 1;
			for (int j = i + 1; j < cnt; j++)
				tmp[j - 1] = tmp[j];
			cnt--;
		}
	}
}
void move_up() {

	for (int j = 0; j < n; j++) {

		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j]) 
				tmp[cnt++] = a[i][j];
		}
		move_line();
		for (int i = 0; i < cnt; i++) 
			a[i][j] = tmp[i];
		for (int i = cnt; i < n; i++)
			a[i][j] = 0;
	}
}
void move_down() {

	for (int j = 0; j < n; j++) {

		cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j])
				tmp[cnt++] = a[i][j];
		}
		move_line();
		for (int i = 0; i < cnt; i++) 
			a[n - 1 - i][j] = tmp[i];
		for (int i = cnt; i < n; i++)
			a[n - 1 - i][j] = 0;
	}
}
void move_right() {
	
	for (int i = 0; i < n; i++) {

		cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j])
				tmp[cnt++] = a[i][j];
		}
		move_line();
		for (int j = 0; j < cnt; j++)
			a[i][n - 1 - j] = tmp[j];
		for (int j = cnt; j < n; j++)
			a[i][n - 1 - j] = 0;
	}
}
void move_left() {

	for (int i = 0; i < n; i++) {

		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j])
				tmp[cnt++] = a[i][j];
		}
		move_line();
		for (int j = 0; j < cnt; j++)
			a[i][j] = tmp[j];
		for (int j = cnt; j < n; j++)
			a[i][j] = 0;
	}
}

int main()
{

	int total_max = 0, local_max;
	int combi[5];
	int idx;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	//모든 경우에 대해서 계산
	for (int i = 0; i < 1024; i++) {

		int digit = 1;
		for (int j = 0; j < 5; j++) {
			combi[j] = (i / digit) % 4;
			digit *= 4;
		}

		//copy arr->a
		for (int row = 0; row < n; row++)
			for (int col = 0; col < n; col++)
				a[row][col] = arr[row][col];

		//모든 조합에 대해서 a의 이동 계산
		for (int j = 0; j < 5; j++) {
			if (combi[j] == 0)
				move_up();
			else if (combi[j] == 1)
				move_right();
			else if (combi[j] == 2)
				move_down();
			else if (combi[j] == 3)
				move_left();
		}

		//모든 수행이 끝나고 값들을 이쁘게 만들어준다.
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (a[row][col] % 2 == 1)
					a[row][col] /= 10;
			}
		}
		local_max = find_max();
		
		if (local_max > total_max) {
			total_max = local_max;
			idx = i;
		}
	}
	cout << total_max <<endl;

	return 0;
}