#include <bits/stdc++.h>
using namespace std;

template <typename V>
class DirectAddressTable{
private:
    vector<V*> T;

public:

    DirectAddressTable(int m){
        assert(m > 0);
        T.assign(m, nullptr);
    }

    ~DirectAddressTable(){
        for (int i = 0; i < T.size(); i++){
            if (T[i] != nullptr){
                delete T[i];
            }
        }
    }

    const V* search(int k){
        assert(k >= 0 && k < T.size());
        return T[k];
    }

    void insert(int k, const V& v){
        assert(k >= 0 && k < T.size());

        if (T[k] != nullptr){
            delete T[k];
        }

        T[k] = new V(v);
    }

    void remove(int k){
        assert(k >= 0 && k < T.size());

        if (T[k] != nullptr){
            delete T[k];
            T[k] = nullptr;
        }
    }

};

void soundex(DirectAddressTable<int>& table){

    // First group
    table.insert('B' - 'A', 1);
    table.insert('F' - 'A', 1);
    table.insert('P' - 'A', 1);
    table.insert('V' - 'A', 1);

    // Second group
    table.insert('C' - 'A', 2);
    table.insert('G' - 'A', 2);
    table.insert('J' - 'A', 2);
    table.insert('K' - 'A', 2);
    table.insert('Q' - 'A', 2);
    table.insert('S' - 'A', 2);
    table.insert('X' - 'A', 2);
    table.insert('Z' - 'A', 2);

    // Third group
    table.insert('D' - 'A', 3);
    table.insert('T' - 'A', 3);

     // Fourth group
    table.insert('L' - 'A', 4);

    // Fifth group
    table.insert('M' - 'A', 5);
    table.insert('N' - 'A', 5);

    // Sixth group
    table.insert('R' - 'A', 6);

}

void word_process(const string& word, DirectAddressTable<int>& table){

    int lcc = 0;

    for (char letra: word){
        int idx = letra - 'A';

        const int* res = table.search(idx);

        int lc = 0; // curr char

        if (res != nullptr){
            lc = *res;
        }

        if (lc > 0 && lc != lcc){
            cout << lc;
        }

        lcc = lc;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DirectAddressTable<int> soundex_table(26);

    soundex(soundex_table);

    string word;

    while (cin >> word){
        word_process(word, soundex_table);
    }

    return 0;
}
