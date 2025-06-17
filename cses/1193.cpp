#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int iter_x[4] = {1, 0, -1, 0};
int iter_y[4] = {0, 1, 0, -1};
char direction[4] = {'D', 'R', 'U', 'L'};

std::pair<int, std::vector<char>> bfs(char** arr, int** levels, int n, int m, std::pair<int, int> A, std::pair<int, int> B) {
    std::queue<std::pair<int, int>> q;
    q.push(B);
    levels[B.first][B.second] = 0;
    while(!q.empty()) {
        std::pair<int, int> next = q.front();
        q.pop();
        if (next == A) break;
        for(int i = 0; i < 4; i++) {
            int i1 = next.first + iter_x[i];
            int j1 = next.second + iter_y[i];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && 
                levels[i1][j1] == -1) {

                levels[i1][j1] = levels[next.first][next.second] + 1;
                q.push({i1, j1});
            }
        }
    }

    std::vector<char> path;
    int length = levels[A.first][A.second]; 
    if (length == -1) {
        return {-1, path};
    }
    int curr_x = A.first, curr_y = A.second;
    for(int l = length; l > 0; l--) {
        for(int i = 0; i < 4; i++) {
            int i1 = curr_x + iter_x[i];
            int j1 = curr_y + iter_y[i];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m &&
                levels[i1][j1] == l-1) {
                
                curr_x = i1;
                curr_y = j1;
                path.push_back(direction[i]);
                break;
            } 
        }
    }

    return {length, path};
}

int main() {
    int n; std::cin >> n;
    int m; std::cin >> m;

    char** arr = new char*[n];
    int** levels = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new char[m];
        levels[i] = new int[m];
    }

    std::pair<int, int> A, B;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
            levels[i][j] = -1;
            if (arr[i][j] == '#') levels[i][j] = INT_MAX;
            else if (arr[i][j] == '.'){
                // do nothing
            }
            else if (arr[i][j] == 'A') {
                A = {i, j};
            }
            else if (arr[i][j] == 'B') {
                B = {i, j};
            }
        }
    }

    std::pair<int, std::vector<char>> ans = bfs(arr, levels, n, m, A, B);
    if (ans.first == -1) {
        std::cout << "NO" << std::endl;
    }
    else {
        std::cout << "YES" << std::endl;
        std::cout << ans.first << std::endl;
        for(int i = 0; i < ans.first; i++) {
            std::cout << ans.second[i];
        }
        std::cout << std::endl;
    }


}