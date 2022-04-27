#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct flight_date {
    int day;
    int month;
    int year;
};

struct flight_data {
    string f_n;
    flight_date f_d;
    int f_p;
    string f_dp;
    int f_m;
};

struct city_pass {
    string city;
    int pass;
};

void entry(flight_data* (&massiv), int& k) {
    cout << "Введите кол-во рейсов: ";
    cin >> k;
    cout << "----------------------------------" << endl;
    massiv = new flight_data[k];
    for (int i = 0; i < k; i++) {
        cout << "Введите номер рейса: ";
        cin >> massiv[i].f_n;
        cout << "Введите дату прибытия: ";
        cin >> massiv[i].f_d.day;
        cin >> massiv[i].f_d.month;
        cin >> massiv[i].f_d.year;
        cout << "Введите кол-во пассажиров: ";
        cin >> massiv[i].f_p;
        cout << "Введите пункт отправления: ";
        cin >> massiv[i].f_dp; 
        cout << "Введите модель самолета (737,767,787): Boeing ";
        cin >> massiv[i].f_m;
        cout << "----------------------------------" << endl;
    }
}

void print(flight_data* massiv, int k) {
    cout << "----------------------------------" << endl;
    for (int i = 1; i < k; i++) {
        cout << "Номер рейса" << " " << massiv[i].f_n << endl;
        cout << "Дата прибытия" << " " << massiv[i].f_d.day << "/" << massiv[i].f_d.month << "/" << massiv[i].f_d.year << endl;
        cout << "Количество пассажиров" << " " << massiv[i].f_p << endl;
        cout << "Пункт отправления" << " " << massiv[i].f_dp << endl;
        cout << "Модель самолета: Boeing " << massiv[i].f_m << endl;
        cout << "----------------------------------" << endl;
    }
}

void change(flight_data* (&massiv), int k) {
    string nomer;
    int counter = 0;
    cout << "Введите номер рейса который вы хотите изменить: ";
    cin >> nomer;
    for (int i = 0; i < k; i++) {
        if (nomer == massiv[i].f_n) {
            counter = 1;
            cout << "Введите номер рейса: ";
            cin >> massiv[i].f_n;
            cout << "Введите дату прибытия: ";
            cin >> massiv[i].f_d.day;
            cin >> massiv[i].f_d.month;
            cin >> massiv[i].f_d.year;
            cout << "Введите кол-во пассажиров: ";
            cin >> massiv[i].f_p;
            cout << "Введите пункт отправления: ";
            cin >> massiv[i].f_dp;
            cout << "Введите модель самолета (737,767,787): Boeing ";
            cin >> massiv[i].f_m;
            system("cls");
            cout << "Данные изменены" << endl;
        }
        else
            if (counter == 0 && i == k - 1)
                cout << "Данного номера рейса не существует" << endl;
    }
}

void copy_1(flight_data* (&massiv_new), flight_data* (&massiv_old), int k) {
    for (int i = 0; i < k; i++)
        massiv_new[i] = massiv_old[i];
}

void copy_2(flight_data& massiv_new, flight_data& massiv_old) {
    massiv_new.f_n = massiv_old.f_n;
    massiv_new.f_d.day = massiv_old.f_d.day;
    massiv_new.f_d.month = massiv_old.f_d.month;
    massiv_new.f_d.year = massiv_old.f_d.year;
    massiv_new.f_p = massiv_old.f_p;
    massiv_new.f_dp = massiv_old.f_dp;
}


void add(flight_data* (&massiv), int& k) {
    flight_data* massiv_2;
    massiv_2 = new flight_data[k];
    copy_1(massiv_2, massiv, k);
    k++;
    massiv = new flight_data[k];
    copy_1(massiv, massiv_2, --k);
    cout << "Введите номер рейса: ";
    cin >> massiv[k].f_n;
    cout << "Введите дату прибытия: ";
    cin >> massiv[k].f_d.day;
    cin >> massiv[k].f_d.month;
    cin >> massiv[k].f_d.year;
    cout << "Введите кол-во пассажиров: ";
    cin >> massiv[k].f_p;
    cout << "Введите пункт отправления: ";
    cin >> massiv[k].f_dp;
    cout << "Введите модель самолета (737,767,787): Boeing ";
    cin >> massiv[k].f_m;
    system("cls");
    cout << "Данные добавлены" << endl;
    delete[]massiv_2;
}

void delet(flight_data* (&massiv), int& k) {
    string nomer;
    int in = 0;
    int counter = 0;
    cout << "Введите  номер рейса который вы хотите удалить: ";
    cin >> nomer;
    system("cls");
    for (int i = 0; i < k; i++) {
        if (nomer == massiv[i].f_n) {
            counter = 1;
            flight_data* massiv_2 = new flight_data[k];
            copy_1(massiv_2, massiv, k);
            --k;
            massiv = new flight_data[k];
            for (int i = 0; i < k; i++) {
                if (nomer != massiv[i].f_n) {
                    massiv[in] = massiv_2[i];
                    ++in;
                }
            }
            system("cls");
            delete[]massiv_2;
        }
        else
            if (counter == 0 && i == k - 1)
                cout << "Данного номера рейса не существует" << endl;
    }
}

