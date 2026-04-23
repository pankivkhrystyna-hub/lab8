#include "Product.h"


Product::Product(std::string n, int c) : name(n), code(c) {}
bool Product::operator<(const Product& other) const { return code < other.code; }
bool Product::operator==(const Product& other) const { return code == other.code; }
bool Product::is_even() const { return code % 2 == 0; }
std::ostream& operator<<(std::ostream& os, const Product& p) {
    return os << "[" << p.name << ":" << p.code << "]";
}
