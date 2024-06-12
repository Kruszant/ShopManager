#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Product.h"
#include <vector>

class ShoppingCart {
public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& id);
    void displayCartContents() const;
    double calculateTotalAmount() const;
    bool productExists(const std::string& id) const;

private:
    std::vector<Product> cart;
};

#endif // SHOPPINGCART_H
