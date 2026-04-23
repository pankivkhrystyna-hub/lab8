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

template <typename T>
void split_by_parity(const std::vector<T>& src, std::vector<T>& even, std::vector<T>& odd) {
    for (auto it = src.begin(); it != src.end(); ++it) {
        bool is_even_val;
        if constexpr (std::is_integral_v<T>) is_even_val = (*it % 2 == 0);
        else is_even_val = it->is_even();

        if (is_even_val) even.push_back(*it);
        else odd.push_back(*it);
    }
}
int main() {
    std::array<int, 3> a1 = {1, 5, 9};
    std::array<int, 2> a2 = {2, 4};
    auto res = merge_arrays(a1, a2);
    std::cout << "Merged Array: ";
    for(int x : res) std::cout << x << " ";


    std::vector<Product> shop = { {"Apple", 10}, {"Bread", 5}, {"Milk", 12} };
    std::vector<Product> even_p, odd_p;
    split_by_parity(shop, even_p, odd_p);
    std::cout << "\nEven Products: " << even_p.size();

    
    return 0;
}
