//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_USER_H
#define ONLINE_FIGURINE_STORE_STORE_USER_H

#include <iostream>
#include "store_namespacer.h"

using namespace std;

store_namespacer ns;

struct User {
    int id;
    string username, password, role;
    User * next;
};

struct UserLinkedList {

    User * head;
    int user_size;

    UserLinkedList() {
        this->user_size = 0;
        this->head = nullptr;
    }

    // Insertion---------------------------------------------------------------------------
    void insertUserAtBeginning(int id, string username, string password, string role) {
        User * newUser = new User;
        newUser->id = id;
        newUser->username = username;
        newUser->password = password;
        newUser->role = role;
        newUser->next = head;
        head = newUser;
        user_size++;
    }

    void insertUserAtEnd(int id, string username, string password, string role) {
        User * newUser = new User;
        newUser->id = id;
        newUser->username = username;
        newUser->password = password;
        newUser->role = role;
        newUser->next = nullptr;
        if ( head == nullptr ) {
            head = newUser;
        } else {
            User * last = head;
            while( last->next != nullptr )
                last = last->next;
            last->next = newUser;
        }
        user_size++;
    }

    void InitUserData() {
        int id[5] = {1, 2, 3, 4, 5};
        string username[5] = {"jcn", "JoPepega", "ir4un", "Nut-Case", "lmao-xd"};
        string password[5] = {"123", "123", "123", "123", "123"};
        string role[5] = {"Admin", "SoE", "Admin", "SoE", "SoE"};

        for (int i = 0; i < 5; i++) {
            insertUserAtEnd(id[i], username[i], password[i], role[i]);
        }

//        ull.showUserDetails();
    }

    int getSize() {
        return user_size;
    }

    //Display---------------------------------------------------------------------------
    void showUserDetails() {
        User * curr = head;
        cout << "List of Users (Total Number of Users: " << user_size << "):" << endl;
        cout << "ID" << "Username" << "Password" << "Role" << endl;
        while (curr != nullptr) {
            cout << curr->id << " " << curr->username << " " << curr->password << " " << curr->role << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayUserDetails(int id, string username, string password, string role) {
        cout << "ID" << "Username" << "Password" << "Role" << endl;
        cout << id << " " << username << " " << password << " " << role << endl;
    }

    //Search---------------------------------------------------------------------------
    bool verifyLogin(string username, string password, string role) {
        User * curr = head;
        while(curr != nullptr) {
            if(curr->username == username && curr->password == password && curr->role == role) {
                return true;
            } else {
                curr = curr->next;
            }
        }
        return false;
    }

    void searchUser (int id) {
        if (id <= user_size || id > 0) {
            User * curr = head;
            int totalResults = 0;

            while( curr != nullptr ) {
                if (curr->id == id) {
                    displayUserDetails(curr->id, curr->username, curr->password,
                                       curr->role);
                    totalResults++;
                    curr = curr->next;
                } else {
                    curr = curr->next;
                }
            }
            cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
        }
    }

    string getRoleBasedID(int id) {
        if (id <= user_size || id > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->id == id) {
                    return curr->role;
                } else {
                    curr = curr->next;
                }
            }
            return "User Don't Exist!";
        }
    }

    bool checkUsernameExist(string username, string role) {
        bool usernameExist = false;

        if (user_size > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->username == username && curr->role == role) {
                    usernameExist = true;
                    return usernameExist;
                } else {
                    curr = curr->next;
                }
            }
            usernameExist = false;
            return usernameExist;
        }
    }

    //Update---------------------------------------------------------------------------
    void updateUserUsername(int id, string username) {
        if (id <= user_size && id > 0) {
            User * curr = head;
            while(curr != nullptr) {
                if (curr->id == id) {
                    curr->username = username;

                    cout << "Successfully Updated Username." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updateUserPassword(int id, string password) {
        if (id <= user_size && id > 0) {
            User * curr = head;
            while(curr != nullptr) {
                if (curr->id == id) {
                    curr->password = password;

                    cout << "Successfully Updated Password." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updateUserRole(int id, string role) {
        if (id <= user_size && id > 0) {
            User * curr = head;
            while(curr != nullptr) {
                if (curr->id == id) {
                    curr->role = role;

                    cout << "Successfully Updated Role." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    //Delete---------------------------------------------------------------------------

    //Sort---------------------------------------------------------------------------
    void sortBasedUserID() {
        //Sort Based on User's ID.
    }
};

#endif //ONLINE_FIGURINE_STORE_STORE_USER_H
