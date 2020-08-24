#include<iostream>

using namespace std;

int main()
{
	int dice[7], arr[1000], board[20][20];
	int n, m, x, y, k, row, col;

	//input
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	//주사위 모든 면 0으로 초기화
	for (int i = 1; i <= 6; i++)
		dice[i] = 0;

	row = x;
	col = y;
	int next_row, next_col, tmp;

	for (int i = 0; i < k; i++) {
		if (arr[i] == 1) {// 동
			next_row = row;
			next_col = col + 1;
			//	cout << next_row << " " << next_col << endl;
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
				continue;
			//동으로 한바퀴 굴렸다.
			tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;

			if (board[next_row][next_col] == 0) {
				board[next_row][next_col] = dice[6];
			}
			else {
				dice[6] = board[next_row][next_col];
				board[next_row][next_col] = 0;
			}
			//그다음으로 옮겨준다.
			row = next_row;
			col = next_col;

			//주사위 상단 출력
			cout << dice[1] << endl;
		}
		else if (arr[i] == 2) { // 서
			next_row = row;
			next_col = col - 1;
			//cout << next_row << " " << next_col << endl;
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
				continue;

			//서로 한바퀴 돌린다.
			tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;

			if (board[next_row][next_col] == 0) {
				board[next_row][next_col] = dice[6];
			}
			else {
				dice[6] = board[next_row][next_col];
				board[next_row][next_col] = 0;
			}
			//그다음으로 옮겨준다.
			row = next_row;
			col = next_col;

			//주사위 상단 출력
			cout << dice[1] << endl;
		}
		else if (arr[i] == 3) { // 북
			next_row = row - 1;
			next_col = col;
			//cout << next_row << " " << next_col << endl;
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
				continue;

			//북으로 한바퀴 돌린다.
			tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;

			if (board[next_row][next_col] == 0) {
				board[next_row][next_col] = dice[6];
			}
			else {
				dice[6] = board[next_row][next_col];
				board[next_row][next_col] = 0;
			}
			//그다음으로 옮겨준다.
			row = next_row;
			col = next_col;

			//주사위 상단 출력
			cout << dice[1] << endl;
		}
		else {//arr[i]==4  남
			next_row = row + 1;
			next_col = col;
			//cout << next_row << " " << next_col << endl;
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
				continue;

			//남으로 한바퀴 돌린다.
			tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;

			if (board[next_row][next_col] == 0) {
				board[next_row][next_col] = dice[6];//주사위의 바닥이 [6]
			}
			else {
				dice[6] = board[next_row][next_col];
				board[next_row][next_col] = 0;
			}
			//그다음으로 옮겨준다.
			row = next_row;
			col = next_col;

			//주사위 상단 출력
			cout << dice[1] << endl;
		}
	}

	return 0;
}