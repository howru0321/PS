//BOJ 7569
//https://www.acmicpc.net/problem/7569


#include<iostream>
#include<queue>
#include<tuple>


using namespace std;

int M, N, H;
int box[100][100][100];
int visit[100][100][100];
int day[100][100][100];
queue<tuple<int, int, int>> Q;

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int BFS()
{
	int total_days = 0;

	while (!Q.empty())
	{
		tuple<int, int, int> coordinate = Q.front();
		Q.pop();
		int x = get<0>(coordinate);
		int y = get<1>(coordinate);
		int z = get<2>(coordinate);

		int days = day[x][y][z] + 1;

		int temp_x, temp_y, temp_z;

		for (int i = 0; i < 6; i++)
		{
			temp_x = x + dx[i];
			temp_y = y + dy[i];
			temp_z = z + dz[i];

			if (temp_x < 0 || temp_x >= H || temp_y < 0 || temp_y >= N || temp_z < 0 || temp_z >= M)
			{
				continue;
			}
			if (visit[temp_x][temp_y][temp_z] == 1 || box[temp_x][temp_y][temp_z] == -1)
			{
				continue;
			}

			Q.push({ temp_x,temp_y,temp_z });
			visit[temp_x][temp_y][temp_z] = 1;
			box[temp_x][temp_y][temp_z] = 1;
			day[temp_x][temp_y][temp_z] = days;

			if (total_days < days)
			{
				total_days = days;
			}
		}
	}
	return total_days;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					Q.push({ i,j,k });
					visit[i][j][k] = 1;
				}
			}
		}
	}


	int ans_days = BFS();
	


	for (int i = 0; i < H; i++)//모든 그룹을 다 익혀도 익지 않은 그룹이 있다는건, 익은 토마토와 붙어있지 않은 토마토가 있다는 뜻
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (box[i][j][k] == 0)
				{
					ans_days = -1;
				}
			}
		}
	}

	cout << ans_days;



	return 0;
}
