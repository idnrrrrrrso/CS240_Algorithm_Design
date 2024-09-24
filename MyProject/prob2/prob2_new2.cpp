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
      /*
      如果在start及其前面 找到和T的前或后匹配的一部分
      比如 S=CABCABCD, T=ABCD, start = 2
      或者 S=C##CABCD，那么'#'可以替代任何字母，满足match T 的需求
      那么在S[2]及其前面，找到了连续的T从头开始的ABC
      就把 S里start前能match T 的前半部分的部分替换为#,
      即 S=C###ABCD
      Let start变为这个被替换位的前一个字母位，在这个例子中 start = 0
      */
      if (start == 0 && S[0] != T[0])
        return false;

      if (S[start] == '#')
        break;

      int t = T.find(S[start]);
      if (std::string::npos == n)
        return false;

      int i = t;
      while (i >= 0) {
        if (S[start] == T[i] || S[start] == '#') {
          start--;
          i--;
        } else
          break;
      }
      if (i < 0) {
        std::fill(S.begin() + start + 1, S.begin() + start + t + 2, '#');
      } else
        break;
    }

    while (end <= N - 1) {
      if (end == N - 1 && S[N - 1] != T[M - 1]) {
        return false;
      }
      if (S[end] == '#')
        break;

      int t = T.find(S[end]);
      if (std::string::npos == n)
        return false;

      int i = t;
      while (i <= M - 1) {
        if (S[end] == T[i] || S[end] == '#') {
          end++;
          i++;
        } else
          break;
      }
      if (i > M - 1) {
        std::fill(S.begin() + end - (M - t), S.begin() + end, '#');
      } else
        break;
    }
  }
  return true;
}
