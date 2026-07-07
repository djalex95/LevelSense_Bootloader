# OTA-Bootloader (STM32G0B1KB)

Eigenständiger Bootloader für den CAN/BLE-Füllstandsensor. Er liegt bei
`0x08000000`, prüft beim Start die Anwendung und nimmt bei Bedarf ein
Firmware-Update über BLE (Würth Proteus-e) entgegen. Die eigentliche
Anwendungsfirmware liegt in einem separaten Repository.

## Flash-Layout

| Bereich | Adresse | Größe |
|---|---|---|
| Bootloader | `0x08000000` | 32 KB |
| Anwendung | `0x08008000` | 90 KB |
| DFU-Metadaten | `0x0801E800` | 2 KB |
| Config-Speicher | `0x0801F000` | 4 KB |

## Struktur

- `Core/Src/main.c` – Entscheidung (App/DFU), Flash-Zugriffe, App-Sprung, DFU-Schleife
- `Core/Src/boot_dfu.c`, `Core/Inc/boot_dfu.h` – DFU-Ablauf (hardwareunabhängig)
- `Core/Src/boot_proteus.c`, `Core/Inc/boot_proteus.h` – Proteus-e-UART-Treiber (Polling)
- `Core/Src/dfu_common.c`, `Core/Inc/dfu_common.h` – CRC32 + gemeinsame Definitionen
- `STM32G0B1KBUXN_BOOT.ld` – Linker-Skript (Bootloader bei `0x08000000`)
- `Bootloader/DESIGN.md` – Gesamtentwurf des OTA-Konzepts
- `Bootloader/tools/make_meta.py` – Metadaten für die Erst-Inbetriebnahme

## Signalisierung (RGB-LED)

- **Weißes Blinken**: Bootloader/DFU-Modus, wartet auf Update
- **Blaues Blinken**: Daten werden übertragen

## Bauen und Flashen

Details in `Bootloader/README.md` und `Bootloader/DESIGN.md`. Kurz:

1. Projekt in STM32CubeIDE öffnen und bauen (Ziel: STM32G0B1KBUxN).
2. Erst-Inbetriebnahme per SWD: Bootloader `@0x08000000`, App `@0x08008000`,
   `meta.bin` (aus `make_meta.py`) `@0x0801E800`.
3. Danach laufen Updates kabellos per BLE über die Handy-App.

> Hinweis: `dfu_common.*` und das DFU-Protokoll müssen mit der Anwendungsfirmware
> zusammenpassen. Bei Änderungen am Protokoll beide Repositories aktualisieren.
