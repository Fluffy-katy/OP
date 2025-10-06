#include "Windows.h"
#include "Utils.h"
#include "Manager.h"

using namespace std;

int main() {

    std::locale::global(std::locale("rus_rus.866"));
    wcin.imbue(std::locale());
    wcout.imbue(std::locale());

    Manager m;

    while (1) {
        system("cls");
        wcout << L"Выберите действие:" << endl;
        wcout << L"1. Ввести данные о товаре" << endl;
        wcout << L"2. Ввести данные об электронике" << endl;
        wcout << L"3. Вывести список товаров" << endl;
        wcout << L"4. Очистить список товаров" << endl;
        wcout << L"5. Сохранить список товаров" << endl;
        wcout << L"6. Загрузить список товаров из файла" << endl;
        wcout << L"0. Выход" << endl;


        switch (GetCorrectNumber(0, 6)) {
        case 0:
            return 0;
        case 1:
        {
            m.createProduct();
            break;
        }
        case 2:
             m.createElectronics();
            break; 
        case 3:
            m.showProducts();
             break;
        case 4:
            m.clearProducts();
            break;
        case 5:
        {
            m.saveProducts();
            break;
        }
        case 6:
            m.loadProducts();
            break;
        default:
            break;
        }
        system("pause");
    };

    return 0;
}
