#include <iostream>
#include <cmath>
#include <string>

class DigitalWallet {
private:
    std::string ownerID;
    double balance;   // stored in dollars

    // Private helper to check overdraft
    bool isOverdraft() const {
        return balance < 0.0;
    }

public:
    // Constructors
    DigitalWallet() : ownerID("UNKNOWN"), balance(0.0) {}

    DigitalWallet(const std::string& id, double initialBalance)
        : ownerID(id), balance(initialBalance) {
        if (initialBalance < 0.0) {
            std::cerr << "Warning: Wallet initialized with negative balance.\n";
        }
    }

    // Destructor
    ~DigitalWallet() {
        std::cout << "Closing wallet [" << ownerID
                  << "] with final balance: $" << balance << std::endl;
    }

    // Getters
    const std::string& getOwnerID() const {
        return ownerID;
    }

    double getBalance() const {
        return balance;
    }

    // Setters
    void setOwnerID(const std::string& id) {
        if (!id.empty()) {
            ownerID = id;
        } else {
            std::cerr << "Error: Owner ID cannot be empty.\n";
        }
    }

    void setBalance(double newBalance) {
        balance = newBalance;
        if (isOverdraft()) {
            std::cerr << "Warning: Balance is negative (overdraft).\n";
        }
    }

    // Deposit operator (wallet + amount)
    DigitalWallet operator+(double amount) const {
        if (amount < 0.0) {
            std::cerr << "Error: Cannot deposit a negative amount.\n";
            return *this;
        }
        return DigitalWallet(ownerID, balance + amount);
    }

    // Withdrawal operator (wallet - amount)
    DigitalWallet operator-(double amount) const {
        if (amount < 0.0) {
            std::cerr << "Error: Cannot withdraw a negative amount.\n";
            return *this;
        }

        DigitalWallet result(ownerID, balance - amount);
        if (result.isOverdraft()) {
            std::cerr << "Warning: Overdraft occurred.\n";
        }
        return result;
    }

    // Interest operator (wallet * rate)
    DigitalWallet operator*(double rate) const {
        if (rate < 0.0) {
            std::cerr << "Error: Interest rate cannot be negative.\n";
            return *this;
        }
        return DigitalWallet(ownerID, balance * rate);
    }

    // Type conversion to long (total cents)
    operator long() const {
        return static_cast<long>(std::round(balance * 100));
    }

    // Status check function
    void checkStatus() const {
        std::cout << "Wallet [" << ownerID << "] Balance: $"
                  << balance;
        if (isOverdraft()) {
            std::cout << " (OVERDRAFT)";
        }
        std::cout << std::endl;
    }

    // Friend operator to allow: amount + wallet
    friend DigitalWallet operator+(double amount, const DigitalWallet& wallet);
};

// Non-member operator (double + wallet)
DigitalWallet operator+(double amount, const DigitalWallet& wallet) {
    return wallet + amount;
}
