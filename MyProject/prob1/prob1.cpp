#include <iostream>
#include <vector>
using namespace std;

static vector<int> prefix_w = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7};
static vector<int> prefix_b = {0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5};
void build_prefix();
bool solve(int, int);

int main() {
  build_prefix();
  int N;
  cin >> N;

  int W, B;
  for (int i = 0; i < N; ++i) {
    cin >> W >> B;
    bool ans = solve(W, B);
    cout << (ans ? "Yes " : "No ");
  }
  cout << endl;
  return 0;
}

void build_prefix() {
  for (int i = 1; i < 15; i++) {
    for (int j = 0; j < 12; j++) {
      prefix_w.push_back(prefix_w[j] + i * 7);
      prefix_b.push_back(prefix_b[j] + i * 5);
    }
  }
}

bool solve(int W, int B) {
  int len = W + B;
  for (int i = 0; i <= 179 - len; ++i) {
    int w_count = prefix_w[i + len] - prefix_w[i];
    int b_count = prefix_b[i + len] - prefix_b[i];

    if (w_count == W && b_count == B) {
      return true;
    }
  }

  return false;
}