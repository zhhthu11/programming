#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

int main(){
	int n, e, t, m;
	scanf("%d%d%d%d", &n, &e, &t, &m);

	int x, y, cost, dis[n][n];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			dis[i][j] = INT_MAX / 2;
		dis[i][i] = 0;
	}
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &x, &y, &cost);
		if (cost < dis[x - 1][y - 1])
			dis[x - 1][y - 1] = cost;
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];

	int ret = 0;
	for (int i = 0; i < n; ++i)
		if (dis[i][e - 1] <= t) ++ret;
	printf("%d\n", ret);

	return 0;
}