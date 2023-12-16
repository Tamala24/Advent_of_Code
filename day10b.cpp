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
//7 i2
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
int num_dig(int N) {
    return floor(log10(N)) + 1;
}

pair<int,int> path(bool b[][SIZE], int i, int j, pair<int,int> med) {
    if(b[i+1][j]) {
        if(b[i-1][j]) {
            return make_pair(1, 0);
        } else if(b[i][j+1]) {
            return make_pair(0, 1);
        } else if(b[i][j-1]) {
            return make_pair(0, -1);
        }
    } else if(b[i-1][j]) {
        if(b[i][j+1]) {
            return make_pair(0,1);
        } else if(b[i][j-1]) {
            return make_pair(-1, 0);
        }
    } else if(b[i][j-1]) {
        if(b[i][j+1]) {
            return make_pair(0, 1);
        }   
    }
}
/*pair<int,int> path(char m[][SIZE], int i, int j) {
    if(m[i+1][j] == '|') {
        return make_pair(1, 0);
    } else if(m[i-1][j] == '7') { 
        return make_pair(-1, 0);
    } else if(m[i-1][j]  == 'F') {
        return make_pair(-1, 0);
    } else if(m[i-1][j] == '|') {
        return make_pair(-1, 0);
    } else if(m[i+1][j] == 'L') {
        return make_pair(1, 0);
    } else if(m[i+1][j] == 'J') {
        return make_pair(1, 0);
    } else if(m[i][j+1] == '-'){
        return make_pair(0, 1);
    } else if(m[i][j+1] == 'J'){
        return make_pair(0, 1);
    } else if(m[i][j+1] == '7'){
        return make_pair(0, 1);
    } else if(m[i][j-1] == '-'){
        return make_pair(0, -1);
    } else if(m[i][j-1] == 'L'){
        return make_pair(0, -1);
    } else if(m[i][j-1] == 'F'){
        return make_pair(0, -1);
    }
}*/
pair<int,int> path_(char m[][SIZE], int i, int j) {
    if((m[i][j-1] == '-') || (m[i][j-1] == 'L') || (m[i][j-1] == 'F')){
        return make_pair(i, j-1);
    } else if((m[i][j+1] == 'J') || (m[i][j+1] == '7') || (m[i][j+1] == '-')) {
        return make_pair(i, j+1);
    } else if((m[i-1][j] == '|') || (m[i-1][j] == '7') || (m[i-1][j] == 'F')) {
        return make_pair(i-1, j);
    } else if((m[i+1][j] == '|') || (m[i+1][j] == 'L') || (m[i+1][j]  == 'J')) {
        return make_pair(i+1, j);
    } 
}
pair<int,int> cont(char m[][SIZE], int i, int j, int ia, int ja) {
    if(m[i][j] == '|') {
        if(ia == i+1) {
            return make_pair(i-1, j);
        } else
            return make_pair(i+1, j);
    } else if(m[i][j] == '-') {
        if(ja == j+1) {
            return make_pair(i, j-1);
        } else
            return make_pair(i, j+1);
    } else if(m[i][j] == 'L') {
        if(ja == j+1) {
            return make_pair(i-1, j);
        } else
            return make_pair(i, j+1);
    } else if(m[i][j] == 'J') {
        if(ja == j-1) {
            return make_pair(i-1, j);
        } else
            return make_pair(i, j-1);
    } else if(m[i][j] == '7') {
        if(ja == j-1) {
            return make_pair(i+1, j);
        } else
            return make_pair(i, j-1);
    } else if(m[i][j] == 'F') {
        if(ja == j+1) {
            return make_pair(i+1, j);
        } else
            return make_pair(i, j+1);
    }
}
pair<int,int> cont_(char m[][SIZE], int i, int j, int ia, int ja) {
    if(m[i][j] == '|') {
        if(ia == i+1) {
            return make_pair(-1, 0);
        } else
            return make_pair(1, 0);
    } else if(m[i][j] == '-') {
        if(ja == j+1) {
            return make_pair(0, -1);
        } else
            return make_pair(0, 1);
    } else if(m[i][j] == 'L') {
        if(ja == j+1) {
            return make_pair(-1, 0);
        } else
            return make_pair(0, 1);
    } else if(m[i][j] == 'J') {
        if(ja == j-1) {
            return make_pair(-1, 0);
        } else
            return make_pair(0, -1);
    } else if(m[i][j] == '7') {
        if(ja == j-1) {
            return make_pair(1, 0);
        } else
            return make_pair(0, -1);
    } else if(m[i][j] == 'F') {
        if(ja == j+1) {
            return make_pair(1, 0);
        } else
            return make_pair(0, 1);
    }
}
bool comp(pair<int, int> a, pair<int,int> b) {
    if((a.first == b.first) && (a.second == b.second)) {
        return false;
    } else
        return true;
}
int dentro(bool b[][SIZE], pair<int,int> d, pair<int,int> a) {
    long k = 0;
    if(d.first == 1) {
        for(int i = a.second + 1; i < (SIZE-1); i++) {
            if(!b[a.first][i]) {
                k++;
                b[a.first][i] = true;
            } else 
                break;
        }
    } else if(d.first == -1) {
         for(int i = a.second-1; i > 0; i--) {
            if(!b[a.first][i]) {
                k++;
                b[a.first][i] = true;
            } else 
                break;
        }
    } else if(d.second == 1){
        for(int i = a.first-1; i > 0; i--) {
            if(!b[i][a.second]) {
                k++;
                b[i][a.second] = true;
            } else 
                break;
        }
    } else { // d.second == -1
         for(int i = a.second + 1; i < (SIZE-1); i++) {
            if(!b[i][a.second]) {
                k++;
                b[i][a.second] = true;
            } else 
                break;
        }
    } 
    return k;
}

