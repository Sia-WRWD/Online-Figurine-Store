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
        string contact_no[5] = {"011-1234-1234", "012-2345-2345", "017-3456-3456",
                                "019-5678-5678", "011-6789-6789"};

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
        cout << client_id << " " << client_name << " " << client_address << " " << contact_no << endl;
    }
    void searchClient(int id) {
        if (client_size > 0) {
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
            cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
        }
    }
    //Search---------------------------------------------------------------------------


    //Update---------------------------------------------------------------------------

    //Delete---------------------------------------------------------------------------

    //Sort---------------------------------------------------------------------------


};



#endif //ONLINE_FIGURINE_STORE_STORE_CLIENT_H
