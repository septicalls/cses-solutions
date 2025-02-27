#include <stack>
#include <string>
#include <vector>
#include <iostream>

void dfs(std::vector<std::string>& floor, int i, int j, int n, int m) {
    const int deltaX[] = {-1, 0, 1, 0};
    const int deltaY[] = {0, 1, 0, -1};

    std::stack<std::pair<int, int>> nodes;
    nodes.push({i, j});

    floor[i][j] = '#';

    while (!nodes.empty()) {
        auto [x, y] = nodes.top();
        nodes.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + deltaX[i];
            int ny = y + deltaY[i];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                floor[nx][ny] == '.') {
                    nodes.push({nx, ny});
                    floor[nx][ny] = '#';
                }
        }
    }
}

int main(void) {

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> floor(n);

    for (int i = 0; i < n; i++) {
        std::cin >> floor[i];
    }

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (floor[i][j] == '.') {
                rooms++;
                dfs(floor, i, j, n, m);
            }
        }
    }

    std::cout << rooms << '\n';

}