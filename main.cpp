
#include "arr.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    arr<int,5> a;
    a.pull(1,0);
    a.pull(10,1);
    a.pull(12,2);
    a.pull(2,3);
    a.pull(7,4);
    a.print();
    a.sort();
    a.print();
    std::cout<<a.search(10);
    return 0;
}
