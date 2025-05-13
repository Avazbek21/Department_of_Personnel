#ifndef Unit6H
#define Unit6H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
class TForm6 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TBitBtn *BitBtn_PPost;
    TBitBtn *BitBtn_Cancel;
    TEdit *Edit1;
    TEdit *Edit2;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BitBtn_PPostClick(TObject *Sender);
    void __fastcall BitBtn_CancelClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit2KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TForm6(TComponent* Owner);
    bool IorE;
};
extern PACKAGE TForm6 *Form6;
#endif
