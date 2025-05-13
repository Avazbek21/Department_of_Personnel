#include <vcl.h>
#pragma hdrstop
#include "Unit6.h"
#include "Unit3.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
bool ppost=false, comma=false;
__fastcall TForm6::TForm6(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(ppost==true){
        DataModule2->IBDataSet3_POSITIONS->Post();
    }else{
        DataModule2->IBDataSet3_POSITIONS->Cancel();
    }
    Edit1->Text="";    Edit2->Text="";    Form3->Show();
    
}
void __fastcall TForm6::BitBtn_PPostClick(TObject *Sender)
{
    if(IorE==true){
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->ZeroSql[3]+" where POS_NAME='"+Edit1->Text+"'");
        if(DataModule2->IBDataSet3_POSITIONS->RecordCount>0){
            MessageBoxA(Handle,"Такая должность существует в базе данных!","Добавление должности",MB_OK);
        }else{
            AnsiString pins="Добавить должность: "+Edit1->Text+" c окладом: "+Edit2->Text+"р.?";
            if(MessageBoxA(Handle,pins.c_str(),"Добавление должности",MB_YESNO|MB_ICONQUESTION)==IDYES){
                DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->ZeroSql[3]);
                DataModule2->IBDataSet3_POSITIONS->Insert();
                DataModule2->IBDataSet3_POSITIONS->FieldByName("POS_NAME")->AsString=Edit1->Text;
                DataModule2->IBDataSet3_POSITIONS->FieldByName("SALARY")->AsFloat=StrToFloat(Edit2->Text);
                DataModule2->IBDataSet3_POSITIONS->FieldByName("P_STATUS")->AsInteger=1;
                ppost=true; Close();
            }
        }
    }else{
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->ZeroSql[3]+" where ID<>"+Form3->IDPOS+" and POS_NAME='"+Edit1->Text+"'");
        if(DataModule2->IBDataSet3_POSITIONS->RecordCount>0){
            MessageBoxA(Handle,"Такая должность есть в базе данных!","Редактирования должности",MB_OK|MB_ICONEXCLAMATION);
        }else{
            AnsiString pins="Сохранить изменение: должность "+Edit1->Text+" c окладом "+Edit2->Text+"р.?";
            if(MessageBoxA(Handle,pins.c_str(),"Редактирования должности",MB_YESNO|MB_ICONQUESTION)==IDYES){
                DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->ZeroSql[3]+" where ID="+Form3->IDPOS);
                DataModule2->IBDataSet3_POSITIONS->Edit();
                DataModule2->IBDataSet3_POSITIONS->FieldByName("POS_NAME")->AsString=Edit1->Text;
                DataModule2->IBDataSet3_POSITIONS->FieldByName("SALARY")->AsFloat=StrToFloat(Edit2->Text);
                ppost=true; Close();
            }
        }
    }
}
void __fastcall TForm6::BitBtn_CancelClick(TObject *Sender)
{
    ppost=false; Close();
}
void __fastcall TForm6::FormShow(TObject *Sender)
{
    ppost=false;
    if(IorE==false){
        Edit1->Text=DataModule2->IBDataSet3_POSITIONS->FieldByName("POS_NAME")->AsString;
        Edit2->Text=DataModule2->IBDataSet3_POSITIONS->FieldByName("SALARY")->AsString;
        Caption="Редактирование должности";
    }else{
        Caption="Добавление новой должности";
    }
}
void __fastcall TForm6::Edit2KeyPress(TObject *Sender, char &Key)
{
    if(Key==',' || Key==8 || (Key>='0' && Key<='9')){
        if(Key==','){
            if(comma==true){
                Key=0;
            }else{
                comma=true;
            }
        }else{
            Key=Key;
        }
    }else{
        Key=0;
    }
}
void __fastcall TForm6::Edit2KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==8){
        bool wwcz=false;
        for(int i=1;i<=Edit2->Text.Length();i++)
        {   if(Edit2->Text[i]==','){
                wwcz=true;
            }
        }
        comma=wwcz;
    }
}
