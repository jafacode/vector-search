#include <iostream>
#include <vector>
#include <chrono>

struct Heavy {
    std::vector<int> data;
    Heavy(){
        data.resize(100000000);
    }
};

void pass_by_value(Heavy h) {}
void pass_by_ref(const Heavy& h) {}

int main() {
    Heavy heavy_object;
    std::cout << "Object created. Starting tests... \n";

    auto start = std::chrono::steady_clock::now();
    for (int i=0; i<100; i++) {
        pass_by_value(heavy_object);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "pass_by_value: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::steady_clock::now();
    for (int i=0; i<100; i++){
        pass_by_ref(heavy_object);
    }
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;

    std:: cout << "pass_by_ref: " << elapsed_seconds.count() << "s\n";
    return 0;
}