#include "headers.h"

#include <iostream>
#include <vector>

using namespace std;

int solution(int A) {
  vector<pair<int, int>> nums;
  string inp = to_string(A);
  nums.push_back(make_pair(0, A));
  for (int i = 1; i < inp.length(); i++)
  {
    int first = stoi(inp.substr(0, i));
    int second = stoi(inp.substr(i));
    cerr << first << ' ' << second << endl;
    nums.push_back(make_pair(first, second));
  }

  int minDiff = INT_MAX;
  for (auto &&parts : nums)
  {
    int diff = abs(parts.first - parts.second);
    minDiff = min(diff, minDiff);
  }

  return minDiff;
}