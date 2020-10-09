::
::  MultiCore_Debug.bat
::

@ECHO off

SET EnableSerialJTAG=1

:SHOW_COMMAND

CLS
SET "CUR_DIR=%cd%"

ECHO [MT6291 Multi-Core Debugging]

ECHO [A] [DualCore] Load code and attach on both PSCore and L1Core
ECHO [B] [DualCore] Load code and attach on PSCore. L1Core will free run.
ECHO [C] [DualCore] Load symbol and attach on L1Core
ECHO [G] [DualCore] Load code and attach on L1Core. PSCore will free run.
ECHO [H] [DualCore] Load symbol and attach on PSCore
ECHO [I] [DualCore] Load symbol and attach on both PSCore and L1Core
ECHO [M] [DualCore][Flashed AP]Load code and attach on both PSCore and L1Core
ECHO [N] [DualCore][Flashed AP]Load code and attach on PSCore. L1Core will free run.
ECHO [O] [DualCore][Flashed AP]Load code and attach on L1Core. PSCore will free run.
ECHO [P] [DualCore][Palladium]Load symbol and attach on both PSCore and L1Core
ECHO [Q] [DualCore][Palladium]Load symbol and attach on both PSCore and L1Core. Load DSP code.
ECHO [S] [DualCore][Self-Selection] Load symbol and attach on both PS/L1Core
ECHO [E] Exit

SET /p choice=">"

IF '%choice%'=='e' (
    GOTO EXIT
)
IF '%choice%'=='E' (
    GOTO EXIT
)
IF '%choice%'=='x' (
    GOTO EXIT
)
IF '%choice%'=='X' (
    GOTO EXIT
)

IF '%choice%'=='a' (
    GOTO LOAD_CODE_ATTACH_ON_BOTH_CORE
)
IF '%choice%'=='A' (
    GOTO LOAD_CODE_ATTACH_ON_BOTH_CORE
)
IF '%choice%'=='b' (
    GOTO LOAD_CODE_ATTACH_ON_PSCORE
)
IF '%choice%'=='B' (
    GOTO LOAD_CODE_ATTACH_ON_PSCORE
)
IF '%choice%'=='c' (
    GOTO ATTACH_ON_L1CORE
)
IF '%choice%'=='C' (
    GOTO ATTACH_ON_L1CORE
)
IF '%choice%'=='g' (
    GOTO LOAD_CODE_ATTACH_ON_L1CORE
)
IF '%choice%'=='G' (
    GOTO LOAD_CODE_ATTACH_ON_L1CORE
)
IF '%choice%'=='h' (
    GOTO ATTACH_ON_PSCORE
)
IF '%choice%'=='H' (
    GOTO ATTACH_ON_PSCORE
)
IF '%choice%'=='i' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE
)
IF '%choice%'=='I' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE
)
IF '%choice%'=='m' (
    GOTO LOAD_CODE_ATTACH_ON_BOTH_CORE_FLASHED_AP
)
IF '%choice%'=='M' (
    GOTO LOAD_CODE_ATTACH_ON_BOTH_CORE_FLASHED_AP
)
IF '%choice%'=='n' (
    GOTO LOAD_CODE_ATTACH_ON_PSCORE_FLASHED_AP
)
IF '%choice%'=='N' (
    GOTO LOAD_CODE_ATTACH_ON_PSCORE_FLASHED_AP
)
IF '%choice%'=='o' (
    GOTO LOAD_CODE_ATTACH_ON_L1CORE_FLASHED_AP
)
IF '%choice%'=='O' (
    GOTO LOAD_CODE_ATTACH_ON_L1CORE_FLASHED_AP
)
IF '%choice%'=='Q' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_LOAD_DSP_CODE_PALLADIUM
)
IF '%choice%'=='q' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_LOAD_DSP_CODE_PALLADIUM
)
IF '%choice%'=='P' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_PALLADIUM
)
IF '%choice%'=='p' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_PALLADIUM
)
IF '%choice%'=='s' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_SELF_SELECT
)
IF '%choice%'=='S' (
    GOTO LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_SELF_SELECT
)


