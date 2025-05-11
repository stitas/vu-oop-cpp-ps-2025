#ifndef INVOICE_MODULE
#define INVOICE_MODULE

#include <string>

class Invoice {
public:
    ~Invoice() = default;

    virtual float getAmount() const = 0;
    virtual void setAmount(float amount) = 0;
    virtual std::string getCustomerName() const = 0;
    virtual void setCustomerName(std::string name) = 0;
    virtual bool isPaid() const = 0;
    virtual void setPaid(bool paid) = 0;
    virtual std::string toString() const = 0;
};

class InvoiceDecorator : public Invoice {
protected:
    Invoice* inner;

public:
    InvoiceDecorator(Invoice* invoice);

    float getAmount() const override;
    void setAmount(float amount) override;
    std::string getCustomerName() const override;
    void setCustomerName(std::string name) override;
    bool isPaid() const override;
    void setPaid(bool paid) override;
    std::string toString() const override;
};

class BaseInvoice : public Invoice {
private:
    std::string customerName;
    int amount;
    bool paid;

public:
    BaseInvoice(std::string customerName, float amount, bool paid);

    float getAmount() const override;
    void setAmount(float amount) override;
    std::string getCustomerName() const override;
    void setCustomerName(std::string name) override;
    bool isPaid() const override;
    void setPaid(bool paid) override;
    std::string toString() const override;
};

// Decorator to add Value added tax to invoice sum
class VATInvoice : public InvoiceDecorator {
public:
    VATInvoice(Invoice* invoice);
    float getAmount() const override;
};

// Discount decorator to reduce invoice price
class DiscountInvoice : public InvoiceDecorator {
private:
    float discountPercentage;

public:
    DiscountInvoice(Invoice* invoice, float discountPercentage);
    float getAmount() const override;
    float getDiscountPercentage() const;

private:
    // Set the discount percentage
    void setDiscountPercentage(float discountPercentage);
};

class InvoiceException : public std::exception {
private:
    std::string message;

public:
    InvoiceException(std::string msg) : message(msg){}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif