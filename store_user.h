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
        cout << "ID" << " " << "Username" << " "  << "Password" << " " << "Role" << endl;
        while (curr != nullptr) {
            cout << curr->id << " " << curr->username << " " << curr->password << " " << curr->role << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayUserDetails(int id, string username, string password, string role) {
        cout << "List of Users (Total Number of Users: " << user_size << "):" << endl;
        cout << "ID" << "Username" << "Password" << "Role" << endl;
        cout << id << " " << username << " " << password << " " << role << endl << endl;
    }

    void showUpdatedUser(int id) {
        if (id <= user_size && id > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->id == id) {
                    cout << "------Updated User #" << id << "------" << endl;
                    displayUserDetails(curr->id, curr->username, curr->password,
                                       curr->role);
                    break;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    void showSelfInfo(int id) {
        if (id <= user_size && id > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->id == id) {
                    cout << "------My Information------" << endl;
                    cout << "My ID: " << curr->id  << endl;
                    cout << "My Username: " << curr->username << endl;
                    cout << "My Role: " << curr->role << endl;

                    break;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    void showUserListAsc(User * n)
    {
        while (n != nullptr) {
            cout << n->id << " " << n->username << " " << n->password << " " << n->role << endl;
            n = n->next;
        }
    }

    void showUserListDsc(User * n) { //geeksforgeeks, 2022
        if(n == nullptr) {
            return;
        }

        showUserListDsc(n->next);

        cout << n->id << " " << n->username << " " << n->password << " " << n->role << endl;
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

            if (totalResults == 0) {
                cout << "No Data with the User ID: #" << id << "is found!" << endl << endl;
            } else {
                cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
            }
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

    bool checkUsernameExist(int id, string username, string role) {
        bool usernameExist = false;

        if (user_size > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->username == username && curr->role == role && curr->id != id) {
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

    string getUsername(int id) {
        if (id <= user_size || id > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->id == id) {
                    return curr->username;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            return "User Don't Exist!";
        }
    }

    int getID(string username) {
        if (user_size > 0) {
            User * curr = head;

            while( curr != nullptr ) {
                if (curr->username == username) {
                    return curr->id;
                } else {
                    curr = curr->next;
                }
            }
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
    void deleteUserAtBeginning() {
        if(user_size > 0) {
            User * toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            user_size--;
        }
    }

    void deleteUser(int id) {
        if(id <= user_size && id > 0) {
            User * prev = head, * toDelete = head;
            while( toDelete != nullptr ) {
                if (toDelete->id == id) {
                    if (toDelete == head) {
                        deleteUserAtBeginning();

                        cout << "Successfully Deleted User #" << id << "!" << endl << endl;

                        break;
                    } else {
                        prev->next = toDelete->next;
                        delete toDelete;
                        user_size--;

                        cout << "Successfully Deleted User #" << id << "!" << endl << endl;

                        break;
                    }
                } else {
                    prev = toDelete;
                    toDelete = toDelete->next;
                }
            }
        } else {
            cout << "User with the ID: #" << id << " cannot be found!" << endl << endl;
        }
    }

    void rearrangeUserID() {
        User * curr = head;
        int new_id = 0;

        while(curr != nullptr) {
            curr->id = new_id + 1;
            curr = curr->next;

            new_id++;
        }
    }

    //Sort---------------------------------------------------------------------------
    void sortUserID() {
        User * curr = head, * index = nullptr;

        int tempID;
        string tempUsername, tempPassword, tempRole;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->id > index->id ) //Sort Ascending Order
                    {
                        tempID = curr->id;
                        tempUsername = curr->username;
                        tempPassword = curr->password;
                        tempRole = curr->role;

                        curr->id = index->id;
                        curr->username = index->username;
                        curr->password = index->password;
                        curr->role = index->role;

                        index->id = tempID;
                        index->username = tempUsername;
                        index->password = tempPassword;
                        index->role = tempRole;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortRole() //Sort User based on their Roles.
    {
        User * curr = head, * index = nullptr;

        int tempID;
        string tempUsername, tempPassword, tempRole;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->role > index->role ) //Sort Ascending Order
                    {
                        tempID = curr->id;
                        tempUsername = curr->username;
                        tempPassword = curr->password;
                        tempRole = curr->role;

                        curr->id = index->id;
                        curr->username = index->username;
                        curr->password = index->password;
                        curr->role = index->role;

                        index->id = tempID;
                        index->username = tempUsername;
                        index->password = tempPassword;
                        index->role = tempRole;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

};

#endif //ONLINE_FIGURINE_STORE_STORE_USER_H
