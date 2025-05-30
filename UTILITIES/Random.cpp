#include <bits/stdc++.h>

using namespace std;

int main(){

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> genrd(1, 100);
    int random_number = genrd(gen);
}