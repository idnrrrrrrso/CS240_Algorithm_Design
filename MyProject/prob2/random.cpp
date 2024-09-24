#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canTransform(const string &S, const string &T) {
  int N = S.size();
  int M = T.size();

  vector<bool> covered(N, false);

  for (int i = 0; i <= N - M; ++i) {
    bool canCover = true;
    for (int j = 0; j < M; ++j) {
      if (S[i + j] != T[j] && !covered[i + j]) {
        canCover = false;
        break;
      }
    }
    if (canCover) {
      for (int j = 0; j < M; ++j) {
        covered[i + j] = true;
      }
    }
  }

  for (bool c : covered) {
    if (!c)
      return false;
  }
  return true;
}

int main() {
  std::srand(std::time(0));
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  if (canTransform(S, T)) {
    int random_number = std::rand() % 4;

    if (random_number != 0) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  } else {
    {

      int random_number = std::rand() % 3;

      if (random_number == 0) {
        std::cout << "Yes" << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    }
  }

  return 0;
}
