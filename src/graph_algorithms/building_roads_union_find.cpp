#include <string>
#include <vector>
#include <numeric>
#include <iostream>

int find(std::vector<int>& parent, int point) {
    if (parent[point] != point) {
        // Path compression
        return parent[point] = find(parent, parent[point]);
    }
    return point;
}

void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX == rootY) {
        return;
    }

    // Union by rank to keep the tree balanced
    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        ++rank[rootX];
    }
}

int main(void) {

    int n, m;
    std::cin >> n >> m;

    std::vector<int> parent(n, 0), rank(n, 0);
    std::iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        unionSets(parent, rank, a - 1, b - 1);
    }

    std::vector<int> cities;

    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            cities.push_back(i);
        }
    }

    std::vector<std::pair<int, int>> roads;

    for (int i = 1; i < cities.size(); i++) {
        roads.emplace_back(cities[i - 1] + 1, cities[i] + 1);
    }

    std::cout << roads.size() << '\n';
    for (const auto& road : roads) {
        std::cout << road.first << ' ' << road.second << '\n';
    }

}