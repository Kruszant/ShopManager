#include "Store.h"

// Adds a product to the store
void Store::addProduct(const Product& product) {
    products.push_back(product);
}

// Removes a product from the store by ID
bool Store::removeProduct(const std::string& id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;
}

// Updates the details of a product in the store
void Store::updateProduct(const std::string& id, const std::string& name, double price, int stock) {
    for (auto& product : products) {
        if (product.getId() == id) {
            product.setName(name);
            product.setPrice(price);
            product.setStock(stock);
            return;
        }
    }
}

// Checks if a product exists in the store by ID
bool Store::productExists(const std::string& id) const {
    for (const auto& product : products) {
        if (product.getId() == id) {
            return true;
        }
    }
    return false;
}

// Gets a product from the store by ID
Product Store::getProductById(const std::string& id) const {
    for (const auto& product : products) {
        if (product.getId() == id) {
            return product;
        }
    }
}

// Returns a vector of all products in the store
std::vector<Product> Store::getProducts() const {
    return products;
}

// Updates the stock quantity of a product in the store
void Store::updateStock(const std::string& id, int stock) {
    for (auto& product : products) {
        if (product.getId() == id) {
            product.setStock(stock);
            return;
        }
    }
}
