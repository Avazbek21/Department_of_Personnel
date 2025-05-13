#include <vcl.h>
#pragma hdrstop
#include "Unit7.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit8.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
bool lp=false,  //false - проверка логина и пароли, true=сохранить изменение логина и пароли и вернуться на Form3 - "Отдел кадров"
     bb=false;  //false - закрыть программу
int idlp=0, countch=5;
__fastcall TForm7::TForm7(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm7::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Edit2->PasswordChar=0;
    Edit2->Font->Size=11;
    Edit2->Height=25;
}
void __fastcall TForm7::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Edit2->PasswordChar='*';
    Edit2->Font->Size=21;
    Edit2->Height=25;
    Edit2->SelStart=Edit2->Text.Length();
}
void __fastcall TForm7::BitBtn_OkClick(TObject *Sender)
{
    if(Edit1->Text!="" && Edit2->Text!=""){
        int *pswrd;
        pswrd=new int[Edit2->Text.Length()];//массив для проведения 2-го и 3-его этапа шифрования
        for(int i=0;i<Edit2->Text.Length();i++)
        {   pswrd[i]=Edit2->Text[i+1];
        }
        for(int i=0; i<Edit2->Text.Length(); i++)                  //начало [ 1 - этап ]
        {   pswrd[i]=pswrd[i]*5-159; //каждый элемент умножаем на 5 и вычитаем 159
        }//конец [ 1 - этап ]
        String encds="";
        for(int i=0; i<Edit2->Text.Length(); i++)     //начало [ 2 - этап ]    &&   начало [ 3 - этап ]
        {   int fl=pswrd[i]%50;         //конец [ 2 - этап ]    //остаток меньше 50 получен
            fl+=7;    fl*=3;
            String ansi=pswrd[i];           //число, полученное с 1-го этапа объединяем с остатком, полученное со 2-го этапа
            ansi+=fl;
            pswrd[i]=StrToInt(ansi);
            pswrd[i]*=9;  //и умножаем  на 9
            encds+=pswrd[i];          //объединяем в общую строку для дальнейшей проверки правильного ввода пароли
        }//конец [ 3 - этап ]
        if(lp==false){
            if(Edit1->Text==DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString && encds==DataModule2->IBDataSet_AUTORIZATION->FieldByName("PASWORD")->AsString){    //правильный ввод логина и пароли
                idlp=DataModule2->IBDataSet_AUTORIZATION->FieldByName("ID")->AsInteger;
                Hide();    countch=5;
                MessageBoxA(Handle,"Правильность логина и пароли подтверждена!","Проверка логина и пароли",MB_OK|MB_ICONINFORMATION);
                if(lporU==false){
                    lp=true;    Show();    Caption="Новый логин и пароль";
                    BitBtn_Ok->Caption="Сохранить";     BitBtn_Ok->Left=100;
                    BitBtn_Ok->Width=115;
                }else{
                    bb=true; Form8->Show(); Close();
                }
            }else{
                countch--;
                String mss="Не правильный ввод логина или пароли! Попытки: "+IntToStr(countch)+'.';
                MessageBoxA(Handle,mss.c_str(),"Авторизация",MB_OK);
            }
        }else if(lp==true){
            DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ACCESS_LEVEL=1 and ID!="+idlp+" and LOGIN='"+Edit1->Text+"'");
            if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
                MessageBoxA(Handle,"Пользователь с таким логином есть базе данных!","Авторизация",MB_OK|MB_ICONEXCLAMATION);
            }else{
                DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ID="+idlp);
                DataModule2->IBDataSet_AUTORIZATION->Edit();
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString=Edit1->Text;
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("PASWORD")->AsString=encds;
                DataModule2->IBDataSet_AUTORIZATION->Post();
                MessageBoxA(Handle,"Изменение успешно завершено!","Авторизация",MB_OK|MB_ICONINFORMATION);
                if(Form3->MB_LPUA->Visible==false){
                    Form3->Caption="Отдел кадров - сотрудник "+DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
                }
                Caption="Проверка логина и пароли";    BitBtn_Ok->Caption="Подтвердить";
                BitBtn_Ok->Left=75;    BitBtn_Ok->Width=155;
                bb=true; Close();
            }

        }
        encds="";
        if(countch==0){
            MessageBoxA(Handle,"Вы не регистрированы! Программа автоматически закроется!","Закрытие программы",MB_OK|MB_ICONHAND);
            Close();
        }
    }else MessageBoxA(Handle,"Поля ввода логин и пароль должны быть заполнены!","Авторизация",MB_OK|MB_ICONHAND);//проверка полей логина и пароли на пустоту
}
void __fastcall TForm7::FormShow(TObject *Sender)
{
     Edit2->Height=25;
    /*Edit1->Clear();
    Edit2->Clear();*/
}
void __fastcall TForm7::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(bb==false) {
        Application->Terminate();
    }else {
        if(lporU==false){
            Form3->Show();
        }bb=false;
    }lp=false;
}
