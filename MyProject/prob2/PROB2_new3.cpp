#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool canTransform(string &S, const string &T);

int main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  if (canTransform(S, T)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

bool is_empty_S(const string &S) {
  int N = S.size();
  for (int i = 0; i < N; ++i) {
    if (S[i] != '#') {
      return false;
    }
  }
  return true;
}

bool canTransform(string &S, const string &T) {
  int N = S.size();
  int M = T.size();

  while (!is_empty_S(S)) {
    auto n = S.find(T);
    if (std::string::npos == n) {
      return false;
    }

    std::fill(S.begin() + n, S.begin() + n + M, '#');

    int start = n - 1;
    int end = n + M;

    while (start >= 0) {
      if (start == 0 && S[0] != T[0]) {
        return false;
      }

      int tmp = T.find(S[start]);
      if (tmp == std::string::npos) {
        return false;
      }

      while (tmp >= 0) {
        S[start] = '#';
        start--;
        if (tmp == 0) {
          break;
        }
        tmp--;
        if (S[start] != T[tmp]) {
          start = -1;
          break;
        }
      }
    }

    while (end <= N - 1) {
      if (end == N - 1 && S[N - 1] != T[M - 1]) {
        return false;
      }

      int tmp = T.find(S[end]);
      if (tmp == std::string::npos) {
        return false;
      }

      while (tmp <= N - 1) {
        S[end] = '#';
        end++;
        if (tmp == M - 1) {
          break;
        }
        tmp++;
        if (S[end] != T[tmp]) {
          end = N + 1;
          break;
        }
      }
    }
  }
  return true;
}