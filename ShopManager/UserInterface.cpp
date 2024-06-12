#include "UserInterface.h"
#include <iostream>
#include <thread> 
#include <chrono>  

// Constructor to initialize sample products
UserInterface::UserInterface() {
    initializeSampleProducts();
}

void UserInterface::initializeSampleProducts() {
    store.addProduct(Product("1", "Apple", 0.99, 1));
    store.addProduct(Product("2", "Banana", 0.59, 150));
    store.addProduct(Product("3", "Orange", 1.29, 200));
    store.addProduct(Product("4", "Milk", 2.49, 50));
    store.addProduct(Product("5", "Bread", 1.99, 75));
}

void UserInterface::run() {
    int userType;
    std::cout << "\nChoose an option:" << std::endl;
    std::cout << "1. Client" << std::endl;
    std::cout << "2. Administrator" << std::endl;
    std::cin >> userType;

    if (userType == 1) {
        clientMenu();
    }
    else if (userType == 2) {
        adminMenu();
    }
    else {
        std::cout << "Invalid option. Exiting." << std::endl;
    }
}

void UserInterface::displayClientMenu() const {
    std::cout << "\nChoose an option:" << std::endl;
    std::cout << "1. Display available products" << std::endl;
    std::cout << "2. Add a product to the shopping cart" << std::endl;
    std::cout << "3. Display shopping cart contents" << std::endl;
    std::cout << "4. Calculate total amount" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "6. Remove a product from the shopping cart" << std::endl;
    std::cout << "7. Procceed to checkout" << std::endl;
}

