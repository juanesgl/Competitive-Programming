#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int max_x, max_y;
bool scent[55][55];
string instructions;

char char_orientacion(int dir) {
    char dirs[] = {'N', 'E', 'S', 'W'};
    return dirs[dir];
}

int num_orientacion(char c) {
    if (c == 'N') return 0;
    if (c == 'E') return 1;
    if (c == 'S') return 2;
    if (c == 'W') return 3;
    return 0;
}

void dfs(int x, int y, int dir, int idx) {
    if (idx == instructions.length()) {
        cout << x << " " << y << " " << char_orientacion(dir) << "\n";
        return;
    }

    switch (instructions[idx]) {
        case 'L':
            dfs(x, y, (dir + 3) % 4, idx + 1);
            break;

        case 'R':
            dfs(x, y, (dir + 1) % 4, idx + 1);
            break;

        case 'F': {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx > max_x || ny < 0 || ny > max_y) {
                if (scent[x][y]) {
                    dfs(x, y, dir, idx + 1);
                } else {
                    scent[x][y] = true;
                    cout << x << " " << y << " " << char_orientacion(dir) << " LOST\n";
                    return;
                }
            } else {
                dfs(nx, ny, dir, idx + 1);
            }
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> max_x >> max_y)) return 0;

    int start_x, start_y;
    char start_dir;

    while (cin >> start_x >> start_y >> start_dir >> instructions) {

        int dir_num = num_orientacion(start_dir);
        dfs(start_x, start_y, dir_num, 0);
    }

    return 0;
}
