#include <iostream>
#include <unordered_set>
#include <vector>

unsigned long long GetDist(std::pair<int, int> arg, std::pair<int, int> h_w,
                           int m, std::vector<std::vector<long long>>& dist,
                           std::vector<std::unordered_set<int>>& relationship) {
  int x1 = arg.first / (m + 1), x2 = arg.second / (m + 1);
  int y1 = arg.first % (m + 1), y2 = arg.second % (m + 1);
  unsigned long long dx = std::abs(x1 - x2) * h_w.first;
  unsigned long long dy = std::abs(y1 - y2) * h_w.second;
  unsigned long long res = dx * dx + dy * dy;
  if (res > dist[x1][y1] * dist[x1][y1]) return 1e18;
  if (relationship[arg.first].count(arg.second)) return 1e18;
  return res;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.sync_with_stdio(false);
  std::cout.tie(NULL);

  int n, m;
  int w, h;
  std::cin >> n >> m;
  std::cin >> w >> h;

  std::vector<std::vector<long long>> dist(n + 1,
                                           std::vector<long long>(m + 1));
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < m + 1; ++j) {
      std::cin >> dist[i][j];
    }
  }

  int k;
  std::cin >> k;
  std::vector<std::unordered_set<int>> relationship((n + 1) * (m + 1));

  for (int i = 0; i < k; ++i) {
    int first, second;
    std::cin >> first >> second;
    relationship[--first].insert(--second);
  }

  auto dist_2 = [&](int a, int b) -> unsigned long long {
    int x1 = a / (m + 1), x2 = b / (m + 1);
    int y1 = a % (m + 1), y2 = b % (m + 1);
    unsigned long long dx = std::abs(x1 - x2) * h;
    unsigned long long dy = std::abs(y1 - y2) * w;
    unsigned long long res = dx * dx + dy * dy;
    if (res > dist[x1][y1] * dist[x1][y1]) return 1e18;
    if (relationship[a].count(b)) return 1e18;
    return res;
  };

  int f;

  std::cin >> f;

  for (int i = 0; i < f; ++i) {
    int first, second;
    std::cin >> first >> second;
    --first;
    --second;
    int ans = -1;
    unsigned long long dist_ = 1e18;
    for (int from = 0; from < (n + 1) * (m + 1); ++from) {
      unsigned long long d =
          GetDist({from, first}, {h, w}, m, dist, relationship) +
          GetDist({from, second}, {h, w}, m, dist, relationship);
      if (d < dist_) {
        dist_ = d;
        ans = from + 1;
      }
    }
    std::cout << ans << "\n";
  }
}
