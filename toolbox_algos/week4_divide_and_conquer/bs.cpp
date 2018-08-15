#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int l, int r, int x) {
	if(l == r) return -1;
	int sz = (r-l);
	int mid = (sz/2)+l;
	if(a[mid] < x) return binary_search(a,mid+1,r,x);
	else if(a[mid] > x) return binary_search(a,l,mid,x);
	else return mid;
}


int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
  int left = 0, right = (int)(a.size());
    std::cout << binary_search(a,left,right, b[i]) << ' ';
  }
}
