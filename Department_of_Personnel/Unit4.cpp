#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "Unit4.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int i=0;
bool sqlkey=false;
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm4::FormShow(TObject *Sender)
{
    Left=995;
    Top=575;
    ComboBox1->Clear();
    ComboBox3->Clear();
    ComboBox4->Clear();
    int recnumEmp=DataModule2->IBDataSet1_SOTRUDNIK->RecNo;
    for(DataModule2->IBDataSet1_SOTRUDNIK->First();!DataModule2->IBDataSet1_SOTRUDNIK->Eof;DataModule2->IBDataSet1_SOTRUDNIK->Next())
    {   ComboBox1->Items->Add(DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("TAB_NOMER")->AsInteger);
    }
    DataModule2->IBDataSet1_SOTRUDNIK->RecNo=recnumEmp;
    DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->BeginFiltr[2]);
    for(DataModule2->IBDataSet3_POSITIONS->First();!DataModule2->IBDataSet3_POSITIONS->Eof;DataModule2->IBDataSet3_POSITIONS->Next())
    {   ComboBox3->Items->Add(DataModule2->IBDataSet3_POSITIONS->FieldByName("POS_NAME")->AsString);
        ComboBox4->Items->Add(DataModule2->IBDataSet3_POSITIONS->FieldByName("SALARY")->AsFloat);
    }
    DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->BeginFiltr[2]+" and ID=:ID_POS");
}
void __fastcall TForm4::CheckBox1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)//��� �����������
{
    RadioGroup1->ItemIndex=-1;
    RadioGroup2->ItemIndex=-1;
    RadioGroup3->ItemIndex=-1;
    RadioGroup4->ItemIndex=-1;
    CheckBox2->Checked=false;
    Form3->sqlEmp.sqlsort=0;
    if(CheckBox1->Checked==false){
        CheckBox1->Checked=true;
    }
    SB_SqlStandart->Visible=false;
}
void __fastcall TForm4::RadioGroup1Click(TObject *Sender)//���������� �� �����. ������
{
    CheckBox1->Checked=false;
    RadioGroup2->ItemIndex=-1;
    RadioGroup3->ItemIndex=-1;
    RadioGroup4->ItemIndex=-1;
    Form3->sqlEmp.sqlsort=RadioGroup1->ItemIndex+1;
    if(Form3->sqlEmp.sqlfiltr[0]>1 && Form3->sqlEmp.sqlfiltr[0]<8){
        CheckBox2->Checked=true;
    }
    SB_SqlStandart->Visible=true;
}
void __fastcall TForm4::RadioGroup2Click(TObject *Sender)//���������� �� �������
{
    CheckBox1->Checked=false;
    RadioGroup1->ItemIndex=-1;
    RadioGroup3->ItemIndex=-1;
    RadioGroup4->ItemIndex=-1;
    Form3->sqlEmp.sqlsort=RadioGroup2->ItemIndex+3;
    if(Form3->sqlEmp.sqlfiltr[0]>1 && Form3->sqlEmp.sqlfiltr[0]<8){
        CheckBox2->Checked=true;
    }
    SB_SqlStandart->Visible=true;
}
void __fastcall TForm4::RadioGroup3Click(TObject *Sender)//���������� �� �����
{
    CheckBox1->Checked=false;
    RadioGroup1->ItemIndex=-1;
    RadioGroup2->ItemIndex=-1;
    RadioGroup4->ItemIndex=-1;
    Form3->sqlEmp.sqlsort=RadioGroup3->ItemIndex+5;
    if(Form3->sqlEmp.sqlfiltr[0]>1 && Form3->sqlEmp.sqlfiltr[0]<8){
        CheckBox2->Checked=true;
    }
    SB_SqlStandart->Visible=true;
}
void __fastcall TForm4::RadioGroup4Click(TObject *Sender)//���������� �� ��������
{
    CheckBox1->Checked=false;
    RadioGroup1->ItemIndex=-1;
    RadioGroup2->ItemIndex=-1;
    RadioGroup3->ItemIndex=-1;
    Form3->sqlEmp.sqlsort=RadioGroup4->ItemIndex+7;
    if(Form3->sqlEmp.sqlfiltr[0]>1 && Form3->sqlEmp.sqlfiltr[0]<8){
        CheckBox2->Checked=true;
    }
    SB_SqlStandart->Visible=true;
}
void __fastcall TForm4::CheckBox2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox2->Checked==true){
        CheckBox2->Checked=false;
    }else{
        CheckBox2->Checked=true;    
    }
}

