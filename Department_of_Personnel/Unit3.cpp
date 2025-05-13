#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit6.h"
#include "Unit5.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit10.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
bool b=false;
String OB=" order by ", d=" desc", and=" and ";
int pos, e=2, indpos=0;                      //для сортировки таблицы Должности
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
    ZeroSql[1]="select * from SOTRUDNIK";
    ZeroSql[2]="select * from EDUCATION";
    ZeroSql[3]="select * from POSITIONS";
    ZeroSql[4]="select * from FAMILY";
    ZeroSql[5]="select * from TRUD_KNIGKA";
    ZeroSql[6]="select * from ATTESTATION";
    ZeroSql[7]="select * from POV_QUALIFICATION";
    ZeroSql[8]="select * from PROF_PODGOTOVKA";
    ZeroSql[9]="select * from NAGRADI";
    ZeroSql[10]="select * from OTPUSK";
    ZeroSql[11]="select * from SOC_LGOTI";
    ZeroSql[12]="select * from TRUD_DOGOVOR";
    ZeroSql[13]="select * from AUTORIZATION";

    BeginFiltr[1]=ZeroSql[1]+" where S_STATUS=1";
    BeginFiltr[2]=ZeroSql[3]+" where P_STATUS=1";
}
//-----------------------------выход  из учётной записи-------------------------
void __fastcall TForm3::MB_UExitClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Выйти из учётной записи","Отдел кадров",MB_YESNO|MB_ICONQUESTION)==IDYES){
        Form1->Show();
        b=true;
        Close();
    }
}//-----------------------------выход  из учётной записи-------------------------
//-----------------------------полный  выход  из  программы---------------------
void __fastcall TForm3::MB_ExitClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Закрыть приложение","Отдел кадров",MB_YESNO|MB_ICONQUESTION)==IDYES)
        Application->Terminate();
}//-----------------------------полный  выход  из  программы---------------------
//----------------------------событие  при закрытия  формы  "Отдел кадров"------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(b==false){
        Application->Terminate();
    }b=false;
}//-----------------------------событие при закрытия формы "Отдел кадров"--------
//-----------------------------редактирование данных сотрудника-------------
void __fastcall TForm3::MB_EmpInsertClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Добавить данные нового сотрудника?", "Отдел кадров", MB_YESNO|MB_ICONQUESTION)==IDYES){
        Form10->Caption="Добавление данных нового сотрудника";
        Form10->forwhat=1;    Form10->Show();
        b=true;    Close();
    }
}
void __fastcall TForm3::MB_EmpEditClick(TObject *Sender)
{
    if(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount>0){
        AnsiString EFIO="Редактировать данные сотрудника "+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString+' '+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString[1]+". "+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString[1]+". ?";
        if(MessageBoxA(Handle,EFIO.c_str(), "Отдел кадров", MB_YESNO|MB_ICONQUESTION)==IDYES){
            Form10->Caption="Редактирование данных сотрудника "+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString+' '+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString[1]+". "+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString[1]+'.';
            Form10->forwhat=2;    Form10->Show();
            b=true;    Close();
        }
    }
}
void __fastcall TForm3::MB_EmpDeleteClick(TObject *Sender)
{
    if(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount>0){
        String name=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString,
        sname=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString,
        DFIO="Перенести  данные сотрудника "+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString+' '+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString[1]+". "+DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString[1]+". в архив?";
        if(MessageBoxA(Handle,DFIO.c_str(), "Отдел кадров", MB_YESNO|MB_ICONQUESTION)==IDYES){
            DataModule2->IBDataSet13_TRUD_DOGOVOR->Edit();
            DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_D_STATUS")->AsInteger=0;
            DataModule2->IBDataSet13_TRUD_DOGOVOR->Post();
            DataModule2->IBDataSet13_TRUD_DOGOVOR->Close();
            DataModule2->IBDataSet13_TRUD_DOGOVOR->Open();

            DataModule2->IBDataSet6_TRUD_KNIGKA->Insert();
            DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ID_S")->AsInteger=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID")->AsInteger;
            DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("TR_DATE")->AsDateTime=Date();
            DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("OSNOVANIYE")->AsString="Увольнение сотрудника с должности "+DataModule2->IBDataSet3_POSITIONS->FieldByName("POS_NAME")->AsString;
            DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ORDERBY")->AsString="Приказ №2 от "+Date().DateString();
            DataModule2->IBDataSet6_TRUD_KNIGKA->Post();
            DataModule2->IBDataSet6_TRUD_KNIGKA->Close();
            DataModule2->IBDataSet6_TRUD_KNIGKA->Open();

            DataModule2->IBDataSet1_SOTRUDNIK->Edit();
            DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("S_STATUS")->AsInteger=0;
            DataModule2->IBDataSet1_SOTRUDNIK->Post();
            DataModule2->IBDataSet1_SOTRUDNIK->Close();
            DataModule2->IBDataSet1_SOTRUDNIK->Open();

        }
    }
}//--------------------------редактирование  данных  сотрудника------------------
//-----------------функция  запроса  для  сортировка  таблицы  сотрудники-------
void __fastcall TForm3::woEmp()
{
    String SqlEmployee[]={"TAB_NOMER","SURNAME","NAME","SECONDNAME","POL","ID_POS","INN","SNILS"};
    String query="", posq="";
    if(Form3->sqlEmp.sqlfiltr[0]>0){          //фильтрация
        query+=and;

        switch(Form3->sqlEmp.sqlfiltr[0]){
              case 1: query+=SqlEmployee[0]+'='+StrToInt(Form4->ComboBox1->Text);     //по таб. номер

                     break;
              case 2: query+=SqlEmployee[1]+'='+Form4->Edit1->Text;     //по фамилии
                      for(int i=1;i<6;i++)
                      {
                          switch(Form3->sqlEmp.sqlfiltr[i]){
                                case 3: query+=and+SqlEmployee[2]+'='+Form4->Edit2->Text;  // +++ по имени
                                       break;

                                case 4: query+=and+SqlEmployee[3]+'='+Form4->Edit3->Text;  // +++ по отчеству
                                       break;

                                case 5: query+=and+SqlEmployee[4]+"='"+Form4->ComboBox2->Text+"'";  // +++ по полу
                                       break;

                                case 6: posq+=and+"POS_NAME='"+Form4->ComboBox3->Text+"'"; // +++ по должности
                                       break;

                                case 7: posq+=and+"SALARY="+StrToInt(Form4->ComboBox4->Text); // +++ по окладу
                                       break;
                                default: break;
                          }
                      }
                     break;

              case 3: query+=SqlEmployee[2]+'='+Form4->Edit2->Text;  //по имени
                      for(int i=1;i<6;i++)
                      {
                          switch(Form3->sqlEmp.sqlfiltr[i]){
                                case 2: query+=and+SqlEmployee[1]+'='+Form4->Edit1->Text;  // +++ по фамилии
                                       break;

                                case 4: query+=and+SqlEmployee[3]+'='+Form4->Edit3->Text;  // +++ по отчеству
                                       break;

                                case 5: query+=and+SqlEmployee[4]+"='"+Form4->ComboBox2->Text+"'";  // +++ по полу
                                       break;

                                case 6: posq+=and+"POS_NAME='"+Form4->ComboBox3->Text+"'"; // +++ по должности
                                       break;

                                case 7: posq+=and+"SALARY="+StrToInt(Form4->ComboBox4->Text); // +++ по окладу
                                       break;
                                default: break;
                          }
                      }
                     break;

              case 4: query+=SqlEmployee[3]+'='+Form4->Edit3->Text;  //по отчеству
                      for(int i=1;i<6;i++)
                      {
                          switch(Form3->sqlEmp.sqlfiltr[i]){
                                case 2: query+=and+SqlEmployee[1]+'='+Form4->Edit1->Text;  // +++ по фамилии
                                       break;

                                case 3: query+=and+SqlEmployee[2]+'='+Form4->Edit2->Text;  // +++ по имени
                                       break;

                                case 5: query+=and+SqlEmployee[4]+"='"+Form4->ComboBox2->Text+"'";  // +++ по полу
                                       break;

                                case 6: posq+=and+"POS_NAME='"+Form4->ComboBox3->Text+"'"; // +++ по должности
                                       break;

                                case 7: posq+=and+"SALARY="+StrToInt(Form4->ComboBox4->Text); // +++ по окладу
                                       break;
                                default: break;
                          }
                      }
                     break;

              case 5: query+=SqlEmployee[4]+"='"+Form4->ComboBox2->Text+"'";  //по полу
                      for(int i=1;i<6;i++)
                      {
                          switch(Form3->sqlEmp.sqlfiltr[i]){
                                case 2: query+=and+SqlEmployee[1]+'='+Form4->Edit1->Text;  // +++ по фамилии
                                       break;
                                case 3: query+=and+SqlEmployee[2]+'='+Form4->Edit2->Text;  // +++ по имени
                                       break;
                                case 4: query+=and+SqlEmployee[3]+"='"+Form4->Edit3->Text+"'";  // +++ по отчеству
                                       break;
                                case 6: posq+=and+and+"POS_NAME='"+Form4->ComboBox3->Text+"'"; // +++ по должности
                                       break;
                                case 7: posq+=and+"SALARY="+StrToInt(Form4->ComboBox4->Text); // +++ по окладу
                                       break;
                                default: break;
                          }
                      }
                     break;

              case 6: posq=and+"POS_NAME='"+Form4->ComboBox3->Text+"'"; //по должности
                      for(int i=1;i<6;i++)
                      {
                          switch(Form3->sqlEmp.sqlfiltr[i]){
                                case 2: query+=and+SqlEmployee[1]+'='+Form4->Edit1->Text;  // +++ по фамилии
                                       break;

                                case 3: query+=and+SqlEmployee[2]+'='+Form4->Edit2->Text;  // +++ по имени
                                       break;

                                case 4: query+=and+SqlEmployee[3]+"='"+Form4->Edit3->Text+"'";  // +++ по отчеству
                                       break;

                                case 5: query+=and+SqlEmployee[4]+"='"+Form4->ComboBox2->Text+"'";  // +++ по полу
                                       break;

                                case 7: posq+=and+"SALARY="+StrToInt(Form4->ComboBox4->Text); // +++ по окладу
                                       break;
                                default: break;
                          }
                      }
                     break;

              case 7: posq=and+"SALARY="+StrToInt(Form4->ComboBox4->Text); //по окладу
                      for(int i=1;i<6;i++)
                      {
                          switch(Form3->sqlEmp.sqlfiltr[i]){
                                case 2: query+=and+SqlEmployee[1]+'='+Form4->Edit1->Text;  // +++ по фамилии
                                       break;

                                case 3: query+=and+SqlEmployee[2]+'='+Form4->Edit2->Text;  // +++ по имени
                                       break;

                                case 4: query+=and+SqlEmployee[3]+"='"+Form4->Edit3->Text+"'";  // +++ по отчеству
                                       break;

                                case 5: query+=and+SqlEmployee[4]+"='"+Form4->ComboBox2->Text+"'";  // +++ по полу
                                       break;

                                case 6: posq=and+"POS_NAME='"+Form4->ComboBox3->Text+"'"; // +++ по должности
                                       break;
                                default: break;
                          }
                      }
                     break;

              case 8: query+=SqlEmployee[6]+"='"+StrToInt(Form4->Edit4->Text)+"'";     //по ИНН
                     break;

              case 9: query+=SqlEmployee[7]+"='"+StrToInt(Form4->Edit5->Text)+"'";     //по СНИЛС
                     break;
        }
    }
    if(Form3->sqlEmp.sqlsort>0){              //сортировка
        query+=OB;
        switch(Form3->sqlEmp.sqlsort)         
        {
        case 1: query+=SqlEmployee[0];
               break;
        case 2: query+=SqlEmployee[0]+d;
               break;
        case 3: query+=SqlEmployee[1];
               break;
        case 4: query+=SqlEmployee[1]+d;
               break;
        case 5: query+=SqlEmployee[2];
               break;
        case 6: query+=SqlEmployee[2]+d;
               break;
        case 7: query+=SqlEmployee[3];
               break;
        case 8: query+=SqlEmployee[3]+d;
               break;
        }
    }
    if(posq!=""){
        posq=BeginFiltr[2]+posq;
        query=SqlEmployee[5]+"=:ID"+query;
    }else{
        posq=BeginFiltr[2]+" and ID=:ID_POS";
    }
    query=BeginFiltr[1]+query;
    ShowMessage(query+"   ,   "+posq);
    DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,posq);
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,query);
}//-----------------функция  запроса  для  сортировка  таблицы  сотрудники-------
//-------------сортировка  и  фильтрация  таблицы  сотрудники-------------------
void __fastcall TForm3::SB_EmpOrderByClick(TObject *Sender)//начиная с сортировки без фильтрации
{
    Form4->Show();
}
//-----------------функция  запроса  для  сортировки  таблицы  должностей-------
void __fastcall TForm3::woPos()
{
    String PosSql[]={"POS_NAME","SALARY"};
    switch(pos){  //сортировка таблицы POSITIONS
        case 1: DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,ZeroSql[3]);
               break;
        case 2: DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,ZeroSql[3]+OB+PosSql[0]);
               break;
        case 3: DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,ZeroSql[3]+OB+PosSql[0]+d);
               break;
        case 4: DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,ZeroSql[3]+OB+PosSql[1]);
               break;
        case 5: DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,ZeroSql[3]+OB+PosSql[1]+d);
               break;
    }
}//-----------------функция  запроса  для сортировки  таблиы должностей----------
//-----------------------------сортировка  таблицы  должностей------------------
void __fastcall TForm3::CheckBoxPosClick(TObject *Sender)//без сортировки
{
    if(CheckBoxPos->Checked==false){
        switch(e){
            case 2:
            case 3: RadioGroup4->ItemIndex=indpos;
                    RadioGroup5->ItemIndex=-1;
                   break;
            case 4:
            case 5: RadioGroup4->ItemIndex=-1;
                    RadioGroup5->ItemIndex=indpos;
        }pos=e;
    }else{
        RadioGroup4->ItemIndex=-1;
        RadioGroup5->ItemIndex=-1;
        pos=1;
    }
    woPos();
}
void __fastcall TForm3::RadioGroup5Click(TObject *Sender) //сортировка по окладу
{
    CheckBoxPos->Checked=false;
    RadioGroup4->ItemIndex=-1;
    indpos=RadioGroup5->ItemIndex;
    if(indpos==0){
        pos=4;
    }else if(indpos==1){
        pos=5;
    }
    e=pos;
    woPos();
}
void __fastcall TForm3::RadioGroup4Click(TObject *Sender) //сортировка по должности
{
    CheckBoxPos->Checked=false;
    RadioGroup5->ItemIndex=-1;
    indpos=RadioGroup4->ItemIndex;
    if(indpos==0)
        pos=2;
    else if(indpos==1)
        pos=3;
    e=pos;
    woPos();
}//-----------------------------сортировка  таблицы  должностей------------------
//-----------------------------кнопки  прокрутки  таблицы  Сотрудники-----------
void __fastcall TForm3::SB_EmpFirstClick(TObject *Sender)//кнопка прокрутки "Первый"
{
    DataModule2->IBDataSet1_SOTRUDNIK->First();//выбор первего из таблицы "Сотрудники"
}
void __fastcall TForm3::SB_EmpPriorClick(TObject *Sender)//кнопка прокрутки "Предыдущий"
{
    DataModule2->IBDataSet1_SOTRUDNIK->Prior();//выбор предыдущего из таблицы "Сотрудники"
}
void __fastcall TForm3::SB_EmpNextClick(TObject *Sender)//кнопка прокрутки "Следующий"
{
    DataModule2->IBDataSet1_SOTRUDNIK->Next();//выбор следующего из таблицы "Сотрудники"
}
void __fastcall TForm3::SB_EmpLastClick(TObject *Sender)//кнопка прокрутки "Последний"
{
    DataModule2->IBDataSet1_SOTRUDNIK->Last();//выбор последнего из таблицы "Сотрудни"
}//-----------------------------кнопки прокрутки--таблицы  Сотрудники------------
//-----------------------------кнопки прокрутки--таблицы  Должности------------
void __fastcall TForm3::SB_PosFirstClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->First();
    NumRecord_Pos->Caption=DataModule2->IBDataSet3_POSITIONS->RecNo;
}
void __fastcall TForm3::SB_PosPriorClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->Prior();
    NumRecord_Pos->Caption=DataModule2->IBDataSet3_POSITIONS->RecNo;
}
void __fastcall TForm3::SB_PosNextClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->Next();
    NumRecord_Pos->Caption=DataModule2->IBDataSet3_POSITIONS->RecNo;
}
void __fastcall TForm3::SB_PosLastClick(TObject *Sender)
{
    DataModule2->IBDataSet3_POSITIONS->Last();
    NumRecord_Pos->Caption=DataModule2->IBDataSet3_POSITIONS->RecNo;
}//-----------------------------кнопки прокрутки--таблицы  Должности------------
void __fastcall TForm3::FormShow(TObject *Sender)//начальные координаты формы
{
    Left=21;
    Top=21;
    if(DataModule2->IBDataSet3_POSITIONS->RecordCount>0){
        NumRecord_Pos->Caption=IntToStr(DataModule2->IBDataSet3_POSITIONS->RecNo);
        CountRecord_Pos->Caption=IntToStr(DataModule2->IBDataSet3_POSITIONS->RecordCount);
    }
    if(PageControl1->ActivePage==TabSheet1){
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, BeginFiltr[1]);
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, ZeroSql[3]+" where ID=:ID_POS");
    }else{
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, BeginFiltr[2]);
    }
}
void __fastcall TForm3::FormCreate(TObject *Sender)//при создании формы "Отдел кадров"
{                                                  //очишаем массив sqlfiltr
    for(int i=0;i<6;i++)                           // структуры sqlEmp
    {    sqlEmp.sqlfiltr[i]=0;                     //(этот массив для фильтрации)
    }
}
void __fastcall TForm3::MB_PInsertClick(TObject *Sender)//добавление должности
{
    if(MessageBoxA(Handle,"Добавить новую должность?","Отдел кадров",MB_YESNO|MB_ICONQUESTION)==IDYES){
        CheckBoxPos->Checked=true;    RadioGroup4->ItemIndex=-1;    RadioGroup5->ItemIndex=-1;
        Form4->Close();
        Form6->IorE=true;         //если true
        Form6->Show(); Hide();    // то открываем для добавления должности
    }
}
void __fastcall TForm3::MB_PEditClick(TObject *Sender)//редактирование должности
{
    IDPOS=DataModule2->IBDataSet3_POSITIONS->FieldByName("ID")->AsInteger;
    int recpos=DataModule2->IBDataSet3_POSITIONS->RecNo;
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,BeginFiltr[1]+and+"ID_POS="+IDPOS);
    if(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount>0){
        String reccot="Сотрудники("+IntToStr(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount)+") в этой должности ещё работают!";
        MessageBoxA(Handle,reccot.c_str(),"Отдел кадров",MB_OK);
    }else{
        if(MessageBoxA(Handle,"Редактировать выбранную должность?","Отдел кадров",MB_YESNO|MB_ICONQUESTION)==IDYES){
            CheckBoxPos->Checked=true;    RadioGroup4->ItemIndex=-1;    RadioGroup5->ItemIndex=-1;
            Form4->Close();
            Form6->IorE=false;         //если false
            Form6->Show(); Hide();     // то открываем для редактирования
        }
    }
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, BeginFiltr[1]);
    DataModule2->IBDataSet3_POSITIONS->RecNo=recpos;
}
void __fastcall TForm3::MB_PDeleteClick(TObject *Sender)//удаление должности
{
    int IdPOS=DataModule2->IBDataSet3_POSITIONS->FieldByName("ID")->AsInteger;
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,BeginFiltr[1]+and+"ID_POS="+IdPOS);
    if(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount>0){
        String reccot="Сотрудники("+IntToStr(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount)+") с такой должностью ещё работают!";
        MessageBoxA(Handle,reccot.c_str(),"Отдел кадров",MB_OK);
    }else{
        if(MessageBoxA(Handle,"Перенести выбранную должность в архив?","Отдел кадров",MB_YESNO|MB_ICONQUESTION)==IDYES){
            DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, ZeroSql[3]+" where ID="+IdPOS);
            DataModule2->IBDataSet3_POSITIONS->Edit();
            DataModule2->IBDataSet3_POSITIONS->FieldByName("P_STATUS")->AsInteger=0;
            DataModule2->IBDataSet3_POSITIONS->Post();
            CheckBoxPos->Checked=true;    RadioGroup4->ItemIndex=-1;    RadioGroup5->ItemIndex=-1;
            DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS,BeginFiltr[2]);
            NumRecord_Pos->Caption=DataModule2->IBDataSet3_POSITIONS->RecNo;
            CountRecord_Pos->Caption=DataModule2->IBDataSet3_POSITIONS->RecordCount;
        }
    }
    DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,BeginFiltr[1]);
}
void __fastcall TForm3::SB_PreviewClick(TObject *Sender)
{
    if(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount>0){
        AnsiString id=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID")->AsString;
        sqlEmp.recno=DataModule2->IBDataSet1_SOTRUDNIK->RecNo;
        sqlEmp.sqlline=DataModule2->IBDataSet1_SOTRUDNIK->SelectSQL->Text;
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK,BeginFiltr[1]+and+"ID="+id);
        Form3->Hide();
        TQRChildBand *TRDChildBand[3];
        TQRLabel *QRLabels;
        TQRDBRichText *QRDBRichTexts;
        Form5->QuickRep1->Preview();
    }
}
void __fastcall TForm3::MB_LPClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Для того, чтобы поменять логин и пароль необходимо подтверждение. Поменять логин и пароль?","Окно подтерждения",MB_YESNO)==IDYES){
        Form7->lporU=false; Form7->Show();    b=true;    Close();
    }
}
void __fastcall TForm3::MB_LPUAClick(TObject *Sender)
{
    if(MessageBoxA(Handle,"Для перехода на форму 'Пользователи' необходимо подтвердить логин и пароль. \nПерейти?","Окно подтерждения",MB_YESNO|MB_ICONQUESTION)==IDYES){
        Form7->lporU=true;    Form7->Show();    b=true;    Close();
    }
}
void __fastcall TForm3::MB_ArkhEmpClick(TObject *Sender)
{
    Form9->EmpORPos=true;    Form9->Show();
    b=true;    Close();
}
void __fastcall TForm3::MB_ArkhPClick(TObject *Sender)
{
    Form9->EmpORPos=false;    Form9->Show();
    b=true;    Close();

}
void __fastcall TForm3::PageControl1Change(TObject *Sender)
{
    if(PageControl1->ActivePage==TabSheet1){
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, BeginFiltr[1]);
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, ZeroSql[3]+" where ID=:ID_POS");
    }else{
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, BeginFiltr[2]);
    }
}