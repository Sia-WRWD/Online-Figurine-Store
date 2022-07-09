//
// Created by chinojen7 on 3/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_MENU_H
#define ONLINE_FIGURINE_STORE_STORE_MENU_H

#include <iostream>
#include <iomanip>

using namespace std;

class Menu {
    private:

    public:
    // Main Menus--------------------------------------------------------------
    void SoEMainMenu() {
        cout << "1) Display Purchase Order List" << endl;
        cout << "2) Display Client List" << endl;
        cout << "3) Display Item List" << endl;
        cout << "4) Search" << endl;
        cout << "5) Produce Sales Order Report" << endl;
        cout << "6) Settings" << endl;
        cout << "7) Log Out" << endl;
    }

    void AdminMainMenu() {
        cout << "1) Display Purchase Order List" << endl;
        cout << "2) Display Client List" << endl;
        cout << "3) Display Item List" << endl;
        cout << "4) Display Account List" << endl;
        cout << "5) Search" << endl;
        cout << "6) Produce Sales Order Report" << endl;
        cout << "7) Settings" << endl;
        cout << "8) Log Out" << endl;
    }

    //After-Display Menus--------------------------------------------------------------
    void afterDisplayActionMenu() {
        cout << "What would you like to do with the displayed data?" << endl;
        cout << "1) Sort Data and re-display" << endl;
        cout << "2) Add new Data" << endl;
        cout << "3) Update Data (based on ID)" << endl;
        cout << "4) Delete Data (based on ID)" << endl;
        cout << "5) Back" << endl;
    }

    //Sort Menus--------------------------------------------------------------
    void sortPOMenu() {
        cout << "How would you like the data to be sorted?" << endl;
        cout << "1) Purchase Order ID" << endl;
        cout << "2) Client ID" << endl;
        cout << "3) Item ID" << endl;
        cout << "4) Date" << endl;
        cout << "5) Quantity" << endl;
        cout << "6) Total" << endl;
        cout << "7) Delivery Status" << endl;
        cout << "8) Back" << endl;
    }

    void sortClientMenu() {
        cout << "How would you like the data to be sorted?" << endl;
        cout << "1) Client ID" << endl;
        cout << "2) Back" << endl;
    }

    void sortItemMenu() {
        cout << "How would you like the data to be sorted?" << endl;
        cout << "1) Item ID" << endl;
        cout << "2) Unit Price" << endl;
        cout << "3) Back" << endl;
    }

    void sortUserMenu() {
        cout << "How would you like the data to be sorted?" << endl;
        cout << "1) User ID" << endl;
        cout << "2) Roles" << endl;
        cout << "3) Back" << endl;
    }

    void sortDirection() {
        cout << "What direction would you like the data to be sorted?" << endl;
        cout << "1) Ascending" << endl;
        cout << "2) Descending" << endl;
        cout << "3) Back" << endl;
    }

    //Update Menus--------------------------------------------------------------
    void updatePOMenu() {
        cout << "What would you like to update?" << endl;
        cout << "1) Date" << endl;
        cout << "2) Quantity" << endl;
        cout << "3) Delivery Status" << endl;
        cout << "4) Back" << endl;
    }

    void updateClientMenu() {
        cout << "What would you like to update?" << endl;
        cout << "1) Name" << endl;
        cout << "2) Address" << endl;
        cout << "3) Contact Number" << endl;
        cout << "4) Back" << endl;
    }

    void updateItemMenu() {
        cout << "What would you like to update?" << endl;
        cout << "1) Name" << endl;
        cout << "2) Unit Price" << endl;
        cout << "3) Back" << endl;
    }

    void updateUserMenu() {
        cout << "What would you like to update?" << endl;
        cout << "1) Username" << endl;
        cout << "2) Password" << endl;
        cout << "3) Role" << endl;
        cout << "4) Back" << endl;
    }

    //Search Menus--------------------------------------------------------------
    void SoESearchMenu() {
        cout <<"What would you like to search (based on ID)?" << endl;
        cout << "1) Purchase Order" << endl;
        cout << "2) Client" << endl;
        cout << "3) Item" << endl;
        cout << "4) Back" << endl;
    }

    void AdminSearchMenu() {
        cout << "What would you like to search (based on ID)?" << endl;
        cout << "1) Purchase Order" << endl;
        cout << "2) Client" << endl;
        cout << "3) Item" << endl;
        cout << "4) Account" << endl;
        cout << "5) Back" << endl;
    }

    void afterSearchActionMenu() {
        cout << "What would you like to do with the searched data?" << endl;
        cout << "1) Update Data" << endl;
        cout << "2) Delete Data" << endl;
        cout << "3) Back" << endl;
    }

    //Settings Menu--------------------------------------------------------------
    void settingsMenu() {
        cout << "What would you like to do?" << endl;
        cout << "1) My Information" << endl;
        cout << "2) Change Password" << endl;
        cout << "3) Delete my Account" << endl;
        cout << "4) Back" << endl;
    }

};

#endif //ONLINE_FIGURINE_STORE_STORE_MENU_H
