#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int heap1[4] = { 37, 26, 25, 0 };
int heap2[4] = { 45, 32, 0, 22 };
int heap3[4] = { 35, 0, 0, 0 };
int heap4[4] = { 25, 0, 39, 0 };
int heap5[4] = { 37, 15, 0, 0 };

class Ant {
public:
    string aboutMe() {
        cout << "\nЯ принадлежу колонии " << my_colony << endl;
        cout << "Тип: " << type << " Класс: " << my_class << endl;
        cout << "Здоровье: " << health << " Защита: " << armor << " Урон: " << damage << endl << endl;
        return "";
    }
    void aboutQueen();
    string type = "";
    string my_colony = "0";
    string my_class = "";
    int health = 0;
    int armor = 0;
    int damage = 0;
};

class Colony {
public:
    void setName(string new_name) {
        name = new_name;
    }
    string getName() {
        return name;
    }
    void nameAndStatus() {
        cout << "Королева: <" << matkaName << "> (здоровье: " << matkaHealth << ", защита: " << matkaArmor << ", урон: " << matkaDamage << ")" << endl;
    }
    void totalResources() {
        cout << "Количество ресурсов: " << endl;
        for (int x = 0; x < 5; x++) {
            cout << resources[x] << " ";
        }
        cout << endl;
    };
    void insertAnt(Ant ant) {
        ant.my_colony = getName();
        ants.push_back(ant);
    }

    void totalAnts() {
        cout << "Колония " << name << endl;
        cout << "Популяция " << ants.size() << endl;

        for (int x = 0; x < ants.size(); x++) {
            cout << ants.at(x).aboutMe();
        }
    }

    void callAnt(int num) {
        if (num < ants.size()) {
            cout << "Обращаемся к муравью " << num << endl;
            ants.at(num).aboutMe();
        }
    }

    void go() {
        kucha = 1 + rand() % 5;
        go_ant = 1 + rand() % ants.size();
        cout << "Идём всей семьёй " << name << ", количеством " << go_ant << " в кучу " << kucha << endl;
        switch (kucha) {
        case 1:
            cout << "Количество веточек в куче 1 до: " << heap1[0] << endl;
            if ((heap1[0] != 0) && (heap1[0] - go_ant >= 0)) {
                heap1[0] = heap1[0] - go_ant;
                cout << "Количество веточек в куче 1 после: " << heap1[0] << endl;
            }
            else {
                cout << "Веточки в куче 1 отсутствуют" << endl;
            }

            break;

        case 2:
            cout << "Количество веточек в куче 2 до: " << heap2[0] << endl;
            if ((heap2[0] != 0) && (heap2[0] - go_ant >= 0)) {
                heap2[0] = heap2[0] - go_ant;
                cout << "Количество веточек в куче 2 после: " << heap2[0] << endl;
            }
            else {
                cout << "Веточки в куче 2 отсутствуют" << endl;
            }
            break;

        case 3:
            cout << "Количество веточек в куче 3 до: " << heap3[0] << endl;
            if ((heap3[0] != 0) && (heap3[0] - go_ant >= 0)) {
                heap3[0] = heap3[0] - go_ant;
                cout << "Количество веточек в куче 3 после: " << heap3[0] << endl;
            }
            else {
                cout << "Веточки в куче 3 отсутствуют" << endl;
            }
            break;

        case 4:
            cout << "Количество веточек в куче 4 до: " << heap4[0] << endl;
            if ((heap4[0] != 0) && (heap4[0] - go_ant >= 0)) {
                heap4[0] = heap4[0] - go_ant;
                cout << "Количество веточек в куче 4 после: " << heap4[0] << endl;
            }
            else {
                cout << "Веточки в куче 4 отсутствуют" << endl;
            }
            break;

        case 5:
            cout << "Количество веточек в куче 5 до: " << heap5[0] << endl;
            if ((heap5[0] != 0) && (heap5[0] - go_ant >= 0)) {
                heap5[0] = heap5[0] - go_ant;
                cout << "Количество веточек в куче 5 после: " << heap5[0] << endl;
            }
            else {
                cout << "Веточки в куче 5 отсутствуют" << endl;
            }
            break;

        default:
            cout << "Семья " << name << " заблудилась ???" << endl;
            break;

        }
    }

