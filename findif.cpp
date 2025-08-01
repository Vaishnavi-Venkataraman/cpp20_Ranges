#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

bool is_even(int x) { return x % 2 == 0; }

int main() {
    std::vector<int> v = {3, 5, 6, 7};

    // Normal find_if
    auto it = std::find_if(v.begin(), v.end(), is_even);
    if (it != v.end()) std::cout << "Normal: Found even: " << *it << "\n";

    // Ranges-based find_if
    auto res = std::ranges::find_if(v, is_even);
    if (res != v.end()) std::cout << "Ranges: Found even: " << *res << "\n";

    return 0;
}
