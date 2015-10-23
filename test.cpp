#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void test_map(){
    unordered_map<float, int> cur_map;
    cout << cur_map[0] << endl;
    cur_map[0] = 1;
    cout << "size = " << cur_map.size() << endl;
    cout << "-1 < cur_map.size() == " << (-1 < cur_map.size()) << endl;
}

int main(){
    test_map();
    return 0;
}
