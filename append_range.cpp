#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> v = {1, 2};
    auto r = std::views::iota(3, 6);  // [3, 4, 5]
    v.insert(v.end(), r.begin(), r.end());

    for (int x : v) std::cout << x << " ";
    std::cout << "\n"; // Output: 1 2 3 4 5
}
