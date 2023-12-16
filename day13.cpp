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
int cols(vector<string> m, int ini, int fin) {
     if(ini >= fin) {
        return 0;
    } 
    if((fin - ini) == 1) {
        for(int i = 0; i < m.size(); i++)
            if(m[i][ini] != m[i][fin])
                return 0;
        return ini;
    } else if((fin - ini) == 2) {
        int i = 0;
        if(m[i][ini] == m[i][fin-1]) {
            for(i = 0; i < m.size(); i++) 
                if(m[i][ini] != m[i][fin-1])
                    return 0;
            return ini;
        } else if(m[i][ini+1] == m[i][fin]) {
            for(i = 0; i < m.size(); i++) 
                if(m[i][ini+1] != m[i][fin])
                    return 0;
            return ini+1;
        } else {
            return 0;
        }   
    } else {
        int med = (fin+ini)/2;
        int j = 0;
        //cout << med << m[j][med] << endl;
        if(m[j][med] == m[j][med-1]) {
            for(j = 0; j < m.size(); j++) 
                if(m[j][med] != m[j][med-1])
                    break;
            if(j == m.size())
                for(j = 0; j < m.size(); j++) 
                    if(m[j][med+1] != m[j][med-2])
                        break;
            if(j == m.size())
                return med-1;
        }
        if(m[j][med] == m[j][med+1]) {
            //cout << med << endl;
            for(j = 0; j < m.size(); j++) 
                if(m[j][med] != m[j][med+1])
                    break;
            if(j == m.size())
                for(j = 0; j < m.size(); j++) 
                    if(m[j][med-1] != m[j][med+2])
                        break;
            if(j == m.size())
                return med;
        }
        int der = cols(m, med+1, fin) ;
        if(der)
            return der;
        else
            return cols(m, ini, med);
    }
}
void solve() {
    ll sum = 0;
    string InputLine;

    while(getline(cin, InputLine)) {
        vector<string> m;
        m.push_back(InputLine);
       while(getline(cin, InputLine)) {
            if(InputLine.empty())
                break;
            m.push_back(InputLine);
        }
        for(int i = 0; i < m.size(); i++)
            cout << m[i] << endl;
        int ro = rows(m, 0, m.size()-1) + 1;
        int co = cols(m, 0, m[0].size()-1) + 1;
        cout << "Rows: " << ro << endl;
        cout << "Cols: " << co << endl;
        if(ro > co) {
            sum += ro*100;
        } else {
            if(co > 1) {
                sum += co;
            }
        }
    }
    cout << "Total Arrangements: " << sum << endl;
}
 //34123   
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
