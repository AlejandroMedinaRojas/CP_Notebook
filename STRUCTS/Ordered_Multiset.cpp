#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <class T>
struct ordered_multiset {
  ordered_set<pair<T, int>> os;
  map<T, int> mp;

  void insert(T x) {
    os.insert(make_pair(x, ++mp[x]));
  }
  void erase(T x) {
    os.erase(make_pair(x, mp[x]--));
  }
  int order_of_key(T x) {
    return os.order_of_key(make_pair(x, 0));
  }
  T find_by_order(int idx) {
     return (*os.find_by_order(idx)).first;
  }
  int count(T x) {
    return mp[x];
  }

  int size() { return (int)os.size(); }
  bool empty() { return os.empty(); }
  void clear() { os.clear(); }
};