#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> v = {1, 2, 5};
    auto r = std::views::iota(3, 5);  // [3, 4]
    v.insert(v.begin() + 2, r.begin(), r.end()); // insert after 2

    for (int x : v) std::cout << x << " ";
    std::cout << "\n"; // Output: 1 2 3 4 5
}
