#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <ranges>

namespace rng = std::ranges;

int main() {
    std::string path = "/foo/bar/baz";

    // Find last '/' using reverse iterators
    auto it = std::find(path.rbegin(), path.rend(), '/');

    std::string_view leaf;
    if (it != path.rend()) {
        // Convert reverse_iterator to base() gives one past the '/'
        leaf = std::string_view(it.base(), path.end());
    } else {
        leaf = path;
    }

    std::cout << "leaf: " << leaf << '\n';  // Output: baz

    // Test with no slash
    path = "none";
    it = std::find(path.rbegin(), path.rend(), '/');
    if (it != path.rend()) {
        leaf = std::string_view(it.base(), path.end());
    } else {
        leaf = path;
    }

    std::cout << "leaf (no slash): " << leaf << '\n';  // Output: none

    return 0;
}
