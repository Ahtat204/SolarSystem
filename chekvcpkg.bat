@echo off
REM ===============================
REM Install vcpkg and required libraries (check existence)
REM ===============================

REM Set vcpkg directory
set VCPKG_DIR=%CD%\vcpkg

REM 1️⃣ Check if vcpkg already exists
if exist "%VCPKG_DIR%" (
    echo vcpkg already exists. Skipping clone.
) else (
    echo Cloning vcpkg...
    git clone https://github.com/microsoft/vcpkg.git "%VCPKG_DIR%"
    if %ERRORLEVEL% neq 0 (
        echo Failed to clone vcpkg
        exit /b 1
    )
)

REM 2️⃣ Bootstrap vcpkg (run even if it exists to ensure latest)
echo Bootstrapping vcpkg...
cd "%VCPKG_DIR%"
.\bootstrap-vcpkg.bat
if %ERRORLEVEL% neq 0 (
    echo Failed to bootstrap vcpkg
    exit /b 1
)

REM 3️⃣ Install libraries (stb, glad, glfw3, glm)
echo Installing/updating libraries: stb, glad, glfw3, glm...
.\vcpkg install stb glad glfw3 glm
if %ERRORLEVEL% neq 0 (
    echo Failed to install libraries
    exit /b 1
)

echo =================================
echo All done! vcpkg and libraries installed successfully.
echo =================================
pause