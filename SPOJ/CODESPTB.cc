#include <iostream>
#include <string.h>
using namespace std;

const int max_num_a = 1000100;
int tree[max_num_a];

int LowBit(int x){
	return x & (x ^ (x - 1));
}

void ChangeValue(int k, int delta){
	while (k <= max_num_a){
		tree[k] += delta;
		k += LowBit(k);
	}
}

int GetSum(int k){
	int ret = 0;
	while (k > 0){
		ret += tree[k];
		k -= LowBit(k);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; ++k){
		int N, value;
		long long answer = 0;
		memset(tree, 0, sizeof(tree));
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			scanf("%d", &value);
			answer += static_cast<long long>(GetSum(max_num_a) - GetSum(value));
			ChangeValue(value, 1);
		}
		printf("%lld\n", answer);
	}
	return 0;
}