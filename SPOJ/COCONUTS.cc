#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXD 310
#define MAXM 91000
#define INF 0x3f3f3f3f
int N, M, S, T, d[MAXD], q[MAXD];
int first[MAXD], e, next[MAXM], v[MAXM], flow[MAXM];

void add(int x, int y, int z){
    v[e] = y, flow[e] = z;
    next[e] = first[x], first[x] = e++;    
}

void init(){
    int x, y;
    S = 0, T = N + 1, e = 0;
    memset(first, -1, sizeof(first[0]) * (T + 1));
    for(int i = 1; i <= N; ++i){
        scanf("%d", &x);
        if (x)
            add(S, i, 1), add(i, S, 0);
        else
            add(i, T, 1), add(T, i, 0);
    }
    for(int i = 0; i < M; ++i){
        scanf("%d%d", &x, &y);
        add(x, y, 1), add(y, x, 1);    
    }
}

bool bfs(){
    int tail = 0;
    memset(d, -1, sizeof(d[0]) * (T + 1));
    d[S] = 0, q[tail++] = S;

    for (int i = 0; i < tail; ++i){
        for (int j = first[q[i]]; j != -1; j = next[j]){
            if (flow[j] && d[v[j]] == -1){
                d[v[j]] = d[q[i]] + 1, q[tail++] = v[j];
                if(v[j] == T)
                    return true;
            }
        }
    }
    return false;
}

int dfs(int cur, int maxflow){
    if (cur == T)
        return maxflow;
    for (int i = first[cur]; i != -1; i = next[i]){
        if (flow[i] && d[v[i]] == d[cur] + 1){
            if (int t = dfs(v[i], std::min(maxflow, flow[i]))){
                flow[i] -= t, flow[i ^ 1] += t;
                return t;
            }
        }
    }
    return 0;
}

void solve(){
    int ans = 0;
    while (bfs()){
        while (true){
        	int t = dfs(S, INF);
        	if (t == 0) break;
            ans += t;
        }
    }
    printf("%d\n", ans);
}

int main(){
    while(scanf("%d%d", &N, &M), N || M){
        init();
        solve();    
    }
    return 0; 
}