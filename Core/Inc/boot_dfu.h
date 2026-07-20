/*
 * boot_dfu.h
 *
 * DFU-Ablaufsteuerung des Bootloaders (hardwareunabhängig, testbar).
 * Verarbeitet die empfangenen Pakete (DFUS/DFUD/DFUE) und ruft für die
 * Flash-Zugriffe die übergebenen Callbacks auf.
 */

#ifndef INC_BOOT_DFU_H_
#define INC_BOOT_DFU_H_

#include <stdint.h>

/* Bootloader-Version. Wird im Update-Modus auf das Kommando "VER" als
 * "BLV;<version>\n" gemeldet. Bei jeder Bootloader-Freigabe erhöhen. */
#define BL_VERSION  "1.1.1-dev"

/* Flash-Schnittstelle (auf dem Ziel per HAL, im Test per RAM-Puffer). */
typedef struct {
	int (*erase_app)(void);                                 /* App-Bereich löschen; 0 = ok */
	int (*write)(uint32_t offset, const uint8_t *data, uint32_t len); /* len ist Vielfaches von 8 */
	uint32_t (*crc)(uint32_t size);                         /* CRC32 über 'size' Byte der App */
	int (*commit_meta)(uint32_t size, uint32_t crc);        /* Metadaten schreiben; 0 = ok */
} dfu_flash_ops_t;

/* Vor dem Empfang einmalig aufrufen. */
void dfu_init(const dfu_flash_ops_t *ops);

/* Ein empfangenes Datenpaket verarbeiten.
 * resp: Puffer (>= 40 Byte) für die nullterminierte Antwortzeile.
 * do_reset: wird 1, wenn nach dem Senden der Antwort neu gestartet werden soll.
 * Rückgabe: Länge der Antwort (0 = keine). */
uint16_t dfu_on_data(const uint8_t *data, uint16_t len, char *resp, uint8_t *do_reset);

/* 1, sobald ein DFUS den App-Bereich gelöscht hat (bleibt bis zum Reset
 * gesetzt). Solange 0, liegt die alte App noch unversehrt im Flash -
 * der DFU-Leerlauf-Timeout darf dann gefahrlos zurück in die App booten. */
uint8_t dfu_flash_touched(void);

#endif /* INC_BOOT_DFU_H_ */
