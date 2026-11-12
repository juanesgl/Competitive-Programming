#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string text;

    while(cin >> N >> text){
        map<string, int> dic;

        int max_frec = 0;
        string winner_psswd = "";

        int limit = text.size() - N;

        for (int i = 0; i < limit; i++){

            string sub = text.substr(i,N);
            dic[sub]++;

            if (dic[sub] > max_frec){
                max_frec = dic[sub];
                winner_psswd = sub;
            }

        }

        cout << winner_psswd << "\n";
    }

    return 0;
}

