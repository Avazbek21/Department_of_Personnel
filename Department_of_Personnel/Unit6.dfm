object Form6: TForm6
  Left = 581
  Top = 441
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1076#1086#1083#1078#1085#1086#1089#1090#1080
  ClientHeight = 65
  ClientWidth = 569
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Arial'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object Label1: TLabel
    Left = 0
    Top = 1
    Width = 92
    Height = 19
    Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 0
    Top = 33
    Width = 53
    Height = 19
    Caption = #1054#1082#1083#1072#1076
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BitBtn_PPost: TBitBtn
    Left = 304
    Top = 31
    Width = 113
    Height = 30
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 0
    OnClick = BitBtn_PPostClick
    Kind = bkYes
  end
  object BitBtn_Cancel: TBitBtn
    Left = 432
    Top = 32
    Width = 113
    Height = 30
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = BitBtn_CancelClick
    Kind = bkCancel
  end
  object Edit1: TEdit
    Left = 96
    Top = 1
    Width = 473
    Height = 26
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 96
    Top = 32
    Width = 135
    Height = 26
    TabOrder = 3
    OnKeyPress = Edit2KeyPress
    OnKeyUp = Edit2KeyUp
  end
end
