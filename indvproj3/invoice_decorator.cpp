#include "invoice_module.h"

InvoiceDecorator::InvoiceDecorator(Invoice* invoice) : inner(invoice){}

float InvoiceDecorator::getAmount() const { 
    return inner->getAmount(); 
}

void InvoiceDecorator::setAmount(float amount) { 
    inner->setAmount(amount); 
}

std::string InvoiceDecorator::getCustomerName() const { 
    return inner->getCustomerName();
}

void InvoiceDecorator::setCustomerName(std::string name) {
    inner->setCustomerName(name); 
}

bool InvoiceDecorator::isPaid() const { 
    return inner->isPaid(); 
}

void InvoiceDecorator::setPaid(bool paid) { 
    inner->setPaid(paid); 
}

std::string InvoiceDecorator::toString() const {
    return inner->toString(); 
}