    string name = "";
    string matkaName = "";
    int matkaHealth = 0;
    int matkaArmor = 0;
    int matkaDamage = 0;
    vector <Ant> ants = {};
    int kucha = 1;
    int go_ant = 0;
    int resources[5] = {0, 0, 0, 0, 0};

};

void showDay(int new_day) {
    string sd = "________________________________________";
    cout << "День " << new_day << " (до засухи " << 10 - new_day << " дней)" << endl;
    cout << sd << endl;
}

int day = 1;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int button, nk, nt, exit1 = 1, exit2 = 1, pn;
    Colony colony1;
    colony1.setName("<Красные>");
    colony1.matkaName = "Нефертити";
    colony1.matkaHealth = 22; colony1.matkaArmor = 8; colony1.matkaDamage = 16;
    Colony colony2;
    colony2.setName("<Рыжие>");
    colony2.matkaName = "Юлия";
    colony2.matkaHealth = 28; colony2.matkaArmor = 6; colony2.matkaDamage = 22;
    Colony colony3;
    colony3.setName("<Чёрные>");
    colony3.matkaName = "Ольга";
    colony3.matkaHealth = 21; colony3.matkaArmor = 7; colony3.matkaDamage = 19;
    for (int x = 0; x < 14; x++) {
        Ant ant1;
        ant1.my_class = "Рабочий"; ant1.type = "<элитный>";
        ant1.health = 8; ant1.armor = 4;
        colony2.insertAnt(ant1);
    }
    for (int x = 0; x < 7; x++) {
        Ant ant1;
        ant1.my_class = "Воин"; ant1.type = "<легендарный аномальный>";
        ant1.health = 10; ant1.armor = 6; ant1.damage = 4;
        colony2.insertAnt(ant1);
    }
    for (int x = 0; x < 10; x++) {
        Ant ant1;
        ant1.my_class = "Рабочий"; ant1.type = "<обычный>";
        ant1.health = 1; ant1.armor = 0;
        colony1.insertAnt(ant1);
    }
    for (int x = 0; x < 6; x++) {
        Ant ant1;
        ant1.my_class = "Воин"; ant1.type = "<старший>";
        ant1.health = 2; ant1.armor = 1; ant1.damage = 2;
        colony1.insertAnt(ant1);
    }
    for (int x = 0; x < 14; x++) {
        Ant ant1;
        ant1.my_class = "рабочий";  ant1.type = "<продвинутый>";
        ant1.health = 6; ant1.armor = 2;
        colony3.insertAnt(ant1);
    }
    for (int x = 0; x < 7; x++) {
        Ant ant1;
        ant1.my_class = "Воин"; ant1.type = "<продвинутый>";
        ant1.health = 6; ant1.armor = 2; ant1.damage = 3;
        colony3.insertAnt(ant1);
    }
    vector <Colony> colonies = {};
    colonies.push_back(colony1);
    colonies.push_back(colony2);
    colonies.push_back(colony3);
    while (day != 10) {
        cout << "<1> - Обратиться к колонии;\n<2> - Новый день.\n >> ";
        cin >> button;
        switch (button) {
        case 1:
            cout << "Выберите номер колонии: \n >>";
            cin >> nk;
            while (exit2 == 1) {
                switch (nk) {
                case 1:
                    colony1.nameAndStatus();
                    colony1.totalAnts();
                    colony1.totalResources();
                    break;
                case 2:
                    colony2.nameAndStatus();
                    colony2.totalAnts();
                    colony2.totalResources();
                    break;
                case 3:
                    colony3.nameAndStatus();
                    colony3.totalAnts();
                    colony3.totalResources();
                    break;
                }
                break;
            }
            break;
        case 2:
            showDay(day);
            colony1.go();
            cout << endl;
            colony2.go();
            cout << endl;
            colony3.go();
            cout << endl;
            day++;
            break;

        }
    }
    return 0;
}
