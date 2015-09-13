#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;

const int max_num = 100100;
long long a[max_num];
long long c[max_num];
int father[max_num];
int n, m;

//Low bit function for BIT
int LowBit(int x){
	return (x & (x ^ (x - 1)));
}

//Change value of c[k]
void ChangeValue(int k, long long delta){
	while (k <= n){
		c[k] += delta;
		k += LowBit(k);
	}
}

//Get sum from c[0] to c[k]
long long GetSum(int k){
	long long answer = 0;
	while (k > 0){
		answer += c[k];
		k -= LowBit(k);
	}
	return answer;
}

//Union Find
int find(int k){
	if (father[k] == k) return k;
	father[k] = find(father[k]);
	return father[k];
}

int main(){
	int count = 0;
	while (scanf("%d", &n) != EOF){
		++count;
		printf("Case #%d:\n", count);
		memset(c, 0, sizeof(c));


		//input array A, and initialize array C
		for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		for (int i = 1; i <= n; ++i) ChangeValue(i, a[i]);
		for (int i = 1; i <= n + 1; ++i) father[i] = i;

		//Ask queries
		scanf("%d", &m);
		int query_type, x, y, temp;
		long long pre_value;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &query_type, &x, &y);
			if (x > y){
				temp = x; x = y; y = temp;
			}

			if (query_type == 0){	//modify operation
				int k = find(x);
				while (k <= y){
					if (a[k] > 1){
						pre_value = a[k];
						a[k] = floor(sqrt(a[k]));
						ChangeValue(k, a[k] - pre_value);
						if (a[k] == 1) father[k] = k + 1;
					}
					k = find(k + 1);
				}
			}
			if (query_type == 1){	//query operation
				printf("%lld\n", GetSum(y) - GetSum(x - 1));
			}
		}
		printf("\n");
	}
}
