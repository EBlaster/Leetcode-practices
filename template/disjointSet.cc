#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class DisjointSet {  // to represent disjoint set
  unordered_map<string, string> parent;

 public:
  void makeSet(vector<string> const &wholeset) {
    // perform makeset operation
    for (string i : wholeset)  // create n disjoint sets
      parent[i] = i;
  }
  string Find(
      string l) {        // Find the root of the set in which element l belongs
    if (parent[l] == l)  // if l is root
      return l;
    return Find(parent[l]);  // recurs for parent till we find root
  }
  void Union(string m, string n) {  // perform Union of two subsets m and n
    string x = Find(m);
    string y = Find(n);
    parent[x] = y;
  }
};
void print(vector<string> const &universe, DisjointSet &dis) {
  for (string i : universe) cout << dis.Find(i) << " ";
  cout << '\n';
}
int main() {
  vector<string> wholeset = {"6", "7", "1", "2", "3"};  // items of whole set
  DisjointSet dis;        // initialize DisjointSet class
  dis.makeSet(wholeset);  // create individual set of the items of wholeset
  dis.Union("7", "6");    // 7,6 are in same set
  print(wholeset, dis);
  if (dis.Find("7") == dis.Find("6"))  // if they are belong to same set or not.
    cout << "Yes" << endl;
  else
    cout << "No";
  if (dis.Find("3") == dis.Find("4"))
    cout << "Yes" << endl;
  else
    cout << "No";
  return 0;
}