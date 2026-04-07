Write-Host "builder>> Compilando el proyecto . . ."
g++ ./src/main.cpp ./src/screen.cpp -o ./out/main.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "builder>> El proyecto se ha compilado exitosamente!" -ForegroundColor Green
    Write-Host "builder>> El ejecutable se encuentra en: ./out/main.exe"
    Write-Host "builder>> Ejecutando el programa . . ." -ForegroundColor Cyan
    Write-Host "=====================================================================" 

    Start-Process -FilePath "./out/main.exe" -NoNewWindow -Wait
}
else {
    Write-Host "builder>> Error al compilar el proyecto." -ForegroundColor Red
    # Mostrar los errores de compilación
        g++ ./src/main.cpp ./src/screen.cpp -o ./out/main.exe 2>&1 | ForEach-Object { Write-Host $_ -ForegroundColor Red }
    Write-Host "builder>> Por favor, corrige los errores y vuelve a intentarlo." -ForegroundColor Gray
}