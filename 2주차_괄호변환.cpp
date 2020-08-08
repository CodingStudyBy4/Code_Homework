#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

stack<char> s;

int is_good(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else {
			if (s.empty())
				return 0;
			else
				s.pop();
		}
	}
	if (s.empty())
		return 1;
	else
		return 0;
}

string solution(string p) {
	
	string answer;
	string u = "";
	string v = "";
	int r = 0, l = 0;

	if (is_good(p))
		return p;

	// �ϴ� �������� u�� ����
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')l++;
		else r++;

		if (l == r)
			break;
	}
	for (int i = 0; i < l + r; i++)
		u += p[i];
	//v����
	for (int i = l + r; i < p.length(); i++)
		v += p[i];

	cout << u << ", " << v << endl;

	//u�� �ùٸ� ���ڿ��̸� v�� ���ؼ� recursive
	if (is_good(u))
		answer = u + solution(v);
	//�ùٸ� ���ڿ��� �ƴϸ� u�� ���ؼ� ���ο� ���ڿ� ����.
	else {
		string tmp = "(";
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(')
				tmp += ")";
			else tmp += "(";
		}
		tmp += ")";

		answer = tmp + solution(v);
	}
	return answer;
}
int main()
{
	string str = "()))((()";

	cout << solution(str);

	return 0;
}