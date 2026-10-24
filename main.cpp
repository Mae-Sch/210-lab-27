// Mae Schweller
// 210 lab 27
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    const string MENU = "1. Increase Friendship\n2. Decrease Friendship\n3. Search for Villager\n4. Exit\n";

    // tuple holds friendship, species, and catchphrase, respectively
    map<string, tuple<int, string, string>> villagerAttributes;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerAttributes["Alphys"] = {9, "Dinosaur", "meoww mreow!!!"};
    villagerAttributes["Raymond"] = {8, "Cat", "Nice fit"};
    villagerAttributes.insert({"Drago", {3, "Alligator", "Snap to it"}});

    cout << "Villager details:" << endl;
    for (auto pair : villagerAttributes) {
        cout << pair.first << ": ";
        cout << "[" << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << "]";
        cout << endl;
    }

    cout << MENU;
    int input;
    cin >> input;
    while (input != 4) {
        switch(input) {
            case 1:
            {
                string villagerToChange;
                cout << "Which villager would you like to increase?\n";
                cin >> villagerToChange;
                auto iter = villagerAttributes.find(villagerToChange);
                if (iter != villagerAttributes.end()) {
                    if (get<0>(iter->second) < 10) // ensures friendship is bounded from 0 - 10
                        get<0>(iter->second) += 1;
                }
                cout << villagerToChange << "'s firendship is now: " << get<0>(iter->second) << endl;
            }
            break;
            case 2:
            {
                string villagerToChange;
                cout << "Which villager would you like to decrease?\n";
                cin >> villagerToChange;
                auto iter = villagerAttributes.find(villagerToChange);
                if (iter != villagerAttributes.end()) {
                    if (get<0>(iter->second) > 0) // ensures friendship is bounded from 0 - 10
                        get<0>(iter->second) -= 1;
                }
                cout << villagerToChange << "'s firendship is now: " << get<0>(iter->second) << endl;
            }
            break;
            case 3:
            {
                string villagerToSearch;
                cout << "Which villager would you like to search for?\n";
                cin >> villagerToSearch;
                auto it = villagerAttributes.find(villagerToSearch);
                if (it != villagerAttributes.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                cout << "\nFound " << villagerToSearch << "'s attributes: ";
                cout << "[" << get<0>(it->second) << ", ";
                cout << get<1>(it->second) << ", ";
                cout << get<2>(it->second) << "]";
                cout << endl;
            } else
                cout << endl << villagerToSearch << " not found." << endl;
            }
            break;
        }
        cout << MENU;
        cin >> input;
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerAttributes.size() << endl;
    villagerAttributes.clear();
    cout << "Size after clear: " << villagerAttributes.size() << endl;

    return 0;
}
