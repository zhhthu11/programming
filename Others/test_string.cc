#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
    cout << tolower('C') << endl;
    cout << tolower('c') << endl;
    cout << tolower('8') << endl;
    string s = "abcd";
    cout << "s = " << s << endl;
    cout << "sub(1, 2) = " << s.substr(1, 2) << endl;
    cout << "sub(0, 2) = " << s.substr(0, 2) << endl;

    int test = 19930325;
    cout << "to_string = " << to_string(test) << endl;
    cout << "stoi = " << stoi(to_string(test)) << endl;

    string  ll = "1993032519930325";
    cout << "stoll = " << stoll(ll) << endl;

    string tree = "[1,2,3,null,null,4,5]";
    stringstream ss;
    ss << tree;
    int x;
    char c;
    while (ss >> c >> x){
        cout << "c = " << c << endl;
        cout << "x = " << x << endl;
    }

    for (int i = 0; i < tree.size(); ++i)
        if (tree[i] == ',' || tree[i] == '[' || tree[i] == ']')
            tree[i] = ' ';
    istringstream in(tree);
    string cur;
    while (in >> cur){
        cout << "in = " << cur << endl;
    }
    return 0;
}
