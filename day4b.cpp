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

void solve() {
    ll sum = 0;
    string inputLine;
    // Variables para almacenar los datos
    std::string token;
    std::vector<int> winners;
    //std::vector<int> cards;
    int w, c = 0;
    int v;
    bool y;
    
    while(getline(std::cin, inputLine)) {
        c++;
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
            if(binary_search(cards.begin(), cards.end(), w)) {
                   cout << w << " ";
                    v += 1;
            }
        }
        winners.push_back(v);
        //cout << v << endl;
        cout << endl;
        //sum += v;
    }
    std::vector<int> sc(c, 1);
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < sc[i]; j++) {
         for(int k = 1;k <= winners[i]; k++) {
            sc[i+k]++;
            //winners[i]--;
         }
        }
        cout << sc[i] << " ";
        sum += sc[i];
    }
    cout << endl << sum << endl;
}

int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
