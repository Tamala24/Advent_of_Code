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
    ll sum = 0, n;
    //vector<char*> v;
    //char a*;
    i = 1;
    /*vector<vector<char>> v;
    vector<char> b;
    while(cin >> c) {
        if(c == '\n') {
            v.emplace_back(v);
        } else {
            b.emplace_back(c);
        }
    }*/
    /*while(cin >> o) {
        a[i][0] = '.';
        for(j = 1; j < (size-1); j++) {
            a[i][j] = o[j-1];
            cout << a[i][j];
        }
        a[i][j] = '.';
        cout << a[i][j];
        i++;
    }*/
    for(j = 1; j < (size-1); j++) {
            a[i][j] = o[j-1];
            cout << a[i][j];
    }
    //a[i][j] = '.';
    //cout << a[i][j];

    i = size -1;
    for(j = 0; j < size; j++) 
        a[i][j] = '.'; 
    i = 0;
    for(j = 0; j < size; j++) 
        a[i][j] = '.';
    j = 0;
    for(i = 0; i < size; i++) //size+1
        a[i][j] = '.';
    
    
    i = 2; j = 1;
    while(cin >> noskipws >> c) {
        if(c != '\n') {
            a[i][j] = c;
            cout << a[i][j] << " ";
            j++;
        } else {
            a[i][j] = '.';
            cout << endl;
            i++; j = 1; //size = j;
        }
    } 
    cout << endl;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    bool m[size][size] = {false};
    //j = size;
    for(i = 1; i < (size-1); i++) {
        for(j = 1; j < (size-1); j++) {
            if((a[i][j] != '.') && ((a[i][j] < '0') || (a[i][j] > '9'))) {
                for(f = -1; f < 2; f++) {
                    for(k = -1; k < 2; k++) {
                        if((a[i+f][j+k] >= '0') && (a[i+f][j+k] <= '9') && (!m[i+f][j+k])) {
                            m[i+f][j+k] = true;//Hay un numero;
                            l = 1;
                            while((a[i+f][j+k+l] >= '0') && (a[i+f][j+k+l] <= '9')) {
                                m[i+f][j+k+l] = true;//Hay un numero;
                                l++;
                            } //recorremos el numero entero
                            l = -1;
                            while((a[i+f][j+k+l] >= '0') && (a[i+f][j+k+l] <= '9')) {
                                m[i+f][j+k+l] = true;//Hay un numero;
                                l--;
                            } //recorremos el numero entero
                        }
                    }
                }
            } // Si es un simbolo
        }
    }
    for(i = size-1; i > 0; i--) {
        p = 0;
        for(j = size-1; j > 0; j--) {
            cout << m[i][j] << " ";
            if(m[i][j]) {
                n += (a[i][j] - '0') * pow(10, p);
                p++;
            } else {
                //cout << n << endl;
                p = 0; n = 0;
            }
            
        }
        cout << endl;
        //cout << sum << endl;
    }

}

int main() {
// Hace más eficiente la entrada de datos
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
