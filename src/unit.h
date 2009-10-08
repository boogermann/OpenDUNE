/* $Id$ */

#ifndef UNIT_H
#define UNIT_H

/**
 * Types of Units available in the game.
 * TODO -- Complete the enum.
 */
typedef enum UnitType {
	UNIT_25 = 25,

	UNIT_INVALID = 0xFFFF
} UnitType;

MSVC_PACKED_BEGIN
/**
 * A Unit as stored in the memory.
 */
typedef struct Unit {
	/* 0000(2)   */ PACK uint16 index;                      /*!< The index of the Unit in the array. */
	/* 0002(1)   */ PACK uint8  typeID;                     /*!< Type of Unit. */
	/* 0003(1)   */ PACK uint8  variable_03;                /*!< ?? */
	/* 0004(2)   */ PACK uint16 variable_04;                /*!< ?? Bitflags. 0x0001 - Used, 0x0002 - Allocated?, 0x0004 - Being-built? */
	/* 0006(2)   */ PACK uint16 variable_06;                /*!< ?? */
	/* 0008(1)   */ PACK uint8  houseID;                    /*!< House of Unit. */
	/* 0009(1)   */ PACK uint8  variable_09;                /*!< ?? */
	/* 000A(4)   */ PACK csip32 variable_0A;                /*!< ?? */
	/* 000E(2)   */ PACK uint16 variable_0E;                /*!< ?? */
	/* 0010(2)   */ PACK uint16 variable_10;                /*!< ?? */
	/* 0012()    */ PACK uint8   unknown_0012[0x0037];
	/* 0049(4)   */ PACK csip32 variable_49;                /*!< ?? */
	/* 004D(2)   */ PACK uint16 variable_4D;                /*!< ?? */
	/* 004F(1)   */ PACK uint8  variable_4F;                /*!< ?? */
	/* 0050(1)   */ PACK uint8  variable_50;                /*!< ?? */
	/* 0051(1)   */ PACK uint8  variable_51;                /*!< ?? */
	/* 0052(2)   */ PACK uint16 variable_52;                /*!< ?? */
	/* 0054(2)   */ PACK uint8   unknown_0054[0x0002];
	/* 0056(2)   */ PACK uint16 variable_56;                /*!< ?? */
	/* 0058(1)   */ PACK uint8  variable_58;                /*!< ?? */
	/* 0059(1)   */ PACK uint8  deviated;                   /*!< ?? If non-zero, the unit is deviated, but what does it hold exactly? */
	/* 005A(4)   */ PACK csip32 variable_5A;                /*!< ?? */
	/* 005E(4)   */ PACK csip32 variable_5E;                /*!< ?? */
	/* 0062()    */ PACK uint8   unknown_005A[0x000A];
	/* 006C(1)   */ PACK uint8  variable_6C;                /*!< ?? */
	/* 006D(1)   */ PACK uint8  variable_6D;                /*!< ?? */
	/* 006E(1)   */ PACK uint8  variable_6E;                /*!< ?? */
	/* 006F(1)   */ PACK uint8  variable_6F;                /*!< ?? */
	/* 0070(1)   */ PACK uint16 variable_70;                /*!< ?? */
	/* 0072(1)   */ PACK uint8  variable_72;                /*!< ?? */
	/* 0073()    */ PACK uint8   unknown_0073[0x000D];
} GCC_PACKED Unit;
MSVC_PACKED_END
assert_compile(sizeof(Unit) == 0x80);

MSVC_PACKED_BEGIN
/**
 * Static information per Unit type.
 */
typedef struct UnitInfo {
	/* 0000()    */ PACK uint8   unknown_0000[0x0010];
	/* 0010(2)   */ PACK uint16 variable_10;                /*!< ?? */
	/* 0012()    */ PACK uint8   unknown_0012[0x0006];
	/* 0018(2)   */ PACK uint16 buildTime;                  /*!< Time required to build this Unit. */
	/* 001A()    */ PACK uint8   unknown_001A[0x000E];
	/* 0028(2)   */ PACK uint16 variable_28;                /*!< ?? */
	/* 002A()    */ PACK uint8   unknown_002A[0x0008];
	/* 0032(2)   */ PACK uint16 indexStart;                 /*!< At Unit create, between this and indexEnd (including) a free index is picked. */
	/* 0034(2)   */ PACK uint16 indexEnd;                   /*!< At Unit create, between indexStart and this (including) a free index is picked. */
	/* 0036()    */ PACK uint8   unknown_0036[0x0006];
	/* 003C(2)   */ PACK uint16 variable_3C;                /*!< ?? */
	/* 003E()    */ PACK uint8   unknown_003E[0x000A];
	/* 0048(2)   */ PACK uint16 variable_48;                /*!< ?? */
	/* 004A()    */ PACK uint8   unknown_004A[0x0010];
} GCC_PACKED UnitInfo;
MSVC_PACKED_END
assert_compile(sizeof(UnitInfo) == 0x5A);

extern UnitInfo *g_unitInfo;

uint8 Unit_GetHouseID(Unit *u);
extern struct Unit *Unit_Create(uint16 index, uint8 typeID, uint8 houseID, csip32 var0C, uint16 var10);


extern void emu_Unit_GetHouseID();
extern void emu_Unit_Create();

#endif /* UNIT_H */
