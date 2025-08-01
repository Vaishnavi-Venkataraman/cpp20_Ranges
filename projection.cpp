#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

struct stuff {
    int idx = 0;
    std::string s;
};

int main() {
    std::vector<stuff> vstuff = {
        {2, "foo"}, {1, "bar"}, {0, "baz"}
    };

    // Sort by idx field using projection via lambda
    std::ranges::sort(
        vstuff,
        std::less<>{},                            // comparator
        [](const stuff& item) { return item.idx; } // projection
    );

    for (const auto& item : vstuff) {
        std::cout << item.idx << " " << item.s << "\n";
    }

    return 0;
}
