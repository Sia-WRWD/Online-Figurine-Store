//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_ITEM_H
#define ONLINE_FIGURINE_STORE_STORE_ITEM_H

#include <iostream>
#include <iomanip>

struct Item {
    int item_id;
    string item_name;
    string unit_price;
    Item * next;
};

struct ItemLinkedList {
    Item * head;
    int item_size;

    ItemLinkedList() {
        this->item_size = 0;
        this->head = nullptr;
    }

    // Insertion---------------------------------------------------------------------------
    void insertItemAtBeginning(int id, string name, string unit_price) {
        Item * newItem = new Item;
        newItem->item_id = id;
        newItem->item_name = name;
        newItem->unit_price = unit_price;
        newItem->next = head;
        head = newItem;
        item_size++;
    }

    void insertItemAtEnd(int id, string name, string unit_price) {
        Item * newItem = new Item;
        newItem->item_id = id;
        newItem->item_name = name;
        newItem->unit_price = unit_price;
        newItem->next = nullptr;
        if ( head == nullptr ) {
            head = newItem;
        } else {
            Item * last = head;
            while( last->next != nullptr )
                last = last->next;
            last->next = newItem;
        }
        item_size++;
    }

    void InitItemData() {
        int id[5] = {1, 2, 3, 4, 5};
        string name[5] = {"Dota Figurine", "LoL Figurine", "Robot Figurine", "Chibi Figurine",
                          "Anime Figurine"};
        string unit_price[5] = {"RM5.00", "RM3.00", "RM10.00", "RM6.00", "RM20.55"};

        for (int i = 0; i < 5; i++) {
            insertItemAtEnd(id[i], name[i], unit_price[i]);
        }

//        showItemDetails();
    }

    int getSize() {
        return item_size;
    }

    //Display---------------------------------------------------------------------------
    void showItemDetails() {
        Item * curr = head;
        cout << "List of Items (Total Number of Items: " << item_size << "):" << endl;
        cout << "ID" << "Name" << "Unit Price"  << endl;
        while (curr != nullptr) {
            cout << curr->item_id << " " << curr->item_name << " " << curr->unit_price << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayItemSearchResult(int item_id, string item_name, string unit_price) {
        cout << "ID" << "Name" << "Address" << "Contact No" << endl;
        cout << item_id << " " << item_name << " " << unit_price << endl;
    }

    //Search---------------------------------------------------------------------------
    void searchItem(int id) {
        if (id <= item_size && id > 0) {
            Item * curr = head;
            int totalResults = 0;

            while( curr != nullptr ) {
                if (curr->item_id == id) {
                    displayItemSearchResult(curr->item_id, curr->item_name,
                                              curr->unit_price);
                    totalResults++;
                    curr = curr->next;
                } else {
                    curr = curr->next;
                }
            }
            cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
        }
    }

    string getItemPrice(int id) {
        string price;

        if (id <= item_size && id > 0) {
            Item * curr = head;

            while( curr != nullptr ) {
                if (curr->item_id == id) {
                    price = curr->unit_price;
                    break;
                } else {
                    curr = curr->next;
                }
            }
        }

        return price;
    }

    //Update---------------------------------------------------------------------------
    void updateItemName(int id, string name) {
        if (id <= item_size && id > 0) {
            Item * curr = head;
            while(curr != nullptr) {
                if (curr->item_id == id) {
                    curr->item_name = name;

                    cout << "Successfully Updated Item Name." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updateItemPrice(int id, string price) {
        if (id <= item_size && id > 0) {
            Item * curr = head;
            while(curr != nullptr) {
                if (curr->item_id == id) {
                    curr->unit_price = price;

                    cout << "Successfully Updated Item Price." << endl << endl;

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

};

#endif //ONLINE_FIGURINE_STORE_STORE_ITEM_H

