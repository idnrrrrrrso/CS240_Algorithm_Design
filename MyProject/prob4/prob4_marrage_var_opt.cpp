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

bool perfect_match(int start_day, int duration) {}

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

  for (int i = 0; i < num_lecturers; i++) {
    for (int day = store[i].first - 1; day < store[i].second; ++day) {
      adj_list[day].insert(i);
    }
  }

  for (int k = 1; k <= num_lecturers; ++k) {
    int sum_days = 0;
    for (int i = 0; i + k <= num_days; ++i) {
      sum_days += perfect_match(i, k);
    }
    cout << sum_days << endl;
  }

  return 0;
}
