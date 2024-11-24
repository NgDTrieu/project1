#include "functions.h"
#include "main.h"

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
