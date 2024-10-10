#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string name;
    string phone;
};

vector<Contact> contacts;

void add_contact(const string& name, const string& phone) {
    contacts.push_back({name, phone});
    cout << "Contact '" << name << "' added successfully." << endl;
}

void change_contact(const string& name, const string& new_name = "", const string& new_phone = "") {
    for (auto& contact : contacts) {
        if (contact.name == name) {
            if (!new_name.empty()) {
                contact.name = new_name;
            }
            if (!new_phone.empty()) {
                contact.phone = new_phone;
            }
            cout << "Contact '" << name << "' changed to '" << contact.name
                 << "' with phone number '" << contact.phone << "'." << endl;
            return;
        }
    }
    cout << "Contact '" << name << "' not found." << endl;
}

void search_by_name(const string& name) {
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Found: " << contact.name << ", Phone: " << contact.phone << endl;
            return;
        }
    }
    cout << "Contact '" << name << "' not found." << endl;
}

void search_by_phone(const string& phone) {
    for (const auto& contact : contacts) {
        if (contact.phone == phone) {
            cout << "Found: " << contact.name << ", Phone: " << contact.phone << endl;
            return;
        }
    }
    cout << "Contact with phone number '" << phone << "' not found." << endl;
}

void display_contacts() {
    if (contacts.empty()) {
        cout << "The phonebook is empty." << endl;
        return;
    }
    cout << "Contacts:" << endl;
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << endl;
    }
}

int main() {
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

        int action = stoi(choice);

        switch (action) {
            case 1: {
                string name, phone;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phone);
                add_contact(name, phone);
                break;
            }
            case 2: {
                string name, new_name, new_phone;
                cout << "Enter name of contact to change: ";
                getline(cin, name);
                cout << "Enter new name (or leave blank to keep unchanged): ";
                getline(cin, new_name);
                cout << "Enter new phone number (or leave blank to keep unchanged): ";
                getline(cin, new_phone);
                change_contact(name, new_name.empty() ? "" : new_name, new_phone.empty() ? "" : new_phone);
                break;
            }
            case 3: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                search_by_name(name);
                break;
            }
            case 4: {
                string phone;
                cout << "Enter phone number to search: ";
                getline(cin, phone);
                search_by_phone(phone);
                break;
            }
            case 5:
                display_contacts();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    return 0;
}
