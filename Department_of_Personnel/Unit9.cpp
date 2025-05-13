#include <vcl.h>
#pragma hdrstop
#include "Unit9.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit10.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
bool cls=false;
__fastcall TForm9::TForm9(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm9::SB_EmpFirstClick(TObject *Sender)
{
    DataModule2->IBDataSet1_SOTRUDNIK->First();
}
void __fastcall TForm9::SB_EmpPriorClick(TObject *Sender)
{
    DataModule2->IBDataSet1_SOTRUDNIK->Prior();    
}
void __fastcall TForm9::SB_EmpNextClick(TObject *Sender)
{
    DataModule2->IBDataSet1_SOTRUDNIK->Next();
}
void __fastcall TForm9::SB_EmpLastClick(TObject *Sender)
{
    DataModule2->IBDataSet1_SOTRUDNIK->Last();
}
void __fastcall TForm9::SB_Recover_DataSClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Подтвердить восстановление данных из архива?","Восстановление данных",MB_YESNO|MB_ICONQUESTION)==IDYES){
        cls=true;    Form10->forwhat=3; Form10->Caption="Восстановление данных";
        Form10->Show();    Close();
    }
}
void __fastcall TForm9::FormShow(TObject *Sender)
{
    if(EmpORPos==true){
        Panel1->Visible=true;    ClientWidth=887;
        Caption="Архив - Сотрудники";
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->ZeroSql[1]+" where S_STATUS=0");
        ComboBox1->Clear();
        for(DataModule2->IBDataSet1_SOTRUDNIK->First(); !DataModule2->IBDataSet1_SOTRUDNIK->Eof; DataModule2->IBDataSet1_SOTRUDNIK->Next())
        {   ComboBox1->Items->Add(DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("TAB_NOMER")->AsString);
        }DataModule2->IBDataSet1_SOTRUDNIK->First();
    }else{
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->ZeroSql[3]+" where P_STATUS=0");
        Panel2->Visible=true;    ClientWidth=458;
        Caption="Архив - Должности";
    }
}
void __fastcall TForm9::FormClose(TObject *Sender, TCloseAction &Action)
{


    if(EmpORPos==true){
        Panel1->Visible=false;
        if(cls==false){
            Form3->Show();
            DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->BeginFiltr[1]);
        }cls=false;
    }else{
        Panel2->Visible=false;
        Form3->Show();
    }
}
void __fastcall TForm9::SB_Recover_DataPClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Подтвердить восстановление данных из архива?","Восстановление данных",MB_YESNO|MB_ICONQUESTION)==IDYES){
        DataModule2->IBDataSet3_POSITIONS->Edit();
        DataModule2->IBDataSet3_POSITIONS->FieldByName("P_STATUS")->AsInteger=1;
        DataModule2->IBDataSet3_POSITIONS->Post();
        DataModule2->IBDataSet3_POSITIONS->Close();
        DataModule2->IBDataSet3_POSITIONS->Open();
    }
}
void __fastcall TForm9::ComboBox1Select(TObject *Sender)
{
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->ZeroSql[1]+" where S_STATUS=0 and TAB_NOMER="+StrToInt(ComboBox1->Text));
}
void __fastcall TForm9::CheckBox1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(CheckBox1->Checked==true){
        if(ComboBox1->Text!=""){
            DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->ZeroSql[1]+" where S_STATUS=0 and TAB_NOMER="+StrToInt(ComboBox1->Text));
        }
    }else{
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->ZeroSql[1]+" where S_STATUS=0");
    }
}
void __fastcall TForm9::SB_PosFirstClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->First();    
}
void __fastcall TForm9::SB_PosPriorClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->Prior();    
}
void __fastcall TForm9::SB_PosNextClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->Next();    
}
void __fastcall TForm9::SB_PosLastClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->Last();    
}