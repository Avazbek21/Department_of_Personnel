object Form4: TForm4
  Left = 940
  Top = 513
  AutoSize = True
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1080'/'#1080#1083#1080' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1090#1072#1073#1083#1080#1094#1099'  "'#1057#1086#1090#1088#1091#1076#1085#1080#1082#1080'"'
  ClientHeight = 306
  ClientWidth = 718
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Arial'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Scaled = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object SB_StartSql: TSpeedButton
    Left = 512
    Top = 280
    Width = 89
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082
    OnClick = SB_StartSqlClick
  end
  object SB_SqlStandart: TSpeedButton
    Left = 624
    Top = 280
    Width = 89
    Height = 25
    Hint = #1047#1072#1087#1088#1086#1089' '#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
    Caption = #1054#1090#1084#1077#1085#1072
    ParentShowHint = False
    ShowHint = True
    Visible = False
    OnClick = SB_SqlStandartClick
  end
  object CheckBox1: TCheckBox
    Left = 45
    Top = 0
    Width = 136
    Height = 20
    Caption = #1041#1077#1079' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1080
    Checked = True
    Color = 3370007
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clYellow
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    State = cbChecked
    TabOrder = 0
    OnMouseUp = CheckBox1MouseUp
  end
  object CheckBox2: TCheckBox
    Left = 273
    Top = 283
    Width = 215
    Height = 19
    Hint = #1045#1089#1083#1080' '#1074#1099#1082#1083#1102#1095#1077#1085', '#1090#1086' '#1090#1086#1083#1100#1082#1086' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1072
    Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1080' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1072
    Color = clGray
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clAqua
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnMouseUp = CheckBox2MouseUp
  end
  object CheckBox12: TCheckBox
    Left = 304
    Top = 0
    Width = 145
    Height = 17
    Caption = #1041#1077#1079' '#1092#1080#1083#1100#1090#1088#1072#1094#1080#1080
    Checked = True
    Color = clHotLight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    State = cbChecked
    TabOrder = 2
    OnMouseUp = CheckBox12MouseUp
  end
  object GroupBox1: TGroupBox
    Left = 259
    Top = 21
    Width = 459
    Height = 252
    Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103
    Color = clBackground
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 3
    object CheckBox4: TCheckBox
      Tag = 2
      Left = 5
      Top = 45
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080
      Color = clLime
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 2
      OnMouseUp = CheckBox4MouseUp
    end
    object CheckBox5: TCheckBox
      Tag = 3
      Left = 5
      Top = 70
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1080#1084#1077#1085#1080
      Color = clBlue
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clYellow
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 3
      OnMouseUp = CheckBox5MouseUp
    end
    object CheckBox6: TCheckBox
      Tag = 4
      Left = 5
      Top = 95
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1086#1090#1095#1077#1089#1090#1074#1091
      Color = clAqua
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 4
      OnMouseUp = CheckBox6MouseUp
    end
    object CheckBox7: TCheckBox
      Tag = 4
      Left = 5
      Top = 120
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1087#1086#1083#1091
      Color = clGray
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clSkyBlue
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 5
      OnMouseUp = CheckBox7MouseUp
    end
    object ComboBox2: TComboBox
      Left = 230
      Top = 118
      Width = 74
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ItemHeight = 15
      ParentFont = False
      TabOrder = 10
      Visible = False
      OnKeyPress = Edit1KeyPress
      Items.Strings = (
        #1084#1091#1078#1089#1082#1086#1081
        #1078#1077#1085#1089#1082#1080#1081)
    end
    object Edit1: TEdit
      Left = 230
      Top = 43
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      Visible = False
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 230
      Top = 68
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 12
      Visible = False
      OnKeyPress = Edit1KeyPress
    end
    object Edit3: TEdit
      Left = 230
      Top = 93
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 13
      Visible = False
      OnKeyPress = Edit1KeyPress
    end
    object CheckBox8: TCheckBox
      Tag = 5
      Left = 5
      Top = 145
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1076#1086#1083#1078#1085#1086#1089#1090#1080
      Color = clGreen
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = 12971552
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 6
      OnMouseUp = CheckBox8MouseUp
    end
    object ComboBox3: TComboBox
      Left = 230
      Top = 143
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ItemHeight = 15
      ParentFont = False
      TabOrder = 14
      Visible = False
      OnKeyPress = Edit1KeyPress
    end
    object CheckBox9: TCheckBox
      Tag = 6
      Left = 5
      Top = 170
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1086#1082#1083#1072#1076#1091
      Color = clMoneyGreen
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = 2396927
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 7
      OnMouseUp = CheckBox9MouseUp
    end
    object ComboBox4: TComboBox
      Left = 230
      Top = 168
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ItemHeight = 15
      ParentFont = False
      TabOrder = 15
      Visible = False
      OnKeyPress = Edit1KeyPress
    end
    object CheckBox10: TCheckBox
      Tag = 7
      Left = 5
      Top = 195
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1048#1053#1053
      Color = 12904726
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 8
      OnMouseUp = CheckBox10MouseUp
    end
    object Edit4: TEdit
      Left = 230
      Top = 193
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      MaxLength = 12
      ParentFont = False
      TabOrder = 16
      Visible = False
      OnKeyPress = Edit4KeyPress
    end
    object CheckBox11: TCheckBox
      Tag = 8
      Left = 5
      Top = 220
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1057#1053#1048#1051#1057
      Color = 33023
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clYellow
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 9
      OnMouseUp = CheckBox11MouseUp
    end
    object Edit5: TEdit
      Left = 230
      Top = 218
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      MaxLength = 15
      ParentFont = False
      TabOrder = 17
      Visible = False
      OnKeyPress = Edit5KeyPress
    end
    object ComboBox1: TComboBox
      Left = 230
      Top = 18
      Width = 225
      Height = 23
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindow
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ItemHeight = 15
      ParentFont = False
      TabOrder = 0
      Visible = False
    end
    object CheckBox3: TCheckBox
      Tag = 1
      Left = 5
      Top = 20
      Width = 225
      Height = 20
      Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103' '#1087#1086' '#1090#1072#1073'. '#1085#1086#1084#1077#1088#1091
      Color = clMaroon
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clAqua
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      OnMouseUp = CheckBox3MouseUp
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 21
    Width = 260
    Height = 285
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -15
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 4
    object RadioGroup1: TRadioGroup
      Left = 5
      Top = 20
      Width = 250
      Height = 65
      Caption = #1055#1086' '#1090#1072#1073#1077#1083#1100#1085#1086#1084#1091' '#1085#1086#1084#1077#1088#1091
      Color = clNavy
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clAqua
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      Items.Strings = (
        #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
        #1055#1086' '#1091#1073#1099#1074#1072#1085#1080#1102)
      ParentColor = False
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object RadioGroup2: TRadioGroup
      Left = 5
      Top = 85
      Width = 250
      Height = 65
      Caption = #1055#1086' '#1092#1072#1084#1080#1083#1080#1080
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      Items.Strings = (
        #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102' ('#1040' -> '#1071')'
        #1055#1086' '#1091#1073#1099#1074#1072#1085#1080#1102' ('#1071' -> '#1040')')
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      OnClick = RadioGroup2Click
    end
    object RadioGroup3: TRadioGroup
      Left = 5
      Top = 150
      Width = 250
      Height = 65
      Caption = #1055#1086' '#1080#1084#1077#1085#1080
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      Items.Strings = (
        #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102' ('#1040' -> '#1071')'
        #1055#1086' '#1091#1073#1099#1074#1072#1085#1080#1102' ('#1071' -> '#1040')')
      ParentColor = False
      ParentFont = False
      TabOrder = 2
      OnClick = RadioGroup3Click
    end
    object RadioGroup4: TRadioGroup
      Left = 5
      Top = 215
      Width = 250
      Height = 65
      Caption = #1055#1086' '#1086#1090#1095#1077#1089#1090#1074#1091
      Color = clGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      Items.Strings = (
        #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102' ('#1040' -> '#1071')'
        #1055#1086' '#1091#1073#1099#1074#1072#1085#1080#1102' ('#1071' -> '#1040')')
      ParentColor = False
      ParentFont = False
      TabOrder = 3
      OnClick = RadioGroup4Click
    end
  end
end
