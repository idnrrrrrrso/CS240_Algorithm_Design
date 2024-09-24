#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#define N 20000  // 长度为
#define M 4      // 每次替换3个字符

using namespace std;

bool containsHash(const string &s) {
  for (char c : s) {
    if (c == '#') {
      return true;
    }
  }
  return false;
}

string generateString() {
  string s(N, '#');
  for (int k = 0; k < 2 * N; ++k) { // 进行30次替换
    int index = rand() % (N - M + 1);
    s[index] = 'A';
    s[index + 1] = 'B';
    s[index + 2] = 'C';
    s[index + 3] = 'D';
  }
  return s;
}

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  string s;
  do {
    s = generateString();
  } while (containsHash(s)); // 检查字符串中是否包含'#'，如果有则重新生成

  std::cout << s << endl;

  return 0;
}
