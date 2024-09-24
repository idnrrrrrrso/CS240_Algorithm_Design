#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAX_DAY 2000
#define MAX_LECTURER 1000

vector<set<int>> adj_list;
vector<int> match_day;
vector<bool> visited;
int num_days = 0;
int num_lecturers;

bool dfs(int day, int start_day, int duration) {
  for (auto lecturer : adj_list[day]) {
    if (!visited[lecturer]) {
      visited[lecturer] = true;
      if (match_day[lecturer] == -1 ||
          dfs(match_day[lecturer], start_day, duration)) {
        match_day[lecturer] = day;
        return true;
      }
    }
  }
  return false;
}

int max_match(int start_day, int duration) {
  fill(match_day.begin(), match_day.end(), -1);
  int match_count = 0;
  for (int day = start_day; day < start_day + duration; ++day) {
    fill(visited.begin(), visited.end(), false);
    if (dfs(day, start_day, duration)) {
      ++match_count;
    }
  }
  return match_count;
}

int main() {
  cin >> num_lecturers;
  vector<pair<int, int>> store(num_lecturers);
  for (int i = 0; i < num_lecturers; i++) {
    cin >> store[i].first >> store[i].second;
    if (store[i].second > num_days)
      num_days = store[i].second;
  }

  // 确保所有lecturer的可行时间起始点都不相同
  for (int i = 0; i < num_lecturers; ++i) {
    for (int j = i + 1; j < num_lecturers; ++j) {
      if (store[i].first == store[j].first) {
        if (store[i].second - store[i].first >
            store[j].second - store[j].first) {
          store[i].first++;
        } else {
          store[j].first++;
        }
      }
    }
  }

  adj_list.resize(num_days);
  visited.resize(num_lecturers);
  match_day.resize(num_lecturers, -1);

  for (int i = 0; i < num_lecturers; i++) {
    for (int day = store[i].first - 1; day < store[i].second; ++day) {
      adj_list[day].insert(i);
    }
  }

  for (int k = 1; k <= num_lecturers; ++k) {
    int sum_days = 0;
    for (int i = 0; i + k <= num_days; ++i) {
      sum_days += max_match(i, k) == k ? 1 : 0;
    }
    cout << sum_days << endl;
  }

  return 0;
}
