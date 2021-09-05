#include "headers.h"

class Solution {
public:
  string parseEmail(string email) {
    string parsed;
    bool passAt = false, passPlus = false;
    for (auto &&c : email) {
      if (c == '@') {
        passAt = true;
        parsed.push_back('@');
      } else if (!passAt) {
        if (c == '.' || passPlus) {
          continue;
        } else if (c == '+') {
          passPlus = true;
          continue;
        } else {
          parsed.push_back(c);
        }
      } else {
        parsed.push_back(c);
      }
    }
    return parsed;
  }

  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> uniqueEmails;
    for (auto &&i : emails) {
      uniqueEmails.insert(parseEmail(i));
    }
    return uniqueEmails.size();
  }
};