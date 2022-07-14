//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_CLIENT_H
#define ONLINE_FIGURINE_STORE_STORE_CLIENT_H

#include <iostream>
#include <iomanip>

#include "store_namespacer.h"

struct Client {
    int client_id;
    string client_name;
    string client_address;
    string contact_no;
    Client * next;
};

struct ClientLinkedList {
    Client * head;
    int client_size;

    ClientLinkedList() {
        this->client_size = 0;
        this->head = nullptr;
    }

    // Insertion---------------------------------------------------------------------------
    void insertClientAtBeginning(int id, string name, string address, string contact_no) {
        Client * newClient = new Client;
        newClient->client_id = id;
        newClient->client_name = name;
        newClient->client_address = address;
        newClient->contact_no = contact_no;
        newClient->next = head;
        head = newClient;
        client_size++;
    }

    void insertClientAtEnd(int id, string name, string address, string contact_no) {
        Client * newClient = new Client;
        newClient->client_id = id;
        newClient->client_name = name;
        newClient->client_address = address;
        newClient->contact_no = contact_no;
        newClient->next = nullptr;
        if ( head == nullptr ) {
            head = newClient;
        } else {
            Client * last = head;
            while( last->next != nullptr )
                last = last->next;
            last->next = newClient;
        }
        client_size++;
    }

    void InitClientData() {
        int id[5] = {1, 2, 3, 4, 5};
        string name[5] = {"Fuad Hall", "Jack Paul", "KeK Saul", "Jesus", "Christ"};
        string address[5] = {"22 Seri Ampang, KL", "23 Seri Bahagia, KL", "24 Seri Cerah, KL",
                             "25 Seri Dekat, KL", "26 Seri Jauh, KL"};
        string contact_no[5] = {"011-12341234", "012-23452345", "017-34563456",
                                "019-56785678", "011-67896789"};

        for (int i = 0; i < 5; i++) {
            insertClientAtEnd(id[i], name[i], address[i], contact_no[i]);
        }

//        showClientDetails();
    }

    int getSize() {
        return client_size;
    }

