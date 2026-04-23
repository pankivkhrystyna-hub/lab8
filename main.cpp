#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include "Product.h"

template <typename T, std::size_t A, std::size_t B>
std::array<T, A + B> merge_arrays(const std::array<T, A>& a, const std::array<T, B>& b) {
    std::array<T, A + B> result;
    auto it1 = a.begin();
    auto it2 = b.begin();
    auto res_it = result.begin();
    while (it1 != a.end() && it2 != b.end()) {
        if (*it1 < *it2) *res_it++ = *it1++;
        else *res_it++ = *it2++;
    }
    while (it1 != a.end()) *res_it++ = *it1++;
    while (it2 != b.end()) *res_it++ = *it2++;
    return result;
}


int main() {
    std::array<int, 3> a1 = {1, 5, 9};
    std::array<int, 2> a2 = {2, 4};
    auto res = merge_arrays(a1, a2);
    std::cout << "Merged Array: ";
    for(int x : res) std::cout << x << " ";

      return 0;
}
