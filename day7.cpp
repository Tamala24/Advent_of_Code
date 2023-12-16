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

class Nodo {
    public:
    pair<string, int> v;
    Nodo* i;
    Nodo* d;

    Nodo(string val, int n) : i(nullptr), d(nullptr) {
        v.first = val;
        v.second = n;
    }
    ~Nodo() {
        delete[] i;
        delete[] d;
        delete this; 
    }
};
int c1[13] = {0};
int c2[13] = {0};
char h[13] = {'A','K','Q','T','9','8','7','6','5','4','3','2','J'};

bool comp(string &a, string &b) {
    int t1 = 0, t2 = 0;
    for(char c: a) {
        REP(i,0,13) {
            if(h[i] == c)
                c1[i] += 1;
        }
    }
    for(char c: b) {
        REP(i,0,13) {
            if(h[i] == c)
                c2[i] += 1;
        }
    }
    int max = 0;
    if(c1[12] > 0)
        REP(i,0,12) 
            if(c1[i] > c1[max])
                max = i;
    c1[max] += c1[12];
    max = 0;
    c1[12] = 0;
    if(c2[12] > 0)
         REP(i,0,12) 
            if(c2[i] > c2[max])
                max = i;
    c2[max] += c2[12];
    c2[12] = 0;
    max = 0;
    REP(i,0,12) {
            if(c1[i] == 5)
                t1 = 6;
            else if(c1[i] == 4)
                t1 = 5;
            else if(c1[i] == 3)
                t1 += 3;
            else if(c1[i] == 2)
                t1 += 1;
            c1[i] = 0;
            if(c2[i] == 5)
                t2 = 6;
            else if(c2[i] == 4)
                t2 = 5;
            else if(c2[i] == 3)
                t2 += 3;
            else if(c2[i] == 2)
                t2 += 1;
            c2[i] = 0;
    }
    cout << a << " " << t1 << endl;
    cout << b << " " << t2 << endl;
    
    if(t1 > t2)
        return true;
    else if(t1 < t2)
        return false;
    else {
        REP(i,0,5) {
            int j1 = 0, j2 = 0;
            while(a[i]!=h[j1]) 
                j1++;
            while(b[i]!=h[j2]) 
                j2++;   
            if(j1 < j2)
                return true;
            else if(j1 > j2)
                return false;
        }
        return true; // Si son iguales
    }
}

Nodo* insertar_en_bst(Nodo* raiz, string valor, int n) {
    // Si la raíz es nula, crea un nuevo nodo como raíz
    if (raiz == nullptr) {
        return new Nodo(valor, n);
    }

    // Si el valor es menor, inserta en el subárbol izquierdo
    if (comp(raiz->v.first, valor)) {
        raiz->i = insertar_en_bst(raiz->i, valor, n);
    }
    // Si el valor es mayor, inserta en el subárbol derecho
    else {
        raiz->d = insertar_en_bst(raiz->d, valor, n);
    }

    return raiz;
}

vector<int*> r;

int* inorden_inverso(Nodo* raiz) {
    if (raiz != nullptr) {
        // Primero recorre el subárbol derecho
        //r.push_back(inorden_inverso(raiz->d));
        inorden_inverso(raiz->d);
        r.push_back(&(raiz->v.second)); 
        inorden_inverso(raiz->i);
        cout << raiz->v.second << endl;
        //r.push_back(inorden_inverso(raiz->i));
        // Luego imprime el valor del nodo actual
        //std::cout << raiz->v << " ";
        // Finalmente recorre el subárbol izquierdo
        //inorden_inverso(raiz->i);
        return nullptr;
    } else 
        return nullptr;
}

void solve() {
    std::string t;
    int b;
    ll sum = 0;
    cin >> t;
    cin >> b;
    Nodo* raiz = nullptr;
    raiz = insertar_en_bst(raiz, t, b);
    cout << "Holi" << endl;
    while(cin >> t) {   
        cin >> b;
        insertar_en_bst(raiz, t, b);
        cout << "Holi2" << endl;
    } 
    cout << "Holi3" << endl;
    inorden_inverso(raiz);
    cout << "Holi4" << endl;
    int j = 1;
    for(int i = r.size()-1; i > -1; i--){
        cout << (*r[i]) << " " << j << endl;
        sum += (*r[i]) * j;
        cout << "Holi5" << endl;
        j++;
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
