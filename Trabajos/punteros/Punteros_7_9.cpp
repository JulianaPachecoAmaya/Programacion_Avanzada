#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double> &v1, vector<double> &v2, vector<double> &res) {

  int n = v1.size();
  int m = v2.size();

  auto p1 = v1.begin();
  auto p2 = v2.begin();

  res.clear();
  res.resize(n + m);

  auto pRes = res.begin();

  while (p1 != v1.end() && p2 != v2.end()) {
    if (*p1 <= *p2) {
      *pRes = *p1;
      p1++;
    } else {
      *pRes = *p2;
      p2++;
    }
    pRes++;
  }

  while (p1 != v1.end()) {
    *pRes = *p1;
    p1++;
    pRes++;
  }

  while (p2 != v2.end()) {
    *pRes = *p2;
    p2++;
    pRes++;
  }
}

int main() {

  vector<double> v1 = {1.0, 3.0, 5.0, 7.0};
  vector<double> v2 = {2.0, 4.0, 6.0, 8.0, 9.0};

  vector<double> res(v1.size() + v2.size());

  merge(v1, v2, res);

  cout << "Vector mezclado: ";
  for (double num : res) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
