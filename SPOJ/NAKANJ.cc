#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int bfs(int start_pos, int end_pos){
	int move_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int move_y[8] = {1, -1, 2, -2, 2, -2, 1, -1};
	int check[64], queue[64], queue_num = 0, cur_num = 0;
	for (int i = 0; i < 64; ++i)
		check[i] = -1;
	check[start_pos] = 0;
	queue[queue_num++] = start_pos;

	while (cur_num < queue_num){
		int cur_pos = queue[cur_num];
		int cur_x = cur_pos / 8, cur_y = cur_pos % 8, next_x, next_y, next_pos;
		for (int i = 0; i < 8; ++i){
			next_x = cur_x + move_x[i];
			next_y = cur_y + move_y[i];
			next_pos = next_x * 8 + next_y;
			if ((next_x < 0) || (next_x > 7)) continue;
			if ((next_y < 0) || (next_y > 7)) continue;
			if (check[next_pos] != -1) continue;
			check[next_pos] = check[cur_pos] + 1;
			if (next_pos == end_pos) return check[next_pos];
			queue[queue_num++] = next_pos;
		}
		++cur_num;
	}
	return -1;
}

int main(){
	int T, start_pos, end_pos, record[64][64];
	char s[10];
	for (int i = 0; i < 64; ++i)
		for (int j = 0; j < 64; ++j)
			record[i][j] = -1;
	for (int i = 0; i < 64; ++i)
		record[i][i] = 0;

	scanf("%d", &T);
	gets(s);    //important
	for (int i = 0; i < T; ++i){
		gets(s);
		start_pos = (s[0] - 'a') * 8 + (s[1] - '1');
		end_pos = (s[3] - 'a') * 8 + (s[4] - '1');
		if (record[start_pos][end_pos] == -1){
			record[start_pos][end_pos] = bfs(start_pos, end_pos);
			record[end_pos][start_pos] = record[start_pos][end_pos];
		}
		printf("%d\n", record[start_pos][end_pos]);
	}

	return 0;
}