void UserInterface::displayAdminMenu() const {
    std::cout << "\nChoose an option:" << std::endl;
    std::cout << "1. Add product to the store" << std::endl;
    std::cout << "2. Remove a product from the store" << std::endl;
    std::cout << "3. Modify product details" << std::endl;
    std::cout << "4. Change user" << std::endl;
    std::cout << "5. Display available products" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

void UserInterface::clientMenu() {
    while (true) {
        displayClientMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Available products in the store:" << std::endl;
            for (const auto& product : store.getProducts()) {
                std::cout << "ID: " << product.getId() << " - " << product.getName() << " - Price: $" << product.getPrice() << std::endl;
            }
            break;
        case 2:
            searchAndAddProductToCart();
            break;
        case 3:
            cart.displayCartContents();
            break;
        case 4:
            std::cout << "Total amount to pay: $" << cart.calculateTotalAmount() << std::endl;
            break;
        case 5:
            std::cout << "Thank you for shopping!" << std::endl;
            return;
        case 6:
            removeProductFromCart();
            break;
        case 7:
            proceedToCheckout();
			return;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}

void UserInterface::adminMenu() {
    while (true) {
        displayAdminMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            addItemToStore();
            break;
        case 2:
            removeItemFromStore();
            break;
        case 3:
            modifyProductDetails();
            break;
        case 4:
            return run();
        case 5:
            std::cout << "Available products in the store:" << std::endl;
            for (const auto& product : store.getProducts()) {
                std::cout << "ID: " << product.getId() << " - " << product.getName() << " - Price: $" << product.getPrice() << std::endl;
            }
            break;
        case 6:
            std::cout << "Exiting administration menu." << std::endl;
            return;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}

void UserInterface::searchAndAddProductToCart() {
    std::cout << "Enter the search criteria:\n";
    std::cout << "1. Search by ID\n";
    std::cout << "2. Search by name\n";
    std::cout << "3. Search by price\n";
    int searchOption;
    std::cin >> searchOption;

    switch (searchOption) {
    case 1:
        searchProductById();
        break;
    case 2:
        searchProductByName();
        break;
    case 3:
        searchProductByPrice();
        break;
    default:
        std::cout << "Invalid search option." << std::endl;
    }
}

void UserInterface::searchProductById() {
    std::string productId;
    std::cout << "Enter the product ID you want to add to the shopping cart: ";
    std::cin >> productId;

    if (store.productExists(productId)) {
        Product product = store.getProductById(productId);
        if (product.getStock() > 0) {
            cart.addProduct(product);
            store.updateStock(productId, product.getStock() - 1);
            std::cout << product.getName() << " (ID: " << product.getId() << ") added to the cart." << std::endl;
        }
        else {
            std::cout << "Product out of stock." << std::endl;
        }
    }
    else {
        std::cout << "Product not found." << std::endl;
    }
}

void UserInterface::searchProductByName() {
    std::string productName;
    std::cout << "Enter the product name you want to add to the shopping cart: ";
    std::cin >> productName;

    bool found = false;
    for (const auto& product : store.getProducts()) {
        if (product.getName() == productName) {
            if (product.getStock() > 0) {
                cart.addProduct(product);
                store.updateStock(product.getId(), product.getStock() - 1);
                std::cout << product.getName() << " added to the cart." << std::endl;
                found = true;
                break;
            }
            else {
                std::cout << "Product with name " << productName << " is out of stock." << std::endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        std::cout << "Product with name " << productName << " not found." << std::endl;
    }
}

void UserInterface::searchProductByPrice() {
    double price;
    std::cout << "Enter the product price you want to add to the shopping cart: ";
    std::cin >> price;

    bool found = false;
    for (const auto& product : store.getProducts()) {
        if (product.getPrice() == price) {
            if (product.getStock() > 0) {
                cart.addProduct(product);
                store.updateStock(product.getId(), product.getStock() - 1);
                std::cout << product.getName() << " (ID: " << product.getId() << ") added to the cart." << std::endl;
                found = true;
                break;
            }
            else {
                std::cout << "Product with price $" << price << " is out of stock." << std::endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        std::cout << "Product with price $" << price << " not found." << std::endl;
    }
}

void UserInterface::addItemToStore() {
    std::string id, name;
    double price;
    int stock;

    std::cout << "Enter product ID: ";
    std::cin >> id;
    std::cout << "Enter product name: ";
    std::cin >> name;
    std::cout << "Enter product price: $";
    std::cin >> price;
    std::cout << "Enter product stock quantity: ";
    std::cin >> stock;

    store.addProduct(Product(id, name, price, stock));
    std::cout << "Product added to the store." << std::endl;
}

void UserInterface::removeItemFromStore() {
    std::string id;
    std::cout << "Enter the product ID you want to remove: ";
    std::cin >> id;

    if (store.removeProduct(id)) {
        std::cout << "Product removed from the store." << std::endl;
    }
    else {
        std::cout << "Product with ID " << id << " not found." << std::endl;
    }
}

void UserInterface::modifyProductDetails() {
    std::string id;
    std::cout << "Enter the product ID you want to modify: ";
    std::cin >> id;

    if (store.productExists(id)) {
        std::string name;
        double price;
        int stock;

        std::cout << "Enter new product name: ";
        std::cin >> name;
        std::cout << "Enter new product price: $";
        std::cin >> price;
        std::cout << "Enter new product stock quantity: ";
        std::cin >> stock;

        store.updateProduct(id, name, price, stock);
        std::cout << "Product details updated." << std::endl;
    }
    else {
        std::cout << "Product with ID " << id << " not found." << std::endl;
    }
}

void UserInterface::removeProductFromCart() {
    std::string productId;
    std::cout << "Enter the product ID you want to remove from the shopping cart: ";
    std::cin >> productId;

    if (cart.productExists(productId)) {
        cart.removeProduct(productId);
        std::cout << "Product removed from the cart." << std::endl;
    }
    else {
        std::cout << "Product with ID " << productId << " not found in the cart." << std::endl;
    }
}


void UserInterface::proceedToCheckout() {
    std::string cardNumber;
    std::string expirationDate;
    std::string cvv;
    int paymentMethod;

    system("CLS");
    std::cout << "Proceeding to checkout..." << std::endl;
    cart.displayCartContents();
    double totalAmount = cart.calculateTotalAmount();
    std::cout << "Total amount to pay: $" << totalAmount << std::endl;
    std::cout << "Select payment method:" << std::endl;
    std::cout << "1. Visa Card" << std::endl;
    std::cout << "2. ApplePay" << std::endl;
    std::cout << "3. Paypal" << std::endl;

    std::cin >> paymentMethod;
    switch (paymentMethod) {
    case 1:
        std::cout << "Paying with Visa Card" << std::endl;
        std::cout << "Enter your credit card information" << std::endl;

        std::cout << "Card Number (16 digits): ";
        std::cin >> cardNumber;
        while (cardNumber.length() != 16){
            std::cout << "Invalid card number. Please enter a 16-digit card number: ";
            std::cin >> cardNumber;
        }

        std::cout << "Expiration Date (MM/YYYY): ";
        std::cin >> expirationDate;
        while (expirationDate.length() != 7 || expirationDate[2] != '/') {
            std::cout << "Invalid expiration date. Please enter in the format MM/YYYY: ";
            std::cin >> expirationDate;
        }

        std::cout << "CVV (3 digits): ";
        std::cin >> cvv;
        while (cvv.length() != 3) {
            std::cout << "Invalid CVV. Please enter a 3-digit CVV: ";
            std::cin >> cvv;
        }

        std::cout << "\nProcessing payment..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Payment Successful" << std::endl;
        std::cout << "You have ordered:" << std::endl;
        cart.displayCartContents();
        std::cout << "Total amount paid: $" << totalAmount << std::endl;
        break;

    case 2:
        std::cout << "Paying with ApplePay (To be implemented)" << std::endl;
        break;

    case 3:
        std::cout << "Paying with Paypal (To be implemented)" << std::endl;
        break;

    default:
        std::cout << "Invalid payment method selected. Returning to main menu." << std::endl;
        return;
    }

    std::cout << "Thank you for shopping!" << std::endl;
}
