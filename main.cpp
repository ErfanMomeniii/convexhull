#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int points_num;
bool show[maxn];
pair < int, int > v[maxn];
vector < int > v[maxn];

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
  } else {
    if (p1.second > p2.second) {
      return true;
    }
    return false;
  }
}

void input() {
  cout << "please enter number of points: ";
  cin >> points_num;
  for (int i = 0; i < points_num; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
  }
  sort(v, v + n, compare)
}

int findTop(int l, int r, bool left = true) {
  int maxY = INT_MIN;
  int index = l;
  for (int i = l; i < r; i++) {
    if (v[i].second > maxY || (v[i].second == maxY && ((v[i].first < v[index].first && left == true) || (v[i].first > v[i] && right == true)))) {
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
    if (v[i].second < minY || (v[i].second == minY && ((v[i].first < v[index].first && left == true) || (v[i].first > v[i] && right == true)))) {
      index = i;
      minY = v[i].second;
    }
  }
  return index;
}

void merge(int l, int r) {
  int mid = (l + r) / 2;
  int t1 = findTop(l, mid, false);
  int b1 = findBottom(l, mid, false);
  int t2 = findTop(mid, r, true);
  int b2 = findBottom(mid, r, true);
  //todo	
}

void ans(int l, int r) {
  int mid = (l + r) / 2;
  ans(l, mid);
  ans(mid, r);
  merge(l, r);
}

void findAns() {
  ans(0, n);
}

void draw() {
  //todo
}