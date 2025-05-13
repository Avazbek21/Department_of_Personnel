#ifndef Unit9H
#define Unit9H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
class TForm9 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TDBGrid *DBGrid1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TDBText *DBText2;
    TDBText *DBText3;
    TDBText *DBText4;
    TDBText *DBText5;
    TDBText *DBText6;
    TSpeedButton *SB_Recover_DataS;
    TSpeedButton *SB_EmpFirst;
    TSpeedButton *SB_EmpPrior;
    TSpeedButton *SB_EmpNext;
    TSpeedButton *SB_EmpLast;
    TPanel *Panel2;
    TDBGrid *DBGrid2;
    TSpeedButton *SB_PosFirst;
    TSpeedButton *SB_PosPrior;
    TSpeedButton *SB_PosNext;
    TSpeedButton *SB_PosLast;
    TSpeedButton *SB_Recover_DataP;
    TCheckBox *CheckBox1;
    TComboBox *ComboBox1;
    TDBText *DBText1;
    void __fastcall SB_EmpFirstClick(TObject *Sender);
    void __fastcall SB_EmpPriorClick(TObject *Sender);
    void __fastcall SB_EmpNextClick(TObject *Sender);
    void __fastcall SB_EmpLastClick(TObject *Sender);
    void __fastcall SB_Recover_DataSClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall SB_Recover_DataPClick(TObject *Sender);
    void __fastcall ComboBox1Select(TObject *Sender);
    void __fastcall CheckBox1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall SB_PosFirstClick(TObject *Sender);
    void __fastcall SB_PosPriorClick(TObject *Sender);
    void __fastcall SB_PosNextClick(TObject *Sender);
    void __fastcall SB_PosLastClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm9(TComponent* Owner);
    bool EmpORPos;
};
extern PACKAGE TForm9 *Form9;
#endif
