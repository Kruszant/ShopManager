#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string& id, const std::string& name, double price, int stock);

    std::string getId() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;
    int getCount() const;

    void setName(const std::string& name);
    void setPrice(double price);
    void setStock(int stock);
    void incrementCount();

private:
    std::string id;
    std::string name;
    double price;
    int stock;
    int count;
};

#endif // PRODUCT_H
