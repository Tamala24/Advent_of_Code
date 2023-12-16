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
    ll min = LLONG_MAX;
    pair<ll,ll> r;
    std::string token;
    int i;
    ll j;
    int w = 0;
    int k;
    long wt = 1;
    
    
    cin >> token;   
    cin >> k;
    r.first = k;
    REP(i,1,RACES) {
        cin >> k;
        r.first *= pow(10, num_dig(k));
        r.first += k;
    }
    cout << r.first << endl;
    cin >> token;   
    cin >> k;
    r.second = k;
    REP(i,1,RACES) {
        cin >> k;
        r.second *= pow(10, num_dig(k));
        r.second += k;
    }
    cout << r.second << endl;

    w = 0;
    REP(j,1,r.first) {
        if((r.first-j)*j > r.second)
            w += 1;
    }
    wt *= w;
    cout << wt << endl; 

}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
