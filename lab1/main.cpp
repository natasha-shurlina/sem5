#include <iostream>
#include <limits>
#include "keeper.h"
#include "speedboat.h"
#include "sailboat.h"
#include "submarine.h"

using namespace std;

void display_menu() {
    cout << "Меню:\n";
    cout << "1. Добавить объект\n";
    cout << "2. Удалить объект\n";
    cout << "3. Редактировать объект\n";
    cout << "4. Показать все объекты\n";
    cout << "5. Сохранить объекты в файл\n";
    cout << "6. Загрузить объекты из файла\n";
    cout << "7. Поменять местами элементы (оператор '!')\n";
    cout << "8. Удалить первый элемент (оператор '*')\n";
    cout << "9. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    Keeper keeper;
    int choice, index;
    string filename;

    while (true) {
        display_menu();
        try {
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "Выберите тип для добавления: \n";
                    cout << "1. Speedboat\n2. Sailboat\n3. Submarine\n";
                    int type;
                    cin >> type;
                    Ship* ship = nullptr;

                    if (type == 1) {
                        ship = new Speedboat();
                    } else if (type == 2) {
                        ship = new Sailboat();
                    } else if (type == 3) {
                        ship = new Submarine();
                    } else {
                        throw invalid_argument("Неверный выбор!\n");
                    }
                    ship->input_info();
                    keeper.add(ship);
                    cout << "Объект добавлен.\n";
                    break;
                }
                case 2:
                    cout << "Введите номер объекта для удаления: ";
                    cin >> index;
                    keeper.delete_Node(index);
                    break;
                case 3:
                    cout << "Введите номер объекта для редактирования: ";
                    cin >> index;
                    keeper.edit_Node(index);
                    break;
                case 4:
                    keeper.print_keeper();
                    break;
                case 5:
                    cout << "Введите имя файла для сохранения: ";
                    cin >> filename;
                    keeper.save(filename);
                    break;
                case 6:
                    cout << "Введите имя файла для загрузки: ";
                    cin >> filename;
                    keeper.load(filename);
                    break;
                case 7:
                    !keeper;
                    break;
                case 8:
                    *keeper;
                    break;
                case 9:
                    cout << "Выход\n";
                    return 0;
                default:
                    throw invalid_argument("Неверный ввод, попробуйте снова.\n");
            }
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
//g++ -std=c++11 main.cpp keeper.cpp sailboat.cpp ship.cpp speedboat.cpp submarine.cpp -o result -Wall