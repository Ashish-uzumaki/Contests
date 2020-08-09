#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  int,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
map_t;

int main()
{
  map_t s;
  s.insert(make_pair(12, 1012));
  s.insert(make_pair(505, 1505));
  s.insert(make_pair(30, 1030));
  cout << s.find_by_order(1)->second << '\n';
  return 0;
}