#include <headers.h>

class Solution {
public:
  vector<string> name;
  vector<int> time;
  vector<int> amount;
  vector<string> city;
  vector<string> result;
  unordered_set<int> invalidIndex;

  void parseStrings(vector<string>& transactions) {
    for (int i = 0; i < transactions.size(); i++) {
      int wordCount = 0;
      string tmp = "";
      for (int j = 0; j < transactions[i].length(); j++) {
        if (transactions[i][j] != ',') {
          tmp.push_back(transactions[i][j]);
        } else {
          switch (wordCount) {
          case 0:
            name.push_back(tmp);
            break;
          case 1:
            time.push_back(stoi(tmp));
            break;
          case 2:
            amount.push_back(stoi(tmp));
            break;
          default:
            break;
          }
          wordCount++;
          tmp = "";
        }
      }
      city.push_back(tmp);
    }
  }

  vector<string> invalidTransactions(vector<string>& transactions) {
    parseStrings(transactions);
    for (int i = 0; i < transactions.size(); i++)
    {
      cout << name[i] << time[i] << amount[i] << city[i] << endl;
    }

    for (int i = 0; i < transactions.size(); i++) {
      if (amount[i] > 1000) {
        invalidIndex.insert(i);
      }
      for (int j = 0; j < transactions.size(); j++) {
        if (i != j
            && name[i] == name[j]
            && city[i] != city[j]
            && abs(time[i] - time[j]) <= 60) {
          invalidIndex.insert(i);
          invalidIndex.insert(j);
        }
      }
    }

    for (auto iter:invalidIndex) {
      result.push_back(transactions[iter]);
    }

    return result;
  }
};