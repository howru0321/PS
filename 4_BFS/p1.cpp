//BOJ
//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int board[100][100];
int visit[100][100];
int dis_board[100][100];

queue < pair<int, int> >Q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void BFS()
{

	while (!Q.empty())
	{
		pair<int, int>coordinate = Q.front();
		Q.pop();

		int x = coordinate.first;
		int y = coordinate.second;
		int dis = dis_board[x][y] + 1;


		for (int i = 0; i < 4; i++)
		{
			int temp_x = x + dx[i];
			int temp_y = y + dy[i];

			if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= M)
			{
				continue;
			}
			if ((visit[temp_x][temp_y] == 1 && dis >= dis_board[temp_x][temp_y]) || board[temp_x][temp_y] == 0)
			{
				continue;
			}

			Q.push({ temp_x,temp_y });
			visit[temp_x][temp_y] = 1;
			dis_board[temp_x][temp_y] = dis;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			int num = temp[j] - '0';
			board[i][j] = num;
		}
	}


	Q.push({ 0,0 });
	visit[0][0] = 1;
	dis_board[0][0] = 1;

	BFS();

	cout << dis_board[N - 1][M - 1];


	return 0;
}
