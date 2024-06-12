#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Store.h"
#include "ShoppingCart.h"

class UserInterface {
public:
    UserInterface();
    void run();

private:
    Store store;
    ShoppingCart cart;

    void displayClientMenu() const;
    void displayAdminMenu() const;
    void clientMenu();
    void adminMenu();
    void searchAndAddProductToCart();
    void searchProductById();
    void searchProductByName();
    void searchProductByPrice();
    void addItemToStore();
    void removeItemFromStore();
    void modifyProductDetails();
    void removeProductFromCart();
    void initializeSampleProducts();
    void proceedToCheckout();
};

#endif // USERINTERFACE_H
