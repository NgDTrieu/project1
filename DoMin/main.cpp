#include "main.h"
#include "Console.h"
#include "functions.h"

using namespace std;

int main()
{
    khoiTao(9, 9, 10);
    Cursor(false);              //An con tro, ham lay tu Console
    xuLySuKien();
    cout << endl << endl;
    system("pause");
    return 0;
}
