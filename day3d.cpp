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

//vector<string> v;

void solve() {
    string o;
    cin >> o;
    int size = o.size() + 2;
    char a[size][size];
    char c;
    int i, j, p = 0, f, k, l;
    bool s = false;
    ll sum = 0;
    int n = 0; pair<int,int> y;

    i = 1;
    for(j = 1; j < (size-1); j++) {
            a[i][j] = o[j-1];
            //cout << a[i][j];
    }

    for(j = 0; j < size; j++) {
        i = 0;
        a[i][j] = '.'; 
        i = size -1;
        a[i][j] = '.';
    }
    for(i = 0; i < size; i++) { //size+1
        j = 0;
        a[i][j] = '.';
        j = size - 1;
        a[i][j] = '.';
    }
     
    for(i = 2; i < (size-1); i++) {
        for(j = 1;j < (size-1); j++) {
            cin >> c;
            a[i][j] = c;
        }
        a[i][j] = '.';
    }

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for(i = size-2; i > -1; i--) {
        for(j = size-2; j > -1; j--) {
            if((a[i][j] >= '0') && (a[i][j] <= '9')) {
                n += (a[i][j] - '0') * pow(10, p);
                p++;
                for(f = -1; f <= 1; f++) {
                    for(k = -1; k <= 1; k++) {
                        if(a[i+f][j+k] == '*') {
                            s = true;
                            if((y.first == (i+f)) && (y.second == (j+k))) {

                            } else 
                        }
                    }
                }
            } else {
                if(s) {
                    cout << n << endl;
                    sum += n;
                }
                s = false;
                n = 0;
                p = 0;
            }
        }
    }
    cout << endl << sum << endl;
}

int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
