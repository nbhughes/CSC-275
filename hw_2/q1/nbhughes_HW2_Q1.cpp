/*
    Nolan Hughes
    HW2 Q1
    Due 2/20/2025
*/

#include <iostream>

std::string memos[] =
{
    "grocery store",
    "restaurant",
    "gas",
    "bowling",
    "coffee"
};

struct Check
{
    int CheckNum;
    std::string CheckMemo;
    float CheckAmount;

    bool operator>(float val)
    {
        return CheckAmount > val;
    }
};

std::ostream& operator<<(std::ostream &stream, const Check &check)
{
    stream << "Check number: " << check.CheckNum << " | Check memo: " << check.CheckMemo << " | Check amount: " << check.CheckAmount;
    return stream;
}

class CheckBook
{
    public:
        CheckBook()
        {
            this->balance = 0.0F;
            this->numOfChecks = 0;
            this->checkBookSize = 4;
            this->chkPtr = new Check[this->checkBookSize];
        }

        CheckBook(float balance)
        {
            this->balance = balance;
            this->numOfChecks = 0;
            this->checkBookSize = 2;
            this->chkPtr = new Check[this->checkBookSize];
        }

        ~CheckBook()
        {
            delete[] this->chkPtr;
        }

        CheckBook(const CheckBook &src)
        {
            this->balance = src.balance;
            this->numOfChecks = src.numOfChecks;
            this->checkBookSize = src.checkBookSize;
        
            this->chkPtr = new Check[this->checkBookSize];
            std::copy(src.chkPtr, src.chkPtr + this->numOfChecks, this->chkPtr);
        }

        bool operator==(const CheckBook &other)
        {
            return this->balance == other.balance && this->numOfChecks == other.numOfChecks && this->checkBookSize == other.checkBookSize;
        }

        void deposit(float amount)
        {
            this->balance += amount;
        }

        bool writeCheck(Check check)
        {
            if (check > this->balance)
            {
                return false;
            }

            if (this->numOfChecks > this->checkBookSize / 2)
            {
                this->checkBookSize *= 2;

                Check *newChkPtr = new Check[this->checkBookSize];
                std::copy(this->chkPtr, this->chkPtr + this->numOfChecks, newChkPtr);
                
                delete[] this->chkPtr;
                this->chkPtr = newChkPtr;

                std::cout << "A new checkbook has been ordered...\n";
            }

            check.CheckNum = this->numOfChecks;
            check.CheckMemo = memos[rand() % 5];

            this->chkPtr[check.CheckNum] = check;

            this->balance -= check.CheckAmount;
            ++this->numOfChecks;

            return true;
        }

        void displayChecks()
        {
            for (int i = numOfChecks - 1; i >= 0; --i)
            {
                std::cout << this->chkPtr[i] << "\n";
            }
        }

        float getBalance()
        {
            return this->balance;
        }

        void setBalance(float balance)
        {
            this->balance = balance;
        }

        float getLastDeposit()
        {
            return this->lastDeposit;
        }

        void setLastDeposit(float val)
        {
            this->lastDeposit = val;
        }

        int getNumOfChecks()
        {
            return this->numOfChecks;
        }

        void setNumOfChecks(int val)
        {
            this->numOfChecks = val;
        }

    private:
        float balance = 0.0F;
        Check *chkPtr = NULL;
        float lastDeposit = 0.0F;
        int numOfChecks = 0;
        int checkBookSize = 0;
};

void checkTest(CheckBook &checkBook)
{
    while (true)
    {
        Check check =
        {
            .CheckAmount = 100.0F
        };

        if (!checkBook.writeCheck(check))
        {
            break;
        }
    }

    checkBook.displayChecks();
}

int main()
{
    CheckBook checkBook(1000.0F);
    checkTest(checkBook);

    std::cout << "\n";
    system("pause");
}