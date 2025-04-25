# Perymetr - System Testowy Wzroku

## Opis Projektu
System perymetru do testowania pola widzenia, wykorzystujący STM32F4 i moduł Verilog do generowania wzorców testowych.

## Struktura Projektu
```
perymetr/
├── inc/           # Pliki nagłówkowe
├── src/           # Kod źródłowy C++
├── doc/           # Dokumentacja
├── lib/           # Biblioteki
└── verilog/       # Moduły Verilog
```

## Komponenty Sprzętowe
- STM32F4 Nucleo
- Wyświetlacz OLED (I2C)
- Czujnik ruchu oka
- Przycisk start/stop

## Funkcje Systemu
1. Generowanie wzorców testowych
2. Śledzenie ruchu oka
3. Zapisywanie wyników
4. Wyświetlanie wyników
5. Obsługa przycisku

## Przykład Użycia
```cpp
// Inicjalizacja systemu
Perymetr_Init();

// Uruchomienie testu
testRunning = true;
testStartTime = HAL_GetTick();

// Główna pętla
while (testRunning) {
    Perymetr_Run_Test();
    Perymetr_Update_Display();
}

// Przetwarzanie wyników
Perymetr_Process_Results();
Perymetr_Save_Data();
Perymetr_Display_Results();
```

## Moduł Verilog
Moduł `pattern_generator.v` generuje wzorce testowe:
- 8x8 matryca LED
- Kontrola jasności
- Kontrola prędkości
- Synchronizacja z STM32

## Testy
1. Testy jednostkowe C++:
   - Test generowania wzorców
   - Test śledzenia oka
   - Test zapisywania danych

2. Testy Verilog:
   - Symulacja wzorców
   - Test synchronizacji
   - Test jasności

## Kompilacja i Uruchomienie
1. Kompilacja STM32:
```bash
cd perymetr
pio run
```

2. Kompilacja Verilog:
```bash
cd perymetr/verilog
iverilog -o test_pattern test_pattern.v
```

3. Uruchomienie testów:
```bash
./test_pattern
```

## Wymagania
- PlatformIO
- Icarus Verilog
- STM32 HAL
- Biblioteki Adafruit

## Licencja
MIT License 