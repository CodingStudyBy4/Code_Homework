#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int n, arr[102][102];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int dir = 0;

queue<pair<int, char>>q;
vector<pair<int, int>>v;

int is_me(int row, int col) {
	for (int i = 1; i < v.size(); i++)
		if (v[i].first == row && v[i].second == col)
			return 1;
	return 0;
}

int main()
{
	int k, L, r, c, x, tik;
	char d;

	//input
	cin >> n;
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < n + 2; j++)
			arr[i][j] = 0;
	for (int i = 0; i < n + 2; i++) {
		arr[0][i] = 1;
		arr[i][0] = 1;
		arr[n + 1][i] = 1;
		arr[i][n + 1] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		arr[r][c] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> d;
		q.push(make_pair(x, d));
	}

	//snake is moving
	tik = 0;
	v.push_back(make_pair(1, 1));
	while (1) {
		tik++;
		int row = v[0].first;
		int col = v[0].second;
		int nr = row + dr[dir];
		int nc = col + dc[dir];

		if (arr[nr][nc] == 1 || is_me(nr, nc))//벽을 만나거나 내 몸이랑 만나면 종료
			break;
		else if (arr[nr][nc] == 0) {
			v.insert(v.begin(), make_pair(nr, nc));
			v.erase(v.end() - 1);
		}
		else {
			v.insert(v.begin(), make_pair(nr, nc));
			arr[nr][nc] = 0;
		}

		if (!q.empty() && q.front().first == tik) {
			char dd = q.front().second;
			if (dd == 'L') {//-> 왼쪽
				if (dir == 0)dir = 3;
				else if (dir == 1)dir = 0;
				else if (dir == 2)dir = 1;
				else dir = 2;
			}
			else {//D일때 -> 오른쪽
				if (dir == 0)dir = 1;
				else if (dir == 1)dir = 2;
				else if (dir == 2)dir = 3;
				else dir = 0;
			}
			q.pop();
		}
	}
	cout << tik << endl;
	return 0;
}