void sort(flight_data* massiv, int k) {
    flight_data massiv_2;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (massiv[j].f_d.day < massiv[j + 1].f_d.day) {
            copy_2(massiv_2, massiv[j+1]);
            copy_2(massiv[j+1], massiv[j]);
            copy_2(massiv[j], massiv_2);
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i; j > 0 && massiv[j1].f_d.month < massiv[j+1].f_d.month; j--) {
            copy_2(massiv_2, massiv[j+1]);
            copy_2(massiv[j+1], massiv[j]);
            copy_2(massiv[j], massiv_2);
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i; j > 0 && massiv[j].f_d.year < massiv[j+1].f_d.year; j--) {
            copy_2(massiv_2, massiv[j+1]);
            copy_2(massiv[j+1], massiv[j]);
            copy_2(massiv[j], massiv_2);
        }
    }
    cout << "Данные отсортированы" << endl;
}

void filtr(flight_data* (&massiv), int& k) {
    string nomer;
    int counter = 0;
    cout << "Введите номер рейса по которому вы хотите посмотреть информацию: ";
    cin >> nomer;
    for (int i = 0; i < k; i++) {
        if (massiv[i].f_n == nomer) {
            counter = 1;
            cout << "Номер рейса" << " " << massiv[i].f_n << endl;
            cout << "Дата прибытия" << " " << massiv[i].f_d.day << "/" << massiv[i].f_d.month << "/" << massiv[i].f_d.year << endl;
            cout << "Количество пассажиров" << " " << massiv[i].f_p << endl;
            cout << "Пункт отправления" << " " << massiv[i].f_dp << endl;
            cout << "Модель самолета: Boeing " << massiv[i].f_m << endl;
            cout << "----------------------------------" << endl;
        }
        else {
            if (counter == 0 && i == k - 1)
                cout << "Данного номера рейса не существует" << endl;
        }
    }
}

int outSize = 0;
void delet_repeat(flight_data* (&massiv_old), city_pass* (&massiv_new), int k) {
    int counter = 0;
    for (int i = 0; i < k; i++) {
        counter = 1;
        for (int j = 0; j < k; j++)
            if (j != i && massiv_old[i].f_dp == massiv_new[j].city)
                counter = 0;
        if (counter)
        {
            outSize++;
            massiv_new[outSize - 1].city = massiv_old[i].f_dp;
        }
    }
}

void sum_pass(flight_data* (&massiv_old), city_pass* (&massiv_new), int k) {
    for (int i = 0; i < outSize; i++) {
        for (int j = 0; j < k; j++) {
            if (massiv_old[j].f_dp == massiv_new[i].city) {
                massiv_new[i].pass = massiv_new[i].pass + massiv_old[j].f_p;
            }
        }
    }
}

void high_pass(flight_data* (&massiv), int& k) {
    city_pass* massiv_2 = new city_pass[k];
    for (int i = 0; i < k; i++) {
        massiv_2[k].city = "";
        massiv_2[k].pass = 0;
    }
    delet_repeat(massiv, massiv_2, k);
    sum_pass(massiv, massiv_2, k);
    int max = massiv_2[0].pass;
    string max_2 = massiv_2[0].city;
    for (int i = 1; i < outSize; i++) {
        if (max < massiv_2[i].pass) {
            max = massiv_2[i].pass;
            max_2 = massiv_2[i].city;
        }
    }
    cout << "Пункт с наибольшим пассажиропотоком: " << max_2 << " - " << max << endl;
    outSize = 0;
    delete[]massiv_2;
}

int  command;
void menu() {
    cout << "Выберите действие" << endl;
    cout << "Выйти: 0" << endl;
    cout << "Ввод данных: 1" << endl;
    cout << "Вывод данных: 2" << endl;
    cout << "Редактирование данных: 3" << endl;
    cout << "Добавление данных: 4" << endl;
    cout << "Удаление данных: 5" << endl;
    cout << "Сортировка данных по дате: 6" << endl;
    cout << "Информация по номеру рейса: 7" << endl;
    cout << "Наибольший пассажиропоток: 8" << endl;
    cout << "Выбор команды: " ;
    cin >> command;
}

void main()
{ 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    int _massiv = 0;
    flight_data* massiv = new  flight_data[_massiv];
    while (command != 0) {
        switch (command) {
        case 1:
            system("cls");
            entry(massiv, _massiv);
            system("pause");
            system("cls");
            menu();
            break;
        case 2:
            system("cls");
            if (_massiv != 0)
                print(massiv, _massiv);
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        case 3:
            system("cls");
            if (_massiv != 0)
                change(massiv, _massiv);
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        case 4:
            system("cls");
            if (_massiv != 0) {
                add(massiv, _massiv);
                _massiv++;
            }
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        case 5:
            system("cls");
            if (_massiv != 0) {
                delet(massiv, _massiv);
            }
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        case 6:
            system("cls");
            if (_massiv != 0) {
                sort(massiv, _massiv);
            }
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        case 7:
            system("cls");
            if (_massiv != 0) {
                filtr(massiv, _massiv);
            }
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        case 8:
            system("cls");
            if (_massiv != 0) {
                high_pass(massiv, _massiv);
            }
            else
                cout << "Данных нет" << endl;
            system("pause");
            system("cls");
            menu();
            break;

        default:
            cout << "Номер действия указан неверно" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    exit(0);
}
