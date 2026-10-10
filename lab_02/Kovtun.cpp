#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Account {
private:
    string surname;
    int accountNumber;
    double balance;
    double vidsotok;


public:
    // початкові дані в систм.
    void Init() {
        surname = "Юрченко";
        accountNumber = 1234;
        balance = 1000;
        vidsotok = 5;


    } // Просим ввод
    void Read() {
        cout << "Введіть прізвище власника: ";
        cin >> surname;

        cout << "Введіть номер рахунку: ";
        cin >> accountNumber;

        cout << "Введіть відсоток нарахування: ";
        cin >> vidsotok;

        cout << "Введіть суму на рахунку: ";
        cin >> balance;
    }
    // вивод 
    void Display() {
        cout << "Призвіще власника: " << surname << endl;
        cout << "Номер рахунку: " << accountNumber << endl;
        cout << "Відсоток нарахування: " << vidsotok << "%" << endl;
        cout << "Баланс разунку: " << balance << "грн" << endl;
    }

    
    //New Vlasnuk
    void ChangeOwner() {
        cout << "Введіть нове прізвище власника: ";
        cin >> surname;
    }


    // Зняти мані
    void ZnyatuGr() {
        double suma;

        cout << "Введіть суму для зняття: ";
        cin >> suma;

        if (suma > 0 && suma <= balance) {
            balance = balance - suma;
            cout << "Гроші знято успішно! " << endl;
        }
        else {
            cout << "Недостатньо коштів або неправильна сума! " << endl;
        }
    } //Поповнення
    void Deposit() {
        double mani;
        cout << "Введіть суму поповнення: ";
        cin >> mani;

        if (mani <= 0) {
            cout << "Помилка поповнення:" << endl;
        }
        else {
            balance += mani;
            cout << "Операція успішна";
        }
    }
     // Проценти
    void AddInterest() {
        double banka;
        banka = balance * vidsotok / 100.0;

        balance += banka;
        cout << "Нараховані кошти(%) =" << banka << "грн." << endl;
    }
    // Долари перевод курс
    void Dollars() {
        double kurs = 45;
        double perevod;

        perevod = balance / kurs;

        cout << "Отриманий результат перевооду гривнів в долари: " << perevod << "$" << endl;

    }
    // Евро перевод
    void Euro() {
        double kursE = 50;
        double perevod;

        perevod = balance / kursE;

        cout << "Отриманий результат перевооду гривнів в euro: " << perevod << " euro" << endl;

    }
    // Костильний перевод в стринг
    void SumWords() {
        int number = (int)balance;
        //??
        if (number < 0 || number > 999) {
            cout << "Введіть баланс від 0 до 999 грн" << endl;
            return;
        }

        string ones[] = { "", "один", "два", "три", "чотири",
            "п'ять", "шість", "сім", "вісім", "дев'ять" };

        string teens[] = { "десять", "одинадцять", "дванадцять",
            "тринадцять", "чотирнадцять", "п'ятнадцять",
            "шістнадцять", "сімнадцять", "вісімнадцять",
            "дев'ятнадцять" };

        string tens[] = { "", "", "двадцять", "тридцять",
            "сорок", "п'ятдесят", "шістдесят",
            "сімдесят", "вісімдесят", "дев'яносто" };

        string hundreds[] = { "", "сто", "двісті", "триста",
            "чотириста", "п'ятсот", "шістсот", "сімсот",
            "вісімсот", "дев'ятсот" };

        if (number == 0) {
            cout << "нуль гривень";
            return;
        }

        if (number / 100 > 0)
            cout << hundreds[number / 100] << " ";

        int rest = number % 100;

        if (rest >= 10 && rest <= 19) {
            cout << teens[rest - 10] << " ";
        }
        else {
            if (rest / 10 > 0)
                cout << tens[rest / 10] << " ";

            if (rest % 10 > 0)
                cout << ones[rest % 10] << " ";
        }

        cout << "грн на Вашому балансі." << endl;

    }
            //??
};

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
        
    
    Account user;

    
    user.Init();
    
    user.Read();
   
    int choice;

    do {
        cout << "\n  ===== МЕНЮ =====  "  << endl;
        cout << "1. Показати рахунок" << endl;
        cout << "2. Змінити власника" << endl;
        cout << "3. Зняти гроші" << endl;
        cout << "4. Поповнити рахунок" << endl;
        cout << "5. Нарахувати відсотки" << endl;
        cout << "6. Перевести в долари" << endl;
        cout << "7. Перевести в євро" << endl;
        cout << "8. Сума прописом" << endl;
        cout << "0. Вийти" << endl;

        cout << "Оберіть дію: ";
        cin >> choice;
       
        switch (choice) {
            case 1:
                user.Display();
                break;
            
            case 2: user.ChangeOwner();
                break;

            case 3: user.ZnyatuGr();
                break;

            case 4: user.Deposit();
                break;

            case 5: user.AddInterest();
                break;

            case 6: user.Dollars();
                break;

            case 7: user.Euro();
                break;
            
            case 8: user.SumWords();
                break;

            case 0: 
                cout<< "До побачення!"  << endl;
                break;

            default:
                cout<< "Помилка, не правильний вибір." << endl;
                               

        }

    } while (choice != 0);


   

    return 0;
}