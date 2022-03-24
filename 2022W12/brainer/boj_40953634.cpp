// 과제 안 내신 분..?
// https://www.acmicpc.net/submit/5597/40953634

#include "bits/stdc++.h"

using namespace std;
int main() {
  int num[30] = {};
  int a = 0;
  bool isCop = false;
  for (int i = 0; i < 31; i++) {
    cin >> a;
    num[a - 1] = 1;
  }
  for (int i = 0; i < 30; i++) {
    if (isCop == false) {
      if (num[i] == 0) {
        cout << i + 1 << endl;
        isCop = true;
      }
    } else {
      if (num[i] == 0) {
        cout << i + 1 << "";
      }
    }
  }
  return 0;
}
