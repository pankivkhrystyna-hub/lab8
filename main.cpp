#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <string>

class Product {
public:
    std::string name;
    int code;
    Product(std::string n = "", int c = 0) : name(n), code(c) {}
    bool operator<(const Product& other) const { return code < other.code; }
    bool operator==(const Product& other) const { return code == other.code; }
    bool is_even() const { return code % 2 == 0; }
};

std::ostream& operator<<(std::ostream& os, const Product& p) {
    return os << "[" << p.name << ":" << p.code << "]";
}

int main() {
    return 0;
}
