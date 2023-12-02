#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<string, string> GetIndex(int n) {
    string result = "00000";
    for(int i = result.size() - 1; i >= 0 and n; --i) {
        result[i] += n % 2;
        n >>= 1;
    }

    string first = "", second = "";
    first.push_back(result[0]);
    first.push_back(result[1]);

    second.push_back(result[2]);
    second.push_back(result[3]);
    second.push_back(result[4]);

    return {first, second};
}

int main() {
    string s; cin >> s;

    map<pair<string, string>, char> KMap;

    vector<string> FirstIndex{"00", "01", "11", "10"},
                   SecondIndex{"000", "001", "011", "010", "110", "111", "101", "100"};

    for(int i = 0; i < 32; ++i) {
        KMap[GetIndex(i)] = s[i];
    }


    for(auto i : FirstIndex) {
        for(auto j : SecondIndex)
            cout << KMap[{i,j}] << ' ';
        cout << '\n';
    }
}
