#include "main.h"
#include "Console.h"
#include "functions.h"

using namespace std;

//Trang, Vi tri dang chon, tong muc
short STrang, SViTriChon, STongMuc;

int main()
{
    resizeConsole(ConsoleWidth, ConsoleHeight); // Thay đổi kích thước màn hình console

    SetConsoleTitle("Game Do Min"); // Đặt tiêu đề game
    veTieuDeGame();
    //khoiTao(9, 9, 10);
    //veTrangThaiChoiGame(1);
    veMenuChinh(0);
    STrang = 1;


    Cursor(false);              //An con tro, ham lay tu Console
    xuLySuKien();
    cout << endl << endl;
    system("pause");
    return 0;
}
