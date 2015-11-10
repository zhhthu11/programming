#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int main(){
	int test_case, n, m;
	char s[185];
	int dis[185][185];
	const int dirX[4] = {-1, 1, 0, 0};
	const int dirY[4] = {0, 0, -1, 1};
	queue<pair<int, int> > q;

	scanf("%d", &test_case);
	for (int t = 0; t < test_case; ++t){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i){
			scanf("%s", s);
			for (int j = 0; j < m; ++j){
				dis[i][j] = -1;
				if (s[j] == '1'){
					q.push(make_pair(i, j));
					dis[i][j] = 0;
				}
			}
		}

		while (!q.empty()){
			int curX = q.front().first, curY = q.front().second;
			q.pop();			
			for (int i = 0; i < 4; ++i){
				int nextX = curX + dirX[i], nextY = curY + dirY[i];
				if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && dis[nextX][nextY] == -1){
					dis[nextX][nextY] = dis[curX][curY] + 1;
					q.push(make_pair(nextX, nextY));
				}
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m - 1; ++j)
				printf("%d ", dis[i][j]);
			printf("%d\n", dis[i][m - 1]);
		}
	}
	return 0;
}