#include <assert.h>
#include "invoice_module.h"

int main() {
    try {
        /*
        Sukurti klasę NameInvoice, kuri yra dekoratorius, kuris padidina sąskaitos sumą priklausomai nuo kliento vardo ilgio:
        Už kiekvieną char pridedama +10% nuo pradinės sumos.

        Pvz: 
        Invoice* invoice = new BaseInvoice("User", 100, false);
        Invoice* nameInvoice = new NameInvoice(invoice);

        nameInvoice->getAmount() grąžina 140

        "User" ilgis yra 4
        10% nuo pradinės sumos (100) yra 10
        100 + 4 * 10 = 140
        */
        
        Invoice* invoice = new BaseInvoice("User", 100, false);
        Invoice* nameInvoice = new NameInvoice(invoice);

        printf("TEST 1: ");
        assert(nameInvoice->getAmount() == 140);
        printf("PASSED\n");

        Invoice* invoice1 = new BaseInvoice("", 100, false);
        Invoice* nameInvoice1 = new NameInvoice(invoice1);

        printf("TEST 2: ");
        assert(nameInvoice1->getAmount() == 100);
        printf("PASSED\n");

        Invoice* invoice2 = new BaseInvoice("User user", 100, false);
        Invoice* nameInvoice2 = new NameInvoice(invoice2);

        printf("TEST 3: ");
        assert(nameInvoice2->getAmount() == 190);
        printf("PASSED\n");
    }
    catch (InvoiceException e) {
        printf("%s", e.what());
    }
    return 0;
}