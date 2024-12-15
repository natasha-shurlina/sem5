#include "container.h"
#include "student.h"
#include "check.h"
#include "sentense_filter.h"

void display_menu() {
    cout << "\n===== Меню управления группами =====" << endl;
    cout << "1. Добавить группу" << endl;
    cout << "2. Удалить группу" << endl;
    cout << "3. Редактировать данные группы" << endl;
    cout << "4. Вывести все группы" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите Ваш выбор: ";
}

int students_program() {
    Container container; 
    int choice;

    while (true) {
        display_menu();
        choice = check_input();

        switch (choice) {
            case 1: {
                int group_number, subject_count;
                cout << "Введите номер группы: ";
                group_number = check_input();
                cout << "Введите номер предмета: ";
                subject_count = check_input();

                string* subjects = new string[subject_count];
                cout << "Введите назввание предмета:" << endl;
                for (int i = 0; i < subject_count; ++i) {
                    cin >> subjects[i];
                }
                cout << "Введите индекс для добавления:\n";
                int index = check_input();

                Group* new_group = new Group(0.0, subjects, group_number, subject_count, 0);
                container.add_group(new_group, index - 1);
                cout << "Группа успешно добавлена." << endl;

                break;
            }
            case 2: {
                cout << "Введите индекс группы для удаления: ";
                int index = check_input();
                try {
                    container.delete_group(index - 1);
                    cout << "Группа успешно удалена." << endl;
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 3: {
                cout << "Введите индекс группы для редактирования: ";
                int index = check_input();
                try {
                    container.edit_group(index - 1);
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 4: {
                container.display_groups();
                break;
            }
            case 0: {
                cout << "Выход из программы." << endl;
                return 0;
            }
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    }
}
int words_program() {
    try {
        int choice;
        cout << "Выберите источник (1 - текстовая строка, 2 - файл): ";
        if (!(cin >> choice)) {
            throw invalid_argument("Ошибка: Неверный источник.");
        }

        if (choice == 1) {
            cin.ignore();
            char text[8192];
            cout << "Введите текст: ";
            cin.getline(text, sizeof(text));

            if (cin.fail()) {
                throw overflow_error("Ошибка: Превышена максимальная длина текста.");
            }

            SentenceFilter filter(text, true);
            filter.result();
        } else if (choice == 2) {
            char filename[256];
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Ошибка: Файл не найден или не может быть открыт.");
            }
            file.close();
            SentenceFilter filter(filename);
            filter.result();
        } else {
            throw out_of_range("Оибка: Выбранный источник не соответствует.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (const overflow_error& e) {
        cerr << e.what() << endl;
        return 2;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 3;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << "Произошла неизвестная ошибка." << endl;
        return -1;
    }
    return 0;
}

int main() {
    int choice;
    while (true) {
        cout << "Select task type:" << endl;
        cout << "1 - Standard streams" << endl;
        cout << "2 - File and text streams" << endl;
        cout << "3 - Exit" << endl;
        choice = check_input();

        switch (choice) {
            case 1:
                students_program();
                break;
            case 2:
                words_program();
                break;
            case 3:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }
}
