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

#include "bits/stdc++.h"

using namespace std;

UserLinkedList ull;
PurchaseOrderLinkedList poll;

void runSoe() {
    string SoeUsername, SoePassword, SoeRole = "SoE";
    int main_input;

    cout << "Please Provide Your Login Information:" << endl;
    cout << "Username:";
    cin >> SoeUsername;
    cout << "Password:";
    cin >> SoePassword;

    ull.showUserDetails();

    bool verificationStatus = ull.verifyLogin(SoeUsername, SoePassword, SoeRole);

    if (verificationStatus == true) {
        while(true) {
            cout << endl;
            cout << "----Welcome Back, " << SoeUsername << "!----" << endl;
            cout << "Your Input:";
            cin >> main_input;

            if (main_input == 7) {
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
    int main_input;

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
            cout << "Your Input:";
            cin >> main_input;

            if (main_input == 7) {
                break;
            }
        }

    } else {
        cout << endl;
        cout << "Login Failed, Please Try Again!" << endl << endl;
    }
}

#endif //ONLINE_FIGURINE_STORE_STORE_CONTROLLER_H
