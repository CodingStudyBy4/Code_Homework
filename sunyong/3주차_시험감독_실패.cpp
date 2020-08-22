#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	//N개의 시험장  , i번 시험장 응시자 수 : Ai명
	//총 감독관 : B명 응시자 감시
	//부 감독관 : C명 응시자 감시
	//감독관 수 최솟값

	int N = 0, B = 0, C = 0;
	int* A = new int[N];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	scanf("%d", &B);
	scanf("%d", &C);

	B = (C > B) ? C : B;


	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		A[i] = A[i] - B;
		cnt++;
	}
	int all_zero_flag = 0;

	while (1)
	{
		all_zero_flag = 1;
		
		for (int i = 0; i < N; i++)
		{
			if (A[i] <= 0)
				continue;
			else
			{
				all_zero_flag = 0;
				A[i] = A[i] - C;
				cnt++;
			}
		}
		if (all_zero_flag == 1)
			break;
	}
	cout << cnt << endl;
	delete[] A;
	return 0;
}
