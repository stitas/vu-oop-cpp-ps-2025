#include <sstream>
#include "invoice_module.h"

BaseInvoice::BaseInvoice(std::string customerName, float amount, bool paid) {
    setCustomerName(customerName);
    setAmount(amount);
    setPaid(paid);
}

std::string BaseInvoice::toString() const {
    std::ostringstream ss;
    ss << getCustomerName() << " " << getAmount() << " " << isPaid() << "\n";

    return ss.str();
}

// Setters
void BaseInvoice::setCustomerName(std::string name) {
    this->customerName = name;
}

void BaseInvoice::setAmount(float amount) {
    if (amount <= 0) {
        throw InvoiceException("Invalid invoice amount");
    }

    this->amount = amount;
}

void BaseInvoice::setPaid(bool paid) {
    this->paid = paid;
}

// Getters
std::string BaseInvoice::getCustomerName() const {
    return this->customerName;
}

float BaseInvoice::getAmount() const {
    return this->amount;
}

bool BaseInvoice::isPaid() const {
    return this->paid;
}