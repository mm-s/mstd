#include <mstd/bigint>
#include <iostream>
using namespace std;
using namespace mstd;

typedef bigint<128> bint;

int main() {

bint a(8);
bint b(8);

cout << a << endl;
cout << b << endl;
cout << a+b << endl;




return 0;
}
