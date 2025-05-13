#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataModule2 *DataModule2;
__fastcall TDataModule2::TDataModule2(TComponent* Owner)
    : TDataModule(Owner)
{
}
void __fastcall TDataModule2::SelectSql(TIBDataSet *IBDataSet, AnsiString sql)
{
    IBDataSet->Close();
    IBDataSet->SelectSQL->Clear();
    IBDataSet->SelectSQL->Add(sql);
    IBDataSet->Open();
}
