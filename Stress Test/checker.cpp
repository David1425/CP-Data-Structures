// Stress Test Checker

#include <bits/stdc++.h>

using namespace std;

struct err {
    int l;
    string va, vb;
};

void printCase() {
    // Change printCase() according to problem
    /*
    Example:
    
    int n;
    cin >> n;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << a << " ";
    }
    cout << "\n\n";
    */
}

class trimmer {
    const string WHITESPACE = " \n\r\t\f\v";
    
    string ltrim(const string &s) {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == string::npos) ? "" : s.substr(start);
    }
    
    string rtrim(const string &s) {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == string::npos) ? "" : s.substr(0, end + 1);
    }
    
    public:
    string trim(const string &s) {
        return rtrim(ltrim(s));
    }
};

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string files[2] = {argv[1], argv[2]};
    ifstream ain(files[0]), bin(files[1]);
    string x, y;
    int line = 0;
    vector<err> diff;
    trimmer tr;
    getline(ain, x);
    getline(bin, y);
    x = tr.trim(x); y = tr.trim(y);
    while (x!="" || y!="") {
        line++;
        if (x != y) {
            diff.push_back({line, x, y});
        }
        getline(ain, x);
        getline(bin, y);
        x = tr.trim(x); y = tr.trim(y);
    }
    
    if (!diff.empty()) {
        printCase();
        cout << diff.size() << " difference found.\n";
        for (auto i : diff) {
            cout << "at line " << i.l << ":\n\tA.cpp: " << i.va << "\n\tB.cpp: " << i.vb << "\n";
        }
    }
    
    return 0;
}
