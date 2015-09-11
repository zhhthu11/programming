#include <iostream>
using namespace std;

int main(){
    const int check_num = 42;
    int cur_num;
    while (true){
        cin >> cur_num;
        if (cur_num == check_num){
            break;
        } else {
            cout << cur_num << endl;
        }
    }
    return 0;
}
