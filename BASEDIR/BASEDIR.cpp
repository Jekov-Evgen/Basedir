#include <C:\Users\Женя\source\repos\BASEDIR\BASEDIR\Data.h>

int actionSelection = 0;

void Menu() {
    std::cout << "Добро пожаловать в БД" << std::endl;
    std::cout << "Выход из программы: 0" << std::endl;
    std::cout << "Ввод данных: 1" << std::endl;
    std::cout << "Вывод данных: 2" << std::endl;
    std::cout << "Изменение данных: 3" << std::endl;
    std::cout << "Добавление данных: 4" << std::endl;
    std::cout << "Удаление данных: 5" << std::endl;
    std::cout << "Сортировка данных: 6" << std::endl;
    std::cout << "Сохранение данных: 7" << std::endl;
    std::cout << "Введите цифру для выбора: ";
    std::cin >> actionSelection;

    while (true) {
        if (std::cin.fail() || actionSelection < 0 || actionSelection > 7) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');  
            std::cout << "Вы ввели неверное значение. Пожалуйста, введите цифру от 0 до 7: ";
            std::cin >> actionSelection;
        }
        else {
            break;
        }
    }
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();

    int execution = 0;
    std::string fileName = "";

    int arraySize = 0;
    FieldBaseDir* arrayData = new FieldBaseDir[arraySize];

    while (actionSelection != 0) {
        switch (actionSelection) {
        case 1:
            system("cls");

            std::cout << "Если вы хотите ввести данные вручную нажмите 1" << std::endl;
            std::cout << "Если вы хотите считать их файла нажмите 2" << std::endl;
            std::cin >> execution;

            system("cls");

            if (execution == 1) {
                FieldBaseDirEntry(arrayData, arraySize);
            }
            else {
                std::cout << "Введите название файла из которого считывать: ";
                std::cin >> fileName;

                FieldBaseDirReading(arrayData, arraySize, fileName);
            }

            system("pause");
            system("cls");

            Menu();

            break;
        case 2:
            system("cls");

            if (arraySize != 0) {
                FieldBaseDirPrint(arrayData, arraySize);
            }
            else {
                std::cout << "Нет записей в БД" << std::endl;
            }

            system("pause");
            system("cls");

            Menu();

            break;
        case 3:
            system("cls");

            if (arraySize != 0) {
                FieldBaseDirChange(arrayData, arraySize);
            }
            else {
                std::cout << "Нет записей в БД" << std::endl;
            }

            system("pause");
            system("cls");

            Menu();

            break;
        case 4:
            system("cls");

            if (arraySize != 0) {
                FieldBaseDirAddData(arrayData, arraySize);
            }
            else {
                std::cout << "Нет записей в БД" << std::endl;
            }

            system("pause");
            system("cls");

            Menu();

            break;
        case 5:
            system("cls");

            if (arraySize != 0) {
                FieldBaseDirDeleteData(arrayData, arraySize);
            }
            else {
                std::cout << "Нет записей в БД" << std::endl;
            }

            system("pause");
            system("cls");

            Menu();

            break;
        case 6:
            system("cls");

            if (arraySize != 0) {
                FieldBaseDirSorting(arrayData, arraySize);
            }
            else {
                std::cout << "Нет записей в БД" << std::endl;
            }

            system("pause");
            system("cls");

            Menu();

            break;
        case 7:
            system("cls");

            if (arraySize != 0) {
                std::cout << "Введите название файла: ";
                std::cin >> fileName;

                FieldBaseDirSaveData(arrayData, arraySize, fileName);
            }
            else {
                std::cout << "Нет записей в БД" << std::endl;
            }

            system("pause");
            system("cls");

            Menu();

            break;
        default:
            std::cout << "Ввод был неверным!" << std::endl;
            system("cls");

            Menu();

            break;
        }
    }

    system("cls");
    std::cout << "Работа была завершена!" << std::endl;
    system("pause");

    delete[] arrayData;

    return 0;
}