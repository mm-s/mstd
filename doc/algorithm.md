# algorithm library
## mstd::filter

erases some elements in a container 

example:
```
#include <mstd/algorithm>

std::vector<int> v{1,2,3,4,5,6,7,8};

//remove even elements
mstd::filter(v,[](int prev, int i) -> bool { return *i%2==0; });
```
