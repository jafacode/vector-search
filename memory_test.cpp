#include <vector>
#include <iostream>

int main(){
    std::vector<int> data(1000000);

    std::cout << "Current size: " << data.size() << "\n";
    std::cout << "Current capacity: " <<data.capacity() << "\n";

    data.clear();

    std::cout << "Size after .clear(): " << data.size() << "\n";
    std::cout << "Capacity after .clear(): " << data.capacity() << "\n";

    data.shrink_to_fit();
    std::cout << "Size after .shrink_to_fit(): " << data.size() << "\n";
    std::cout << "Capacity after .shrink_to_fit(): " << data.capacity() << "\n";
    return 0;
}