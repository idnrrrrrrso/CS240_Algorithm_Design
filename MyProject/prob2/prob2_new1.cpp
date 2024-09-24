#include <iostream>
#include <string>

using namespace std;

bool canTransform(string &S, const string &T) {
  int N = S.size();
  int M = T.size();
}

int main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  if (M > N) {
    cout << "No" << endl;
    return 0;
  }

  if (canTransform(S, T)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
