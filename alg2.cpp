// ranges_part2.cpp
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <iterator>

namespace rv = std::ranges::views;

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};

    // replace: Replace 2s with 99
    std::ranges::replace(vec, 2, 99);
    std::cout << "After replace 2 -> 99: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << "\n";

    // unique_copy: Copy unique elements
    std::vector<int> uniq;
    std::ranges::unique_copy(vec, std::back_inserter(uniq));
    std::cout << "Unique copied: ";
    for (int i : uniq) std::cout << i << " ";
    std::cout << "\n";

    // move: Move data to new vector
    std::vector<int> moved(uniq.size());
    std::ranges::move(uniq, moved.begin());
    std::cout << "Moved data: ";
    for (int i : moved) std::cout << i << " ";
    std::cout << "\n";

    // clamp: Clamp values between 3 and 6
    std::cout << "Clamped values [3, 6]: ";
    for (int i : moved) {
        std::cout << std::clamp(i, 3, 6) << " ";
    }
    std::cout << "\n";

    // any_of: Check if any number > 4
    bool gt4 = std::ranges::any_of(moved, [](int x) { return x > 4; });
    std::cout << "Any > 4? " << std::boolalpha << gt4 << "\n";

    // stride: Take every 2nd element (simulate with custom adaptor)
    std::cout << "Stride-2 elements: ";
    for (size_t i = 0; i < moved.size(); i += 2)
        std::cout << moved[i] << " ";
    std::cout << "\n";

    return 0;
}
