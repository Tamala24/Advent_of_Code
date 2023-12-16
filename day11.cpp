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
//142 i
//13 i2
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
int num_dig(int N) {
    return floor(log10(N)) + 1;
}
/*long shortest_path(vector<vector<long>> m, pair<int,int> o, pair<int,int> d, int i, int j, int modo) {
    if((o.first < 0) || (o.first >= i) || (o.second < 0) || (o.second >= j)) {
        return LONG_MAX;
    } else {
        if(m[o.first][o.second] < LONG_MAX) {
            return m[o.first][o.second];
        } else if((o.first == d.first) && (o.second == d.second)) {
            return 0;
        } else {
            switch (modo) {
            case 1:
                m[o.first][o.second] = 1 + min(shortest_path(m,make_pair(o.first+1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second+1),d,i,j,modo));
                break;
            case 2:
                m[o.first][o.second] = 1 + min(shortest_path(m,make_pair(o.first+1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second-1),d,i,j,modo));
                break;
            case 3:
                m[o.first][o.second] = 1 + min(shortest_path(m,make_pair(o.first-1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second+1),d,i,j,modo));
                break;
            case 4:
                m[o.first][o.second] = 1 + min(shortest_path(m,make_pair(o.first-1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second-1),d,i,j,modo));
                break;
            }
            //m[o.first][o.second] = 1 + min(min(min(shortest_path(m,make_pair(o.first+1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second+1),d,i,j,modo)), min(shortest_path(m,make_pair(o.first+1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second-1),d,i,j,modo))), min(min(shortest_path(m,make_pair(o.first-1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second+1),d,i,j,modo)),min(shortest_path(m,make_pair(o.first-1, o.second),d,i,j,modo), shortest_path(m,make_pair(o.first, o.second-1),d,i,j,modo))));
        }
    }
    return m[o.first][o.second];
}*/

/*long shortest_path_(vector<vector<char>> m, pair<int,int> o, pair<int,int> d, int i, int j) {
    vector<vector<long>> m2(i, vector<long>(j, LONG_MAX));
    int modo = 0;
    if(o.first < d.first) {
        if(o.second < d.second) {
            modo = 1; // o arriba izquierda
        } else {
            modo = 2; // o arriba derecha
        }
    } else {
        if(o.second < d.second) {
            modo = 3; // o abajo izquierda
        } else {
            modo = 4; // o abajo derecha
        }
    }
    //return modo;
    return shortest_path(m2, o, d, i, j, modo);
}*/



void solve() {
    ll sum = 0;
    string InputLine;
    char c;
    vector<pair<int, int>> g;
    vector<vector<char>> m; 
    

    int i = 0; int j; int n;
    while(getline(cin, InputLine)) {
        m.push_back(std::vector<char>());
        j = 0; n = 0;
        istringstream iss(InputLine);
        while(iss >> c) {
            m[i].push_back(c);
            if(c == '#') {
                g.push_back(make_pair(i,j));
                //m[i].push_back('.');
                n++; //j++;
            }
            j++;
        }
        if(n == 0) {
            m.push_back(vector<char>(j, '.'));
            i++;
        }
        i++;
    }
    vector<vector<char>> m2(i);
    int j2 = 0;
    for(int w = 0; w < j; w++) {
        n = 0;
        for(int q = 0; q < g.size(); q++) 
            if(w == g[q].second) {
                n++;
                break;
            }
        if(n > 0) {
            for(int q = 0; q < i; q++) 
                m2[q].push_back(m[q][w]);
        } else {
            for(int q = 0; q < i; q++) {
                m2[q].push_back('.');
                m2[q].push_back('.');
            }
                j2++;
        }
        j2++;
    }
    vector<pair<int,int>> g2;
    //cout << j2 << " " << j << endl; 
    for(int w = 0; w < i; w++) {
        for(int q = 0; q < j2; q++) {
            cout << m2[w][q] << " ";
            if(m2[w][q] == '#') 
                g2.push_back(make_pair(w,q));
        }
        cout << endl;
    }
    int aux;
    bool mv[g2.size()][g2.size()] = {false};
    for(int q = 0; q < g2.size(); q++) {
        cout << "Origen: " << g2[q].first << " " << g2[q].second << endl << "Destinos: ";
        for(int w = 0; w < g2.size(); w++) {
            // (w != q) &&  && (!mv[w][q])
            if((!mv[q][w])) {
                mv[q][w] = true;
                mv[w][q] = true;
                aux = abs(g2[q].first - g2[w].first) + abs(g2[q].second - g2[w].second);
                //sum += shortest_path_(m2, g[q], g[w], i, j2);
                sum += aux;
                cout << g2[w].first << " " << g2[w].second << " Dist: ";
                cout << aux << "; ";
                //cout << "Modo: " << shortest_path_(m2, g[q], g[w], i, j2) << endl;
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
