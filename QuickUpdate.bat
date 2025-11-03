@echo off
setlocal enabledelayedexpansion

echo ============================================
echo   Checking Git Submodules in Vendors folder
echo ============================================

REM --- Kiểm tra xem đang ở trong repo Git chưa
git rev-parse --is-inside-work-tree >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] This is not a Git repository.
    pause
    exit /b 1
)

REM --- Kiểm tra thư mục Vendors
if not exist Vendors (
    echo [INFO] Vendors folder not found. Creating...
    mkdir Vendors
)

REM --- Kiểm tra danh sách submodules trong file .gitmodules
if not exist .gitmodules (
    echo [INFO] No .gitmodules file found. Nothing to update.
    pause
    exit /b 0
)

echo [INFO] Checking submodule status...
git submodule status > temp_submodules.txt

set needUpdate=0

for /f "tokens=1*" %%A in (temp_submodules.txt) do (
    set "line=%%A"
    if "!line!"=="-" (
        set needUpdate=1
    )
)

del temp_submodules.txt >nul 2>&1

if %needUpdate%==1 (
    echo [INFO] Some submodules are not initialized. Updating...
    git submodule update --init --recursive
) else (
    echo [OK] All submodules are already initialized.
)

echo ============================================
echo Done.
echo ============================================

pause
