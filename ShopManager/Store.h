#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include <vector>

class Store {
public:
    void addProduct(const Product& product);
    bool removeProduct(const std::string& id);
    void updateProduct(const std::string& id, const std::string& name, double price, int stock);
    bool productExists(const std::string& id) const;
    Product getProductById(const std::string& id) const;
    std::vector<Product> getProducts() const;
    void updateStock(const std::string& id, int stock);

private:
    std::vector<Product> products;
};

#endif // STORE_H
