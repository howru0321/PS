//BOJ 1406
//https://www.acmicpc.net/problem/1406

#include <iostream>

using namespace std;


int func(int a[], int n)
{
	int num[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		num[a[i]]++;
	}

	for (int i = 0; i < 50; i++)
	{
		if (num[i] && num[100 - i])
		{
			return 1;
		}
	}

	return 0;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int arr[1000];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cout << func(arr, N);
	

	return 0;
}
