#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int points_num;
bool show[maxn];
pair < int, int > v[maxn];
int nextPoint[maxn];

void input();
void findAns();
void draw();
void ans(int l, int r);
void merge(int l, int r);

int main() {
  input();
  findAns();
  draw();
}

bool compare(pair < int, int > p1, pair < int, int > p2) {
  if (p1.first < p2.first) {
    return true;
  } else if (p1.first == p2.first) {
    if (p1.second > p2.second) {
      return true;
    }
    return false;
  }
  return false;
}

void input() {
  fill(nextPoint, nextPoint + points_num, -1);
  cout << "please enter number of points: ";
  cin >> points_num;
  for (int i = 0; i < points_num; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
  }
  sort(v, v + points_num, compare);
}

bool check(int root, int p1, int p2) {
  //0 for p2 is more clockwise than p1
  //1 for p1 is more clockwise than p2
  if (p1 == -1) {
    return 0;
  }
  if (p2 == -1) {
    return 1;
  }
  int val = (v[p1].second - v[root].second) * (v[p2].first - v[p1].first) - (v[p1].first - v[root].first) * (v[p2].second - v[p1].second);

  return (val >= 0) ? 0 : 1;
}
void ans(int point) {
  if (point == -1) {
    return;
  }
  if (point == 0 && show[point]) {
    return;
  }
  int index = -1;
  for (int i = 0; i < points_num; i++) {
    if (i == point) {
      continue;
    }
    if (check(point, i, index) && (!show[i])) {
      index = i;
    }
  }
  nextPoint[point] = index;
  show[index] = true;
  ans(index);
}

void findAns() {
  ans(0);

}

void draw() {
  cout << "-----------answer-----------"
  int u = 0;
  int o = u;
  while (nextPoint[u] != o) {
    cout << v[u].first << " " << v[u].second << endl;
    u = nextPoint[u];
  }
  cout << v[u].first << " " << v[u].second << endl;
}