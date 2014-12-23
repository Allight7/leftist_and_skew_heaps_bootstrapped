#include "skew_heap.h"
#include <ctime>
#include <climits>


#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void gen( int n, std::vector <int> &a ) {
  a.resize(n);
  forn(i, n)
    a[i] = rand();
}

const int maxN = 1e5;
SHeap<int, INT_MAX> h;

int main() {
  std::vector <int> x;
  int n = maxN;
  forn(t, 10) { // number of tests
    // test extractMin
    gen(n, x);
    h.build(x.begin(), x.end());
    forn(i, n)
      h.extractMin();
    // test add
    gen(n, x);
    h.clear();
    forn(i, n)
      h.add(x[i]);
  }
  fprintf(stderr, "Test for TL: OK. Time = %.2f\n", 1. * clock() / CLOCKS_PER_SEC);
}