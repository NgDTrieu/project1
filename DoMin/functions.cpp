#include "functions.h"
#include "main.h"
#include "Console.h"

CauTrucBang CTBang;
CauTrucO **CTO;

//Vi tri con tro hien tai
COORD CViTriConTro;

// Su dung phim
bool BSuDungPhim = false;

// Toa do x, y ve bang
short SToaDoX;
short SToaDoY;

//Cap nhat trang thai choi game
bool BTrangThaiChoiGame = false;


void taoMang2ChieuDong(){
    CTO = new CauTrucO*[CTBang.SDong];
    for (int i = 0; i < CTBang.SDong; ++i)
        CTO[i] = new CauTrucO[CTBang.SCot];
}

void xoaMang2ChieuDong(){
    for (int i = 0; i < CTBang.SDong; ++i) delete[] CTO[i];
    delete[] CTO;
}

void luuToanDoBang(){
    SToaDoX = (ConsoleWidth/2) - CTBang.SDong;
    SToaDoY = ((ConsoleHeight - 6) - (CTBang.SCot))/2 + 4;
}

void khoiTao(short SDong, short SCot, short SSoBom){
    CTBang.SDong = SDong;
    CTBang.SCot = SCot;
    CTBang.SSoBom = SSoBom;
    CTBang.SSoODaMo = 0;
    CTBang.SSoCo = 0;

    taoMang2ChieuDong();
    taoBomNgauNhien();
    luuToanDoBang();
    CViTriConTro = {0, 0};
    BTrangThaiChoiGame = true;
    veBang();
    veTrangThaiChoiGame(1);

    //xuatBom();
    //xoaMang2ChieuDong();
}

