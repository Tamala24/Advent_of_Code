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
#define SIZE 21
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
int num_dig(int N) {
    return floor(log10(N)) + 1;
}

ll dif(long m[][SIZE+1], int ini, int fin, int i) {
    if(ini >= fin)
        return m[i+1][ini];

    int med = (ini+fin)/2;
    m[i+1][med] = m[i][med+1] - m[i][med];
    return abs(m[i+1][med]) + abs(dif(m, 0, med, i)) + abs(dif(m, med+1, fin, i));
}
ll sol(long m[][SIZE+1], int j, int k) {
    if(j < 1)
        return m[j][k];
    m[j-1][k+1] = m[j-1][k] + m[j][k];
    cout << m[j-1][k+1] << " ";
    return sol(m, j-1, k+1);
}

void solve() {
    ll sum = 0;
    ll a;
    string InputLine;
    while(getline(cin, InputLine)) {
        long m[SIZE][SIZE+1] = {-1};
        istringstream iss(InputLine);
        for(int i = 0; i < 21; i++) {
            iss >> m[0][i];
        }
        int j = 0; int k = SIZE-1;
        while(dif(m, 0, k, j)) {
            j++; k--;
        }
        //k++;
        j++; 
        cout << m[j][k] << endl;
        m[j][k] = 0;
        a = sol(m, j, k);
        sum += a;
        cout << endl << a << endl;
    }
    cout << "Suma: " << sum << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
