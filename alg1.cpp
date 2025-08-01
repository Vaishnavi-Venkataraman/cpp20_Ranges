// ranges_part1.cpp
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>
#include <utility>

namespace rv = std::ranges::views;

int main() {
    std::vector<std::string> words = {"apple", "banana", "apricot", "avocado", "berry"};

    // starts_with: Print words that start with 'a'
    std::cout << "Words starting with 'a': ";
    for (auto&& w : words | rv::filter([](auto& s) { return s.starts_with('a'); }))
        std::cout << w << " ";
    std::cout << "\n";

    // contains: Check if 'banana' is present
    bool has_banana = std::ranges::contains(words, std::string("banana"));
    std::cout << "Contains 'banana'? " << std::boolalpha << has_banana << "\n";

    // count even numbers
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int evens = std::ranges::count_if(nums, [](int x) { return x % 2 == 0; });
    std::cout << "Number of evens: " << evens << "\n";

    // minmax: Find min and max in nums
    auto [min_it, max_it] = std::ranges::minmax_element(nums);
    std::cout << "Min: " << *min_it << ", Max: " << *max_it << "\n";

    // next_permutation: Next lexicographic permutation
    std::ranges::next_permutation(nums);
    std::cout << "After next_permutation: ";
    for (int i : nums)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}
