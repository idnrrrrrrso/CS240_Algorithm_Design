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

    for (int i = 0; i != M; ++i) {
      S[n + i] = '#';
    }

    int start = n - 1;
    int end = n + M;

    while (start >= 0) {
      if (start == 0 && S[0] != T[0]) {
        return false;
      }
      if (S[start] == T[M - 1] || S[start] == '#') {
        break;
      }

      int tmp = T.find(S[start]);
      if (tmp == std::string::npos) {
        return false;
      }

      bool overwrite = false;
      int i = tmp;
      while (i >= 0) {
        if (S[start - (tmp - i)] != T[i] && S[start - (tmp - i)] != '#') {
          start = -1; // to exit the outer while loop
          break;
        }

        if (i == 0) {
          overwrite = true;
        }
        i--;
      }

      if (overwrite) {
        while (tmp >= 0) {
          S[start] = '#';
          start--;
          tmp--;
        }
      }
    }

    while (end <= N - 1) {
      if (end == N - 1 && S[N - 1] != T[M - 1]) {
        return false;
      }
      if (S[end] == T[0] || S[end] == '#') {
        break;
      }

      int tmp = T.find(S[end]);
      if (tmp == std::string::npos) {
        return false;
      }

      bool overwrite = false;
      int i = tmp;
      while (i <= M - 1) {
        if (S[end + (i - tmp)] != T[i] && S[end + (i - tmp)] != '#') {
          end = N + 1; // to exit the outer while loop
          break;
        }

        if (i == M - 1) {
          overwrite = true;
        }
        i++;
      }

      if (overwrite) {
        while (tmp <= M - 1) {
          S[end] = '#';
          end++;
          tmp++;
        }
      }
    }
  }
  return true;
}
