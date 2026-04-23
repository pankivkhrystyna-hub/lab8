#ifndef LABB8_PRODUCT_H
#define LABB8_PRODUCT_H
#include <string>
#include <iostream>

class Product {
public:
    std::string name;
    int code;
    Product(std::string n = "", int c = 0);
    bool operator<(const Product& other) const;
    bool operator==(const Product& other) const;
    bool is_even() const;
};
std::ostream& operator<<(std::ostream& os, const Product& p);

#endif //LABB8_PRODUCT_H