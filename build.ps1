Write-Host "builder>> Compilando el proyecto . . ."
g++ ./src/dasm.cpp ./src/inputArgs.cpp ./src/adminFile.cpp ./src/programController.cpp  ./src/about.cpp -o ./out/dasm.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "builder>> El proyecto se ha compilado exitosamente!" -ForegroundColor Green
    Write-Host "builder>> El ejecutable se encuentra en: ./out/dasm.exe"
}
else {
    Write-Host "builder>> Error al compilar el proyecto." -ForegroundColor Red
    # Mostrar los errores de compilación
        g++ ./src/dasm.cpp ./src/inputArgs.cpp ./src/adminFile.cpp ./src/programController.cpp  ./src/about.cpp -o ./out/dasm.exe 2>&1 | ForEach-Object { Write-Host $_ -ForegroundColor Red }
    Write-Host "builder>> Por favor, corrige los errores y vuelve a intentarlo." -ForegroundColor Gray
}