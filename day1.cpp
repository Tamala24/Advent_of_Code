#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define entf cout << endl
#define ent cout << "\n"
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define MOD 1000000007
#define TESTCASES true
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
string n[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void solve() {
   string s; int f, l, i, j, k, o;
   ll sum = 0;
   while(cin >> s) {
        i = 0; f = 0; l = 0;
        while((s[i] >= 'A') && (f < 1) && (i < (s.size()-1))) {
            k = i + 1; o = -1; 
            if(s[i] == 'o') {
                o = 0;
            } else if(s[i] == 't') {
                if(s[k] == 'w') {
                    o = 1;
                } else if(s[k] == 'h') {
                    o = 2;
                }
            } else if(s[i] == 'f') {
                if(s[k] == 'o') {
                    o = 3;
                } else if(s[k] == 'i') {
                    o = 4;
                }
            } else if(s[i] == 's') {
                if(s[k] == 'i') {
                    o = 5;
                } else if(s[k] == 'e') {
                    o = 6;
                }
            } else if(s[i] == 'e') {
                o = 7;
            } else if(s[i] == 'n') {
                o = 8;
            }
            if(o > -1) {
                j = 1; 
                while(j < n[o].size()) {
                    if(s[k] == n[o][j]) {
                        k++;j++;
                    } else {
                        break;
                    }
                }
                if(j == n[o].size())
                    f = o + 1;
            }
            i++;
        }
        if(f < 1)
            f = s[i] - '0';
        i = s.size() - 1;
       while((s[i] >= 'A') && (l < 1) && (i > 0)) {
            k = i - 1; o = 0;  
            if(s[i] == 'o') {
                o = 1;
            } else if(s[i] == 'e') {
                if(s[k] == 'e') {
                    o = 2;
                } else if(s[k] == 'n') {
                    if(s[k-1] == 'o') {
                        l = 1;
                        break;
                    } else if(s[k-1] == 'i') {
                        o = 8;
                    }
                } else if(s[k] == 'v') {
                    o = 4;
                }
            } else if(s[i] == 'r') {
                o = 3;
            } else if(s[i] == 'x') {
                o = 5;
            } else if(s[i] == 'n') {
                o = 6;
            } else if(s[i] == 't') {
                o = 7;
            }
            if(o) {
                j = n[o].size() - 2; 
                while(j > -1) {
                    if(s[k] == n[o][j]) {
                        k--;j--;
                    } else {
                        break;
                    }
                }
                if(j == -1)
                    l = o + 1;
            }
            i--;
        }

        if(l < 1)
            l = s[i] - '0';
        //l += f*10;
        sum += f*10 + l;
        std::cout << sum << endl;
   }
}

int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
