#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int bswrap(vector<int> b, int l, int r, int n){
	if(l == r) return -1;
	int sz = (r-l);
	int mid = (sz/2)+l;
	//int mid = l+(r-l)/2;
	//int mid = (l+r)/2;
	if(b[mid] < n) return bswrap(b,mid+1,r,n);
	else if(b[mid] > n) return bswrap(b,l,mid,n);
	else return mid;
}

/*
int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)(a.size());
  if(x>a[right-1])return -1;
  if(x<a[left])return -1;
  return bswrap(a, left, right, x);
}
*/

//int binary_search(const vector<int> &a, int l, int r, int x) {
int binary_search(const vector<int> &a, int l, int r, int x) {
	if(l == r) return -1;
	//int mid = l+(r-l)/2;
	int sz = (r-l);
	int mid = (sz/2)+l;
	if(a[mid] < x) return binary_search(a,mid+1,r,x);
	else if(a[mid] > x) return binary_search(a,l,mid,x);
	else return mid;
  //return binary_search(a, l, r, x);
}

/*
  if(right >=left){
	int sz = (right-left);
	//int mid = (sz/2)+left;
	int mid = left+(right-left)/2;
  if(a[mid] == x) return mid;
  if(a[mid] > x){
	//vector<int> b(a.begin(),a.begin()+(mid-1));
	vector<int> b(a.begin(),a.begin()+(mid-1));
	   return binary_search(b,x);
  //if(a[mid] < x) return binary_search(*a[mid+1],x);
  }
	//vector<int> b(a.begin()+(mid),a.begin()+right);
	vector<int> b(a.begin()+(mid+1),a.end());
	   return binary_search(b,x);
  }
  return -1;
}
*/

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
  //int left = 0, right = b[0];
    std::cout << binary_search(a,left,right, b[i]) << ' ';
    //std::cout << binary_search(a, b[i]) << ' ';
  }
}
