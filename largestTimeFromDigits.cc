#include "headers.h"

class Solution {
 public:
  string largestTimeFromDigits(vector<int>& arr) {
    vector<vector<int>> table;

    table.push_back({arr[0], arr[1], arr[2], arr[3]});
    table.push_back({arr[0], arr[1], arr[3], arr[2]});
    table.push_back({arr[0], arr[2], arr[1], arr[3]});
    table.push_back({arr[0], arr[2], arr[3], arr[1]});
    table.push_back({arr[0], arr[3], arr[1], arr[2]});
    table.push_back({arr[0], arr[3], arr[2], arr[1]});
    table.push_back({arr[1], arr[0], arr[2], arr[3]});
    table.push_back({arr[1], arr[0], arr[3], arr[2]});
    table.push_back({arr[1], arr[2], arr[0], arr[3]});
    table.push_back({arr[1], arr[2], arr[3], arr[0]});
    table.push_back({arr[1], arr[3], arr[0], arr[2]});
    table.push_back({arr[1], arr[3], arr[2], arr[0]});
    table.push_back({arr[2], arr[1], arr[0], arr[3]});
    table.push_back({arr[2], arr[1], arr[3], arr[0]});
    table.push_back({arr[2], arr[0], arr[1], arr[3]});
    table.push_back({arr[2], arr[0], arr[3], arr[1]});
    table.push_back({arr[2], arr[3], arr[1], arr[0]});
    table.push_back({arr[2], arr[3], arr[0], arr[1]});
    table.push_back({arr[3], arr[1], arr[2], arr[0]});
    table.push_back({arr[3], arr[1], arr[0], arr[2]});
    table.push_back({arr[3], arr[2], arr[1], arr[0]});
    table.push_back({arr[3], arr[2], arr[0], arr[1]});
    table.push_back({arr[3], arr[0], arr[1], arr[2]});
    table.push_back({arr[3], arr[0], arr[2], arr[1]});

    int maxValue = 0;
    bool valid = false;

    for (auto&& i : table) {
      if (((i[0] <= 2 && i[1] <= 3) || i[0] <= 1) && i[2] <= 5) {
        valid = true;
        if (i[0] * 1000 + i[1] * 100 + i[2] * 10 + i[3] >= maxValue) {
          maxValue = i[0] * 1000 + i[1] * 100 + i[2] * 10 + i[3];
        }
      }
    }

    string result = "";

    if (!valid)
    {
      return "";
    }


    result += (maxValue / 1000) + '0';
    result += ((maxValue / 100) % 10) + '0';
    result += ":";
    result += ((maxValue / 10) % 10) + '0';
    result += (maxValue % 10) + '0';

    return result;
  }
};