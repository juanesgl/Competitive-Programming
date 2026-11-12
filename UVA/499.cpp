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

bool is_letter(char c){
    char lt = c | (1 << 5); // trucazoo
    return (lt >= 'a' && lt <= 'z');
}

void process_line(string line){

    DirectAddressTable<int> table(256);
    int max_frec = 0;

    for (char c: line){

        if (is_letter(c)){
            const int* res = table.search(c);
            int frec = 0;
            if (res != nullptr){
                frec = *res;
            }
            int new_frec = frec + 1;
            table.insert(c, new_frec);

            if (new_frec > max_frec){
                max_frec = new_frec;
            }
        }
    }

    if (max_frec > 0){
        for (char letter = 'A'; letter <= 'Z'; letter ++){
           const int* res = table.search(letter);

           if (res != nullptr && *res == max_frec){
                printf("%c", letter);
           }
        }

        for (char letter = 'a'; letter <= 'z'; letter ++){
           const int* res = table.search(letter);

           if (res != nullptr && *res == max_frec){
                printf("%c", letter);
           }
        }
        printf(" %d\n", max_frec);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;

    while (getline(cin, line)){
        process_line(line);
    }
    return 0;
}
