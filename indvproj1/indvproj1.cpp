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

    static int staticCount;
    static int staticId;

    void setId(int id) {
        this->id = id;
    }

    static void incStaticId() {
        staticId++;
    }

    static void incCount() {
        staticCount++;
    }

    static void decCount() {
        staticCount--;
    }

public:
    Invoice(string customerName, int amount, bool paid) {
        setCustomerName(customerName);
        setAmount(amount);
        setPaid(paid);
        setId(staticId);
        incStaticId();
        incCount();
    }

    // New invoice (unpaid)
    Invoice(string customerName, int amount) {
        setCustomerName(customerName);
        setAmount(amount);
        setPaid(paid);
        setId(staticId);
        incStaticId();
        incCount();
    }

    ~Invoice() {
        decCount();
    }

    string toString() {
        stringstream ss;
        ss << getCustomerName() << " " << getAmount() << " " << isPaid() << endl;

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

    static int getCount() {
        return staticCount;
    }
};

int Invoice::staticCount = 0;
int Invoice::staticId = 0;

int main(){
    Invoice* invoices[3];
    invoices[0] = new Invoice("Titas", 100, false);

    assert(invoices[0]->getId() == 0);

    invoices[1] = new Invoice("Dovydas", 500);
    invoices[2] = new Invoice("Emile", 4000, true);

    // Test objCount
    assert(Invoice::getCount() == 3);

    // Test getters
    assert(invoices[0]->getCustomerName() == "Titas");
    assert(invoices[0]->getAmount() == 100);
    assert(invoices[0]->isPaid() == false);

    string invoiceString = "Titas 100 0\n";

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
    assert(Invoice::getCount() == 2);

    delete invoices[1];
    assert(Invoice::getCount() == 1);

    delete invoices[2];
    assert(Invoice::getCount() == 0);
}
