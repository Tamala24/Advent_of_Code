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
ll recsol(string s, vector<int> n, int pos) {
    /*while((pos < s.size()) && (s[pos] == '.')) {
        pos++;
        cout << pos << endl;
    }
    while((pos < s.size()) && (s[pos] == '#')) {
        pos++; 
    }*/
    while((pos < s.size()) && (s[pos] != '?')) {
        pos++; 
    }
    //cout << s.size() << endl;
 
    if((pos >= s.size()) || (pos < 0)) {
        int gr = 0; int i = 0; int b = 0;
        /*while(s[i] == '.')
            i++;
        while(s[i] == '#') {
            n[gr]--;
            i++;
        }
        if(n[gr] != 0) {
            cout << "Caso 1\n";
            return 0;
        }
        gr++;*/
        while(i < s.size()) {
            if(s[i] == '.') {
                if(b > 0) {
                    n[gr] -= b;
                    if(n[gr] != 0) {
                 //       cout << "Caso 2\n";
                        return 0;
                    }
                    gr++;
                    b = 0;
                }
            } else {
                b++;
            }
            i++;
        }
        
        cout << s << endl;
        cout << "Gr: " << gr << " " << n.size() <<  endl;
        if(gr >= n.size()) {
            
            while(gr >= n.size()) gr--;
            if(n[gr] == 0) {
                
                 if(b > 0) {
                    //cout << "Caso 9\n";

                    return 0;
                 }

                 //cout << s << endl;
                cout << "Caso 3\n";
                return 1;
            } else {
                
                if(b > 0) {
                    n[gr] -= b;
                }
                if(n[gr] != 0) {
                  //  cout << "Caso 4\n";
                    return 0;
                } else {
                     //cout << s << endl;
                    cout << "Caso 8\n";
                    return 1;
                }
                
            }
        } else {
            
            //cout << gr << endl;
            if(gr < (n.size()-1)) {
                //cout << "Caso 7\n"; 
                return 0;
            }
            //gr = n.size()-1;
            if(b > 0) {
                n[gr] -= b;  
            }
                
            if(n[gr] != 0) {
                //cout << "Caso 5\n";
                return 0;
            } else {
                 //cout << s << endl;
                cout << "Caso 6\n"; 
                return 1;
            }
        } 
    }
    if((pos < s.size()) && (s[pos] == '?')) {
        s[pos] = '.'; //pos++; 
        //cout << s << endl;
        ll o1 = recsol(s, n, pos);
        //pos--; 
        s[pos] = '#'; 
        //cout << s << endl;
        //pos++;
        
        return o1 + recsol(s, n, pos);
    }
    //pos++;
}

void solve() {
    ll sum = 0;
    string InputLine;
    string s;
    string n;
     
     
    while(getline(cin, InputLine)) {
        vector<int> g;
        istringstream iss(InputLine);
        iss >> s; iss >> n;
        cout << s << " " << n << endl;
        for(int i = 0; i < n.size(); i += 2) { 
            g.push_back(n[i] - '0');
            cout << n[i] - '0' << " ";
        }
        cout << endl;
        sum += recsol(s, g, 0); 
        cout << sum << endl;
    }
    cout << "Total Arrangements: " << sum << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
