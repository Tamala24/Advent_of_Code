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
#define SIZE 142
#define EXP 1000000

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
int num_dig(int N) {
    return floor(log10(N)) + 1;
}
int rows(vector<string> m, int ini, int fin) {
    if(ini >= fin) {
        return 0;
    } 
    if((fin - ini) == 1) {
        if(m[ini] == m[fin])
            return ini;
    } else if((fin - ini) == 2) {
        if(m[ini] == m[fin-1]) {
            return ini;
        } else if(m[ini+1] == m[fin]) {
            return ini+1;
        } else {
            return 0;
        }   
    } else {
        int med = (fin+ini)/2;
        if(m[med] == m[med-1]) {
            if(m[med+1] == m[med-2])
                return med-1;
        } else if(m[med] == m[med+1]) {
            if(m[med-1] == m[med+2])
                return med;
        } else {
            int der = rows(m, med+1, fin);
            if(der)
                return der;
            else
                return rows(m, ini, med);
        }   
    }
}
void cols(vector<string> m, int ini, int fin, ll& sum) {
     if(ini >= fin) {
         int j; int r = -1; int o = 1 ;int i;
        //cout << med << m[j][med] << endl;
            for(j = 0; j < m.size(); j++) 
                if(m[j][ini] == '#') {
                    o = 1;
                    for(i = j-1; i > r; i--) {
                        if(m[i][ini] == 'O') {
                            sum += m.size() - (r+o);
                            //m[r+o][ini] = 'O';
                            //m[i][ini] = '.';
                            o++;
                        }
                    }
                    r = j;
                }
        return;
    } 
        int med = (fin+ini)/2;
        cols(m, med+1, fin, sum);
        cols(m, ini, med, sum);
    
}
void solve() {
    ll sum = 0;
    string InputLine;
    vector<string> m;

    while(getline(cin, InputLine)) {
        m.push_back(InputLine);
    }
        for(int i = 0; i < m.size(); i++) {
            cout << m[i] << endl;

        }
        //int ro = rows(m, 0, m.size()-1) + 1;
        cout << endl;
        cols(m, 0, m[0].size()-1, sum);
        /*for(int i = 0; i < m.size(); i++) {
            cout << m[i] << endl;
            for(int j = 0; j < m[0].size(); j++) {
                if(m[i][j] == 'O') {
                    sum += m.size() - i;
                }
            }
        }*/

    cout << "Total: " << sum << endl;
}
 //34123   
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
