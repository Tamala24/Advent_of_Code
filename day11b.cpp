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

void solve() {
    ll sum = 0;
    string InputLine;
    char c;
    vector<pair<int, int>> g;
    vector<vector<char>> m; 
    vector<vector<int>> f; 
    int vacias = 0;
    int i = 0; int j; int n;
    while(getline(cin, InputLine)) {
        m.push_back(std::vector<char>());
        j = 0; n = 0;
        istringstream iss(InputLine);
        while(iss >> c) {
            m[i].push_back(c);
            if(c == '#') {
                g.push_back(make_pair(i,j));
                n++; 
            }
            j++;
        }
        if(n == 0) {
            vacias++; 
        }
        f.push_back(vector<int>(j, vacias));
        i++;
    }
    vector<vector<int>> col(i); 
    vacias = 0;
    for(int w = 0; w < j; w++) {
        n = 0;
        for(int q = 0; q < g.size(); q++) 
            if(w == g[q].second) {
                n++;
                break;
            }
        if(n > 0) {
        } else {
            vacias++;
        }
        for(int q = 0; q < i; q++) 
            col[q].push_back(vacias);
    }
  
    for(int w = 0; w < i; w++) {
        for(int q = 0; q < j; q++) 
            cout << m[w][q] << " ";
        cout << endl;
    }

    ll aux;
    bool mv[g.size()][g.size()] = {false};
    for(int q = 0; q < g.size(); q++) {
        cout << "Origen: " << g[q].first << " " << g[q].second << endl << "Destinos: ";
        for(int w = 0; w < g.size(); w++) {
            if((w != q) && (!mv[q][w])) {
                mv[q][w] = true;
                mv[w][q] = true;
                aux = (abs(g[q].first - g[w].first) + (abs(f[g[w].first][g[w].second] - f[g[q].first][g[q].second])*EXP - abs(f[g[w].first][g[w].second] - f[g[q].first][g[q].second]))) + (abs(g[q].second - g[w].second) + (abs(col[g[w].first][g[w].second] - col[g[q].first][g[q].second])*EXP - abs(col[g[w].first][g[w].second] - col[g[q].first][g[q].second])));
                sum += aux;
                cout << g[w].first << " " << g[w].second << " Dist: ";
                cout << aux << "; ";
            }       
        }
        cout << endl;
    }
    cout << "Sum de caminos mas cortos: " << sum << endl;  
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
