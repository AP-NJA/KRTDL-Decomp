#include "../macros.s"

invincibleDataConstructor:
/* 804F04DC 004EC31C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 804F04E0 004EC320  7C 08 02 A6 */	mflr r0
/* 804F04E4 004EC324  90 01 00 14 */	stw r0, 0x14(r1)
/* 804F04E8 004EC328  93 E1 00 0C */	stw r31, 0xc(r1)
/* 804F04EC 004EC32C  7C 7F 1B 78 */	mr r31, r3
/* 804F04F0 004EC330  90 83 00 00 */	stw r4, 0x0(r3)
/* 804F04F4 004EC334  38 63 00 04 */	addi r3, r3, 0x4
/* 804F04F8 004EC338  4B E5 F3 E1 */	bl intangibleDataConstructor
/* 804F04FC 004EC33C  38 00 00 00 */	li r0, 0x0
/* 804F0500 004EC340  98 1F 00 10 */	stb r0, 0x10(r31)
/* 804F0504 004EC344  98 1F 00 11 */	stb r0, 0x11(r31)
/* 804F0508 004EC348  98 1F 00 12 */	stb r0, 0x12(r31)
/* 804F050C 004EC34C  90 1F 00 14 */	stw r0, 0x14(r31)
/* 804F0510 004EC350  90 1F 00 18 */	stw r0, 0x18(r31)
/* 804F0514 004EC354  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 804F0518 004EC358  98 1F 00 24 */	stb r0, 0x24(r31)
/* 804F051C 004EC35C  7F E3 FB 78 */	mr r3, r31
/* 804F0520 004EC360  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 804F0524 004EC364  80 01 00 14 */	lwz r0, 0x14(r1)
/* 804F0528 004EC368  7C 08 03 A6 */	mtlr r0
/* 804F052C 004EC36C  38 21 00 10 */	addi r1, r1, 0x10
/* 804F0530 004EC370  4E 80 00 20 */	blr