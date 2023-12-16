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

pair<int,int> path(char m[][SIZE], int i, int j) {
    if(m[i+1][j] == '|') {
        return make_pair(i+1, j);
    } else if(m[i+1][j] == '7') { 
        return make_pair(i+1, j);
    } else if(m[i+1][j]  == 'F') {
        return make_pair(i+1, j);
    } else if(m[i-1][j] == '|') {
        return make_pair(i-1, j);
    } else if(m[i-1][j] == 'L') {
        return make_pair(i-1, j);
    } else if(m[i-1][j] == 'J') {
        return make_pair(i-1, j);
    } else if(m[i][j+1] == '-'){
        return make_pair(i, j+1);
    } else if(m[i][j+1] == 'J'){
        return make_pair(i, j+1);
    } else if(m[i][j+1] == '7'){
        return make_pair(i, j+1);
    } else if(m[i][j-1] == '-'){
        return make_pair(i, j-1);
    } else if(m[i][j-1] == 'L'){
        return make_pair(i, j-1);
    } else if(m[i][j-1] == 'F'){
        return make_pair(i, j-1);
    }
}
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
bool comp(pair<int, int> a, pair<int,int> b) {
    if((a.first == b.first) && (a.second == b.second)) {
        return false;
    } else
        return true;
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
    //pair<int,int> b;
    a = path_(m, s.first, s.second);
    //b = path_(m, s.first, s.second);
    int k = 1; int ia, ja;
    //int ib, jb, o = s.first, p = s.second;
    i = s.first; j = s.second;
    cout << "S en " << s.first << ", " << s.second << endl;
    cout << "a en " << a.first << ", " << a.second << endl;
    while((a.first != s.first) || (a.second != s.second)) {
        ia = a.first; ja = a.second;
        //ib = b.first; jb = b.second;
        a = cont(m, a.first, a.second, i, j);
        //b = cont(m, b.first, b.second, o, p);
        cout << "a en " << a.first << ", " << a.second << endl;
        i = ia; j = ja;
        //o = ib; p = jb;
        k++;
        cout << k << endl;
    }
    cout << k << endl;
    cout << k/2 << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
