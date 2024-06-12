#include "ShoppingCart.h"
#include <iostream>

// Adds a product to the shopping cart
void ShoppingCart::addProduct(const Product& product) {
    for (auto& cartProduct : cart) {
        if (cartProduct.getId() == product.getId()) {
            cartProduct.incrementCount();
            return;
        }
    }
    Product newProduct = product;
    newProduct.incrementCount();
    cart.push_back(newProduct);
}

// Removes a product from the shopping cart
void ShoppingCart::removeProduct(const std::string& id) {
    for (auto it = cart.begin(); it != cart.end(); ++it) {
        if (it->getId() == id) {
            cart.erase(it);
            return;
        }
    }
}

// Displays the contents of the shopping cart
void ShoppingCart::displayCartContents() const {
    if (cart.empty()) {
        std::cout << "Your shopping cart is empty." << std::endl;
        return;
    }

    std::cout << "Shopping cart contents:" << std::endl;
    for (const auto& product : cart) {
        std::cout << "ID: " << product.getId()
            << " - Name: " << product.getName()
            << " - Price: $" << product.getPrice()
            << " - Count: " << product.getCount() << std::endl;
    }
}

// Calculates the total amount for the products in the shopping cart
double ShoppingCart::calculateTotalAmount() const {
    double totalAmount = 0.0;
    for (const auto& product : cart) {
        totalAmount += product.getPrice() * product.getCount();
    }
    return totalAmount;
}

// Checks if a product exists in the shopping cart
bool ShoppingCart::productExists(const std::string& id) const {
    for (const auto& product : cart) {
        if (product.getId() == id) {
            return true;
        }
    }
    return false;
}