    //Display---------------------------------------------------------------------------
    void showClientDetails() {
        Client * curr = head;
        cout << "List of Users (Total Number of Client: " << client_size << "):" << endl;
        cout << "ID" << sn.spacePrinter(6, 2)
            << "Name" << sn.spacePrinter(15, 4)
            << "Address" << sn.spacePrinter(35, 7)
            << "Contact No" << endl;
        cout << sn.headerUnderline(6 + 15 + 35 + 10) << endl; // number of dashes

        while (curr != nullptr) {
            cout << curr->client_id << sn.spacePrinter(6, to_string(curr->client_id).size())
                << curr->client_name << sn.spacePrinter(15, curr->client_name.size())
                << curr->client_address << sn.spacePrinter(35, curr->client_address.size())
                << curr->contact_no << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayClientSearchResult(int client_id, string client_name, string client_address,
                                   string contact_no) {
        cout << "List of Users (Total Number of Client: " << client_size << "):" << endl;
        cout << "ID" << sn.spacePrinter(6, 2)
             << "Name" << sn.spacePrinter(15, 4)
             << "Address" << sn.spacePrinter(35, 7)
             << "Contact No" << endl;
        cout << sn.headerUnderline(6 + 15 + 35 + 10) << endl; // number of dashes

        cout << client_id << sn.spacePrinter(6, to_string(client_id).size())
             << client_name << sn.spacePrinter(15, client_name.size())
             << client_address << sn.spacePrinter(35, client_address.size())
             << contact_no << endl << endl;
    }

    void showUpdatedClient(int id) {
        if (id <= client_size && id > 0) {
            Client * curr = head;

            while( curr != nullptr ) {
                if (curr->client_id == id) {
                    cout << "------Updated Client #" << id << "------" << endl;
                    displayClientSearchResult(curr->client_id, curr->client_name,
                                              curr->client_address, curr->contact_no);
                    break;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    void showClientListAsc(Client * n)
    {
        cout << "List of Users (Total Number of Client: " << client_size << "):" << endl;
        cout << "ID" << sn.spacePrinter(6, 2)
             << "Name" << sn.spacePrinter(15, 4)
             << "Address" << sn.spacePrinter(35, 7)
             << "Contact No" << endl;
        cout << sn.headerUnderline(6 + 15 + 35 + 10) << endl; // number of dashes
        
        while (n != nullptr) {
            cout << n->client_id << sn.spacePrinter(6, to_string(n->client_id).size())
                 << n->client_name << sn.spacePrinter(15, n->client_name.size())
                 << n->client_address << sn.spacePrinter(35, n->client_address.size())
                 << n->contact_no << endl;
            n = n->next;
        }
    }

    void showClientListDsc(Client * n) { //geeksforgeeks, 2022
        if(n == nullptr) {
            return;
        }

        showClientListDsc(n->next);

        cout << n->client_id << sn.spacePrinter(6, to_string(n->client_id).size())
             << n->client_name << sn.spacePrinter(15, n->client_name.size())
             << n->client_address << sn.spacePrinter(35, n->client_address.size())
             << n->contact_no << endl;
    }

    //Search---------------------------------------------------------------------------
    void searchClient(int id) {
        if (id <= client_size && id > 0) {
            Client * curr = head;
            int totalResults = 0;

            while( curr != nullptr ) {
                if (curr->client_id == id) {
                    displayClientSearchResult(curr->client_id, curr->client_name,
                                              curr->client_address, curr->contact_no);
                    totalResults++;
                    curr = curr->next;
                } else {
                    curr = curr->next;
                }
            }
            if (totalResults == 0) {
                cout << "No Data with the Client ID: #" << id << "is found!" << endl << endl;
            } else {
                cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
            }
        }
    }

    //Update---------------------------------------------------------------------------
    void updateClientName(int id, string name) {
        if (id <= client_size && id > 0) {
            Client * curr = head;
            while(curr != nullptr) {
                if (curr->client_id == id) {
                    curr->client_name = name;

                    cout << "Successfully Updated Name." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updateClientAddress(int id, string address) {
        if (id <= client_size && id > 0) {
            Client * curr = head;
            while(curr != nullptr) {
                if (curr->client_id == id) {
                    curr->client_address = address;

                    cout << "Successfully Updated Address." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updateClientContacts(int id, string contact) {
        if (id <= client_size && id > 0) {
            Client * curr = head;
            while(curr != nullptr) {
                if (curr->client_id == id) {
                    curr->contact_no = contact;

                    cout << "Successfully Updated Contact Number." << endl << endl;

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
    void deleteClientAtBeginning() {
        if(client_size > 0) {
            Client * toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            client_size--;
        }
    }

    void deleteClient(int id) {
        if(id <= client_size && id > 0) {
            Client * prev = head, * toDelete = head;
            while( toDelete != nullptr ) {
                if (toDelete->client_id == id) {
                    if (toDelete == head) {
                        deleteClientAtBeginning();

                        cout << "Successfully Deleted Client #" << id << "!" << endl << endl;

                        break;
                    } else {
                        prev->next = toDelete->next;
                        delete toDelete;
                        client_size--;

                        cout << "Successfully Deleted Client #" << id << "!" << endl << endl;

                        break;
                    }
                } else {
                    prev = toDelete;
                    toDelete = toDelete->next;
                }
            }
        } else {
            cout << "Item with the ID: #" << id << " cannot be found!" << endl << endl;
        }
    }

    void rearrangeClientID() {
        Client * curr = head;
        int new_id = 0;

        while(curr != nullptr) {
            curr->client_id = new_id + 1;
            curr = curr->next;

            new_id++;
        }
    }

    //Sort---------------------------------------------------------------------------
    void sortClientID() //Sort User based on their Roles.
    {
        Client * curr = head, * index = nullptr;

        int temp_client_id;
        string temp_client_name;
        string temp_client_address;
        string temp_contact_no;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->client_id > index->client_id ) //Sort Ascending Order
                    {
                        temp_client_id = curr->client_id;
                        temp_client_name = curr->client_name;
                        temp_client_address = curr->client_address;
                        temp_contact_no = curr->contact_no;

                        curr->client_id = index->client_id;
                        curr->client_name = index->client_name;
                        curr->client_address = index->client_address;
                        curr->contact_no = index->contact_no;

                        index->client_id = temp_client_id;
                        index->client_name = temp_client_name;
                        index->client_address = temp_client_address;
                        index->contact_no = temp_contact_no;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }



};



#endif //ONLINE_FIGURINE_STORE_STORE_CLIENT_H