void solve() {
    //ll sum = 0;
    string InputLine;
    char c;
    pair<int, int> s;
    char m[SIZE][SIZE];

    for(int w = 0; w < SIZE; w++) 
        m[0][w] = '.';
    int i = 1; int j;
    while(getline(cin, InputLine)) {
        m[i][0] = '.';
        j = 1; 
        istringstream iss(InputLine);
        while(iss >> c) {
            m[i][j] = c;
            if(c == 'S') {
                s.first = i; s.second = j;
            }
            j++;
        }
        m[i][j] = '.';
        i++;
    }
    for(int w = 0; w < SIZE; w++) 
        m[i][w] = '.';

    for(int w = 0; w < SIZE; w++) {
        for(int q = 0; q < SIZE; q++) 
            cout << m[w][q] << " ";
        cout << endl;
    }
    pair<int,int> a; 
    pair<int,int> d;
    pair<int,int> med;
    bool b[SIZE][SIZE] = {false};
    int ia, ja; long k = 1;

    b[s.first][s.second] = true;
    a = path_(m, s.first, s.second);
    b[a.first][a.second] = true;
    i = s.first; j = s.second;
    cout << "S en " << s.first << ", " << s.second << endl;
    cout << "a en " << a.first << ", " << a.second << endl;
    while((a.first != s.first) || (a.second != s.second)) {
        ia = a.first; ja = a.second;
        a = cont(m, a.first, a.second, i, j);
        b[a.first][a.second] = true;
        cout << "a en " << a.first << ", " << a.second << endl;
        i = ia; j = ja;
        k++;
        if(k == 6831) {
            med.first = a.first;
            med.second = a.second;
        }
    }


    a = s;
    d = path(b, s.first, s.second, med);
    a.first += d.first;
    a.second += d.second;
    k = 0;
    k += dentro(b, d, a);
    i = s.first; j = s.second;
    cout << "S en " << s.first << ", " << s.second << endl;
    cout << "a en " << a.first << ", " << a.second << endl;
    while((a.first != s.first) || (a.second != s.second)) {
        ia = a.first; ja = a.second;
        d = cont_(m, a.first, a.second, i, j);
        a.first += d.first;
        a.second += d.second;
        k += dentro(b, d, a);
        cout << "a en " << a.first << ", " << a.second << endl;
        i = ia; j = ja;
    }
    cout << "Dentro: " << k << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
