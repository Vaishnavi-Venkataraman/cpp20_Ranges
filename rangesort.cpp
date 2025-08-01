#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> v = {7, 2, 5, 1, 4};
    std::ranges::sort(v);

    for (int i : v) std::cout << i << " ";
    return 0;
}
