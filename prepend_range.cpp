#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> v = {6, 7};
    auto r = std::views::iota(3, 6);  // [3, 4, 5]
    v.insert(v.begin(), r.begin(), r.end());

    for (int x : v) std::cout << x << " ";
    std::cout << "\n"; // Output: 3 4 5 6 7
}
