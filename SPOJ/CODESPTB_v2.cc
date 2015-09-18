#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

const int max_array_a = 100100;
int a[max_array_a], temp[max_array_a];

long long merge_sort(int start_index, int end_index){
	//No need to sort
	if (start_index >= end_index) return 0;

	//merge sort, and calculate the number of reversed pairs
	long long ret;
	int mid_index = (start_index + end_index) / 2;
	ret = merge_sort(start_index, mid_index);
	ret += merge_sort(mid_index + 1, end_index);
	for (int i = start_index; i <= end_index; ++i)
		temp[i] = a[i];

	int left_index = start_index, right_index = mid_index + 1;
	for (int i = start_index; i <= end_index; ++i){
		if ((left_index <= mid_index) and ((temp[left_index] <= temp[right_index]) or (right_index > end_index))){
			a[i] = temp[left_index];
			++left_index;
			continue;
		}
		a[i] = temp[right_index];
		++right_index;
		ret += static_cast<long long>(mid_index - left_index + 1);
	}
	return ret;
}

int main(){
	int T, N;
	scanf("%d", &T);
	for (int k = 0; k < T; ++k){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		long long answer = merge_sort(0, N - 1);
		printf("%lld\n", answer);
	}
	return 0;
}