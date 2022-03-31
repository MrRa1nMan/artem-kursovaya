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
        cout << "\n� ���������� ������� " << my_colony << endl;
        cout << "���: " << type << " �����: " << my_class << endl;
        cout << "��������: " << health << " ������: " << armor << " ����: " << damage << endl << endl;
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
        cout << "��������: <" << matkaName << "> (��������: " << matkaHealth << ", ������: " << matkaArmor << ", ����: " << matkaDamage << ")" << endl;
    }
    void totalResources() {
        cout << "���������� ��������: " << endl;
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
        cout << "������� " << name << endl;
        cout << "��������� " << ants.size() << endl;

        for (int x = 0; x < ants.size(); x++) {
            cout << ants.at(x).aboutMe();
        }
    }

    void callAnt(int num) {
        if (num < ants.size()) {
            cout << "���������� � ������� " << num << endl;
            ants.at(num).aboutMe();
        }
    }

    void go() {
        kucha = 1 + rand() % 5;
        go_ant = 1 + rand() % ants.size();
        cout << "��� ���� ������ " << name << ", ����������� " << go_ant << " � ���� " << kucha << endl;
        switch (kucha) {
        case 1:
            cout << "���������� ������� � ���� 1 ��: " << heap1[0] << endl;
            if ((heap1[0] != 0) && (heap1[0] - go_ant >= 0)) {
                heap1[0] = heap1[0] - go_ant;
                cout << "���������� ������� � ���� 1 �����: " << heap1[0] << endl;
            }
            else {
                cout << "������� � ���� 1 �����������" << endl;
            }

            break;

        case 2:
            cout << "���������� ������� � ���� 2 ��: " << heap2[0] << endl;
            if ((heap2[0] != 0) && (heap2[0] - go_ant >= 0)) {
                heap2[0] = heap2[0] - go_ant;
                cout << "���������� ������� � ���� 2 �����: " << heap2[0] << endl;
            }
            else {
                cout << "������� � ���� 2 �����������" << endl;
            }
            break;

        case 3:
            cout << "���������� ������� � ���� 3 ��: " << heap3[0] << endl;
            if ((heap3[0] != 0) && (heap3[0] - go_ant >= 0)) {
                heap3[0] = heap3[0] - go_ant;
                cout << "���������� ������� � ���� 3 �����: " << heap3[0] << endl;
            }
            else {
                cout << "������� � ���� 3 �����������" << endl;
            }
            break;

        case 4:
            cout << "���������� ������� � ���� 4 ��: " << heap4[0] << endl;
            if ((heap4[0] != 0) && (heap4[0] - go_ant >= 0)) {
                heap4[0] = heap4[0] - go_ant;
                cout << "���������� ������� � ���� 4 �����: " << heap4[0] << endl;
            }
            else {
                cout << "������� � ���� 4 �����������" << endl;
            }
            break;

        case 5:
            cout << "���������� ������� � ���� 5 ��: " << heap5[0] << endl;
            if ((heap5[0] != 0) && (heap5[0] - go_ant >= 0)) {
                heap5[0] = heap5[0] - go_ant;
                cout << "���������� ������� � ���� 5 �����: " << heap5[0] << endl;
            }
            else {
                cout << "������� � ���� 5 �����������" << endl;
            }
            break;

        default:
            cout << "����� " << name << " ����������� ???" << endl;
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
    cout << "���� " << new_day << " (�� ������ " << 10 - new_day << " ����)" << endl;
    cout << sd << endl;
}

int day = 1;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int button, nk, nt, exit1 = 1, exit2 = 1, pn;
    Colony colony1;
    colony1.setName("<�������>");
    colony1.matkaName = "���������";
    colony1.matkaHealth = 22; colony1.matkaArmor = 8; colony1.matkaDamage = 16;
    Colony colony2;
    colony2.setName("<�����>");
    colony2.matkaName = "����";
    colony2.matkaHealth = 28; colony2.matkaArmor = 6; colony2.matkaDamage = 22;
    Colony colony3;
    colony3.setName("<׸����>");
    colony3.matkaName = "�����";
    colony3.matkaHealth = 21; colony3.matkaArmor = 7; colony3.matkaDamage = 19;
    for (int x = 0; x < 14; x++) {
        Ant ant1;
        ant1.my_class = "�������"; ant1.type = "<�������>";
        ant1.health = 8; ant1.armor = 4;
        colony2.insertAnt(ant1);
    }
    for (int x = 0; x < 7; x++) {
        Ant ant1;
        ant1.my_class = "����"; ant1.type = "<����������� ����������>";
        ant1.health = 10; ant1.armor = 6; ant1.damage = 4;
        colony2.insertAnt(ant1);
    }
    for (int x = 0; x < 10; x++) {
        Ant ant1;
        ant1.my_class = "�������"; ant1.type = "<�������>";
        ant1.health = 1; ant1.armor = 0;
        colony1.insertAnt(ant1);
    }
    for (int x = 0; x < 6; x++) {
        Ant ant1;
        ant1.my_class = "����"; ant1.type = "<�������>";
        ant1.health = 2; ant1.armor = 1; ant1.damage = 2;
        colony1.insertAnt(ant1);
    }
    for (int x = 0; x < 14; x++) {
        Ant ant1;
        ant1.my_class = "�������";  ant1.type = "<�����������>";
        ant1.health = 6; ant1.armor = 2;
        colony3.insertAnt(ant1);
    }
    for (int x = 0; x < 7; x++) {
        Ant ant1;
        ant1.my_class = "����"; ant1.type = "<�����������>";
        ant1.health = 6; ant1.armor = 2; ant1.damage = 3;
        colony3.insertAnt(ant1);
    }
    vector <Colony> colonies = {};
    colonies.push_back(colony1);
    colonies.push_back(colony2);
    colonies.push_back(colony3);
    while (day != 10) {
        cout << "<1> - ���������� � �������;\n<2> - ����� ����.\n >> ";
        cin >> button;
        switch (button) {
        case 1:
            cout << "�������� ����� �������: \n >>";
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
