@echo off
echo =========== ��ʼ����! ===========

set PROTO_PATH=.
set PROTOC_PATH=.
set CPP_PATH=.

for /r %PROTO_PATH% %%i in (*.proto) do (
    echo ------- ��ǰ�ļ���%%i
    setlocal enabledelayedexpansion
    set RELATIVE_PATH=%%i:~%PROTO_PATH%:~2%
    echo @���·����!RELATIVE_PATH!
    echo 6
    %PROTOC_PATH%\protoc.exe --cpp_out=!CPP_PATH! !RELATIVE_PATH!
    endlocal
    echo @i: %%i
::set RELATIVE_PATH=!RELATIVE_PATH:\=\\!
    :: set PROTO=%%i:~%PROTO_PATH%:~2%
    :: echo PROTO: %PROTO%
    .\protoc.exe --cpp_out=.\cpp\ %PROTO%
)

echo =========== �������! ===========
pause