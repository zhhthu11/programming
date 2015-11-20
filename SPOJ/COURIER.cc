#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
#include <utility>
using namespace std;

int test_num, n, m, source;
int dis[100][100], from[12], goal[12], dp[1 << 12][12];
queue<pair<int, int> > q;

int min(int x, int y){
	return x < y ? x : y;
}

int main(){
	scanf("%d", &test_num);
	for (int test = 0; test < test_num; ++test){
		//========Preprocessing========
		scanf("%d%d%d", &n, &m, &source);
		--source;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				dis[i][j] = INT_MAX / 4;
			dis[i][i] = 0;
		}

		//========Input Distance=======
		int x, y, len;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &x, &y, &len);
			--x, --y;
			dis[x][y] = len;
			dis[y][x] = len;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

		//==========Input Task=========
		int z, bj, task = 0;
		scanf("%d", &z);
		for (int i = 0; i < z; ++i){
			scanf("%d%d%d", &x, &y, &bj);
			--x, --y;
			for (int j = 0; j < bj; ++j){
				from[task] = x;
				goal[task] = y;
				++task;
			}
		}

		//=========DP Processing=======
		for (int i = 0; i < (1 << task); ++i)
			for (int j = 0; j < task; ++j)
				dp[i][j] = INT_MAX / 4;

		for (int i = 0; i < task; ++i){
			dp[1 << i][i] = dis[source][from[i]] + dis[from[i]][goal[i]];
			q.push(make_pair(1 << i, i));
		}

		while (!q.empty()){
			int status = q.front().first, index = q.front().second;
			q.pop();
			for (int i = 0; i < task; ++i){
				if (((1 << i) & status) == 0){
					int next_status = status + (1 << i);
					if (dp[next_status][i] == INT_MAX / 4)
						q.push(make_pair(next_status, i));
					dp[next_status][i] = min(dp[next_status][i], dp[status][index] + dis[goal[index]][from[i]] + dis[from[i]][goal[i]]);
					//cout << "status = " << status << " : " << dp[status][index] << ", " << " next_status = " << next_status << " : " << dp[next_status][i] << endl;
				}
			}
		}

		//==========Find Answer=========
		int answer = INT_MAX / 4;
		for (int i = 0; i < task; ++i)
			answer = min(answer, dp[(1 << task) - 1][i] + dis[goal[i]][source]);
		printf("%d\n", answer);
	}
	return 0;
}