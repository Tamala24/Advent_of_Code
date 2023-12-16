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

bool binaria(int x, vector<int> a, int ini, int end) {
        if(ini > end)
                return false;
        int m = (end + ini)/2;
        if(a[m] == x) {
                return m;
        } else if(a[m] > x) {
                return binaria(x, a, ini, m - 1);
        } else {
                return binaria(x, a, m + 1, end);
        }
}

void solve() {
    ll sum = 0;
    string inputLine;
    // Variables para almacenar los datos
    std::string token;
    //std::vector<int> winners;
    //std::vector<int> cards;
    int w;
    int v;
    bool y;
    
    while(getline(std::cin, inputLine)) {
        v = 0; y = false; std::vector<int> cards;
        std::istringstream iss(inputLine);
        iss >> token; // "Card"
        iss >> token; // "X:"
        while(iss >> token) {
            if(token == "|") {
                //cout << token << " ";
                break;
            } else {
                //cout << token << " ";
                cards.push_back(stoi(token));
            }
        }
        /*for(int i = 0; i < cards.size();i++) 
            cout << cards[i] << " ";
        cout << endl;*/
        sort(cards.begin(), cards.end());
        while(iss >> token) {
            w = stoi(token);
            //cout << w << " ";
            //cout << token << " ";
            //binary_search(cards.begin(), cards.end(), w)
            //binaria(w, cards, 0, cards.size()-1)
            if(binary_search(cards.begin(), cards.end(), w)) {
                if(y) {
                   cout << w << " ";
                    v = v << 1;
                } else {
                    cout << w << " ";
                    v = 1;
                    y = true;
                }
            }
        }
        //cout << v << endl;
        cout << endl;
        sum += v;
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
