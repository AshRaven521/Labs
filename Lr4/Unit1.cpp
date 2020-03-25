//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

stackint st;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//a*(b-c)/(d+e)
	//1.6*(4.9-5.7)/(0.8+2.3)
	//a b c - * d e + /
	//1.6 4.9 5.7 - * 0.8 2.3 + /
	//-0.413

	AnsiString strStr=Edit1->Text;
	std::string str=strStr.c_str();

	Memo1->Clear();

	//�������������� � ����������� ����� (���)
	char note[100];
	strcpy(note,str.c_str());
	std::string pnote = st.OPZ(note);
	strStr=pnote.c_str();
	Memo1->Lines->Add("���: "+strStr);

	//���������� ���������
	double dd=st.Calc(pnote);
	Memo1->Lines->Add("���������: "+AnsiString(dd));

	//��������
	dd=1.6*(4.9-5.7)/(0.8+2.3);
	Memo1->Lines->Add("�������� 1.6*(4.9-5.7)/(0.8+2.3)="+AnsiString(dd));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text="1.6*(4.9-5.7)/(0.8+2.3)";
	Memo1->Clear();
}
//---------------------------------------------------------------------------
