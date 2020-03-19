#include<iostream>
#include<string>
#include<windows.h> 
using namespace std; 

struct home{
    int postcode;
    char country[58];
    char region[58];
    char district[58];
    char town[85];
    char street[45];
    int house;
    int apartment;
};
struct date {
    short day;
    short month;
    short  year;
    bool isCorrect();
};
bool date::isCorrect()
{
    bool result = false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if ((day <= 31) && (day > 0))
        {
            result = true;
            break;
        }
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if ((day <= 30) && (day > 0))
        {
            result = true;
            break;
        }
    }
    case 2:
    {
        if (year % 4 != 0)
        {
            if ((day <= 28) && (day > 0))
                result = true;
        }
        else
            if (year % 400 == 0)
            {
                if ((day <= 29) && (day > 0))
                    result = true;
            }
            else
                if ((year % 100 == 0) && (year % 400 != 0))
                {
                    if ((day == 28) && (day > 0))
                        result = true;
                }
                else
                    if ((year % 4 == 0) && (year % 100 != 0))
                        if ((day <= 29) && (day > 0))
                            result = true;
        break;
    }
    default:
        result = false;
    }
    return result;
}

struct Worker {
    char F[56];
    char I[32];
    char O[48];
    home address;
    char nationality[32];
    date birth;
    int NumberShop;
    int PersonnelNumber;
    char educated[32];
    int YearEmployment;
};

Worker*AddStruct(Worker* Obj, const int amount);
void setData(Worker* Obj, const int amount);
void showData(const Worker* Obj, const int amount);
void NumberShop_compare(const Worker* Obj, const int amount);
void YearEmployment_choise(const Worker* Obj, const int amount);

int main()
{
    setlocale(LC_ALL, "rus");

    Worker* OurWorker = 0;
    int WorkerAmount = 0;
    int YesOrNot = 0; 

    do
    {
        OurWorker = AddStruct(OurWorker, WorkerAmount);
        setData(OurWorker, WorkerAmount);

        WorkerAmount++;

        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();
    } while (YesOrNot != 0);

    showData(OurWorker, WorkerAmount);

    delete[] OurWorker;
    return 0;
}

Worker* AddStruct(Worker* Obj, const int amount)
{
    if (amount == 0)
    {
        Obj = new Worker[amount + 1]; 
    }
    else
    {
        Worker* tempObj = new Worker[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; 
        }
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}
void setData(Worker* Obj, const int amount)
{
    cout << "F: ";
    cin.getline(Obj[amount].F, 56);
    cout << "I: ";
    cin.getline(Obj[amount].I, 32);
    cout << "O: ";
    cin.getline(Obj[amount].O, 48);
    cout << "Nationality: ";
    cin.getline(Obj[amount].nationality, 32);
    cout << "Number Shop: ";
    cin >> Obj[amount].NumberShop;
    cin.get();
    cout << "PersonnelNumber: ";
    cin >> Obj[amount].PersonnelNumber;
    cin.get();
    cout << "Educated: ";
    cin.getline(Obj[amount].educated, 32);
    cout << "Year of employment: ";
    cin >> Obj[amount].YearEmployment;
    cin.get();
    do
    {
        cout << "Input date of birth: ";
        cin >> Obj[amount].birth.day >> Obj[amount].birth.month >> Obj[amount].birth.year;
    } while (!Obj[amount].birth.isCorrect());
    cout << "Input home address: ";
    cout << endl;
    cout << "Postcode: ";
    cin >> Obj[amount].address.postcode;
    cin.get();
    cout << "Country: ";
    cin.getline(Obj[amount].address.country, 58);
    cout << "Region: ";
    cin.getline(Obj[amount].address.region, 58);
    cout << "District: ";
    cin.getline(Obj[amount].address.district, 58);
    cout << "Town: ";
    cin.getline(Obj[amount].address.town, 85);
    cout << "Street: ";
    cin.getline(Obj[amount].address.street, 45);
    cout << "House: ";
    cin >> Obj[amount].address.house;
    cin.get();
    cout << "Apartment: ";
    cin >> Obj[amount].address.apartment;
    cin.get();
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Worker* Obj, const int amount)
{
    system("cls");
    cout << "№  " << "F\t" << "I\t" << "O\t" << "Nationality\t" << "Number of shop\t" << "Personnel Number\t" << "Year of employment\t" << endl;
    cout << "================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << "  " << Obj[i].F << '\t' << Obj[i].I << '\t' << Obj[i].O << '\t' <<  '\t' << Obj[i].nationality << '\t' << Obj[i].NumberShop << '\t' << Obj[i].PersonnelNumber << '\t' << Obj[i].YearEmployment << endl;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void NumberShop_compare(Worker * Obj, const int amount)
    {
        for (int i = amount - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (Obj[j].NumberShop > Obj[j + 1].NumberShop)
                {
                    Worker tmp = Obj[j];
                    Obj[j] = Obj[j + 1];
                    Obj[j + 1] = tmp;
                }
            }
        }
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void YearEmployment_choise(const Worker* Obj, const int amount)
{
    int year;
    cout << "Input year of employment";
    cin >> year;
    cout << "№  " << "F\t" << "I\t" << "O\t" << "Nationality\t" << "Number of shop\t" << "Personnel Number\t" << "Year of employment\t" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < amount; i++)
    {    
        if (Obj[i].YearEmployment == year) {
            cout << i + 1 <<  "  " << Obj[i].F << '\t' << Obj[i].I << '\t' << Obj[i].O << '\t' << Obj[i].nationality << '\t' << Obj[i].NumberShop << '\t' << Obj[i].PersonnelNumber << '\t' << Obj[i].YearEmployment << endl;
            }
       
    }
}




   