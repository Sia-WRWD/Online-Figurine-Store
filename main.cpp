#include <iostream>

#include "store_controller.h"

using namespace std;

void InitMenu() {
    cout << "Welcome to ABCD Purchase Order Management System (POMS), what would you like to do?" << endl;
    cout << "1) Login as Sales Order Executive (SOE)" << endl;
    cout << "2) Login as Administrator" << endl;
    cout << "3) Exit" << endl;
}

void handleAction(int options) {
    switch (options) {
        case 1:
            runSoe();
            break;
        case 2:
            runAdmin();
            break;
        case 3:
            cout <<  "\n-----------------------------" << endl;
            cout << "Thank you for using ABCD Purchase Order Management System (POMS)..." << endl;
            break;
        default:
            break;
    }
}

int main() {
    //Initialize Data
    ull.InitUserData();
    poll.InitPurchaseOrdersData();
    cll.InitClientData();
    ill.InitItemData();

    //Get User Input for Initial Menu
    while(true) {
        int init_input;

        InitMenu();

        cout << "Your Input:";
        cin >> init_input;
        cout << endl;

        handleAction(init_input);

        if (init_input == 3) {
            break;
        }

    }
}