void __fastcall TForm4::CheckBox12MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox12->Checked==false){
        CheckBox12->Checked=true;
    }
    for(i=0;i<6;i++)
    {    Form3->sqlEmp.sqlfiltr[i]=0;
    }
    CheckBox2->Checked=false;     CheckBox2->Visible=true;
    CheckBox3->Checked=false;     CheckBox3->Visible=true;
    CheckBox4->Checked=false;     CheckBox4->Visible=true;
    CheckBox5->Checked=false;     CheckBox5->Visible=true;
    CheckBox6->Checked=false;     CheckBox6->Visible=true;
    CheckBox7->Checked=false;     CheckBox7->Visible=true;
    CheckBox8->Checked=false;     CheckBox8->Visible=true;
    CheckBox9->Checked=false;     CheckBox9->Visible=true;
    CheckBox10->Checked=false;    CheckBox10->Visible=true;
    CheckBox11->Checked=false;    CheckBox11->Visible=true;

    ComboBox1->Text="";    ComboBox1->Visible=false;
    Edit1->Clear();        Edit1->Visible=false;
    Edit2->Clear();        Edit2->Visible=false;
    Edit3->Clear();        Edit3->Visible=false;
    ComboBox2->Text="";    ComboBox2->Visible=false;
    ComboBox3->Text="";    ComboBox3->Visible=false;
    ComboBox4->Text="";    ComboBox4->Visible=false;
    Edit4->Clear();        Edit4->Visible=false;
    Edit5->Clear();        Edit5->Visible=false;

    RadioGroup1->Visible=true;    RadioGroup2->Visible=true;
    RadioGroup3->Visible=true;    RadioGroup4->Visible=true;
    
}//------------------------���  ����������------------------------------------
//-----------�����  ������  ���  CheckBox-��  3  10  11----------------------
void __fastcall TForm4::OnCheckBox31011Checked(int filtr)
{
    Form3->sqlEmp.sqlfiltr[0]=filtr;
    for(i=1;i<6;i++)
    {   Form3->sqlEmp.sqlfiltr[i]=0;
    }
    Form3->sqlEmp.sqlsort=0;                        //������ ����������
    //��������  �������  ����������
    CheckBox12->Checked=false;                                //��� ����������          =false
    CheckBox2->Checked=false;    CheckBox2->Visible=false;   //���������� � ���������� =false
    CheckBox4->Checked=false;    CheckBox4->Visible=false;   //�������                 =false
    CheckBox5->Checked=false;    CheckBox5->Visible=false;   //���                     =false
    CheckBox6->Checked=false;    CheckBox6->Visible=false;   //��������                =false
    CheckBox7->Checked=false;    CheckBox7->Visible=false;   //���                     =false
    CheckBox8->Checked=false;    CheckBox8->Visible=false;   //���������               =false
    CheckBox9->Checked=false;    CheckBox9->Visible=false;   //�����                   =false
    Edit1->Clear();              Edit1->Visible=false;
    Edit2->Clear();              Edit2->Visible=false;
    Edit3->Clear();              Edit3->Visible=false;
    ComboBox2->Text="";          ComboBox2->Visible=false;
    ComboBox3->Text="";          ComboBox3->Visible=false;
    ComboBox4->Text="";          ComboBox4->Visible=false;
    //��������  �������  ����������
    //��������  �����  ������  ���������� (Form-����������)
    CheckBox1->Checked=true;
    RadioGroup1->Visible=false;    RadioGroup1->ItemIndex=-1;
    RadioGroup2->Visible=false;    RadioGroup2->ItemIndex=-1;
    RadioGroup3->Visible=false;    RadioGroup3->ItemIndex=-1;
    RadioGroup4->Visible=false;    RadioGroup4->ItemIndex=-1;
    //��������  �����  ������  ����������
    SB_SqlStandart->Visible=true;
}//-----------�����  ������  ���  CheckBox-��  3  10  11---------------------
//---��������  ���  ������  CheckBox-��  3 10 11----------------------------
void __fastcall TForm4::CheckingCancel()
{
    for(i=0;i<6;i++)
    {
        Form3->sqlEmp.sqlfiltr[i]=0;
    }
    CheckBox12->Checked=true;            //��� ���������� =true
    //��������  ���������  �������  ����������
    CheckBox2->Visible=true;    CheckBox4->Visible=true;
    CheckBox5->Visible=true;    CheckBox6->Visible=true;
    CheckBox7->Visible=true;    CheckBox8->Visible=true;
    CheckBox9->Visible=true;
    //��������  ���������  �������  ����������
    //�������� ���������  ������  ������  ����������
    RadioGroup1->Visible=true;    RadioGroup2->Visible=true;
    RadioGroup3->Visible=true;    RadioGroup4->Visible=true;
    SB_SqlStandart->Visible=false;
}//---��������  ������������  �����  ���  ����������  �������  "����������"---
//-----------------------����������  �� ����������  ������-------------------
void __fastcall TForm4::CheckBox3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox3->Checked==true) {//���  ����������  <<  ��  ����������  ������  >>
        OnCheckBox31011Checked(1);
        ComboBox1->Visible=true;        //��������� �����         =true
        CheckBox10->Checked=false;    CheckBox10->Visible=false;  //���    =false
        CheckBox11->Checked=false;    CheckBox11->Visible=false;  //�����  =false
        Edit4->Clear();               Edit4->Visible=false;
        Edit5->Clear();               Edit5->Visible=false;
        SB_SqlStandart->Visible=true;
    }else if(CheckBox3->Checked==false){    //������  ���������
        CheckingCancel();
        ComboBox1->Visible=false;           //��������� �����         =false
        CheckBox10->Visible=true;    CheckBox11->Visible=true;//��� =true //����� =true
        SB_SqlStandart->Visible=false;
    }
}//-----------------------����������  �� ����������  ������------------------
//-----------�����  ������  ���  CheckBox-��  4--9 -------------------------
void __fastcall TForm4::OnCheckBox49Checked(int filtr)
{
    for(i=0;i<6;i++)
    {   if(Form3->sqlEmp.sqlfiltr[i]==0){
            Form3->sqlEmp.sqlfiltr[i]=filtr;
            break;
        }
    }
    CheckBox12->Checked=false;
    CheckBox3->Checked=false;    CheckBox3->Visible=false;
    ComboBox1->Text="";          ComboBox1->Visible=false;

    CheckBox10->Checked=false;    CheckBox10->Visible=false;
    Edit4->Clear();               Edit4->Visible=false;
    CheckBox11->Checked=false;    CheckBox11->Visible=false;
    Edit5->Clear();               Edit5->Visible=false;
    if(Form3->sqlEmp.sqlsort>0){             // ����� ���������� ��������,
        CheckBox2->Checked=true;             //�������� �������� ���������� � ����������
    }
    SB_SqlStandart->Visible=true;
}//-----------�����  ������  ���  CheckBox-��  4--9 -------------------------
//---��������  ������������  �����  ���  ����������  �������  "����������"--
void __fastcall TForm4::Checking()
{
    for(i=0;i<5;i++)
    {   Form3->sqlEmp.sqlfiltr[i]=Form3->sqlEmp.sqlfiltr[i+1];
    }
    Form3->sqlEmp.sqlfiltr[5]=0;
    if(Form3->sqlEmp.sqlfiltr[0]==0){
        CheckBox12->Checked=true;
        CheckBox2->Checked=false;
        CheckBox3->Visible=true;
        CheckBox10->Visible=true;
        CheckBox11->Visible=true;                                  
        SB_SqlStandart->Visible=false;
    }
}//---��������  ������������  �����  ���  ����������  �������  "����������"---
//-----------------------����������  ��  �������----------------------------
void __fastcall TForm4::CheckBox4MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox4->Checked==true){
        OnCheckBox49Checked(2);
        Edit1->Visible=true;
    }else {
        Edit1->Visible=false;
        Checking();
    }
}//-----------------------����������  ��  �������----------------------------
//------�����  ��������  �����  ������  Enter-------------------------------
void __fastcall TForm4::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==VK_RETURN){
        SB_StartSqlClick(Sender);
    }

}//------�����  ��������  �����  ������  Enter-------------------------------
//------------------------����������  ��  �����------------------------------
void __fastcall TForm4::CheckBox5MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox5->Checked==true){
        OnCheckBox49Checked(3);
        Edit2->Visible=true;
    }else{
        Edit2->Visible=false;
        Checking();
    }
}//------------------------����������  ��  �����------------------------------
//------------------------����������  ��  ��������---------------------------
void __fastcall TForm4::CheckBox6MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox6->Checked==true){
        OnCheckBox49Checked(4);
        Edit3->Visible=true;
    }else{
        Edit3->Visible=false;
        Checking();
    }
}//------------------------����������  ��  ��������---------------------------
//------------------------����������  ��  ����-------------------------------
void __fastcall TForm4::CheckBox7MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox7->Checked==true){
        OnCheckBox49Checked(5);
        ComboBox2->Visible=true;
    }else{
        ComboBox2->Visible=false;
        Checking();
    }
}//------------------------����������  ��  ����-------------------------------
//------------------------����������  ��  ���������--------------------------
void __fastcall TForm4::CheckBox8MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox8->Checked==true){
        OnCheckBox49Checked(6);
        ComboBox3->Visible=true;
    }else{
        Checking();
        ComboBox3->Visible=false;
    }
}//------------------------����������  ��  ���������--------------------------
//------------------------����������  ��  ������-----------------------------
void __fastcall TForm4::CheckBox9MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox9->Checked==true){
        OnCheckBox49Checked(7);
        ComboBox4->Visible=true;
        SB_SqlStandart->Visible=true;
    }else{
        Checking();
        ComboBox4->Visible=false;
    }
}//------------------------����������  ��  ������-----------------------------
//------------------------����������  ��  ���--------------------------------
void __fastcall TForm4::CheckBox10MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox10->Checked==true) {//���  ����������  <<  ��  ����������  ������  >>
        OnCheckBox31011Checked(8);
        Edit4->Visible=true;          //���             =true
        CheckBox3->Checked=false;     CheckBox3->Visible=false;//���������
        ComboBox1->Text="";           ComboBox1->Visible=false;//����� =false
        CheckBox11->Visible=false;    //�����           =false
        Edit5->Clear();               Edit5->Visible=false;
    }else{    //������  ���������
        CheckingCancel();
        Edit4->Visible=false;       //���             =false
        CheckBox3->Visible=true;    CheckBox11->Visible=true;
    }
}//------------------------����������  ��  ���--------------------------------
//------------------------����������  ��  �����------------------------------
void __fastcall TForm4::CheckBox11MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox11->Checked==true) {//���  ����������  <<  ��  ����������  ������  >>
        OnCheckBox31011Checked(9);
        Edit5->Visible=true;          //�����             =true
        CheckBox3->Checked=false;     CheckBox3->Visible=false;//���������
        ComboBox1->Text="";           ComboBox1->Visible=false;//����� =false
        CheckBox10->Visible=false;    //�����           =false
        Edit4->Clear();               Edit4->Visible=false;
    }else{    //������  ���������
        CheckingCancel();
        Edit5->Visible=false;       //���             =false
        CheckBox3->Visible=true;    CheckBox10->Visible=true;
    }
}//------------------------����������  ��  �����-----------------------------
//------------------------������  "������"-----------------------------------
void __fastcall TForm4::SB_SqlStandartClick(TObject *Sender)
{
    CheckBox12->Checked=true;       //��� ����������
    for(i=0;i<6;i++)
    {    Form3->sqlEmp.sqlfiltr[i]=0;
    }
    CheckBox2->Checked=false;     CheckBox2->Visible=true;
    CheckBox3->Checked=false;     CheckBox3->Visible=true;
    CheckBox4->Checked=false;     CheckBox4->Visible=true;
    CheckBox5->Checked=false;     CheckBox5->Visible=true;
    CheckBox6->Checked=false;     CheckBox6->Visible=true;
    CheckBox7->Checked=false;     CheckBox7->Visible=true;
    CheckBox8->Checked=false;     CheckBox8->Visible=true;
    CheckBox9->Checked=false;     CheckBox9->Visible=true;
    CheckBox10->Checked=false;    CheckBox10->Visible=true;
    CheckBox11->Checked=false;    CheckBox11->Visible=true;

    ComboBox1->Text="";    ComboBox1->Visible=false;
    Edit1->Clear();        Edit1->Visible=false;
    Edit2->Clear();        Edit2->Visible=false;
    Edit3->Clear();        Edit3->Visible=false;
    ComboBox2->Text="";    ComboBox2->Visible=false;
    ComboBox3->Text="";    ComboBox3->Visible=false;
    ComboBox4->Text="";    ComboBox4->Visible=false;
    Edit4->Clear();        Edit4->Visible=false;
    Edit5->Clear();        Edit5->Visible=false;

    CheckBox1->Checked=true;         //��� ����������
    Form3->sqlEmp.sqlsort=0;
    RadioGroup1->Visible=true;    RadioGroup1->ItemIndex=-1;
    RadioGroup2->Visible=true;    RadioGroup2->ItemIndex=-1;
    RadioGroup3->Visible=true;    RadioGroup3->ItemIndex=-1;
    RadioGroup4->Visible=true;    RadioGroup4->ItemIndex=-1;
    if(sqlkey==true){
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,Form3->BeginFiltr[1]);
    }

}//------------------------������  "������"----------------------------------
//------------------------������  "������"-----------------------------------
void __fastcall TForm4::SB_StartSqlClick(TObject *Sender)
{
    if(Form3->sqlEmp.sqlfiltr[0]==0){
        sqlkey=true;
        Form3->woEmp();
    }else if(Form3->sqlEmp.sqlfiltr[0]==1){
        if(ComboBox1->ItemIndex<0){
            MessageBoxA(Handle,"��������� ����� �� ������!","����� ������", MB_OK|MB_ICONEXCLAMATION);
        }else{
            sqlkey=true;
            Form3->woEmp();
        }
    }else if(Form3->sqlEmp.sqlfiltr[0]>=2 && Form3->sqlEmp.sqlfiltr[0]<=7){
        int kol1=0, kol2=0;
        String f1="", f2="", message="����, ������� �������� � ���������� �� ������ ���� ������ ��� ������� ������������ ��������! ";
        if(CheckBox4->Checked==true && Edit1->Text==""){
             f1="�������"; kol1=1;
        }
        if(CheckBox5->Checked==true && Edit2->Text==""){
             if(kol1==1)    { f1+=", "; }
             f1+="���";    kol1++;
        }
        if(CheckBox6->Checked==true && Edit3->Text==""){
             if(kol1>0)     { f1+=", "; }
             f1+="��������"; kol1++;
        }
        if(CheckBox7->Checked==true && ComboBox2->ItemIndex<0){
            ComboBox2->Text="";    f2="���";    kol2=1;
        }
        if(CheckBox8->Checked==true && ComboBox3->ItemIndex<0){
            ComboBox3->Text="";
            if(kol2==1)     { f2+=", "; }
            f2+="���������"; kol2++;
        }
        if(CheckBox9->Checked==true && ComboBox4->ItemIndex<0){
            ComboBox4->Text="";
            if(kol2>1)     { f2+=", "; }
            f2+="�����";   kol2++;
        }
        if(kol1==0 && kol2==0){
            sqlkey=true;
            Form3->woEmp();
        }else{
            if(kol1>0){
                if(kol1==1){
                    message+="���� ����� "+f1+" ������! ";
                }else{
                    message+="���� �����: "+f1+" ������! ";
                }
            }
            if(kol2>0){
                if(kol2==1){
                    message+="� ���� ������ "+f2+" �� ���������� ��������!";
                }else{
                    message+="� ���� ������ "+f2+" �� ���������� ��������!";
                }
            }
            MessageBoxA(Handle, message.c_str(), "����� ������", MB_OK|MB_ICONEXCLAMATION);
        }
    }else if(Form3->sqlEmp.sqlfiltr[0]==8){
        if(Edit4->Text=="" || Edit4->Text.Length()<12){
            MessageBoxA(Handle,"� ���� ��� ������� 12 ������!","����� ������", MB_OK|MB_ICONEXCLAMATION);
        }else{
            sqlkey=true;
            Form3->woEmp();
        }
    }else{
        if(Edit5->Text==""){
            MessageBoxA(Handle,"���� ����� ����!","����� ������", MB_OK|MB_ICONEXCLAMATION);
        }else if(Edit5->Text.Length()<14){
            MessageBoxA(Handle,"��������� ���� �����(�� ����� 14)!","����� ������", MB_OK|MB_ICONEXCLAMATION);
        }else{
            sqlkey=true;
            Form3->woEmp();
        }
    }
}//----------------------������  "������"-----------------------------------
void __fastcall TForm4::Edit4KeyPress(TObject *Sender, char &Key)
{
    if(Key==VK_RETURN){
        SB_StartSqlClick(Sender);
    }else if(Key>='0' && Key<='9' || Key==8 || Key==46){
        Key=Key;
    }else
        Key=0;
}

void __fastcall TForm4::Edit5KeyPress(TObject *Sender, char &Key)
{
    if(Key==VK_RETURN){
        SB_StartSqlClick(Sender);
    }else if(Key>='0' && Key<='9' || Key==' ' || Key=='-' || Key==8 || Key==46){
        Key=Key;
    }else
        Key=0;
}
void __fastcall TForm4::ComboBox1KeyPress(TObject *Sender, char &Key)
{
    if(Key==VK_RETURN){
        SB_StartSqlClick(Sender);
    }else if(Key>='0' && Key<='9' || Key==8 || Key==46){
        Key=Key;
    }else{
        Key=0;
    }
}
