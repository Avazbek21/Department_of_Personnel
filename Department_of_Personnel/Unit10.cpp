#include <vcl.h>
#pragma hdrstop
#include "Unit10.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit9.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
bool notempty[43], ntrk=false;
int rec=0; String post;
__fastcall TForm10::TForm10(TComponent* Owner)
    : TForm(Owner)
{ 
}
void __fastcall TForm10::FormCreate(TObject *Sender)
{
    Constraints->MaxHeight=1038;    Constraints->MinHeight=212;
    Constraints->MaxWidth=920;     Constraints->MinWidth=920;
    Height=1038;      Width=920;
    Panel1->Left=55;    Panel2->Left=55;    Panel3->Left=55;    Panel4->Left=55;

    StringGrid1->Cells[0][0]="Степень родства";
    StringGrid1->Cells[1][0]="Фамилия Имя Отчества";
    StringGrid1->Cells[2][0]="День рождения";

    StringGrid4->Cells[0][0]="день";
    StringGrid4->Cells[1][0]="месяц";
    StringGrid4->Cells[2][0]="лет";
    StringGrid4->Cells[3][0]="день";
    StringGrid4->Cells[4][0]="месяц";
    StringGrid4->Cells[5][0]="лет";
    StringGrid4->Cells[6][0]="день";
    StringGrid4->Cells[7][0]="месяц";
    StringGrid4->Cells[8][0]="лет";

    StringGrid5->Cells[0][0]="Дата";
    StringGrid5->Cells[1][0]="Сведение о работе";
    StringGrid5->Cells[2][0]="Основание";

    MaskEdit1->Text="+7 (000) 000-00-00";
}
void __fastcall TForm10::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(forwhat==3){
        Form9->Show();
    }else{
        Form3->Show();
    }
    MaskEdit1->Clear();
    MaskEdit1->Refresh();
    MaskEdit1->Text="+7 (000) 000-00-00";
}
void __fastcall TForm10::FormShow(TObject *Sender)
{
    Top=0;    ntrk=false;
    ComboBox1->Clear();
    DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->BeginFiltr[2]);
    for(DataModule2->IBDataSet3_POSITIONS->First(); !DataModule2->IBDataSet3_POSITIONS->Eof; DataModule2->IBDataSet3_POSITIONS->Next())
    {   ComboBox1->Items->Add(DataModule2->IBDataSet3_POSITIONS->FieldByName("POS_NAME")->AsString);
    }   
    if(forwhat==1){                    //при добавлении данных сотрудника
        for(int i=0; i<33 && i!=13; i++)
        {   notempty[i]=false;
        }
        notempty[13]=true;
        for(int i=33; i<43; i++)
        {   notempty[i]=true;
        }
        DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->ZeroSql[1]);
        DataModule2->IBDataSet1_SOTRUDNIK->Last();
        int tab=0;
        if(DataModule2->IBDataSet1_SOTRUDNIK->RecordCount>0){
            tab=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("TAB_NOMER")->AsInteger;
        }
        Edit2->Text=IntToStr(tab+1);
        Edit1->Text="";        Edit3->Text="";     Edit4->Text="";
        Edit5->Text="";        DateTimePicker1->Date=IncYear(Date(),-18);
        ComboBox2->Text="";    Edit6->Text="";     Edit7->Text="";
        ComboBox1->Text="";    Edit9->Text="";     DateTimePicker2->Date=Date();
        Edit10->Text="";       Edit13->Text="";    Edit14->Text="";
        Edit11->Text="";       Edit12->Text="";    DateTimePicker3->Date=Date();
        Edit15->Text="";       Edit16->Text="";    Edit17->Text="";
        DateTimePicker4->Date=Date();     StringGrid4->Cells[0][1]="";
        StringGrid4->Cells[1][1]="";      StringGrid4->Cells[2][1]="";
        StringGrid4->Cells[3][1]="";      StringGrid4->Cells[4][1]="";
        StringGrid4->Cells[5][1]="";      StringGrid4->Cells[6][1]="";
        StringGrid4->Cells[7][1]="";      StringGrid4->Cells[8][1]="";
        ComboBox3->Text="";    Edit18->Text="";                Edit19->Text="";
        ComboBox4->Text="";    Edit20->Text="";                Edit21->Text="";
        Edit22->Text="";       Edit23->Text="";                Edit24->Text="";
        Edit25->Text="";       DateTimePicker6->Date=Date();   Memo1->Text="";

        for(int i=1; i<6; i++)          //состав семьи
        {   StringGrid1->Cells[0][i]="";    StringGrid1->Cells[1][i]="";
            StringGrid1->Cells[2][i]="";
        }

        for(int i=0; i<5; i++)      //образование
        {   StringGrid2->Cells[0][i]="";    StringGrid2->Cells[1][i]="";
            StringGrid2->Cells[2][i]="";    StringGrid2->Cells[3][i]="";
            StringGrid2->Cells[4][i]="";    StringGrid2->Cells[5][i]="";
            StringGrid2->Cells[6][i]="";
        }

        for(int i=0; i<5; i++)          //послевузовское образование
        {   StringGrid3->Cells[0][i]="";    StringGrid3->Cells[1][i]="";
            StringGrid3->Cells[2][i]="";    StringGrid3->Cells[3][i]="";
            StringGrid3->Cells[4][i]="";    StringGrid3->Cells[5][i]="";
        }

        StringGrid5->RowCount=8;        //трудовая деятельность
        for(int i=1; i<8; i++)
        {   StringGrid5->Cells[0][i]="";    StringGrid5->Cells[1][i]="";
            StringGrid5->Cells[2][i]="";
        }

        StringGrid6->RowCount=5;        //аттестация в предприятии
        for(int i=0; i<5; i++)
        {   StringGrid6->Cells[0][i]="";    StringGrid6->Cells[1][i]="";
            StringGrid6->Cells[2][i]="";    StringGrid6->Cells[3][i]="";
            StringGrid6->Cells[4][i]="";
        }

        for(int i=0; i<5; i++)          //повышение квалификации
        {   StringGrid7->Cells[0][i]="";    StringGrid7->Cells[1][i]="";
            StringGrid7->Cells[2][i]="";    StringGrid7->Cells[3][i]="";
            StringGrid7->Cells[4][i]="";    StringGrid7->Cells[5][i]="";
            StringGrid7->Cells[6][i]="";    StringGrid7->Cells[7][i]="";
        }

        StringGrid8->RowCount=4;
        for(int i=0; i<4; i++)     //профессиональная переподготовка
        {   StringGrid8->Cells[0][i]="";    StringGrid8->Cells[1][i]="";
            StringGrid8->Cells[2][i]="";    StringGrid8->Cells[3][i]="";
            StringGrid8->Cells[4][i]="";    StringGrid8->Cells[5][i]="";
            StringGrid8->Cells[6][i]="";
        }

        StringGrid9->RowCount=4;
        for(int i=0; i<4; i++)     //награды (поощрения), почётные звания
        {   StringGrid9->Cells[0][i]="";    StringGrid9->Cells[1][i]="";
            StringGrid9->Cells[2][i]="";    StringGrid9->Cells[3][i]="";
        }

        StringGrid10->RowCount=5;
        for(int i=0; i<5; i++)     //отпуска
        {   StringGrid10->Cells[0][i]="";   StringGrid10->Cells[1][i]="";
            StringGrid10->Cells[2][i]="";   StringGrid10->Cells[3][i]="";
            StringGrid10->Cells[4][i]="";   StringGrid10->Cells[5][i]="";
            StringGrid10->Cells[6][i]="";
        }

        StringGrid11->RowCount=3;
        for(int i=0; i<3; i++)     //социальные льготы
        {   StringGrid11->Cells[0][i]="";   StringGrid11->Cells[1][i]="";
            StringGrid11->Cells[2][i]="";   StringGrid11->Cells[3][i]="";
        }
        Memo2->Text="";
        Memo3->Text="";
        Memo4->Text="";
        Memo5->Text="";
        Memo6->Text="";
        Memo7->Text="";
        Memo8->Text="";
        Memo9->Text="";
        DateTimePicker5->Date=Date();
    }else{                 //при редактировании данных
        if(forwhat==2){
            for(int i=0; i<43; i++)
            {   notempty[i]=true;
            }
            //DataModule2->SelectSql(DataModule2->IBDataSet13_TRUD_DOGOVOR, Form3->ZeroSql[12]+" where ID_S=:ID and ID_D_STATUS=1")
            Memo2->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("PREDMET")->AsString;
            Memo3->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_OPL_TR")->AsString;
            Memo4->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("REGIM_W")->AsString;
            Memo5->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_SOCSTR")->AsString;
            Memo6->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_TR")->AsString;
            Memo7->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("DOP_USL")->AsString;
            Memo8->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ADDRESS_REKV")->AsString;
            Memo9->Text=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("NOTM_ACTS")->AsString;
            DateTimePicker5->Date=DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("D_FINDATE")->AsDateTime;

        }else{
            for(int i=0; i!=23 && i<26; i++)
            {   notempty[i]=true;
            }
            for(int i=33; i<43; i++)
            {   notempty[i]=true;
            }
            notempty[23]=false;
            for(int i=26; i<33; i++)
            {   notempty[i]=false;
            }

            Memo2->Text="";
            Memo3->Text="";
            Memo4->Text="";
            Memo5->Text="";
            Memo6->Text="";
            Memo7->Text="";
            Memo8->Text="";
            Memo9->Text="";
            DateTimePicker5->Date=Date();

        }
        Edit2->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("TAB_NOMER")->AsInteger;
        Edit1->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME_COMPANY")->AsString;
        Edit3->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString;
        Edit4->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString;
        Edit5->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString;
        DateTimePicker1->Date=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_BIRTH")->AsDateTime;
        ComboBox2->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("POL")->AsString;
        Edit6->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CITIZENSHIP")->AsString;
        Edit7->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("BIRTH_ADDRESS")->AsString;
        ComboBox1->Text=Form3->posEmployee;
        Edit9->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SN_PASPORT")->AsString;
        DateTimePicker2->Date=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_ISSUED")->AsDateTime;
        Edit10->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("WHOM_ISSUED")->AsString;
        Edit13->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("INN")->AsString;
        Edit14->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNILS")->AsString;
        Edit11->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS")->AsString;
        Edit12->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS_FACT")->AsString;
        DateTimePicker3->Date=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_REGIST")->AsDateTime;
        MaskEdit1->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KONTAKT_NOMER")->AsString;
        Edit15->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOSTVBRAKE")->AsString;
        Edit16->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_NAME")->AsString;
        Edit17->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_LEVEL")->AsString;
        DateTimePicker4->Date=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STAG_RABOTI")->AsDateTime;
        StringGrid4->Cells[0][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_D")->AsInteger;
        StringGrid4->Cells[1][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_M")->AsInteger;
        StringGrid4->Cells[2][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_Y")->AsInteger;
        StringGrid4->Cells[3][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_D")->AsInteger;
        StringGrid4->Cells[4][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_M")->AsInteger;
        StringGrid4->Cells[5][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_Y")->AsInteger;
        StringGrid4->Cells[6][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_D")->AsInteger;
        StringGrid4->Cells[7][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_M")->AsInteger;
        StringGrid4->Cells[8][1]=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_Y")->AsInteger;
        ComboBox3->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CAT_ZAPASA")->AsString;
        Edit18->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ZVANIYE")->AsString;
        Edit19->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("PROFIL")->AsString;
        ComboBox4->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KAT_GODN")->AsString;
        Edit20->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_VUS")->AsString;
        Edit21->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("MLTR_NAME")->AsString;
        Edit22->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOS_NA_UCHET")->AsString;
        Edit23->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNYATS_UCHETA")->AsString;
        Edit24->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("FIO_EMP_DP")->AsString;
        Edit25->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("EMP_DP_POS")->AsString;
        DateTimePicker6->Date=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_UCHET")->AsDateTime;
        Memo1->Text=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DOP_SVEDENIYA")->AsString;

        DataModule2->IBDataSet5_FAMILY->First();
        for(int i=1; i<5 && !DataModule2->IBDataSet5_FAMILY->Eof; i++)                //состав семьи
        {   StringGrid1->Cells[0][i]=DataModule2->IBDataSet5_FAMILY->FieldByName("STEPEN_RODS")->AsString;
            StringGrid1->Cells[1][i]=DataModule2->IBDataSet5_FAMILY->FieldByName("FIO")->AsString;
            StringGrid1->Cells[2][i]=DataModule2->IBDataSet5_FAMILY->FieldByName("DATE_BIRTH")->AsString;
            DataModule2->IBDataSet5_FAMILY->Next();
        }

        DataModule2->IBDataSet2_EDUCATION->First();
        for(int i=0; i<5 && !DataModule2->IBDataSet2_EDUCATION->Eof; i++)                     //образование
        {   StringGrid2->Cells[0][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("E_NAME")->AsString;
            StringGrid2->Cells[1][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("T_DOC")->AsString;
            StringGrid2->Cells[2][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("E_SN")->AsString;
            StringGrid2->Cells[3][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("D_ISSD")->AsString;
            StringGrid2->Cells[4][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("QUALIF")->AsString;
            StringGrid2->Cells[5][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("SPEC")->AsString;
            StringGrid2->Cells[6][i]=DataModule2->IBDataSet2_EDUCATION->FieldByName("T_E")->AsString;
            DataModule2->IBDataSet2_EDUCATION->Next();
        }

        DataModule2->IBDataSet4_AFTER_EDUCATION->First();
        for(int i=0; i<5 && !DataModule2->IBDataSet4_AFTER_EDUCATION->Eof; i++)                           //послевузовское образование
        {   StringGrid3->Cells[0][i]=DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_NAME")->AsString;
            StringGrid3->Cells[1][i]=DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_DOC")->AsString;
            StringGrid3->Cells[2][i]=DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_SN")->AsString;
            StringGrid3->Cells[3][i]=DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("D_ISSD")->AsString;
            StringGrid3->Cells[4][i]=DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_E")->AsString;
            StringGrid3->Cells[5][i]=DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("SPEC")->AsString;
            DataModule2->IBDataSet4_AFTER_EDUCATION->Next();
        }

        StringGrid5->RowCount=DataModule2->IBDataSet6_TRUD_KNIGKA->RecordCount+2;
        StringGrid5->FixedRows=1;
        DataModule2->IBDataSet6_TRUD_KNIGKA->First();
        for(int i=1; i<StringGrid5->RowCount; i++)     //трудовая деятельность
        {   StringGrid5->Cells[0][i]=DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("TR_DATE")->AsString;
            StringGrid5->Cells[1][i]=DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("OSNOVANIYE")->AsString;
            StringGrid5->Cells[2][i]=DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ORDERBY")->AsString;
            DataModule2->IBDataSet6_TRUD_KNIGKA->Next();
        }
        StringGrid6->RowCount=DataModule2->IBDataSet7_ATTESTATION->RecordCount;
        DataModule2->IBDataSet7_ATTESTATION->First();
        for(int i=0; i<StringGrid6->RowCount && !DataModule2->IBDataSet7_ATTESTATION->Eof; i++)     //аттестация в предприятии
        {   StringGrid6->Cells[0][i]=DataModule2->IBDataSet7_ATTESTATION->FieldByName("DATEATTESTAT")->AsString;
            StringGrid6->Cells[1][i]=DataModule2->IBDataSet7_ATTESTATION->FieldByName("RESH_KOMISSII")->AsString;
            StringGrid6->Cells[2][i]=DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_NOMER")->AsString;
            StringGrid6->Cells[3][i]=DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_DATE")->AsString;
            StringGrid6->Cells[4][i]=DataModule2->IBDataSet7_ATTESTATION->FieldByName("OSNPVANIYE")->AsString;
            DataModule2->IBDataSet7_ATTESTATION->Next();
        }

        DataModule2->IBDataSet8_POV_QUALIFICATION->First();
        for(int i=0; i<5 && !DataModule2->IBDataSet8_POV_QUALIFICATION->Eof; i++)     //повышение квалификации
        {   StringGrid7->Cells[0][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_BEG_ST")->AsString;
            StringGrid7->Cells[1][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_FIN_ST")->AsString;
            StringGrid7->Cells[2][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_VID")->AsString;
            StringGrid7->Cells[3][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("NAME_ST_ADR")->AsString;
            StringGrid7->Cells[4][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_NAME")->AsString;
            StringGrid7->Cells[5][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_SN")->AsString;
            StringGrid7->Cells[6][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_DATE")->AsString;
            StringGrid7->Cells[7][i]=DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_OSNV")->AsString;
            DataModule2->IBDataSet8_POV_QUALIFICATION->Next();
        }

        StringGrid8->RowCount=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->RecordCount;
        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->First();
        for(int i=0; i<StringGrid8->RowCount && !DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Eof; i++)     //профессиональная переподготовка
        {   StringGrid8->Cells[0][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DBEG")->AsString;
            StringGrid8->Cells[1][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DFIN")->AsString;
            StringGrid8->Cells[2][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("SPECIAL")->AsString;
            StringGrid8->Cells[3][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_NAME")->AsString;
            StringGrid8->Cells[4][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_SN")->AsString;
            StringGrid8->Cells[5][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DATE")->AsString;
            StringGrid8->Cells[6][i]=DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_OSNV")->AsString;
            DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Next();
        }

        StringGrid9->RowCount=DataModule2->IBDataSet10_NAGRADI->RecordCount;
        DataModule2->IBDataSet10_NAGRADI->First();
        for(int i=0; i<StringGrid9->RowCount && !DataModule2->IBDataSet10_NAGRADI->Eof; i++)     //награды (поощрения), почётные звания
        {   StringGrid9->Cells[0][i]=DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_NAME")->AsString;
            StringGrid9->Cells[1][i]=DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DNAME")->AsString;
            StringGrid9->Cells[2][i]=DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DDATE")->AsString;
            StringGrid9->Cells[3][i]=DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DOC_SN")->AsString;
            DataModule2->IBDataSet10_NAGRADI->Next();
        }

        StringGrid10->RowCount=DataModule2->IBDataSet11_OTPUSK->RecordCount;
        DataModule2->IBDataSet11_OTPUSK->First();
        for(int i=0; i<StringGrid10->RowCount && !DataModule2->IBDataSet11_OTPUSK->Eof; i++)     //отпуска
        {   StringGrid10->Cells[0][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_VID")->AsString;
            StringGrid10->Cells[1][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEB")->AsString;
            StringGrid10->Cells[2][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEF")->AsString;
            StringGrid10->Cells[3][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DAYS")->AsString;
            StringGrid10->Cells[4][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEB")->AsString;
            StringGrid10->Cells[5][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEF")->AsString;
            StringGrid10->Cells[6][i]=DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_OSNOVA")->AsString;
            DataModule2->IBDataSet11_OTPUSK->Next();
        }

        StringGrid11->RowCount=DataModule2->IBDataSet12_SOC_LGOTI->RecordCount;
        DataModule2->IBDataSet12_SOC_LGOTI->First();
        for(int i=0; i<StringGrid11->RowCount && !DataModule2->IBDataSet12_SOC_LGOTI->Eof; i++)     //социальные льготы
        {   StringGrid11->Cells[0][i]=DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_NAME")->AsString;
            StringGrid11->Cells[1][i]=DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_NOMER")->AsString;
            StringGrid11->Cells[2][i]=DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_DATE")->AsString;
            StringGrid11->Cells[3][i]=DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_OSNOVA")->AsString;
            DataModule2->IBDataSet12_SOC_LGOTI->Next();
        }
    }
    Label100->Caption=Edit2->Text;
    Label7->Caption=Date();
}
void __fastcall TForm10::Edit13KeyPress(TObject *Sender, char &Key)
{
    if(Key==8 || Key>='0' && Key<='9'){
        Key=Key;
        if(Edit13->Text==""){
            notempty[8]=false;
        }else{
            Edit13->Color=clWindow;
            notempty[8]=true;
        }
    }else{
        Key=0;
    }
}
void __fastcall TForm10::Edit14KeyPress(TObject *Sender, char &Key)
{
    if(Key==8 || Key=='-' || Key==' ' || (Key>='0' && Key<='9')){
        Key=Key;
        if(Edit14->Text==""){
            notempty[9]=false;
        }else{
            Edit14->Color=clWindow;
            notempty[9]=true;
        }
    }else{
        Key=0;
    }
}
void __fastcall TForm10::ComboBox3KeyPress(TObject *Sender, char &Key)
{
    if(Key>='1' && Key<='3'){
        char c=Key; Key=0;
        ComboBox3->Text=c;
        ComboBox3->Color=clWindow;
        notempty[24]=true;
    }else if(Key==8){
        Key=Key;
        notempty[24]=false;
    }else{
        Key=0;
    }
}
void __fastcall TForm10::ComboBox3Select(TObject *Sender)
{
    ComboBox3->Color=clWindow;
    notempty[24]=true;
}
void __fastcall TForm10::ComboBox4KeyPress(TObject *Sender, char &Key)
{
    if(Key>='А' && Key<='Д'){
        char c=Key; Key=0;
        ComboBox4->Text=c;
        ComboBox4->Color=clWindow;
        notempty[25]=true;
    }else if(Key==8){
        Key=Key;
        notempty[25]=false;
    }else{
        Key=0;
    }
}
void __fastcall TForm10::ComboBox4Select(TObject *Sender)
{
    ComboBox4->Color=clWindow;
    notempty[25]=true;
}
void __fastcall TForm10::SpeedButton1Click(TObject *Sender)//труд. книжка +1 запись
{
    StringGrid5->RowCount++;
}
void __fastcall TForm10::SpeedButton2Click(TObject *Sender)//труд. книжка -1 запись
{
    if(StringGrid5->RowCount>2){
        StringGrid5->RowCount--;
    }
}
void __fastcall TForm10::SpeedButton3Click(TObject *Sender)//аттестация +1 запись
{
    StringGrid6->RowCount++;   
}
void __fastcall TForm10::SpeedButton4Click(TObject *Sender)//аттестация -1 запись
{
    if(StringGrid6->RowCount>0){
        StringGrid6->RowCount--;
    }
}
void __fastcall TForm10::SpeedButton5Click(TObject *Sender)//проф. переподготовка +1 запись
{
    if(StringGrid8->RowCount<10){
        StringGrid8->RowCount++;
    }
}
void __fastcall TForm10::SpeedButton6Click(TObject *Sender)//проф. переподготовка -1 запись
{
    if(StringGrid8->RowCount>0){
        StringGrid8->RowCount--;
    }    
}
void __fastcall TForm10::SpeedButton7Click(TObject *Sender)//награды (поощрения) +1 запись
{
    if(StringGrid9->RowCount<15){
        StringGrid9->RowCount++;
    }
}
void __fastcall TForm10::SpeedButton8Click(TObject *Sender)//награды (поощрения) +1 запись
{
    if(StringGrid9->RowCount>0){
        StringGrid9->RowCount--;
    }
}
void __fastcall TForm10::SpeedButton9Click(TObject *Sender)//отпуски +1 запись
{
    if(StringGrid10->RowCount<15){
        StringGrid10->RowCount++;
    }
}
void __fastcall TForm10::SpeedButton10Click(TObject *Sender)//отпуски -1 запись
{
    if(StringGrid10->RowCount>0){
        StringGrid10->RowCount--;
    }
}
void __fastcall TForm10::SpeedButton11Click(TObject *Sender)//социальные льготы +1 запись
{
    if(StringGrid11->RowCount<10){
        StringGrid11->RowCount++;
    }
}
void __fastcall TForm10::SpeedButton12Click(TObject *Sender)//социальные льготы -1 запись
{
    if(StringGrid11->RowCount>0){
        StringGrid11->RowCount--;
    }
}
void __fastcall TForm10::SB_LeftClick(TObject *Sender)
{
    if(Panel2->Visible==true){
        Panel1->Visible=true;
        Panel2->Visible=false;
    }else if(Panel3->Visible==true){
        Panel2->Visible=true;
        Panel3->Visible=false;
    }else{
        Panel3->Visible=true;
        Panel4->Visible=false;
    }
}
void __fastcall TForm10::SB_RightClick(TObject *Sender)
{
    if(Panel1->Visible==true){
        Panel2->Visible=true;
        Panel1->Visible=false;
    }else if(Panel2->Visible==true){
        Panel3->Visible=true;
        Panel2->Visible=false;
    }else{
        Panel4->Visible=true;
        Panel3->Visible=false;
    }                  
}
void __fastcall TForm10::SB_Save1Click(TObject *Sender)//событие на кнопке "Сохранить"
{
    bool ok=true;
    String koling="wgbe ";
    for(int i=0; i<43; i++){
        if(notempty[i]==false){
            ok=false;          //koling+="  "; koling+=IntToStr(i);
            switch(i)                               //пустое поле!
            {case 0: Edit1->Color=clSilver; break;       //организация
             case 1: Edit3->Color=clSilver; break;       //фамилия
             case 2: Edit4->Color=clSilver; break;       //имя
             case 3: Edit5->Color=clSilver; break;       //отчество
             case 4: Edit6->Color=clSilver; break;       //гражданство
             case 5: Edit7->Color=clSilver; break;       //место рождения
             case 6: Edit9->Color=clSilver; break;       //номер паспорта
             case 7: Edit10->Color=clSilver;break;       //паспорт выдан
             case 8: Edit13->Color=clSilver;break;       //инн
             case 9: Edit14->Color=clSilver;break;       //снилс
             case 10: Edit11->Color=clSilver;break;      //адрес постоянный
             case 11: Edit12->Color=clSilver;break;      //адрес по месту жительсвту
             case 12: Edit15->Color=clSilver;break;      //состояние в браке
             case 13: if(Edit16->Text==""){
                          Edit16->Color=clSilver;        //Знание иностранного языка
                      }else{
                          Edit17->Color=clSilver;        //Степень знания иностранного языка
                      }break;
             case 14: Edit18->Color=clSilver;break;      //воинское звание
             case 15: Edit19->Color=clSilver;break;      //Состав(профиль)
             case 16: Edit20->Color=clSilver;break;      //полное кодовое обозначение ВУС
             case 17: Edit21->Color=clSilver;break;      //наименование военного коммиссариата по месту жительству
             case 18: Edit22->Color=clSilver;break;      //состоит на учёте
             case 19: Edit23->Color=clSilver;break;      //отметка о снятии с  военного учёта
             case 20: Edit24->Color=clSilver;break;      //работник кадровой службы(фио)
             case 21: Edit25->Color=clSilver;break;      //работник кадровой службы(должность)
             case 22: ComboBox2->Color=clSilver;break;   //пол
             case 23: ComboBox1->Color=clSilver;break;   //должность
             case 24: ComboBox3->Color=clSilver;break;   //категория запаса
             case 25: ComboBox4->Color=clSilver;break;   //категория годности
             case 26: Memo2->Color=clSilver;break;       //предмет договора
             case 27: Memo3->Color=clSilver;break;       //условия оплаты труда
             case 28: Memo4->Color=clSilver;break;       //режим рабочего времени и времени отдыха
             case 29: Memo5->Color=clSilver;break;       //условия об обязательном социальном страховании работника
             case 30: Memo6->Color=clSilver;break;       //гарантии и конпесации за работу с вредными и (или) опасными условиями труда. Условия труда на рабочем месте
             case 31: Memo8->Color=clSilver;break;       //адреса и реквизиты сторон
             case 32: Memo9->Color=clSilver;break;       //локальные нормативные акты
             case 33: StringGrid1->Color=clSilver;break; //состав семьи[таблица]
             case 34: StringGrid2->Color=clSilver;break; //образование[таблица]
             case 35: StringGrid3->Color=clSilver;break; //послевузовское образование[таблица]
             case 36: StringGrid5->Color=clSilver;break; //трудовая деятельность[таблица]
             case 37: StringGrid6->Color=clSilver;break; //аттестация[таблица]
             case 38: StringGrid7->Color=clSilver;break; //повышение квалификации[таблица]
             case 39: StringGrid8->Color=clSilver;break; //профессиональная переподготовка[таблица]
             case 40: StringGrid9->Color=clSilver;break; //награды[таблица]
             case 41: StringGrid10->Color=clSilver;break;//отпуска[таблица]
             case 42: StringGrid11->Color=clSilver;break;//социальные льготы[таблица]
            }
        }
    }
    //ShowMessage(koling);/*
    if(ok==true){ //если все необходимые поля заполнены, то сохранить.
        if(MessageBoxA(Handle, "Сохранить данные о сотруднике?", "Сохранение", MB_YESNO|MB_ICONQUESTION)==IDYES){
            if(forwhat==1){  //при добавлении данных нового сотрудника предприятии
                DataModule2->IBDataSet1_SOTRUDNIK->Insert();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID")->AsInteger=StrToInt(Edit2->Text);
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("S_STATUS")->AsInteger=1;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME_COMPANY")->AsString=Edit1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_SOSTAV")->AsDateTime=Label7->Caption;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("TAB_NOMER")->AsInteger=StrToInt(Edit2->Text);
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString=Edit3->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString=Edit4->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString=Edit5->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_BIRTH")->AsDateTime=DateTimePicker1->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("POL")->AsString=ComboBox2->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CITIZENSHIP")->AsString=Edit6->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("BIRTH_ADDRESS")->AsString=Edit7->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_POS")->AsInteger=DataModule2->IBDataSet3_POSITIONS->FieldByName("ID")->AsInteger;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SN_PASPORT")->AsString=Edit9->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_ISSUED")->AsDateTime=DateTimePicker2->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("WHOM_ISSUED")->AsString=Edit10->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("INN")->AsString=Edit13->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNILS")->AsString=Edit14->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS")->AsString=Edit11->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS_FACT")->AsString=Edit12->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_REGIST")->AsDateTime=DateTimePicker3->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KONTAKT_NOMER")->AsString=MaskEdit1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOSTVBRAKE")->AsString=Edit15->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_NAME")->AsString=Edit16->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_LEVEL")->AsString=Edit17->Text;
                bool savestg=false;
                for(int i=0; i<9; i++)
                {   if(StringGrid4->Cells[i][1]!=""){
                        savestg=true; break;
                    }
                }
                if(savestg==true){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STAG_RABOTI")->AsDateTime=DateTimePicker4->Date.DateString();
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_D")->AsInteger=StrToInt(StringGrid4->Cells[0][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_M")->AsInteger=StrToInt(StringGrid4->Cells[1][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_Y")->AsInteger=StrToInt(StringGrid4->Cells[2][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_D")->AsInteger=StrToInt(StringGrid4->Cells[3][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_M")->AsInteger=StrToInt(StringGrid4->Cells[4][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_Y")->AsInteger=StrToInt(StringGrid4->Cells[5][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_D")->AsInteger=StrToInt(StringGrid4->Cells[6][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_M")->AsInteger=StrToInt(StringGrid4->Cells[7][1]);
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_Y")->AsInteger=StrToInt(StringGrid4->Cells[8][1]);
                }
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CAT_ZAPASA")->AsString=ComboBox3->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ZVANIYE")->AsString=Edit18->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("PROFIL")->AsString=Edit19->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KAT_GODN")->AsString=ComboBox4->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_VUS")->AsString=Edit20->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("MLTR_NAME")->AsString=Edit21->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOS_NA_UCHET")->AsString=Edit22->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNYATS_UCHETA")->AsString=Edit23->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("FIO_EMP_DP")->AsString=Edit24->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("EMP_DP_POS")->AsString=Edit25->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_UCHET")->AsDateTime=DateTimePicker6->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DOP_SVEDENIYA")->AsString=Memo1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->Post();
                int idEmp=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID")->AsInteger;
                DataModule2->IBDatabase1->Connected=false;
                DataModule2->IBDatabase1->Connected=true;
                DataModule2->IBTransaction1->Active=true;
                DataModule2->IBDataSet2_EDUCATION->Active=true;
                DataModule2->IBDataSet3_POSITIONS->Active=true;
                DataModule2->IBDataSet4_AFTER_EDUCATION->Active=true;
                DataModule2->IBDataSet5_FAMILY->Active=true;
                DataModule2->IBDataSet6_TRUD_KNIGKA->Active=true;
                DataModule2->IBDataSet6_TRUD_KNIGKA->Active=true;
                DataModule2->IBDataSet7_ATTESTATION->Active=true;
                DataModule2->IBDataSet8_POV_QUALIFICATION->Active=true;
                DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Active=true;
                DataModule2->IBDataSet10_NAGRADI->Active=true;
                DataModule2->IBDataSet11_OTPUSK->Active=true;
                DataModule2->IBDataSet12_SOC_LGOTI->Active=true;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Active=true;
                DataModule2->IBDataSet_AUTORIZATION->Active=true;
                DataModule2->SelectSql(DataModule2->IBDataSet5_FAMILY, Form3->ZeroSql[4]);
                for(int i=1; i<StringGrid1->RowCount; i++)                //состав семьи
                {   if(StringGrid1->Cells[0][i]!=""){
                        DataModule2->IBDataSet5_FAMILY->Insert();
                        DataModule2->IBDataSet5_FAMILY->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet5_FAMILY->FieldByName("STEPEN_RODS")->AsString=StringGrid1->Cells[0][i];
                        DataModule2->IBDataSet5_FAMILY->FieldByName("FIO")->AsString=StringGrid1->Cells[1][i];
                        DataModule2->IBDataSet5_FAMILY->FieldByName("DATE_BIRTH")->AsString=StringGrid1->Cells[2][i];
                        DataModule2->IBDataSet5_FAMILY->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet2_EDUCATION, Form3->ZeroSql[2]); //образование
                for(int i=0; i<StringGrid2->RowCount; i++)
                {   if(StringGrid2->Cells[0][i]!=""){
                        DataModule2->IBDataSet2_EDUCATION->Insert();
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("ID_E_AORF")->AsInteger=1;
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("E_NAME")->AsString=StringGrid2->Cells[0][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("T_DOC")->AsString=StringGrid2->Cells[1][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("E_SN")->AsString=StringGrid2->Cells[2][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("D_ISSD")->AsString=StringGrid2->Cells[3][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("QUALIF")->AsString=StringGrid2->Cells[4][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("SPEC")->AsString=StringGrid2->Cells[5][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("T_E")->AsString=StringGrid2->Cells[6][i];
                        DataModule2->IBDataSet2_EDUCATION->Post();
                    }
                }
                for(int i=0; i<StringGrid3->RowCount; i++)                           //послевузовское образование
                {   if(StringGrid3->Cells[0][i]!=""){
                        DataModule2->IBDataSet4_AFTER_EDUCATION->Insert();
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("ID_E_AORF")->AsInteger=2;
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_NAME")->AsString=StringGrid3->Cells[0][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_DOC")->AsString=StringGrid3->Cells[1][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_SN")->AsString=StringGrid3->Cells[2][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("D_ISSD")->AsString=StringGrid3->Cells[3][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_E")->AsString=StringGrid3->Cells[4][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("SPEC")->AsString=StringGrid3->Cells[5][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet6_TRUD_KNIGKA, Form3->ZeroSql[5]);//трудовая деятельность
                for(int i=1; i<StringGrid5->RowCount; i++)
                {   if(StringGrid5->Cells[0][i]!=""){
                        DataModule2->IBDataSet6_TRUD_KNIGKA->Insert();
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("TR_DATE")->AsString=StringGrid5->Cells[0][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("OSNOVANIYE")->AsString=StringGrid5->Cells[1][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ORDERBY")->AsString=StringGrid5->Cells[2][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet7_ATTESTATION, Form3->ZeroSql[6]);
                for(int i=0; i<StringGrid6->RowCount; i++)     //аттестация в предприятии
                {   if(StringGrid6->Cells[0][i]!=""){
                        DataModule2->IBDataSet7_ATTESTATION->Insert();
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("DATEATTESTAT")->AsString=StringGrid6->Cells[0][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("RESH_KOMISSII")->AsString=StringGrid6->Cells[1][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_NOMER")->AsString=StringGrid6->Cells[2][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_DATE")->AsString=StringGrid6->Cells[3][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("OSNPVANIYE")->AsString=StringGrid6->Cells[4][i];
                        DataModule2->IBDataSet7_ATTESTATION->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet8_POV_QUALIFICATION, Form3->ZeroSql[7]);
                for(int i=0; i<StringGrid7->RowCount; i++)     //повышение квалификации
                {   if(StringGrid7->Cells[0][i]!=""){
                        DataModule2->IBDataSet8_POV_QUALIFICATION->Insert();
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_BEG_ST")->AsString=StringGrid7->Cells[0][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_FIN_ST")->AsString=StringGrid7->Cells[1][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_VID")->AsString=StringGrid7->Cells[2][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("NAME_ST_ADR")->AsString=StringGrid7->Cells[3][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_NAME")->AsString=StringGrid7->Cells[4][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_SN")->AsString=StringGrid7->Cells[5][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_DATE")->AsString=StringGrid7->Cells[6][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_OSNV")->AsString=StringGrid7->Cells[7][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA, Form3->ZeroSql[8]);
                for(int i=0; i<StringGrid8->RowCount; i++)     //профессиональная переподготовка
                {   if(StringGrid8->Cells[0][i]!=""){
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Insert();
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DBEG")->AsString=StringGrid8->Cells[0][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DFIN")->AsString=StringGrid8->Cells[1][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("SPECIAL")->AsString=StringGrid8->Cells[2][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_NAME")->AsString=StringGrid8->Cells[3][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_SN")->AsString=StringGrid8->Cells[4][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DATE")->AsString=StringGrid8->Cells[5][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_OSNV")->AsString=StringGrid8->Cells[6][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet10_NAGRADI, Form3->ZeroSql[9]);
                for(int i=0; i<StringGrid9->RowCount; i++)     //награды (поощрения), почётные звания
                {   if(StringGrid9->Cells[0][i]!=""){
                        DataModule2->IBDataSet10_NAGRADI->Insert();
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_NAME")->AsString=StringGrid9->Cells[0][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DNAME")->AsString=StringGrid9->Cells[1][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DDATE")->AsString=StringGrid9->Cells[2][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DOC_SN")->AsString=StringGrid9->Cells[3][i];
                        DataModule2->IBDataSet10_NAGRADI->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet11_OTPUSK, Form3->ZeroSql[10]);
                for(int i=0; i<StringGrid10->RowCount; i++)     //отпуска
                {   if(StringGrid10->Cells[0][i]!=""){
                        DataModule2->IBDataSet11_OTPUSK->Insert();
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_VID")->AsString=StringGrid10->Cells[0][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEB")->AsString=StringGrid10->Cells[1][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEF")->AsString=StringGrid10->Cells[2][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DAYS")->AsString=StringGrid10->Cells[3][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEB")->AsString=StringGrid10->Cells[4][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEF")->AsString=StringGrid10->Cells[5][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_OSNOVA")->AsString=StringGrid10->Cells[6][i];
                        DataModule2->IBDataSet11_OTPUSK->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet12_SOC_LGOTI, Form3->ZeroSql[11]);
                for(int i=0; i<StringGrid11->RowCount; i++)     //социальные льготы
                {   if(StringGrid11->Cells[0][i]!=""){
                        DataModule2->IBDataSet12_SOC_LGOTI->Insert();
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_NAME")->AsString=StringGrid11->Cells[0][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_NOMER")->AsString=StringGrid11->Cells[1][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_DATE")->AsString=StringGrid11->Cells[2][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_OSNOVA")->AsString=StringGrid11->Cells[3][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet13_TRUD_DOGOVOR, Form3->ZeroSql[12]);//трудовой договор
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Insert();
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_S")->AsInteger=idEmp;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_D_STATUS")->AsInteger=1;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("PREDMET")->AsString=Memo2->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_OPL_TR")->AsString=Memo3->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("REGIM_W")->AsString=Memo4->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_SOCSTR")->AsString=Memo5->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_TR")->AsString=Memo6->Text;
                if(Memo7->Text!=""){
                    DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("DOP_USL")->AsString=Memo7->Text;
                }
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ADDRESS_REKV")->AsString=Memo8->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("NOTM_ACTS")->AsString=Memo9->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("D_FINDATE")->AsDateTime=DateTimePicker5->Date.DateString();
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Post();
            }else if(forwhat==2){  //при редактировании данных сотрудника предприятии
                DataModule2->IBDataSet1_SOTRUDNIK->Edit();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME_COMPANY")->AsString=Edit1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_SOSTAV")->AsDateTime=Label7->Caption;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString=Edit3->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString=Edit4->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString=Edit5->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_BIRTH")->AsDateTime=DateTimePicker1->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("POL")->AsString=ComboBox2->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CITIZENSHIP")->AsString=Edit6->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("BIRTH_ADDRESS")->AsString=Edit7->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_POS")->AsInteger=DataModule2->IBDataSet3_POSITIONS->FieldByName("ID")->AsInteger;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SN_PASPORT")->AsString=Edit9->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_ISSUED")->AsDateTime=DateTimePicker2->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("WHOM_ISSUED")->AsString=Edit10->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("INN")->AsString=Edit13->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNILS")->AsString=Edit14->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS")->AsString=Edit11->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS_FACT")->AsString=Edit12->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_REGIST")->AsDateTime=DateTimePicker3->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KONTAKT_NOMER")->AsString=MaskEdit1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOSTVBRAKE")->AsString=Edit15->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_NAME")->AsString=Edit16->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_LEVEL")->AsString=Edit17->Text;
                bool savestg=false;
                if(StringGrid4->Cells[0][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_D")->AsInteger=StrToInt(StringGrid4->Cells[0][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_D")->AsString="";
                }
                if(StringGrid4->Cells[1][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_M")->AsInteger=StrToInt(StringGrid4->Cells[1][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_M")->AsString="";
                }
                if(StringGrid4->Cells[2][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_Y")->AsInteger=StrToInt(StringGrid4->Cells[2][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_Y")->AsString="";
                }
                if(StringGrid4->Cells[3][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_D")->AsInteger=StrToInt(StringGrid4->Cells[3][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_D")->AsString="";
                }
                if(StringGrid4->Cells[4][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_M")->AsInteger=StrToInt(StringGrid4->Cells[4][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_M")->AsString="";
                }
                if(StringGrid4->Cells[5][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_Y")->AsInteger=StrToInt(StringGrid4->Cells[5][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_Y")->AsString="";
                }
                if(StringGrid4->Cells[6][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_D")->AsInteger=StrToInt(StringGrid4->Cells[6][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_D")->AsString="";
                }
                if(StringGrid4->Cells[7][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_M")->AsInteger=StrToInt(StringGrid4->Cells[7][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_M")->AsString="";
                }
                if(StringGrid4->Cells[8][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_Y")->AsInteger=StrToInt(StringGrid4->Cells[8][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_Y")->AsString="";
                }
                if(savestg==true){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STAG_RABOTI")->AsDateTime=DateTimePicker4->Date.DateString();
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STAG_RABOTI")->AsString="";
                }
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CAT_ZAPASA")->AsString=ComboBox3->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ZVANIYE")->AsString=Edit18->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("PROFIL")->AsString=Edit19->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KAT_GODN")->AsString=ComboBox4->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_VUS")->AsString=Edit20->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("MLTR_NAME")->AsString=Edit21->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOS_NA_UCHET")->AsString=Edit22->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNYATS_UCHETA")->AsString=Edit23->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("FIO_EMP_DP")->AsString=Edit24->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("EMP_DP_POS")->AsString=Edit25->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_UCHET")->AsDateTime=DateTimePicker6->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DOP_SVEDENIYA")->AsString=Memo1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->Post();
                int idEmp=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID")->AsInteger;//код сотрудника
                if(DataModule2->IBDataSet5_FAMILY->RecordCount>0){
                    for(DataModule2->IBDataSet5_FAMILY->First(); !DataModule2->IBDataSet5_FAMILY->Eof; DataModule2->IBDataSet5_FAMILY->Next())
                    {   DataModule2->IBDataSet5_FAMILY->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet5_FAMILY, Form3->ZeroSql[4]);
                for(int i=1; i<StringGrid1->RowCount; i++)                        //состав семьи
                {   if(StringGrid1->Cells[0][i]!=""){
                        DataModule2->IBDataSet5_FAMILY->Insert();
                        DataModule2->IBDataSet5_FAMILY->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet5_FAMILY->FieldByName("STEPEN_RODS")->AsString=StringGrid1->Cells[0][i];
                        DataModule2->IBDataSet5_FAMILY->FieldByName("FIO")->AsString=StringGrid1->Cells[1][i];
                        DataModule2->IBDataSet5_FAMILY->FieldByName("DATE_BIRTH")->AsString=StringGrid1->Cells[2][i];
                        DataModule2->IBDataSet5_FAMILY->Post();
                    }
                }
                if(DataModule2->IBDataSet2_EDUCATION->RecordCount>0){
                    for(DataModule2->IBDataSet2_EDUCATION->First(); !DataModule2->IBDataSet2_EDUCATION->Eof; DataModule2->IBDataSet2_EDUCATION->Next())
                    {   DataModule2->IBDataSet2_EDUCATION->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet2_EDUCATION, Form3->ZeroSql[2]); //образование
                for(int i=0; i<StringGrid2->RowCount; i++)
                {   if(StringGrid2->Cells[0][i]!=""){
                        DataModule2->IBDataSet2_EDUCATION->Insert();
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("ID_E_AORF")->AsInteger=1;
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("E_NAME")->AsString=StringGrid2->Cells[0][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("T_DOC")->AsString=StringGrid2->Cells[1][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("E_SN")->AsString=StringGrid2->Cells[2][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("D_ISSD")->AsString=StringGrid2->Cells[3][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("QUALIF")->AsString=StringGrid2->Cells[4][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("SPEC")->AsString=StringGrid2->Cells[5][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("T_E")->AsString=StringGrid2->Cells[6][i];
                        DataModule2->IBDataSet2_EDUCATION->Post();
                    }
                }
                if(DataModule2->IBDataSet4_AFTER_EDUCATION->RecordCount>0){
                    for(DataModule2->IBDataSet4_AFTER_EDUCATION->First(); !DataModule2->IBDataSet4_AFTER_EDUCATION->Eof; DataModule2->IBDataSet4_AFTER_EDUCATION->Next())
                    {   DataModule2->IBDataSet4_AFTER_EDUCATION->Delete();
                    }
                }
                for(int i=0; i<StringGrid3->RowCount; i++)                           //послевузовское образование
                {   if(StringGrid3->Cells[0][i]!=""){
                        DataModule2->IBDataSet4_AFTER_EDUCATION->Insert();
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("ID_E_AORF")->AsInteger=2;
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_NAME")->AsString=StringGrid3->Cells[0][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_DOC")->AsString=StringGrid3->Cells[1][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_SN")->AsString=StringGrid3->Cells[2][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("D_ISSD")->AsString=StringGrid3->Cells[3][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_E")->AsString=StringGrid3->Cells[4][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("SPEC")->AsString=StringGrid3->Cells[5][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->Post();
                    }
                }
                if(DataModule2->IBDataSet6_TRUD_KNIGKA->RecordCount>0){
                    for(DataModule2->IBDataSet6_TRUD_KNIGKA->First(); !DataModule2->IBDataSet6_TRUD_KNIGKA->Eof; DataModule2->IBDataSet6_TRUD_KNIGKA->Next())
                    {   DataModule2->IBDataSet6_TRUD_KNIGKA->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet6_TRUD_KNIGKA, Form3->ZeroSql[5]);
                for(int i=1; i<StringGrid5->RowCount; i++)     //трудовая деятельность
                {   if(StringGrid5->Cells[0][i]!=""){
                        DataModule2->IBDataSet6_TRUD_KNIGKA->Insert();
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("TR_DATE")->AsString=StringGrid5->Cells[0][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("OSNOVANIYE")->AsString=StringGrid5->Cells[1][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ORDERBY")->AsString=StringGrid5->Cells[2][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->Post();
                    }
                }
                if(DataModule2->IBDataSet7_ATTESTATION->RecordCount>0){
                    for(DataModule2->IBDataSet7_ATTESTATION->First(); !DataModule2->IBDataSet7_ATTESTATION->Eof; DataModule2->IBDataSet7_ATTESTATION->Next())
                    {   DataModule2->IBDataSet7_ATTESTATION->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet7_ATTESTATION, Form3->ZeroSql[6]);
                for(int i=0; i<StringGrid6->RowCount; i++)     //аттестация в предприятии
                {   if(StringGrid6->Cells[0][i]!=""){
                        DataModule2->IBDataSet7_ATTESTATION->Insert();
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("DATEATTESTAT")->AsString=StringGrid6->Cells[0][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("RESH_KOMISSII")->AsString=StringGrid6->Cells[1][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_NOMER")->AsString=StringGrid6->Cells[2][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_DATE")->AsString=StringGrid6->Cells[3][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("OSNPVANIYE")->AsString=StringGrid6->Cells[4][i];
                        DataModule2->IBDataSet7_ATTESTATION->Post();
                    }
                }
                if(DataModule2->IBDataSet8_POV_QUALIFICATION->RecordCount>0){
                    for(DataModule2->IBDataSet8_POV_QUALIFICATION->First(); !DataModule2->IBDataSet8_POV_QUALIFICATION->Eof; DataModule2->IBDataSet8_POV_QUALIFICATION->Next())
                    {   DataModule2->IBDataSet8_POV_QUALIFICATION->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet8_POV_QUALIFICATION, Form3->ZeroSql[7]);
                for(int i=0; i<StringGrid7->RowCount; i++)     //повышение квалификации
                {   if(StringGrid7->Cells[0][i]!=""){
                        DataModule2->IBDataSet8_POV_QUALIFICATION->Insert();
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_BEG_ST")->AsString=StringGrid7->Cells[0][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_FIN_ST")->AsString=StringGrid7->Cells[1][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_VID")->AsString=StringGrid7->Cells[2][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("NAME_ST_ADR")->AsString=StringGrid7->Cells[3][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_NAME")->AsString=StringGrid7->Cells[4][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_SN")->AsString=StringGrid7->Cells[5][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_DATE")->AsString=StringGrid7->Cells[6][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_OSNV")->AsString=StringGrid7->Cells[7][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->Post();
                    }
                }
                if(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->RecordCount>0){
                    for(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->First(); !DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Eof; DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Next())
                    {   DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA, Form3->ZeroSql[8]);
                for(int i=0; i<StringGrid8->RowCount; i++)     //профессиональная переподготовка
                {   if(StringGrid8->Cells[0][i]!=""){
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Insert();
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DBEG")->AsString=StringGrid8->Cells[0][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DFIN")->AsString=StringGrid8->Cells[1][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("SPECIAL")->AsString=StringGrid8->Cells[2][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_NAME")->AsString=StringGrid8->Cells[3][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_SN")->AsString=StringGrid8->Cells[4][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DATE")->AsString=StringGrid8->Cells[5][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_OSNV")->AsString=StringGrid8->Cells[6][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Post();
                    }
                }
                if(DataModule2->IBDataSet10_NAGRADI->RecordCount>0){
                    for(DataModule2->IBDataSet10_NAGRADI->First(); !DataModule2->IBDataSet10_NAGRADI->Eof; DataModule2->IBDataSet10_NAGRADI->Next())
                    {   DataModule2->IBDataSet10_NAGRADI->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet10_NAGRADI, Form3->ZeroSql[9]);
                for(int i=0; i<StringGrid9->RowCount; i++)     //награды (поощрения), почётные звания
                {   if(StringGrid9->Cells[0][i]!=""){
                        DataModule2->IBDataSet10_NAGRADI->Insert();
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_NAME")->AsString=StringGrid9->Cells[0][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DNAME")->AsString=StringGrid9->Cells[1][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DDATE")->AsString=StringGrid9->Cells[2][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DOC_SN")->AsString=StringGrid9->Cells[3][i];
                        DataModule2->IBDataSet10_NAGRADI->Post();
                    }
                }
                if(DataModule2->IBDataSet11_OTPUSK->RecordCount>0){
                    for(DataModule2->IBDataSet11_OTPUSK->First(); !DataModule2->IBDataSet11_OTPUSK->Eof; DataModule2->IBDataSet11_OTPUSK->Next())
                    {   DataModule2->IBDataSet11_OTPUSK->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet11_OTPUSK, Form3->ZeroSql[10]);
                for(int i=0; i<StringGrid10->RowCount; i++)     //отпуска
                {   if(StringGrid10->Cells[0][i]!=""){
                        DataModule2->IBDataSet11_OTPUSK->Insert();
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_VID")->AsString=StringGrid10->Cells[0][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEB")->AsString=StringGrid10->Cells[1][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEF")->AsString=StringGrid10->Cells[2][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DAYS")->AsString=StringGrid10->Cells[3][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEB")->AsString=StringGrid10->Cells[4][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEF")->AsString=StringGrid10->Cells[5][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_OSNOVA")->AsString=StringGrid10->Cells[6][i];
                        DataModule2->IBDataSet11_OTPUSK->Post();
                    }
                }
                if(DataModule2->IBDataSet12_SOC_LGOTI->RecordCount>0){
                    for(DataModule2->IBDataSet12_SOC_LGOTI->First(); !DataModule2->IBDataSet12_SOC_LGOTI->Eof; DataModule2->IBDataSet12_SOC_LGOTI->Next())
                    {   DataModule2->IBDataSet12_SOC_LGOTI->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet12_SOC_LGOTI, Form3->ZeroSql[11]);
                for(int i=0; i<StringGrid11->RowCount; i++)     //социальные льготы
                {   if(StringGrid11->Cells[0][i]!=""){
                        DataModule2->IBDataSet12_SOC_LGOTI->Insert();
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_NAME")->AsString=StringGrid11->Cells[0][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_NOMER")->AsString=StringGrid11->Cells[1][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_DATE")->AsString=StringGrid11->Cells[2][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_OSNOVA")->AsString=StringGrid11->Cells[3][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->Post();
                    }
                }
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Edit();//трудовой договор
                if(Label_NewD->Visible==true){
                    DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_D_STATUS")->AsInteger=0;
                    DataModule2->SelectSql(DataModule2->IBDataSet13_TRUD_DOGOVOR, Form3->ZeroSql[12]);
                    DataModule2->IBDataSet13_TRUD_DOGOVOR->Insert();
                    Label_NewD->Visible==false;
                }
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_S")->AsInteger=idEmp;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_D_STATUS")->AsInteger=1;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("PREDMET")->AsString=Memo2->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_OPL_TR")->AsString=Memo3->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("REGIM_W")->AsString=Memo4->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_SOCSTR")->AsString=Memo5->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_TR")->AsString=Memo6->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("DOP_USL")->AsString=Memo7->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ADDRESS_REKV")->AsString=Memo8->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("NOTM_ACTS")->AsString=Memo9->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("D_FINDATE")->AsDateTime=DateTimePicker5->Date.DateString();
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Post();
            }else{         //при восстановлении данных сотрудника предприятии
                DataModule2->IBDataSet1_SOTRUDNIK->Edit();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("S_STATUS")->AsInteger=1;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME_COMPANY")->AsString=Edit1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_SOSTAV")->AsDateTime=Label7->Caption;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SURNAME")->AsString=Edit3->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("NAME")->AsString=Edit4->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SECONDNAME")->AsString=Edit5->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_BIRTH")->AsDateTime=DateTimePicker1->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("POL")->AsString=ComboBox2->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CITIZENSHIP")->AsString=Edit6->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("BIRTH_ADDRESS")->AsString=Edit7->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_POS")->AsInteger=DataModule2->IBDataSet3_POSITIONS->FieldByName("ID")->AsInteger;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SN_PASPORT")->AsString=Edit9->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_ISSUED")->AsDateTime=DateTimePicker2->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("WHOM_ISSUED")->AsString=Edit10->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("INN")->AsString=Edit13->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNILS")->AsString=Edit14->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS")->AsString=Edit11->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ADDRESS_FACT")->AsString=Edit12->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_REGIST")->AsDateTime=DateTimePicker3->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KONTAKT_NOMER")->AsString=MaskEdit1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOSTVBRAKE")->AsString=Edit15->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_NAME")->AsString=Edit16->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KNLG_LEVEL")->AsString=Edit17->Text;
                bool savestg=false;
                if(StringGrid4->Cells[0][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_D")->AsInteger=StrToInt(StringGrid4->Cells[0][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_D")->AsString="";
                }
                if(StringGrid4->Cells[1][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_M")->AsInteger=StrToInt(StringGrid4->Cells[1][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_M")->AsString="";
                }
                if(StringGrid4->Cells[2][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_Y")->AsInteger=StrToInt(StringGrid4->Cells[2][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STGEN_Y")->AsString="";
                }
                if(StringGrid4->Cells[3][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_D")->AsInteger=StrToInt(StringGrid4->Cells[3][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_D")->AsString="";
                }
                if(StringGrid4->Cells[4][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_M")->AsInteger=StrToInt(StringGrid4->Cells[4][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_M")->AsString="";
                }
                if(StringGrid4->Cells[5][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_Y")->AsInteger=StrToInt(StringGrid4->Cells[5][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNEPR_Y")->AsString="";
                }
                if(StringGrid4->Cells[6][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_D")->AsInteger=StrToInt(StringGrid4->Cells[6][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_D")->AsString="";
                }
                if(StringGrid4->Cells[7][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_M")->AsInteger=StrToInt(StringGrid4->Cells[7][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_M")->AsString="";
                }
                if(StringGrid4->Cells[8][1]!=""){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_Y")->AsInteger=StrToInt(StringGrid4->Cells[8][1]);
                    savestg=true;
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STNADBV_Y")->AsString="";
                }
                if(savestg==true){
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STAG_RABOTI")->AsDateTime=DateTimePicker4->Date.DateString();
                }else{
                    DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("STAG_RABOTI")->AsString="";
                }
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("CAT_ZAPASA")->AsString=ComboBox3->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ZVANIYE")->AsString=Edit18->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("PROFIL")->AsString=Edit19->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("KAT_GODN")->AsString=ComboBox4->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID_VUS")->AsString=Edit20->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("MLTR_NAME")->AsString=Edit21->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SOS_NA_UCHET")->AsString=Edit22->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("SNYATS_UCHETA")->AsString=Edit23->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("FIO_EMP_DP")->AsString=Edit24->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("EMP_DP_POS")->AsString=Edit25->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DATE_UCHET")->AsDateTime=DateTimePicker6->Date.DateString();
                DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("DOP_SVEDENIYA")->AsString=Memo1->Text;
                DataModule2->IBDataSet1_SOTRUDNIK->Post();
                int idEmp=DataModule2->IBDataSet1_SOTRUDNIK->FieldByName("ID")->AsInteger;//код сотрудника
                if(DataModule2->IBDataSet5_FAMILY->RecordCount>0){
                    for(DataModule2->IBDataSet5_FAMILY->First(); !DataModule2->IBDataSet5_FAMILY->Eof; DataModule2->IBDataSet5_FAMILY->Next())
                    {   DataModule2->IBDataSet5_FAMILY->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet5_FAMILY, Form3->ZeroSql[4]);
                for(int i=1; i<StringGrid1->RowCount; i++)                        //состав семьи
                {   if(StringGrid1->Cells[0][i]!=""){
                        DataModule2->IBDataSet5_FAMILY->Insert();
                        DataModule2->IBDataSet5_FAMILY->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet5_FAMILY->FieldByName("STEPEN_RODS")->AsString=StringGrid1->Cells[0][i];
                        DataModule2->IBDataSet5_FAMILY->FieldByName("FIO")->AsString=StringGrid1->Cells[1][i];
                        DataModule2->IBDataSet5_FAMILY->FieldByName("DATE_BIRTH")->AsString=StringGrid1->Cells[2][i];
                        DataModule2->IBDataSet5_FAMILY->Post();
                    }
                }
                if(DataModule2->IBDataSet2_EDUCATION->RecordCount>0){
                    for(DataModule2->IBDataSet2_EDUCATION->First(); !DataModule2->IBDataSet2_EDUCATION->Eof; DataModule2->IBDataSet2_EDUCATION->Next())
                    {   DataModule2->IBDataSet2_EDUCATION->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet2_EDUCATION, Form3->ZeroSql[2]); //образование
                for(int i=0; i<StringGrid2->RowCount; i++)
                {   if(StringGrid2->Cells[0][i]!=""){
                        DataModule2->IBDataSet2_EDUCATION->Insert();
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("ID_E_AORF")->AsInteger=1;
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("E_NAME")->AsString=StringGrid2->Cells[0][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("T_DOC")->AsString=StringGrid2->Cells[1][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("E_SN")->AsString=StringGrid2->Cells[2][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("D_ISSD")->AsString=StringGrid2->Cells[3][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("QUALIF")->AsString=StringGrid2->Cells[4][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("SPEC")->AsString=StringGrid2->Cells[5][i];
                        DataModule2->IBDataSet2_EDUCATION->FieldByName("T_E")->AsString=StringGrid2->Cells[6][i];
                        DataModule2->IBDataSet2_EDUCATION->Post();
                    }
                }
                if(DataModule2->IBDataSet4_AFTER_EDUCATION->RecordCount>0){
                    for(DataModule2->IBDataSet4_AFTER_EDUCATION->First(); !DataModule2->IBDataSet4_AFTER_EDUCATION->Eof; DataModule2->IBDataSet4_AFTER_EDUCATION->Next())
                    {   DataModule2->IBDataSet4_AFTER_EDUCATION->Delete();
                    }
                }
                for(int i=0; i<StringGrid3->RowCount; i++)                           //послевузовское образование
                {   if(StringGrid3->Cells[0][i]!=""){
                        DataModule2->IBDataSet4_AFTER_EDUCATION->Insert();
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("ID_E_AORF")->AsInteger=2;
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_NAME")->AsString=StringGrid3->Cells[0][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_DOC")->AsString=StringGrid3->Cells[1][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("E_SN")->AsString=StringGrid3->Cells[2][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("D_ISSD")->AsString=StringGrid3->Cells[3][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("T_E")->AsString=StringGrid3->Cells[4][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->FieldByName("SPEC")->AsString=StringGrid3->Cells[5][i];
                        DataModule2->IBDataSet4_AFTER_EDUCATION->Post();
                    }
                }
                if(DataModule2->IBDataSet6_TRUD_KNIGKA->RecordCount>0){
                    for(DataModule2->IBDataSet6_TRUD_KNIGKA->First(); !DataModule2->IBDataSet6_TRUD_KNIGKA->Eof; DataModule2->IBDataSet6_TRUD_KNIGKA->Next())
                    {   DataModule2->IBDataSet6_TRUD_KNIGKA->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet6_TRUD_KNIGKA, Form3->ZeroSql[5]);
                for(int i=1; i<StringGrid5->RowCount; i++)     //трудовая деятельность
                {   if(StringGrid5->Cells[0][i]!=""){
                        DataModule2->IBDataSet6_TRUD_KNIGKA->Insert();
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("TR_DATE")->AsString=StringGrid5->Cells[0][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("OSNOVANIYE")->AsString=StringGrid5->Cells[1][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->FieldByName("ORDERBY")->AsString=StringGrid5->Cells[2][i];
                        DataModule2->IBDataSet6_TRUD_KNIGKA->Post();
                    }
                }
                if(DataModule2->IBDataSet7_ATTESTATION->RecordCount>0){
                    for(DataModule2->IBDataSet7_ATTESTATION->First(); !DataModule2->IBDataSet7_ATTESTATION->Eof; DataModule2->IBDataSet7_ATTESTATION->Next())
                    {   DataModule2->IBDataSet7_ATTESTATION->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet7_ATTESTATION, Form3->ZeroSql[6]);
                for(int i=0; i<StringGrid6->RowCount; i++)     //аттестация в предприятии
                {   if(StringGrid6->Cells[0][i]!=""){
                        DataModule2->IBDataSet7_ATTESTATION->Insert();
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("DATEATTESTAT")->AsString=StringGrid6->Cells[0][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("RESH_KOMISSII")->AsString=StringGrid6->Cells[1][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_NOMER")->AsString=StringGrid6->Cells[2][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("PROTOCOL_DATE")->AsString=StringGrid6->Cells[3][i];
                        DataModule2->IBDataSet7_ATTESTATION->FieldByName("OSNPVANIYE")->AsString=StringGrid6->Cells[4][i];
                        DataModule2->IBDataSet7_ATTESTATION->Post();
                    }
                }
                if(DataModule2->IBDataSet8_POV_QUALIFICATION->RecordCount>0){
                    for(DataModule2->IBDataSet8_POV_QUALIFICATION->First(); !DataModule2->IBDataSet8_POV_QUALIFICATION->Eof; DataModule2->IBDataSet8_POV_QUALIFICATION->Next())
                    {   DataModule2->IBDataSet8_POV_QUALIFICATION->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet8_POV_QUALIFICATION, Form3->ZeroSql[7]);
                for(int i=0; i<StringGrid7->RowCount; i++)     //повышение квалификации
                {   if(StringGrid7->Cells[0][i]!=""){
                        DataModule2->IBDataSet8_POV_QUALIFICATION->Insert();
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_BEG_ST")->AsString=StringGrid7->Cells[0][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_FIN_ST")->AsString=StringGrid7->Cells[1][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_VID")->AsString=StringGrid7->Cells[2][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("NAME_ST_ADR")->AsString=StringGrid7->Cells[3][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_NAME")->AsString=StringGrid7->Cells[4][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_SN")->AsString=StringGrid7->Cells[5][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("DOC_DATE")->AsString=StringGrid7->Cells[6][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->FieldByName("Q_OSNV")->AsString=StringGrid7->Cells[7][i];
                        DataModule2->IBDataSet8_POV_QUALIFICATION->Post();
                    }
                }
                if(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->RecordCount>0){
                    for(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->First(); !DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Eof; DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Next())
                    {   DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA, Form3->ZeroSql[8]);
                for(int i=0; i<StringGrid8->RowCount; i++)     //профессиональная переподготовка
                {   if(StringGrid8->Cells[0][i]!=""){
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Insert();
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DBEG")->AsString=StringGrid8->Cells[0][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DFIN")->AsString=StringGrid8->Cells[1][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("SPECIAL")->AsString=StringGrid8->Cells[2][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_NAME")->AsString=StringGrid8->Cells[3][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_SN")->AsString=StringGrid8->Cells[4][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_DATE")->AsString=StringGrid8->Cells[5][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->FieldByName("PRO_OSNV")->AsString=StringGrid8->Cells[6][i];
                        DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA->Post();
                    }
                }
                if(DataModule2->IBDataSet10_NAGRADI->RecordCount>0){
                    for(DataModule2->IBDataSet10_NAGRADI->First(); !DataModule2->IBDataSet10_NAGRADI->Eof; DataModule2->IBDataSet10_NAGRADI->Next())
                    {   DataModule2->IBDataSet10_NAGRADI->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet10_NAGRADI, Form3->ZeroSql[9]);
                for(int i=0; i<StringGrid9->RowCount; i++)     //награды (поощрения), почётные звания
                {   if(StringGrid9->Cells[0][i]!=""){
                        DataModule2->IBDataSet10_NAGRADI->Insert();
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_NAME")->AsString=StringGrid9->Cells[0][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DNAME")->AsString=StringGrid9->Cells[1][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DDATE")->AsString=StringGrid9->Cells[2][i];
                        DataModule2->IBDataSet10_NAGRADI->FieldByName("NAG_DOC_SN")->AsString=StringGrid9->Cells[3][i];
                        DataModule2->IBDataSet10_NAGRADI->Post();
                    }
                }
                if(DataModule2->IBDataSet11_OTPUSK->RecordCount>0){
                    for(DataModule2->IBDataSet11_OTPUSK->First(); !DataModule2->IBDataSet11_OTPUSK->Eof; DataModule2->IBDataSet11_OTPUSK->Next())
                    {   DataModule2->IBDataSet11_OTPUSK->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet11_OTPUSK, Form3->ZeroSql[10]);
                for(int i=0; i<StringGrid10->RowCount; i++)     //отпуска
                {   if(StringGrid10->Cells[0][i]!=""){
                        DataModule2->IBDataSet11_OTPUSK->Insert();
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_VID")->AsString=StringGrid10->Cells[0][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEB")->AsString=StringGrid10->Cells[1][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("WORK_DATEF")->AsString=StringGrid10->Cells[2][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DAYS")->AsString=StringGrid10->Cells[3][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEB")->AsString=StringGrid10->Cells[4][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_DATEF")->AsString=StringGrid10->Cells[5][i];
                        DataModule2->IBDataSet11_OTPUSK->FieldByName("OTP_OSNOVA")->AsString=StringGrid10->Cells[6][i];
                        DataModule2->IBDataSet11_OTPUSK->Post();
                    }
                }
                if(DataModule2->IBDataSet12_SOC_LGOTI->RecordCount>0){
                    for(DataModule2->IBDataSet12_SOC_LGOTI->First(); !DataModule2->IBDataSet12_SOC_LGOTI->Eof; DataModule2->IBDataSet12_SOC_LGOTI->Next())
                    {   DataModule2->IBDataSet12_SOC_LGOTI->Delete();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet12_SOC_LGOTI, Form3->ZeroSql[11]);
                for(int i=0; i<StringGrid11->RowCount; i++)     //социальные льготы
                {   if(StringGrid11->Cells[0][i]!=""){
                        DataModule2->IBDataSet12_SOC_LGOTI->Insert();
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("ID_S")->AsInteger=idEmp;
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_NAME")->AsString=StringGrid11->Cells[0][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_NOMER")->AsString=StringGrid11->Cells[1][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_DOC_DATE")->AsString=StringGrid11->Cells[2][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->FieldByName("L_OSNOVA")->AsString=StringGrid11->Cells[3][i];
                        DataModule2->IBDataSet12_SOC_LGOTI->Post();
                    }
                }
                DataModule2->SelectSql(DataModule2->IBDataSet13_TRUD_DOGOVOR, Form3->ZeroSql[12]);//трудовой договор
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Insert();
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_S")->AsInteger=idEmp;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ID_D_STATUS")->AsInteger=1;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("PREDMET")->AsString=Memo2->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_OPL_TR")->AsString=Memo3->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("REGIM_W")->AsString=Memo4->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_SOCSTR")->AsString=Memo5->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("USL_TR")->AsString=Memo6->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("DOP_USL")->AsString=Memo7->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("ADDRESS_REKV")->AsString=Memo8->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("NOTM_ACTS")->AsString=Memo9->Text;
                DataModule2->IBDataSet13_TRUD_DOGOVOR->FieldByName("D_FINDATE")->AsDateTime=DateTimePicker5->Date.DateString();
                DataModule2->IBDataSet13_TRUD_DOGOVOR->Post();
            }
            DataModule2->SelectSql(DataModule2->IBDataSet1_SOTRUDNIK, Form3->BeginFiltr[1]);
            DataModule2->IBDataSet1_SOTRUDNIK->Last();
            DataModule2->SelectSql(DataModule2->IBDataSet5_FAMILY, Form3->ZeroSql[4]+"where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet2_EDUCATION, Form3->ZeroSql[2]+"where ID_S=:ID and ID_E_AORF=1");
            DataModule2->SelectSql(DataModule2->IBDataSet4_AFTER_EDUCATION, Form3->ZeroSql[2]+"where ID_S=:ID and ID_E_AORF=2");
            DataModule2->SelectSql(DataModule2->IBDataSet6_TRUD_KNIGKA, Form3->ZeroSql[5]+" where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet7_ATTESTATION, Form3->ZeroSql[6]+" where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet8_POV_QUALIFICATION, Form3->ZeroSql[7]+" where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet9_PROF_PEREPODGOTOVKA, Form3->ZeroSql[8]+" where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet10_NAGRADI, Form3->ZeroSql[9]+"where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet11_OTPUSK, Form3->ZeroSql[10]+"where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet12_SOC_LGOTI, Form3->ZeroSql[11]+"where ID_S=:ID");
            DataModule2->SelectSql(DataModule2->IBDataSet13_TRUD_DOGOVOR, Form3->ZeroSql[12]+"where ID_S=:ID and ID_D_STATUS=1");
            Close();
        }
    }else{//иначи если не все необходимые поля заполнены, то подсветить те поля серым цветом, и предупредить.
        MessageBoxA(Handle, "Заполните все необходимые поля! Не заполненные поля обозначены серым цветом!", "Проверка на пустоту", MB_OK|MB_ICONEXCLAMATION);//восклицание(желтоё)
        //MB_ICONWARNING);//восклицание(желтоё)
        //MB_OK|MB_ICONINFORMATION);//восклицание(синее)
        //MB_OK|MB_ICONASTERISK);//восклицание(синее)
        //MB_OK|MB_ICONQUESTION);//вопрос
        //MB_OK|MB_ICONSTOP);//стоп
        //MB_OK|MB_ICONERROR);//стоп
        //MB_OK|MB_ICONHAND );//стоп
    }    
}
void __fastcall TForm10::Edit16Exit(TObject *Sender)
{
    if((Edit16->Text=="" && Edit17->Text!="") || (Edit16->Text!="" && Edit17->Text=="")){
        notempty[13]=false;
    }else{
        notempty[13]=true;
    }    
}void __fastcall TForm10::Edit1Change(TObject *Sender)
{
    Edit1->Color=clWindow;
    if(Edit1->Text==""){
        notempty[0]=false;
    }else{
        notempty[0]=true;
    }
}
void __fastcall TForm10::Edit3Change(TObject *Sender)
{
    Edit3->Color=clWindow;
    if(Edit3->Text==""){
        notempty[1]=false;
    }else{
        notempty[1]=true;
    }
}
void __fastcall TForm10::Edit4Change(TObject *Sender)
{
    Edit4->Color=clWindow;
    if(Edit4->Text==""){
        notempty[2]=false;
    }else{
        notempty[2]=true;
    }
}
void __fastcall TForm10::Edit5Change(TObject *Sender)
{
    Edit5->Color=clWindow;
    if(Edit5->Text==""){
        notempty[3]=false;
    }else{
        notempty[3]=true;
    }
}
void __fastcall TForm10::Edit6Change(TObject *Sender)
{
    Edit6->Color=clWindow;
    if(Edit6->Text==""){
        notempty[4]=false;
    }else{
        notempty[4]=true;
    }
}
void __fastcall TForm10::Edit7Change(TObject *Sender)
{
    Edit7->Color=clWindow;
    if(Edit7->Text==""){
        notempty[5]=false;
    }else{
        notempty[5]=true;
    }
}
void __fastcall TForm10::Edit9Change(TObject *Sender)
{
    Edit9->Color=clWindow;
    if(Edit9->Text==""){
        notempty[6]=false;
    }else{
        notempty[6]=true;
    }
}
void __fastcall TForm10::Edit10Change(TObject *Sender)
{
    Edit10->Color=clWindow;
    if(Edit10->Text==""){
        notempty[7]=false;
    }else{
        notempty[7]=true;
    }
}
void __fastcall TForm10::Edit11Change(TObject *Sender)
{
    Edit11->Color=clWindow;
    if(Edit11->Text==""){
        notempty[10]=false;
    }else{
        notempty[10]=true;
    }
}
void __fastcall TForm10::Edit12Change(TObject *Sender)
{
    Edit12->Color=clWindow;
    if(Edit12->Text==""){
        notempty[11]=false;
    }else{
        notempty[11]=true;
    }
}
void __fastcall TForm10::Edit15Change(TObject *Sender)
{
    Edit15->Color=clWindow;
    if(Edit15->Text==""){
        notempty[12]=false;
    }else{
        notempty[12]=true;
    }
}
void __fastcall TForm10::Edit16Change(TObject *Sender)
{
    Edit16->Color=clWindow;
}
void __fastcall TForm10::Edit17Change(TObject *Sender)
{
    Edit17->Color=clWindow;
}
void __fastcall TForm10::Edit18Change(TObject *Sender)
{
    Edit18->Color=clWindow;
    if(Edit18->Text==""){
        notempty[14]=false;
    }else{
        notempty[14]=true;
    }
}
void __fastcall TForm10::Edit19Change(TObject *Sender)
{
    Edit19->Color=clWindow;
    if(Edit19->Text==""){
        notempty[15]=false;
    }else{
        notempty[15]=true;
    }
}
void __fastcall TForm10::Edit20Change(TObject *Sender)
{
    Edit20->Color=clWindow;
    if(Edit20->Text==""){
        notempty[16]=false;
    }else{
        notempty[16]=true;
    }
}
void __fastcall TForm10::Edit21Change(TObject *Sender)
{
    Edit21->Color=clWindow;
    if(Edit21->Text==""){
        notempty[17]=false;
    }else{
        notempty[17]=true;
    }
}
void __fastcall TForm10::Edit22Change(TObject *Sender)
{
    Edit22->Color=clWindow;
    if(Edit22->Text==""){
        notempty[18]=false;
    }else{
        notempty[18]=true;
    }
}
void __fastcall TForm10::Edit23Change(TObject *Sender)
{
    Edit23->Color=clWindow;
    if(Edit23->Text==""){
        notempty[19]=false;
    }else{
        notempty[19]=true;
    }
}
void __fastcall TForm10::Edit24Change(TObject *Sender)
{
    Edit24->Color=clWindow;
    if(Edit24->Text==""){
        notempty[20]=false;
    }else{
        notempty[20]=true;
    }
}
void __fastcall TForm10::Edit25Change(TObject *Sender)
{
    Edit25->Color=clWindow;
    if(Edit25->Text==""){
        notempty[21]=false;
    }else{
        notempty[21]=true;
    }
}void __fastcall TForm10::ComboBox1Change(TObject *Sender)
{
    if(ComboBox1->ItemIndex>-1){
        ComboBox1->Color=clWindow;
        DataModule2->SelectSql(DataModule2->IBDataSet3_POSITIONS, Form3->BeginFiltr[2]+ " and POS_NAME='"+ComboBox1->Text+"'");
        Edit8->Text=DataModule2->IBDataSet3_POSITIONS->FieldByName("SALARY")->AsFloat;
        notempty[23]=true;
        if(forwhat==2){
            if(ComboBox1->Text!=Form3->posEmployee){
                ntrk=true;
                Label_NewD->Visible=true;
            }else{
                ntrk=false;
                Label_NewD->Visible=false;
            }
        }else if(forwhat==3 ||forwhat==1){
            if(ntrk==false){
                post=ComboBox1->Text;
            }
        }
    }else{
        Edit8->Text="";
        notempty[23]=false;
    }
}
void __fastcall TForm10::Memo2Change(TObject *Sender)
{
    Memo2->Color=clWindow;
    if(Memo2->Text==""){
        notempty[26]=false;
    }else{
        notempty[26]=true;
    }    
}
void __fastcall TForm10::Memo3Change(TObject *Sender)
{
    Memo3->Color=clWindow;
    if(Memo3->Text==""){
        notempty[27]=false;
    }else{
        notempty[27]=true;
    }
}
void __fastcall TForm10::Memo4Change(TObject *Sender)
{
    Memo4->Color=clWindow;
    if(Memo4->Text==""){
        notempty[28]=false;
    }else{
        notempty[28]=true;
    }
}
void __fastcall TForm10::Memo5Change(TObject *Sender)
{
    Memo5->Color=clWindow;
    if(Memo5->Text==""){
        notempty[29]=false;
    }else{
        notempty[29]=true;
    }
}
void __fastcall TForm10::Memo6Change(TObject *Sender)
{
    Memo6->Color=clWindow;
    if(Memo6->Text==""){
        notempty[30]=false;
    }else{
        notempty[30]=true;
    }
}
void __fastcall TForm10::Memo8Change(TObject *Sender)
{
    Memo8->Color=clWindow;
    if(Memo8->Text==""){
        notempty[31]=false;
    }else{
        notempty[31]=true;
    }
}
void __fastcall TForm10::Memo9Change(TObject *Sender)
{
    Memo9->Color=clWindow;
    if(Memo9->Text==""){
        notempty[32]=false;
    }else{
        notempty[32]=true;
    }
}
void __fastcall TForm10::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    int x, y;
    x = Rect.Left + (Rect.Width() - StringGrid1->Canvas->TextWidth(StringGrid1->Cells[ACol][ARow]))/2;
    y = Rect.Top + (Rect.Height() - StringGrid1->Canvas->TextHeight(StringGrid1->Cells[ACol][ARow]))/2;
    StringGrid1->Canvas->FillRect(Rect);
    StringGrid1->Canvas->TextOut(x,y,StringGrid1->Cells[ACol][ARow]);
}
void __fastcall TForm10::StringGrid4DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    int x, y;
    x = Rect.Left + (Rect.Width() - StringGrid4->Canvas->TextWidth(StringGrid4->Cells[ACol][ARow]))/2;
    y = Rect.Top + (Rect.Height() - StringGrid4->Canvas->TextHeight(StringGrid4->Cells[ACol][ARow]))/2;
    StringGrid4->Canvas->FillRect(Rect);
    StringGrid4->Canvas->TextOut(x,y,StringGrid4->Cells[ACol][ARow]);
}
void __fastcall TForm10::StringGrid5DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    int x, y;
    x = Rect.Left + (Rect.Width() - StringGrid5->Canvas->TextWidth(StringGrid5->Cells[ACol][ARow]))/2;
    y = Rect.Top + (Rect.Height() - StringGrid5->Canvas->TextHeight(StringGrid5->Cells[ACol][ARow]))/2;
    StringGrid5->Canvas->FillRect(Rect);
    StringGrid5->Canvas->TextOut(x,y,StringGrid5->Cells[ACol][ARow]);
}
void __fastcall TForm10::StringGrid4KeyPress(TObject *Sender, char &Key)
{
    if(Key==8 || Key>='0' && Key<='9'){
        Key=Key;
    }else{
        Key=0;
    }
}
void __fastcall TForm10::StringGrid4Exit(TObject *Sender)
{
    /*int dmy[9], kol[6];
    for(int i=0; i<6; i++)
    {   kol[i]=0;
    }
    for(int i=0; i<9; i++)
    {   dmy[i]=0;
    }
    for(int i=0; i<9; i++)
    {   if(StringGrid4->Cells[i][0]!=""){
            dmy[i]=StrToInt(StringGrid4->Cells[i][0]);
        }
    }
    for(int i=0, kl=0; i<9; i+=3, kl++)
    {   while(dmy[i]>31)
        {  dmy[i]-=31; kol[kl];
        }
    }
    for(int i=1, kl=2; i<9; i+=3, kl++)
    {   while(dmy[i]>12)
        {  dmy[i]-=12; kol[kl];
        }
    } */

}
void __fastcall TForm10::StringGrid1KeyPress(TObject *Sender, char &Key)
{
    StringGrid1->Color=clWindow;
    notempty[33]=true;
    for(int i=1; i<StringGrid1->RowCount; i++)
    {   for(int j=0; j<StringGrid1->ColCount-1; j++)
        {   if(StringGrid1->Cells[j][i]=="" && StringGrid1->Cells[j+1][i]!=""){
                notempty[33]=false; break;
            }else if(StringGrid1->Cells[j][i]!="" && StringGrid1->Cells[j+1][i]==""){
                notempty[33]=false; break;
            }
        }
    }
}
void __fastcall TForm10::StringGrid2KeyPress(TObject *Sender, char &Key)
{
    StringGrid2->Color=clWindow;
    notempty[34]=true;
    for(int i=0; i<StringGrid2->RowCount; i++)
    {   for(int j=0; j<StringGrid2->ColCount-1; j++)
        {   if(StringGrid2->Cells[j][i]=="" && StringGrid2->Cells[j+1][i]!=""){
                notempty[34]=false; break;
            }else if(StringGrid2->Cells[j][i]!="" && StringGrid2->Cells[j+1][i]==""){
                notempty[34]=false; break;
            }
        }
    }
}
void __fastcall TForm10::StringGrid3KeyPress(TObject *Sender, char &Key)
{
    StringGrid3->Color=clWindow;
    notempty[35]=true;
    for(int i=0; i<StringGrid3->RowCount; i++)
    {   for(int j=0; j<StringGrid3->ColCount-1; j++)
        {   if(StringGrid3->Cells[j][i]=="" && StringGrid3->Cells[j+1][i]!=""){
                notempty[35]=false; break;
            }else if(StringGrid3->Cells[j][i]!="" && StringGrid3->Cells[j+1][i]==""){
                notempty[35]=false; break;
            }
        }
    }
}
void __fastcall TForm10::StringGrid5KeyPress(TObject *Sender, char &Key)
{
    StringGrid5->Color=clWindow;
    notempty[36]=true;
    for(int i=1; i<StringGrid5->RowCount; i++)
    {   for(int j=0; j<StringGrid5->ColCount-1; j++)
        {   if(StringGrid5->Cells[j][i]=="" && StringGrid5->Cells[j+1][i]!=""){
                notempty[36]=false; break;
            }else if(StringGrid5->Cells[j][i]!="" && StringGrid5->Cells[j+1][i]==""){
                notempty[36]=false; break;
            }
        }
    }
}
void __fastcall TForm10::StringGrid6KeyPress(TObject *Sender, char &Key)
{
    StringGrid6->Color=clWindow;
    notempty[37]=true;
    for(int i=0; i<StringGrid6->RowCount; i++)
    {   for(int j=0; j<StringGrid6->ColCount-1; j++)
        {   if(StringGrid3->Cells[j][i]=="" && StringGrid6->Cells[j+1][i]!=""){
                notempty[37]=false; break;
            }else if(StringGrid6->Cells[j][i]!="" && StringGrid6->Cells[j+1][i]==""){
                notempty[37]=false; break;
            }
        }
    }
}
void __fastcall TForm10::StringGrid7KeyPress(TObject *Sender, char &Key)
{
    StringGrid7->Color=clWindow;
    notempty[38]=true;
    for(int i=0; i<StringGrid7->RowCount; i++)
    {   for(int j=0; j<StringGrid7->ColCount-1; j++)
        {   if(StringGrid7->Cells[j][i]=="" && StringGrid7->Cells[j+1][i]!=""){
                notempty[38]=false; break;
            }else if(StringGrid7->Cells[j][i]!="" && StringGrid7->Cells[j+1][i]==""){
                notempty[38]=false; break;
            }
        }
    }    
}
void __fastcall TForm10::StringGrid8KeyPress(TObject *Sender, char &Key)
{
    StringGrid8->Color=clWindow;
    notempty[39]=true;
    for(int i=0; i<StringGrid8->RowCount; i++)
    {   for(int j=0; j<StringGrid8->ColCount-1; j++)
        {   if(StringGrid8->Cells[j][i]=="" && StringGrid8->Cells[j+1][i]!=""){
                notempty[39]=false; break;
            }else if(StringGrid8->Cells[j][i]!="" && StringGrid8->Cells[j+1][i]==""){
                notempty[39]=false; break;
            }
        }
    }    
}
void __fastcall TForm10::StringGrid9KeyPress(TObject *Sender, char &Key)
{
    StringGrid9->Color=clWindow;
    notempty[40]=true;
    for(int i=0; i<StringGrid9->RowCount; i++)
    {   for(int j=0; j<StringGrid9->ColCount-1; j++)
        {   if(StringGrid9->Cells[j][i]=="" && StringGrid9->Cells[j+1][i]!=""){
                notempty[40]=false; break;
            }else if(StringGrid9->Cells[j][i]!="" && StringGrid9->Cells[j+1][i]==""){
                notempty[40]=false; break;
            }
        }
    }    
}
void __fastcall TForm10::StringGrid10KeyPress(TObject *Sender, char &Key)
{
    StringGrid10->Color=clWindow;
    notempty[41]=true;
    for(int i=0; i<StringGrid10->RowCount; i++)
    {   for(int j=0; j<StringGrid10->ColCount-1; j++)
        {   if(StringGrid10->Cells[j][i]=="" && StringGrid10->Cells[j+1][i]!=""){
                notempty[41]=false; break;
            }else if(StringGrid10->Cells[j][i]!="" && StringGrid10->Cells[j+1][i]==""){
                notempty[41]=false; break;
            }
        }
    }    
}
void __fastcall TForm10::StringGrid11KeyPress(TObject *Sender, char &Key)
{
    StringGrid11->Color=clWindow;
    notempty[42]=true;
    for(int i=0; i<StringGrid11->RowCount; i++)
    {   for(int j=0; j<StringGrid11->ColCount-1; j++)
        {   if(StringGrid11->Cells[j][i]=="" && StringGrid11->Cells[j+1][i]!=""){
                notempty[42]=false; break;
            }else if(StringGrid11->Cells[j][i]!="" && StringGrid11->Cells[j+1][i]==""){
                notempty[42]=false; break;
            }
        }
    }
}
void __fastcall TForm10::ComboBox2KeyPress(TObject *Sender, char &Key)
{
    if(Key=='м' || Key=='ж'){
        char c=Key; Key=0;
        ComboBox2->Text=c;
        ComboBox2->Color=clWindow;
        notempty[22]=true;
    }else if(Key==8){
        Key=Key;
        notempty[22]=false;
    }else{
        Key=0;
    }    
}
void __fastcall TForm10::ComboBox2Select(TObject *Sender)
{
    ComboBox2->Color=clWindow;
    notempty[22]=true;
}
void __fastcall TForm10::StringGrid5Enter(TObject *Sender)
{
    if(forwhat==2){
        if(ntrk==true){
            if(MessageBoxA(Handle,"Выбрана другая должность! \nCоздать запись в таблице о переводе на другую должность?", "Трудовая книжка", MB_YESNO|MB_ICONQUESTION)==IDYES){
                bool dinrow=true;
                for(int i=1; i<StringGrid5->RowCount; i++)
                {   for(int j=0; j<2; j++)
                    {   if(StringGrid5->Cells[j][i]=="" && StringGrid5->Cells[j+1][i]!="" || StringGrid5->Cells[j][i]!="" && StringGrid5->Cells[j+1][i]==""){
                            StringGrid5->Cells[j][i]=Date();
                            StringGrid5->Cells[j][i]="Перевод на должность "+ComboBox1->Text;
                            StringGrid5->Cells[j][i]="Приказ №3 от "+Date();
                            dinrow=false; break;
                        }
                    }
                }
                if(dinrow==true){
                    StringGrid5->RowCount++;
                    StringGrid5->Cells[0][StringGrid5->RowCount-1]=Date();
                    StringGrid5->Cells[1][StringGrid5->RowCount-1]="Перевод на должность "+ComboBox1->Text;
                    StringGrid5->Cells[2][StringGrid5->RowCount-1]="Приказ №3 от "+Date();
                }
            }
        }ntrk=false;
    }else if(forwhat==1 || forwhat==3){
        if(ntrk==false){
            if(ComboBox1->Text!=""){
                String ness=" сотрудника выбрана новая должность! Создать запись в таблице об устройстве на новую должность?";
                if(forwhat==1){
                    ness="При добавлении данных нового "+ness;
                }else{
                    ness="При восстановлении данных "+ness;
                }
                if(MessageBoxA(Handle, ness.c_str(), "Трудовая книжка", MB_YESNO)==IDYES){
                    bool newrec=false;
                    for(int i=1; i<StringGrid5->RowCount; i++)
                    {   if(StringGrid5->Cells[0][i]==""){
                            StringGrid5->Cells[0][i]=Date();
                            StringGrid5->Cells[1][i]="Устройство на должность "+ComboBox1->Text;
                            StringGrid5->Cells[2][i]="Приказ №1 от "+Date();
                            newrec=true; rec=i; break;
                        }
                    }
                    if(newrec==false){
                        StringGrid5->RowCount++;
                        StringGrid5->Cells[0][StringGrid5->RowCount-1]=Date();
                        StringGrid5->Cells[1][StringGrid5->RowCount-1]="Устройство на должность "+ComboBox1->Text;
                        StringGrid5->Cells[2][StringGrid5->RowCount-1]="Приказ №1 от "+Date();
                    }
                }
            }ntrk=true;
        }else if(ComboBox1->Text!=post){
            if(StringGrid5->RowCount>rec){
                StringGrid5->Cells[1][rec]="Устройство на должность "+ComboBox1->Text;
            }else{
                StringGrid5->RowCount++;
                StringGrid5->Cells[0][StringGrid5->RowCount-1]=Date();
                StringGrid5->Cells[1][StringGrid5->RowCount-1]="Устройство на должность "+ComboBox1->Text;
                StringGrid5->Cells[2][StringGrid5->RowCount-1]="Приказ №1 от "+Date();
                rec=StringGrid5->RowCount-1;
            }
        }
    }
    notempty[36]=true;
    for(int i=1; i<StringGrid5->RowCount; i++)
    {   for(int j=0; j<StringGrid5->ColCount-1; j++)
        {   if(StringGrid5->Cells[j][i]=="" && StringGrid5->Cells[j+1][i]!=""){
                notempty[36]=false; break;
            }else if(StringGrid5->Cells[j][i]!="" && StringGrid5->Cells[j+1][i]==""){
                notempty[36]=false; break;
            }
        }
    }
}
void __fastcall TForm10::MaskEdit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==8){
        int selstart=MaskEdit1->SelStart;
        AnsiString q=MaskEdit1->Text;
        for(int i=4; i<9; i++)
        {   if(q[i]==' ')
                q[i]='0';
        }
        for(int i=10; i<=18; i++)
        {   if(q[i]==' ')
                q[i]='0';
        }
        MaskEdit1->Text=q;
        MaskEdit1->SelStart=selstart;
    }
}

