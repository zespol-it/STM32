# STM32 Project with Verilog Integration

## Project Structure
```
.
├── src/
│   ├── main.cpp          # Main STM32 application
│   ├── main.h            # Header file for STM32
│   └── verilog/
│       └── counter.v     # Verilog counter module
├── platformio.ini        # PlatformIO configuration
└── README.md            # This file
```

## Requirements
- PlatformIO
- STM32 HAL libraries
- Icarus Verilog (for Verilog simulation)

## Building the Project
1. Clean the project:
```bash
pio run -t clean
```

2. Build the project:
```bash
pio run
```

## Components
### STM32 Application
- Main application running on STM32F4 microcontroller
- UART communication at 115200 baud
- LED control functionality

### Verilog Module
- 8-bit counter implementation
- Clock and reset inputs
- Synchronous reset functionality

## Usage
1. Connect STM32 board to your computer
2. Upload the firmware:
```bash
pio run -t upload
```

3. Monitor serial output:
```bash
pio device monitor
```

## License
MIT License