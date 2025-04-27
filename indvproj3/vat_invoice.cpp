#include "invoice_module.h"

VATInvoice::VATInvoice(Invoice* invoice) : InvoiceDecorator(invoice){}

float VATInvoice::getAmount() const {
    float taxPercentage = 0.21;
    return inner->getAmount() + inner->getAmount() * taxPercentage; 
}