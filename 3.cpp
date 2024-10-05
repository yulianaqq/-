#include <iostream>
#include <string>

using namespace std;

const int MAX_CONTACTS = 100;

class Phonebook {
public:
    Phonebook() : contact_count(0) {}

    void add_contact(const string& name, const string& phone) {
        if (contact_count < MAX_CONTACTS) {
            contacts[contact_count][0] = name;
            contacts[contact_count][1] = phone;
            contact_count++;
            cout << "Contact '" << name << "' added successfully." << endl;
        } else {
            cout << "Phonebook is full. Cannot add more contacts." << endl;
        }
    }

    void change_contact(const string& name, const string& new_name = "", const string& new_phone = "") {
        for (int i = 0; i < contact_count; i++) {
            if (contacts[i][0] == name) {
                if (!new_name.empty()) {
                    contacts[i][0] = new_name;
                }
                if (!new_phone.empty()) {
                    contacts[i][1] = new_phone;
                }
                cout << "Contact '" << name << "' changed to '" << contacts[i][0] 
                     << "' with phone number '" << contacts[i][1] << "'." << endl;
                return;
            }
        }
        cout << "Contact '" << name << "' not found." << endl;
    }

    void search_by_name(const string& name) const {
        for (int i = 0; i < contact_count; i++) {
            if (contacts[i][0] == name) {
                cout << "Found: " << contacts[i][0] << ", Phone: " << contacts[i][1] << endl;
                return;
            }
        }
        cout << "Contact '" << name << "' not found." << endl;
    }

    void search_by_phone(const string& phone) const {
        for (int i = 0; i < contact_count; i++) {
            if (contacts[i][1] == phone) {
                cout << "Found: " << contacts[i][0] << ", Phone: " << contacts[i][1] << endl;
                return;
            }
        }
        cout << "Contact with phone number '" << phone << "' not found." << endl;
    }

    void display_contacts() const {
        if (contact_count == 0) {
            cout << "The phonebook is empty." << endl;
            return;
        }
        cout << "Contacts:" << endl;
        for (int i = 0; i < contact_count; i++) {
            cout << "Name: " << contacts[i][0] << ", Phone: " << contacts[i][1] << endl;
        }
    }

private:
    string contacts[MAX_CONTACTS][2];
    int contact_count;
};

int main() {
    Phonebook phonebook;

    while (true) {
        cout << "\nChoose an action:" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Change contact" << endl;
        cout << "3. Search by name" << endl;
        cout << "4. Search by phone" << endl;
        cout << "5. Display all contacts" << endl;
        cout << "6. Exit" << endl;

        string choice;
        cout << "Your choice: ";
        getline(cin, choice);

        if (choice == "1") {
            string name, phone;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phone);
            phonebook.add_contact(name, phone);
        } else if (choice == "2") {
            string name, new_name, new_phone;
            cout << "Enter name of contact to change: ";
            getline(cin, name);
            cout << "Enter new name (or leave blank to keep unchanged): ";
            getline(cin, new_name);
            cout << "Enter new phone number (or leave blank to keep unchanged): ";
            getline(cin, new_phone);
            phonebook.change_contact(name, new_name.empty() ? "" : new_name, new_phone.empty() ? "" : new_phone);
        } else if (choice == "3") {
            string name;
            cout << "Enter name to search: ";
            getline(cin, name);
            phonebook.search_by_name(name);
        } else if (choice == "4") {
            string phone;
            cout << "Enter phone number to search: ";
            getline(cin, phone);
            phonebook.search_by_phone(phone);
        } else if (choice == "5") {
            phonebook.display_contacts();
        } else if (choice == "6") {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
