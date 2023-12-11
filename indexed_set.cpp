#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int, int>, null_type, less<>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_map tree<int, int, less<>, rb_tree_tag, tree_order_statistics_node_update>
