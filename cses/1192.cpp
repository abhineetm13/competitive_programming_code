#include <iostream>
#include <array>

int count = 0;

int iter_x[4] = {1, 0, -1, 0};
int iter_y[4] = {0, 1, 0, -1};

void dfs (char** arr, int i, int j, int n, int m, bool** visited) {
    if (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j]){
        visited[i][j] = true;
        for(int itr = 0; itr < 4; itr++) {
            int i1 = i + iter_x[itr];
            int j1 = j + iter_y[itr];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && !visited[i1][j1]) {
                dfs(arr, i1, j1, n, m, visited);
            }
        }
        return;
    }
    else return;
}

int main() {
    int n; std::cin >> n;
    int m; std::cin >> m;

    char** arr = new char*[n];
    for(int i=0; i<n; i++) {
        arr[i] = new char[m];
    }
    bool** visited = new bool*[n];
    for(int i=0; i<n; i++) {
        visited[i] = new bool[m];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cin >> arr[i][j];
            if (arr[i][j] == '.') visited[i][j] = false;
            else visited[i][j] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(arr, i, j, n, m, visited);
                count++;
            }
        }
    }

    std::cout << count << std::endl;

}