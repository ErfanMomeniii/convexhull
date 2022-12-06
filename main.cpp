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
  for (int i = 0; i < points_num; i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}

int findTop(int l, int r, bool left = true) {
  int maxY = INT_MIN;
  int index = l;
  for (int i = l; i < r; i++) {
    if (v[i].second > maxY || (v[i].second == maxY && ((v[i].first < v[index].first && left == true) || (v[i].first > v[index].first && left == false)))) {
      index = i;
      maxY = v[i].second;
    }
  }
  return index;
}

int findBottom(int l, int r, bool left = true) {
  int minY = INT_MAX;
  int index = l;
  for (int i = l; i < r; i++) {
    if (v[i].second < minY || (v[i].second == minY && ((v[i].first < v[index].first && left == true) || (v[i].first > v[index].first && left == false)))) {
      index = i;
      minY = v[i].second;
    }
  }
  return index;
}

void merge(int l, int r) {
  if (l + 1 >= r - 1) {
    int t1 = findTop(l, r, false);
    int b1 = findBottom(l, r, false);
    nextPoint[t1] = b1;
    nextPoint[b1] = t1;
    return;
  }
  int mid = (l + r) / 2;
  int t1 = findTop(l, mid, false);
  int b1 = findBottom(l, mid, false);
  int t2 = findTop(mid, r, true);
  int b2 = findBottom(mid, r, true);
  nextPoint[t1] = t2;
  nextPoint[b1] = b2;
}

void ans(int l, int r) {
  if (l == r - 1) {
    return;
  }
  int mid = (l + r) / 2;
  ans(l, mid);
  ans(mid, r);
  merge(l, r);
}

void findAns() {
  ans(0, points_num);
}

void draw() {
  int u = findTop(0, points_num, false);
  int o = u;
  while (nextPoint[u] != o) {
    cout << v[u].first << " " << v[u].second << endl;
    u = nextPoint[u];
  }
}