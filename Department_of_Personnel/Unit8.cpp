#include <vcl.h>
#pragma hdrstop
#include "Unit8.h"
#include "Unit2.h"
#include "Unit7.h"
#include "Unit3.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
__fastcall TForm8::TForm8(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm8::FormShow(TObject *Sender)
{
    DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, "select *from AUTORIZATION where ACCESS_LEVEL>0");
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
    }
}
void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(MessageBoxA(Handle,"����� ������� �� ����� '����� ������', ������� '��', ���� '���', �� ��������� ��������� ������.","������� ��� ����������",MB_YESNO|MB_ICONQUESTION)==IDYES){
        DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ACCESS_LEVEL=0");
        Form3->Show();
    }else{
        Application->Terminate();
    }
}
void __fastcall TForm8::SB_UserFirstClick(TObject *Sender)
{
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        DataModule2->IBDataSet_AUTORIZATION->First();
        Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
    }
}
void __fastcall TForm8::SB_UserPriorClick(TObject *Sender)
{
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        DataModule2->IBDataSet_AUTORIZATION->Prior();
        Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
    }
}
void __fastcall TForm8::SB_UserNextClick(TObject *Sender)
{
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        DataModule2->IBDataSet_AUTORIZATION->Next();
        Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
    }
}
void __fastcall TForm8::SB_UserLastClick(TObject *Sender)
{
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        DataModule2->IBDataSet_AUTORIZATION->Last();
        Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
    }
}
void __fastcall TForm8::MB_UserInsertClick(TObject *Sender)
{
    if(MB_UserInsert->Checked==true){
        Edit1->Clear();    Edit1->ReadOnly=false;    Label2->Visible=true;
        Edit2->Visible=true;            BitBtn_Post->Visible=true;
        BitBtn_Cancel->Visible=true;    SB_UserFirst->Visible=false;
        SB_UserPrior->Visible=false;    SB_UserNext->Visible=false;
        SB_UserLast->Visible=false;     SB_UserInsert->Visible=false;
        SB_UserEdit->Visible=false;     SB_UserDelete->Visible=false;
        MB_UserEdit->Enabled=false;     MB_UserDelete->Enabled=false;
    }else{
        Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
        Edit1->ReadOnly=true;    Label2->Visible=false;    Edit2->Visible=false;
        BitBtn_Post->Visible=false;    BitBtn_Cancel->Visible=false;
        SB_UserFirst->Visible=true;    SB_UserPrior->Visible=true;
        SB_UserNext->Visible=true;     SB_UserLast->Visible=true;
        SB_UserInsert->Visible=true;   SB_UserEdit->Visible=true;
        SB_UserDelete->Visible=true;
        MB_UserEdit->Enabled=true;     MB_UserDelete->Enabled=true;
    }
}
void __fastcall TForm8::MB_UserEditClick(TObject *Sender)
{
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        if(MB_UserEdit->Checked==true){
            String user="�������� ����� � ������ ������������: "+DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString+"?";
            if(MessageBoxA(Handle,user.c_str(),"������������",MB_YESNO|MB_ICONQUESTION)==IDYES){
                Edit1->ReadOnly=false;    Label2->Visible=true;
                Edit2->Visible=true;    BitBtn_Post->Visible=true;
                BitBtn_Cancel->Visible=true;     SB_UserFirst->Visible=false;
                SB_UserPrior->Visible=false;     SB_UserNext->Visible=false;
                SB_UserLast->Visible=false;      SB_UserInsert->Visible=false;
                SB_UserEdit->Visible=false;     SB_UserDelete->Visible=false;
                MB_UserInsert->Enabled=false;    MB_UserDelete->Enabled=false;
            }else{
                MB_UserEdit->Checked=false;    MB_UserInsert->Enabled=true;
                MB_UserDelete->Enabled=true;
            }
        }else{
            Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
            Edit1->ReadOnly=true;    Label2->Visible=false;    Edit2->Visible=false;
            BitBtn_Post->Visible=false;     BitBtn_Cancel->Visible=false;
            SB_UserFirst->Visible=true;      SB_UserPrior->Visible=true;
            SB_UserNext->Visible=true;       SB_UserLast->Visible=true;
            MB_UserInsert->Enabled=true;     MB_UserDelete->Enabled=true;
            SB_UserInsert->Visible=true;    SB_UserEdit->Visible=true;
            SB_UserDelete->Visible=true;
        }
    }
}
void __fastcall TForm8::MB_UserDeleteClick(TObject *Sender)
{
    if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
        String user="������� ������� ������ ������������: "+DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString+"?";
        if(MessageBoxA(Handle,user.c_str(),"������������",MB_YESNO|MB_ICONQUESTION)==IDYES){
            DataModule2->IBDataSet_AUTORIZATION->Delete();
        }
    }
}
void __fastcall TForm8::BitBtn_PostClick(TObject *Sender)
{
    if(Edit1->Text!="" && Edit2->Text.Length()>7){
        int *pswrd;
        pswrd=new int[Edit2->Text.Length()];//������ ��� ���������� 2-�� � 3-��� ����� ����������
        for(int i=0;i<Edit2->Text.Length();i++){
            pswrd[i]=Edit2->Text[i+1];
        }
        for(int i=0; i<Edit2->Text.Length(); i++) {                 //������ [ 1 - ���� ]
            pswrd[i]=pswrd[i]*5-159; //������ ������� �������� �� 5 � �������� 159
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
        if(MB_UserInsert->Checked==true){
            DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ACCESS_LEVEL=1 and LOGIN='"+Edit1->Text+"'");
            if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
                MessageBoxA(Handle,"������������ � ����� ������� ���� � ��!\n ������� ����� �����.","�������� ������",MB_OK|MB_ICONWARNING);
            }else if(MessageBoxA(Handle,"�������� ����� ������������?","���������� ������������",MB_YESNO|MB_ICONQUESTION)==IDYES){
                DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]);
                DataModule2->IBDataSet_AUTORIZATION->Insert();
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("ACCESS_LEVEL")->AsInteger=1;
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString=Edit1->Text;
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("PASWORD")->AsString=encds;
                DataModule2->IBDataSet_AUTORIZATION->Post();
                MB_UserInsert->Checked=false;
                MB_UserInsertClick(Sender);
            }DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ACCESS_LEVEL=1");
        }else if(MB_UserEdit->Checked==true){
            int xidlp=DataModule2->IBDataSet_AUTORIZATION->FieldByName("ID")->AsInteger;
            DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION,Form3->ZeroSql[13]+" where ACCESS_LEVEL=1 and ID!="+xidlp+" and LOGIN='"+Edit1->Text+"'");
            if(DataModule2->IBDataSet_AUTORIZATION->RecordCount>0){
                MessageBoxA(Handle,"������������ � ����� ������� ���� � ��!\n ������� ����� �����.","�������� ������",MB_OK|MB_ICONWARNING);
            }else if(MessageBoxA(Handle,"��������� ���������?","�������������� ������� ������",MB_YESNO|MB_ICONQUESTION)==IDYES){
                DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ID="+xidlp);
                DataModule2->IBDataSet_AUTORIZATION->Edit();
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString=Edit1->Text;
                DataModule2->IBDataSet_AUTORIZATION->FieldByName("PASWORD")->AsString=encds;
                DataModule2->IBDataSet_AUTORIZATION->Post();
                MB_UserEdit->Checked=false;
                MB_UserEditClick(Sender);
            }
        }encds=""; DataModule2->SelectSql(DataModule2->IBDataSet_AUTORIZATION, Form3->ZeroSql[13]+" where ACCESS_LEVEL=1");
    }else if(Edit1->Text!="" && Edit2->Text.Length()<8){
        MessageBoxA(Handle,"������ ������ ���� �� ������ 8 ��������!","�������� ������ � ������",MB_OK|MB_ICONINFORMATION);//�������� ����� ������ � ������ �� �������
    }else if(Edit1->Text=="" && Edit2->Text.Length()>7){
        MessageBoxA(Handle,"������� �����!","�������� �� �������",MB_OK|MB_ICONERROR);//�������� ����� ������ � ������ �� �������
    }else {
        MessageBoxA(Handle,"������� ����� � ������!","�������� �� �������",MB_OK|MB_ICONERROR);//�������� ����� ������ � ������ �� �������
    }
}
void __fastcall TForm8::BitBtn_CancelClick(TObject *Sender)
{
    if(MB_UserInsert->Checked==true){
        MB_UserInsert->Checked=false;
        MB_UserInsertClick(Sender);
    }else{
        MB_UserEdit->Checked=false;
        MB_UserEditClick(Sender);

    }
}
void __fastcall TForm8::SB_UserInsertClick(TObject *Sender)
{
    MB_UserInsert->Checked=true;
    MB_UserInsertClick(Sender);
}
void __fastcall TForm8::SB_UserEditClick(TObject *Sender)
{
    MB_UserEdit->Checked=true;
    MB_UserEditClick(Sender);
}
void __fastcall TForm8::Edit2KeyPress(TObject *Sender, char &Key)
{
    if(Key==8 || Key>=32 && Key<126){
        Key=Key;
    }else{
        Key=0;
    }
}
void __fastcall TForm8::DBGrid1CellClick(TColumn *Column)
{
    Edit1->Text=DataModule2->IBDataSet_AUTORIZATION->FieldByName("LOGIN")->AsString;
}