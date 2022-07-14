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
        cout << "ID" << sn.spacePrinter(6, 2)
            << "Name" << sn.spacePrinter(20, 4)
            << "Unit Price"  << endl;
        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes
        while (curr != nullptr) {
            cout << curr->item_id << sn.spacePrinter(6, to_string(curr->item_id).size())
                << curr->item_name << sn.spacePrinter(20, curr->item_name.size())
                << curr->unit_price << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayItemSearchResult(int item_id, string item_name, string unit_price) {
        cout << "ID" << sn.spacePrinter(6, 4) << "Name" << sn.spacePrinter(20, 4) << "Unit Price" << endl;
        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes
        cout << item_id << sn.spacePrinter(6, to_string(item_id).size())
            << item_name << sn.spacePrinter(20, item_name.size())
            << unit_price << endl << endl;
    }

    void showUpdatedItem(int id) {
        if (id <= item_size && id > 0) {
            Item * curr = head;

            while( curr != nullptr ) {
                if (curr->item_id == id) {
                    cout << "------Updated Item #" << id << "------" << endl;
                    displayItemSearchResult(curr->item_id, curr->item_name,
                                            curr->unit_price);
                    break;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    void showItemListAsc(Item * n)
    {
        cout << "ID" << sn.spacePrinter(6, 2)
             << "Name" << sn.spacePrinter(20, 4)
             << "Unit Price"  << endl;
        cout << sn.headerUnderline(6 + 20 + 11) << endl; // number of dashes

        while (n != nullptr) {
            cout << n->item_id << sn.spacePrinter(6, to_string(n->item_id).size())
                << n->item_name << sn.spacePrinter(20, n->item_name.size())
                << n->unit_price << endl;
            n = n->next;
        }
    }

    void showItemListDsc(Item * n) { //geeksforgeeks, 2022
        if(n == nullptr) {
            return;
        }

        showItemListDsc(n->next);

        cout << n->item_id << sn.spacePrinter(6, to_string(n->item_id).size())
             << n->item_name << sn.spacePrinter(20, n->item_name.size())
             << n->unit_price << endl;
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

            if (totalResults == 0) {
                cout << "No Data with the Item ID: #" << id << "is found!" << endl << endl;
            } else {
                cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
            }
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
    void deleteItemAtBeginning() {
        if(item_size > 0) {
            Item * toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            item_size--;
        }
    }

    void deleteItem(int id) {
        if(id <= item_size && id > 0) {
            Item * prev = head, * toDelete = head;
            while( toDelete != nullptr ) {
                if (toDelete->item_id == id) {
                    if (toDelete == head) {
                        deleteItemAtBeginning();

                        cout << "Successfully Deleted Item #" << id << "!" << endl << endl;

                        break;
                    } else {
                        prev->next = toDelete->next;
                        delete toDelete;
                        item_size--;

                        cout << "Successfully Deleted Item #" << id << "!" << endl << endl;

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

    void rearrangeItemID() {
        Item * curr = head;
        int new_id = 0;

        while(curr != nullptr) {
            curr->item_id = new_id + 1;
            curr = curr->next;

            new_id++;
        }
    }

    //Sort---------------------------------------------------------------------------
    void sortItemID() {
        Item * curr = head, * index = nullptr;

        int tempID;
        string tempName, tempPrice;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->item_id > index->item_id ) //Sort Ascending Order
                    {
                        tempID = curr->item_id;
                        tempName = curr->item_name;
                        tempPrice = curr->unit_price;

                        curr->item_id = index->item_id;
                        curr->item_name = index->item_name;
                        curr->unit_price = index->unit_price;

                        index->item_id = tempID;
                        index->item_name = tempName;
                        index->unit_price = tempPrice;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortUnitPrice()
    {
        Item * curr = head, * index = nullptr;

        int tempID;
        string tempName, tempPrice;
        int RM_pos;
        string s_unit_price1, s_unit_price2;
        float f_unit_price1, f_unit_price2;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                RM_pos = curr->unit_price.find("RM");
                s_unit_price1 = curr->unit_price.substr(RM_pos+2, curr->unit_price.length());
                f_unit_price1 = stof(s_unit_price1);

                index = curr->next;
                while( index != nullptr )
                {
                    RM_pos = index->unit_price.find("RM");
                    s_unit_price2 = index->unit_price.substr(RM_pos+2, index->unit_price.length());
                    f_unit_price2 = stof(s_unit_price2);

                    if( f_unit_price1 > f_unit_price2 ) //Sort Ascending Order
                    {
                        tempID = curr->item_id;
                        tempName = curr->item_name;
                        tempPrice = curr->unit_price;

                        curr->item_id = index->item_id;
                        curr->item_name = index->item_name;
                        curr->unit_price = index->unit_price;

                        index->item_id = tempID;
                        index->item_name = tempName;
                        index->unit_price = tempPrice;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

};

#endif //ONLINE_FIGURINE_STORE_STORE_ITEM_H

