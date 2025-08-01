#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> v;
    auto r = std::views::iota(10, 15);  // [10, 11, 12, 13, 14]
    v.assign(r.begin(), r.end());

    for (int x : v) std::cout << x << " ";
    std::cout << "\n"; // Output: 10 11 12 13 14
}
