#include "headers.h"

class Solution {
 public:
  vector<string> splitSentence(string sentence) {
    vector<string> splitted;
    string curr = "";
    for (auto &&i : sentence) {
      if (i == ' ') {
        splitted.push_back(curr);
        curr = "";
      } else {
        curr.push_back(i);
      }
    }
    splitted.push_back(curr);
    return splitted;
  }

  vector<string> generateSentences(
      vector<vector<string>>& synonyms,
      string text) {
    vector<string> sentence = splitSentence(text);
    vector<string> temp = sentence;
    vector<unordered_set<string>> filteredSynonyms(synonyms.size());
    vector<int> synPos(sentence.size(), -1);
    set<vector<string>> sortedSentences;
    vector<string> result;

    sortedSentences.insert(sentence);

    for (int i = 0; i < synonyms.size(); i++) {
      filteredSynonyms[i].insert(synonyms[i][0]);
      filteredSynonyms[i].insert(synonyms[i][1]);
      for (int j = i + 1; j < synonyms.size(); j++) {
        if (filteredSynonyms[i].find(synonyms[j][0]) != filteredSynonyms[i].end()) {
          filteredSynonyms[i].insert(synonyms[j][1]);
          synonyms.erase(synonyms.begin() + j);
        } else if (filteredSynonyms[i].find(synonyms[j][1]) != filteredSynonyms[i].end()) {
          filteredSynonyms[i].insert(synonyms[j][1]);
          synonyms.erase(synonyms.begin() + j);
        }
      }
    }

    for (int i = 0; i < sentence.size(); i++) {
      for (int j = 0; j < filteredSynonyms.size(); j++) {
        if (filteredSynonyms[j].find(sentence[i]) != filteredSynonyms[j].end()) {
          synPos[i] = j;
        }
      }
    }

    for (int i = 0; i < sentence.size(); i++) {
      if (synPos[i] == -1) {
        continue;
      } else {
        for (auto &&sent : sortedSentences) {
          temp = sent;
          for (auto &&synonym : filteredSynonyms[synPos[i]]) {
            temp[i] = synonym;
            sortedSentences.insert(temp);
          }
        }
      }
    }

    for (auto &&sent : sortedSentences) {
      string tempSent = "";
      for (auto &&word : sent) {
        tempSent.append(word);
        tempSent.push_back(' ');
      }
      tempSent.pop_back();
      result.push_back(tempSent);
    }

    return result;
  }
};