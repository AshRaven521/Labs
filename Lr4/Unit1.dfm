object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Stack'
  ClientHeight = 282
  ClientWidth = 629
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 40
    Width = 131
    Height = 24
    Caption = #1042#1099#1088#1072#1078#1077#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 24
    Top = 80
    Width = 153
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 200
    Top = 78
    Width = 75
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 129
    Width = 613
    Height = 145
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
end
