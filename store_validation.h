//
// Created by chinojen7 on 4/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_VALIDATION_H
#define ONLINE_FIGURINE_STORE_STORE_VALIDATION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Validation {
    private:

    public:
    bool checkDate(int day, int month, int year) { //Prowl, 2013
        const int lookup_table[12] = {31,29,31,30,31,30,
                                      31,31,30,31,30,31};
        if (!(month >= 1 && month <= 12)) {
            return false;
        }
        if (!(day >= 1 && day <= lookup_table[month-1])) {
            return false;
        }
        if (!(year >= 1900)) {
            return false;
        }
        return true;
    }

    string formatDate(int day, int month, int year) { //Nawaz, 2013
        string s_day, s_month, s_year, f_date;

        stringstream ss;

        ss << setfill('0') << setw(2) << day << setw(2) << month << year;
        ss >> s_day >> s_month >> s_year;

        f_date = s_day + s_month + s_year;

        return f_date;
    }

    bool checkContactFormat(string number) { //jpanther, 2015
        bool validNumber = false;

        if (number.length() != 12) {
            validNumber = false;
            return validNumber;
        }

        for(int i = 0; i < number.length(); i++) {
            if (i == 3 && number[i] != '-') {
                validNumber = false;
                return validNumber;
            } else {
                validNumber = true;
            }
        }
        return validNumber;
    }

    string checkFormatPrice(string price) {

        int dotPos = price.find("."); //Find dot in Price.
        bool gotDot = false; //Bool to determine if got dot.
        string new_price_format;
        string trailingNums;

        if (dotPos == -1) { //No Dot.
            gotDot = false;
            trailingNums = "";
        } else { //Got Dot.
            gotDot = true;
            trailingNums = price.substr(dotPos+1, price.length()); //Find for the total trailing nums after dots.
        }

        if (gotDot && trailingNums.length() == 2) { //Got Dot && Total Trailing Nums = 2
            new_price_format = "RM" + price;
        } else if (gotDot && trailingNums.length() == 1) { //Got Dot && Total Trailing Nums = 1
            new_price_format = "RM" + price + "0";
        } else if (!gotDot && trailingNums.length() == 0){ //No Dot && Total Trailing Nums = 0
            new_price_format = "RM" + price + ".00";
        }
        return new_price_format;
    }
};

#endif //ONLINE_FIGURINE_STORE_STORE_VALIDATION_H
