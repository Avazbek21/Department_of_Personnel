#include <vcl.h>
#pragma hdrstop
#include "Unit5.h"
#include "Unit2.h"
#include "Unit3.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm5::QuickRep1AfterPreview(TObject *Sender)
{
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,Form3->sqlEmp.sqlline);
    DataModule2->IBDataSet1_SOTRUDNIK->RecNo=Form3->sqlEmp.recno;
    Form3->Show();  
    Close();
}
