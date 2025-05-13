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
        MessageBoxA(0,"���� ������ � ������� ����� �� �������","�������� ���� ������",MB_OK|MB_ICONSTOP);
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
        pswrd=new int[Edit2->Text.Length()];//������ ��� ���������� 2-�� � 3-��� ����� ����������
        for(int i=0;i<Edit2->Text.Length();i++){
             pswrd[i]=Edit2->Text[i+1];
        }
        for(int i=0; i<Edit2->Text.Length(); i++) {                 //������ [ 1 - ���� ]
            pswrd[i]=pswrd[i]*5-159; //������ ������� �������� �� 5 � �������� 159
        }//����� [ 1 - ���� ]
        String encds="";
        for(int i=0; i<Edit2->Text.Length(); i++) {    //������ [ 2 - ���� ]    &&   ������ [ 3 - ���� ]
            int fl=pswrd[i]%50;         //����� [ 2 - ���� ]    //������� ������ 50 �������
            fl+=7;    fl*=3;
            String ansi=pswrd[i];           //�����, ���������� � 1-�� ����� ���������� � ��������, ���������� �� 2-�� �����
            ansi+=fl;
            pswrd[i]=StrToInt(ansi);
            pswrd[i]*=9;  //� ��������  �� 9
            encds+=pswrd[i];          //���������� � ����� ������ ��� ���������� �������� ����������� ����� ������
        }//����� [ 3 - ���� ]
        DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where LOGIN = '"+Edit1->Text+"' and PASWORD = '"+encds+"'");
        encds="";
        if(DataModule2->IBDataSet_AUTORIZATION->RecordCount==1) {             //���������� ���� ������ � ������
            if(CheckBox1->Checked) {
                if(DataModule2->IBDataSet_AUTORIZATION->FieldByName("ACCESS_LEVEL")->AsInteger==0) {
                    MessageBoxA(Handle,"�������� �����������!","�����������",MB_OK|MB_ICONINFORMATION);
                    Form3->Show();
                    Form3->Caption="����� ������ - ������������";
                    Form3->MB_A->Caption="������������";
                    Form3->MB_LPUA->Visible=true;
                    Hide();
                }else MessageBoxA(Handle,"�� ���������� ���� ������ ��� ������!","�����������",MB_OK|MB_ICONSTOP);
            }else if(!CheckBox1->Checked){
                if(DataModule2->IBDataSet_AUTORIZATION->FieldByName("ACCESS_LEVEL")->AsInteger==1) {
                    MessageBoxA(Handle,"�������� �����������!","�����������",MB_OK|MB_ICONINFORMATION);
                    Form3->MB_A->Caption="������������";
                    Form3->MB_LPUA->Visible=false;
                    Form3->Show();
                    Form3->Caption="����� ������ - ��������� "+DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
                    Hide();
                }else MessageBoxA(Handle,"�� ���������� ���� ������ ��� ������ ��� ���������� � ��������������!","�����������",MB_OK|MB_ICONSTOP);
            }
        }else MessageBoxA(Handle,"�� ���������� ���� ������ ��� ������ ��� ���������� � ��������������!","�����������",MB_OK|MB_ICONSTOP);//�� ���������� ���� ������ ��� ������
    }else MessageBoxA(Handle,"���� ����� ����� � ������ ������ ���� ���������!","�����������",MB_OK|MB_ICONEXCLAMATION);//�������� ����� ������ � ������ �� �������
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