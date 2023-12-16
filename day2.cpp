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
//only 12 red cubes, 13 green cubes, and 14 blue cubes
int n[3] = {12, 13, 14};

void solve() {
    // Lee la línea de entrada
    string inputLine;
    // Variables para almacenar los datos
    string token; 
    int q; int sum = 0; bool p; int id = 0;
    int r = 0, g = 0, b = 0;
    //std::vector<std::string> colors;
    //std::vector<int> quantities;
    
   //while(getline(cin, inputLine)) {
        //id++;
        //std::cout << "id: " << id << endl;
        // Utiliza un stringstream para dividir la cadena en palabras
        //istringstream iss(inputLine);
        // Ignora el texto inicial "Game X:"
    while(cin >> token) { // "Game"
        cin >> token; // "X:"
        id++;
        cout << token << endl;
        cout << "id: " << id << endl;
        p = true; r = 0; g = 0; b = 0;
        while (cin >> q) {
            cin >> token; //color
            cout << q << " " << token << endl;
            if (token[0] == 'r') {
                if(q > r)
                    r = q;
                    //r += q;
                //if(q > n[0])
                    //p = false;   
            } else if(token[0] == 'g') {
                if(q > g)
                    g = q;
                    //g += q;
                //if(q > n[1])
                    //p = false;
            } else if(token[0] == 'b') {
                if(q > b)
                    b = q;
                    //b += q;
                //if(q > n[2])
                    //p = false;
            }   
            if(token[token.size()-1] > 'A') {
                //if(p)
                    //sum += id;
                cout << r << " " << g << " " << b << endl;
                sum += r*g*b;
                cout << "id: " << id << endl;
                cout << "summinset: "<< sum << endl;
                //cout << sum << endl;
                break;
            }
        }  
    //}
    //cout << sum << endl;
    }
}

int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
