#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &input, int n) {
  for (int i = n - 1; i > 0; --i) {
    int j = i - 1;

    if (n == 2) {
      if (input[1] < input[0]) {
        cout << -1;
        return;
      }
      int tmp = input[1];
      input[1] = input[0];
      input[0] = tmp;
      cout << input[0] << " " << input[1];
      return;
    }

    if (input[i] < input[j])
      continue;

    else {
      next_permutation(input.begin() + 1, input.end());
      for (int i = 0; i < n; i++) {
        // cout << i << endl;
        cout << input[i] << " ";
      }

      return;
    }
  }
  cout << -1;
}

int main() {
  int n = 0;
  cin >> n;
  vector<int> input;
  int j = 0;
  for (int i = 0; i < n; i++) {
    cin >> j;
    input.push_back(j);
  }
  nextPermutation(input, n);
}
