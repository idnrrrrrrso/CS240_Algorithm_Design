#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#define MAX_DAY 20
#define MAX_LECTURER 10

using namespace std;

vector<vector<bool>> adj(MAX_DAY + 1, vector<bool>(MAX_LECTURER + 1));
vector<int> match_day(MAX_LECTURER + 1, -1);
vector<bool> visited(MAX_DAY + 1);
int num_lecturer;
int num_day = 0;

// use Hall's marriage theorem
// run perfect_match on this bipartite graph
// with adj[start_day] to adj[start_day + duration -1]
bool perfect_match(int start_day, int duration) {
  // 遍历 day[start_day] to day[start_day + duration -1]这
  // “duration”个元素的集合的所有子集W chech whether each subset W satisfies |W|
  // \le |N_G`(W)|
  // 一旦有一个子集不满足，return false

  for (int subset = 1; subset < (1 << duration); ++subset) {
    set<int> W;         // 当前子集W
    set<int> neighbors; // N_G(W)
    for (int i = 0; i < duration; ++i) {
      if (subset & (1 << i)) {
        W.insert(start_day + i);
        for (int lecturer = 0; lecturer < num_lecturer; ++lecturer) {
          if (adj[start_day + i][lecturer]) {
            neighbors.insert(lecturer);
          }
        }
      }
    }
    if (W.size() > neighbors.size()) {
      return false; // 一旦有一个子集不满足|W| <= |N_G(W)|，返回false
    }
  }
  return true;
}

int main() {
  cin >> num_lecturer;
  vector<pair<int, int>> store(num_lecturer);
  for (int i = 0; i < num_lecturer; i++) {
    cin >> store[i].first >> store[i].second;
    if (store[i].second > num_day)
      num_day = store[i].second;
  }

  for (int i = 0; i < num_lecturer; i++) {
    for (int j = store[i].first - 1; j < store[i].second; ++j) {
      adj[j][i] = 1;
    }
  }

  for (int k = 1; k <= num_lecturer; ++k) {
    int sum_days = 0;
    for (int i = 0; i + k <= num_day; ++i) {
      sum_days += perfect_match(i, k);
    }
    cout << sum_days << endl;
  }

  return 0;
}
