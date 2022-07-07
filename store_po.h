//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_PO_H
#define ONLINE_FIGURINE_STORE_STORE_PO_H

#include <iostream>
#include <iomanip>
#include "store_controller.h"

struct PurchaseOrder {
    int po_id;
    string date;
    int client_id;
    int item_id;
    int quantity;
    string po_total;
    string delivery_status;
    PurchaseOrder * next;
};

class PurchaseOrderLinkedList {
    private:
    PurchaseOrder * head;
    int po_size;

    public:
    PurchaseOrderLinkedList() {
        this->po_size = 0;
        this->head = nullptr;
    }

    //Insertion---------------------------------------------------------------------------
    void insertPOAtBeginning(int po_id, string date, int client_id, int item_id, int quantity,
                             string po_total, string delivery_status) {
        PurchaseOrder * newPO = new PurchaseOrder;
        newPO->po_id = po_id;
        newPO->date = date;
        newPO->client_id = client_id;
        newPO->item_id = item_id;
        newPO->quantity = quantity;
        newPO->po_total = po_total;
        newPO->delivery_status = delivery_status;
        newPO->next = head;
        head = newPO;
        po_size++;
    }

    void insertPOAtEnd(int po_id, string date, int client_id, int item_id, int quantity,
                       string po_total, string delivery_status) {
        PurchaseOrder * newPO = new PurchaseOrder;
        newPO->po_id = po_id;
        newPO->date = date;
        newPO->client_id = client_id;
        newPO->item_id = item_id;
        newPO->quantity = quantity;
        newPO->po_total = po_total;
        newPO->delivery_status = delivery_status;
        newPO->next = nullptr;
        if ( head == nullptr ) {
            head = newPO;
        } else {
            PurchaseOrder * last = head;
            while( last->next != nullptr )
                last = last->next;
            last->next = newPO;
        }
        po_size++;
    }

    void InitPurchaseOrdersData() {
        int po_id[5] = {1, 2, 3, 4, 5};
        string date[5] = {"10/06/2022", "11/06/2022", "12/06/2022", "13/06/2022",
                          "14/06/2022"};
        int client_id[5] = {5, 4, 2, 3, 1};
        int item_id[5] = {3, 2, 5, 4, 1};
        int quantity[5] = {2, 5, 2, 5, 2};
        string po_total[5] = {"RM20.00", "RM15.00", "RM41.10", "RM30.00", "RM10.00"};
        string delivery_status[5] = {"Processed", "Ongoing", "Processed", "Processed",
                                     "Ongoing"};

        for (int i = 0; i < 5; i++) {
            insertPOAtEnd(po_id[i], date[i], client_id[i], item_id[i],
                          quantity[i],po_total[i], delivery_status[i]);
        }

//        poll.showPODetails();
    }

    int getSize() {
        return po_size;
    }

    //Display---------------------------------------------------------------------------
    void showPODetails() {
        PurchaseOrder * curr = head;
        cout << "List of Purchase Orders (Total Number of POs: " << po_size << "):" << endl;
        cout << "POID" << " " << "Date" << " " << "Client ID" << " " << "Item ID" << " " << "Qty"
             << " " << "Total" << " "  << "Delivery Status" << endl;
        while (curr != nullptr) {
            cout << curr->po_id << " " << curr->date << " " << curr->client_id << " " << curr->item_id <<
                 " " << curr->quantity << " " << curr->po_total << " " << curr->delivery_status << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void displayPOSearchResult(int id, string date, int client_id, int item_id, int quantity, string po_total,
                             string delivery_status) {
        cout << "POID" << " " << "Date" << " " << "Client ID" << " " << "Item ID" << " " << "Qty"
             << " " << "Total" << " "  << "Delivery Status" << endl;
        cout << id << " " << date << " " << client_id << " " << item_id << " " << quantity << " "
             << po_total << " " << delivery_status << endl << endl;
    }

    //Search---------------------------------------------------------------------------
    void searchPurchaseOrder(int id) {
        if (id <= po_size && id > 0) {
            PurchaseOrder * curr = head;
            int totalResults = 0;

            while( curr != nullptr ) {
                if (curr->po_id == id) {
                    displayPOSearchResult(curr->po_id, curr->date, curr->client_id,
                                        curr->item_id, curr->quantity,curr->po_total,
                                        curr->delivery_status);
                    totalResults++;
                    curr = curr->next;
                } else {
                    curr = curr->next;
                }
            }

            if (totalResults == 0) {
                cout << "No Data with the PO_ID: #" << id << "is found!" << endl << endl;
            } else {
                cout << "(Total Results Found: " << totalResults << ")" << endl << endl;
            }
        }
    }

    void searchUpdatedPO(int id) {
        if (id <= po_size && id > 0) {
            PurchaseOrder * curr = head;

            while( curr != nullptr ) {
                if (curr->po_id == id) {
                    cout << "------Updated Purchase Order #" << id << "------" << endl;
                    displayPOSearchResult(curr->po_id, curr->date, curr->client_id,
                                        curr->item_id, curr->quantity,curr->po_total,
                                        curr->delivery_status);
                    break;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    int searchItemID(int id) {
        if(id <= po_size && id > 0) {
            PurchaseOrder * curr = head;

            while(curr != nullptr) {
                if (curr->po_id == id) {
                    return curr->item_id;
                } else {
                    curr = curr->next;
                }
            }
        }
    }

    //Update---------------------------------------------------------------------------
    void updatePODate(int id, string Date) {
        if (id <= po_size && id > 0) {
            PurchaseOrder * curr = head;
            while(curr != nullptr) {
                if (curr->po_id == id) {
                    curr->date = Date;

                    cout << "Successfully Updated Date." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updatePOQty(int id, int quantity, string total) {
        if (id <= po_size && id > 0) {
            PurchaseOrder * curr = head;
            while(curr != nullptr) {
                if (curr->po_id == id) {
                    curr->quantity = quantity;
                    curr->po_total = total;

                    cout << "Successfully Updated Quantity." << endl << endl;

                    return;
                } else {
                    curr = curr->next;
                }
            }
        } else {
            cout << "Error: ID is Out of Bounds!" << endl;
        }
    }

    void updatePODeliStatus(int id, string delivery_status) {
        if (id <= po_size && id > 0) {
            PurchaseOrder * curr = head;
            while(curr != nullptr) {
                if (curr->po_id == id) {
                    curr->delivery_status = delivery_status;

                    cout << "Successfully Updated Delivery Status." << endl << endl;

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

    //Validation---------------------------------------------------------------------------

};

#endif //ONLINE_FIGURINE_STORE_STORE_PO_H
