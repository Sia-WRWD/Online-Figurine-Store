#include <iostream>

#include "store_controller.h"

using namespace std;

void InitMenu() {
    cout << "Welcome to ABCD Purchase Order Management System (POMS), what would you like to do?" << endl;
    cout << "1) Login as Sales Order Executive (SOE)" << endl;
    cout << "2) Login as Administrator" << endl;
    cout << "3) Exit" << endl;
}

void handleAction(int options) {
    switch (options) {
        case 1:
            runSoe();
            break;
        case 2:
            runAdmin();
            break;
        case 3:
            cout << "-------------------------------------------------------------------" << endl;
            cout << "Thank you for using ABCD Purchase Order Management System (POMS)..." << endl;
            cout << "-------------------------------------------------------------------" << endl; //(wally, 2016)
            cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWWWWNNNNWWWWMMMMMMMMMMMMMMMWWWWWMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMWWWNXK00OOOOOO000KXNWWMMMMMMWWNXKKKKKXNNWWMMMMMMMMMMMMMMM
MMMMMMMMMWWX0kxxxxkkkkkkkkkkOO0XNNNNNXK0OOOOOOOOOO0KNWMMMMMMMMMMMMM
MMMMMMMMWXOdddxxxkkkkkkkkkkkkkkkOO00OOOOOOOOOOOOOOkk0XWWMMMMMMMMMMM
MMMMMMMWKxddxxxxxkkkkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkOKNWMMMMMMMMMM
MMMMMMW0xdxxxkkxkkkOOOOOO00000OOOO000OO00OOOOOOO0OO00OO0XWMMMMMMMMM
MMMMMNOdddxxkxxdddxxkkOO000000000000000000000000000000OO0XWMWMMMMMM
MMMWXkooodddolc::;;;:::cclddxxkO000KKKKK0KKK000000OOOOkkkkOKNWMWMMM
MWXOxdoddoolc:;,,,''......'',:loxk000KKKKK0Okxdollcc::ccllllx0NWMMM
WKxoddxxxdoollllllllllllcc:::clodxkOOO0000Okxdl:;,,,,,,;::clclkNMMM
WKdodxxxxxdoollccccllllllllcccclodxkkOOOOOkxdoollllllooddddxxdx0WMM
WKdoddxddolcc:;''''....':clcc::::coxkOO00Oxdoolllol:,,:clclodddONMM
WKdooooollccc:;',;;.  ..;lolc:;;;:odxOO0Okdolccodl,...':l::clodONMM
MKdoddoodooooollccc:,',:cllcc::::codxkO00Oxlccclol;..':lllllooxKWMM
MKxdxxxxxxxkkkxxddddoooooolllclloodxxkO00OkdolllooolllodddxkOKNWMMM
WKxdxxxxkkkkkkkkxxxxxxdoollooddddddddxkO000OkxxdxxxkkkkkkOKXWWMMMMM
WKxdxxxxkkkkkkkkkkxxxxxddoddddddddddddkO000OOOkkkOOOOOOOOXWWWMMMMMM
WKxdxdxxxxkkkkkkkkxxxxxxxxxdoollllooodkO000OOkkkkOOOOOOkOKWWMMMMMMM
WKdddddxxxkkkkkkkkkkkxxxxkxdollodoooodk0000OkxxxkOOOOOOkkkKWMMMMMMM
WKdodddxxxkkkkkkkkkkkkxxxxkxoooddooodxOKKK0OkkxxkO00O0OOkxkXWMMMMMM
WKdodddddddddddxxxxxxxddxxxxdoollloodkO00OkkkkkkOOOOOOOOkkxkXWMMMMM
MKdlooodooolccc::::::::::clllllloddxxxkkkkxdxxkkkkkkkkkkkkkxONMMMMM
W0oloooddddoolc:;;,,''....''''',;::::ccccc::cccccclooddxxxdx0NMMMMM
WKolooooooooooooolllccc:::::::;;;;;;;;,,,,,,,,,,,,,;;:cllokKNWMMMMM
WKl:;,''''''',,;:cllooooollooooooooooooooooooooooooooodddkXWMMMMMMM
Wk,.................';:lddxxxddddddddddddddddxxxxdxxkkO0KNWMMMMMMMM
Wk'.',,;;;;;;;;,,''.....':ldxxxxxxxxxddolllllllooodOKXWWWWWWMMMMMMM
WO:;:::::::::::::;;:;,'.....;ldddolcc;,..........'c0NWMWWWWWMMMMMMM
WOc;::::::::::::::::::;;,'.  .,:;'.........''''''..,;lkXWMWWMMMMMMM
WOc;::::::::::::::::::::;;,..    ...',;;;::ccllllc:,,..,xXWMMMMMMMM
WOc;:::::::::::::::::::::::;'.   .,;::;::lodddxxxdol::;..:0WWMMMMMM
WOc;::::::::::::::::::::::::;,.. .',;::::clcllodxxxdoc;;,.;0WMMMMMM
WOc;:::;;;;::::::::::::::::::;;'...',;:::::;::codxxxdl:;;..oNMMMMMM
WO:,,'......',;;;::::::::::::;:;,'',;;:::::::;:codxxdl::;,.:KWMMMMM
Wk'...',;;,'....,;:::;:::::::::::;;;;,,,,,,,;;;:lodol:;:;,.;KWMMMMM
Wx..:oxkOOkkd:. .';::::::::::::::;'...........',;cc:::;:;..cNWWMMMM
W0dxOOOOOOOO0k:. .,;::::::::::::;.. .'cooolc,....,;::::;'..kWMMMMMM
WX0OOOOOOOOxo;. ..,;::::::::::::,.  .:kOOkkkxc.  .';;:;,..oNMMMMMMM
WX0OOOOOkd:'. ..',;;:;;;;;;;;;;;,.   ,dOOkkkkxl.  .';;,..oNMMMMMMMM
WNXKXXXK0xlllodxxxxxxxxxxxxxxxxxxdolldOKKKKKKK0xolloxxdokNWWMMMMMMM
MMMMWWWMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMMWWWWWWWMWWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMMWMMMMMMMMMMMMMMMMMMM
- xQcL
                    )" << endl;
            break;
        default:
            break;
    }
}

int main() {
    //Initialize Data
    ull.InitUserData();
    poll.InitPurchaseOrdersData();
    cll.InitClientData();
    ill.InitItemData();

    //Get User Input for Initial Menu
    while(true) {
        int init_input;

        InitMenu();

        cout << "Your Input:";
        cin >> init_input;
        cout << endl;

        while(cin.fail()) {
            cout << "Your Input:";
            cout << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> init_input;
        }

        handleAction(init_input);

        if (init_input == 3) {
            break;
        }

    }
}
