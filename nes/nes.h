#pragma once

#include "def.h"
#include "cpu.h"
#include "ppu.h"
#include "cart.h"
#include "window.h"

struct ines_header {
	u8 ines[4];
	u8 prg_sz;
	u8 chr_sz;
	u8 fl6;
	u8 fl7;
	u8 ram_sz;
	u8 tv;
	u8 fl10;
	u8 reserved[5];
};

struct nes {
	struct ines_header hdr;
	struct window window;
	struct cpu cpu;
	struct cart cart;
	struct ppu ppu;
	u8 joyp;
	u8 strobe;
	u8 jidx;
};
extern struct nes nes;

int nes_init();

u8 nes_dbg_read(u16);

u8 _nes_read(u16);
void _nes_write(u16, u8);

u8 nes_read(u16);
void nes_write(u16, u8);

u16 nes_read16(u16);
void nes_write16(u16, u16);

void nes_cycle();
int nes_mapper_supported();
