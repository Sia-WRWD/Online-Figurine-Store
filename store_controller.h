//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H
#define ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H

#include <iostream>
#include <iomanip>
#include "store_user.h"
#include "store_po.h"
#include "store_client.h"
#include "store_item.h"
#include "store_menu.h"

#include "bits/stdc++.h"

using namespace std;

UserLinkedList ull;
PurchaseOrderLinkedList poll;
ClientLinkedList cll;
ItemLinkedList ill;
Menu menu;

void runSoe() {
    string SoeUsername, SoePassword, SoeRole = "SoE";
    int main_opt, actions_opt, actions_input, sort_opt, sort_dir_opt, search_opt, search_input;
    int settings_opt;

    cout << "Please Provide Your Login Information:" << endl;
    cout << "Username:";
    cin >> SoeUsername;
    cout << "Password:";
    cin >> SoePassword;

    bool verificationStatus = ull.verifyLogin(SoeUsername, SoePassword, SoeRole);

    if (verificationStatus == true) {
        while(true) {
            cout << endl;
            cout << "----Welcome Back, " << SoeUsername << "!----" << endl;

            menu.SoEMainMenu(); //Display SoE Main Menu

            cout << "Your Input:";
            cin >> main_opt;
            cout << endl;

            if (main_opt == 7) {
                break;
            }

            switch(main_opt) {
                case 1: //Display Purchase Order Details
                    poll.showPODetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortPOMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 7) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Purchase Order ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 3: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 4: //Date
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 5: //Quantity
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 6: //Delivery Status
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 2: //Display Client List Details
                    cll.showClientDetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortClientMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 3) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Client Name
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 3: //Display Item List Details
                    ill.showItemDetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortItemMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 4) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Item Name
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 3: //Unit Price
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 4: //Search for PO, Client or Item
                    while (true) {
                        menu.SoESearchMenu(); //Display SoE Search Menu

                        cout << "Your Input:";
                        cin >> search_opt;
                        cout << endl;

                        if (search_opt == 4) {
                            break;
                        }

                        switch (search_opt) {
                            case 1: //Search Purchase Order
                                cout << "Purchase Order ID:";
                                cin >> search_input;
                                cout << endl;

                                poll.searchPurchaseOrder(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Search Client
                                cout << "Client ID:";
                                cin >> search_input;
                                cout << endl;

                                cll.searchClient(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 3: //Search Item
                                cout << "Item ID:";
                                cin >> search_input;
                                cout << endl;

                                ill.searchItem(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                        }
                    }
                case 5: //Produce Sales Order Report
                    //Generate Report.

                    break;
                case 6: //Settings
                    while(true) {
                        menu.settingsMenu();

                        cout << "Your Input:";
                        cin >> settings_opt;
                        cout << endl;

                        if (settings_opt == 4) {
                            break;
                        }

                        switch(settings_opt) {
                            case 1: //My Information
                                break;
                            case 2: //Change My Password
                                break;
                            case 3: //Delete My Account
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                default:
                    break;
            }
        }
    } else {
        cout << endl;
        cout << "Login Failed, Please Try Again!" << endl << endl;
    }
}

void runAdmin() {
    string adminUsername, adminPassword, adminRole = "Admin";
    int main_opt, actions_opt, actions_input, sort_opt, sort_dir_opt, search_opt, search_input;
    int settings_opt;

    cout << "Please Provide Your Login Information:" << endl;
    cout << "Username:";
    cin >> adminUsername;
    cout << "Password:";
    cin >> adminPassword;

    ull.showUserDetails();

    bool verificationStatus = ull.verifyLogin(adminUsername, adminPassword, adminRole);

    if (verificationStatus == true) {
        while (true) {
            cout << endl;
            cout << "----Welcome Back, " << adminUsername << "!----" << endl;

            menu.AdminMainMenu();

            cout << "Your Input:";
            cin >> main_opt;

            if (main_opt == 8) {
                break;
            }

            switch(main_opt) {
                case 1: //Display Purchase Order Details
                    poll.showPODetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortPOMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 7) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Purchase Order ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 3: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 4: //Date
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 5: //Quantity
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 6: //Delivery Status
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 2: //Display Client List Details
                    cll.showClientDetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortClientMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 3) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Client Name
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 3: //Display Item List Details
                    ill.showItemDetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortItemMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 4) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Item Name
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 3: //Unit Price
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 4:
                    ull.showUserDetails();

                    while(true) {
                        menu.afterDisplayActionMenu(); //Display After Display Action Menu

                        cout << "Your Input:";
                        cin >> actions_opt;
                        cout << endl;

                        if (actions_opt == 5) {
                            break;
                        }

                        switch (actions_opt) {
                            case 1: //Sort Data
                                while(true) {
                                    menu.sortUserMenu();

                                    cout << "Your Input:";
                                    cin >> sort_opt;
                                    cout << endl;

                                    if (sort_opt == 3) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        case 2: //Client Name
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        break;
                                                    case 2: //Descending
                                                        break;
                                                }
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                break;
                            case 3: //Update Data
                                break;
                            case 4: //Delete Data
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                case 5: //Search for PO, Client or Item
                    while (true) {
                        menu.AdminSearchMenu(); //Display SoE Search Menu

                        cout << "Your Input:";
                        cin >> search_opt;
                        cout << endl;

                        if (search_opt == 5) {
                            break;
                        }

                        switch (search_opt) {
                            case 1: //Search Purchase Order
                                cout << "Purchase Order ID:";
                                cin >> search_input;
                                cout << endl;

                                poll.searchPurchaseOrder(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Search Client
                                cout << "Client ID:";
                                cin >> search_input;
                                cout << endl;

                                cll.searchClient(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 3: //Search Item
                                cout << "Item ID:";
                                cin >> search_input;
                                cout << endl;

                                ill.searchItem(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 4: //Search User
                                cout << "User ID:";
                                cin >> search_input;
                                cout << endl;

                                ull.searchUser(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            break;
                                        case 2: //Delete Data
                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                        }
                    }
                case 6: //Produce Sales Order Report
                    //Generate Report.

                    break;
                case 7: //Settings
                    while(true) {
                        menu.settingsMenu();

                        cout << "Your Input:";
                        cin >> settings_opt;
                        cout << endl;

                        if (settings_opt == 4) {
                            break;
                        }

                        switch(settings_opt) {
                            case 1: //My Information
                                break;
                            case 2: //Change My Password
                                break;
                            case 3: //Delete My Account
                                break;
                            default:
                                break;
                        }
                    }

                    break;
                default:
                    break;
            }
        }

    } else {
        cout << endl;
        cout << "Login Failed, Please Try Again!" << endl << endl;
    }
}

#endif //ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H
