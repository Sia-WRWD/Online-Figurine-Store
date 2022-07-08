//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_CLIENT_H
#define ONLINE_FIGURINE_STORE_STORE_CLIENT_H

#include <iostream>
#include <iomanip>

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
        cout << "ID" << "Name" << "Address" << "Contact No" << endl;
        while (curr != nullptr) {
            cout << curr->client_id << " " << curr->client_name << " " << curr->client_address
                 << " " << curr->contact_no << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayClientSearchResult(int client_id, string client_name, string client_address,
                                   string contact_no) {
        cout << "ID" << "Name" << "Address" << "Contact No" << endl;
        cout << client_id << " " << client_name << " " << client_address << " " << contact_no << endl << endl;
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


};



#endif //ONLINE_FIGURINE_STORE_STORE_CLIENT_H
