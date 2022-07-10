//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_PO_H
#define ONLINE_FIGURINE_STORE_STORE_PO_H

#include <iostream>
#include <iomanip>
#include <cmath>

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

struct PurchaseOrderLinkedList {
    PurchaseOrder * head;
    int po_size;

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
        string date[5] = {"10/12/2023", "11/07/2025", "12/08/2022", "13/10/2022",
                          "14/11/2024"};
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

    void showPOListAsc(PurchaseOrder * n)
    {
        while (n != nullptr) {
            cout << n->po_id << " " << n->date << " " << n->client_id << " " << n->item_id <<
                 " " << n->quantity << " " << n->po_total << " " << n->delivery_status << endl;
            n = n->next;
        }
    }

    void showPOListDsc(PurchaseOrder * n) { //geeksforgeeks, 2022
        if(n == nullptr) {
            return;
        }

        showPOListDsc(n->next);

        cout << n->po_id << " " << n->date << " " << n->client_id << " " << n->item_id <<
             " " << n->quantity << " " << n->po_total << " " << n->delivery_status << endl;
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

    float getTotalRevenue() {
        string total_input;
        float f_total_input = 0, temp_total_input = 0;

        PurchaseOrder * curr = head;
        while(curr != nullptr) { //Get All PO_Total and Add them up.
            total_input = curr->po_total.substr(2, curr->po_total.length());
            temp_total_input = stof(total_input);
            f_total_input += temp_total_input;
            curr = curr->next;
        }

        //Convert Revenue back to RM format.
        f_total_input = floor(f_total_input * 100) / 100;

        return f_total_input;
    }

    int getTotalQty() {
        int total_qty = 0, temp_total_qty = 0;

        PurchaseOrder * curr = head;
        while(curr != nullptr) { //Get All PO_Total and Add them up.
            temp_total_qty = curr->quantity;
            total_qty += temp_total_qty;
            curr = curr->next;
        }

        return total_qty;
    }

    string getDeliveryStatus () {
        int processed = 0, ongoing = 0;
        string ratio;

        PurchaseOrder * curr = head;
        while(curr != nullptr) { //Get All PO_Total and Add them up.
            if (curr->delivery_status == "Processed") {
                processed++;
                curr = curr->next;
            } else {
                ongoing ++;
                curr = curr->next;
            }
        }

        ratio = to_string(processed) + ":" + to_string(ongoing);

        return ratio;
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
    void deletePOAtBeginning() {
        if(po_size > 0) {
            PurchaseOrder * toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            po_size--;
        }
    }

    void deletePurchaseOrder(int id) {
        if(id <= po_size && id > 0) {
            PurchaseOrder * prev = head, * toDelete = head;
            while( toDelete != nullptr ) {
                if (toDelete->po_id == id) {
                    if (toDelete == head) {
                        deletePOAtBeginning();

                        cout << "Successfully Deleted Purchase Order #" << id << "!" << endl << endl;

                        break;
                    } else {
                        prev->next = toDelete->next;
                        delete toDelete;
                        po_size--;

                        cout << "Successfully Deleted Purchase Order #" << id << "!" << endl << endl;

                        break;
                    }
                } else {
                    prev = toDelete;
                    toDelete = toDelete->next;
                }
            }
        } else {
            cout << "Purchase Order with the ID: #" << id << " cannot be found!" << endl << endl;
        }
    }

    void rearrangePOID() {
        PurchaseOrder * curr = head;
        int new_id = 0;

        while(curr != nullptr) {
            curr->po_id = new_id + 1;
            curr = curr->next;

            new_id++;
        }
    }

    //Sort---------------------------------------------------------------------------
    void sortPOID() { //Sort Based on PO ID.
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->po_id > index->po_id ) //Sort Ascending Order
                    {
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortPOClientID() { //Sort Based on Client ID.
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

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
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortPOItemID() { //Sort Based on Item ID.
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

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
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortPODate() {
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

        int separator_pos;
        string s_day1, s_month1, s_year1, s_day2, s_month2, s_year2;
        int f_day1, f_month1, f_year1, f_day2, f_month2, f_year2;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                s_day1 = curr->date.substr(0, 2);
                s_month1 = curr->date.substr(3, 2);
                s_year1 = curr->date.substr(6, curr->date.length());

                f_day1 = stoi(s_day1);
                f_month1 = stoi(s_month1);
                f_year1 = stoi(s_year1);

                index = curr->next;
                while( index != nullptr )
                {
                    s_day2 = index->date.substr(0, 2);
                    s_month2 = index->date.substr(3, 2);
                    s_year2 = index->date.substr(6, index->date.length());

                    f_day2 = stoi(s_day2);
                    f_month2 = stoi(s_month2);
                    f_year2 = stoi(s_year2);

                    if (f_year1 < f_year2 || (f_year1 == f_year2 && f_month1 < f_month2)
                        || (f_year1 == f_year2 && f_month1 == f_month2 && f_day1 < f_day2)) //Sort Ascending Order
                    {
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortPOQty() { //Sort PO based on their Quantity.
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->quantity > index->quantity ) //Sort Ascending Order
                    {
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortPOTotal() { //Sort PO based on their Total.
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

        int RM_pos;
        string s_total_price1, s_total_price2;
        float f_total_price1, f_total_price2;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                RM_pos = curr->po_total.find("RM");
                s_total_price1 = curr->po_total.substr(RM_pos+2, curr->po_total.length());
                f_total_price1 = stof(s_total_price1);

                index = curr->next;
                while( index != nullptr )
                {
                    RM_pos = index->po_total.find("RM");
                    s_total_price2 = index->po_total.substr(RM_pos+2, index->po_total.length());
                    f_total_price2 = stof(s_total_price2);

                    if( f_total_price1 > f_total_price2 ) //Sort Ascending Order
                    {
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

    void sortPODeliveryStatus() { //Sort PO based on their Delivery Status.
        PurchaseOrder * curr = head, * index = nullptr;

        int temp_po_id;
        string temp_date;
        int temp_client_id;
        int temp_item_id;
        int temp_quantity;
        string temp_po_total;
        string temp_delivery_status;

        if ( head == nullptr ) {
            return;
        } else {
            while( curr != nullptr )
            {
                index = curr->next;
                while( index != nullptr )
                {
                    if( curr->delivery_status > index->delivery_status ) //Sort Ascending Order
                    {
                        temp_po_id = curr->po_id;
                        temp_date = curr->date;
                        temp_client_id = curr->client_id;
                        temp_item_id = curr->item_id;
                        temp_quantity = curr->quantity;
                        temp_po_total = curr->po_total;
                        temp_delivery_status = curr->delivery_status;

                        curr->po_id = index->po_id;
                        curr->date = index->date;
                        curr->client_id = index->client_id;
                        curr->item_id = index->item_id;
                        curr->quantity = index->quantity;
                        curr->po_total = index->po_total;
                        curr->delivery_status = index->delivery_status;

                        index->po_id = temp_po_id;
                        index->date = temp_date;
                        index->client_id = temp_client_id;
                        index->item_id = temp_item_id;
                        index->quantity = temp_quantity;
                        index->po_total = temp_po_total;
                        index->delivery_status = temp_delivery_status;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
    }

};

#endif //ONLINE_FIGURINE_STORE_STORE_PO_H
