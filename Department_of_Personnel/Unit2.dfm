object DataModule2: TDataModule2
  OldCreateOrder = False
  Left = 861
  Top = 261
  Height = 632
  Width = 609
  object DataSource1: TDataSource
    DataSet = IBDataSet1_SOTRUDNIK
    Left = 208
    Top = 136
  end
  object DataSource2: TDataSource
    DataSet = IBDataSet2_EDUCATION
    Left = 536
    Top = 8
  end
  object IBDatabase1: TIBDatabase
    Connected = True
    DatabaseName = 'Department_of_Personnel.FDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=WIN1251')
    LoginPrompt = False
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 32
    Top = 8
  end
  object IBTransaction1: TIBTransaction
    Active = True
    DefaultDatabase = IBDatabase1
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 32
    Top = 64
  end
  object DataSource4: TDataSource
    DataSet = IBDataSet4_AFTER_EDUCATION
    Left = 536
    Top = 104
  end
  object DataSource5: TDataSource
    DataSet = IBDataSet5_FAMILY
    Left = 536
    Top = 152
  end
  object DataSource6: TDataSource
    DataSet = IBDataSet6_TRUD_KNIGKA
    Left = 536
    Top = 200
  end
  object DataSource7: TDataSource
    DataSet = IBDataSet7_ATTESTATION
    Left = 536
    Top = 248
  end
  object DataSource8: TDataSource
    DataSet = IBDataSet8_POV_QUALIFICATION
    Left = 536
    Top = 296
  end
  object DataSource9: TDataSource
    DataSet = IBDataSet9_PROF_PEREPODGOTOVKA
    Left = 536
    Top = 344
  end
  object DataSource10: TDataSource
    DataSet = IBDataSet10_NAGRADI
    Left = 536
    Top = 392
  end
  object DataSource11: TDataSource
    DataSet = IBDataSet11_OTPUSK
    Left = 536
    Top = 440
  end
  object DataSource12: TDataSource
    DataSet = IBDataSet12_SOC_LGOTI
    Left = 536
    Top = 488
  end
  object DataSource13: TDataSource
    DataSet = IBDataSet13_TRUD_DOGOVOR
    Left = 536
    Top = 536
  end
  object IBDataSet2_EDUCATION: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from EDUCATION'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into EDUCATION'
      
        '  (ID_S, ID_E_AORF, E_NAME, SPEC, QUALIF, T_DOC, D_ISSD, T_E, E_' +
        'SN)'
      'values'
      
        '  (:ID_S, :ID_E_AORF, :E_NAME, :SPEC, :QUALIF, :T_DOC, :D_ISSD, ' +
        ':T_E, :E_SN)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  ID_E_AORF,'
      '  E_NAME,'
      '  SPEC,'
      '  QUALIF,'
      '  T_DOC,'
      '  D_ISSD,'
      '  T_E,'
      '  E_SN'
      'from EDUCATION '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from EDUCATION where ID_S=:ID and ID_E_AORF=1')
    ModifySQL.Strings = (
      'update EDUCATION'
      'set'
      '  ID_S = :ID_S,'
      '  ID_E_AORF = :ID_E_AORF,'
      '  E_NAME = :E_NAME,'
      '  SPEC = :SPEC,'
      '  QUALIF = :QUALIF,'
      '  T_DOC = :T_DOC,'
      '  D_ISSD = :D_ISSD,'
      '  T_E = :T_E,'
      '  E_SN = :E_SN'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_EDUCATION_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 8
  end
  object IBDataSet4_AFTER_EDUCATION: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from EDUCATION'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into EDUCATION'
      
        '  (ID_S, ID_E_AORF, E_NAME, SPEC, QUALIF, T_DOC, D_ISSD, T_E, E_' +
        'SN)'
      'values'
      
        '  (:ID_S, :ID_E_AORF, :E_NAME, :SPEC, :QUALIF, :T_DOC, :D_ISSD, ' +
        ':T_E, :E_SN)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  ID_E_AORF,'
      '  E_NAME,'
      '  SPEC,'
      '  QUALIF,'
      '  T_DOC,'
      '  D_ISSD,'
      '  T_E,'
      '  E_SN'
      'from EDUCATION '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from EDUCATION where ID_S=:ID and ID_E_AORF=2')
    ModifySQL.Strings = (
      'update EDUCATION'
      'set'
      '  ID_S = :ID_S,'
      '  ID_E_AORF = :ID_E_AORF,'
      '  E_NAME = :E_NAME,'
      '  SPEC = :SPEC,'
      '  QUALIF = :QUALIF,'
      '  T_DOC = :T_DOC,'
      '  D_ISSD = :D_ISSD,'
      '  T_E = :T_E,'
      '  E_SN = :E_SN'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_EDUCATION_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 104
  end
  object IBDataSet5_FAMILY: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from FAMILY'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into FAMILY'
      '  (ID_S, STEPEN_RODS, FIO, DATE_BIRTH)'
      'values'
      '  (:ID_S, :STEPEN_RODS, :FIO, :DATE_BIRTH)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  STEPEN_RODS,'
      '  FIO,'
      '  DATE_BIRTH'
      'from FAMILY '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from FAMILY where ID_S=:ID')
    ModifySQL.Strings = (
      'update FAMILY'
      'set'
      '  ID_S = :ID_S,'
      '  STEPEN_RODS = :STEPEN_RODS,'
      '  FIO = :FIO,'
      '  DATE_BIRTH = :DATE_BIRTH'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_FAMILY_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 152
  end
  object IBDataSet6_TRUD_KNIGKA: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from TRUD_KNIGKA'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into TRUD_KNIGKA'
      '  (ID_S, TR_DATE, OSNOVANIYE, ORDERBY)'
      'values'
      '  (:ID_S, :TR_DATE, :OSNOVANIYE, :ORDERBY)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  TR_DATE,'
      '  OSNOVANIYE,'
      '  ORDERBY'
      'from TRUD_KNIGKA '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from TRUD_KNIGKA where ID_S=:ID')
    ModifySQL.Strings = (
      'update TRUD_KNIGKA'
      'set'
      '  ID_S = :ID_S,'
      '  TR_DATE = :TR_DATE,'
      '  OSNOVANIYE = :OSNOVANIYE,'
      '  ORDERBY = :ORDERBY'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_TRUD_KNIGKA_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 200
  end
  object IBDataSet7_ATTESTATION: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from ATTESTATION'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into ATTESTATION'
      
        '  (ID_S, DATEATTESTAT, RESH_KOMISSII, PROTOCOL_NOMER, PROTOCOL_D' +
        'ATE, OSNPVANIYE)'
      'values'
      
        '  (:ID_S, :DATEATTESTAT, :RESH_KOMISSII, :PROTOCOL_NOMER, :PROTO' +
        'COL_DATE, '
      '   :OSNPVANIYE)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  DATEATTESTAT,'
      '  RESH_KOMISSII,'
      '  PROTOCOL_NOMER,'
      '  PROTOCOL_DATE,'
      '  OSNPVANIYE'
      'from ATTESTATION '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from ATTESTATION where ID_S=:ID')
    ModifySQL.Strings = (
      'update ATTESTATION'
      'set'
      '  ID_S = :ID_S,'
      '  DATEATTESTAT = :DATEATTESTAT,'
      '  RESH_KOMISSII = :RESH_KOMISSII,'
      '  PROTOCOL_NOMER = :PROTOCOL_NOMER,'
      '  PROTOCOL_DATE = :PROTOCOL_DATE,'
      '  OSNPVANIYE = :OSNPVANIYE'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_ATTESTATION_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 248
  end
  object IBDataSet8_POV_QUALIFICATION: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from POV_QUALIFICATION'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into POV_QUALIFICATION'
      
        '  (ID_S, Q_BEG_ST, Q_FIN_ST, NAME_ST_ADR, DOC_NAME, DOC_SN, DOC_' +
        'DATE, Q_VID, '
      '   Q_OSNV)'
      'values'
      
        '  (:ID_S, :Q_BEG_ST, :Q_FIN_ST, :NAME_ST_ADR, :DOC_NAME, :DOC_SN' +
        ', :DOC_DATE, '
      '   :Q_VID, :Q_OSNV)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  Q_BEG_ST,'
      '  Q_FIN_ST,'
      '  NAME_ST_ADR,'
      '  DOC_NAME,'
      '  DOC_SN,'
      '  DOC_DATE,'
      '  Q_VID,'
      '  Q_OSNV'
      'from POV_QUALIFICATION '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from POV_QUALIFICATION where ID_S=:ID')
    ModifySQL.Strings = (
      'update POV_QUALIFICATION'
      'set'
      '  ID_S = :ID_S,'
      '  Q_BEG_ST = :Q_BEG_ST,'
      '  Q_FIN_ST = :Q_FIN_ST,'
      '  NAME_ST_ADR = :NAME_ST_ADR,'
      '  DOC_NAME = :DOC_NAME,'
      '  DOC_SN = :DOC_SN,'
      '  DOC_DATE = :DOC_DATE,'
      '  Q_VID = :Q_VID,'
      '  Q_OSNV = :Q_OSNV'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_POV_QUALIFICATION_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 296
  end
  object IBDataSet9_PROF_PEREPODGOTOVKA: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from PROF_PODGOTOVKA'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into PROF_PODGOTOVKA'
      
        '  (ID_S, PRO_DBEG, PRO_DFIN, SPECIAL, PRO_NAME, PRO_SN, PRO_DATE' +
        ', PRO_OSNV)'
      'values'
      
        '  (:ID_S, :PRO_DBEG, :PRO_DFIN, :SPECIAL, :PRO_NAME, :PRO_SN, :P' +
        'RO_DATE, '
      '   :PRO_OSNV)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  PRO_DBEG,'
      '  PRO_DFIN,'
      '  SPECIAL,'
      '  PRO_NAME,'
      '  PRO_SN,'
      '  PRO_DATE,'
      '  PRO_OSNV'
      'from PROF_PODGOTOVKA '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from PROF_PODGOTOVKA where ID_S=:ID')
    ModifySQL.Strings = (
      'update PROF_PODGOTOVKA'
      'set'
      '  ID_S = :ID_S,'
      '  PRO_DBEG = :PRO_DBEG,'
      '  PRO_DFIN = :PRO_DFIN,'
      '  SPECIAL = :SPECIAL,'
      '  PRO_NAME = :PRO_NAME,'
      '  PRO_SN = :PRO_SN,'
      '  PRO_DATE = :PRO_DATE,'
      '  PRO_OSNV = :PRO_OSNV'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_PROF_PODGOTOVKA_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 344
  end
  object IBDataSet10_NAGRADI: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from NAGRADI'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into NAGRADI'
      '  (ID_S, NAG_NAME, NAG_DNAME, NAG_DDATE, NAG_DOC_SN)'
      'values'
      '  (:ID_S, :NAG_NAME, :NAG_DNAME, :NAG_DDATE, :NAG_DOC_SN)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  NAG_NAME,'
      '  NAG_DNAME,'
      '  NAG_DDATE,'
      '  NAG_DOC_SN'
      'from NAGRADI '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from NAGRADI where ID_S=:ID')
    ModifySQL.Strings = (
      'update NAGRADI'
      'set'
      '  ID_S = :ID_S,'
      '  NAG_NAME = :NAG_NAME,'
      '  NAG_DNAME = :NAG_DNAME,'
      '  NAG_DDATE = :NAG_DDATE,'
      '  NAG_DOC_SN = :NAG_DOC_SN'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_NAGRADI_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 392
  end
  object IBDataSet11_OTPUSK: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from OTPUSK'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into OTPUSK'
      
        '  (ID_S, OTP_VID, WORK_DATEB, WORK_DATEF, OTP_DAYS, OTP_DATEB, O' +
        'TP_DATEF, '
      '   OTP_OSNOVA)'
      'values'
      
        '  (:ID_S, :OTP_VID, :WORK_DATEB, :WORK_DATEF, :OTP_DAYS, :OTP_DA' +
        'TEB, :OTP_DATEF, '
      '   :OTP_OSNOVA)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  OTP_VID,'
      '  WORK_DATEB,'
      '  WORK_DATEF,'
      '  OTP_DAYS,'
      '  OTP_DATEB,'
      '  OTP_DATEF,'
      '  OTP_OSNOVA'
      'from OTPUSK '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from OTPUSK where ID_S=:ID')
    ModifySQL.Strings = (
      'update OTPUSK'
      'set'
      '  ID_S = :ID_S,'
      '  OTP_VID = :OTP_VID,'
      '  WORK_DATEB = :WORK_DATEB,'
      '  WORK_DATEF = :WORK_DATEF,'
      '  OTP_DAYS = :OTP_DAYS,'
      '  OTP_DATEB = :OTP_DATEB,'
      '  OTP_DATEF = :OTP_DATEF,'
      '  OTP_OSNOVA = :OTP_OSNOVA'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_OTPUSK_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 440
  end
  object IBDataSet12_SOC_LGOTI: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from SOC_LGOTI'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into SOC_LGOTI'
      '  (ID_S, L_NAME, L_DOC_NOMER, L_DOC_DATE, L_OSNOVA)'
      'values'
      '  (:ID_S, :L_NAME, :L_DOC_NOMER, :L_DOC_DATE, :L_OSNOVA)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  L_NAME,'
      '  L_DOC_NOMER,'
      '  L_DOC_DATE,'
      '  L_OSNOVA'
      'from SOC_LGOTI '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from SOC_LGOTI where ID_S=:ID')
    ModifySQL.Strings = (
      'update SOC_LGOTI'
      'set'
      '  ID_S = :ID_S,'
      '  L_NAME = :L_NAME,'
      '  L_DOC_NOMER = :L_DOC_NOMER,'
      '  L_DOC_DATE = :L_DOC_DATE,'
      '  L_OSNOVA = :L_OSNOVA'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_SOC_LGOTI_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 488
  end
  object IBDataSet13_TRUD_DOGOVOR: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from TRUD_DOGOVOR'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into TRUD_DOGOVOR'
      
        '  (ID_S, ID_D_STATUS, PREDMET, REGIM_W, USL_SOCSTR, USL_TR, DOP_' +
        'USL, USL_OPL_TR, '
      '   ADDRESS_REKV, NOTM_ACTS, D_FINDATE)'
      'values'
      
        '  (:ID_S, :ID_D_STATUS, :PREDMET, :REGIM_W, :USL_SOCSTR, :USL_TR' +
        ', :DOP_USL, '
      '   :USL_OPL_TR, :ADDRESS_REKV, :NOTM_ACTS, :D_FINDATE)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  ID_S,'
      '  ID_D_STATUS,'
      '  PREDMET,'
      '  REGIM_W,'
      '  USL_SOCSTR,'
      '  USL_TR,'
      '  DOP_USL,'
      '  USL_OPL_TR,'
      '  ADDRESS_REKV,'
      '  NOTM_ACTS,'
      '  D_FINDATE'
      'from TRUD_DOGOVOR '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from TRUD_DOGOVOR where ID_S=:ID and ID_D_STATUS=1')
    ModifySQL.Strings = (
      'update TRUD_DOGOVOR'
      'set'
      '  ID_S = :ID_S,'
      '  ID_D_STATUS = :ID_D_STATUS,'
      '  PREDMET = :PREDMET,'
      '  REGIM_W = :REGIM_W,'
      '  USL_SOCSTR = :USL_SOCSTR,'
      '  USL_TR = :USL_TR,'
      '  DOP_USL = :DOP_USL,'
      '  USL_OPL_TR = :USL_OPL_TR,'
      '  ADDRESS_REKV = :ADDRESS_REKV,'
      '  NOTM_ACTS = :NOTM_ACTS,'
      '  D_FINDATE = :D_FINDATE'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_TRUD_DOGOVOR_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 536
  end
  object DataSource: TDataSource
    DataSet = IBDataSet_AUTORIZATION
    Left = 40
    Top = 208
  end
  object IBDataSet_AUTORIZATION: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from AUTORIZATION'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into AUTORIZATION'
      '  (LOGIN, PASWORD, ACCESS_LEVEL)'
      'values'
      '  (:LOGIN, :PASWORD, :ACCESS_LEVEL)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  LOGIN,'
      '  PASWORD,'
      '  ACCESS_LEVEL'
      'from AUTORIZATION '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from AUTORIZATION')
    ModifySQL.Strings = (
      'update AUTORIZATION'
      'set'
      '  LOGIN = :LOGIN,'
      '  PASWORD = :PASWORD,'
      '  ACCESS_LEVEL = :ACCESS_LEVEL'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_AUTORIZATION_ID'
    Active = True
    Left = 80
    Top = 208
  end
  object DataSource3: TDataSource
    DataSet = IBDataSet3_POSITIONS
    Left = 536
    Top = 56
  end
  object IBDataSet3_POSITIONS: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from POSITIONS'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into POSITIONS'
      '  (POS_NAME, SALARY, P_STATUS)'
      'values'
      '  (:POS_NAME, :SALARY, :P_STATUS)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  POS_NAME,'
      '  SALARY,'
      '  P_STATUS'
      'from POSITIONS '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from POSITIONS where ID=:ID_POS and P_STATUS=1')
    ModifySQL.Strings = (
      'update POSITIONS'
      'set'
      '  POS_NAME = :POS_NAME,'
      '  SALARY = :SALARY,'
      '  P_STATUS = :P_STATUS'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_POSITIONS_ID'
    Active = True
    DataSource = DataSource1
    Left = 400
    Top = 56
  end
  object IBDataSet1_SOTRUDNIK: TIBDataSet
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      'delete from SOTRUDNIK'
      'where'
      '  ID = :OLD_ID')
    InsertSQL.Strings = (
      'insert into SOTRUDNIK'
      
        '  (TAB_NOMER, S_STATUS, SNILS, INN, SURNAME, NAME, SECONDNAME, P' +
        'OL, DATE_BIRTH, '
      
        '   KNLG_NAME, KNLG_LEVEL, DATE_SOSTAV, NAME_COMPANY, ID_POS, STA' +
        'G_RABOTI, '
      
        '   STGEN_D, STGEN_M, STGEN_Y, STNEPR_D, STNEPR_M, STNEPR_Y, STNA' +
        'DBV_D, '
      
        '   STNADBV_M, STNADBV_Y, SOSTVBRAKE, DATE_ISSUED, WHOM_ISSUED, A' +
        'DDRESS, '
      
        '   ADDRESS_FACT, DATE_REGIST, CAT_ZAPASA, ZVANIYE, PROFIL, ID_VU' +
        'S, KAT_GODN, '
      
        '   MLTR_NAME, DATE_UCHET, DOP_SVEDENIYA, SNYATS_UCHETA, CITIZENS' +
        'HIP, BIRTH_ADDRESS, '
      
        '   KONTAKT_NOMER, SOS_NA_UCHET, EMP_DP_POS, FIO_EMP_DP, SN_PASPO' +
        'RT)'
      'values'
      
        '  (:TAB_NOMER, :S_STATUS, :SNILS, :INN, :SURNAME, :NAME, :SECOND' +
        'NAME, :POL, '
      
        '   :DATE_BIRTH, :KNLG_NAME, :KNLG_LEVEL, :DATE_SOSTAV, :NAME_COM' +
        'PANY, :ID_POS, '
      
        '   :STAG_RABOTI, :STGEN_D, :STGEN_M, :STGEN_Y, :STNEPR_D, :STNEP' +
        'R_M, :STNEPR_Y, '
      
        '   :STNADBV_D, :STNADBV_M, :STNADBV_Y, :SOSTVBRAKE, :DATE_ISSUED' +
        ', :WHOM_ISSUED, '
      
        '   :ADDRESS, :ADDRESS_FACT, :DATE_REGIST, :CAT_ZAPASA, :ZVANIYE,' +
        ' :PROFIL, '
      
        '   :ID_VUS, :KAT_GODN, :MLTR_NAME, :DATE_UCHET, :DOP_SVEDENIYA, ' +
        ':SNYATS_UCHETA, '
      
        '   :CITIZENSHIP, :BIRTH_ADDRESS, :KONTAKT_NOMER, :SOS_NA_UCHET, ' +
        ':EMP_DP_POS, '
      '   :FIO_EMP_DP, :SN_PASPORT)')
    RefreshSQL.Strings = (
      'Select '
      '  ID,'
      '  TAB_NOMER,'
      '  S_STATUS,'
      '  SNILS,'
      '  INN,'
      '  SURNAME,'
      '  NAME,'
      '  SECONDNAME,'
      '  POL,'
      '  DATE_BIRTH,'
      '  KNLG_NAME,'
      '  KNLG_LEVEL,'
      '  DATE_SOSTAV,'
      '  NAME_COMPANY,'
      '  ID_POS,'
      '  STAG_RABOTI,'
      '  STGEN_D,'
      '  STGEN_M,'
      '  STGEN_Y,'
      '  STNEPR_D,'
      '  STNEPR_M,'
      '  STNEPR_Y,'
      '  STNADBV_D,'
      '  STNADBV_M,'
      '  STNADBV_Y,'
      '  SOSTVBRAKE,'
      '  DATE_ISSUED,'
      '  WHOM_ISSUED,'
      '  ADDRESS,'
      '  ADDRESS_FACT,'
      '  DATE_REGIST,'
      '  CAT_ZAPASA,'
      '  ZVANIYE,'
      '  PROFIL,'
      '  ID_VUS,'
      '  KAT_GODN,'
      '  MLTR_NAME,'
      '  DATE_UCHET,'
      '  DOP_SVEDENIYA,'
      '  SNYATS_UCHETA,'
      '  CITIZENSHIP,'
      '  BIRTH_ADDRESS,'
      '  KONTAKT_NOMER,'
      '  SOS_NA_UCHET,'
      '  EMP_DP_POS,'
      '  FIO_EMP_DP,'
      '  SN_PASPORT'
      'from SOTRUDNIK '
      'where'
      '  ID = :ID')
    SelectSQL.Strings = (
      'select * from SOTRUDNIK where S_STATUS=1')
    ModifySQL.Strings = (
      'update SOTRUDNIK'
      'set'
      '  TAB_NOMER = :TAB_NOMER,'
      '  S_STATUS = :S_STATUS,'
      '  SNILS = :SNILS,'
      '  INN = :INN,'
      '  SURNAME = :SURNAME,'
      '  NAME = :NAME,'
      '  SECONDNAME = :SECONDNAME,'
      '  POL = :POL,'
      '  DATE_BIRTH = :DATE_BIRTH,'
      '  KNLG_NAME = :KNLG_NAME,'
      '  KNLG_LEVEL = :KNLG_LEVEL,'
      '  DATE_SOSTAV = :DATE_SOSTAV,'
      '  NAME_COMPANY = :NAME_COMPANY,'
      '  ID_POS = :ID_POS,'
      '  STAG_RABOTI = :STAG_RABOTI,'
      '  STGEN_D = :STGEN_D,'
      '  STGEN_M = :STGEN_M,'
      '  STGEN_Y = :STGEN_Y,'
      '  STNEPR_D = :STNEPR_D,'
      '  STNEPR_M = :STNEPR_M,'
      '  STNEPR_Y = :STNEPR_Y,'
      '  STNADBV_D = :STNADBV_D,'
      '  STNADBV_M = :STNADBV_M,'
      '  STNADBV_Y = :STNADBV_Y,'
      '  SOSTVBRAKE = :SOSTVBRAKE,'
      '  DATE_ISSUED = :DATE_ISSUED,'
      '  WHOM_ISSUED = :WHOM_ISSUED,'
      '  ADDRESS = :ADDRESS,'
      '  ADDRESS_FACT = :ADDRESS_FACT,'
      '  DATE_REGIST = :DATE_REGIST,'
      '  CAT_ZAPASA = :CAT_ZAPASA,'
      '  ZVANIYE = :ZVANIYE,'
      '  PROFIL = :PROFIL,'
      '  ID_VUS = :ID_VUS,'
      '  KAT_GODN = :KAT_GODN,'
      '  MLTR_NAME = :MLTR_NAME,'
      '  DATE_UCHET = :DATE_UCHET,'
      '  DOP_SVEDENIYA = :DOP_SVEDENIYA,'
      '  SNYATS_UCHETA = :SNYATS_UCHETA,'
      '  CITIZENSHIP = :CITIZENSHIP,'
      '  BIRTH_ADDRESS = :BIRTH_ADDRESS,'
      '  KONTAKT_NOMER = :KONTAKT_NOMER,'
      '  SOS_NA_UCHET = :SOS_NA_UCHET,'
      '  EMP_DP_POS = :EMP_DP_POS,'
      '  FIO_EMP_DP = :FIO_EMP_DP,'
      '  SN_PASPORT = :SN_PASPORT'
      'where'
      '  ID = :OLD_ID')
    GeneratorField.Field = 'ID'
    GeneratorField.Generator = 'GEN_SOTRUDNIK_ID'
    GeneratorField.ApplyEvent = gamOnPost
    Active = True
    Left = 240
    Top = 137
  end
end
