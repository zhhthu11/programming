#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

void test_map(){
    unordered_map<float, int> cur_map;
    cout << cur_map[0] << endl;
}

int main(){
    test_map();
    cout << "check.." << endl;
    return 0;
}
