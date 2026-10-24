// Mae Schweller
// 210 lab 27
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    const string MENU = "1. Add Villager\n2. Delete Villager\n3. Increase Friendship\n4. Decrease Friendship\n5. Search for Villager\n6. Exit\n";

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
    while (input != 6) {
        switch(input) {
            case 1: {
                cout << "Villager name: ";
                string name;
                cin >> name;
                cout << "Friendship level: ";
                int friendshipLevel;
                cin >> friendshipLevel;
                cout << "Species: ";
                string newSpecies;
                cin >> newSpecies;
                cout << "Catchphrase: ";
                string catchphrase;
                cin >> catchphrase;
                villagerAttributes.insert({name, {friendshipLevel, newSpecies, catchphrase}});
                cout << name << " added\n";
            }
            break;
            case 2:
            {
                string villagerToDelete;
                cout << "Which villager would you like to delete?\n";
                cin >> villagerToDelete;
                auto it = villagerAttributes.find(villagerToDelete);
                if (it != villagerAttributes.end()) {  // the iterator points to beyond the end of the map
                    villagerAttributes.erase(it);
                    cout << villagerToDelete << " has been removed\n";
                } else
                    cout << endl << villagerToDelete << " not found." << endl;
            }
            break;
            case 3:
            {
                string villagerToChange;
                cout << "Which villager would you like to increase?\n";
                cin >> villagerToChange;
                auto iter = villagerAttributes.find(villagerToChange);
                if (iter != villagerAttributes.end()) {
                    if (get<0>(iter->second) < 10) // ensures friendship is bounded from 0 - 10
                        get<0>(iter->second) += 1;
                }
                cout << villagerToChange << "'s friendship is now: " << get<0>(iter->second) << endl;
            }
            break;
            case 4:
            {
                string villagerToChange;
                cout << "Which villager would you like to decrease?\n";
                cin >> villagerToChange;
                auto iter = villagerAttributes.find(villagerToChange);
                if (iter != villagerAttributes.end()) {
                    if (get<0>(iter->second) > 0) // ensures friendship is bounded from 0 - 10
                        get<0>(iter->second) -= 1;
                }
                cout << villagerToChange << "'s friendship is now: " << get<0>(iter->second) << endl;
            }
            break;
            case 5:
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