GOTO MODEM_ATTACH_ONLY

:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load code and attach on both PSCore and L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_CODE_ATTACH_ON_BOTH_CORE
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
ECHO Load code and attach on dual core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadCode_Attach.csf

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadSym_Attach.csf

GOTO END

:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: [Flashed AP] Load code and attach on both PSCore and L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_CODE_ATTACH_ON_BOTH_CORE_FLASHED_AP
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
ECHO Load code and attach on dual core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadCode_Attach_FlashedAP.csf

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadSym_Attach.csf

GOTO END




:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load code and attach on PSCore procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_CODE_ATTACH_ON_PSCORE
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F

ECHO Load code and attach on PSCore core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadCode_Attach.csf

GOTO END




:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: [Flashed AP] Load code and attach on PSCore procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_CODE_ATTACH_ON_PSCORE_FLASHED_AP
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F

ECHO Load code and attach on PSCore core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadCode_Attach_FlashedAP.csf

GOTO END




:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load code and attach on L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_CODE_ATTACH_ON_L1CORE
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F

ECHO Load code and attach on L1Core core.

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadCode_Attach.csf

GOTO END




:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: [Flashed AP] Load code and attach on L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_CODE_ATTACH_ON_L1CORE_FLASHED_AP
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F

ECHO Load code and attach on L1Core core.

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadCode_Attach_FlashedAP.csf

GOTO END




:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load Symbol and Attach on PSCore procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:ATTACH_ON_PSCORE
ECHO Load code and attach on PSCore core.

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadSym_Attach.csf

GOTO END




:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load Symbol and Attach on L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:ATTACH_ON_L1CORE
ECHO Load code and attach on L1Core core.

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadSym_Attach.csf

GOTO END


:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load symbol and attach on both PSCore and L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_SYMBOL_ATTACH_ON_BOTH_CORE
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
ECHO Load symbol and attach on dual core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadSym_Attach.csf

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadSym_Attach.csf

GOTO END

:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load symbol and attach on both PSCore and L1Core procedure(Palladium)
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_PALLADIUM
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
ECHO Load symbol and attach on dual core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 "%CUR_DIR%\Palladium\MD_DualCoreDebugging_P_LoadSym_Attach_Pallaidum.csf"

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 "%CUR_DIR%\Palladium\MD_DualCoreDebugging_L_LoadSym_Attach_Palladium.csf"

GOTO END

:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::
:: Load symbol and attach on both PSCore and L1Core with Load DSP code procedure(Palladium)
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_LOAD_DSP_CODE_PALLADIUM
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
ECHO Load symbol and attach on dual core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 "%CUR_DIR%\Palladium\MD_DualCoreDebugging_P_LoadSym_Attach_Pallaidum.csf"

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 "%CUR_DIR%\Palladium\MD_DualCoreDebugging_L_LoadSym_Attach_DSP_LoadCode_Palladium.csf"

GOTO END

:: _SELF_SELECT Load symbol and attach on both PSCore and L1Core procedure
:: ::::::::::::::::::::::::::::::::::::::::::::::::::::::: ::

:LOAD_SYMBOL_ATTACH_ON_BOTH_CORE_SELF_SELECT
ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
ECHO Load symbol and attach on dual core.

ECHO Starting PSCore ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Master -Core=1 MD_DualCoreDebugging_P_LoadSym_Attach_USER_ELF_SELECT.csf

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Starting L1Core ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -Core=2 MD_DualCoreDebugging_L_LoadSym_Attach_USER_ELF_SELECT.csf

GOTO END


:END
ECHO ************************
//ECHO Press any key to start a new debug session...
//PAUSE
//SET choice=
GOTO SHOW_COMMAND
:EXIT
ECHO ************************
ECHO Bye~
PAUSE
