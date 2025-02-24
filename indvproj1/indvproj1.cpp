// Titas Stongvila
// 1 individualus darbas OOP CPP
// Invoice klase

#include <iostream>
#include <sstream>
#include <assert.h>

using namespace std;

class Invoice {
private:
    string customerName;
    int amount;
    bool paid;
    int id;

public:
    static int count;

    Invoice(string customerName, int amount, bool paid) {
        this->customerName = customerName;
        this->amount = amount;
        this->paid = paid;
        this->id = count;
        count++;
    }

    // New invoice (unpaid)
    Invoice(string customerName, int amount) {
        this->customerName = customerName;
        this->amount = amount;
        this->paid = false;
        this->id = count;
        count++;
    }

    ~Invoice() {
        count--;
    }

    string toString() {
        stringstream ss;
        ss << "Name: " << this->customerName << endl << "Amount: " << this->amount << endl << "Is paid: " << (this->paid ? "True" : "False") << endl;

        return ss.str();
    }

    // Setters
    void setCustomerName(string name) {
        this->customerName = name;
    }

    void setAmount(int amount) {
        if (amount > 0) {
            this->amount = amount;
        }
    }

    void setPaid(bool paid) {
        this->paid = paid;
    }

    // Getters
    string getCustomerName() {
        return this->customerName;
    }

    int getAmount() {
        return this->amount;
    }

    bool isPaid() {
        return this->paid;
    }

    int getId() {
        return this->id;
    }
};

int Invoice::count = 0;

int main(){
    Invoice* invoices[3];
    invoices[0] = new Invoice("Titas", 100, false);

    assert(invoices[0]->getId() == 0);

    invoices[1] = new Invoice("Dovydas", 500);
    invoices[2] = new Invoice("Emile", 4000, true);

    // Test objCount
    assert(Invoice::count == 3);

    // Test getters
    assert(invoices[0]->getCustomerName() == "Titas");
    assert(invoices[0]->getAmount() == 100);
    assert(invoices[0]->isPaid() == false);

    string invoiceString = "Name: Titas\nAmount: 100\nIs paid: False\n";

    assert(invoices[0]->toString() == invoiceString);

    // Test setters
    invoices[0]->setCustomerName("Rokas");
    assert(invoices[0]->getCustomerName() == "Rokas");

    invoices[0]->setAmount(10);
    assert(invoices[0]->getAmount() == 10);

    invoices[0]->setAmount(-99);
    assert(invoices[0]->getAmount() == 10);

    invoices[0]->setPaid(true);
    assert(invoices[0]->isPaid() == true);

    // Test destructor
    delete invoices[0];
    assert(Invoice::count == 2);

    delete invoices[1];
    assert(Invoice::count == 1);

    delete invoices[2];
    assert(Invoice::count == 0);

}
