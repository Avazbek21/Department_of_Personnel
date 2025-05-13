#ifndef Unit7H
#define Unit7H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
class TForm7 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label19;
    TLabel *Label20;
    TImage *Image1;
    TEdit *Edit1;
    TEdit *Edit2;
    TBitBtn *BitBtn_Ok;
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall BitBtn_OkClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TForm7(TComponent* Owner);
    bool lporU; //false - для редактирования логина и пароли, true - для вызова формы "Пользователи"
};
extern PACKAGE TForm7 *Form7;
#endif
