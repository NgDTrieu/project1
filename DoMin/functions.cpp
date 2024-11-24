#include "functions.h"
#include "main.h"
#include "Console.h"

CauTrucBang CTBang;
CauTrucO **CTO;

void taoMang2ChieuDong(){
    CTO = new CauTrucO*[CTBang.SDong];
    for (int i = 0; i < CTBang.SDong; ++i)
        CTO[i] = new CauTrucO[CTBang.SCot];
}

void xoaMang2ChieuDong(){
    for (int i = 0; i < CTBang.SDong; ++i) delete[] CTO[i];
    delete[] CTO;
}

void khoiTao(short SDong, short SCot, SSoBom){
    CTBang.SDong = SDong;
    CTBang.SCot = SCot;
    CTBang.SSoBom = SSoBom;
    CTBang.SSoODaMo = 0;
    CTBang.SSoCo = 0;

    taoMang2ChieuDong();


    xoaMang2ChieuDong();
}

short toaDoX(short SX) return (SX * 2);
short toaDoY(short SY) return (SY);

void veO(short SX, short SY, short SKieu){
    switch (Skieu)
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
        for (int i = 0; i < CTBang.SCot; j++){
            veO(j, i, 1);
        }
    }
}
