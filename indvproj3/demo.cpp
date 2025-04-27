#include "invoice_module.h"

int main() {
    try {
        Invoice* invoice = new BaseInvoice("User2", 500, false);
        Invoice* taxInvoice = new VATInvoice(invoice);
        Invoice* discountInvoice = new DiscountInvoice(invoice, 10);
        Invoice* allInvoice = new VATInvoice(new DiscountInvoice(new BaseInvoice("User1", 1000, true), 15));

        printf("BASE INVOICE: %f\n", invoice->getAmount()); // polimorfizmas
        printf("TAX INVOICE: %f\n", taxInvoice->getAmount()); // polimorfizmas
        printf("DISCOUNT INVOICE: %f\n", discountInvoice->getAmount()); // polimorfizmas
        printf("ALL INVOICE: %f\n", allInvoice->getAmount()); // polimorfizmas
    }
    catch (InvoiceException e) {
        printf("%s", e.what());
    }

    return 0;
}