//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H
#define ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H

#include <iostream>
#include <iomanip>
#include <ctime>

#include "store_namespacer.h"
store_namespacer sn;

#include "store_user.h"
#include "store_po.h"
#include "store_client.h"
#include "store_item.h"
#include "store_menu.h"
#include "store_validation.h"

#include "bits/stdc++.h"

using namespace std;

UserLinkedList ull;
PurchaseOrderLinkedList poll;
ClientLinkedList cll;
ItemLinkedList ill;
Menu menu;
Validation validation;
stringstream ss;

time_t now = time(0);
tm *ltm = localtime(&now);

void runSoe() {
    //Menu Variables
    string SoeUsername, SoePassword, SoeRole = "SoE";
    int main_opt, actions_opt, actions_input, sort_opt, sort_dir_opt, search_opt, search_input;
    int update_opt, report_opt, settings_opt;

    //CRUD Variables
    int po_size, client_size, item_size, user_size;
    int day_input, month_input, year_input, cache_id;
    string date_input, f_day, f_month, f_year, f_total_input, f_unit_price_input;
    string client_name_input, item_name_input, delivery_input;
    string client_address_input, client_contact_input, password_input;
    int po_id_input, client_id_input, item_id_input, RM_pos, quantity_input, user_id_input;
    int p, c, i, totalQuantity, totalProcessed, totalOngoing, separatorPos;
    string totalRevenue, delivery_status, f_totalProcessed, f_totalOngoing;
    float total_input, unit_price_input, f_totalRevenue;
    bool valiResp;

    //Login
    cout << "Please Provide Your Login Information:" << endl;
    cout << "Username:";
    cin >> SoeUsername;
    cout << "Password:";
    cin >> SoePassword;

    cache_id = ull.getID(SoeUsername);

    bool verificationStatus = ull.verifyLogin(SoeUsername, SoePassword, SoeRole);

    if (verificationStatus == true) {
        while(true) {
            cout << endl;
            cout << "----Welcome Back, " << SoeUsername << "!----" << endl;

            menu.SoEMainMenu(); //Display SoE Main Menu

            cout << "Your Input:";
            cin >> main_opt;
            cout << endl;

            while(cin.fail()) {
                cout << "Your Input:";
                cout << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> main_opt;
            }

            if (main_opt == 7) {
                cout << "Thank You for Using ABCD Purchase Order Management System (POMS)..." << endl << endl;
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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> sort_opt;
                                    }

                                    if (sort_opt == 8) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Purchase Order ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on PO ID"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on PO ID"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOClientID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Client ID"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOClientID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Client ID"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 3: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOItemID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Item ID"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOItemID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Item ID"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 4: //Date
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPODate();
                                                        poll.sortPODate();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Date"
                                                             << " (Ascending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPODate();
                                                        poll.sortPODate();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Date"
                                                             << " (Descending)------" << endl;

                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
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

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOQty();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Quantity"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOQty();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Quantity"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 6: //Total
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOTotal();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Total"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOTotal();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Total"
                                                             << " (Descending)------" << endl;
                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 7: //Delivery Status
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPODeliveryStatus();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Delivery Status"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPODeliveryStatus();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Delivery Status"
                                                             << " (Descending)------" << endl;
                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                //Initialize Variables
                                po_size = poll.getSize();
                                client_size = cll.getSize();
                                item_size = ill.getSize();

                                ss.str(""); //Clear StringStream (BartoszKP & Wilka, 2015)

                                cout << "------Add New Purchase Order------" << endl;

                                //Date Input
                                cout << "Input Date (i.e. 11 02 2024):";
                                cin >> day_input >> month_input >> year_input;

                                while(cin.fail()) {
                                    cout << "Input Date (i.e. 11 02 2024):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> day_input >> month_input >> year_input;
                                }

                                valiResp = validation.checkDate(day_input, month_input, year_input); //First-Check

                                while (valiResp == false) {
                                    cout << "Either Your Date Format is Wrong or Date is False!" << endl;
                                    cout << "Input Date (i.e. 11 02 2024):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> setw(2) >> day_input >> setw(2) >> month_input >> setw (4) >> year_input;

                                    valiResp = validation.checkDate(day_input, month_input, year_input); //Re-Check
                                }

                                //Processing Date Format
                                date_input = validation.formatDate(day_input, month_input, year_input);
                                f_day = date_input.substr(0, 2); //Get Day
                                f_month = date_input.substr(2, 2); //Get Month
                                f_year = date_input.substr(4, 7); //Get Year

                                date_input = f_day + "/" + f_month + "/" + f_year; //Formatting (dd/mm/yyyy)

                                //Client ID Input
                                cout << "Input Client ID (From 1-" << client_size << "):";
                                cin >> client_id_input;

                                while (cin.fail() || client_id_input > client_size || client_id_input <= 0) {
                                    cout << "Wrong Input or Client ID Provided Don't Exist!" << endl;
                                    cout << "Input Client ID (From 1-" << client_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_id_input;
                                }

                                //Item ID Input
                                cout << "Input Item ID (From 1-" << item_size << "):";
                                cin >> item_id_input;

                                while (cin.fail() || item_id_input > item_size || item_id_input <= 0) {
                                    cout << "Wrong Input or Item ID Provided Don't Exist!" << endl;
                                    cout << "Input Item ID (From 1-" << item_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> item_id_input;
                                }

                                //Quantity Input
                                cout << "Input Quantity:";
                                cin >> quantity_input;

                                while (cin.fail() || quantity_input > 1000) {
                                    cout << "Input Quantity:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> quantity_input;
                                }

                                //Total Input (geeksforgeeks n.d., w3schools, n.d.)
                                f_total_input = ill.getItemPrice(item_id_input); //get item unit price.
                                RM_pos = f_total_input.find("RM"); //Find RM position
                                f_total_input = f_total_input.substr(RM_pos+2, f_total_input.length());

                                total_input = stof(f_total_input) * quantity_input; //Convert to Float and Total.
                                total_input = floor(total_input * 100) / 100; //Round off to 2 dp.

                                ss << total_input; //Convert Float to String.

                                f_total_input = validation.checkFormatPrice(ss.str());

                                //Delivery Status Input
                                cout << "Input Delivery Status (Processed/ Ongoing):";
                                cin >> delivery_input;

                                while (cin.fail() || (delivery_input != "Processed" &&
                                       delivery_input != "Ongoing")) {
                                    cout << "Input Delivery Status (Processed/ Ongoing):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> delivery_input;
                                }

                                cout << endl;

                                //Insert New Record
                                poll.insertPOAtEnd(po_size + 1, date_input, client_id_input, item_id_input,
                                                   quantity_input, f_total_input, delivery_input);
                                poll.showPODetails();

                                break;
                            case 3: //Update Data
                                while (true) {
                                    menu.updatePOMenu();
                                    po_size = poll.getSize();

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if(update_opt == 4) {
                                        break;
                                    }

                                    switch (update_opt) {
                                        case 1: //Update Date
                                            cout << "------Update PO's Date------" << endl;

                                            //Get Purchase Order ID to update
                                            cout << "Purchase Order ID to update (1-" << po_size << "):";
                                            cin >> po_id_input;

                                            while(cin.fail() || po_id_input > po_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Purchase Order ID to update (1-" << po_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> po_id_input;
                                            }

                                            //Get New Date
                                            cout << "Input New Date (i.e. 11 02 2024):";
                                            cin >> day_input >> month_input >> year_input;

                                            while(cin.fail()) {
                                                cout << "Input New Date (i.e. 11 02 2024):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> day_input >> month_input >> year_input;
                                            }

                                            valiResp = validation.checkDate(day_input, month_input, year_input); //First-Check

                                            while (valiResp == false) {
                                                cout << "Either Your Date Format is Wrong or Date is False!" << endl;
                                                cout << "Input Date (i.e. 11 02 2024):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> setw(2) >> day_input >> setw(2) >> month_input >>
                                                       setw (4) >> year_input;

                                                valiResp = validation.checkDate(day_input, month_input, year_input); //Re-Check
                                            }

                                            //Processing Date Format
                                            date_input = validation.formatDate(day_input, month_input, year_input);
                                            f_day = date_input.substr(0, 2); //Get Day
                                            f_month = date_input.substr(2, 2); //Get Month
                                            f_year = date_input.substr(4, 7); //Get Year

                                            date_input = f_day + "/" + f_month + "/" + f_year; //Formatting (dd/mm/yyyy)

                                            poll.updatePODate(po_id_input, date_input);
                                            poll.showPODetails();

                                            break;
                                        case 2: //Update Quantity
                                            cout << "------Update PO's Quantity------" << endl;

                                            //Get Purchase Order ID to update
                                            cout << "Purchase Order ID to update (1-" << po_size << "):";
                                            cin >> po_id_input;

                                            while(cin.fail() || po_id_input > po_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Purchase Order ID to update (1-" << po_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> po_id_input;
                                            }

                                            //Get New Quantity
                                            cout << "Input New Quantity:";
                                            cin >> quantity_input;

                                            while (cin.fail() || quantity_input > 1000) {
                                                cout << "Input Quantity:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> quantity_input;
                                            }

                                            //Get Item ID
                                            item_id_input = poll.searchItemID(po_id_input);

                                            //Re-Calculate Total (geeksforgeeks n.d., w3schools, n.d.)
                                            f_total_input = ill.getItemPrice(item_id_input); //Get item unit price.

                                            cout << f_total_input << endl;

                                            RM_pos = f_total_input.find("RM"); //Find RM position
                                            f_total_input = f_total_input.substr(RM_pos+2, f_total_input.length());

                                            total_input = stof(f_total_input) * quantity_input; //Convert to Float and Total.
                                            total_input = floor(total_input * 100) / 100; //Round off to 2 dp.

                                            ss << total_input; //Convert Float to String.

                                            f_total_input = validation.checkFormatPrice(ss.str());

                                            poll.updatePOQty(po_id_input, quantity_input, f_total_input);
                                            poll.showPODetails();

                                            break;
                                        case 3: //Update Delivery Status
                                            cout << "------Update PO's Delivery Status------" << endl;

                                            //Get Purchase Order ID to update
                                            cout << "Purchase Order ID to update (1-" << po_size << "):";
                                            cin >> po_id_input;

                                            while(cin.fail() || po_id_input > po_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Purchase Order ID to update (1-" << po_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> po_id_input;
                                            }

                                            //Delivery Status Input
                                            cout << "Input Delivery Status (Processed/ Ongoing):";
                                            cin >> delivery_input;

                                            while (cin.fail() || (delivery_input != "Processed" &&
                                                                  delivery_input != "Ongoing")) {
                                                cout << "Input Delivery Status (Processed/ Ongoing):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> delivery_input;
                                            }

                                            poll.updatePODeliStatus(po_id_input, delivery_input);
                                            poll.showPODetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                po_size = poll.getSize();

                                cout << "------Delete Purchase Order------" << endl;

                                //Get Purchase Order ID to delete
                                cout << "Purchase Order ID to delete (1-" << po_size << "):";
                                cin >> po_id_input;

                                while(cin.fail() || po_id_input > po_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "Purchase Order ID to delete (1-" << po_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> po_id_input;
                                }

                                poll.deletePurchaseOrder(po_id_input);
                                poll.rearrangePOID();
                                poll.showPODetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> sort_opt;
                                    }

                                    if (sort_opt == 2) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        cll.sortClientID();

                                                        cout << "------Sorted Client List Based on Client ID" <<
                                                             " (Ascending)------" << endl;
                                                        cll.showClientListAsc(cll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        cll.sortClientID();

                                                        cout << "------Sorted Client List Based on Client ID" <<
                                                             " (Descending)------" << endl;
                                                        cout << "List of Users (Total Number of Client: " << client_size << "):" << endl;
                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Name" << sn.spacePrinter(15, 4)
                                                             << "Address" << sn.spacePrinter(35, 7)
                                                             << "Contact No" << endl;
                                                        cout << sn.headerUnderline(6 + 15 + 35 + 10) << endl; // number of dashes

                                                        cll.showClientListDsc(cll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data (Speight & dev gr, 2017)
                                //Initialize Variable
                                client_size = cll.getSize();

                                cout << "------Add New Client------" << endl;

                                //Client Name
                                cout << "Input Client Name:";
                                getline(cin >> ws, client_name_input);

                                while(cin.fail()) {
                                    cout << "Wrong Input or Input cannot be Empty!" << endl;
                                    cout << "Input Client Name:";
                                    cin.clear();
                                    getline(cin >> ws, client_name_input);
                                }

                                //Client Address
                                cout << "Input Client Address:";
                                getline(cin >> ws, client_address_input);

                                while(cin.fail()) {
                                    cout << "Wrong Input or Input cannot be Empty!" << endl;
                                    cout << "Input Client Address:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, client_address_input);
                                }

                                //Client Contacts
                                cout << "Input Client Contact No (i.e. 011-12345678):";
                                cin >> client_contact_input;

                                while(cin.fail()) {
                                    cout << "Wrong Input or Input cannot be Empty!" << endl;
                                    cout << "Input Client Contact No (i.e. 011-12345678):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_contact_input;
                                }

                                valiResp = validation.checkContactFormat(client_contact_input);

                                while (valiResp == false) {
                                    cout << "Wrong Input Format or Input cannot be Empty!" << endl;
                                    cout << "Input Client Contact No (i.e. 011-12345678):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_contact_input;

                                    valiResp = validation.checkContactFormat(client_contact_input);
                                }

                                cll.insertClientAtEnd(client_size + 1, client_name_input,
                                                      client_address_input, client_contact_input);
                                cll.showClientDetails();

                                break;
                            case 3: //Update Data
                                while (true) {
                                    //Initialize Variable
                                    menu.updateClientMenu();
                                    client_size = cll.getSize();

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if (update_opt == 4) {
                                        break;
                                    }

                                    switch (update_opt) {
                                        case 1: //Name
                                            cout << "------Update Client's Name------" << endl;
                                            //Get Client ID
                                            cout << "Input Client's ID (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size ||
                                                  client_id_input <= 0) {
                                                cout << "Invalid Client ID!";
                                                cout << "Input Client's ID (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            //Get New Client's Name
                                            cout << "Input New Client's Name:";
                                            getline(cin >> ws, client_name_input);

                                            while(cin.fail()) {
                                                cout << "Input New Client's Name:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, client_name_input);
                                            }

                                            cll.updateClientName(client_id_input, client_name_input);
                                            cll.showClientDetails();

                                            break;
                                        case 2: //Address
                                            cout << "------Update Client's Address------" << endl;
                                            //Get Client ID
                                            cout << "Input Client's ID (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size ||
                                                  client_id_input <= 0) {
                                                cout << "Invalid Client ID!";
                                                cout << "Input Client's ID (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            //Get New Client's Address
                                            cout << "Input New Client's Address:";
                                            getline(cin >> ws, client_address_input);

                                            while(cin.fail()) {
                                                cout << "Input New Client's Address:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, client_address_input);
                                            }

                                            cll.updateClientAddress(client_id_input, client_address_input);
                                            cll.showClientDetails();

                                            break;
                                        case 3: //Contacts
                                            cout << "------Update Client's Contacts------" << endl;
                                            //Get Client ID
                                            cout << "Input Client's ID (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size ||
                                                  client_id_input <= 0) {
                                                cout << "Invalid Client ID!";
                                                cout << "Input Client's ID (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            //Get New Client's Contact
                                            cout << "Input New Client Contact No (i.e. 011-12345678):";
                                            cin >> client_contact_input;

                                            while(cin.fail()) {
                                                cout << "Wrong Input or Input cannot be Empty!" << endl;
                                                cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_contact_input;
                                            }

                                            valiResp = validation.checkContactFormat(client_contact_input);

                                            while (valiResp == false) {
                                                cout << "Wrong Input Format or Input cannot be Empty!" << endl;
                                                cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_contact_input;

                                                valiResp = validation.checkContactFormat(client_contact_input);
                                            }

                                            cll.updateClientContacts(client_id_input, client_contact_input);
                                            cll.showClientDetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                client_size = cll.getSize();

                                cout << "------Delete Client------" << endl;

                                //Get Purchase Order ID to update
                                cout << "Client ID to delete (1-" << client_size << "):";
                                cin >> client_id_input;

                                while(cin.fail() || client_id_input > client_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "Client ID to delete (1-" << client_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_id_input;
                                }

                                cll.deleteClient(client_id_input);
                                cll.rearrangeClientID();
                                cll.showClientDetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> sort_opt;
                                    }

                                    if (sort_opt == 3) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        ill.sortItemID();

                                                        cout << "------Sorted Item List Based on Item ID" <<
                                                             " (Ascending)------" << endl;
                                                        ill.showItemListAsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        ill.sortItemID();

                                                        cout << "------Sorted Item List Based on Item ID" <<
                                                             " (Descending)------" << endl;

                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Name" << sn.spacePrinter(20, 4)
                                                             << "Unit Price"  << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes

                                                        ill.showItemListDsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Unit Price
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        ill.sortUnitPrice();

                                                        cout << "------Sorted User List Based on Unit Price" <<
                                                                " (Ascending)------" << endl;
                                                        ill.showItemListAsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        ill.sortUnitPrice();

                                                        cout << "------Sorted User List Based on Unit Price" <<
                                                                " (Descending)------" << endl;

                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Name" << sn.spacePrinter(20, 4)
                                                             << "Unit Price"  << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes

                                                        ill.showItemListDsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                //Initialize Variable
                                item_size = ill.getSize();
                                ss.str("");

                                cout << "------Add New Item------" << endl;

                                //Item Name
                                cout << "Input Item Name:";
                                getline(cin >> ws, item_name_input);

                                while(cin.fail()) {
                                    cout << "Input Item Name:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, item_name_input);
                                }

                                //Unit Price
                                cout << "Input Item Unit Price (i.e. 10.00 / 10.5): RM";
                                cin >> unit_price_input;

                                while(cin.fail()) {
                                    cout << "Input Item Unit Price (i.e. 10.00 / 10.5): RM";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> unit_price_input;
                                }

                                ss << unit_price_input;

                                f_unit_price_input = validation.checkFormatPrice(ss.str());

                                ill.insertItemAtEnd(item_size + 1, item_name_input, f_unit_price_input);
                                ill.showItemDetails();

                                break;
                            case 3: //Update Data
                                while(true) {
                                    //Initialize Variable
                                    menu.updateItemMenu();
                                    item_size = ill.getSize();
                                    ss.str("");

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if (update_opt == 3) {
                                        break;
                                    }

                                    switch(update_opt) {
                                        case 1: //Name
                                            cout << "------Update Item Name------" << endl;
                                            //Get Item ID
                                            cout << "Input Item ID (1-" << item_size << "):";
                                            cin >> item_id_input;

                                            while(cin.fail() || item_id_input > item_size ||
                                                  item_id_input <= 0) {
                                                cout << "Input Item ID (1-" << item_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> item_id_input;
                                            }

                                            //Get Item's New Name
                                            cout << "Input New Item Name:";
                                            getline(cin >> ws, item_name_input);

                                            while(cin.fail()) {
                                                cout << "Input New Item Name:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> item_name_input;
                                            }

                                            ill.updateItemName(item_id_input, item_name_input);
                                            ill.showItemDetails();

                                            break;
                                        case 2: //Unit Price
                                            cout << "------Update Item Price------" << endl;
                                            //Get Item ID
                                            cout << "Input Item ID (1-" << item_size << "):";
                                            cin >> item_id_input;

                                            while(cin.fail() || item_id_input > item_size ||
                                                  item_id_input <= 0) {
                                                cout << "Input Item ID (1-" << item_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> item_id_input;
                                            }

                                            //Get Item's New Unit Price
                                            cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                            cin >> unit_price_input;

                                            while(cin.fail()) {
                                                cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> unit_price_input;
                                            }

                                            ss << unit_price_input;

                                            f_unit_price_input = validation.checkFormatPrice(ss.str());

                                            ill.updateItemPrice(item_id_input, f_unit_price_input);
                                            ill.showItemDetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                item_size = ill.getSize();

                                cout << "------Delete Item------" << endl;

                                //Get Item ID to update
                                cout << "Item ID to delete (1-" << item_size << "):";
                                cin >> item_id_input;

                                while(cin.fail() || item_id_input > item_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "Item ID to delete (1-" << item_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> item_id_input;
                                }

                                ill.deleteItem(item_id_input);
                                ill.rearrangeItemID();
                                ill.showItemDetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> search_opt;
                        }

                        if (search_opt == 4) {
                            break;
                        }

                        switch (search_opt) {
                            case 1: //Search Purchase Order
                                cout << "Purchase Order ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "Purchase Order ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                poll.searchPurchaseOrder(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while(true) {
                                                menu.updatePOMenu();
                                                po_size = poll.getSize();

                                                cout << "Your Input:";
                                                cin >> update_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if(update_opt == 4) {
                                                    break;
                                                }

                                                switch (update_opt) {
                                                    case 1: //Update Date
                                                        cout << "------Update PO's Date------" << endl;

                                                        //Get Purchase Order ID to update
                                                        po_id_input = search_input;

                                                        //Get New Date
                                                        cout << "Input New Date (i.e. 11 02 2024):";
                                                        cin >> day_input >> month_input >> year_input;

                                                        while(cin.fail()) {
                                                            cout << "Input New Date (i.e. 11 02 2024):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> day_input >> month_input >> year_input;
                                                        }

                                                        valiResp = validation.checkDate(day_input, month_input, year_input); //First-Check

                                                        while (valiResp == false) {
                                                            cout << "Either Your Date Format is Wrong or Date is False!" << endl;
                                                            cout << "Input Date (i.e. 11 02 2024):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> setw(2) >> day_input >> setw(2) >> month_input >>
                                                                setw (4) >> year_input;

                                                            valiResp = validation.checkDate(day_input, month_input, year_input); //Re-Check
                                                        }

                                                        //Processing Date Format
                                                        date_input = validation.formatDate(day_input, month_input, year_input);
                                                        f_day = date_input.substr(0, 2); //Get Day
                                                        f_month = date_input.substr(2, 2); //Get Month
                                                        f_year = date_input.substr(4, 7); //Get Year

                                                        date_input = f_day + "/" + f_month + "/" + f_year; //Formatting (dd/mm/yyyy)

                                                        poll.updatePODate(po_id_input, date_input);
                                                        poll.searchUpdatedPO(po_id_input);

                                                        break;
                                                    case 2: //Update Quantity
                                                        cout << "------Update PO's Quantity------" << endl;

                                                        //Get Purchase Order ID to update
                                                        po_id_input = search_input;

                                                        //Get New Quantity
                                                        cout << "Input New Quantity:";
                                                        cin >> quantity_input;

                                                        while (cin.fail() || quantity_input > 1000) {
                                                            cout << "Input Quantity:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> quantity_input;
                                                        }

                                                        //Get Item ID
                                                        item_id_input = poll.searchItemID(po_id_input);

                                                        //Re-Calculate Total (geeksforgeeks n.d., w3schools, n.d.)
                                                        f_total_input = ill.getItemPrice(item_id_input); //Get item unit price.

                                                        cout << f_total_input << endl;

                                                        RM_pos = f_total_input.find("RM"); //Find RM position
                                                        f_total_input = f_total_input.substr(RM_pos+2, f_total_input.length());

                                                        total_input = stof(f_total_input) * quantity_input; //Convert to Float and Total.
                                                        total_input = floor(total_input * 100) / 100; //Round off to 2 dp.

                                                        ss << total_input; //Convert Float to String.

                                                        f_total_input = validation.checkFormatPrice(ss.str());

                                                        poll.updatePOQty(po_id_input, quantity_input, f_total_input);
                                                        poll.searchUpdatedPO(po_id_input);

                                                        break;
                                                    case 3: //Update Delivery Status
                                                        cout << "------Update PO's Delivery Status------" << endl;

                                                        //Get Purchase Order ID to update
                                                        po_id_input = search_input;

                                                        //Delivery Status Input
                                                        cout << "Input Delivery Status (Processed/ Ongoing):";
                                                        cin >> delivery_input;

                                                        while (cin.fail() || (delivery_input != "Processed" &&
                                                                              delivery_input != "Ongoing")) {
                                                            cout << "Input Delivery Status (Processed/ Ongoing):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> delivery_input;
                                                        }

                                                        poll.updatePODeliStatus(po_id_input, delivery_input);
                                                        poll.searchUpdatedPO(po_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            po_size = poll.getSize();

                                            cout << "------Delete Purchase Order------" << endl;

                                            //Get Purchase Order ID to delete
                                            po_id_input = search_input;

                                            poll.deletePurchaseOrder(po_id_input);
                                            poll.rearrangePOID();
                                            poll.showPODetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                            case 2: //Search Client
                                cout << "Client ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "Client ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                cll.searchClient(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while (true) {
                                                //Initialize Variable
                                                menu.updateClientMenu();
                                                client_size = cll.getSize();

                                                cout << "Your Input:";
                                                cin >> update_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if (update_opt == 4) {
                                                    break;
                                                }

                                                switch (update_opt) {
                                                    case 1: //Name
                                                        cout << "------Update Client's Name------" << endl;
                                                        //Get Client ID
                                                        client_id_input = search_input;

                                                        //Get New Client's Name
                                                        cout << "Input New Client's Name:";
                                                        getline(cin >> ws, client_name_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Client's Name:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, client_name_input);
                                                        }

                                                        cll.updateClientName(client_id_input, client_name_input);
                                                        cll.showUpdatedClient(client_id_input);

                                                        break;
                                                    case 2: //Address
                                                        cout << "------Update Client's Address------" << endl;
                                                        //Get Client ID
                                                        client_id_input = search_input;

                                                        //Get New Client's Address
                                                        cout << "Input New Client's Address:";
                                                        getline(cin >> ws, client_address_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Client's Address:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, client_address_input);
                                                        }

                                                        cll.updateClientAddress(client_id_input, client_address_input);
                                                        cll.showUpdatedClient(client_id_input);

                                                        break;
                                                    case 3: //Contacts
                                                        cout << "------Update Client's Contacts------" << endl;
                                                        //Get Client ID
                                                        client_id_input = search_input;

                                                        //Get New Client's Contact
                                                        cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                        cin >> client_contact_input;

                                                        while(cin.fail()) {
                                                            cout << "Wrong Input or Input cannot be Empty!" << endl;
                                                            cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> client_contact_input;
                                                        }

                                                        valiResp = validation.checkContactFormat(client_contact_input);

                                                        while (valiResp == false) {
                                                            cout << "Wrong Input Format or Input cannot be Empty!" << endl;
                                                            cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> client_contact_input;

                                                            valiResp = validation.checkContactFormat(client_contact_input);
                                                        }

                                                        cll.updateClientContacts(client_id_input, client_contact_input);
                                                        cll.showUpdatedClient(client_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            client_size = cll.getSize();

                                            cout << "------Delete Client------" << endl;

                                            //Get Client ID to delete
                                            cout << "Client ID to delete (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Client ID to delete (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            cll.deleteClient(client_id_input);
                                            cll.rearrangeClientID();
                                            cll.showClientDetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                            case 3: //Search Item
                                cout << "Item ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "Item ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                ill.searchItem(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while(true) {
                                                //Initialize Variable
                                                menu.updateItemMenu();
                                                item_size = ill.getSize();
                                                ss.str("");

                                                cout << "Your Input:";
                                                cin >> update_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if (update_opt == 3) {
                                                    break;
                                                }

                                                switch(update_opt) {
                                                    case 1: //Name
                                                        cout << "------Update Item Name------" << endl;
                                                        //Get Item ID
                                                        item_id_input = search_input;

                                                        //Get Item's New Name
                                                        cout << "Input New Item Name:";
                                                        getline(cin >> ws, item_name_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Item Name:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> item_name_input;
                                                        }

                                                        ill.updateItemName(item_id_input, item_name_input);
                                                        ill.showUpdatedItem(item_id_input);

                                                        break;
                                                    case 2: //Unit Price
                                                        cout << "------Update Item Price------" << endl;
                                                        //Get Item ID
                                                        item_id_input = search_input;

                                                        //Get Item's New Unit Price
                                                        cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                                        cin >> unit_price_input;

                                                        while(cin.fail()) {
                                                            cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> unit_price_input;
                                                        }

                                                        ss << unit_price_input;

                                                        f_unit_price_input = validation.checkFormatPrice(ss.str());

                                                        ill.updateItemPrice(item_id_input, f_unit_price_input);
                                                        ill.showUpdatedItem(item_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            item_size = ill.getSize();

                                            cout << "---------Delete Item---------" << endl;

                                            //Get Item ID to update
                                            item_id_input = search_input;

                                            ill.deleteItem(item_id_input);
                                            ill.rearrangeItemID();
                                            ill.showItemDetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                        }
                    }
                case 5: //Produce Sales Order Report
                    while(true) { //(tutorialspoint, n.d.)
                        menu.soeReportMenu();

                        p = poll.getSize();
                        c = cll.getSize();
                        i = ill.getSize();

                        cout << "Your Input:";
                        cin >> report_opt;
                        cout << endl;

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> report_opt;
                        }

                        if (report_opt == 3) {
                            break;
                        }

                        switch(report_opt) {
                            case 1: //Summary Report
                                cout << "----------------------Summary Report----------------------" << endl;
                                cout << "Date Report Generated: " << ltm->tm_mday << "/"
                                     << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
                                cout << "Time Report Generated: " << ltm->tm_hour << ":"
                                     << ltm->tm_min << ":" << ltm->tm_sec << endl;
                                cout << "Requested By User: " << ull.getUsername(cache_id) << endl << endl;

                                //Second Section - Summary Details
                                cout << "Summary Table" << endl;
                                cout << "------------" << "----------------" << "---------------" << endl;
                                cout << "| Total PO |" << "| Total Client |" << "| Total Items |" << endl;
                                cout << "------------" << "----------------" << "---------------" << endl;
                                cout << "|     " << p << "    |" << "|        " << c << "     |" << "|       " << i << "     |"
                                     << endl;
                                cout << "------------" << "----------------" << "---------------" << endl;

                                cout << endl << "(Auto-Generated by ABCD POMS)" << endl << endl;

                                break;
                            case 2: //Purchase Order List Report
                                ss.str("");

                                //Format Returned Total Revenue
                                f_totalRevenue = poll.getTotalRevenue();
                                ss << f_totalRevenue;
                                totalRevenue = validation.checkFormatPrice(ss.str());

                                //Get Total Quantity
                                totalQuantity = poll.getTotalQty();

                                //Get Delivery Status
                                delivery_status = poll.getDeliveryStatus();
                                separatorPos = delivery_status.find(":");
                                f_totalProcessed = delivery_status.substr(0, separatorPos);
                                f_totalOngoing = delivery_status.substr(separatorPos+1, delivery_status.length());
                                totalProcessed = stoi(f_totalProcessed);
                                totalOngoing = stoi(f_totalOngoing);

                                cout << "--------------Purchase Order (PO) List Report--------------" << endl;
                                cout << "Date Report Generated: " << ltm->tm_mday << "/"
                                     << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
                                cout << "Time Report Generated: " << ltm->tm_hour << ":"
                                     << ltm->tm_min << ":" << ltm->tm_sec << endl;
                                cout << "Requested By User: " << ull.getUsername(cache_id) << endl << endl;

                                //Second Section - Purchase Order Details
                                cout << "----------------------------------------------------------" << endl;
                                cout << "Total Number of PO Made: " << p << endl;
                                cout << "Total Quantity of Items Sold: " << totalQuantity << endl;
                                cout << "Total Number of Processed PO: " << totalProcessed << endl;
                                cout << "Total Number of Ongoing PO: " << totalOngoing << endl;
                                cout << "Total Revenue Made: " << totalRevenue << endl;
                                cout << "----------------------------------------------------------" << endl;

                                cout << endl << "(Auto-Generated by ABCD POMS)" << endl << endl;

                                break;
                        }
                    }

                    break;
                case 6: //Settings
                    while(true) {
                        menu.settingsMenu();

                        cout << "Your Input:";
                        cin >> settings_opt;
                        cout << endl;

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> settings_opt;
                        }

                        if (settings_opt == 4) {
                            break;
                        }

                        switch(settings_opt) {
                            case 1: //My Information
                                ull.showSelfInfo(cache_id);

                                break;
                            case 2: //Change My Password
                                cout << "------Change My Password------" << endl;

                                //Get User ID
                                user_id_input = cache_id;

                                //Get User's New Password
                                cout << "Input New Password:";
                                getline(cin >> ws, password_input);

                                while(cin.fail()) {
                                    cout << "Input New Password:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, password_input);
                                }

                                ull.updateUserPassword(user_id_input, password_input);

                                break;
                            case 3: //Delete My Account
                                user_id_input = cache_id;

                                ull.deleteUser(user_id_input);
                                ull.rearrangeUserID();

                                break;
                            default:
                                break;
                        }
                        break;
                    }

                    break;
                default:
                    break;
            }

            if (settings_opt == 3) {
                break;
            }

        }
    } else {
        cout << endl;
        cout << "Login Failed, Please Try Again!" << endl << endl;
    }
}

void runAdmin() {
    //Menu Variables
    string adminUsername, adminPassword, adminRole = "Admin";
    int main_opt, actions_opt, actions_input, sort_opt, sort_dir_opt, search_opt, search_input;
    int update_opt, report_opt, settings_opt;

    //CRUD Variables
    int po_size, client_size, item_size, user_size;
    int day_input, month_input, year_input, cache_id;
    string date_input, f_day, f_month, f_year, f_total_input, f_unit_price_input;
    string client_name_input, item_name_input, delivery_input;
    string client_address_input, client_contact_input, username_input, password_input, role_input;
    int po_id_input, client_id_input, item_id_input, user_id_input, quantity_input, RM_pos;
    int p, c, i, u, totalQuantity, totalProcessed, totalOngoing, separatorPos, totalSoe, totalAdmin; //For Report;
    string totalRevenue, delivery_status, f_totalProcessed, f_totalOngoing, role, f_totalAdmin, f_totalSoe;
    float total_input, unit_price_input, f_totalRevenue;
    bool valiResp;

    //Login
    cout << "Please Provide Your Login Information:" << endl;
    cout << "Username:";
    cin >> adminUsername;
    cout << "Password:";
    cin >> adminPassword;

    cache_id = ull.getID(adminUsername);

    bool verificationStatus = ull.verifyLogin(adminUsername, adminPassword, adminRole);

    if (verificationStatus == true) {
        while (true) {
            cout << endl;
            cout << "----Welcome Back, " << adminUsername << "!----" << endl;

            menu.AdminMainMenu();

            cout << "Your Input:";
            cin >> main_opt;
            cout << endl;

            while(cin.fail()) {
                cout << "Your Input:";
                cout << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> main_opt;
            }

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> sort_opt;
                                    }

                                    if (sort_opt == 8) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Purchase Order ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on PO ID"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on PO ID"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOClientID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Client ID"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOClientID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Client ID"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 3: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOItemID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Item ID"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOItemID();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Item ID"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 4: //Date
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPODate();
                                                        poll.sortPODate();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Date"
                                                             << " (Ascending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPODate();
                                                        poll.sortPODate();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Date"
                                                             << " (Descending)------" << endl;

                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 5: //Quantity
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOQty();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Quantity"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOQty();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Quantity"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 6: //Total
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPOTotal();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Total"
                                                             << " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPOTotal();

                                                        cout << "------Sorted Purchase Order (PO) List Based on Total"
                                                             << " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 7: //Delivery Status
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        poll.sortPODeliveryStatus();

                                                        cout << "------Sorted User List Based on Delivery Status" <<
                                                             " (Ascending)------" << endl;
                                                        poll.showPOListAsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        poll.sortPODeliveryStatus();

                                                        cout << "------Sorted User List Based on Delivery Status" <<
                                                             " (Descending)------" << endl;
                                                        cout << "POID" << sn.spacePrinter(6,4)
                                                             << "Date" << sn.spacePrinter(20, 4)
                                                             << "Client ID" << sn.spacePrinter(15, 9)
                                                             << "Item ID" << sn.spacePrinter(15, 7)
                                                             << "Qty" << sn.spacePrinter(10, 3)
                                                             << "Total" << sn.spacePrinter(15, 5)
                                                             << "Delivery Status" << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 15 + 15 + 10 + 15 + 15) << endl; // number of dashes

                                                        poll.showPOListDsc(poll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                //Initialize Variables
                                po_size = poll.getSize();
                                client_size = cll.getSize();
                                item_size = ill.getSize();

                                ss.str(""); //Clear StringStream (BartoszKP & Wilka, 2015)

                                cout << "------Add New Purchase Order------" << endl;

                                //Date Input
                                cout << "Input Date (i.e. 11 02 2024):";
                                cin >> day_input >> month_input >> year_input;

                                while(cin.fail()) {
                                    cout << "Input Date (i.e. 11 02 2024):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> day_input >> month_input >> year_input;
                                }

                                valiResp = validation.checkDate(day_input, month_input, year_input); //First-Check

                                while (valiResp == false) {
                                    cout << "Either Your Date Format is Wrong or Date is False!" << endl;
                                    cout << "Input Date (i.e. 11 02 2024):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> setw(2) >> day_input >> setw(2) >> month_input >> setw (4) >> year_input;

                                    valiResp = validation.checkDate(day_input, month_input, year_input); //Re-Check
                                }

                                //Processing Date Format
                                date_input = validation.formatDate(day_input, month_input, year_input);
                                f_day = date_input.substr(0, 2); //Get Day
                                f_month = date_input.substr(2, 2); //Get Month
                                f_year = date_input.substr(4, 7); //Get Year

                                date_input = f_day + "/" + f_month + "/" + f_year; //Formatting (dd/mm/yyyy)

                                //Client ID Input
                                cout << "Input Client ID (From 1-" << client_size << "):";
                                cin >> client_id_input;

                                while (cin.fail() || client_id_input > client_size || client_id_input <= 0) {
                                    cout << "Wrong Input or Client ID Provided Don't Exist!" << endl;
                                    cout << "Input Client ID (From 1-" << client_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_id_input;
                                }

                                //Item ID Input
                                cout << "Input Item ID (From 1-" << item_size << "):";
                                cin >> item_id_input;

                                while (cin.fail() || item_id_input > item_size || item_id_input <= 0) {
                                    cout << "Wrong Input or Item ID Provided Don't Exist!" << endl;
                                    cout << "Input Item ID (From 1-" << item_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> item_id_input;
                                }

                                //Quantity Input
                                cout << "Input Quantity:";
                                cin >> quantity_input;

                                while (cin.fail() || quantity_input > 1000) {
                                    cout << "Input Quantity:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> quantity_input;
                                }

                                //Total Input (geeksforgeeks n.d., w3schools, n.d.)
                                f_total_input = ill.getItemPrice(item_id_input); //get item unit price.
                                RM_pos = f_total_input.find("RM"); //Find RM position
                                f_total_input = f_total_input.substr(RM_pos+2, f_total_input.length());

                                total_input = stof(f_total_input) * quantity_input; //Convert to Double and Total.
                                total_input = floor(total_input * 100) / 100; //Round off to 2 dp.

                                ss << total_input; //Convert Float to String.

                                f_total_input = validation.checkFormatPrice(ss.str());

                                //Delivery Status Input
                                cout << "Input Delivery Status (Processed/ Ongoing):";
                                cin >> delivery_input;

                                while (cin.fail() || (delivery_input != "Processed" &&
                                       delivery_input != "Ongoing")) {
                                    cout << "Input Delivery Status (Processed/ Ongoing):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> delivery_input;
                                }

                                cout << endl;

                                //Insert New Record
                                poll.insertPOAtEnd(po_size + 1, date_input, client_id_input, item_id_input,
                                                   quantity_input, f_total_input, delivery_input);
                                poll.showPODetails();

                                break;
                            case 3: //Update Data
                                while (true) {
                                    menu.updatePOMenu();
                                    po_size = poll.getSize();
                                    ss.str("");

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if(update_opt == 4) {
                                        break;
                                    }

                                    switch (update_opt) {
                                        case 1: //Update Date
                                            cout << "------Update PO's Date------" << endl;

                                            //Get Purchase Order ID to update
                                            cout << "Purchase Order ID to update (1-" << po_size << "):";
                                            cin >> po_id_input;

                                            while(cin.fail() || po_id_input > po_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Purchase Order ID to update (1-" << po_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> po_id_input;
                                            }

                                            //Get New Date
                                            cout << "Input New Date (i.e. 11 02 2024):";
                                            cin >> day_input >> month_input >> year_input;

                                            while(cin.fail()) {
                                                cout << "Input New Date (i.e. 11 02 2024):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> day_input >> month_input >> year_input;
                                            }

                                            valiResp = validation.checkDate(day_input, month_input, year_input); //First-Check

                                            while (valiResp == false) {
                                                cout << "Either Your Date Format is Wrong or Date is False!" << endl;
                                                cout << "Input Date (i.e. 11 02 2024):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> setw(2) >> day_input >> setw(2) >> month_input >>
                                                    setw (4) >> year_input;

                                                valiResp = validation.checkDate(day_input, month_input, year_input); //Re-Check
                                            }

                                            //Processing Date Format
                                            date_input = validation.formatDate(day_input, month_input, year_input);
                                            f_day = date_input.substr(0, 2); //Get Day
                                            f_month = date_input.substr(2, 2); //Get Month
                                            f_year = date_input.substr(4, 7); //Get Year

                                            date_input = f_day + "/" + f_month + "/" + f_year; //Formatting (dd/mm/yyyy)

                                            poll.updatePODate(po_id_input, date_input);
                                            poll.showPODetails();

                                            break;
                                        case 2: //Update Quantity
                                            cout << "------Update PO's Quantity------" << endl;

                                            //Get Purchase Order ID to update
                                            cout << "Purchase Order ID to update (1-" << po_size << "):";
                                            cin >> po_id_input;

                                            while(cin.fail() || po_id_input > po_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Purchase Order ID to update (1-" << po_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> po_id_input;
                                            }

                                            //Get New Quantity
                                            cout << "Input New Quantity:";
                                            cin >> quantity_input;

                                            while (cin.fail() || quantity_input > 1000) {
                                                cout << "Input Quantity:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> quantity_input;
                                            }

                                            //Get Item ID
                                            item_id_input = poll.searchItemID(po_id_input);

                                            //Re-Calculate Total (geeksforgeeks n.d., w3schools, n.d.)
                                            f_total_input = ill.getItemPrice(item_id_input); //Get item unit price.

                                            cout << f_total_input << endl;

                                            RM_pos = f_total_input.find("RM"); //Find RM position
                                            f_total_input = f_total_input.substr(RM_pos+2, f_total_input.length());

                                            total_input = stof(f_total_input) * quantity_input; //Convert to Float and Total.
                                            total_input = floor(total_input * 100) / 100; //Round off to 2 dp.

                                            ss << total_input; //Convert Float to String.

                                            f_total_input = validation.checkFormatPrice(ss.str());

                                            poll.updatePOQty(po_id_input, quantity_input, f_total_input);
                                            poll.showPODetails();

                                            break;
                                        case 3: //Update Delivery Status
                                            cout << "------Update PO's Delivery Status------" << endl;

                                            //Get Purchase Order ID to update
                                            cout << "Purchase Order ID to update (1-" << po_size << "):";
                                            cin >> po_id_input;

                                            while(cin.fail() || po_id_input > po_size) {
                                                cout << "Error: Invalid ID or ID Format!" << endl;
                                                cout << "Purchase Order ID to update (1-" << po_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> po_id_input;
                                            }

                                            //Delivery Status Input
                                            cout << "Input Delivery Status (Processed/ Ongoing):";
                                            cin >> delivery_input;

                                            while (cin.fail() || (delivery_input != "Processed" &&
                                                                  delivery_input != "Ongoing")) {
                                                cout << "Input Delivery Status (Processed/ Ongoing):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> delivery_input;
                                            }

                                            poll.updatePODeliStatus(po_id_input, delivery_input);
                                            poll.showPODetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                po_size = poll.getSize();

                                cout << "------Delete Purchase Order------" << endl;
                                //Get Purchase Order ID to delete
                                cout << "Purchase Order ID to delete (1-" << po_size << "):";
                                cin >> po_id_input;

                                while(cin.fail() || po_id_input > po_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "Purchase Order ID to delete (1-" << po_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> po_id_input;
                                }

                                poll.deletePurchaseOrder(po_id_input);
                                poll.rearrangePOID();
                                poll.showPODetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    if (sort_opt == 2) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Client ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        cll.sortClientID();

                                                        cout << "------Sorted Client List Based on Client ID" <<
                                                             " (Ascending)------" << endl;
                                                        cll.showClientListAsc(cll.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        cll.sortClientID();

                                                        cout << "------Sorted Client List Based on Client ID" <<
                                                             " (Descending)------" << endl;
                                                        cout << "List of Users (Total Number of Client: " << client_size << "):" << endl;
                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Name" << sn.spacePrinter(15, 4)
                                                             << "Address" << sn.spacePrinter(35, 7)
                                                             << "Contact No" << endl;
                                                        cout << sn.headerUnderline(6 + 15 + 35 + 10) << endl; // number of dashes

                                                        cll.showClientListDsc(cll.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                //Initialize Variable
                                client_size = cll.getSize();

                                cout << "------Add New Client------" << endl;

                                //Client Name
                                cout << "Input Client Name:";
                                getline(cin >> ws, client_name_input);

                                while(cin.fail()) {
                                    cout << "Wrong Input or Input cannot be Empty!" << endl;
                                    cout << "Input Client Name:";
                                    cin.clear();
                                    getline(cin >> ws, client_name_input);
                                }

                                //Client Address
                                cout << "Input Client Address:";
                                getline(cin >> ws, client_address_input);

                                while(cin.fail()) {
                                    cout << "Wrong Input or Input cannot be Empty!" << endl;
                                    cout << "Input Client Address:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, client_address_input);
                                }

                                //Client Contacts
                                cout << "Input Client Contact No (i.e. 011-12345678):";
                                cin >> client_contact_input;

                                while(cin.fail()) {
                                    cout << "Wrong Input or Input cannot be Empty!" << endl;
                                    cout << "Input Client Contact No (i.e. 011-12345678):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_contact_input;
                                }

                                valiResp = validation.checkContactFormat(client_contact_input);

                                while (valiResp == false) {
                                    cout << "Wrong Input Format or Input cannot be Empty!" << endl;
                                    cout << "Input Client Contact No (i.e. 011-12345678):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_contact_input;

                                    valiResp = validation.checkContactFormat(client_contact_input);
                                }

                                cll.insertClientAtEnd(client_size + 1, client_name_input,
                                                      client_address_input, client_contact_input);
                                cll.showClientDetails();


                                break;
                            case 3: //Update Data
                                while (true) {
                                    //Initialize Variable
                                    menu.updateClientMenu();
                                    client_size = cll.getSize();

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if (update_opt == 4) {
                                        break;
                                    }

                                    switch (update_opt) {
                                        case 1: //Name
                                            cout << "------Update Client's Name------" << endl;
                                            //Get Client ID
                                            cout << "Input Client's ID (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size ||
                                                  client_id_input <= 0) {
                                                cout << "Invalid Client ID!";
                                                cout << "Input Client's ID (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            //Get New Client's Name
                                            cout << "Input New Client's Name:";
                                            getline(cin >> ws, client_name_input);

                                            while(cin.fail()) {
                                                cout << "Input New Client's Name:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, client_name_input);
                                            }

                                            cll.updateClientName(client_id_input, client_name_input);
                                            cll.showClientDetails();

                                            break;
                                        case 2: //Address
                                            cout << "------Update Client's Address------" << endl;
                                            //Get Client ID
                                            cout << "Input Client's ID (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size ||
                                                  client_id_input <= 0) {
                                                cout << "Invalid Client ID!";
                                                cout << "Input Client's ID (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            //Get New Client's Address
                                            cout << "Input New Client's Address:";
                                            getline(cin >> ws, client_address_input);

                                            while(cin.fail()) {
                                                cout << "Input New Client's Address:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, client_address_input);
                                            }

                                            cll.updateClientAddress(client_id_input, client_address_input);
                                            cll.showClientDetails();

                                            break;
                                        case 3: //Contacts
                                            cout << "------Update Client's Contacts------" << endl;
                                            //Get Client ID
                                            cout << "Input Client's ID (1-" << client_size << "):";
                                            cin >> client_id_input;

                                            while(cin.fail() || client_id_input > client_size ||
                                                  client_id_input <= 0) {
                                                cout << "Invalid Client ID!";
                                                cout << "Input Client's ID (1-" << client_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_id_input;
                                            }

                                            //Get New Client's Contact
                                            cout << "Input New Client Contact No (i.e. 011-12345678):";
                                            cin >> client_contact_input;

                                            while(cin.fail()) {
                                                cout << "Wrong Input or Input cannot be Empty!" << endl;
                                                cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_contact_input;
                                            }

                                            valiResp = validation.checkContactFormat(client_contact_input);

                                            while (valiResp == false) {
                                                cout << "Wrong Input Format or Input cannot be Empty!" << endl;
                                                cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> client_contact_input;

                                                valiResp = validation.checkContactFormat(client_contact_input);
                                            }

                                            cll.updateClientContacts(client_id_input, client_contact_input);
                                            cll.showClientDetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                client_size = cll.getSize();

                                cout << "------Delete Client------" << endl;

                                //Get Client ID to update
                                cout << "Client ID to delete (1-" << client_size << "):";
                                cin >> client_id_input;

                                while(cin.fail() || client_id_input > client_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "Client ID to delete (1-" << client_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> client_id_input;
                                }

                                cll.deleteClient(client_id_input);
                                cll.rearrangeClientID();
                                cll.showClientDetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> sort_opt;
                                    }

                                    if (sort_opt == 3) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //Item ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        ill.sortItemID();

                                                        cout << "------Sorted Item List Based on Item ID" <<
                                                             " (Ascending)------" << endl;
                                                        ill.showItemListAsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        ill.sortItemID();

                                                        cout << "------Sorted Item List Based on Item ID" <<
                                                             " (Descending)------" << endl;

                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Name" << sn.spacePrinter(20, 4)
                                                             << "Unit Price"  << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes

                                                        ill.showItemListDsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Unit Price
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        ill.sortUnitPrice();

                                                        cout << "------Sorted Item List Based on Unit Price" <<
                                                                " (Ascending)------" << endl;
                                                        ill.showItemListAsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        ill.sortUnitPrice();

                                                        cout << "------Sorted Item List Based on Unit Price" <<
                                                                " (Descending)------" << endl;

                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Name" << sn.spacePrinter(20, 4)
                                                             << "Unit Price"  << endl;
                                                        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes

                                                        ill.showItemListDsc(ill.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                //Initialize Variable
                                item_size = ill.getSize();
                                ss.str("");

                                cout << "------Add New Item------" << endl;

                                //Item Name
                                cout << "Input Item Name:";
                                getline(cin >> ws, item_name_input);

                                while(cin.fail()) {
                                    cout << "Input Item Name:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, item_name_input);
                                }

                                //Unit Price
                                cout << "Input Item Unit Price (i.e. 10.00 / 10.5): RM";
                                cin >> unit_price_input;

                                while(cin.fail()) {
                                    cout << "Input Item Unit Price (i.e. 10.00): RM";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> unit_price_input;
                                }

                                ss << unit_price_input;

                                f_unit_price_input = validation.checkFormatPrice(ss.str());

                                ill.insertItemAtEnd(item_size + 1, item_name_input, f_unit_price_input);
                                ill.showItemDetails();


                                break;
                            case 3: //Update Data
                                while(true) {
                                    //Initialize Variable
                                    menu.updateItemMenu();
                                    item_size = ill.getSize();
                                    ss.str("");

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if (update_opt == 3) {
                                        break;
                                    }

                                    switch(update_opt) {
                                        case 1: //Name
                                            cout << "------Update Item Name------" << endl;
                                            //Get Item ID
                                            cout << "Input Item ID (1-" << item_size << "):";
                                            cin >> item_id_input;

                                            while(cin.fail() || item_id_input > item_size ||
                                                  item_id_input <= 0) {
                                                cout << "Input Item ID (1-" << item_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> item_id_input;
                                            }

                                            //Get Item's New Name
                                            cout << "Input New Item Name:";
                                            getline(cin >> ws, item_name_input);

                                            while(cin.fail()) {
                                                cout << "Input New Item Name:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> item_name_input;
                                            }

                                            ill.updateItemName(item_id_input, item_name_input);
                                            ill.showItemDetails();

                                            break;
                                        case 2: //Unit Price
                                            cout << "------Update Item Price------" << endl;
                                            //Get Item ID
                                            cout << "Input Item ID (1-" << item_size << "):";
                                            cin >> item_id_input;

                                            while(cin.fail() || item_id_input > item_size
                                                  || item_id_input <= 0) {
                                                cout << "Input Item ID (1-" << item_size << "):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> item_id_input;
                                            }

                                            //Get Item's New Unit Price
                                            cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                            cin >> unit_price_input;

                                            while(cin.fail()) {
                                                cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> unit_price_input;
                                            }

                                            ss << unit_price_input;

                                            f_unit_price_input = validation.checkFormatPrice(ss.str());

                                            ill.updateItemPrice(item_id_input, f_unit_price_input);
                                            ill.showItemDetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                item_size = ill.getSize();

                                cout << "------Delete Item------" << endl;

                                //Get Item ID to update
                                cout << "Item ID to delete (1-" << item_size << "):";
                                cin >> item_id_input;

                                while(cin.fail() || item_id_input > item_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "Item ID to delete (1-" << item_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> item_id_input;
                                }

                                ill.deleteItem(item_id_input);
                                ill.rearrangeItemID();
                                ill.showItemDetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> actions_opt;
                        }

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

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> sort_opt;
                                    }

                                    if (sort_opt == 3) {
                                        break;
                                    }

                                    switch(sort_opt) {
                                        case 1: //User ID
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        ull.sortUserID();

                                                        cout << "------Sorted User List Based on User ID" <<
                                                             " (Ascending)------" << endl;
                                                        ull.showUserListAsc(ull.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        ull.sortUserID();

                                                        cout << "------Sorted User List Based on User ID" <<
                                                             " (Descending)------" << endl;
                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Username" << sn.spacePrinter(15, 8)
                                                             << "Password" << sn.spacePrinter(15, 8)
                                                             << "Role" << endl;
                                                        cout << sn.headerUnderline(6 + 15 + 15 + 4) << endl; // number of dashes

                                                        ull.showUserListDsc(ull.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Roles
                                            while(true) {
                                                menu.sortDirection();

                                                cout << "Your Input:";
                                                cin >> sort_dir_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> sort_dir_opt;
                                                }

                                                if (sort_dir_opt == 3) {
                                                    break;
                                                }

                                                switch (sort_dir_opt) {
                                                    case 1: //Ascending
                                                        ull.sortRole();

                                                        cout << "------Sorted User List Based on Role" << " (Descending)------" << endl;
                                                        ull.showUserListAsc(ull.head);
                                                        cout << endl;

                                                        break;
                                                    case 2: //Descending
                                                        ull.sortRole();

                                                        cout << "------Sorted User List Based on Role" << " (Descending)------" << endl;
                                                        cout << "ID" << sn.spacePrinter(6, 2)
                                                             << "Username" << sn.spacePrinter(15, 8)
                                                             << "Password" << sn.spacePrinter(15, 8)
                                                             << "Role" << endl;
                                                        cout << sn.headerUnderline(6 + 15 + 15 + 4) << endl; // number of dashes

                                                        ull.showUserListDsc(ull.head);
                                                        cout << endl;

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        default:
                                            break;
                                    }
                                }

                                break;
                            case 2: //Add New Data
                                //Initialize Data
                                user_size = ull.getSize();

                                cout << "------Add New User------" << endl;

                                //Username Input
                                cout << "Input Username:";
                                getline(cin >> ws, username_input);

                                while(cin.fail()) {
                                    cout << "Input Username:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, username_input);
                                }

                                //Password Input
                                cout << "Input Password:";
                                getline(cin >> ws, password_input);

                                while(cin.fail()) {
                                    cout << "Input Password:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, password_input);
                                }

                                //Role Input
                                cout << "Input Role (Admin/ SoE):";
                                getline(cin >> ws, role_input);

                                while(cin.fail() || (role_input != "Admin" && role_input != "SoE")) {
                                    cout << "Input Role (Admin/ SoE):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, role_input);
                                }

                                ull.insertUserAtEnd(user_size + 1, username_input, password_input,
                                                    role_input);
                                ull.showUserDetails();

                                break;
                            case 3: //Update Data
                                while(true) {
                                    menu.updateUserMenu();
                                    user_size = ull.getSize();

                                    cout << "Your Input:";
                                    cin >> update_opt;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> update_opt;
                                    }

                                    if(update_opt == 4) {
                                        break;
                                    }

                                    switch(update_opt) {
                                        case 1: //Username
                                            cout << "------Update User's Username------" << endl;

                                            //Get User ID
                                            cout << "Input User ID:";
                                            cin >> user_id_input;
                                            cout << endl;

                                            while(cin.fail() || user_id_input > user_size ||
                                                  user_id_input <= 0) {
                                                cout << "Input User ID:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> user_id_input;
                                            }

                                            role_input = ull.getRoleBasedID(user_id_input);

                                            //Get User's New Username
                                            cout << "Input New Username:";
                                            getline(cin >> ws, username_input);

                                            while(cin.fail()) {
                                                cout << "Input New Username:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, username_input);
                                            }

                                            valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                              role_input);

                                            while(valiResp == true) {
                                                cout << "Error: User with the same username and role exist!";
                                                cout << "Input New Username:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, username_input);

                                                valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                                  role_input);
                                            }

                                            ull.updateUserUsername(user_id_input, username_input);
                                            ull.showUserDetails();

                                            break;
                                        case 2: //Password
                                            cout << "------Update User's Password------" << endl;

                                            //Get User ID
                                            cout << "Input User ID:";
                                            cin >> user_id_input;

                                            while(cin.fail() || user_id_input > user_size ||
                                                  user_id_input <= 0) {
                                                cout << "Input User ID:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> user_id_input;
                                            }

                                            //Get User's New Password
                                            cout << "Input New Password:";
                                            getline(cin >> ws, password_input);

                                            while(cin.fail()) {
                                                cout << "Input New Password:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, password_input);
                                            }

                                            ull.updateUserPassword(user_id_input, password_input);
                                            ull.showUserDetails();

                                            break;
                                        case 3: //Role
                                            cout << "------Update User's Role------" << endl;

                                            //Get User ID
                                            cout << "Input User ID:";
                                            cin >> user_id_input;

                                            while(cin.fail() || user_id_input > user_size ||
                                                  user_id_input <= 0) {
                                                cout << "Input User ID:";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                cin >> user_id_input;
                                            }

                                            //Get User's Username
                                            username_input = ull.getUsername(user_id_input);

                                            //Get User's New Role
                                            cout << "Input New Role (Admin/ SoE):";
                                            getline(cin >> ws, role_input);

                                            while(cin.fail() || (role_input != "Admin" && role_input != "SoE")) {
                                                cout << "Input New Role (Admin/ SoE):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, role_input);
                                            }

                                            valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                              role_input);

                                            while(valiResp == true) {
                                                cout << "Error: User with the same username and role exist!"
                                                     << endl;
                                                cout << "Input New Role (Admin/ SoE):";
                                                cin.clear();
                                                cin.ignore(256, '\n');
                                                getline(cin >> ws, role_input);

                                                valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                                  role_input);
                                            }

                                            ull.updateUserRole(user_id_input, role_input);
                                            ull.showUserDetails();

                                            break;
                                    }
                                }

                                break;
                            case 4: //Delete Data
                                user_size = ull.getSize();

                                cout << "------Delete User------" << endl;

                                //Get User ID to update
                                cout << "User ID to delete (1-" << user_size << "):";
                                cin >> user_id_input;

                                while(cin.fail() || user_id_input > user_size) {
                                    cout << "Error: Invalid ID or ID Format!" << endl;
                                    cout << "User ID to delete (1-" << user_size << "):";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> user_id_input;
                                }

                                ull.deleteUser(user_id_input);
                                ull.rearrangeUserID();
                                ull.showUserDetails();

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

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> search_opt;
                        }

                        if (search_opt == 5) {
                            break;
                        }

                        switch (search_opt) {
                            case 1: //Search Purchase Order
                                cout << "Purchase Order ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "Purchase Order ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                poll.searchPurchaseOrder(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while(true) {
                                                menu.updatePOMenu();
                                                po_size = poll.getSize();

                                                cout << "Your Input:";
                                                cin >> update_opt;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if(update_opt == 4) {
                                                    break;
                                                }

                                                switch (update_opt) {
                                                    case 1: //Update Date
                                                        cout << "------Update PO's Date------" << endl;

                                                        //Get Purchase Order ID to update
                                                        po_id_input = search_input;

                                                        //Get New Date
                                                        cout << "Input New Date (i.e. 11 02 2024):";
                                                        cin >> day_input >> month_input >> year_input;

                                                        while(cin.fail()) {
                                                            cout << "Input New Date (i.e. 11 02 2024):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> day_input >> month_input >> year_input;
                                                        }

                                                        valiResp = validation.checkDate(day_input, month_input, year_input); //First-Check

                                                        while (valiResp == false) {
                                                            cout << "Either Your Date Format is Wrong or Date is False!" << endl;
                                                            cout << "Input Date (i.e. 11 02 2024):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> setw(2) >> day_input >> setw(2) >> month_input >>
                                                                setw (4) >> year_input;

                                                            valiResp = validation.checkDate(day_input, month_input, year_input); //Re-Check
                                                        }

                                                        //Processing Date Format
                                                        date_input = validation.formatDate(day_input, month_input, year_input);
                                                        f_day = date_input.substr(0, 2); //Get Day
                                                        f_month = date_input.substr(2, 2); //Get Month
                                                        f_year = date_input.substr(4, 7); //Get Year

                                                        date_input = f_day + "/" + f_month + "/" + f_year; //Formatting (dd/mm/yyyy)

                                                        poll.updatePODate(po_id_input, date_input);
                                                        poll.searchUpdatedPO(po_id_input);

                                                        break;
                                                    case 2: //Update Quantity
                                                        cout << "------Update PO's Quantity------" << endl;

                                                        //Get Purchase Order ID to update
                                                        po_id_input = search_input;

                                                        //Get New Quantity
                                                        cout << "Input New Quantity:";
                                                        cin >> quantity_input;

                                                        while (cin.fail() || quantity_input > 1000) {
                                                            cout << "Input Quantity:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> quantity_input;
                                                        }

                                                        //Get Item ID
                                                        item_id_input = poll.searchItemID(po_id_input);

                                                        //Re-Calculate Total (geeksforgeeks n.d., w3schools, n.d.)
                                                        f_total_input = ill.getItemPrice(item_id_input); //Get item unit price.

                                                        cout << f_total_input << endl;

                                                        RM_pos = f_total_input.find("RM"); //Find RM position
                                                        f_total_input = f_total_input.substr(RM_pos+2, f_total_input.length());

                                                        total_input = stof(f_total_input) * quantity_input; //Convert to Float and Total.
                                                        total_input = floor(total_input * 100) / 100; //Round off to 2 dp.

                                                        ss << total_input; //Convert Float to String.

                                                        f_total_input = validation.checkFormatPrice(ss.str());

                                                        poll.updatePOQty(po_id_input, quantity_input, f_total_input);
                                                        poll.searchUpdatedPO(po_id_input);

                                                        break;
                                                    case 3: //Update Delivery Status
                                                        cout << "------Update PO's Delivery Status------" << endl;

                                                        //Get Purchase Order ID to update
                                                        po_id_input = search_input;

                                                        //Delivery Status Input
                                                        cout << "Input Delivery Status (Processed/ Ongoing):";
                                                        cin >> delivery_input;

                                                        while (cin.fail() || (delivery_input != "Processed" &&
                                                                              delivery_input != "Ongoing")) {
                                                            cout << "Input Delivery Status (Processed/ Ongoing):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> delivery_input;
                                                        }

                                                        poll.updatePODeliStatus(po_id_input, delivery_input);
                                                        poll.searchUpdatedPO(po_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            po_size = poll.getSize();

                                            cout << "------Delete Purchase Order------" << endl;
                                            //Get Purchase Order ID to delete
                                            po_id_input = search_input;

                                            poll.deletePurchaseOrder(po_id_input);
                                            poll.rearrangePOID();
                                            poll.showPODetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                            case 2: //Search Client
                                cout << "Client ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "Client ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                cll.searchClient(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while (true) {
                                                //Initialize Variable
                                                menu.updateClientMenu();
                                                client_size = cll.getSize();

                                                cout << "Your Input:";
                                                cin >> update_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if (update_opt == 4) {
                                                    break;
                                                }

                                                switch (update_opt) {
                                                    case 1: //Name
                                                        cout << "------Update Client's Name------" << endl;
                                                        //Get Client ID
                                                        client_id_input = search_input;

                                                        //Get New Client's Name
                                                        cout << "Input New Client's Name:";
                                                        getline(cin >> ws, client_name_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Client's Name:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, client_name_input);
                                                        }

                                                        cll.updateClientName(client_id_input, client_name_input);
                                                        cll.showUpdatedClient(client_id_input);

                                                        break;
                                                    case 2: //Address
                                                        cout << "------Update Client's Address------" << endl;
                                                        //Get Client ID
                                                        client_id_input = search_input;

                                                        //Get New Client's Address
                                                        cout << "Input New Client's Address:";
                                                        getline(cin >> ws, client_address_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Client's Address:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, client_address_input);
                                                        }

                                                        cll.updateClientAddress(client_id_input, client_address_input);
                                                        cll.showUpdatedClient(client_id_input);

                                                        break;
                                                    case 3: //Contacts
                                                        cout << "------Update Client's Contacts------" << endl;
                                                        //Get Client ID
                                                        client_id_input = search_input;

                                                        //Get New Client's Contact
                                                        cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                        cin >> client_contact_input;

                                                        while(cin.fail()) {
                                                            cout << "Wrong Input or Input cannot be Empty!" << endl;
                                                            cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> client_contact_input;
                                                        }

                                                        valiResp = validation.checkContactFormat(client_contact_input);

                                                        while (valiResp == false) {
                                                            cout << "Wrong Input Format or Input cannot be Empty!" << endl;
                                                            cout << "Input New Client Contact No (i.e. 011-12345678):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> client_contact_input;

                                                            valiResp = validation.checkContactFormat(client_contact_input);
                                                        }

                                                        cll.updateClientContacts(client_id_input, client_contact_input);
                                                        cll.showUpdatedClient(client_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            client_size = cll.getSize();

                                            cout << "------Delete Client------" << endl;

                                            //Get Client ID to update
                                            client_id_input = client_size;

                                            cll.deleteClient(client_id_input);
                                            cll.rearrangeClientID();
                                            cll.showClientDetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                            case 3: //Search Item
                                cout << "Item ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "Item ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                ill.searchItem(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while(true) {
                                                //Initialize Variable
                                                menu.updateItemMenu();
                                                item_size = ill.getSize();
                                                ss.str("");

                                                cout << "Your Input:";
                                                cin >> update_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if (update_opt == 3) {
                                                    break;
                                                }

                                                switch(update_opt) {
                                                    case 1: //Name
                                                        cout << "------Update Item Name------" << endl;
                                                        //Get Item ID
                                                        item_id_input = search_input;

                                                        //Get Item's New Name
                                                        cout << "Input New Item Name:";
                                                        getline(cin >> ws, item_name_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Item Name:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> item_name_input;
                                                        }

                                                        ill.updateItemName(item_id_input, item_name_input);
                                                        ill.showUpdatedItem(item_id_input);

                                                        break;
                                                    case 2: //Unit Price
                                                        cout << "------Update Item Price------" << endl;
                                                        //Get Item ID
                                                        item_id_input = search_input;

                                                        //Get Item's New Unit Price
                                                        cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                                        cin >> unit_price_input;

                                                        while(cin.fail()) {
                                                            cout << "Input Item New Unit Price (i.e. 10.00 / 10.5): RM";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            cin >> unit_price_input;
                                                        }

                                                        ss << unit_price_input;

                                                        f_unit_price_input = validation.checkFormatPrice(ss.str());

                                                        ill.updateItemPrice(item_id_input, f_unit_price_input);
                                                        ill.showUpdatedItem(item_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            item_size = ill.getSize();

                                            cout << "---------Delete Item---------" << endl;

                                            //Get Purchase Order ID to update
                                            item_id_input = search_input;

                                            ill.deleteItem(item_id_input);
                                            ill.rearrangeItemID();
                                            ill.showItemDetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                            case 4: //Search User
                                cout << "User ID:";
                                cin >> search_input;
                                cout << endl;

                                while(cin.fail()) {
                                    cout << "User ID:";
                                    cout << endl;
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cin >> search_input;
                                }

                                ull.searchUser(search_input);

                                while(true) {
                                    menu.afterSearchActionMenu(); //Display Search Action Menu

                                    cout << "Your Input:";
                                    cin >> actions_input;
                                    cout << endl;

                                    while(cin.fail()) {
                                        cout << "Your Input:";
                                        cout << endl;
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> actions_input;
                                    }

                                    if (actions_input == 3) {
                                        break;
                                    }

                                    switch(actions_input) {
                                        case 1: //Update Data
                                            while(true) {
                                                menu.updateUserMenu();
                                                user_size = ull.getSize();

                                                cout << "Your Input:";
                                                cin >> update_opt;
                                                cout << endl;

                                                while(cin.fail()) {
                                                    cout << "Your Input:";
                                                    cout << endl;
                                                    cin.clear();
                                                    cin.ignore(256, '\n');
                                                    cin >> update_opt;
                                                }

                                                if(update_opt == 4) {
                                                    break;
                                                }

                                                switch(update_opt) {
                                                    case 1: //Username
                                                        cout << "------Update User's Username------" << endl;

                                                        //Get User ID
                                                        user_id_input = search_input;

                                                        role_input = ull.getRoleBasedID(user_id_input);

                                                        //Get User's New Username
                                                        cout << "Input New Username:";
                                                        getline(cin >> ws, username_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Username:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, username_input);
                                                        }

                                                        valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                                          role_input);

                                                        while(valiResp == true) {
                                                            cout << "Error: User with the same username and role exist!";
                                                            cout << "Input New Username:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, username_input);

                                                            valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                                              role_input);
                                                        }

                                                        ull.updateUserUsername(user_id_input, username_input);
                                                        ull.showUpdatedUser(user_id_input);

                                                        break;
                                                    case 2: //Password
                                                        cout << "------Update User's Password------" << endl;

                                                        //Get User ID
                                                        user_id_input = search_input;

                                                        //Get User's New Password
                                                        cout << "Input New Password:";
                                                        getline(cin >> ws, password_input);

                                                        while(cin.fail()) {
                                                            cout << "Input New Password:";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, password_input);
                                                        }

                                                        ull.updateUserPassword(user_id_input, password_input);
                                                        ull.showUpdatedUser(user_id_input);

                                                        break;
                                                    case 3: //Role
                                                        cout << "------Update User's Role------" << endl;

                                                        //Get User ID
                                                        user_id_input = search_input;

                                                        //Get User's Username
                                                        username_input = ull.getUsername(user_id_input);

                                                        //Get User's New Role
                                                        cout << "Input New Role (Admin/ SoE):";
                                                        getline(cin >> ws, role_input);

                                                        while(cin.fail() || (role_input != "Admin" && role_input != "SoE")) {
                                                            cout << "Input New Role (Admin/ SoE):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, role_input);
                                                        }

                                                        valiResp = ull.checkUsernameExist(user_id_input, username_input, role_input);

                                                        while(valiResp == true) {
                                                            cout << "Error: User with the same username and role exist!"
                                                                    << endl;
                                                            cout << "Input New Role (Admin/ SoE):";
                                                            cin.clear();
                                                            cin.ignore(256, '\n');
                                                            getline(cin >> ws, role_input);

                                                            valiResp = ull.checkUsernameExist(user_id_input, username_input,
                                                                                              role_input);
                                                        }

                                                        ull.updateUserRole(user_id_input, role_input);
                                                        ull.showUpdatedUser(user_id_input);

                                                        break;
                                                }
                                                break;
                                            }

                                            break;
                                        case 2: //Delete Data
                                            user_size = ull.getSize();

                                            cout << "---------Delete User---------" << endl;

                                            //Get User ID to update
                                            user_id_input = search_input;

                                            ull.deleteUser(user_id_input);
                                            ull.rearrangeUserID();
                                            ull.showUserDetails();

                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                }

                                break;
                        }
                    }
                case 6: //Produce Sales Order Report
                    while(true) { //(tutorialspoint, n.d.)
                        menu.adminReportMenu();

                        p = poll.getSize();
                        c = cll.getSize();
                        i = ill.getSize();
                        u = ull.getSize();

                        cout << "Your Input:";
                        cin >> report_opt;
                        cout << endl;

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> report_opt;
                        }

                        if (report_opt == 4) {
                            break;
                        }

                        switch(report_opt) {
                            case 1: //Summary Report
                                cout << "----------------------Summary Report----------------------" << endl;
                                cout << "Date Report Generated: " << ltm->tm_mday << "/"
                                     << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
                                cout << "Time Report Generated: " << ltm->tm_hour << ":"
                                     << ltm->tm_min << ":" << ltm->tm_sec << endl;
                                cout << "Requested By User: " << ull.getUsername(cache_id) << endl << endl;

                                //Second Section - Summary Details
                                cout << "Summary Table" << endl;
                                cout << "------------" << "----------------" << "---------------" << "---------------" << endl;
                                cout << "| Total PO |" << "| Total Client |" << "| Total Items |" << "| Total Users |" << endl;
                                cout << "------------" << "----------------" << "---------------" << "---------------" << endl;
                                cout << "|     " << p << "    |" << "|        " << c << "     |" << "|       " << i << "     |"
                                     << "|     " << u << "       |" << endl;
                                cout << "------------" << "----------------" << "---------------" << "---------------" << endl;

                                cout << endl << "(Auto-Generated by ABCD POMS)" << endl << endl;

                                break;
                            case 2: //Purchase Order List Report
                                ss.str("");

                                //Format Returned Total Revenue
                                f_totalRevenue = poll.getTotalRevenue();
                                ss << f_totalRevenue;
                                totalRevenue = validation.checkFormatPrice(ss.str());

                                //Get Total Quantity
                                totalQuantity = poll.getTotalQty();

                                //Get Delivery Status
                                delivery_status = poll.getDeliveryStatus();
                                separatorPos = delivery_status.find(":");
                                f_totalProcessed = delivery_status.substr(0, separatorPos);
                                f_totalOngoing = delivery_status.substr(separatorPos+1, delivery_status.length());
                                totalProcessed = stoi(f_totalProcessed);
                                totalOngoing = stoi(f_totalOngoing);

                                cout << "--------------Purchase Order (PO) List Report--------------" << endl;
                                cout << "Date Report Generated: " << ltm->tm_mday << "/"
                                     << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
                                cout << "Time Report Generated: " << ltm->tm_hour << ":"
                                     << ltm->tm_min << ":" << ltm->tm_sec << endl;
                                cout << "Requested By User: " << ull.getUsername(cache_id) << endl << endl;

                                //Second Section - Purchase Order Details
                                cout << "----------------------------------------------------------" << endl;
                                cout << "Total Number of PO Made: " << p << endl;
                                cout << "Total Quantity of Items Sold: " << totalQuantity << endl;
                                cout << "Total Number of Processed PO: " << totalProcessed << endl;
                                cout << "Total Number of Ongoing PO: " << totalOngoing << endl;
                                cout << "Total Revenue Made: " << totalRevenue << endl;
                                cout << "----------------------------------------------------------" << endl;

                                cout << endl << "(Auto-Generated by ABCD POMS)" << endl << endl;

                                break;
                            case 3: //User List Report

                                //Get User Types
                                role = ull.getUserType();
                                separatorPos = role.find(":");
                                f_totalAdmin = role.substr(0, separatorPos);
                                f_totalSoe = role.substr(separatorPos+1, role.length());
                                totalAdmin = stoi(f_totalAdmin);
                                totalSoe = stoi(f_totalSoe);

                                cout << "--------------------User List Report---------------------" << endl;
                                cout << "Date Report Generated: " << ltm->tm_mday << "/"
                                     << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
                                cout << "Time Report Generated: " << ltm->tm_hour << ":"
                                     << ltm->tm_min << ":" << ltm->tm_sec << endl;
                                cout << "Requested By User: " << ull.getUsername(cache_id) << endl << endl;

                                //Second Section - Purchase Order Details
                                cout << "----------------------------------------------------------" << endl;
                                cout << "Total Number of Users: " << p << endl;
                                cout << "Total Number of SoE: " << totalSoe << endl;
                                cout << "Total Number of Admin: " << totalAdmin << endl;
                                cout << "----------------------------------------------------------" << endl;

                                cout << endl << "(Auto-Generated by ABCD POMS)" << endl << endl;

                                break;
                        }
                    }

                    break;
                case 7: //Settings
                    while(true) {
                        menu.settingsMenu();

                        cout << "Your Input:";
                        cin >> settings_opt;
                        cout << endl;

                        while(cin.fail()) {
                            cout << "Your Input:";
                            cout << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> settings_opt;
                        }

                        if (settings_opt == 4) {
                            break;
                        }

                        switch(settings_opt) {
                            case 1: //My Information
                                ull.showSelfInfo(cache_id);

                                break;
                            case 2: //Change My Password
                                cout << "------Change My Password------" << endl;

                                //Get User ID
                                user_id_input = cache_id;

                                //Get User's New Password
                                cout << "Input New Password:";
                                getline(cin >> ws, password_input);

                                while(cin.fail()) {
                                    cout << "Input New Password:";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    getline(cin >> ws, password_input);
                                }

                                ull.updateUserPassword(user_id_input, password_input);

                                break;
                            case 3: //Delete My Account
                                user_id_input = cache_id;

                                ull.deleteUser(user_id_input);
                                ull.rearrangeUserID();

                                break;
                            default:
                                break;
                        }
                        break;
                    }

                    break;
                default:
                    break;
            }

            if (settings_opt == 3) {
                break;
            }

        }

    } else {
        cout << endl;
        cout << "Login Failed, Please Try Again!" << endl << endl;
    }
}

#endif //ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H
