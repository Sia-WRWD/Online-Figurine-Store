//
// Created by chinojen7 on 2/7/2022.
//

#ifndef ONLINE_FIGURINE_STORE_STORE_NAMESPACER_H
#define ONLINE_FIGURINE_STORE_STORE_NAMESPACER_H

#include <iostream>

using namespace std;

class store_namespacer {
    private:

    public:
    string spacePrinter(int columnSize, int length) {
        string spaces ="";
        int spaceNum = columnSize - length;
        for(int i=0; i<spaceNum; i++){
            spaces.append(" ");
        }
        return spaces;
    }

    string headerUnderline(int size){
        string lines = "-";
        for(int i=0; i<size; i++){
            lines.append("-");
        }
        return lines;
    }
};


#endif //ONLINE_FIGURINE_STORE_STORE_NAMESPACER_H
