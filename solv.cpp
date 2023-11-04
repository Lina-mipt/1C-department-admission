#include <iostream> 
#include <vector>
#include <unordered_set> 

int main(){
  std::cin.sync_with_stdio(false); 
  std::cin.tie(NULL); 
  std::cout.sync_with_stdio(false); 
  std::cout.tie(NULL);

  int n, m;
  int w, h; 
  std::cin >> n >> m; 
  std::cin >> w >> h; 

  std::vector<std::vector<long long>> dist(n, std::vector<long long>(m)); 
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      std::cin >> dist[i][j]; 
    }
  }

  int k;
  std::vector<std::unordered_set<int>> relationship(n * m + 1); 
  std::cin >> k;
  for(int i = 0; i < k; ++i){
    int first, second; 
    std::cin >> first >> second; 
    relationship[--first].insert(--second); 
  }

  auto dist_2 = [&](int a, int b) -> unsigned long long {
    int x1 = a / (m + 1), x2 = b / (m + 1);
    int y1 = a % (m + 1), y2 = b % (m + 1);
    unsigned long long dx = std::abs(x1 - x2) * h;
    unsigned long long dy = std::abs(y1 - y2) * h;
    unsigned long long res = dx * dx + dy * dy;
    if (res > dist[x1][y1] * dist[x1][y1]) return 1e18;
    if (relationship[a].count(b)) return 1e18;
    return res;
  };

  int f; 
  for(int i = 0; i < f; ++i){
    int first, second; 
    std::cin >> first >> second;
    --first;
    --second;
    int ans = -1;
    unsigned long long dist = 1e18;
    for (int from = 0; from < (n + 1) * (m + 1); ++from) {
      unsigned long long d = dist_2(from, first) + dist_2(from, second);
      if (d < dist) {
        dist = d;
        ans = from + 1;
      }
    }
    std::cout << ans << "\n";
  }
}
