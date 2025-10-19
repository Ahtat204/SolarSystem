@echo off
setlocal

:: Define vcpkg directory name
set VCPKG_DIR=vcpkg

:: Clone vcpkg if it doesn't exist
if not exist %VCPKG_DIR% (
    echo Cloning vcpkg...
    git clone https://github.com/microsoft/vcpkg.git %VCPKG_DIR%
)

:: Bootstrap vcpkg
echo Bootstrapping vcpkg...
cd %VCPKG_DIR%
call bootstrap-vcpkg.bat
cd ..

:: Install dependencies
echo Installing dependencies...

:: Note: Add --triplet if you want x64-windows or x64-windows-static
%VCPKG_DIR%\vcpkg install glfw3 glad glm

echo All dependencies installed successfully.

pause
