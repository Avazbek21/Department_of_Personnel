#ifndef Unit4H
#define Unit4H
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
class TForm4 : public TForm
{
__published:	// IDE-managed Components
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox12;
    TGroupBox *GroupBox1;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TComboBox *ComboBox2;
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TCheckBox *CheckBox8;
    TComboBox *ComboBox3;
    TCheckBox *CheckBox9;
    TComboBox *ComboBox4;
    TCheckBox *CheckBox10;
    TEdit *Edit4;
    TCheckBox *CheckBox11;
    TEdit *Edit5;
    TComboBox *ComboBox1;
    TCheckBox *CheckBox3;
    TGroupBox *GroupBox2;
    TRadioGroup *RadioGroup1;
    TRadioGroup *RadioGroup2;
    TRadioGroup *RadioGroup3;
    TRadioGroup *RadioGroup4;
    TSpeedButton *SB_StartSql;
    TSpeedButton *SB_SqlStandart;
    void __fastcall RadioGroup1Click(TObject *Sender);
    void __fastcall RadioGroup2Click(TObject *Sender);
    void __fastcall RadioGroup3Click(TObject *Sender);
    void __fastcall RadioGroup4Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CheckBox1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox12MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox5MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox6MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox7MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox8MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox9MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox10MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CheckBox11MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall CheckBox4MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall SB_SqlStandartClick(TObject *Sender);
    void __fastcall SB_StartSqlClick(TObject *Sender);
    void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
    void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
    void __fastcall ComboBox1KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __fastcall TForm4(TComponent* Owner);
    void __fastcall CheckingCancel();
    void __fastcall Checking();
    void __fastcall OnCheckBox31011Checked(int filtr);
    void __fastcall OnCheckBox49Checked(int filtr);
};
extern PACKAGE TForm4 *Form4;
#endif