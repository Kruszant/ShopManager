#include "Product.h"

// Constructor
Product::Product(const std::string& id, const std::string& name, double price, int stock)
    : id(id), name(name), price(price), stock(stock), count(0) {}

// Getter for ID
std::string Product::getId() const {
    return id;
}

// Getter for name
std::string Product::getName() const {
    return name;
}

// Getter for price
double Product::getPrice() const {
    return price;
}

// Getter for stock
int Product::getStock() const {
    return stock;
}

// Getter for count
int Product::getCount() const {
    return count;
}

// Setter for name
void Product::setName(const std::string& name) {
    this->name = name;
}

// Setter for price
void Product::setPrice(double price) {
    this->price = price;
}

// Setter for stock
void Product::setStock(int stock) {
    this->stock = stock;
}

// Increment count
void Product::incrementCount() {
    count++;
}
