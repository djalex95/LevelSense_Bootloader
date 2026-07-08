## Bootloader v1.1.0

**Neu: Notfall-Update per Taster (Firmware-Recovery).**
Wird der Taster beim Einschalten (Anlegen der Stromversorgung) gedrückt gehalten,
geht der Sensor in den DFU-Modus (weißes Blinken) – auch wenn eine gültige, aber
unbrauchbare Firmware installiert ist. Damit ist immer ein Update möglich.
Nicht-destruktiv: ohne Update bootet beim nächsten Start die vorhandene App normal.

Außerdem: meldet im Update-Modus seine Version auf das Kommando `VER` (`BLV;1.1.0`).

**Flashen:** per ST-Link nach `0x08000000` (nicht per OTA).
- `Bootloader_v1.1.0.bin`
- `Bootloader_v1.1.0.hex` (mit eingetragener Adresse)
