#include <queue>
#include <limits>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node {
    int x, y, priority;
    Node(int x, int y, int priority)
        : x(x), y(y), priority(priority) {}
};

struct compare {
    bool operator()(const Node& a, const Node& b) {
        return a.priority > b.priority;
    }
};

// Manhattan distance
inline int heuristic(const std::pair<int, int>& point, const std::pair<int, int>& end) {
    return std::abs(point.first - end.first) + std::abs(point.second - end.second);
}

std::string aStar(std::vector<std::string>& floor, std::pair<int, int> start, std::pair<int, int> end, int n, int m) {
    const int deltaX[] = {-1, 0, 1, 0};
    const int deltaY[] = {0, 1, 0, -1};
    const char directions[] = {'U', 'R', 'D', 'L'};

    std::vector<std::vector<bool>> visited (n, std::vector<bool> (m, false));
    std::vector<std::vector<int>> distance (n, std::vector<int> (m, std::numeric_limits<int>::max()));
    std::vector<std::vector<std::pair<int, int>>> parent(n, std::vector<std::pair<int, int>>(m, {-1, -1}));

    std::priority_queue<Node, std::vector<Node>, compare> pq;
    pq.emplace(start.first, start.second, heuristic(start, end));

    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;

    while (!pq.empty()) {

        Node t = pq.top();
        pq.pop();
        int x = t.x;
        int y = t.y;

        visited[x][y] = true;

        if (x == end.first &&
            y == end.second) {

                std::string path;
                std::pair<int, int> p = end;
                while (p != start) {
                    std::pair<int, int> previous = parent[p.first][p.second];
                    for (int i = 0; i < 4; i++) {
                        if (previous.first + deltaX[i] == p.first &&
                            previous.second + deltaY[i] == p.second) {
                                path += directions[i];
                                break;
                            }
                    }
                    p = previous;
                }
                std::reverse(path.begin(), path.end());
                return path;

            }

        for (int i = 0; i < 4; i++) {

            int nx = x + deltaX[i];
            int ny = y + deltaY[i];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                floor[nx][ny] != '#' &&
                !visited[nx][ny]) {

                    if (distance[nx][ny] > distance[x][y] + 1) {
                        distance[nx][ny] = distance[x][y] + 1;
                        parent[nx][ny] = {x, y};
                        pq.emplace(
                            nx,
                            ny,
                            /* only heuristic makes it greedy best-first search. */
                            /* only distance makes it dijkstra's algorithm. */
                            distance[nx][ny] + heuristic({nx, ny}, end)
                        );
                    }

            }

        }

    }

    return "";
}

int main(void) {

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> floor(n);
    std::pair<int, int> start, end;

    size_t position;

    for (int i = 0; i < n; i++) {

        std::cin >> floor[i];

        position = floor[i].find('A');
        if (position != std::string::npos) {
            start = {i, static_cast<int>(position)};
        }

        position = floor[i].find('B');
        if (position != std::string::npos) {
            end = {i, static_cast<int>(position)};
        }

    }

    std::string path = aStar(floor, start, end, n, m);

    if (path.size() == 0) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n" << path.size() << '\n' << path << '\n';
    }

}