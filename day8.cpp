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
#define RACES 4
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
int num_dig(int N) {
    return floor(log10(N)) + 1;
}

void solve() {
    std::string k, i, d;
    std::string a, r;
    ll sum = 0; 
    bool end = true;
    // Crear un mapa con claves de tipo int y valores de tipo string
    std::map<std::string, pair<std::string, std::string>> m;

    cin >> r;// Recorrido
    while(cin >> k) {
        cout << k << " ";
        cin >> a;
        cin >> a; i = a.substr(1,3);
        cout << i << " ";
        cin >> a; d = a.substr(0,3);
        cout << d << endl;
        m.insert(std::make_pair(k, std::make_pair(i, d)));
    } // Mapa de nodos

    // Buscar un elemento en el mapa
    auto it = m.find("AAA");
    while(end) {
        for(char c : r) {
            if(it->first == "ZZZ") {
                end = false;
                break;
            } else if(c == 'R') {
                it = m.find(it->second.second);
            } else
                it = m.find(it->second.first);
            sum++;
        }
    }
    cout << sum << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
