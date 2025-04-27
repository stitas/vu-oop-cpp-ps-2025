#include "invoice_module.h"

DiscountInvoice::DiscountInvoice(Invoice* invoice, float discountPercentage) : InvoiceDecorator(invoice) {
    setDiscountPercentage(discountPercentage);
}

float DiscountInvoice::getAmount() const {
    return inner->getAmount() * (1 - getDiscountPercentage() / 100);
}


float DiscountInvoice::getDiscountPercentage() const {
    return this->discountPercentage;
}

void DiscountInvoice::setDiscountPercentage(float discountPercentage) {
    if(discountPercentage < 0 || discountPercentage > 100){
        throw InvoiceException("Invalid discount percentage. Must be between 0 and 100");
    }
    this->discountPercentage = discountPercentage;
}