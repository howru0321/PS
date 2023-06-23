//BOJ 1926
//https://www.acmicpc.net/problem/1926


#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

int X, Y;
int board[500][500];
int visit[500][500];

queue<pair<int, int>> Q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int BFS()
{
	int area = 0;

	while (!Q.empty())
	{
		pair<int, int> coordinate = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_coordinate = coordinate.first + dx[i];
			int y_coordinate = coordinate.second + dy[i];

			if (x_coordinate < 0 || x_coordinate >= X || y_coordinate < 0 || y_coordinate >= Y)
			{
				continue;
			}

			if (visit[x_coordinate][y_coordinate] == 1 || board[x_coordinate][y_coordinate] == 0)
			{
				continue;
			}

			Q.push({ x_coordinate, y_coordinate });
			visit[x_coordinate][y_coordinate] = 1;
			area++;
		}
	}

	return area;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y;

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cin >> board[i][j];
		}
	}

	vector<int>area;

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (visit[i][j] == 0 && board[i][j] == 1)
			{
				Q.push({ i,j });
				visit[i][j] = 1;
				area.push_back(BFS() + 1);
			}
		}
	}

	cout << area.size() << '\n';
	if (area.size())
	{
		cout << *max_element(area.begin(), area.end());
	}
	else
	{
		cout << 0;
	}


	return 0;
}
