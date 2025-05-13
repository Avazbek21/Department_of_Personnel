#include <vcl.h>
#pragma hdrstop
#include "Unit7.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit8.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
bool lp=false,  //false - �������� ������ � ������, true=��������� ��������� ������ � ������ � ��������� �� Form3 - "����� ������"
     bb=false;  //false - ������� ���������
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
        pswrd=new int[Edit2->Text.Length()];//������ ��� ���������� 2-�� � 3-��� ����� ����������
        for(int i=0;i<Edit2->Text.Length();i++)
        {   pswrd[i]=Edit2->Text[i+1];
        }
        for(int i=0; i<Edit2->Text.Length(); i++)                  //������ [ 1 - ���� ]
        {   pswrd[i]=pswrd[i]*5-159; //������ ������� �������� �� 5 � �������� 159
        }//����� [ 1 - ���� ]
        String encds="";
        for(int i=0; i<Edit2->Text.Length(); i++)     //������ [ 2 - ���� ]    &&   ������ [ 3 - ���� ]
        {   int fl=pswrd[i]%50;         //����� [ 2 - ���� ]    //������� ������ 50 �������
            fl+=7;    fl*=3;
            String ansi=pswrd[i];           //�����, ���������� � 1-�� ����� ���������� � ��������, ���������� �� 2-�� �����
            ansi+=fl;
            pswrd[i]=StrToInt(ansi);
            pswrd[i]*=9;  //� ��������  �� 9
            encds+=pswrd[i];          //���������� � ����� ������ ��� ���������� �������� ����������� ����� ������
        }//����� [ 3 - ���� ]
        if(lp==false){
            if(Edit1->Text==DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString && encds==DataModule2->IBDataSet_AUTORIZATION->FieldByName("PASWORD")->AsString){    //���������� ���� ������ � ������
                idlp=DataModule2->IBDataSet_AUTORIZATION->FieldByName("ID")->AsInteger;
                Hide();    countch=5;
                MessageBoxA(Handle,"������������ ������ � ������ ������������!","�������� ������ � ������",MB_OK|MB_ICONINFORMATION);
                if(lporU==false){
                    lp=true;    Show();    Caption="����� ����� � ������";
                    BitBtn_Ok->Caption="���������";     BitBtn_Ok->Left=100;
                    BitBtn_Ok->Width=115;
                }else{
                    bb=true; Form8->Show(); Close();
                }
            }else{
                countch--;
                String mss="�� ���������� ���� ������ ��� ������! �������: "+IntToStr(countch)+'.';
                MessageBoxA(Handle,mss.c_str(),"�����������",MB_OK);
            }
        }else if(lp==true){
            DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ACCESS_LEVEL=1 and ID!="+idlp+" and LOGIN='"+Edit1->Text+"'");
            if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
                MessageBoxA(Handle,"������������ � ����� ������� ���� ���� ������!","�����������",MB_OK|MB_ICONEXCLAMATION);
            }else{
                DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ID="+idlp);
                DataModule2->IBDataSet_AUTORIZATION->Edit();
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString=Edit1->Text;
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("PASWORD")->AsString=encds;
                DataModule2->IBDataSet_AUTORIZATION->Post();
                MessageBoxA(Handle,"��������� ������� ���������!","�����������",MB_OK|MB_ICONINFORMATION);
                if(Form3->MB_LPUA->Visible==false){
                    Form3->Caption="����� ������ - ��������� "+DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
                }
                Caption="�������� ������ � ������";    BitBtn_Ok->Caption="�����������";
                BitBtn_Ok->Left=75;    BitBtn_Ok->Width=155;
                bb=true; Close();
            }

        }
        encds="";
        if(countch==0){
            MessageBoxA(Handle,"�� �� ��������������! ��������� ������������� ���������!","�������� ���������",MB_OK|MB_ICONHAND);
            Close();
        }
    }else MessageBoxA(Handle,"���� ����� ����� � ������ ������ ���� ���������!","�����������",MB_OK|MB_ICONHAND);//�������� ����� ������ � ������ �� �������
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
