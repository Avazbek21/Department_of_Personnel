#ifndef Unit2H
#define Unit2H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
class TDataModule2 : public TDataModule
{
__published:	// IDE-managed Components
    TDataSource *DataSource1;
    TDataSource *DataSource2;
    TIBDatabase *IBDatabase1;
    TIBTransaction *IBTransaction1;
    TDataSource *DataSource4;
    TDataSource *DataSource5;
    TDataSource *DataSource6;
    TDataSource *DataSource7;
    TDataSource *DataSource8;
    TDataSource *DataSource9;
    TDataSource *DataSource10;
    TDataSource *DataSource11;
    TDataSource *DataSource12;
    TDataSource *DataSource13;
    TIBDataSet *IBDataSet2_EDUCATION;
    TIBDataSet *IBDataSet4_AFTER_EDUCATION;
    TIBDataSet *IBDataSet5_FAMILY;
    TIBDataSet *IBDataSet6_TRUD_KNIGKA;
    TIBDataSet *IBDataSet7_ATTESTATION;
    TIBDataSet *IBDataSet8_POV_QUALIFICATION;
    TIBDataSet *IBDataSet9_PROF_PEREPODGOTOVKA;
    TIBDataSet *IBDataSet10_NAGRADI;
    TIBDataSet *IBDataSet11_OTPUSK;
    TIBDataSet *IBDataSet12_SOC_LGOTI;
    TIBDataSet *IBDataSet13_TRUD_DOGOVOR;
    TDataSource *DataSource;
    TIBDataSet *IBDataSet_AUTORIZATION;
    TDataSource *DataSource3;
    TIBDataSet *IBDataSet3_POSITIONS;
    TIBDataSet *IBDataSet1_SOTRUDNIK;
private:	// User declarations
public:		// User declarations
    __fastcall TDataModule2(TComponent* Owner);
    void __fastcall SelectSql(TIBDataSet *IBDataSet, AnsiString sql);
};
extern PACKAGE TDataModule2 *DataModule2;
#endif
