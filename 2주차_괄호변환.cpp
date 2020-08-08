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

	// 일단 균형잡힌 u를 생성
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')l++;
		else r++;

		if (l == r)
			break;
	}
	for (int i = 0; i < l + r; i++)
		u += p[i];
	//v생성
	for (int i = l + r; i < p.length(); i++)
		v += p[i];

	cout << u << ", " << v << endl;

	//u가 올바른 문자열이면 v에 대해서 recursive
	if (is_good(u))
		answer = u + solution(v);
	//올바른 문자열이 아니면 u에 대해서 새로운 문자열 생성.
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