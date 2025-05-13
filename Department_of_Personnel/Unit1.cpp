#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int Keyindex[35];
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)

{
    if(!FileExists("Department_of_Personnel.fdb")){
        MessageBoxA(0,"База данных в текущей папке не найдена","Проверка базы данных",MB_OK|MB_ICONSTOP);
        Application->Terminate();
    }else {
        for(int i=0; i<35; i++)
        {   Keyindex[i]=0;
        }
    }
}
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    if(Edit1->Text!="" && Edit2->Text!=""){
        int *pswrd;
        pswrd=new int[Edit2->Text.Length()];//массив для проведения 2-го и 3-его этапа шифрования
        for(int i=0;i<Edit2->Text.Length();i++){
             pswrd[i]=Edit2->Text[i+1];
        }
        for(int i=0; i<Edit2->Text.Length(); i++) {                 //начало [ 1 - этап ]
            pswrd[i]=pswrd[i]*5-159; //каждый элемент умножаем на 5 и вычитаем 159
        }//конец [ 1 - этап ]
        String encds="";
        for(int i=0; i<Edit2->Text.Length(); i++) {    //начало [ 2 - этап ]    &&   начало [ 3 - этап ]
            int fl=pswrd[i]%50;         //конец [ 2 - этап ]    //остаток меньше 50 получен
            fl+=7;    fl*=3;
            String ansi=pswrd[i];           //число, полученное с 1-го этапа объединяем с остатком, полученное со 2-го этапа
            ansi+=fl;
            pswrd[i]=StrToInt(ansi);
            pswrd[i]*=9;  //и умножаем  на 9
            encds+=pswrd[i];          //объединяем в общую строку для дальнейшей проверки правильного ввода пароли
        }//конец [ 3 - этап ]
        DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where LOGIN = '"+Edit1->Text+"' and PASWORD = '"+encds+"'");
        encds="";
        if(DataModule2->IBDataSet_AUTORIZATION->RecordCount==1) {             //правильный ввод логина и пароли
            if(CheckBox1->Checked) {
                if(DataModule2->IBDataSet_AUTORIZATION->FieldByName("ACCESS_LEVEL")->AsInteger==0) {
                    MessageBoxA(Handle,"Успешная авторизация!","Авторизация",MB_OK|MB_ICONINFORMATION);
                    Form3->Show();
                    Form3->Caption="Отдел кадров - Админстратор";
                    Form3->MB_A->Caption="Админстратор";
                    Form3->MB_LPUA->Visible=true;
                    Hide();
                }else MessageBoxA(Handle,"Не правильный ввод логина или пароли!","Авторизация",MB_OK|MB_ICONSTOP);
            }else if(!CheckBox1->Checked){
                if(DataModule2->IBDataSet_AUTORIZATION->FieldByName("ACCESS_LEVEL")->AsInteger==1) {
                    MessageBoxA(Handle,"Успешная авторизация!","Авторизация",MB_OK|MB_ICONINFORMATION);
                    Form3->MB_A->Caption="Пользователь";
                    Form3->MB_LPUA->Visible=false;
                    Form3->Show();
                    Form3->Caption="Отдел кадров - сотрудник "+DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
                    Hide();
                }else MessageBoxA(Handle,"Не правильный ввод логина или пароли или обратитесь к администратору!","Авторизация",MB_OK|MB_ICONSTOP);
            }
        }else MessageBoxA(Handle,"Не правильный ввод логина или пароли или обратитесь к администратору!","Авторизация",MB_OK|MB_ICONSTOP);//не правильный ввод логина или пароли
    }else MessageBoxA(Handle,"Поля ввода логин и пароль должны быть заполнены!","Авторизация",MB_OK|MB_ICONEXCLAMATION);//проверка полей логина и пароли на пустоту
}
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Edit2->PasswordChar=0;
    Edit2->Font->Size=11;
    Edit2->Height=25;
}
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Edit2->PasswordChar='*';
    Edit2->Font->Size=21;
    Edit2->Height=25;
    Edit2->SelStart=Edit2->Text.Length();
}
void __fastcall TForm1::FormShow(TObject *Sender)
{
    Edit2->Height=25;
    /*Edit1->Clear();
    Edit2->Clear();
    CheckBox1->Checked=false; */
}

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
    if(Key==8 || Key>=32 && Key<126){
        Key=Key;
    }else{
        Key=0;
    }
}