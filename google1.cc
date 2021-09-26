#include <iostream>
#include <vector>

#include "headers.h"

using namespace std;

int solution(vector<int> A) {
  int n = A.size();
  int result = INT_MIN;
  sort(A.begin(), A.end());

  for (int i = 0; i < n / 2; i++) {
    result = max(result, A[i] + A[n - i - 1]);
  }

  return result;
}

// cerr <<
