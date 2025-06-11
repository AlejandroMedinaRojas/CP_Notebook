#include <bits/stdc++.h>

typedef __int128_t int128;
typedef __uint128_t uint128;

using namespace std;

int128 StringToInt128(string &s){
    int128 number = 0;
    int sign = 1, i = 0;
    if (s[0] == '-'){
        sign = -1;
        i = 1;
    }
    for (; i < (int)s.size(); ++i){
        number = number * 10 + (s[i] - '0');
    }
    return number * sign;
}

string Int128ToString(int128 number){
    if (number == 0) return "0";
    string s = "";
    bool negative = false;
    if (number < 0){
        negative = true;
        number = -number;
    }
    while (number > 0){
        s += '0' + (number % 10);
        number /= 10;
    }
    if (negative) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

uint128 StringToUInt128(string &s){
    uint128 number = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        number = number * 10 + (s[i] - '0');
    }
    return number;
}

string Uint128ToString(uint128 number) {
    if (number == 0) return "0";
    string s = "";
    while (number > 0) {
        s += '0' + (number % 10);
        number /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}