short toaDoX(short SX){ return (SX * 2 + SToaDoX); }
short toaDoY(short SY){ return (SY + SToaDoY); }

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
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 12, "B ");
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
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 6, "Px");
        break;
    case 15:         //Cam Co dung
        setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, "B ");
        break;
    }
}
void veBang(){
    for (int i = 0; i < CTBang.SDong; ++i){
        for (int j = 0; j < CTBang.SCot; ++j){


            if (CTO[i][j].BCamCo) veO(j, i, 13);
            else if(CTO[i][j].SBomLanCan) veO(j, i, CTO[i][j].SBomLanCan);
            else if(CTO[i][j].BDaMo) veO(j, i, 0);
            else if ((i + j) % 2) veO(j, i, 11);
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

short demBomLanCan(short SX, short SY){
    short SDem = 0;
    for (int i = SX - 1; i <= SX + 1; ++i){
        for (int j = SY - 1; j <= SY + 1; ++j){
            if(i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
                continue;
            if(CTO[i][j].BCoBom) ++SDem;
        }
    }
    return SDem;
}

void moO(short SX, short SY){
    if(!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamCo){
        CTO[SX][SY].BDaMo = true;
        if(CTO[SX][SY].BCoBom){
            thua();
        }
        else{
            CTBang.SSoODaMo++;
            short SSoBomLanCan = demBomLanCan(SX, SY);
            if(SSoBomLanCan){
                CTO[SX][SY].SBomLanCan = SSoBomLanCan;
            }
            else{
                for (int i = SX - 1; i <= SX + 1; ++i){
                    for (int j = SY - 1; j <= SY + 1; ++j){
                        if(i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
                            continue;

                        //goi de quy
                        moO(i,j);
                    }
                }
            }
        }
    }
}

bool thongKeCo(){
    if(CTBang.SSoODaMo + CTBang.SSoBom == CTBang.SDong * CTBang.SCot) return true;
    return false;
}

void clickTrai(short SX, short SY){
    if(!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamCo){
        moO(SX, SY);
        if(BTrangThaiChoiGame){
            veBang();
            if(thongKeCo()) thang();
        }

    }
}



void thang(){
    BTrangThaiChoiGame = false;
    xoaMang2ChieuDong();
    deleteRow(4, 1);
    veTrangThaiChoiGame(2);     // Cap nhat trang thai la thang
}

void thua(){
    // Hien boom an va kiem tra cam co dung hay sai
    for (int i = 0; i < CTBang.SDong; ++i){
        for(int j = 0; j < CTBang.SCot; ++j){
            if(CTO[i][j].BCamCo){
                if(CTO[i][j].BCoBom){
                    veO(j, i, 15); // Cam co dung
                }
                else{
                    veO(j, i, 14);      // Cam co sai
                }
            }
            else{
                if(CTO[i][j].BCoBom){
                    veO(j, i, 9);   // Hien boom an
                }
            }
        }
    }
    BTrangThaiChoiGame = false;
    xoaMang2ChieuDong();
    deleteRow(4,1);
    veTrangThaiChoiGame(3);     // Cap nhat trang thai thua
}

void xuLyPhim(KEY_EVENT_RECORD key){
    if(key.bKeyDown){
        switch(key.wVirtualKeyCode)
        {
        case VK_UP:
            switch(STrang)
            {
            case 1: //menu chinh
                if(STongMuc == 4){
                    if(SViTriChon == 0){
                        SViTriChon = STongMuc - 1;
                    }
                    else{
                        SViTriChon -= 1;
                    }
                    veMenuChinh(SViTriChon);
                }
                break;
            case 2: //menu cap do
                if(STongMuc == 4){
                    if(SViTriChon == 0){
                        SViTriChon = STongMuc - 1;
                    }
                    else{
                        SViTriChon -= 1;
                    }
                    veMenuCapDo(SViTriChon);
                }
                break;
            case 3: // Trang choi game
                if(BTrangThaiChoiGame){
                    BSuDungPhim = true;
                    CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong - 1 : CViTriConTro.Y - 1);
                    veBang();
                }
                break;
            case 4: // Trang thua
                break;
            case 5: // Trang thang
                break;
            }

            break;
        case VK_DOWN:
            switch(STrang)
            {
            case 1: //menu chinh
                if(STongMuc == 4){
                    if(SViTriChon == STongMuc - 1){
                        SViTriChon = 0;
                    }
                    else{
                        SViTriChon += 1;
                    }
                    veMenuChinh(SViTriChon);
                }
                break;
            case 2: //menu cap do
                if(STongMuc == 4){
                    if(SViTriChon == STongMuc - 1){
                        SViTriChon = 0;
                    }
                    else{
                        SViTriChon += 1;
                    }
                    veMenuCapDo(SViTriChon);
                }
                break;
            case 3: // Trang choi game
                if(BTrangThaiChoiGame){
                    BSuDungPhim = true;
                    CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong - 1) ? 0 : CViTriConTro.Y + 1);
                    veBang();
                }
                break;
            case 4: // Trang thua
                break;
            case 5: // Trang thang
                break;
            }
            break;
        case VK_LEFT:
            if(BTrangThaiChoiGame){
                BSuDungPhim = true;
                CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
                veBang();
            }
            break;
        case VK_RIGHT:
            if(BTrangThaiChoiGame){
                BSuDungPhim = true;
                CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot - 1) ? 0 : CViTriConTro.X + 1);
                veBang();
            }
            break;
        case VK_RETURN: // Phim Enter
            switch(STrang)
            {
            case 1: //menu chinh
                if(SViTriChon == 0){
                    STrang = 2;
                    deleteRow(4, 5);
                    veMenuCapDo(0);
                }
                else if(SViTriChon == 1){

                }
                else if(SViTriChon == 2){

                }
                else{
                    exit(0);
                }
                break;
            case 2: //menu cap do
                if(SViTriChon == 0){
                    STrang = 3;
                    deleteRow(4, 10);
                    khoiTao(9, 9, 10);

                }
                else if(SViTriChon == 1){
                    STrang = 3;
                    deleteRow(4, 10);
                    khoiTao(16, 16, 40);
                }
                else if(SViTriChon == 2){
                    STrang = 3;
                    deleteRow(4, 10);
                    khoiTao(24, 24, 99);
                }
                else{
                    STrang = 1;
                    deleteRow(4, 10);
                    veMenuChinh(0);
                }
                break;
            case 4: // Trang thua
                break;
            case 5: // Trang thang
                break;
            }
            break;
        case VK_ESCAPE: //Phim thoat
            switch(STrang)
            {
            case 1: //menu chinh
                exit(0);
                break;
            case 2: //menu cap do
                STrang = 1;
                deleteRow(4,10);
                veMenuChinh(0);
                break;
            case 4: // Trang thua
                break;
            case 5: // Trang thang
                break;
            }
            break;
        case ClickTrai: //Phim z - Mo o
            clickTrai(CViTriConTro.Y, CViTriConTro.X);
            break;
        case ClickPhai: //Phim x - Danh dau co
            clickPhai(CViTriConTro.Y,CViTriConTro.X);
            break;
        }
    }
}


