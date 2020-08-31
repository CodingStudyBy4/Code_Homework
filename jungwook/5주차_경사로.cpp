#include<iostream>
using namespace std;

int n, L;
int arr[100][100];

int is_possible(int a[100]) {

	int flag = 1;

	//경사로가 놓였는지 안 놓였는지에 대한 flag
	int visit[100];
	for (int i = 0; i < n; i++)
		visit[i] = 0;

	for (int i = 1; i < n; i++) {
		//cout << "Test" << endl;
		if (a[i - 1] - a[i] == 1) {
			int local_flag = 1;
			for (int j = i + 1; j < i + L; j++) {
				if (a[j - 1] == a[j] && j < n && !visit[j - 1] && !visit[j]);
				else {
					local_flag = 0;
					break;
				}
			}
			if (local_flag) {
				for (int j = i; j < i + L; j++)
					visit[j] = 1;
				i += L - 1;
			}
			else {
				flag = 0;
				break;
			}
		}
		else if (a[i - 1] - a[i] == -1) {
			int local_flag = 1;
			for (int j = i - 1; j > i - L; j--) {
				if (a[j - 1] == a[j] && j > 0 && !visit[j] && !visit[j - 1]);
				else {
					local_flag = 0;
					break;
				}
			}
			if (local_flag) {
				for (int j = i - L; j < i; j++)
					visit[j] = 1;
			}
			else {
				flag = 0;
				break;
			}
		}
		else if (a[i - 1] - a[i] == 0);
		else {
			flag = 0;
			break;
		}
	}
	/*for (int i = 0; i < n; i++)
		cout << visit[i] << " ";
	cout << endl;*/
	return flag;
}
int L1(int a[100]) {
	int flag = 1;

	//경사로가 놓였는지 안 놓였는지에 대한 flag
	int visit[100];
	for (int i = 0; i < n; i++)
		visit[i] = 0;

	for (int i = 1; i < n; i++) {
		//cout << "Test" << endl;
		if (a[i - 1] - a[i] == 1) {
			visit[i] = 1;
		}
		else if (a[i - 1] - a[i] == -1) {
			if (visit[i - 1]) {
				flag = 0;
				break;
			}
			else
				visit[i - 1] = 1;
		}
		else if (a[i - 1] - a[i] == 0);
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}
int main()
{
	int tmp[100], cnt = 0;
	cin >> n >> L;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	if (L == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				tmp[j] = arr[i][j];
			if (L1(tmp))
				cnt++;
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++)
				tmp[i] = arr[i][j];
			if (L1(tmp))
				cnt++;
		}
		cout << cnt << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				tmp[j] = arr[i][j];
			if (is_possible(tmp))
				cnt++;
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++)
				tmp[i] = arr[i][j];
			if (is_possible(tmp))
				cnt++;
		}
		cout << cnt << endl;
	}


	/*for (int i = 0; i < n; i++)
		cin >> tmp[i];
	if (is_possible(tmp))
		cout << "possible!!\n";
	else cout << "No! No! No!!\n";*/
	return 0;
}