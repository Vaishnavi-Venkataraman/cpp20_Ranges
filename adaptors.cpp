#include <iostream>
#include <ranges>
#include <numeric>
#include <vector>

namespace rv = std::ranges::views;
namespace rng = std::ranges;

int main() {
    // Step 1: Create range of numbers from 1 to 10
    auto nums = rv::iota(1) | rv::take(10);
    std::cout << "Original numbers: ";
    for (int i : nums) std::cout << i << " ";
    std::cout << "\n";

    // Step 2: Filter even numbers
    auto evens = nums | rv::filter([](int x) { return x % 2 == 0; });
    std::cout << "Even numbers: ";
    for (int i : evens) std::cout << i << " ";
    std::cout << "\n";

    // Step 3: Transform (square the evens)
    auto squares = evens | rv::transform([](int x) { return x * x; });
    std::cout << "Squared evens: ";
    for (int i : squares) std::cout << i << " ";
    std::cout << "\n";

    // Step 4: Drop the first one
    auto dropped = squares | rv::drop(1);
    std::cout << "After dropping first: ";
    for (int i : dropped) std::cout << i << " ";
    std::cout << "\n";

    // Step 5: Reverse view
    auto reversed = dropped | rv::reverse;
    std::cout << "Reversed: ";
    for (int i : reversed) std::cout << i << " ";
    std::cout << "\n";

    return 0;
}
