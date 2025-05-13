//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", DataModule2); /* TDataModule: File Type */
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit7.cpp", Form7);
USEFORM("Unit8.cpp", Form8);
USEFORM("Unit9.cpp", Form9);
USEFORM("Unit10.cpp", Form10);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "Отдел кадров";
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TForm3), &Form3);
         Application->CreateForm(__classid(TForm10), &Form10);
         Application->CreateForm(__classid(TForm5), &Form5);
         Application->CreateForm(__classid(TForm8), &Form8);
         Application->CreateForm(__classid(TForm6), &Form6);
         Application->CreateForm(__classid(TDataModule2), &DataModule2);
         Application->CreateForm(__classid(TForm4), &Form4);
         Application->CreateForm(__classid(TForm7), &Form7);
         Application->CreateForm(__classid(TForm9), &Form9);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------
