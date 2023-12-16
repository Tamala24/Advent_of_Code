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
    ll min = LLONG_MAX;
    std::vector<ll> seeds;
    std::string token;
    string inputLine;
    int i, j, k;

    getline(std::cin, inputLine);
    std::istringstream iss(inputLine);
    iss >> token; // "Seeds:"
    while(iss >> token) {
        seeds.push_back(stoll(token));
    }
    std::vector<ll> s[seeds.size()]; // para guardar los resultados
    bool y[seeds.size()] = {false};
    getline(std::cin, inputLine);

    getline(std::cin, inputLine); // Seed-to-soil
    while(getline(std::cin, inputLine)) {   
        if (inputLine.empty()) 
                break;
        std::vector<ll> l;
        std::istringstream iss(inputLine);
        while(iss >> token) {
                cout << endl << token << " ";
                l.push_back(stoll(token));
        }  
        cout << endl << "In l: " << l[0] << " " << l[1] << " " << l[2] << endl;
        cout << "In: ";
        for(i = 0; i < seeds.size(); i++) {
            //cout << seeds[i] << " ";
            if((seeds[i] >= l[1]) && (seeds[i] <= (l[1]+l[2]))) {
                s[i].push_back(l[0] + (seeds[i]-l[1]));
                cout << seeds[i] << " ";
                y[i] = true;
            }
        }
    }
    cout << endl;
     for(i = 0; i < seeds.size(); i++)
        for(j = 0; j < s[i].size(); j++)
            cout << i << " " << j << " "<< s[i][j] << endl;
    cout << "False: ";
    for(i = 0; i < seeds.size(); i++) {
        if(y[i]) {
            //cout << seeds[i] << " ";
            y[i] = false;
        } else {
            cout << seeds[i] << " ";
            s[i].push_back(seeds[i]);
        }
    }
    cout << endl;
     for(i = 0; i < seeds.size(); i++)
        for(j = 0; j < s[i].size(); j++)
            cout << i << " " << j << " "<< s[i][j] << endl;
    cout << endl;
    for(j = 0; j < 6; j++) {
        getline(std::cin, inputLine); // Soil-to-fertilizer
        while(getline(std::cin, inputLine)) {   
            if (inputLine.empty()) 
                    break;
            std::vector<ll> l;
            std::istringstream iss(inputLine);
            while(iss >> token) 
                    l.push_back(stoll(token));  
            for(i = 0; i < seeds.size(); i++) {
                if((s[i][j] >= l[1]) && (s[i][j] <= (l[1]+l[2]))) {
                    if(y[i]) {
                        if(s[i][s[i].size()-1] > (l[0] + (s[i][j]-l[1])))
                            s[i][s[i].size()-1] =  (l[0] + (s[i][j]-l[1]));
                    } else {
                        s[i].push_back(l[0] + (s[i][j]-l[1]));
                        y[i] = true;
                    }  
                }
            }
        }
        for(i = 0; i < seeds.size(); i++) {
            if(y[i]) {
                y[i] = false;
            } else {
                s[i].push_back(s[i][j]);
            }
        }
        cout << endl;
     for(i = 0; i < seeds.size(); i++)
        for(k = 0; k < s[i].size(); k++)
            cout << i << " " << k << " "<< s[i][k] << endl;
    }
    //cout << s[0][s[0].size()-1] << endl;
    for(i = 0; i < seeds.size(); i++)
        for(j = 0; j < s[i].size(); j++)
            cout << i << " " << j << " "<< s[i][j] << endl;

    for(i = 0; i < seeds.size(); i++)
        if(s[i][s[i].size()-1] < min)
            min = s[i][s[i].size()-1];
        
    cout << "Min: " << min << endl;
}
    
int main() {
// Hace más eficiente la entrada de datos
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
