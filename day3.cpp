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

vector<string> v;

void solve() {
    string a; int i = 0, p = 0, k;
    bool s = false;
    ll sum = 0, n;
    while(cin >> a) {
        v.emplace_back(a);
    }

    int j = v[i].size() - 1;
    while(j > -1) {
        n = 0; p = 0; s = false;
        if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
            s = true;
            j--;
        }
        if((v[i][j] >= '0') && (v[i][j] <= '9')) {
            n += (v[i][j] - '0') * pow(10, p);
            p++;
            //if(j > 0) {
                j--; 
                while((j > -1) && (v[i][j] >= '0') && (v[i][j] <= '9')) {
                    n += (v[i][j] - '0') * pow(10, p);
                    j--; p++;
                }
            //}
            if(j == -1) {
                j++;
            }
            if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
                s = true;
                j--;
            }
            if(s)
                sum += n;
            else {
            i++; //fila 1
            for(k = 0; (k < (p+2)) && (j < v.size());k++) {
                cout << v[i][j];
                if((v[i][j] != '.') && ((v[i][j] < '0') || (v[i][j] > '9'))) {
                    sum += n;
                    break;
                }
                j++;
            } //Vemos si hay símbolos en línea de abajo
            cout << k << endl;
            i--; j -= k;//volvemos a fila 0 y pos j
            }
            if(j > 0) 
                j++;
            cout << v[i][j] << endl;
        }
        j--;
    } // Recorremos fila 0
    std::cout << sum << endl;

    i++; //Fila 1
    
    while(i < (v.size() - 1)) {
        j = v.size() - 1; 
        while(j > -1) {
        n = 0; p = 0; s = false;
        if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
            s = true;
            j--;
        }
        if((v[i][j] >= '0') && (v[i][j] <= '9')) {
            n += (v[i][j] - '0') * pow(10, p);
            p++;
           // if(j > 0) {
                j--; 
                while((j > -1) && (v[i][j] >= '0') && (v[i][j] <= '9')) {
                    n += (v[i][j] - '0') * pow(10, p);
                    j--; p++;
                }
            //}
            if(j == -1) {
                j++; 
            }
            if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
                s = true;
                j--;
            }
            if(s)
                sum += n;
            else {
            i++; //fila i+1
            for(k = 0; (k < (p+2)) && (j < v.size());k++) {
                cout << v[i][j];
                if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
                    sum += n;
                    s = true;
                    break;
                }
                j++;
            } //Vemos si hay símbolos en línea de abajo
            cout << endl;
            i--; j -= k;//volvemos a fila i y pos j
            cout << v[i][j] << endl;

            if(!s) {
                i--; //fila i-1
                for(k = 0; (k < (p+2)) && (j < v.size());k++) {
                    cout << v[i][j];
                    if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
                        sum += n;
                        break;
                    }
                    j++;
                } //Vemos si hay símbolos en línea de abajo
                cout << endl;
                i++; j -= k;//volvemos a fila i y pos j
            }
        }
            if(j > 0) 
                    j++;
                cout << v[i][j] << endl;
        }
        j--;
    } // recorremos fila i

        std::cout << sum << endl;
        i++;
    } // Recorremos matriz

    j = v.size() - 1;
    while(j > -1) {
        n = 0; p = 0; s = false;
        if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
            s = true;
            j--;
        }
        if((v[i][j] >= '0') && (v[i][j] <= '9')) {
            n += (v[i][j] - '0') * pow(10, p);
            p++;
            //if(j > 0) {
                j--; 
                while((j > -1) && (v[i][j] >= '0') && (v[i][j] <= '9')) {
                    n += (v[i][j] - '0') * pow(10, p);
                    j--; p++;
                }
            //}
            if(j == -1) {
                j++; 
            }
                if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
                s = true;
                j--;
            }
            if(s)
                sum += n;
            else {
            i--; //fila penúltima
            for(k = 0; (k < (p+2)) && (j < v.size());k++) {
                cout << v[i][j];
                if((v[i][j] != '.') && (v[i][j] < '0') || (v[i][j] > '9')) {
                    sum += n;
                    break;
                }
                j++;
            } //Vemos si hay símbolos en línea de abajo
            cout << endl;
            i++; j -= k;//volvemos a fila última y pos j
            }
            if(j > 0) 
                j++;
            cout << v[i][j] << endl;
        }
        j--;
    } // recorremos última fila
    std::cout << sum << endl;


    /*if((v[i][j] >= '0') && (v[i][j] <= '9')) {
        if((v[1][j] < '0') || (v[1][j] > '9')) {
            while((v[i][j] >= '0') && (v[i][j] <= '9')) {
                sum += (v[i][j] - '0') * pow(10, p);
                j--; p++;
            }
        } else if((v[1][j-1] < '0') || (v[1][j-1] > '9')) {
            j--;
            while((v[i][j] >= '0') && (v[i][j] <= '9')) {
                sum += (v[i][j] - '0') * pow(10, p);
                j--; p++;
            }
        }
    }
    j--;
    while(j > 0) {
        if((v[i][j] >= '0') && (v[i][j] <= '9')) {
        if((v[1][j] < '0') || (v[1][j] > '9')) {
            while((v[i][j] >= '0') && (v[i][j] <= '9')) {
                sum += (v[i][j] - '0') * pow(10, p);
                j--; p++;
            }
        } else if((v[1][j-1] < '0') || (v[1][j-1] > '9')) {
            j--;
            while((v[i][j] >= '0') && (v[i][j] <= '9')) {
                sum += (v[i][j] - '0') * pow(10, p);
                j--; p++;
            }
        }
    }
    j--;
    } 

    for(i = 1; i < (v.size() - 1); i++) {
        j = 0;
        while(j < v[i].size()) {

        }
    }
    j = 0;
    while(j < v[i].size()) {
        
    }*/

}

int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
