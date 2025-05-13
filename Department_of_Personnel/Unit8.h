#ifndef Unit8H
#define Unit8H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
class TForm8 : public TForm
{
__published:	// IDE-managed Components
    TDBGrid *DBGrid1;
    TMainMenu *MainMenu1;
    TMenuItem *MB_Users;
    TMenuItem *MB_UserInsert;
    TEdit *Edit1;
    TEdit *Edit2;
    TLabel *Label1;
    TLabel *Label2;
    TBitBtn *BitBtn_Post;
    TBitBtn *BitBtn_Cancel;
    TSpeedButton *SB_UserFirst;
    TSpeedButton *SB_UserPrior;
    TSpeedButton *SB_UserNext;
    TSpeedButton *SB_UserLast;
    TMenuItem *MB_UserEdit;
    TMenuItem *MB_UserDelete;
    TSpeedButton *SB_UserInsert;
    TSpeedButton *SB_UserEdit;
    TSpeedButton *SB_UserDelete;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall MB_UserInsertClick(TObject *Sender);
    void __fastcall BitBtn_PostClick(TObject *Sender);
    void __fastcall MB_UserDeleteClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall SB_UserFirstClick(TObject *Sender);
    void __fastcall SB_UserPriorClick(TObject *Sender);
    void __fastcall SB_UserNextClick(TObject *Sender);
    void __fastcall SB_UserLastClick(TObject *Sender);
    void __fastcall MB_UserEditClick(TObject *Sender);
    void __fastcall BitBtn_CancelClick(TObject *Sender);
    void __fastcall SB_UserInsertClick(TObject *Sender);
    void __fastcall SB_UserEditClick(TObject *Sender);
    void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
    void __fastcall DBGrid1CellClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
    __fastcall TForm8(TComponent* Owner);
};
extern PACKAGE TForm8 *Form8;
#endif
