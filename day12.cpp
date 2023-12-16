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
ll recsol(string s, vector<int> n, int pos, int gr, int b) {
    while((pos < s.size()) && (s[pos] == '.')) {
        if(b > 0) { 
            n[gr] -= b;
            if(n[gr] != 0)
                return 0;
            gr++;
            b = 0;
        }
        pos++;
    }  
    
    while((pos < s.size()) && (s[pos] == '#')) {
        pos++; 
        b++;
    }
    if((pos >= s.size()) || (pos < 0) || (gr >= n.size())) {
        //for(int i = 0; i < s.size(); i++)
            cout << s;
        cout << endl << "Pos: " << pos << " Gr:" << gr << endl;
        if((gr >= n.size())) {
            if(n[gr-1] == 0) {
                cout << 1 << endl;
                return 1;
            } else {
                cout << 0 << endl;
                return 0; 
            }
        } else {
            if(b > 0) {
                n[gr] -= b;
                if(n[gr] != 0) {
                    cout << 0 << endl;
                    return 0;
                }
                //gr++;
                //b = 0;
                cout << 1 << endl;
                return 1;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }

     if(s[pos] == '?') {
        /*if(n[gr] == 0) {
            gr++;
            pos++;
            return recsol(s, n, pos, gr);
        } else if(n[gr] < 0) {
            return 0;
        } else {*/ // n[gr] > 0
            //pos++; 
            s[pos] = '.'; 
            ll o1 = recsol(s, n, pos, gr, b);
            //n[gr]--;
            s[pos] = '#'; 
            return o1 + recsol(s, n, pos, gr, b);
        //}
    }
}

void solve() {
    ll sum = 0;
    string InputLine;
    string s;
    string n;
     
     int i = 0;
    while(getline(cin, InputLine)) {
        vector<int> g;
        istringstream iss(InputLine);
        iss >> s; iss >> n;
        cout << "---------CASO " << i << "------------\n";
        cout << s << " " << n << endl;
        for(int i = 0; i < n.size(); i += 2) { 
            g.push_back(n[i] - '0');
            cout << n[i] - '0' << " ";
        }
        cout << endl;
        sum += recsol(s, g, 0, 0, 0); 
        cout << sum << endl;
        i++;
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
