#include "functions.h"
#include "main.h"
#include "Console.h"

CauTrucBang CTBang;
CauTrucO **CTO;

COORD CViTriConTro;

bool BSuDungPhim = false;

void taoMang2ChieuDong(){
    CTO = new CauTrucO*[CTBang.SDong];
    for (int i = 0; i < CTBang.SDong; ++i)
        CTO[i] = new CauTrucO[CTBang.SCot];
}

void xoaMang2ChieuDong(){
    for (int i = 0; i < CTBang.SDong; ++i) delete[] CTO[i];
    delete[] CTO;
}

void khoiTao(short SDong, short SCot, short SSoBom){
    CTBang.SDong = SDong;
    CTBang.SCot = SCot;
    CTBang.SSoBom = SSoBom;
    CTBang.SSoODaMo = 0;
    CTBang.SSoCo = 0;

    taoMang2ChieuDong();
    veBang();
    taoBomNgauNhien();
    //xuatBom();
    xoaMang2ChieuDong();
}

short toaDoX(short SX){ return (SX * 2); }
short toaDoY(short SY){ return (SY); }

void veO(short SX, short SY, short SKieu){
    switch (SKieu)
    {
    case 0:        //O mau xanh la
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 10, "  ");
        break;
    case 1:         //Chu xanh duong, nen trang 1->8
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 9, 15, "1 ");
        break;
    case 2:         //Chu xanh la
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 2, 15, "2 ");
        break;
    case 3:         //Chu do
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 15, "3 ");
        break;
    case 4:         //Chu xanh duong dam
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 1, 15, "4 ");
        break;
    case 5:         //Chu do dam
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 4, 15, "5 ");
        break;
    case 6:         //Chu xanh dam
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 3, 15, "6 ");
        break;
    case 7:         //Chu den
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 15, "7 ");
        break;
    case 8:         //Chu hong
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 13, 15, "8 ");
        break;
    case 9:         //O Bom
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, "B ");
        break;
    case 10:         //O chan
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 8, "  ");
        break;
    case 11:         //Chu O le
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 7, "  ");
        break;
    case 12:         //O co con tro
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 13, "  ");
        break;
    case 13:         //Cam Co
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, "P ");
        break;
    case 14:         //Cam Co sai
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 16, "Px");
        break;
    case 15:         //Cam Co dung
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, "B ");
        break;
    }
}
void veBang(){
    for (int i = 0; i < CTBang.SDong; ++i){
        for (int j = 0; j < CTBang.SCot; ++j){

            if(CTO[i][j].BCamCo) veO(j, i, 13);
            if ((i + j) % 2) veO(j, i, 11);
            else veO(j, i, 10);

            if(BSuDungPhim){
                veO(CViTriConTro.X, CViTriConTro.Y, 12);
            }


        }
    }
}

void taoBomNgauNhien(){
    short SSoBom = CTBang.SSoBom;
    short SI, SJ;                   //SI, SJ la dong, cot chua bom
    srand(time(NULL));
    while (SSoBom){
        SI = rand() % CTBang.SDong;
        SJ = rand() % CTBang.SCot;
        if (CTO[SI][SJ].BCoBom) continue;
        CTO[SI][SJ].BCoBom = true;
        --SSoBom;
    }
}

void xuatBom(){
    for(int i = 0; i < CTBang.SDong; ++i){
        for(int j = 0; j < CTBang.SCot; ++j){
            std::cout << CTO[i][j].BCoBom << " ";
        }
        std::cout << std::endl;
    }
}

void clickPhai(short SX, short SY){ //CamCo
    if(!CTO[SX][SY].BDaMo){
        if(CTO[SX][SY].BCamCo){
            CTO[SX][SY].BCamCo = false;
            CTBang.SSoCo--;
        }
        else{
            CTO[SX][SY].BCamCo = true;
            CTBang.SSoCo++;
        }
    }
    veBang();
}

void xuLyPhim(KEY_EVENT_RECORD key){
    if(key.bKeyDown){
        switch(key.wVirtualKeyCode)
        {
        case VK_UP:
            BSuDungPhim = true;
            CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong - 1 : CViTriConTro.Y - 1);
            veBang();
            break;
        case VK_DOWN:
            BSuDungPhim = true;
            CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong - 1) ? 0 : CViTriConTro.Y + 1);
            veBang();
            break;
        case VK_LEFT:
            BSuDungPhim = true;
            CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
            veBang();
            break;
        case VK_RIGHT:
            BSuDungPhim = true;
            CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot - 1) ? 0 : CViTriConTro.X + 1);
            veBang();
            break;
        case VK_RETURN: // Phim Enter
            break;
        case VK_ESCAPE: //Phim thoat
            break;
        case ClickTrai: //Phim z - Mo o
            break;
        case ClickPhai: //Phim x - Danh dau co
            clickPhai(CViTriConTro.Y,CViTriConTro.X);
            break;
        }
    }
}

void xuLySuKien(){
    while(1){
        DWORD DWNumberOfEvents = 0;     // Luu skien hien tai
        DWORD DWNumberOfEventsRead = 0; // Luu lai so luong su kien da duoc loc

        HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE);  //Thiet bi dau vao
        GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents); // Dat su kien dau vao cua giao dien cho bien DWNumberOfEvents

        if (DWNumberOfEvents){
            INPUT_RECORD *IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];   // Con tro EventBuffer
            ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead); // Dat cac su kien dươc luu vao con tro EventBuffer
            //Chay vong lap
            for(DWORD i = 0; i < DWNumberOfEvents; ++i){
                if(IREventBuffer[i].EventType == KEY_EVENT){
                    xuLyPhim(IREventBuffer[i].Event.KeyEvent);
                }
            }
        }
    }
}
