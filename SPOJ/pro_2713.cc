#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;

const int max_num = 100001;
int a[max_num];
long long c[max_num];
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

int main(){
	int query_type, x, y, temp, count = 1;
	while (scanf("%d", &n) != EOF){
		//memset(a, 0, sizeof(a));
		//memset(c, 0, sizeof(c));
		printf("Case #%d:\n", count);
		++count;
		for (int i = 0; i <= n; ++i) c[i] = 0;

		//input array A, and initialize array C
		for (int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			//ChangeValue(i, static_cast<long long>(a[i]));
			ChangeValue(i, a[i]);
		}

		//Ask queries
		scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &query_type, &x, &y);
			if (x > y){
				temp = x; x = y; y = temp;
			}

			if (query_type == 0){	//modify operation
				for (int j = x; j <= y; ++j){
					if (a[j] > 1){
						temp = a[j];
						//a[j] = static_cast<int>(floor(sqrt(a[j])));
						a[j] = (int) floor(sqrt(a[j]));
						//ChangeValue(j, static_cast<long long>(a[j] - temp));
						ChangeValue(j, a[j] - temp);
					}
				}
			}
			if (query_type == 1){	//query operation
				//long long current_sum = GetSum(y) - GetSum(x - 1);
				//printf("%lld\n", current_sum);
				printf("%lld\n", GetSum(y) - GetSum(x - 1));
			}
		}
		printf("\n");
	}
}
