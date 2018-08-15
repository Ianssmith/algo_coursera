#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct eqx {
	int startpos;
	int stoppos;
};

eqx partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  //int eqp = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
	  //eqp++;
      swap(a[i], a[j]);
    //}else if(a[i] == x){
	  //eqp++;
	  //j++;
	  //swap(a[i],a[eqp]);
    }
  }
  //swap(a[l],a[eqp]);

  ////int eqs = j;
  ////for(int i=l;i<eqp;i++){
	////swap(a[i], a[j]);
	////j++;
  ////}
  eqx res;
  res.startpos = j;
  swap(a[l],a[j]);
  res.stoppos = j;
  //res.stoppos = eqp;
  return res;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //swap(a[l], a[k]);
  eqx ststp = partition3(a, l, r);

  randomized_quick_sort(a, l, ststp.startpos - 1);
  randomized_quick_sort(a, ststp.stoppos + 1, r);
  //randomized_quick_sort(a, l, m - 1);
  //randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
