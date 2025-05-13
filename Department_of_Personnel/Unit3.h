#ifndef Unit3H
#define Unit3H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TMainMenu *MainMenu1;
    TMenuItem *N2;
    TMenuItem *MB_A;
    TMenuItem *MB_LP;
    TMenuItem *MB_LPUA;
    TMenuItem *MB_P;
    TMenuItem *MB_PInsert;
    TMenuItem *MB_PEdit;
    TMenuItem *MB_PDelete;
    TMenuItem *MB_Emp;
    TMenuItem *MB_EmpInsert;
    TMenuItem *MB_EmpEdit;
    TMenuItem *MB_EmpDelete;
    TMenuItem *N3;
    TMenuItem *MB_ArkhEmp;
    TMenuItem *MB_ArkhP;
    TMenuItem *MB_UExit;
    TMenuItem *MB_Exit;
    TSpeedButton *SB_EmpNext;
    TSpeedButton *SB_EmpFirst;
    TSpeedButton *SB_EmpPrior;
    TSpeedButton *SB_EmpLast;
    TSpeedButton *SB_EmpInsert;
    TSpeedButton *SB_EmpEdit;
    TSpeedButton *SB_EmpDelete;
    TLabel *Label2;
    TPanel *Panel3;
    TLabel *Label29;
    TDBText *DBText14;
    TLabel *Label30;
    TDBText *DBText15;
    TPanel *Panel4;
    TSpeedButton *SB_EmpFiltr;
    TSpeedButton *SB_EmpOrderBy;
    TDBGrid *DBGrid1;
    TDBEdit *DBEdit2;
    TLabel *Label1;
    TDBEdit *DBEdit1;
    TSpeedButton *SB_Preview;
    TSpeedButton *SB_PosFirst;
    TSpeedButton *SB_PosPrior;
    TSpeedButton *SB_PosNext;
    TSpeedButton *SB_PosLast;
    TSpeedButton *SB_PInsert;
    TSpeedButton *SB_PEdit;
    TSpeedButton *SB_PDelete;
    TLabel *Label32;
    TLabel *NumRecord_Pos;
    TLabel *Label35;
    TLabel *CountRecord_Pos;
    TDBGrid *DBGrid4;
    TGroupBox *GroupBox7;
    TRadioGroup *RadioGroup5;
    TCheckBox *CheckBoxPos;
    TRadioGroup *RadioGroup4;
    void __fastcall MB_UExitClick(TObject *Sender);
    void __fastcall MB_ExitClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

    void __fastcall SB_EmpFirstClick(TObject *Sender);
    void __fastcall SB_EmpPriorClick(TObject *Sender);
    void __fastcall SB_EmpNextClick(TObject *Sender);
    void __fastcall SB_EmpLastClick(TObject *Sender);



    void __fastcall CheckBoxPosClick(TObject *Sender);
    void __fastcall RadioGroup5Click(TObject *Sender);
    void __fastcall RadioGroup4Click(TObject *Sender);
    void __fastcall MB_EmpInsertClick(TObject *Sender);
    void __fastcall MB_EmpEditClick(TObject *Sender);
    void __fastcall MB_EmpDeleteClick(TObject *Sender);
    void __fastcall SB_EmpOrderByClick(TObject *Sender);
    void __fastcall SB_PosFirstClick(TObject *Sender);
    void __fastcall SB_PosPriorClick(TObject *Sender);
    void __fastcall SB_PosNextClick(TObject *Sender);
    void __fastcall SB_PosLastClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall SB_PreviewClick(TObject *Sender);
    void __fastcall MB_LPClick(TObject *Sender);
    void __fastcall MB_LPUAClick(TObject *Sender);
    void __fastcall MB_ArkhEmpClick(TObject *Sender);
    void __fastcall MB_ArkhPClick(TObject *Sender);
    void __fastcall MB_PInsertClick(TObject *Sender);
    void __fastcall MB_PDeleteClick(TObject *Sender);
    void __fastcall MB_PEditClick(TObject *Sender);
    void __fastcall PageControl1Change(TObject *Sender);

private:	// User declarations
public:		// User declarations
    __fastcall TForm3(TComponent* Owner);
    String ZeroSql[13],
           BeginFiltr[2];
    void __fastcall woEmp();
    void __fastcall woPos();
    int IDPOS;      //для проверки совпадения должности
    struct{
        int sqlsort,
            sqlfiltr[6],
            recno;          //при возвращении на форму "Отдел кадров"(главную)(текущую),
         AnsiString sqlline;//верную предыдущий запрос и номер записи
    }sqlEmp;
    String posEmployee;//для сравнения с предыдущей должностью
};
extern PACKAGE TForm3 *Form3;
#endif