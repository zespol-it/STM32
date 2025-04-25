# Simple - Podstawowy Projekt STM32

## Opis Projektu
Podstawowy projekt demonstracyjny dla STM32F4, zawierający:
- Test LED
- Komunikację UART
- Podstawowe operacje GPIO

## Struktura Projektu
```
simple/
├── inc/           # Pliki nagłówkowe
│   └── main.h     # Główny plik nagłówkowy
├── src/           # Kod źródłowy C++
│   └── main.cpp   # Główny plik źródłowy
└── README.md      # Ten plik
```

## Wymagania Sprzętowe
- STM32F4 Nucleo
- LED na pinie PD12
- Połączenie UART

## Wymagania Programowe
- PlatformIO
- STM32 HAL

## Instalacja
1. Sklonuj repozytorium
2. Zainstaluj PlatformIO:
```bash
brew install platformio
```

## Kompilacja i Uruchomienie
```bash
cd simple
pio run
```

## Funkcje Systemu
1. Test LED:
   - Miganie LED 5 razy
   - Opóźnienie 200ms między mignięciami
   - Powtarzanie co 2 sekundy

2. Komunikacja UART:
   - Prędkość 115200 baud
   - Wysyłanie komunikatów testowych
   - Monitorowanie stanu systemu

## Przykład Użycia
```cpp
// Inicjalizacja systemu
HAL_Init();
SystemClock_Config();
MX_GPIO_Init();
MX_USART2_UART_Init();

// Główna pętla
while (1) {
    // Test LED
    Test_LED_Pattern();
    
    // Test UART
    Test_UART_Communication();
    
    // Opóźnienie
    HAL_Delay(2000);
}
```

## Licencja
MIT License

## Autor
[Twoje Imię]

## Kontakt
[Twoje dane kontaktowe] 