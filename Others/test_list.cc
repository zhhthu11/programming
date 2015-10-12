#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> zhh;
    zhh.push_back(1);
    zhh.push_back(2);
    zhh.push_back(3);
    list<int>::iterator it;
    for (it = zhh.begin(); it != zhh.end(); ++it){
        cout << *it << endl;
        zhh.pop_front();
    }
}
