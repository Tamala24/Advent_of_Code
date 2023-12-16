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
// Función para calcular el máximo común divisor (MCD) utilizando el algoritmo de Euclides
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Función para calcular el mínimo común múltiplo (LCM) utilizando el MCD
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
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

    vector<string> v;
    cout << "Clave con A: ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        // Obtener la clave y el par asociado
        const std::string& clave = it->first;
       // const std::pair<std::string, std::string>& valores = it->second;

        // Acceder a los elementos del par
        //const std::string& valor1 = valores.first;
        //const std::string& valor2 = valores.second;

        if(clave[2] == 'A') {
            cout << clave << " ";
            v.push_back(clave);
        }
    }

    cout << endl;

   ll steps[v.size()]; 
    for(int i = 0; i < v.size(); i++) {
        sum = 0; end = true;
        while(end) {
            for(char c : r) {
                auto it = m.find(v[i]);
                if(it->first[2] == 'Z') {
                    steps[i] = sum;
                    end = false;
                    break;
                } else if(c == 'R') {
                    v[i] = it->second.second;
                } else
                    v[i] = it->second.first;
                sum++;
            }
            if(!end) 
                break;  
        }
    }
    for(int w = 0; w < (v.size()-1); w++) {
        steps[w+1] = lcm(steps[w], steps[w+1]);
    }
    cout << steps[v.size()-1] << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
