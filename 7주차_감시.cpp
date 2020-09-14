#include<iostream>
#include<cmath>

using namespace std;

typedef struct {
	int row;
	int col;
	int num;
}CCTV;

CCTV node[64];
int n, m;
int arr[8][8], tmp[8][8];
int cnt = 0;
int minimum = 100;

int blind() {
	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (tmp[i][j] == 0)
				cnt++;

	return cnt;
}
void look_up(int row, int col) {
	while (1) {
		if (tmp[row][col] == 6 || row < 0)
			break;
		if (!tmp[row][col])
			tmp[row][col] = 9;

		row--;
	}
}
void look_down(int row, int col) {
	while (1) {
		if (tmp[row][col] == 6 || row >= n)
			break;
		if (!tmp[row][col])
			tmp[row][col] = 9;

		row++;
	}
}
void look_left(int row, int col) {
	while (1) {
		if (tmp[row][col] == 6 || col < 0)
			break;
		if (!tmp[row][col])
			tmp[row][col] = 9;

		col--;
	}
}
void look_right(int row, int col) {
	while (1) {
		if (tmp[row][col] == 6 || col >= m)
			break;
		if (!tmp[row][col])
			tmp[row][col] = 9;

		col++;
	}
}
int main()
{
	int row, col;
	int motion[8];

	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	//CCTY 정보 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (1 <= arr[i][j] && arr[i][j] <= 4) {
				node[cnt].row = i;
				node[cnt].col = j;
				node[cnt].num = arr[i][j];

				cnt++;
			}
			else if (arr[i][j] == 5) {

				//위로
				row = i;
				col = j;
				while (1) {
					if (arr[row][col] == 6 || row < 0)
						break;
					if (!arr[row][col])
						arr[row][col] = 9;

					row--;
				}
				//아래로
				row = i;
				col = j;
				while (1) {
					if (arr[row][col] == 6 || row >= n)
						break;
					if (!arr[row][col])
						arr[row][col] = 9;

					row++;
				}
				//왼쪽으로
				row = i;
				col = j;
				while (1) {
					if (arr[row][col] == 6 || col < 0)
						break;
					if (!arr[row][col])
						arr[row][col] = 9;

					col--;
				}
				//오른쪽으로
				row = i;
				col = j;
				while (1) {
					if (arr[row][col] == 6 || col >= m)
						break;
					if (!arr[row][col])
						arr[row][col] = 9;

					col++;
				}
			}
		}
	}

	for (int i = 0; i < pow(4, cnt); i++) {

		//arr->tmp copy
		for (int ii = 0; ii < n; ii++)
			for (int jj = 0; jj < m; jj++)
				tmp[ii][jj] = arr[ii][jj];

		//모든 경우에 대해서 계산
		int digit = 1;
		for (int j = 0; j < cnt; j++) {
			motion[j] = (i / digit) % 4;
			digit *= 4;
		}
		for (int j = 0; j < cnt; j++) {

			row = node[j].row;
			col = node[j].col;

			if (node[j].num == 1) {
				if (motion[j] == 0)
					look_up(row, col);
				else if (motion[j] == 1)
					look_right(row, col);
				else if (motion[j] == 2)
					look_down(row, col);
				else if (motion[j] == 3)
					look_left(row, col);
			}
			else if (node[j].num == 2) {
				if (motion[j] == 0 || motion[j] == 2) {
					look_up(row, col);
					look_down(row, col);
				}
				else if (motion[j] == 1 || motion[j] == 3) {
					look_left(row, col);
					look_right(row, col);
				}
			}
			else if (node[j].num == 3) {
				if (motion[j] == 0) {
					look_up(row, col);
					look_right(row, col);
				}
				else if (motion[j] == 1) {
					look_right(row, col);
					look_down(row, col);
				}
				else if (motion[j] == 2) {
					look_down(row, col);
					look_left(row, col);
				}
				else if (motion[j] == 3) {
					look_left(row, col);
					look_up(row, col);
				}
			}
			else if (node[j].num == 4) {
				if (motion[j] == 0) {
					look_left(row, col);
					look_up(row, col);
					look_right(row, col);
				}
				else if (motion[j] == 1) {
					look_up(row, col);
					look_right(row, col);
					look_down(row, col);
				}
				else if (motion[j] == 2) {
					look_right(row, col);
					look_down(row, col);
					look_left(row, col);
				}
				else if (motion[j] == 3) {
					look_down(row, col);
					look_left(row, col);
					look_up(row, col);
				}
			}
		}
		if (minimum > blind())
			minimum = blind();
	}
	cout << minimum << endl;

	return 0;
}