void xuLySuKien(){
    while(1){
        DWORD DWNumberOfEvents = 0;     // số lượng sự kiện đầu vào hiện có trong buffer của bảng điều khiển
        DWORD DWNumberOfEventsRead = 0; // số lượng sự kiện đầu vào đã được đọc từ buffer của bảng điều khiển

        HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE);  //Ham Window API, truu tuong hoa tbi dau vao cua bang dieu khien
        GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents);    //sử dụng HConsoleInput để truy cập và lấy số lượng sự kiện đầu vào đang chờ xử lý
                                                                            //trong buffer của bảng điều khiển, và lưu vào biến DWNumberOfEvents

        if (DWNumberOfEvents){
            INPUT_RECORD *IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];   // Con tro EventBuffer
            ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead);    //đọc các sự kiện đầu vào từ bảng điều khiển
                                                                                                        //thông qua HConsoleInput và lưu chúng vào mảng IREventBuffer.
                                                                                                        //DWNumberOfEventsRead lưu số lượng sự kiện đã đọc được.
            //Chay vong lap
            for(DWORD i = 0; i < DWNumberOfEvents; ++i){
                if(IREventBuffer[i].EventType == KEY_EVENT){
                    xuLyPhim(IREventBuffer[i].Event.KeyEvent);
                }
            }
        }
    }
}

void veTieuDeGame(){
    short i;
    for (i = 0; i < ConsoleWidth; ++i){
        printf("%c", 45);
    }
    setColorBGTextXY((ConsoleWidth/2) - 8, 1, 5, 0, "Game Do Min\n");
    setColor(7);
     for (i = 0; i < ConsoleWidth; ++i){
        printf("%c", 45);
    }
}

void veTrangThaiChoiGame(short STrangThai){
    setColorBGTextXY(1, 3, 15, 0, "Ban Do: %d * %d", CTBang.SDong, CTBang.SCot);
    setColorBGTextXY(1, 4, 15, 0, "So Bom: %d ", CTBang.SSoBom);
    if (STrangThai == 1)
        setColorBGTextXY(ConsoleWidth - 22, 4, 15, 0, "Trang Thai: %s ", "Dang Choi");
    if (STrangThai == 2)
        setColorBGTextXY(ConsoleWidth - 22, 4, 15, 0, "Trang Thai: %s ", "Thang");
    if (STrangThai == 3)
        setColorBGTextXY(ConsoleWidth - 22, 4, 15, 0, "Trang Thai: %s ", "Thua");
    std :: cout << std :: endl;
    setColor(7);
    short i;
     for (i = 0; i < ConsoleWidth; ++i){
        printf("%c", 45);
    }
}

void veMenuChinh(short SIndex){
    //Cap nhat lai vi tri dang chon va tong muc cuar menu
    SViTriChon = SIndex;
    STongMuc = 4;

    //Ve menu
    LPSTR STRTextMenuChinh = "  Game Moi  ";
    strlen(STRTextMenuChinh);
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 7, 15, (SIndex == 0) ? 2 : 0, STRTextMenuChinh);

    STRTextMenuChinh = "  Bang Diem  ";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 8, 15, (SIndex == 1) ? 2 : 0, STRTextMenuChinh);

    STRTextMenuChinh = "  Thong Tin  ";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 9, 15, (SIndex == 2) ? 2 : 0, STRTextMenuChinh);

    STRTextMenuChinh = "  Thoat  ";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 10, 15, (SIndex == 3) ? 2 : 0, STRTextMenuChinh);
}

void veMenuCapDo(short SIndex){
    //Cap nhat lai vi tri dang chon va tong muc cuar menu
    SViTriChon = SIndex;
    STongMuc = 4;

    //Ve menu
    LPSTR STRTextMenuChinh = "  Chon Cap Do";
    strlen(STRTextMenuChinh);
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 4, 1, 0, STRTextMenuChinh);

    STRTextMenuChinh = "  De (Bang 9x9 va 10 boom)";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 7, 15, (SIndex == 0) ? 2 : 0, STRTextMenuChinh);

    STRTextMenuChinh = "  Trung Binh (Bang 16x16 va 40 boom)  ";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 8, 15, (SIndex == 1) ? 2 : 0, STRTextMenuChinh);

    STRTextMenuChinh = "  Kho (Bang 24x24 vaf 99 boom)  ";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 9, 15, (SIndex == 2) ? 2 : 0, STRTextMenuChinh);

    STRTextMenuChinh = "  Thoat  ";
    setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRTextMenuChinh) / 2 + 4), 10, 15, (SIndex == 3) ? 2 : 0, STRTextMenuChinh);
}
