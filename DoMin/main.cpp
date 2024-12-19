#include "main.h"
#include "Console.h"
#include "functions.h"
#include <thread>
#include <chrono>

using namespace std;

//Trang, Vi tri dang chon, tong muc
short STrang, SViTriChon, STongMuc;

int main()
{
    resizeConsole(ConsoleWidth, ConsoleHeight); // Thay đổi kích thước màn hình console
    SetConsoleTitle("Game Do Min"); // Đặt tiêu đề game
    veTieuDeGame();
    veMenuChinh(0);
    STrang = 1;
    Cursor(false);         //An con tro, ham lay tu Console
    while(1){
        xuLySuKien();
    }
    cout << endl << endl;
    system("pause");
    return 0;
}
