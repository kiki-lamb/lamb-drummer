
.pioenvs/nanoatmega328/firmware.elf:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
       0:	0c 94 ee 00 	jmp	0x1dc	; 0x1dc <__dtors_end>
       4:	0c 94 64 09 	jmp	0x12c8	; 0x12c8 <__vector_1>
       8:	0c 94 3d 09 	jmp	0x127a	; 0x127a <__vector_2>
       c:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      10:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      14:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      18:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      1c:	0c 94 40 0b 	jmp	0x1680	; 0x1680 <__vector_7>
      20:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      24:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      28:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      2c:	0c 94 63 07 	jmp	0xec6	; 0xec6 <__vector_11>
      30:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      34:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      38:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      3c:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      40:	0c 94 18 11 	jmp	0x2230	; 0x2230 <__vector_16>
      44:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      48:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      4c:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      50:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      54:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      58:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      5c:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>
      60:	0c 94 8b 09 	jmp	0x1316	; 0x1316 <__vector_24>
      64:	0c 94 16 01 	jmp	0x22c	; 0x22c <__bad_interrupt>

00000068 <__trampolines_end>:
      68:	00 40       	sbci	r16, 0x00	; 0
      6a:	7a 10       	cpse	r7, r10
      6c:	f3 5a       	subi	r31, 0xA3	; 163
      6e:	00 a0       	ldd	r0, Z+32	; 0x20
      70:	72 4e       	sbci	r23, 0xE2	; 226
      72:	18 09       	sbc	r17, r8
      74:	00 10       	cpse	r0, r0
      76:	a5 d4       	rcall	.+2378   	; 0x9c2 <_ZN7SSIntro10impl_enterEv+0x7c>
      78:	e8 00       	.word	0x00e8	; ????
      7a:	00 e8       	ldi	r16, 0x80	; 128
      7c:	76 48       	sbci	r23, 0x86	; 134
      7e:	17 00       	.word	0x0017	; ????
      80:	00 e4       	ldi	r16, 0x40	; 64
      82:	0b 54       	subi	r16, 0x4B	; 75
      84:	02 00       	.word	0x0002	; ????
      86:	00 ca       	rjmp	.-3072   	; 0xfffff488 <__eeprom_end+0xff7ef488>
      88:	9a 3b       	cpi	r25, 0xBA	; 186
      8a:	00 00       	nop
      8c:	00 e1       	ldi	r16, 0x10	; 16
      8e:	f5 05       	cpc	r31, r5
      90:	00 00       	nop
      92:	80 96       	adiw	r24, 0x20	; 32
      94:	98 00       	.word	0x0098	; ????
      96:	00 00       	nop
      98:	40 42       	sbci	r20, 0x20	; 32
      9a:	0f 00       	.word	0x000f	; ????
      9c:	00 00       	nop
      9e:	a0 86       	std	Z+8, r10	; 0x08
      a0:	01 00       	.word	0x0001	; ????
      a2:	00 00       	nop
      a4:	10 27       	eor	r17, r16
      a6:	00 00       	nop
      a8:	00 00       	nop
      aa:	e8 03       	fmulsu	r22, r16
      ac:	00 00       	nop
      ae:	00 00       	nop
      b0:	64 00       	.word	0x0064	; ????
      b2:	00 00       	nop
      b4:	00 00       	nop
      b6:	0a 00       	.word	0x000a	; ????
      b8:	00 00       	nop
      ba:	00 00       	nop
      bc:	01 00       	.word	0x0001	; ????
      be:	00 00       	nop
      c0:	00 00       	nop
      c2:	2c 76       	andi	r18, 0x6C	; 108
      c4:	d8 88       	ldd	r13, Y+16	; 0x10
      c6:	dc 67       	ori	r29, 0x7C	; 124
      c8:	4f 08       	sbc	r4, r15
      ca:	23 df       	rcall	.-442    	; 0xffffff12 <__eeprom_end+0xff7eff12>
      cc:	c1 df       	rcall	.-126    	; 0x50 <__SREG__+0x11>
      ce:	ae 59       	subi	r26, 0x9E	; 158
      d0:	e1 b1       	in	r30, 0x01	; 1
      d2:	b7 96       	adiw	r30, 0x27	; 39
      d4:	e5 e3       	ldi	r30, 0x35	; 53
      d6:	e4 53       	subi	r30, 0x34	; 52
      d8:	c6 3a       	cpi	r28, 0xA6	; 166
      da:	e6 51       	subi	r30, 0x16	; 22
      dc:	99 76       	andi	r25, 0x69	; 105
      de:	96 e8       	ldi	r25, 0x86	; 134
      e0:	e6 c2       	rjmp	.+1484   	; 0x6ae <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv+0x12>
      e2:	84 26       	eor	r8, r20
      e4:	eb 89       	ldd	r30, Y+19	; 0x13
      e6:	8c 9b       	sbis	0x11, 4	; 17
      e8:	62 ed       	ldi	r22, 0xD2	; 210
      ea:	40 7c       	andi	r20, 0xC0	; 192
      ec:	6f fc       	.word	0xfc6f	; ????
      ee:	ef bc       	out	0x2f, r14	; 47
      f0:	9c 9f       	mul	r25, r28
      f2:	40 f2       	brcs	.-112    	; 0x84 <__trampolines_end+0x1c>
      f4:	ba a5       	ldd	r27, Y+42	; 0x2a
      f6:	6f a5       	ldd	r22, Y+47	; 0x2f
      f8:	f4 90       	lpm	r15, Z
      fa:	05 5a       	subi	r16, 0xA5	; 165
      fc:	2a f7       	brpl	.-54     	; 0xc8 <__trampolines_end+0x60>
      fe:	5c 93       	st	X, r21
     100:	6b 6c       	ori	r22, 0xCB	; 203
     102:	f9 67       	ori	r31, 0x79	; 121
     104:	6d c1       	rjmp	.+730    	; 0x3e0 <_ZN19ButtonSouce9impl_pollEv.lto_priv.153+0x12>
     106:	1b fc       	.word	0xfc1b	; ????
     108:	e0 e4       	ldi	r30, 0x40	; 64
     10a:	0d 47       	sbci	r16, 0x7D	; 125
     10c:	fe f5       	brtc	.+126    	; 0x18c <port_to_mode_PGM+0x5>
     10e:	20 e6       	ldi	r18, 0x60	; 96
     110:	b5 00       	.word	0x00b5	; ????
     112:	d0 ed       	ldi	r29, 0xD0	; 208
     114:	90 2e       	mov	r9, r16
     116:	03 00       	.word	0x0003	; ????
     118:	94 35       	cpi	r25, 0x54	; 84
     11a:	77 05       	cpc	r23, r7
     11c:	00 80       	ld	r0, Z
     11e:	84 1e       	adc	r8, r20
     120:	08 00       	.word	0x0008	; ????
     122:	00 20       	and	r0, r0
     124:	4e 0a       	sbc	r4, r30
     126:	00 00       	nop
     128:	00 c8       	rjmp	.-4096   	; 0xfffff12a <__eeprom_end+0xff7ef12a>
     12a:	0c 33       	cpi	r16, 0x3C	; 60
     12c:	33 33       	cpi	r19, 0x33	; 51
     12e:	33 0f       	add	r19, r19
     130:	98 6e       	ori	r25, 0xE8	; 232
     132:	12 83       	std	Z+2, r17	; 0x02
     134:	11 41       	sbci	r17, 0x11	; 17
     136:	ef 8d       	ldd	r30, Y+31	; 0x1f
     138:	21 14       	cp	r2, r1
     13a:	89 3b       	cpi	r24, 0xB9	; 185
     13c:	e6 55       	subi	r30, 0x56	; 86
     13e:	16 cf       	rjmp	.-468    	; 0xffffff6c <__eeprom_end+0xff7eff6c>
     140:	fe e6       	ldi	r31, 0x6E	; 110
     142:	db 18       	sub	r13, r11
     144:	d1 84       	ldd	r13, Z+9	; 0x09
     146:	4b 38       	cpi	r20, 0x8B	; 139
     148:	1b f7       	brvc	.-58     	; 0x110 <__trampolines_end+0xa8>
     14a:	7c 1d       	adc	r23, r12
     14c:	90 1d       	adc	r25, r0
     14e:	a4 bb       	out	0x14, r26	; 20
     150:	e4 24       	eor	r14, r4
     152:	20 32       	cpi	r18, 0x20	; 32
     154:	84 72       	andi	r24, 0x24	; 36
     156:	5e 22       	and	r5, r30
     158:	81 00       	.word	0x0081	; ????
     15a:	c9 f1       	breq	.+114    	; 0x1ce <digital_pin_to_timer_PGM+0xb>
     15c:	24 ec       	ldi	r18, 0xC4	; 196
     15e:	a1 e5       	ldi	r26, 0x51	; 81
     160:	3d 27       	eor	r19, r29

00000162 <port_to_input_PGM>:
     162:	00 00 00 00 23 00 26 00 29 00                       ....#.&.).

0000016c <_ZZN6SSMain9draw_barsEvE3__c>:
     16c:	7c 00                                               |.

0000016e <_ZZN7SSIntro10impl_enterEvE3__c_1>:
     16e:	20 00                                                .

00000170 <_ZZN7SSIntro10impl_enterEvE3__c_0>:
     170:	20 00                                                .

00000172 <_ZZN7SSIntro10impl_enterEvE3__c>:
     172:	20 20 20 20 4c 61 6d 62 20 44 72 75 6d 6d 65 72         Lamb Drummer
     182:	20 20 20 20 00                                          .

00000187 <port_to_mode_PGM>:
     187:	00 00 00 00 24 00 27 00 2a 00                       ....$.'.*.

00000191 <port_to_output_PGM>:
     191:	00 00 00 00 25 00 28 00 2b 00                       ....%.(.+.

0000019b <digital_pin_to_port_PGM>:
     19b:	04 04 04 04 04 04 04 04 02 02 02 02 02 02 03 03     ................
     1ab:	03 03 03 03                                         ....

000001af <digital_pin_to_bit_mask_PGM>:
     1af:	01 02 04 08 10 20 40 80 01 02 04 08 10 20 01 02     ..... @...... ..
     1bf:	04 08 10 20                                         ... 

000001c3 <digital_pin_to_timer_PGM>:
     1c3:	00 00 00 08 00 02 01 00 00 03 04 07 00 00 00 00     ................
     1d3:	00 00 00 00 00                                      .....

000001d8 <__ctors_start>:
     1d8:	18 13       	cpse	r17, r24

000001da <__ctors_end>:
     1da:	62 11       	cpse	r22, r2

000001dc <__dtors_end>:
     1dc:	11 24       	eor	r1, r1
     1de:	1f be       	out	0x3f, r1	; 63
     1e0:	cf ef       	ldi	r28, 0xFF	; 255
     1e2:	d8 e0       	ldi	r29, 0x08	; 8
     1e4:	de bf       	out	0x3e, r29	; 62
     1e6:	cd bf       	out	0x3d, r28	; 61

000001e8 <__do_copy_data>:
     1e8:	13 e0       	ldi	r17, 0x03	; 3
     1ea:	a0 e0       	ldi	r26, 0x00	; 0
     1ec:	b1 e0       	ldi	r27, 0x01	; 1
     1ee:	e6 e5       	ldi	r30, 0x56	; 86
     1f0:	fb e3       	ldi	r31, 0x3B	; 59
     1f2:	02 c0       	rjmp	.+4      	; 0x1f8 <__do_copy_data+0x10>
     1f4:	05 90       	lpm	r0, Z+
     1f6:	0d 92       	st	X+, r0
     1f8:	ac 34       	cpi	r26, 0x4C	; 76
     1fa:	b1 07       	cpc	r27, r17
     1fc:	d9 f7       	brne	.-10     	; 0x1f4 <__do_copy_data+0xc>

000001fe <__do_clear_bss>:
     1fe:	24 e0       	ldi	r18, 0x04	; 4
     200:	ac e4       	ldi	r26, 0x4C	; 76
     202:	b3 e0       	ldi	r27, 0x03	; 3
     204:	01 c0       	rjmp	.+2      	; 0x208 <.do_clear_bss_start>

00000206 <.do_clear_bss_loop>:
     206:	1d 92       	st	X+, r1

00000208 <.do_clear_bss_start>:
     208:	a3 3d       	cpi	r26, 0xD3	; 211
     20a:	b2 07       	cpc	r27, r18
     20c:	e1 f7       	brne	.-8      	; 0x206 <.do_clear_bss_loop>

0000020e <__do_global_ctors>:
     20e:	10 e0       	ldi	r17, 0x00	; 0
     210:	cd ee       	ldi	r28, 0xED	; 237
     212:	d0 e0       	ldi	r29, 0x00	; 0
     214:	04 c0       	rjmp	.+8      	; 0x21e <__do_global_ctors+0x10>
     216:	21 97       	sbiw	r28, 0x01	; 1
     218:	fe 01       	movw	r30, r28
     21a:	0e 94 a8 17 	call	0x2f50	; 0x2f50 <__tablejump2__>
     21e:	cc 3e       	cpi	r28, 0xEC	; 236
     220:	d1 07       	cpc	r29, r17
     222:	c9 f7       	brne	.-14     	; 0x216 <__do_global_ctors+0x8>
     224:	0e 94 6a 11 	call	0x22d4	; 0x22d4 <main>
     228:	0c 94 9e 1d 	jmp	0x3b3c	; 0x3b3c <__do_global_dtors>

0000022c <__bad_interrupt>:
     22c:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000230 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE18impl_dequeue_eventEv>:
     230:	dc 01       	movw	r26, r24
     232:	5f 96       	adiw	r26, 0x1f	; 31
     234:	2c 91       	ld	r18, X
     236:	5f 97       	sbiw	r26, 0x1f	; 31
     238:	21 11       	cpse	r18, r1
     23a:	04 c0       	rjmp	.+8      	; 0x244 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE18impl_dequeue_eventEv+0x14>
     23c:	6c e0       	ldi	r22, 0x0C	; 12
     23e:	70 e0       	ldi	r23, 0x00	; 0
     240:	80 e0       	ldi	r24, 0x00	; 0
     242:	08 95       	ret
     244:	5e 96       	adiw	r26, 0x1e	; 30
     246:	9c 91       	ld	r25, X
     248:	5e 97       	sbiw	r26, 0x1e	; 30
     24a:	e9 2f       	mov	r30, r25
     24c:	f0 e0       	ldi	r31, 0x00	; 0
     24e:	31 96       	adiw	r30, 0x01	; 1
     250:	af 01       	movw	r20, r30
     252:	44 0f       	add	r20, r20
     254:	55 1f       	adc	r21, r21
     256:	e4 0f       	add	r30, r20
     258:	f5 1f       	adc	r31, r21
     25a:	ea 0f       	add	r30, r26
     25c:	fb 1f       	adc	r31, r27
     25e:	65 8d       	ldd	r22, Z+29	; 0x1d
     260:	76 8d       	ldd	r23, Z+30	; 0x1e
     262:	87 8d       	ldd	r24, Z+31	; 0x1f
     264:	21 50       	subi	r18, 0x01	; 1
     266:	5f 96       	adiw	r26, 0x1f	; 31
     268:	2c 93       	st	X, r18
     26a:	5f 97       	sbiw	r26, 0x1f	; 31
     26c:	9f 5f       	subi	r25, 0xFF	; 255
     26e:	97 70       	andi	r25, 0x07	; 7
     270:	5e 96       	adiw	r26, 0x1e	; 30
     272:	9c 93       	st	X, r25
     274:	08 95       	ret

00000276 <_ZNK13ControlSourceI17Buttonpad_PCF8754ILh63EEE16impl_queue_countEv>:
     276:	fc 01       	movw	r30, r24
     278:	87 8d       	ldd	r24, Z+31	; 0x1f
     27a:	08 95       	ret

0000027c <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18decrease_phase_majER5Track>:
     27c:	fc 01       	movw	r30, r24
     27e:	80 85       	ldd	r24, Z+8	; 0x08
     280:	81 11       	cpse	r24, r1
     282:	01 c0       	rjmp	.+2      	; 0x286 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18decrease_phase_majER5Track+0xa>
     284:	85 81       	ldd	r24, Z+5	; 0x05
     286:	81 50       	subi	r24, 0x01	; 1
     288:	80 87       	std	Z+8, r24	; 0x08
     28a:	81 e0       	ldi	r24, 0x01	; 1
     28c:	84 83       	std	Z+4, r24	; 0x04
     28e:	08 95       	ret

00000290 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_majER5Track>:
     290:	fc 01       	movw	r30, r24
     292:	20 85       	ldd	r18, Z+8	; 0x08
     294:	42 2f       	mov	r20, r18
     296:	50 e0       	ldi	r21, 0x00	; 0
     298:	85 81       	ldd	r24, Z+5	; 0x05
     29a:	90 e0       	ldi	r25, 0x00	; 0
     29c:	01 97       	sbiw	r24, 0x01	; 1
     29e:	48 17       	cp	r20, r24
     2a0:	59 07       	cpc	r21, r25
     2a2:	1c f4       	brge	.+6      	; 0x2aa <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_majER5Track+0x1a>
     2a4:	2f 5f       	subi	r18, 0xFF	; 255
     2a6:	20 87       	std	Z+8, r18	; 0x08
     2a8:	04 c0       	rjmp	.+8      	; 0x2b2 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_majER5Track+0x22>
     2aa:	48 17       	cp	r20, r24
     2ac:	59 07       	cpc	r21, r25
     2ae:	19 f4       	brne	.+6      	; 0x2b6 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_majER5Track+0x26>
     2b0:	10 86       	std	Z+8, r1	; 0x08
     2b2:	81 e0       	ldi	r24, 0x01	; 1
     2b4:	84 83       	std	Z+4, r24	; 0x04
     2b6:	08 95       	ret

000002b8 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18decrease_phase_minER5Track>:
     2b8:	fc 01       	movw	r30, r24
     2ba:	87 81       	ldd	r24, Z+7	; 0x07
     2bc:	81 11       	cpse	r24, r1
     2be:	01 c0       	rjmp	.+2      	; 0x2c2 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18decrease_phase_minER5Track+0xa>
     2c0:	86 81       	ldd	r24, Z+6	; 0x06
     2c2:	81 50       	subi	r24, 0x01	; 1
     2c4:	87 83       	std	Z+7, r24	; 0x07
     2c6:	81 e0       	ldi	r24, 0x01	; 1
     2c8:	84 83       	std	Z+4, r24	; 0x04
     2ca:	08 95       	ret

000002cc <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_minER5Track>:
     2cc:	fc 01       	movw	r30, r24
     2ce:	27 81       	ldd	r18, Z+7	; 0x07
     2d0:	42 2f       	mov	r20, r18
     2d2:	50 e0       	ldi	r21, 0x00	; 0
     2d4:	86 81       	ldd	r24, Z+6	; 0x06
     2d6:	90 e0       	ldi	r25, 0x00	; 0
     2d8:	01 97       	sbiw	r24, 0x01	; 1
     2da:	48 17       	cp	r20, r24
     2dc:	59 07       	cpc	r21, r25
     2de:	1c f4       	brge	.+6      	; 0x2e6 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_minER5Track+0x1a>
     2e0:	2f 5f       	subi	r18, 0xFF	; 255
     2e2:	27 83       	std	Z+7, r18	; 0x07
     2e4:	04 c0       	rjmp	.+8      	; 0x2ee <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_minER5Track+0x22>
     2e6:	48 17       	cp	r20, r24
     2e8:	59 07       	cpc	r21, r25
     2ea:	19 f4       	brne	.+6      	; 0x2f2 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE18increase_phase_minER5Track+0x26>
     2ec:	17 82       	std	Z+7, r1	; 0x07
     2ee:	81 e0       	ldi	r24, 0x01	; 1
     2f0:	84 83       	std	Z+4, r24	; 0x04
     2f2:	08 95       	ret

000002f4 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_majER5Track>:
     2f4:	fc 01       	movw	r30, r24
     2f6:	85 81       	ldd	r24, Z+5	; 0x05
     2f8:	82 30       	cpi	r24, 0x02	; 2
     2fa:	30 f0       	brcs	.+12     	; 0x308 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_majER5Track+0x14>
     2fc:	90 e0       	ldi	r25, 0x00	; 0
     2fe:	95 95       	asr	r25
     300:	87 95       	ror	r24
     302:	85 83       	std	Z+5, r24	; 0x05
     304:	81 e0       	ldi	r24, 0x01	; 1
     306:	84 83       	std	Z+4, r24	; 0x04
     308:	85 81       	ldd	r24, Z+5	; 0x05
     30a:	90 85       	ldd	r25, Z+8	; 0x08
     30c:	98 17       	cp	r25, r24
     30e:	18 f0       	brcs	.+6      	; 0x316 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_majER5Track+0x22>
     310:	10 86       	std	Z+8, r1	; 0x08
     312:	91 e0       	ldi	r25, 0x01	; 1
     314:	94 83       	std	Z+4, r25	; 0x04
     316:	96 81       	ldd	r25, Z+6	; 0x06
     318:	89 17       	cp	r24, r25
     31a:	18 f4       	brcc	.+6      	; 0x322 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_majER5Track+0x2e>
     31c:	86 83       	std	Z+6, r24	; 0x06
     31e:	81 e0       	ldi	r24, 0x01	; 1
     320:	84 83       	std	Z+4, r24	; 0x04
     322:	96 81       	ldd	r25, Z+6	; 0x06
     324:	87 81       	ldd	r24, Z+7	; 0x07
     326:	89 17       	cp	r24, r25
     328:	18 f0       	brcs	.+6      	; 0x330 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_majER5Track+0x3c>
     32a:	17 82       	std	Z+7, r1	; 0x07
     32c:	81 e0       	ldi	r24, 0x01	; 1
     32e:	84 83       	std	Z+4, r24	; 0x04
     330:	08 95       	ret

00000332 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16increase_mod_majER5Track>:
     332:	fc 01       	movw	r30, r24
     334:	95 81       	ldd	r25, Z+5	; 0x05
     336:	91 32       	cpi	r25, 0x21	; 33
     338:	20 f4       	brcc	.+8      	; 0x342 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16increase_mod_majER5Track+0x10>
     33a:	99 0f       	add	r25, r25
     33c:	95 83       	std	Z+5, r25	; 0x05
     33e:	81 e0       	ldi	r24, 0x01	; 1
     340:	84 83       	std	Z+4, r24	; 0x04
     342:	08 95       	ret

00000344 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_minER5Track>:
     344:	fc 01       	movw	r30, r24
     346:	86 81       	ldd	r24, Z+6	; 0x06
     348:	82 30       	cpi	r24, 0x02	; 2
     34a:	20 f0       	brcs	.+8      	; 0x354 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_minER5Track+0x10>
     34c:	81 50       	subi	r24, 0x01	; 1
     34e:	86 83       	std	Z+6, r24	; 0x06
     350:	81 e0       	ldi	r24, 0x01	; 1
     352:	84 83       	std	Z+4, r24	; 0x04
     354:	96 81       	ldd	r25, Z+6	; 0x06
     356:	87 81       	ldd	r24, Z+7	; 0x07
     358:	89 17       	cp	r24, r25
     35a:	18 f0       	brcs	.+6      	; 0x362 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16decrease_mod_minER5Track+0x1e>
     35c:	17 82       	std	Z+7, r1	; 0x07
     35e:	81 e0       	ldi	r24, 0x01	; 1
     360:	84 83       	std	Z+4, r24	; 0x04
     362:	08 95       	ret

00000364 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16increase_mod_minER5Track>:
     364:	fc 01       	movw	r30, r24
     366:	86 81       	ldd	r24, Z+6	; 0x06
     368:	95 81       	ldd	r25, Z+5	; 0x05
     36a:	89 17       	cp	r24, r25
     36c:	20 f4       	brcc	.+8      	; 0x376 <_ZN19ProcessTrackControlI13ControlSourceI17Buttonpad_PCF8754ILh63EEEE16increase_mod_minER5Track+0x12>
     36e:	8f 5f       	subi	r24, 0xFF	; 255
     370:	86 83       	std	Z+6, r24	; 0x06
     372:	81 e0       	ldi	r24, 0x01	; 1
     374:	84 83       	std	Z+4, r24	; 0x04
     376:	08 95       	ret

00000378 <_ZThn4_N19ButtonSouce18impl_dequeue_eventEv>:
     378:	fc 01       	movw	r30, r24
     37a:	34 97       	sbiw	r30, 0x04	; 4
     37c:	26 81       	ldd	r18, Z+6	; 0x06
     37e:	37 81       	ldd	r19, Z+7	; 0x07
     380:	8c e0       	ldi	r24, 0x0C	; 12
     382:	90 e0       	ldi	r25, 0x00	; 0
     384:	97 83       	std	Z+7, r25	; 0x07
     386:	86 83       	std	Z+6, r24	; 0x06
     388:	60 e0       	ldi	r22, 0x00	; 0
     38a:	70 e0       	ldi	r23, 0x00	; 0
     38c:	80 e0       	ldi	r24, 0x00	; 0
     38e:	b9 01       	movw	r22, r18
     390:	08 95       	ret

00000392 <_ZN19ButtonSouce18impl_dequeue_eventEv.lto_priv.155>:
     392:	fc 01       	movw	r30, r24
     394:	26 81       	ldd	r18, Z+6	; 0x06
     396:	37 81       	ldd	r19, Z+7	; 0x07
     398:	4c e0       	ldi	r20, 0x0C	; 12
     39a:	50 e0       	ldi	r21, 0x00	; 0
     39c:	57 83       	std	Z+7, r21	; 0x07
     39e:	46 83       	std	Z+6, r20	; 0x06
     3a0:	60 e0       	ldi	r22, 0x00	; 0
     3a2:	70 e0       	ldi	r23, 0x00	; 0
     3a4:	80 e0       	ldi	r24, 0x00	; 0
     3a6:	b9 01       	movw	r22, r18
     3a8:	08 95       	ret

000003aa <_ZThn4_NK19ButtonSouce16impl_queue_countEv>:
     3aa:	21 e0       	ldi	r18, 0x01	; 1
     3ac:	fc 01       	movw	r30, r24
     3ae:	82 81       	ldd	r24, Z+2	; 0x02
     3b0:	93 81       	ldd	r25, Z+3	; 0x03
     3b2:	0c 97       	sbiw	r24, 0x0c	; 12
     3b4:	09 f4       	brne	.+2      	; 0x3b8 <_ZThn4_NK19ButtonSouce16impl_queue_countEv+0xe>
     3b6:	20 e0       	ldi	r18, 0x00	; 0
     3b8:	82 2f       	mov	r24, r18
     3ba:	08 95       	ret

000003bc <_ZNK19ButtonSouce16impl_queue_countEv.lto_priv.154>:
     3bc:	21 e0       	ldi	r18, 0x01	; 1
     3be:	fc 01       	movw	r30, r24
     3c0:	86 81       	ldd	r24, Z+6	; 0x06
     3c2:	97 81       	ldd	r25, Z+7	; 0x07
     3c4:	0c 97       	sbiw	r24, 0x0c	; 12
     3c6:	09 f4       	brne	.+2      	; 0x3ca <_ZNK19ButtonSouce16impl_queue_countEv.lto_priv.154+0xe>
     3c8:	20 e0       	ldi	r18, 0x00	; 0
     3ca:	82 2f       	mov	r24, r18
     3cc:	08 95       	ret

000003ce <_ZN19ButtonSouce9impl_pollEv.lto_priv.153>:
     3ce:	fc 01       	movw	r30, r24
     3d0:	92 81       	ldd	r25, Z+2	; 0x02
     3d2:	9e 30       	cpi	r25, 0x0E	; 14
     3d4:	08 f0       	brcs	.+2      	; 0x3d8 <_ZN19ButtonSouce9impl_pollEv.lto_priv.153+0xa>
     3d6:	9e 50       	subi	r25, 0x0E	; 14
     3d8:	97 70       	andi	r25, 0x07	; 7
     3da:	90 64       	ori	r25, 0x40	; 64
     3dc:	90 93 7c 00 	sts	0x007C, r25	; 0x80007c <__TEXT_REGION_LENGTH__+0x7e007c>
     3e0:	80 91 7a 00 	lds	r24, 0x007A	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
     3e4:	80 64       	ori	r24, 0x40	; 64
     3e6:	80 93 7a 00 	sts	0x007A, r24	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
     3ea:	80 91 7a 00 	lds	r24, 0x007A	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
     3ee:	86 fd       	sbrc	r24, 6
     3f0:	fc cf       	rjmp	.-8      	; 0x3ea <_ZN19ButtonSouce9impl_pollEv.lto_priv.153+0x1c>
     3f2:	20 91 78 00 	lds	r18, 0x0078	; 0x800078 <__TEXT_REGION_LENGTH__+0x7e0078>
     3f6:	80 91 79 00 	lds	r24, 0x0079	; 0x800079 <__TEXT_REGION_LENGTH__+0x7e0079>
     3fa:	30 e0       	ldi	r19, 0x00	; 0
     3fc:	38 2b       	or	r19, r24
     3fe:	83 81       	ldd	r24, Z+3	; 0x03
     400:	88 23       	and	r24, r24
     402:	49 f0       	breq	.+18     	; 0x416 <__LOCK_REGION_LENGTH__+0x16>
     404:	20 34       	cpi	r18, 0x40	; 64
     406:	31 05       	cpc	r19, r1
     408:	58 f4       	brcc	.+22     	; 0x420 <__LOCK_REGION_LENGTH__+0x20>
     40a:	13 82       	std	Z+3, r1	; 0x03
     40c:	8b e0       	ldi	r24, 0x0B	; 11
     40e:	90 e0       	ldi	r25, 0x00	; 0
     410:	97 83       	std	Z+7, r25	; 0x07
     412:	86 83       	std	Z+6, r24	; 0x06
     414:	08 95       	ret
     416:	21 3c       	cpi	r18, 0xC1	; 193
     418:	31 05       	cpc	r19, r1
     41a:	10 f0       	brcs	.+4      	; 0x420 <__LOCK_REGION_LENGTH__+0x20>
     41c:	81 e0       	ldi	r24, 0x01	; 1
     41e:	83 83       	std	Z+3, r24	; 0x03
     420:	08 95       	ret

00000422 <_ZThn4_N19ButtonSouce9impl_pollEv>:
     422:	04 97       	sbiw	r24, 0x04	; 4
     424:	0c 94 e7 01 	jmp	0x3ce	; 0x3ce <_ZN19ButtonSouce9impl_pollEv.lto_priv.153>

00000428 <_ZThn4_N19ButtonSouceD1Ev>:
     428:	08 95       	ret

0000042a <_ZN13EncoderSource18impl_dequeue_eventEv.lto_priv.161>:
     42a:	fc 01       	movw	r30, r24
     42c:	64 81       	ldd	r22, Z+4	; 0x04
     42e:	75 81       	ldd	r23, Z+5	; 0x05
     430:	86 81       	ldd	r24, Z+6	; 0x06
     432:	2c e0       	ldi	r18, 0x0C	; 12
     434:	30 e0       	ldi	r19, 0x00	; 0
     436:	35 83       	std	Z+5, r19	; 0x05
     438:	24 83       	std	Z+4, r18	; 0x04
     43a:	16 82       	std	Z+6, r1	; 0x06
     43c:	08 95       	ret

0000043e <_ZThn2_N13EncoderSource18impl_dequeue_eventEv>:
     43e:	02 97       	sbiw	r24, 0x02	; 2
     440:	0c 94 15 02 	jmp	0x42a	; 0x42a <_ZN13EncoderSource18impl_dequeue_eventEv.lto_priv.161>

00000444 <_ZThn2_NK13EncoderSource16impl_queue_countEv>:
     444:	21 e0       	ldi	r18, 0x01	; 1
     446:	fc 01       	movw	r30, r24
     448:	82 81       	ldd	r24, Z+2	; 0x02
     44a:	93 81       	ldd	r25, Z+3	; 0x03
     44c:	0c 97       	sbiw	r24, 0x0c	; 12
     44e:	09 f4       	brne	.+2      	; 0x452 <_ZThn2_NK13EncoderSource16impl_queue_countEv+0xe>
     450:	20 e0       	ldi	r18, 0x00	; 0
     452:	82 2f       	mov	r24, r18
     454:	08 95       	ret

00000456 <_ZNK13EncoderSource16impl_queue_countEv.lto_priv.160>:
     456:	21 e0       	ldi	r18, 0x01	; 1
     458:	fc 01       	movw	r30, r24
     45a:	84 81       	ldd	r24, Z+4	; 0x04
     45c:	95 81       	ldd	r25, Z+5	; 0x05
     45e:	0c 97       	sbiw	r24, 0x0c	; 12
     460:	09 f4       	brne	.+2      	; 0x464 <_ZNK13EncoderSource16impl_queue_countEv.lto_priv.160+0xe>
     462:	20 e0       	ldi	r18, 0x00	; 0
     464:	82 2f       	mov	r24, r18
     466:	08 95       	ret

00000468 <_ZN13EncoderSource9impl_pollEv.lto_priv.159>:
     468:	fc 01       	movw	r30, r24
     46a:	a0 91 35 04 	lds	r26, 0x0435	; 0x800435 <_ZN7Encoder8_encoderE>
     46e:	b0 91 36 04 	lds	r27, 0x0436	; 0x800436 <_ZN7Encoder8_encoderE+0x1>
     472:	15 96       	adiw	r26, 0x05	; 5
     474:	2d 91       	ld	r18, X+
     476:	3c 91       	ld	r19, X
     478:	16 97       	sbiw	r26, 0x06	; 6
     47a:	36 95       	lsr	r19
     47c:	27 95       	ror	r18
     47e:	36 95       	lsr	r19
     480:	27 95       	ror	r18
     482:	28 30       	cpi	r18, 0x08	; 8
     484:	38 f4       	brcc	.+14     	; 0x494 <_ZN13EncoderSource9impl_pollEv.lto_priv.159+0x2c>
     486:	80 e2       	ldi	r24, 0x20	; 32
     488:	90 e0       	ldi	r25, 0x00	; 0
     48a:	16 96       	adiw	r26, 0x06	; 6
     48c:	9c 93       	st	X, r25
     48e:	8e 93       	st	-X, r24
     490:	15 97       	sbiw	r26, 0x05	; 5
     492:	28 e0       	ldi	r18, 0x08	; 8
     494:	87 81       	ldd	r24, Z+7	; 0x07
     496:	82 17       	cp	r24, r18
     498:	31 f0       	breq	.+12     	; 0x4a6 <_ZN13EncoderSource9impl_pollEv.lto_priv.159+0x3e>
     49a:	8a e0       	ldi	r24, 0x0A	; 10
     49c:	90 e0       	ldi	r25, 0x00	; 0
     49e:	95 83       	std	Z+5, r25	; 0x05
     4a0:	84 83       	std	Z+4, r24	; 0x04
     4a2:	26 83       	std	Z+6, r18	; 0x06
     4a4:	27 83       	std	Z+7, r18	; 0x07
     4a6:	08 95       	ret

000004a8 <_ZThn2_N13EncoderSource9impl_pollEv>:
     4a8:	02 97       	sbiw	r24, 0x02	; 2
     4aa:	0c 94 34 02 	jmp	0x468	; 0x468 <_ZN13EncoderSource9impl_pollEv.lto_priv.159>

000004ae <_ZThn2_N13EncoderSourceD1Ev>:
     4ae:	08 95       	ret

000004b0 <_ZN2UiI6UiDataI15TrackCollectionILj3E5TrackEEED0Ev>:
     4b0:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

000004b4 <_ZN6UiDataI15TrackCollectionILj3E5TrackEED0Ev>:
     4b4:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

000004b8 <_ZN17Buttonpad_PCF8754ILh63EED0Ev>:
     4b8:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

000004bc <_ZN19ButtonSouceD0Ev.lto_priv.152>:
     4bc:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

000004c0 <_ZThn4_N19ButtonSouceD0Ev.lto_priv.156>:
     4c0:	04 97       	sbiw	r24, 0x04	; 4
     4c2:	0c 94 5e 02 	jmp	0x4bc	; 0x4bc <_ZN19ButtonSouceD0Ev.lto_priv.152>

000004c6 <_ZN13EncoderSourceD0Ev.lto_priv.158>:
     4c6:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

000004ca <_ZThn2_N13EncoderSourceD0Ev.lto_priv.162>:
     4ca:	02 97       	sbiw	r24, 0x02	; 2
     4cc:	0c 94 63 02 	jmp	0x4c6	; 0x4c6 <_ZN13EncoderSourceD0Ev.lto_priv.158>

000004d0 <_ZN13EncoderSource5setupEv>:
     4d0:	cf 93       	push	r28
     4d2:	df 93       	push	r29
     4d4:	ec 01       	movw	r28, r24
     4d6:	0e 94 ec 05 	call	0xbd8	; 0xbd8 <_ZN7Encoder5setupEv>
     4da:	e0 91 35 04 	lds	r30, 0x0435	; 0x800435 <_ZN7Encoder8_encoderE>
     4de:	f0 91 36 04 	lds	r31, 0x0436	; 0x800436 <_ZN7Encoder8_encoderE+0x1>
     4e2:	8f 81       	ldd	r24, Y+7	; 0x07
     4e4:	24 e0       	ldi	r18, 0x04	; 4
     4e6:	82 9f       	mul	r24, r18
     4e8:	c0 01       	movw	r24, r0
     4ea:	11 24       	eor	r1, r1
     4ec:	96 83       	std	Z+6, r25	; 0x06
     4ee:	85 83       	std	Z+5, r24	; 0x05
     4f0:	df 91       	pop	r29
     4f2:	cf 91       	pop	r28
     4f4:	08 95       	ret

000004f6 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE5setupEv>:
     4f6:	cf 93       	push	r28
     4f8:	df 93       	push	r29
     4fa:	ec 01       	movw	r28, r24
     4fc:	45 96       	adiw	r24, 0x15	; 21
     4fe:	0e 94 68 02 	call	0x4d0	; 0x4d0 <_ZN13EncoderSource5setupEv>
     502:	62 e0       	ldi	r22, 0x02	; 2
     504:	8f 85       	ldd	r24, Y+15	; 0x0f
     506:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
     50a:	ce 01       	movw	r24, r28
     50c:	02 96       	adiw	r24, 0x02	; 2
     50e:	df 91       	pop	r29
     510:	cf 91       	pop	r28
     512:	0c 94 44 06 	jmp	0xc88	; 0xc88 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv>

00000516 <_ZN2UiI6UiDataI15TrackCollectionILj3E5TrackEEED1Ev.lto_priv.135>:
     516:	08 95       	ret

00000518 <_ZN6UiDataI15TrackCollectionILj3E5TrackEED1Ev.lto_priv.140>:
     518:	08 95       	ret

0000051a <_ZN17Buttonpad_PCF8754ILh63EED1Ev.lto_priv.150>:
     51a:	08 95       	ret

0000051c <_ZN4lamb20PositionalFixedArrayILj3E5TrackED1Ev.lto_priv.134>:
     51c:	0f 93       	push	r16
     51e:	1f 93       	push	r17
     520:	cf 93       	push	r28
     522:	df 93       	push	r29
     524:	23 eb       	ldi	r18, 0xB3	; 179
     526:	32 e0       	ldi	r19, 0x02	; 2
     528:	fc 01       	movw	r30, r24
     52a:	21 93       	st	Z+, r18
     52c:	31 93       	st	Z+, r19
     52e:	8f 01       	movw	r16, r30
     530:	ef 2b       	or	r30, r31
     532:	71 f0       	breq	.+28     	; 0x550 <_ZN4lamb20PositionalFixedArrayILj3E5TrackED1Ev.lto_priv.134+0x34>
     534:	ec 01       	movw	r28, r24
     536:	6d 96       	adiw	r28, 0x1d	; 29
     538:	c0 17       	cp	r28, r16
     53a:	d1 07       	cpc	r29, r17
     53c:	49 f0       	breq	.+18     	; 0x550 <_ZN4lamb20PositionalFixedArrayILj3E5TrackED1Ev.lto_priv.134+0x34>
     53e:	29 97       	sbiw	r28, 0x09	; 9
     540:	e8 81       	ld	r30, Y
     542:	f9 81       	ldd	r31, Y+1	; 0x01
     544:	02 80       	ldd	r0, Z+2	; 0x02
     546:	f3 81       	ldd	r31, Z+3	; 0x03
     548:	e0 2d       	mov	r30, r0
     54a:	ce 01       	movw	r24, r28
     54c:	09 95       	icall
     54e:	f4 cf       	rjmp	.-24     	; 0x538 <_ZN4lamb20PositionalFixedArrayILj3E5TrackED1Ev.lto_priv.134+0x1c>
     550:	df 91       	pop	r29
     552:	cf 91       	pop	r28
     554:	1f 91       	pop	r17
     556:	0f 91       	pop	r16
     558:	08 95       	ret

0000055a <_ZN4lamb20PositionalFixedArrayILj3E5TrackED0Ev>:
     55a:	cf 93       	push	r28
     55c:	df 93       	push	r29
     55e:	ec 01       	movw	r28, r24
     560:	0e 94 8e 02 	call	0x51c	; 0x51c <_ZN4lamb20PositionalFixedArrayILj3E5TrackED1Ev.lto_priv.134>
     564:	ce 01       	movw	r24, r28
     566:	df 91       	pop	r29
     568:	cf 91       	pop	r28
     56a:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000056e <_ZN15TrackCollectionILj3E5TrackED1Ev.lto_priv.133>:
     56e:	2b eb       	ldi	r18, 0xBB	; 187
     570:	32 e0       	ldi	r19, 0x02	; 2
     572:	fc 01       	movw	r30, r24
     574:	31 83       	std	Z+1, r19	; 0x01
     576:	20 83       	st	Z, r18
     578:	0c 94 8e 02 	jmp	0x51c	; 0x51c <_ZN4lamb20PositionalFixedArrayILj3E5TrackED1Ev.lto_priv.134>

0000057c <_ZN15TrackCollectionILj3E5TrackED0Ev>:
     57c:	cf 93       	push	r28
     57e:	df 93       	push	r29
     580:	ec 01       	movw	r28, r24
     582:	0e 94 b7 02 	call	0x56e	; 0x56e <_ZN15TrackCollectionILj3E5TrackED1Ev.lto_priv.133>
     586:	ce 01       	movw	r24, r28
     588:	df 91       	pop	r29
     58a:	cf 91       	pop	r28
     58c:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000590 <_ZN15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEED1Ev.lto_priv.144>:
     590:	08 95       	ret

00000592 <_ZThn7_N15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEED1Ev.lto_priv.149>:
     592:	08 95       	ret

00000594 <_ZN15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEED0Ev.lto_priv.145>:
     594:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000598 <_ZThn7_N15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEED0Ev>:
     598:	07 97       	sbiw	r24, 0x07	; 7
     59a:	0c 94 ca 02 	jmp	0x594	; 0x594 <_ZN15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEED0Ev.lto_priv.145>

0000059e <_ZN17EventSourceI5EventE13dequeue_eventEv>:
     59e:	dc 01       	movw	r26, r24
     5a0:	ed 91       	ld	r30, X+
     5a2:	fc 91       	ld	r31, X
     5a4:	00 84       	ldd	r0, Z+8	; 0x08
     5a6:	f1 85       	ldd	r31, Z+9	; 0x09
     5a8:	e0 2d       	mov	r30, r0
     5aa:	09 95       	icall
     5ac:	08 95       	ret

000005ae <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv>:
     5ae:	0f 93       	push	r16
     5b0:	1f 93       	push	r17
     5b2:	cf 93       	push	r28
     5b4:	df 93       	push	r29
     5b6:	ec 01       	movw	r28, r24
     5b8:	8c 01       	movw	r16, r24
     5ba:	09 5e       	subi	r16, 0xE9	; 233
     5bc:	1f 4f       	sbci	r17, 0xFF	; 255
     5be:	c8 01       	movw	r24, r16
     5c0:	0e 94 54 02 	call	0x4a8	; 0x4a8 <_ZThn2_N13EncoderSource9impl_pollEv>
     5c4:	c8 01       	movw	r24, r16
     5c6:	0e 94 cf 02 	call	0x59e	; 0x59e <_ZN17EventSourceI5EventE13dequeue_eventEv>
     5ca:	a8 2f       	mov	r26, r24
     5cc:	cb 01       	movw	r24, r22
     5ce:	8c 30       	cpi	r24, 0x0C	; 12
     5d0:	91 05       	cpc	r25, r1
     5d2:	b9 f0       	breq	.+46     	; 0x602 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv+0x54>
     5d4:	5a 2f       	mov	r21, r26
     5d6:	2d 8d       	ldd	r18, Y+29	; 0x1d
     5d8:	48 2f       	mov	r20, r24
     5da:	39 2f       	mov	r19, r25
     5dc:	e2 2f       	mov	r30, r18
     5de:	f0 e0       	ldi	r31, 0x00	; 0
     5e0:	31 96       	adiw	r30, 0x01	; 1
     5e2:	cf 01       	movw	r24, r30
     5e4:	88 0f       	add	r24, r24
     5e6:	99 1f       	adc	r25, r25
     5e8:	e8 0f       	add	r30, r24
     5ea:	f9 1f       	adc	r31, r25
     5ec:	ec 0f       	add	r30, r28
     5ee:	fd 1f       	adc	r31, r29
     5f0:	45 8f       	std	Z+29, r20	; 0x1d
     5f2:	36 8f       	std	Z+30, r19	; 0x1e
     5f4:	57 8f       	std	Z+31, r21	; 0x1f
     5f6:	8f 8d       	ldd	r24, Y+31	; 0x1f
     5f8:	8f 5f       	subi	r24, 0xFF	; 255
     5fa:	8f 8f       	std	Y+31, r24	; 0x1f
     5fc:	2f 5f       	subi	r18, 0xFF	; 255
     5fe:	27 70       	andi	r18, 0x07	; 7
     600:	2d 8f       	std	Y+29, r18	; 0x1d
     602:	8e 01       	movw	r16, r28
     604:	0f 5e       	subi	r16, 0xEF	; 239
     606:	1f 4f       	sbci	r17, 0xFF	; 255
     608:	c8 01       	movw	r24, r16
     60a:	0e 94 11 02 	call	0x422	; 0x422 <_ZThn4_N19ButtonSouce9impl_pollEv>
     60e:	c8 01       	movw	r24, r16
     610:	0e 94 cf 02 	call	0x59e	; 0x59e <_ZN17EventSourceI5EventE13dequeue_eventEv>
     614:	a8 2f       	mov	r26, r24
     616:	cb 01       	movw	r24, r22
     618:	8c 30       	cpi	r24, 0x0C	; 12
     61a:	91 05       	cpc	r25, r1
     61c:	b1 f0       	breq	.+44     	; 0x64a <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv+0x9c>
     61e:	2d 8d       	ldd	r18, Y+29	; 0x1d
     620:	48 2f       	mov	r20, r24
     622:	39 2f       	mov	r19, r25
     624:	e2 2f       	mov	r30, r18
     626:	f0 e0       	ldi	r31, 0x00	; 0
     628:	31 96       	adiw	r30, 0x01	; 1
     62a:	cf 01       	movw	r24, r30
     62c:	88 0f       	add	r24, r24
     62e:	99 1f       	adc	r25, r25
     630:	e8 0f       	add	r30, r24
     632:	f9 1f       	adc	r31, r25
     634:	ec 0f       	add	r30, r28
     636:	fd 1f       	adc	r31, r29
     638:	45 8f       	std	Z+29, r20	; 0x1d
     63a:	36 8f       	std	Z+30, r19	; 0x1e
     63c:	a7 8f       	std	Z+31, r26	; 0x1f
     63e:	8f 8d       	ldd	r24, Y+31	; 0x1f
     640:	8f 5f       	subi	r24, 0xFF	; 255
     642:	8f 8f       	std	Y+31, r24	; 0x1f
     644:	2f 5f       	subi	r18, 0xFF	; 255
     646:	27 70       	andi	r18, 0x07	; 7
     648:	2d 8f       	std	Y+29, r18	; 0x1d
     64a:	8e 01       	movw	r16, r28
     64c:	07 5f       	subi	r16, 0xF7	; 247
     64e:	1f 4f       	sbci	r17, 0xFF	; 255
     650:	c8 01       	movw	r24, r16
     652:	0e 94 87 04 	call	0x90e	; 0x90e <_ZThn7_N15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv>
     656:	c8 01       	movw	r24, r16
     658:	0e 94 cf 02 	call	0x59e	; 0x59e <_ZN17EventSourceI5EventE13dequeue_eventEv>
     65c:	a8 2f       	mov	r26, r24
     65e:	cb 01       	movw	r24, r22
     660:	8c 30       	cpi	r24, 0x0C	; 12
     662:	91 05       	cpc	r25, r1
     664:	b1 f0       	breq	.+44     	; 0x692 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv+0xe4>
     666:	2d 8d       	ldd	r18, Y+29	; 0x1d
     668:	48 2f       	mov	r20, r24
     66a:	39 2f       	mov	r19, r25
     66c:	e2 2f       	mov	r30, r18
     66e:	f0 e0       	ldi	r31, 0x00	; 0
     670:	31 96       	adiw	r30, 0x01	; 1
     672:	cf 01       	movw	r24, r30
     674:	88 0f       	add	r24, r24
     676:	99 1f       	adc	r25, r25
     678:	e8 0f       	add	r30, r24
     67a:	f9 1f       	adc	r31, r25
     67c:	ec 0f       	add	r30, r28
     67e:	fd 1f       	adc	r31, r29
     680:	45 8f       	std	Z+29, r20	; 0x1d
     682:	36 8f       	std	Z+30, r19	; 0x1e
     684:	a7 8f       	std	Z+31, r26	; 0x1f
     686:	8f 8d       	ldd	r24, Y+31	; 0x1f
     688:	8f 5f       	subi	r24, 0xFF	; 255
     68a:	8f 8f       	std	Y+31, r24	; 0x1f
     68c:	2f 5f       	subi	r18, 0xFF	; 255
     68e:	27 70       	andi	r18, 0x07	; 7
     690:	2d 8f       	std	Y+29, r18	; 0x1d
     692:	df 91       	pop	r29
     694:	cf 91       	pop	r28
     696:	1f 91       	pop	r17
     698:	0f 91       	pop	r16
     69a:	08 95       	ret

0000069c <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv>:
     69c:	fc 01       	movw	r30, r24
     69e:	80 89       	ldd	r24, Z+16	; 0x10
     6a0:	97 81       	ldd	r25, Z+7	; 0x07
     6a2:	98 17       	cp	r25, r24
     6a4:	08 f4       	brcc	.+2      	; 0x6a8 <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv+0xc>
     6a6:	98 2f       	mov	r25, r24
     6a8:	81 8d       	ldd	r24, Z+25	; 0x19
     6aa:	89 17       	cp	r24, r25
     6ac:	08 f4       	brcc	.+2      	; 0x6b0 <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv+0x14>
     6ae:	89 2f       	mov	r24, r25
     6b0:	08 95       	ret

000006b2 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEED1Ev.lto_priv.143>:
     6b2:	08 95       	ret

000006b4 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEED0Ev>:
     6b4:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

000006b8 <_ZN19ButtonSouceD1Ev.lto_priv.151>:
     6b8:	08 95       	ret

000006ba <_ZN13EncoderSourceD1Ev.lto_priv.157>:
     6ba:	08 95       	ret

000006bc <_ZN11Application16flag_main_screenEv>:
     6bc:	e0 91 5b 04 	lds	r30, 0x045B	; 0x80045b <_ZN11Application2uiE+0xa>
     6c0:	f0 91 5c 04 	lds	r31, 0x045C	; 0x80045c <_ZN11Application2uiE+0xb>
     6c4:	81 e0       	ldi	r24, 0x01	; 1
     6c6:	84 83       	std	Z+4, r24	; 0x04
     6c8:	08 95       	ret

000006ca <_ZN11Application14update_ui_dataEv>:
     6ca:	1f 93       	push	r17
     6cc:	cf 93       	push	r28
     6ce:	df 93       	push	r29
     6d0:	c1 e6       	ldi	r28, 0x61	; 97
     6d2:	d4 e0       	ldi	r29, 0x04	; 4
     6d4:	1c 81       	ldd	r17, Y+4	; 0x04
     6d6:	83 e7       	ldi	r24, 0x73	; 115
     6d8:	94 e0       	ldi	r25, 0x04	; 4
     6da:	0e 94 4e 03 	call	0x69c	; 0x69c <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv>
     6de:	68 2f       	mov	r22, r24
     6e0:	e9 e3       	ldi	r30, 0x39	; 57
     6e2:	f4 e0       	ldi	r31, 0x04	; 4
     6e4:	81 2f       	mov	r24, r17
     6e6:	86 95       	lsr	r24
     6e8:	0e 94 52 17 	call	0x2ea4	; 0x2ea4 <__udivmodqi4>
     6ec:	92 95       	swap	r25
     6ee:	9f 70       	andi	r25, 0x0F	; 15
     6f0:	94 83       	std	Z+4, r25	; 0x04
     6f2:	8a 81       	ldd	r24, Y+2	; 0x02
     6f4:	85 83       	std	Z+5, r24	; 0x05
     6f6:	8d 81       	ldd	r24, Y+5	; 0x05
     6f8:	9e 81       	ldd	r25, Y+6	; 0x06
     6fa:	af 81       	ldd	r26, Y+7	; 0x07
     6fc:	b8 85       	ldd	r27, Y+8	; 0x08
     6fe:	86 83       	std	Z+6, r24	; 0x06
     700:	97 83       	std	Z+7, r25	; 0x07
     702:	a0 87       	std	Z+8, r26	; 0x08
     704:	b1 87       	std	Z+9, r27	; 0x09
     706:	8b 81       	ldd	r24, Y+3	; 0x03
     708:	82 87       	std	Z+10, r24	; 0x0a
     70a:	13 87       	std	Z+11, r17	; 0x0b
     70c:	df 91       	pop	r29
     70e:	cf 91       	pop	r28
     710:	1f 91       	pop	r17
     712:	08 95       	ret

00000714 <_ZN4lamb8Encoders6States4UIntILc8ELb0EE7do_downEv>:
     714:	fc 01       	movw	r30, r24
     716:	85 81       	ldd	r24, Z+5	; 0x05
     718:	96 81       	ldd	r25, Z+6	; 0x06
     71a:	96 95       	lsr	r25
     71c:	87 95       	ror	r24
     71e:	96 95       	lsr	r25
     720:	87 95       	ror	r24
     722:	25 81       	ldd	r18, Z+5	; 0x05
     724:	36 81       	ldd	r19, Z+6	; 0x06
     726:	21 50       	subi	r18, 0x01	; 1
     728:	31 09       	sbc	r19, r1
     72a:	37 fd       	sbrc	r19, 7
     72c:	07 c0       	rjmp	.+14     	; 0x73c <_ZN4lamb8Encoders6States4UIntILc8ELb0EE7do_downEv+0x28>
     72e:	21 15       	cp	r18, r1
     730:	44 e0       	ldi	r20, 0x04	; 4
     732:	34 07       	cpc	r19, r20
     734:	2c f0       	brlt	.+10     	; 0x740 <_ZN4lamb8Encoders6States4UIntILc8ELb0EE7do_downEv+0x2c>
     736:	2f ef       	ldi	r18, 0xFF	; 255
     738:	33 e0       	ldi	r19, 0x03	; 3
     73a:	02 c0       	rjmp	.+4      	; 0x740 <_ZN4lamb8Encoders6States4UIntILc8ELb0EE7do_downEv+0x2c>
     73c:	20 e0       	ldi	r18, 0x00	; 0
     73e:	30 e0       	ldi	r19, 0x00	; 0
     740:	36 83       	std	Z+6, r19	; 0x06
     742:	25 83       	std	Z+5, r18	; 0x05
     744:	25 81       	ldd	r18, Z+5	; 0x05
     746:	36 81       	ldd	r19, Z+6	; 0x06
     748:	36 95       	lsr	r19
     74a:	27 95       	ror	r18
     74c:	36 95       	lsr	r19
     74e:	27 95       	ror	r18
     750:	41 e0       	ldi	r20, 0x01	; 1
     752:	28 17       	cp	r18, r24
     754:	39 07       	cpc	r19, r25
     756:	09 f4       	brne	.+2      	; 0x75a <_ZN4lamb8Encoders6States4UIntILc8ELb0EE7do_downEv+0x46>
     758:	40 e0       	ldi	r20, 0x00	; 0
     75a:	44 83       	std	Z+4, r20	; 0x04
     75c:	08 95       	ret

0000075e <_ZN4lamb8Encoders6States4UIntILc8ELb0EE5do_upEv>:
     75e:	fc 01       	movw	r30, r24
     760:	85 81       	ldd	r24, Z+5	; 0x05
     762:	96 81       	ldd	r25, Z+6	; 0x06
     764:	96 95       	lsr	r25
     766:	87 95       	ror	r24
     768:	96 95       	lsr	r25
     76a:	87 95       	ror	r24
     76c:	25 81       	ldd	r18, Z+5	; 0x05
     76e:	36 81       	ldd	r19, Z+6	; 0x06
     770:	2f 5f       	subi	r18, 0xFF	; 255
     772:	3f 4f       	sbci	r19, 0xFF	; 255
     774:	37 fd       	sbrc	r19, 7
     776:	07 c0       	rjmp	.+14     	; 0x786 <_ZN4lamb8Encoders6States4UIntILc8ELb0EE5do_upEv+0x28>
     778:	21 15       	cp	r18, r1
     77a:	44 e0       	ldi	r20, 0x04	; 4
     77c:	34 07       	cpc	r19, r20
     77e:	2c f0       	brlt	.+10     	; 0x78a <_ZN4lamb8Encoders6States4UIntILc8ELb0EE5do_upEv+0x2c>
     780:	2f ef       	ldi	r18, 0xFF	; 255
     782:	33 e0       	ldi	r19, 0x03	; 3
     784:	02 c0       	rjmp	.+4      	; 0x78a <_ZN4lamb8Encoders6States4UIntILc8ELb0EE5do_upEv+0x2c>
     786:	20 e0       	ldi	r18, 0x00	; 0
     788:	30 e0       	ldi	r19, 0x00	; 0
     78a:	36 83       	std	Z+6, r19	; 0x06
     78c:	25 83       	std	Z+5, r18	; 0x05
     78e:	25 81       	ldd	r18, Z+5	; 0x05
     790:	36 81       	ldd	r19, Z+6	; 0x06
     792:	36 95       	lsr	r19
     794:	27 95       	ror	r18
     796:	36 95       	lsr	r19
     798:	27 95       	ror	r18
     79a:	41 e0       	ldi	r20, 0x01	; 1
     79c:	28 17       	cp	r18, r24
     79e:	39 07       	cpc	r19, r25
     7a0:	09 f4       	brne	.+2      	; 0x7a4 <_ZN4lamb8Encoders6States4UIntILc8ELb0EE5do_upEv+0x46>
     7a2:	40 e0       	ldi	r20, 0x00	; 0
     7a4:	44 83       	std	Z+4, r20	; 0x04
     7a6:	08 95       	ret

000007a8 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE13poll_requiredEv>:
     7a8:	80 e0       	ldi	r24, 0x00	; 0
     7aa:	08 95       	ret

000007ac <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv>:
     7ac:	1f 93       	push	r17
     7ae:	cf 93       	push	r28
     7b0:	df 93       	push	r29
     7b2:	1f b7       	in	r17, 0x3f	; 63
     7b4:	f8 94       	cli
     7b6:	e0 91 4f 03 	lds	r30, 0x034F	; 0x80034f <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin0_portE>
     7ba:	f0 91 50 03 	lds	r31, 0x0350	; 0x800350 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin0_portE+0x1>
     7be:	20 81       	ld	r18, Z
     7c0:	80 91 52 03 	lds	r24, 0x0352	; 0x800352 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin0_maskE>
     7c4:	08 2e       	mov	r0, r24
     7c6:	00 0c       	add	r0, r0
     7c8:	99 0b       	sbc	r25, r25
     7ca:	30 e0       	ldi	r19, 0x00	; 0
     7cc:	82 23       	and	r24, r18
     7ce:	93 23       	and	r25, r19
     7d0:	89 2b       	or	r24, r25
     7d2:	11 f4       	brne	.+4      	; 0x7d8 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0x2c>
     7d4:	80 e0       	ldi	r24, 0x00	; 0
     7d6:	01 c0       	rjmp	.+2      	; 0x7da <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0x2e>
     7d8:	82 e0       	ldi	r24, 0x02	; 2
     7da:	e0 91 4d 03 	lds	r30, 0x034D	; 0x80034d <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin1_portE>
     7de:	f0 91 4e 03 	lds	r31, 0x034E	; 0x80034e <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin1_portE+0x1>
     7e2:	40 81       	ld	r20, Z
     7e4:	c0 91 53 03 	lds	r28, 0x0353	; 0x800353 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE5stateE>
     7e8:	d0 91 54 03 	lds	r29, 0x0354	; 0x800354 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE5stateE+0x1>
     7ec:	ea 81       	ldd	r30, Y+2	; 0x02
     7ee:	fb 81       	ldd	r31, Y+3	; 0x03
     7f0:	20 91 51 03 	lds	r18, 0x0351	; 0x800351 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin1_maskE>
     7f4:	02 2e       	mov	r0, r18
     7f6:	00 0c       	add	r0, r0
     7f8:	33 0b       	sbc	r19, r19
     7fa:	50 e0       	ldi	r21, 0x00	; 0
     7fc:	24 23       	and	r18, r20
     7fe:	35 23       	and	r19, r21
     800:	91 e0       	ldi	r25, 0x01	; 1
     802:	23 2b       	or	r18, r19
     804:	09 f4       	brne	.+2      	; 0x808 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0x5c>
     806:	90 e0       	ldi	r25, 0x00	; 0
     808:	89 2b       	or	r24, r25
     80a:	08 2e       	mov	r0, r24
     80c:	00 0c       	add	r0, r0
     80e:	99 0b       	sbc	r25, r25
     810:	31 96       	adiw	r30, 0x01	; 1
     812:	e3 70       	andi	r30, 0x03	; 3
     814:	ff 27       	eor	r31, r31
     816:	e5 5d       	subi	r30, 0xD5	; 213
     818:	fe 4f       	sbci	r31, 0xFE	; 254
     81a:	20 81       	ld	r18, Z
     81c:	30 e0       	ldi	r19, 0x00	; 0
     81e:	28 17       	cp	r18, r24
     820:	39 07       	cpc	r19, r25
     822:	59 f4       	brne	.+22     	; 0x83a <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0x8e>
     824:	e8 81       	ld	r30, Y
     826:	f9 81       	ldd	r31, Y+1	; 0x01
     828:	04 80       	ldd	r0, Z+4	; 0x04
     82a:	f5 81       	ldd	r31, Z+5	; 0x05
     82c:	e0 2d       	mov	r30, r0
     82e:	ce 01       	movw	r24, r28
     830:	09 95       	icall
     832:	8a 81       	ldd	r24, Y+2	; 0x02
     834:	9b 81       	ldd	r25, Y+3	; 0x03
     836:	01 96       	adiw	r24, 0x01	; 1
     838:	1b c0       	rjmp	.+54     	; 0x870 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0xc4>
     83a:	ea 81       	ldd	r30, Y+2	; 0x02
     83c:	fb 81       	ldd	r31, Y+3	; 0x03
     83e:	31 97       	sbiw	r30, 0x01	; 1
     840:	e3 70       	andi	r30, 0x03	; 3
     842:	ff 27       	eor	r31, r31
     844:	e5 5d       	subi	r30, 0xD5	; 213
     846:	fe 4f       	sbci	r31, 0xFE	; 254
     848:	20 81       	ld	r18, Z
     84a:	30 e0       	ldi	r19, 0x00	; 0
     84c:	82 17       	cp	r24, r18
     84e:	93 07       	cpc	r25, r19
     850:	29 f0       	breq	.+10     	; 0x85c <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0xb0>
     852:	1f bf       	out	0x3f, r17	; 63
     854:	df 91       	pop	r29
     856:	cf 91       	pop	r28
     858:	1f 91       	pop	r17
     85a:	08 95       	ret
     85c:	e8 81       	ld	r30, Y
     85e:	f9 81       	ldd	r31, Y+1	; 0x01
     860:	06 80       	ldd	r0, Z+6	; 0x06
     862:	f7 81       	ldd	r31, Z+7	; 0x07
     864:	e0 2d       	mov	r30, r0
     866:	ce 01       	movw	r24, r28
     868:	09 95       	icall
     86a:	8a 81       	ldd	r24, Y+2	; 0x02
     86c:	9b 81       	ldd	r25, Y+3	; 0x03
     86e:	01 97       	sbiw	r24, 0x01	; 1
     870:	83 70       	andi	r24, 0x03	; 3
     872:	99 27       	eor	r25, r25
     874:	9b 83       	std	Y+3, r25	; 0x03
     876:	8a 83       	std	Y+2, r24	; 0x02
     878:	ec cf       	rjmp	.-40     	; 0x852 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE6updateEv+0xa6>

0000087a <_ZThn7_N15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE18impl_dequeue_eventEv>:
     87a:	fc 01       	movw	r30, r24
     87c:	37 97       	sbiw	r30, 0x07	; 7
     87e:	21 85       	ldd	r18, Z+9	; 0x09
     880:	32 85       	ldd	r19, Z+10	; 0x0a
     882:	8c e0       	ldi	r24, 0x0C	; 12
     884:	90 e0       	ldi	r25, 0x00	; 0
     886:	92 87       	std	Z+10, r25	; 0x0a
     888:	81 87       	std	Z+9, r24	; 0x09
     88a:	60 e0       	ldi	r22, 0x00	; 0
     88c:	70 e0       	ldi	r23, 0x00	; 0
     88e:	80 e0       	ldi	r24, 0x00	; 0
     890:	b9 01       	movw	r22, r18
     892:	08 95       	ret

00000894 <_ZN15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE18impl_dequeue_eventEv.lto_priv.148>:
     894:	fc 01       	movw	r30, r24
     896:	21 85       	ldd	r18, Z+9	; 0x09
     898:	32 85       	ldd	r19, Z+10	; 0x0a
     89a:	4c e0       	ldi	r20, 0x0C	; 12
     89c:	50 e0       	ldi	r21, 0x00	; 0
     89e:	52 87       	std	Z+10, r21	; 0x0a
     8a0:	41 87       	std	Z+9, r20	; 0x09
     8a2:	60 e0       	ldi	r22, 0x00	; 0
     8a4:	70 e0       	ldi	r23, 0x00	; 0
     8a6:	80 e0       	ldi	r24, 0x00	; 0
     8a8:	b9 01       	movw	r22, r18
     8aa:	08 95       	ret

000008ac <_ZThn7_NK15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE16impl_queue_countEv>:
     8ac:	21 e0       	ldi	r18, 0x01	; 1
     8ae:	fc 01       	movw	r30, r24
     8b0:	82 81       	ldd	r24, Z+2	; 0x02
     8b2:	93 81       	ldd	r25, Z+3	; 0x03
     8b4:	0c 97       	sbiw	r24, 0x0c	; 12
     8b6:	09 f4       	brne	.+2      	; 0x8ba <_ZThn7_NK15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE16impl_queue_countEv+0xe>
     8b8:	20 e0       	ldi	r18, 0x00	; 0
     8ba:	82 2f       	mov	r24, r18
     8bc:	08 95       	ret

000008be <_ZNK15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE16impl_queue_countEv.lto_priv.147>:
     8be:	21 e0       	ldi	r18, 0x01	; 1
     8c0:	fc 01       	movw	r30, r24
     8c2:	81 85       	ldd	r24, Z+9	; 0x09
     8c4:	92 85       	ldd	r25, Z+10	; 0x0a
     8c6:	0c 97       	sbiw	r24, 0x0c	; 12
     8c8:	09 f4       	brne	.+2      	; 0x8cc <_ZNK15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE16impl_queue_countEv.lto_priv.147+0xe>
     8ca:	20 e0       	ldi	r18, 0x00	; 0
     8cc:	82 2f       	mov	r24, r18
     8ce:	08 95       	ret

000008d0 <_ZN15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv.lto_priv.146>:
     8d0:	cf 93       	push	r28
     8d2:	df 93       	push	r29
     8d4:	ec 01       	movw	r28, r24
     8d6:	e8 81       	ld	r30, Y
     8d8:	f9 81       	ldd	r31, Y+1	; 0x01
     8da:	04 80       	ldd	r0, Z+4	; 0x04
     8dc:	f5 81       	ldd	r31, Z+5	; 0x05
     8de:	e0 2d       	mov	r30, r0
     8e0:	09 95       	icall
     8e2:	88 23       	and	r24, r24
     8e4:	89 f0       	breq	.+34     	; 0x908 <__stack+0x9>
     8e6:	e8 81       	ld	r30, Y
     8e8:	f9 81       	ldd	r31, Y+1	; 0x01
     8ea:	06 80       	ldd	r0, Z+6	; 0x06
     8ec:	f7 81       	ldd	r31, Z+7	; 0x07
     8ee:	e0 2d       	mov	r30, r0
     8f0:	ce 01       	movw	r24, r28
     8f2:	09 95       	icall
     8f4:	e8 2f       	mov	r30, r24
     8f6:	f0 e0       	ldi	r31, 0x00	; 0
     8f8:	ee 0f       	add	r30, r30
     8fa:	ff 1f       	adc	r31, r31
     8fc:	e5 5e       	subi	r30, 0xE5	; 229
     8fe:	fe 4f       	sbci	r31, 0xFE	; 254
     900:	80 81       	ld	r24, Z
     902:	91 81       	ldd	r25, Z+1	; 0x01
     904:	9a 87       	std	Y+10, r25	; 0x0a
     906:	89 87       	std	Y+9, r24	; 0x09
     908:	df 91       	pop	r29
     90a:	cf 91       	pop	r28
     90c:	08 95       	ret

0000090e <_ZThn7_N15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv>:
     90e:	07 97       	sbiw	r24, 0x07	; 7
     910:	0c 94 68 04 	jmp	0x8d0	; 0x8d0 <_ZN15ButtonpadSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv.lto_priv.146>

00000914 <_ZNK17Buttonpad_PCF8754ILh63EE11impl_buttonEv>:
     914:	fc 01       	movw	r30, r24
     916:	82 81       	ldd	r24, Z+2	; 0x02
     918:	08 95       	ret

0000091a <_ZN7Timer2_D0Ev>:
     91a:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000091e <_ZN7Timer1_D0Ev>:
     91e:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000922 <_ZN6SSNoneD0Ev>:
     922:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000926 <_ZN7SSInstrD0Ev>:
     926:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000092a <_ZN7SSIntroD0Ev>:
     92a:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000092e <_ZN6SSMainD0Ev>:
     92e:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000932 <_ZN6EepromD0Ev>:
     932:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000936 <_ZN13EncoderButtonD0Ev>:
     936:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000093a <_ZN4lamb8Encoders6States4UIntILc8ELb0EED0Ev>:
     93a:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000093e <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EED0Ev>:
     93e:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000942 <_ZN7EncoderD0Ev>:
     942:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

00000946 <_ZN7SSIntro10impl_enterEv>:
     946:	1f 93       	push	r17
     948:	cf 93       	push	r28
     94a:	df 93       	push	r29
     94c:	60 e0       	ldi	r22, 0x00	; 0
     94e:	80 e0       	ldi	r24, 0x00	; 0
     950:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     954:	82 e7       	ldi	r24, 0x72	; 114
     956:	91 e0       	ldi	r25, 0x01	; 1
     958:	0e 94 40 0e 	call	0x1c80	; 0x1c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>
     95c:	14 e0       	ldi	r17, 0x04	; 4
     95e:	c0 e0       	ldi	r28, 0x00	; 0
     960:	d1 e0       	ldi	r29, 0x01	; 1
     962:	6d 2f       	mov	r22, r29
     964:	8c 2f       	mov	r24, r28
     966:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     96a:	80 e7       	ldi	r24, 0x70	; 112
     96c:	91 e0       	ldi	r25, 0x01	; 1
     96e:	0e 94 40 0e 	call	0x1c80	; 0x1c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>
     972:	df 5f       	subi	r29, 0xFF	; 255
     974:	d4 30       	cpi	r29, 0x04	; 4
     976:	a9 f7       	brne	.-22     	; 0x962 <_ZN7SSIntro10impl_enterEv+0x1c>
     978:	6a e0       	ldi	r22, 0x0A	; 10
     97a:	70 e0       	ldi	r23, 0x00	; 0
     97c:	80 e0       	ldi	r24, 0x00	; 0
     97e:	90 e0       	ldi	r25, 0x00	; 0
     980:	0e 94 de 10 	call	0x21bc	; 0x21bc <delay>
     984:	cf 5f       	subi	r28, 0xFF	; 255
     986:	c4 31       	cpi	r28, 0x14	; 20
     988:	59 f7       	brne	.-42     	; 0x960 <_ZN7SSIntro10impl_enterEv+0x1a>
     98a:	c0 e0       	ldi	r28, 0x00	; 0
     98c:	d1 e0       	ldi	r29, 0x01	; 1
     98e:	6d 2f       	mov	r22, r29
     990:	8c 2f       	mov	r24, r28
     992:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     996:	62 e0       	ldi	r22, 0x02	; 2
     998:	8d e1       	ldi	r24, 0x1D	; 29
     99a:	94 e0       	ldi	r25, 0x04	; 4
     99c:	0e 94 39 0b 	call	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>
     9a0:	df 5f       	subi	r29, 0xFF	; 255
     9a2:	d4 30       	cpi	r29, 0x04	; 4
     9a4:	a1 f7       	brne	.-24     	; 0x98e <_ZN7SSIntro10impl_enterEv+0x48>
     9a6:	6a e0       	ldi	r22, 0x0A	; 10
     9a8:	70 e0       	ldi	r23, 0x00	; 0
     9aa:	80 e0       	ldi	r24, 0x00	; 0
     9ac:	90 e0       	ldi	r25, 0x00	; 0
     9ae:	0e 94 de 10 	call	0x21bc	; 0x21bc <delay>
     9b2:	cf 5f       	subi	r28, 0xFF	; 255
     9b4:	c4 31       	cpi	r28, 0x14	; 20
     9b6:	51 f7       	brne	.-44     	; 0x98c <_ZN7SSIntro10impl_enterEv+0x46>
     9b8:	11 50       	subi	r17, 0x01	; 1
     9ba:	89 f6       	brne	.-94     	; 0x95e <_ZN7SSIntro10impl_enterEv+0x18>
     9bc:	c0 e0       	ldi	r28, 0x00	; 0
     9be:	d1 e0       	ldi	r29, 0x01	; 1
     9c0:	6d 2f       	mov	r22, r29
     9c2:	8c 2f       	mov	r24, r28
     9c4:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     9c8:	8e e6       	ldi	r24, 0x6E	; 110
     9ca:	91 e0       	ldi	r25, 0x01	; 1
     9cc:	0e 94 40 0e 	call	0x1c80	; 0x1c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>
     9d0:	df 5f       	subi	r29, 0xFF	; 255
     9d2:	d4 30       	cpi	r29, 0x04	; 4
     9d4:	a9 f7       	brne	.-22     	; 0x9c0 <_ZN7SSIntro10impl_enterEv+0x7a>
     9d6:	6a e0       	ldi	r22, 0x0A	; 10
     9d8:	70 e0       	ldi	r23, 0x00	; 0
     9da:	80 e0       	ldi	r24, 0x00	; 0
     9dc:	90 e0       	ldi	r25, 0x00	; 0
     9de:	0e 94 de 10 	call	0x21bc	; 0x21bc <delay>
     9e2:	cf 5f       	subi	r28, 0xFF	; 255
     9e4:	c4 31       	cpi	r28, 0x14	; 20
     9e6:	59 f7       	brne	.-42     	; 0x9be <_ZN7SSIntro10impl_enterEv+0x78>
     9e8:	6c e2       	ldi	r22, 0x2C	; 44
     9ea:	71 e0       	ldi	r23, 0x01	; 1
     9ec:	80 e0       	ldi	r24, 0x00	; 0
     9ee:	90 e0       	ldi	r25, 0x00	; 0
     9f0:	0e 94 de 10 	call	0x21bc	; 0x21bc <delay>
     9f4:	0e 94 68 0c 	call	0x18d0	; 0x18d0 <_ZN13LiquidCrystal5clearEv.constprop.62>
     9f8:	6c e2       	ldi	r22, 0x2C	; 44
     9fa:	71 e0       	ldi	r23, 0x01	; 1
     9fc:	80 e0       	ldi	r24, 0x00	; 0
     9fe:	90 e0       	ldi	r25, 0x00	; 0
     a00:	df 91       	pop	r29
     a02:	cf 91       	pop	r28
     a04:	1f 91       	pop	r17
     a06:	0c 94 de 10 	jmp	0x21bc	; 0x21bc <delay>

00000a0a <_ZN6SSMain11impl_updateEv>:
     a0a:	cf 92       	push	r12
     a0c:	df 92       	push	r13
     a0e:	ef 92       	push	r14
     a10:	ff 92       	push	r15
     a12:	0f 93       	push	r16
     a14:	1f 93       	push	r17
     a16:	cf 93       	push	r28
     a18:	df 93       	push	r29
     a1a:	ec 01       	movw	r28, r24
     a1c:	ed 81       	ldd	r30, Y+5	; 0x05
     a1e:	fe 81       	ldd	r31, Y+6	; 0x06
     a20:	86 85       	ldd	r24, Z+14	; 0x0e
     a22:	88 23       	and	r24, r24
     a24:	a1 f0       	breq	.+40     	; 0xa4e <_ZN6SSMain11impl_updateEv+0x44>
     a26:	16 86       	std	Z+14, r1	; 0x0e
     a28:	2f b7       	in	r18, 0x3f	; 63
     a2a:	f8 94       	cli
     a2c:	80 91 0d 04 	lds	r24, 0x040D	; 0x80040d <timer0_millis>
     a30:	90 91 0e 04 	lds	r25, 0x040E	; 0x80040e <timer0_millis+0x1>
     a34:	a0 91 0f 04 	lds	r26, 0x040F	; 0x80040f <timer0_millis+0x2>
     a38:	b0 91 10 04 	lds	r27, 0x0410	; 0x800410 <timer0_millis+0x3>
     a3c:	2f bf       	out	0x3f, r18	; 63
     a3e:	8f 83       	std	Y+7, r24	; 0x07
     a40:	98 87       	std	Y+8, r25	; 0x08
     a42:	a9 87       	std	Y+9, r26	; 0x09
     a44:	ba 87       	std	Y+10, r27	; 0x0a
     a46:	81 e0       	ldi	r24, 0x01	; 1
     a48:	8b 87       	std	Y+11, r24	; 0x0b
     a4a:	61 e0       	ldi	r22, 0x01	; 1
     a4c:	01 c0       	rjmp	.+2      	; 0xa50 <_ZN6SSMain11impl_updateEv+0x46>
     a4e:	60 e0       	ldi	r22, 0x00	; 0
     a50:	8b 85       	ldd	r24, Y+11	; 0x0b
     a52:	88 23       	and	r24, r24
     a54:	e9 f0       	breq	.+58     	; 0xa90 <_ZN6SSMain11impl_updateEv+0x86>
     a56:	2f b7       	in	r18, 0x3f	; 63
     a58:	f8 94       	cli
     a5a:	80 91 0d 04 	lds	r24, 0x040D	; 0x80040d <timer0_millis>
     a5e:	90 91 0e 04 	lds	r25, 0x040E	; 0x80040e <timer0_millis+0x1>
     a62:	a0 91 0f 04 	lds	r26, 0x040F	; 0x80040f <timer0_millis+0x2>
     a66:	b0 91 10 04 	lds	r27, 0x0410	; 0x800410 <timer0_millis+0x3>
     a6a:	2f bf       	out	0x3f, r18	; 63
     a6c:	0f 81       	ldd	r16, Y+7	; 0x07
     a6e:	18 85       	ldd	r17, Y+8	; 0x08
     a70:	29 85       	ldd	r18, Y+9	; 0x09
     a72:	3a 85       	ldd	r19, Y+10	; 0x0a
     a74:	80 1b       	sub	r24, r16
     a76:	91 0b       	sbc	r25, r17
     a78:	a2 0b       	sbc	r26, r18
     a7a:	b3 0b       	sbc	r27, r19
     a7c:	88 35       	cpi	r24, 0x58	; 88
     a7e:	92 40       	sbci	r25, 0x02	; 2
     a80:	a1 05       	cpc	r26, r1
     a82:	b1 05       	cpc	r27, r1
     a84:	28 f0       	brcs	.+10     	; 0xa90 <_ZN6SSMain11impl_updateEv+0x86>
     a86:	1b 86       	std	Y+11, r1	; 0x0b
     a88:	ed 81       	ldd	r30, Y+5	; 0x05
     a8a:	fe 81       	ldd	r31, Y+6	; 0x06
     a8c:	81 e0       	ldi	r24, 0x01	; 1
     a8e:	84 8b       	std	Z+20, r24	; 0x14
     a90:	ce 01       	movw	r24, r28
     a92:	0e 94 70 0e 	call	0x1ce0	; 0x1ce0 <_ZN6SSMain10draw_line0Eb.constprop.4>
     a96:	ed 80       	ldd	r14, Y+5	; 0x05
     a98:	fe 80       	ldd	r15, Y+6	; 0x06
     a9a:	f7 01       	movw	r30, r14
     a9c:	03 85       	ldd	r16, Z+11	; 0x0b
     a9e:	10 e0       	ldi	r17, 0x00	; 0
     aa0:	15 95       	asr	r17
     aa2:	07 95       	ror	r16
     aa4:	82 81       	ldd	r24, Z+2	; 0x02
     aa6:	93 81       	ldd	r25, Z+3	; 0x03
     aa8:	0e 94 4e 03 	call	0x69c	; 0x69c <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv>
     aac:	d8 2e       	mov	r13, r24
     aae:	68 2f       	mov	r22, r24
     ab0:	70 e0       	ldi	r23, 0x00	; 0
     ab2:	c8 01       	movw	r24, r16
     ab4:	0e 94 5e 17 	call	0x2ebc	; 0x2ebc <__divmodhi4>
     ab8:	c8 2e       	mov	r12, r24
     aba:	f7 01       	movw	r30, r14
     abc:	81 89       	ldd	r24, Z+17	; 0x11
     abe:	88 23       	and	r24, r24
     ac0:	11 f0       	breq	.+4      	; 0xac6 <_ZN6SSMain11impl_updateEv+0xbc>
     ac2:	11 8a       	std	Z+17, r1	; 0x11
     ac4:	23 c0       	rjmp	.+70     	; 0xb0c <_ZN6SSMain11impl_updateEv+0x102>
     ac6:	f7 01       	movw	r30, r14
     ac8:	84 81       	ldd	r24, Z+4	; 0x04
     aca:	90 91 00 01 	lds	r25, 0x0100	; 0x800100 <__data_start>
     ace:	89 17       	cp	r24, r25
     ad0:	19 f0       	breq	.+6      	; 0xad8 <_ZN6SSMain11impl_updateEv+0xce>
     ad2:	80 93 00 01 	sts	0x0100, r24	; 0x800100 <__data_start>
     ad6:	1a c0       	rjmp	.+52     	; 0xb0c <_ZN6SSMain11impl_updateEv+0x102>
     ad8:	f1 2c       	mov	r15, r1
     ada:	41 e0       	ldi	r20, 0x01	; 1
     adc:	6c 2d       	mov	r22, r12
     ade:	ce 01       	movw	r24, r28
     ae0:	0e 94 c9 0f 	call	0x1f92	; 0x1f92 <_ZN6SSMain11draw_columnEhbb.constprop.2>
     ae4:	f1 10       	cpse	r15, r1
     ae6:	29 c0       	rjmp	.+82     	; 0xb3a <_ZN6SSMain11impl_updateEv+0x130>
     ae8:	8f ef       	ldi	r24, 0xFF	; 255
     aea:	80 0f       	add	r24, r16
     aec:	6d 2d       	mov	r22, r13
     aee:	0e 94 52 17 	call	0x2ea4	; 0x2ea4 <__udivmodqi4>
     af2:	40 e0       	ldi	r20, 0x00	; 0
     af4:	69 2f       	mov	r22, r25
     af6:	ce 01       	movw	r24, r28
     af8:	df 91       	pop	r29
     afa:	cf 91       	pop	r28
     afc:	1f 91       	pop	r17
     afe:	0f 91       	pop	r16
     b00:	ff 90       	pop	r15
     b02:	ef 90       	pop	r14
     b04:	df 90       	pop	r13
     b06:	cf 90       	pop	r12
     b08:	0c 94 c9 0f 	jmp	0x1f92	; 0x1f92 <_ZN6SSMain11draw_columnEhbb.constprop.2>
     b0c:	ce 01       	movw	r24, r28
     b0e:	0e 94 5a 0e 	call	0x1cb4	; 0x1cb4 <_ZN6SSMain16draw_page_numberEv.constprop.6>
     b12:	f1 2c       	mov	r15, r1
     b14:	ed 81       	ldd	r30, Y+5	; 0x05
     b16:	fe 81       	ldd	r31, Y+6	; 0x06
     b18:	84 81       	ldd	r24, Z+4	; 0x04
     b1a:	6f 2d       	mov	r22, r15
     b1c:	f0 e1       	ldi	r31, 0x10	; 16
     b1e:	8f 9f       	mul	r24, r31
     b20:	60 0d       	add	r22, r0
     b22:	11 24       	eor	r1, r1
     b24:	40 e0       	ldi	r20, 0x00	; 0
     b26:	ce 01       	movw	r24, r28
     b28:	0e 94 c9 0f 	call	0x1f92	; 0x1f92 <_ZN6SSMain11draw_columnEhbb.constprop.2>
     b2c:	f3 94       	inc	r15
     b2e:	20 e1       	ldi	r18, 0x10	; 16
     b30:	f2 12       	cpse	r15, r18
     b32:	f0 cf       	rjmp	.-32     	; 0xb14 <_ZN6SSMain11impl_updateEv+0x10a>
     b34:	ff 24       	eor	r15, r15
     b36:	f3 94       	inc	r15
     b38:	d0 cf       	rjmp	.-96     	; 0xada <_ZN6SSMain11impl_updateEv+0xd0>
     b3a:	df 91       	pop	r29
     b3c:	cf 91       	pop	r28
     b3e:	1f 91       	pop	r17
     b40:	0f 91       	pop	r16
     b42:	ff 90       	pop	r15
     b44:	ef 90       	pop	r14
     b46:	df 90       	pop	r13
     b48:	cf 90       	pop	r12
     b4a:	08 95       	ret

00000b4c <_ZN6SSMain10impl_enterEv>:
     b4c:	0f 93       	push	r16
     b4e:	1f 93       	push	r17
     b50:	cf 93       	push	r28
     b52:	8c 01       	movw	r16, r24
     b54:	dc 01       	movw	r26, r24
     b56:	15 96       	adiw	r26, 0x05	; 5
     b58:	ed 91       	ld	r30, X+
     b5a:	fc 91       	ld	r31, X
     b5c:	16 97       	sbiw	r26, 0x06	; 6
     b5e:	81 e0       	ldi	r24, 0x01	; 1
     b60:	86 87       	std	Z+14, r24	; 0x0e
     b62:	60 e0       	ldi	r22, 0x00	; 0
     b64:	c8 01       	movw	r24, r16
     b66:	0e 94 70 0e 	call	0x1ce0	; 0x1ce0 <_ZN6SSMain10draw_line0Eb.constprop.4>
     b6a:	60 e0       	ldi	r22, 0x00	; 0
     b6c:	83 e1       	ldi	r24, 0x13	; 19
     b6e:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     b72:	61 e0       	ldi	r22, 0x01	; 1
     b74:	8d e1       	ldi	r24, 0x1D	; 29
     b76:	94 e0       	ldi	r25, 0x04	; 4
     b78:	0e 94 39 0b 	call	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>
     b7c:	c8 01       	movw	r24, r16
     b7e:	0e 94 02 0e 	call	0x1c04	; 0x1c04 <_ZN6SSMain20draw_channel_numbersEv.constprop.13>
     b82:	c1 e0       	ldi	r28, 0x01	; 1
     b84:	6c 2f       	mov	r22, r28
     b86:	85 e0       	ldi	r24, 0x05	; 5
     b88:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     b8c:	8c e6       	ldi	r24, 0x6C	; 108
     b8e:	91 e0       	ldi	r25, 0x01	; 1
     b90:	0e 94 40 0e 	call	0x1c80	; 0x1c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>
     b94:	6c 2f       	mov	r22, r28
     b96:	8a e0       	ldi	r24, 0x0A	; 10
     b98:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     b9c:	8c e6       	ldi	r24, 0x6C	; 108
     b9e:	91 e0       	ldi	r25, 0x01	; 1
     ba0:	0e 94 40 0e 	call	0x1c80	; 0x1c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>
     ba4:	6c 2f       	mov	r22, r28
     ba6:	8f e0       	ldi	r24, 0x0F	; 15
     ba8:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
     bac:	8c e6       	ldi	r24, 0x6C	; 108
     bae:	91 e0       	ldi	r25, 0x01	; 1
     bb0:	0e 94 40 0e 	call	0x1c80	; 0x1c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>
     bb4:	cf 5f       	subi	r28, 0xFF	; 255
     bb6:	c4 30       	cpi	r28, 0x04	; 4
     bb8:	29 f7       	brne	.-54     	; 0xb84 <_ZN6SSMain10impl_enterEv+0x38>
     bba:	c0 e0       	ldi	r28, 0x00	; 0
     bbc:	40 e0       	ldi	r20, 0x00	; 0
     bbe:	6c 2f       	mov	r22, r28
     bc0:	c8 01       	movw	r24, r16
     bc2:	0e 94 c9 0f 	call	0x1f92	; 0x1f92 <_ZN6SSMain11draw_columnEhbb.constprop.2>
     bc6:	cf 5f       	subi	r28, 0xFF	; 255
     bc8:	c0 31       	cpi	r28, 0x10	; 16
     bca:	c1 f7       	brne	.-16     	; 0xbbc <_ZN6SSMain10impl_enterEv+0x70>
     bcc:	c8 01       	movw	r24, r16
     bce:	cf 91       	pop	r28
     bd0:	1f 91       	pop	r17
     bd2:	0f 91       	pop	r16
     bd4:	0c 94 5a 0e 	jmp	0x1cb4	; 0x1cb4 <_ZN6SSMain16draw_page_numberEv.constprop.6>

00000bd8 <_ZN7Encoder5setupEv>:
     bd8:	e5 e3       	ldi	r30, 0x35	; 53
     bda:	f4 e0       	ldi	r31, 0x04	; 4
     bdc:	82 81       	ldd	r24, Z+2	; 0x02
     bde:	93 81       	ldd	r25, Z+3	; 0x03
     be0:	60 81       	ld	r22, Z
     be2:	71 81       	ldd	r23, Z+1	; 0x01
     be4:	dc 01       	movw	r26, r24
     be6:	ed 91       	ld	r30, X+
     be8:	fc 91       	ld	r31, X
     bea:	04 80       	ldd	r0, Z+4	; 0x04
     bec:	f5 81       	ldd	r31, Z+5	; 0x05
     bee:	e0 2d       	mov	r30, r0
     bf0:	09 95       	icall
     bf2:	a1 e1       	ldi	r26, 0x11	; 17
     bf4:	b1 e0       	ldi	r27, 0x01	; 1
     bf6:	26 ed       	ldi	r18, 0xD6	; 214
     bf8:	33 e0       	ldi	r19, 0x03	; 3
     bfa:	11 96       	adiw	r26, 0x01	; 1
     bfc:	3c 93       	st	X, r19
     bfe:	2e 93       	st	-X, r18
     c00:	e9 e6       	ldi	r30, 0x69	; 105
     c02:	f0 e0       	ldi	r31, 0x00	; 0
     c04:	80 81       	ld	r24, Z
     c06:	8c 7f       	andi	r24, 0xFC	; 252
     c08:	81 60       	ori	r24, 0x01	; 1
     c0a:	80 83       	st	Z, r24
     c0c:	e8 9a       	sbi	0x1d, 0	; 29
     c0e:	13 96       	adiw	r26, 0x03	; 3
     c10:	3c 93       	st	X, r19
     c12:	2e 93       	st	-X, r18
     c14:	12 97       	sbiw	r26, 0x02	; 2
     c16:	80 81       	ld	r24, Z
     c18:	83 7f       	andi	r24, 0xF3	; 243
     c1a:	84 60       	ori	r24, 0x04	; 4
     c1c:	80 83       	st	Z, r24
     c1e:	e9 9a       	sbi	0x1d, 1	; 29
     c20:	08 95       	ret

00000c22 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE5setupEPNS0_6States6IStateE>:
     c22:	70 93 54 03 	sts	0x0354, r23	; 0x800354 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE5stateE+0x1>
     c26:	60 93 53 03 	sts	0x0353, r22	; 0x800353 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE5stateE>
     c2a:	62 e0       	ldi	r22, 0x02	; 2
     c2c:	82 e0       	ldi	r24, 0x02	; 2
     c2e:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
     c32:	62 e0       	ldi	r22, 0x02	; 2
     c34:	83 e0       	ldi	r24, 0x03	; 3
     c36:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
     c3a:	e1 eb       	ldi	r30, 0xB1	; 177
     c3c:	f1 e0       	ldi	r31, 0x01	; 1
     c3e:	e4 91       	lpm	r30, Z
     c40:	e0 93 52 03 	sts	0x0352, r30	; 0x800352 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin0_maskE>
     c44:	e2 eb       	ldi	r30, 0xB2	; 178
     c46:	f1 e0       	ldi	r31, 0x01	; 1
     c48:	e4 91       	lpm	r30, Z
     c4a:	e0 93 51 03 	sts	0x0351, r30	; 0x800351 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin1_maskE>
     c4e:	ed e9       	ldi	r30, 0x9D	; 157
     c50:	f1 e0       	ldi	r31, 0x01	; 1
     c52:	e4 91       	lpm	r30, Z
     c54:	f0 e0       	ldi	r31, 0x00	; 0
     c56:	ee 0f       	add	r30, r30
     c58:	ff 1f       	adc	r31, r31
     c5a:	ee 59       	subi	r30, 0x9E	; 158
     c5c:	fe 4f       	sbci	r31, 0xFE	; 254
     c5e:	85 91       	lpm	r24, Z+
     c60:	94 91       	lpm	r25, Z
     c62:	90 93 50 03 	sts	0x0350, r25	; 0x800350 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin0_portE+0x1>
     c66:	80 93 4f 03 	sts	0x034F, r24	; 0x80034f <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin0_portE>
     c6a:	ee e9       	ldi	r30, 0x9E	; 158
     c6c:	f1 e0       	ldi	r31, 0x01	; 1
     c6e:	e4 91       	lpm	r30, Z
     c70:	f0 e0       	ldi	r31, 0x00	; 0
     c72:	ee 0f       	add	r30, r30
     c74:	ff 1f       	adc	r31, r31
     c76:	ee 59       	subi	r30, 0x9E	; 158
     c78:	fe 4f       	sbci	r31, 0xFE	; 254
     c7a:	85 91       	lpm	r24, Z+
     c7c:	94 91       	lpm	r25, Z
     c7e:	90 93 4e 03 	sts	0x034E, r25	; 0x80034e <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin1_portE+0x1>
     c82:	80 93 4d 03 	sts	0x034D, r24	; 0x80034d <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE9pin1_portE>
     c86:	08 95       	ret

00000c88 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv>:
     c88:	cf 93       	push	r28
     c8a:	df 93       	push	r29
     c8c:	ec 01       	movw	r28, r24
     c8e:	10 92 97 03 	sts	0x0397, r1	; 0x800397 <_ZN7TwoWire13rxBufferIndexE>
     c92:	10 92 96 03 	sts	0x0396, r1	; 0x800396 <_ZN7TwoWire14rxBufferLengthE>
     c96:	10 92 99 03 	sts	0x0399, r1	; 0x800399 <_ZN7TwoWire13txBufferIndexE>
     c9a:	10 92 98 03 	sts	0x0398, r1	; 0x800398 <_ZN7TwoWire14txBufferLengthE>
     c9e:	10 92 9f 03 	sts	0x039F, r1	; 0x80039f <twi_state.lto_priv.181>
     ca2:	81 e0       	ldi	r24, 0x01	; 1
     ca4:	80 93 a1 03 	sts	0x03A1, r24	; 0x8003a1 <twi_sendStop.lto_priv.182>
     ca8:	10 92 a0 03 	sts	0x03A0, r1	; 0x8003a0 <twi_inRepStart.lto_priv.188>
     cac:	61 e0       	ldi	r22, 0x01	; 1
     cae:	82 e1       	ldi	r24, 0x12	; 18
     cb0:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
     cb4:	61 e0       	ldi	r22, 0x01	; 1
     cb6:	83 e1       	ldi	r24, 0x13	; 19
     cb8:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
     cbc:	80 91 b9 00 	lds	r24, 0x00B9	; 0x8000b9 <__TEXT_REGION_LENGTH__+0x7e00b9>
     cc0:	8e 7f       	andi	r24, 0xFE	; 254
     cc2:	80 93 b9 00 	sts	0x00B9, r24	; 0x8000b9 <__TEXT_REGION_LENGTH__+0x7e00b9>
     cc6:	80 91 b9 00 	lds	r24, 0x00B9	; 0x8000b9 <__TEXT_REGION_LENGTH__+0x7e00b9>
     cca:	8d 7f       	andi	r24, 0xFD	; 253
     ccc:	80 93 b9 00 	sts	0x00B9, r24	; 0x8000b9 <__TEXT_REGION_LENGTH__+0x7e00b9>
     cd0:	88 e4       	ldi	r24, 0x48	; 72
     cd2:	80 93 b8 00 	sts	0x00B8, r24	; 0x8000b8 <__TEXT_REGION_LENGTH__+0x7e00b8>
     cd6:	85 e4       	ldi	r24, 0x45	; 69
     cd8:	80 93 bc 00 	sts	0x00BC, r24	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
     cdc:	83 e8       	ldi	r24, 0x83	; 131
     cde:	98 e0       	ldi	r25, 0x08	; 8
     ce0:	90 93 9b 03 	sts	0x039B, r25	; 0x80039b <twi_onSlaveTransmit.lto_priv.189+0x1>
     ce4:	80 93 9a 03 	sts	0x039A, r24	; 0x80039a <twi_onSlaveTransmit.lto_priv.189>
     ce8:	84 e8       	ldi	r24, 0x84	; 132
     cea:	98 e0       	ldi	r25, 0x08	; 8
     cec:	90 93 9d 03 	sts	0x039D, r25	; 0x80039d <twi_onSlaveReceive.lto_priv.190+0x1>
     cf0:	80 93 9c 03 	sts	0x039C, r24	; 0x80039c <twi_onSlaveReceive.lto_priv.190>
     cf4:	9c 81       	ldd	r25, Y+4	; 0x04
     cf6:	99 23       	and	r25, r25
     cf8:	21 f0       	breq	.+8      	; 0xd02 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x7a>
     cfa:	8b 81       	ldd	r24, Y+3	; 0x03
     cfc:	8f 33       	cpi	r24, 0x3F	; 63
     cfe:	09 f0       	breq	.+2      	; 0xd02 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x7a>
     d00:	58 c0       	rjmp	.+176    	; 0xdb2 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x12a>
     d02:	8f e3       	ldi	r24, 0x3F	; 63
     d04:	8b 83       	std	Y+3, r24	; 0x03
     d06:	91 11       	cpse	r25, r1
     d08:	54 c0       	rjmp	.+168    	; 0xdb2 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x12a>
     d0a:	91 e0       	ldi	r25, 0x01	; 1
     d0c:	9c 83       	std	Y+4, r25	; 0x04
     d0e:	90 93 75 03 	sts	0x0375, r25	; 0x800375 <_ZN7TwoWire12transmittingE>
     d12:	80 93 4c 03 	sts	0x034C, r24	; 0x80034c <__data_end>
     d16:	10 92 99 03 	sts	0x0399, r1	; 0x800399 <_ZN7TwoWire13txBufferIndexE>
     d1a:	10 92 98 03 	sts	0x0398, r1	; 0x800398 <_ZN7TwoWire14txBufferLengthE>
     d1e:	80 91 9f 03 	lds	r24, 0x039F	; 0x80039f <twi_state.lto_priv.181>
     d22:	81 11       	cpse	r24, r1
     d24:	fc cf       	rjmp	.-8      	; 0xd1e <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x96>
     d26:	92 e0       	ldi	r25, 0x02	; 2
     d28:	90 93 9f 03 	sts	0x039F, r25	; 0x80039f <twi_state.lto_priv.181>
     d2c:	91 e0       	ldi	r25, 0x01	; 1
     d2e:	90 93 a1 03 	sts	0x03A1, r25	; 0x8003a1 <twi_sendStop.lto_priv.182>
     d32:	9f ef       	ldi	r25, 0xFF	; 255
     d34:	90 93 9e 03 	sts	0x039E, r25	; 0x80039e <twi_error.lto_priv.183>
     d38:	10 92 c3 03 	sts	0x03C3, r1	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
     d3c:	10 92 c2 03 	sts	0x03C2, r1	; 0x8003c2 <twi_masterBufferLength.lto_priv.185>
     d40:	10 92 c4 03 	sts	0x03C4, r1	; 0x8003c4 <twi_slarw.lto_priv.187>
     d44:	90 91 c4 03 	lds	r25, 0x03C4	; 0x8003c4 <twi_slarw.lto_priv.187>
     d48:	9e 67       	ori	r25, 0x7E	; 126
     d4a:	90 93 c4 03 	sts	0x03C4, r25	; 0x8003c4 <twi_slarw.lto_priv.187>
     d4e:	90 91 a0 03 	lds	r25, 0x03A0	; 0x8003a0 <twi_inRepStart.lto_priv.188>
     d52:	91 30       	cpi	r25, 0x01	; 1
     d54:	61 f4       	brne	.+24     	; 0xd6e <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0xe6>
     d56:	10 92 a0 03 	sts	0x03A0, r1	; 0x8003a0 <twi_inRepStart.lto_priv.188>
     d5a:	90 91 c4 03 	lds	r25, 0x03C4	; 0x8003c4 <twi_slarw.lto_priv.187>
     d5e:	90 93 bb 00 	sts	0x00BB, r25	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
     d62:	90 91 bc 00 	lds	r25, 0x00BC	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
     d66:	93 fd       	sbrc	r25, 3
     d68:	f8 cf       	rjmp	.-16     	; 0xd5a <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0xd2>
     d6a:	95 ec       	ldi	r25, 0xC5	; 197
     d6c:	01 c0       	rjmp	.+2      	; 0xd70 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0xe8>
     d6e:	95 ee       	ldi	r25, 0xE5	; 229
     d70:	90 93 bc 00 	sts	0x00BC, r25	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
     d74:	90 91 9f 03 	lds	r25, 0x039F	; 0x80039f <twi_state.lto_priv.181>
     d78:	92 30       	cpi	r25, 0x02	; 2
     d7a:	e1 f3       	breq	.-8      	; 0xd74 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0xec>
     d7c:	90 91 9e 03 	lds	r25, 0x039E	; 0x80039e <twi_error.lto_priv.183>
     d80:	9f 3f       	cpi	r25, 0xFF	; 255
     d82:	69 f0       	breq	.+26     	; 0xd9e <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x116>
     d84:	80 91 9e 03 	lds	r24, 0x039E	; 0x80039e <twi_error.lto_priv.183>
     d88:	80 32       	cpi	r24, 0x20	; 32
     d8a:	31 f0       	breq	.+12     	; 0xd98 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x110>
     d8c:	80 91 9e 03 	lds	r24, 0x039E	; 0x80039e <twi_error.lto_priv.183>
     d90:	80 33       	cpi	r24, 0x30	; 48
     d92:	21 f0       	breq	.+8      	; 0xd9c <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x114>
     d94:	84 e0       	ldi	r24, 0x04	; 4
     d96:	03 c0       	rjmp	.+6      	; 0xd9e <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x116>
     d98:	82 e0       	ldi	r24, 0x02	; 2
     d9a:	01 c0       	rjmp	.+2      	; 0xd9e <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x116>
     d9c:	83 e0       	ldi	r24, 0x03	; 3
     d9e:	10 92 99 03 	sts	0x0399, r1	; 0x800399 <_ZN7TwoWire13txBufferIndexE>
     da2:	10 92 98 03 	sts	0x0398, r1	; 0x800398 <_ZN7TwoWire14txBufferLengthE>
     da6:	10 92 75 03 	sts	0x0375, r1	; 0x800375 <_ZN7TwoWire12transmittingE>
     daa:	91 e0       	ldi	r25, 0x01	; 1
     dac:	81 11       	cpse	r24, r1
     dae:	90 e0       	ldi	r25, 0x00	; 0
     db0:	9c 83       	std	Y+4, r25	; 0x04
     db2:	8d 81       	ldd	r24, Y+5	; 0x05
     db4:	9e 81       	ldd	r25, Y+6	; 0x06
     db6:	20 e0       	ldi	r18, 0x00	; 0
     db8:	30 e0       	ldi	r19, 0x00	; 0
     dba:	61 e0       	ldi	r22, 0x01	; 1
     dbc:	70 e0       	ldi	r23, 0x00	; 0
     dbe:	ab 01       	movw	r20, r22
     dc0:	02 2e       	mov	r0, r18
     dc2:	01 c0       	rjmp	.+2      	; 0xdc6 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x13e>
     dc4:	44 0f       	add	r20, r20
     dc6:	0a 94       	dec	r0
     dc8:	ea f7       	brpl	.-6      	; 0xdc4 <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x13c>
     dca:	40 95       	com	r20
     dcc:	84 23       	and	r24, r20
     dce:	48 2f       	mov	r20, r24
     dd0:	40 95       	com	r20
     dd2:	94 2b       	or	r25, r20
     dd4:	2f 5f       	subi	r18, 0xFF	; 255
     dd6:	3f 4f       	sbci	r19, 0xFF	; 255
     dd8:	28 30       	cpi	r18, 0x08	; 8
     dda:	31 05       	cpc	r19, r1
     ddc:	81 f7       	brne	.-32     	; 0xdbe <_ZN17Buttonpad_PCF8754ILh63EE10impl_setupEv+0x136>
     dde:	8d 83       	std	Y+5, r24	; 0x05
     de0:	9e 83       	std	Y+6, r25	; 0x06
     de2:	df 91       	pop	r29
     de4:	cf 91       	pop	r28
     de6:	08 95       	ret

00000de8 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv>:
     de8:	cf 93       	push	r28
     dea:	df 93       	push	r29
     dec:	ec 01       	movw	r28, r24
     dee:	78 94       	sei
     df0:	8c 81       	ldd	r24, Y+4	; 0x04
     df2:	88 23       	and	r24, r24
     df4:	09 f4       	brne	.+2      	; 0xdf8 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x10>
     df6:	50 c0       	rjmp	.+160    	; 0xe98 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xb0>
     df8:	8b 81       	ldd	r24, Y+3	; 0x03
     dfa:	90 91 9f 03 	lds	r25, 0x039F	; 0x80039f <twi_state.lto_priv.181>
     dfe:	91 11       	cpse	r25, r1
     e00:	fc cf       	rjmp	.-8      	; 0xdfa <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x12>
     e02:	91 e0       	ldi	r25, 0x01	; 1
     e04:	90 93 9f 03 	sts	0x039F, r25	; 0x80039f <twi_state.lto_priv.181>
     e08:	90 93 a1 03 	sts	0x03A1, r25	; 0x8003a1 <twi_sendStop.lto_priv.182>
     e0c:	2f ef       	ldi	r18, 0xFF	; 255
     e0e:	20 93 9e 03 	sts	0x039E, r18	; 0x80039e <twi_error.lto_priv.183>
     e12:	10 92 c3 03 	sts	0x03C3, r1	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
     e16:	10 92 c2 03 	sts	0x03C2, r1	; 0x8003c2 <twi_masterBufferLength.lto_priv.185>
     e1a:	90 93 c4 03 	sts	0x03C4, r25	; 0x8003c4 <twi_slarw.lto_priv.187>
     e1e:	90 91 c4 03 	lds	r25, 0x03C4	; 0x8003c4 <twi_slarw.lto_priv.187>
     e22:	88 0f       	add	r24, r24
     e24:	89 2b       	or	r24, r25
     e26:	80 93 c4 03 	sts	0x03C4, r24	; 0x8003c4 <twi_slarw.lto_priv.187>
     e2a:	80 91 a0 03 	lds	r24, 0x03A0	; 0x8003a0 <twi_inRepStart.lto_priv.188>
     e2e:	81 30       	cpi	r24, 0x01	; 1
     e30:	61 f4       	brne	.+24     	; 0xe4a <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x62>
     e32:	10 92 a0 03 	sts	0x03A0, r1	; 0x8003a0 <twi_inRepStart.lto_priv.188>
     e36:	80 91 c4 03 	lds	r24, 0x03C4	; 0x8003c4 <twi_slarw.lto_priv.187>
     e3a:	80 93 bb 00 	sts	0x00BB, r24	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
     e3e:	80 91 bc 00 	lds	r24, 0x00BC	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
     e42:	83 fd       	sbrc	r24, 3
     e44:	f8 cf       	rjmp	.-16     	; 0xe36 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x4e>
     e46:	85 ec       	ldi	r24, 0xC5	; 197
     e48:	01 c0       	rjmp	.+2      	; 0xe4c <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x64>
     e4a:	85 ee       	ldi	r24, 0xE5	; 229
     e4c:	80 93 bc 00 	sts	0x00BC, r24	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
     e50:	80 91 9f 03 	lds	r24, 0x039F	; 0x80039f <twi_state.lto_priv.181>
     e54:	81 30       	cpi	r24, 0x01	; 1
     e56:	e1 f3       	breq	.-8      	; 0xe50 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x68>
     e58:	80 91 c3 03 	lds	r24, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
     e5c:	81 11       	cpse	r24, r1
     e5e:	03 c0       	rjmp	.+6      	; 0xe66 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x7e>
     e60:	90 91 c3 03 	lds	r25, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
     e64:	01 c0       	rjmp	.+2      	; 0xe68 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x80>
     e66:	91 e0       	ldi	r25, 0x01	; 1
     e68:	e2 ea       	ldi	r30, 0xA2	; 162
     e6a:	f3 e0       	ldi	r31, 0x03	; 3
     e6c:	a6 e7       	ldi	r26, 0x76	; 118
     e6e:	b3 e0       	ldi	r27, 0x03	; 3
     e70:	80 e0       	ldi	r24, 0x00	; 0
     e72:	89 17       	cp	r24, r25
     e74:	21 f0       	breq	.+8      	; 0xe7e <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x96>
     e76:	21 91       	ld	r18, Z+
     e78:	2d 93       	st	X+, r18
     e7a:	8f 5f       	subi	r24, 0xFF	; 255
     e7c:	fa cf       	rjmp	.-12     	; 0xe72 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0x8a>
     e7e:	10 92 97 03 	sts	0x0397, r1	; 0x800397 <_ZN7TwoWire13rxBufferIndexE>
     e82:	80 93 96 03 	sts	0x0396, r24	; 0x800396 <_ZN7TwoWire14rxBufferLengthE>
     e86:	81 30       	cpi	r24, 0x01	; 1
     e88:	11 f0       	breq	.+4      	; 0xe8e <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xa6>
     e8a:	1c 82       	std	Y+4, r1	; 0x04
     e8c:	05 c0       	rjmp	.+10     	; 0xe98 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xb0>
     e8e:	81 e1       	ldi	r24, 0x11	; 17
     e90:	94 e0       	ldi	r25, 0x04	; 4
     e92:	0e 94 95 08 	call	0x112a	; 0x112a <_ZN7TwoWire4readEv>
     e96:	01 c0       	rjmp	.+2      	; 0xe9a <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xb2>
     e98:	8f ef       	ldi	r24, 0xFF	; 255
     e9a:	f8 94       	cli
     e9c:	21 e0       	ldi	r18, 0x01	; 1
     e9e:	90 e0       	ldi	r25, 0x00	; 0
     ea0:	38 2f       	mov	r19, r24
     ea2:	32 23       	and	r19, r18
     ea4:	21 f0       	breq	.+8      	; 0xeae <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xc6>
     ea6:	9f 5f       	subi	r25, 0xFF	; 255
     ea8:	22 0f       	add	r18, r18
     eaa:	98 30       	cpi	r25, 0x08	; 8
     eac:	c9 f7       	brne	.-14     	; 0xea0 <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xb8>
     eae:	8a 81       	ldd	r24, Y+2	; 0x02
     eb0:	89 17       	cp	r24, r25
     eb2:	21 f0       	breq	.+8      	; 0xebc <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xd4>
     eb4:	9a 83       	std	Y+2, r25	; 0x02
     eb6:	81 e0       	ldi	r24, 0x01	; 1
     eb8:	98 30       	cpi	r25, 0x08	; 8
     eba:	09 f4       	brne	.+2      	; 0xebe <_ZN17Buttonpad_PCF8754ILh63EE9impl_readEv+0xd6>
     ebc:	80 e0       	ldi	r24, 0x00	; 0
     ebe:	df 91       	pop	r29
     ec0:	cf 91       	pop	r28
     ec2:	08 95       	ret

00000ec4 <_ZN7Timer2_D1Ev>:
     ec4:	08 95       	ret

00000ec6 <__vector_11>:
     ec6:	1f 92       	push	r1
     ec8:	0f 92       	push	r0
     eca:	0f b6       	in	r0, 0x3f	; 63
     ecc:	0f 92       	push	r0
     ece:	11 24       	eor	r1, r1
     ed0:	0f 93       	push	r16
     ed2:	1f 93       	push	r17
     ed4:	2f 93       	push	r18
     ed6:	3f 93       	push	r19
     ed8:	4f 93       	push	r20
     eda:	5f 93       	push	r21
     edc:	6f 93       	push	r22
     ede:	7f 93       	push	r23
     ee0:	8f 93       	push	r24
     ee2:	9f 93       	push	r25
     ee4:	af 93       	push	r26
     ee6:	bf 93       	push	r27
     ee8:	cf 93       	push	r28
     eea:	ef 93       	push	r30
     eec:	ff 93       	push	r31
     eee:	e0 91 c5 03 	lds	r30, 0x03C5	; 0x8003c5 <_ZN7Timer1_9_instanceE>
     ef2:	f0 91 c6 03 	lds	r31, 0x03C6	; 0x8003c6 <_ZN7Timer1_9_instanceE+0x1>
     ef6:	c4 81       	ldd	r28, Z+4	; 0x04
     ef8:	c0 fd       	sbrc	r28, 0
     efa:	36 c0       	rjmp	.+108    	; 0xf68 <__vector_11+0xa2>
     efc:	0e 94 5e 03 	call	0x6bc	; 0x6bc <_ZN11Application16flag_main_screenEv>
     f00:	e0 91 c5 03 	lds	r30, 0x03C5	; 0x8003c5 <_ZN7Timer1_9_instanceE>
     f04:	f0 91 c6 03 	lds	r31, 0x03C6	; 0x8003c6 <_ZN7Timer1_9_instanceE+0x1>
     f08:	83 81       	ldd	r24, Z+3	; 0x03
     f0a:	81 11       	cpse	r24, r1
     f0c:	04 c0       	rjmp	.+8      	; 0xf16 <__vector_11+0x50>
     f0e:	88 b1       	in	r24, 0x08	; 8
     f10:	80 7f       	andi	r24, 0xF0	; 240
     f12:	88 b9       	out	0x08, r24	; 8
     f14:	33 c0       	rjmp	.+102    	; 0xf7c <__vector_11+0xb6>
     f16:	c6 95       	lsr	r28
     f18:	e3 e7       	ldi	r30, 0x73	; 115
     f1a:	f4 e0       	ldi	r31, 0x04	; 4
     f1c:	20 e0       	ldi	r18, 0x00	; 0
     f1e:	30 e0       	ldi	r19, 0x00	; 0
     f20:	40 e0       	ldi	r20, 0x00	; 0
     f22:	01 e0       	ldi	r16, 0x01	; 1
     f24:	10 e0       	ldi	r17, 0x00	; 0
     f26:	82 85       	ldd	r24, Z+10	; 0x0a
     f28:	9c 2f       	mov	r25, r28
     f2a:	98 1b       	sub	r25, r24
     f2c:	89 2f       	mov	r24, r25
     f2e:	67 81       	ldd	r22, Z+7	; 0x07
     f30:	0e 94 52 17 	call	0x2ea4	; 0x2ea4 <__udivmodqi4>
     f34:	89 2f       	mov	r24, r25
     f36:	90 e0       	ldi	r25, 0x00	; 0
     f38:	51 85       	ldd	r21, Z+9	; 0x09
     f3a:	85 1b       	sub	r24, r21
     f3c:	91 09       	sbc	r25, r1
     f3e:	60 85       	ldd	r22, Z+8	; 0x08
     f40:	70 e0       	ldi	r23, 0x00	; 0
     f42:	0e 94 5e 17 	call	0x2ebc	; 0x2ebc <__divmodhi4>
     f46:	89 2b       	or	r24, r25
     f48:	39 f4       	brne	.+14     	; 0xf58 <__vector_11+0x92>
     f4a:	c8 01       	movw	r24, r16
     f4c:	02 2e       	mov	r0, r18
     f4e:	01 c0       	rjmp	.+2      	; 0xf52 <__vector_11+0x8c>
     f50:	88 0f       	add	r24, r24
     f52:	0a 94       	dec	r0
     f54:	ea f7       	brpl	.-6      	; 0xf50 <__vector_11+0x8a>
     f56:	48 2b       	or	r20, r24
     f58:	2f 5f       	subi	r18, 0xFF	; 255
     f5a:	3f 4f       	sbci	r19, 0xFF	; 255
     f5c:	39 96       	adiw	r30, 0x09	; 9
     f5e:	23 30       	cpi	r18, 0x03	; 3
     f60:	31 05       	cpc	r19, r1
     f62:	09 f7       	brne	.-62     	; 0xf26 <__vector_11+0x60>
     f64:	48 b9       	out	0x08, r20	; 8
     f66:	03 c0       	rjmp	.+6      	; 0xf6e <__vector_11+0xa8>
     f68:	88 b1       	in	r24, 0x08	; 8
     f6a:	80 7f       	andi	r24, 0xF0	; 240
     f6c:	88 b9       	out	0x08, r24	; 8
     f6e:	e0 91 c5 03 	lds	r30, 0x03C5	; 0x8003c5 <_ZN7Timer1_9_instanceE>
     f72:	f0 91 c6 03 	lds	r31, 0x03C6	; 0x8003c6 <_ZN7Timer1_9_instanceE+0x1>
     f76:	84 81       	ldd	r24, Z+4	; 0x04
     f78:	8f 5f       	subi	r24, 0xFF	; 255
     f7a:	84 83       	std	Z+4, r24	; 0x04
     f7c:	ff 91       	pop	r31
     f7e:	ef 91       	pop	r30
     f80:	cf 91       	pop	r28
     f82:	bf 91       	pop	r27
     f84:	af 91       	pop	r26
     f86:	9f 91       	pop	r25
     f88:	8f 91       	pop	r24
     f8a:	7f 91       	pop	r23
     f8c:	6f 91       	pop	r22
     f8e:	5f 91       	pop	r21
     f90:	4f 91       	pop	r20
     f92:	3f 91       	pop	r19
     f94:	2f 91       	pop	r18
     f96:	1f 91       	pop	r17
     f98:	0f 91       	pop	r16
     f9a:	0f 90       	pop	r0
     f9c:	0f be       	out	0x3f, r0	; 63
     f9e:	0f 90       	pop	r0
     fa0:	1f 90       	pop	r1
     fa2:	18 95       	reti

00000fa4 <_ZN7Timer1_13set_hz_by_bpmEh>:
     fa4:	cf 93       	push	r28
     fa6:	cf b7       	in	r28, 0x3f	; 63
     fa8:	f8 94       	cli
     faa:	68 2f       	mov	r22, r24
     fac:	70 e0       	ldi	r23, 0x00	; 0
     fae:	80 e0       	ldi	r24, 0x00	; 0
     fb0:	90 e0       	ldi	r25, 0x00	; 0
     fb2:	0e 94 be 18 	call	0x317c	; 0x317c <__floatsisf>
     fb6:	20 e0       	ldi	r18, 0x00	; 0
     fb8:	30 e0       	ldi	r19, 0x00	; 0
     fba:	40 e7       	ldi	r20, 0x70	; 112
     fbc:	52 e4       	ldi	r21, 0x42	; 66
     fbe:	0e 94 1b 18 	call	0x3036	; 0x3036 <__divsf3>
     fc2:	20 e0       	ldi	r18, 0x00	; 0
     fc4:	30 e0       	ldi	r19, 0x00	; 0
     fc6:	40 e0       	ldi	r20, 0x00	; 0
     fc8:	51 e4       	ldi	r21, 0x41	; 65
     fca:	0e 94 4a 19 	call	0x3294	; 0x3294 <__mulsf3>
     fce:	20 e0       	ldi	r18, 0x00	; 0
     fd0:	30 e0       	ldi	r19, 0x00	; 0
     fd2:	40 e8       	ldi	r20, 0x80	; 128
     fd4:	53 e4       	ldi	r21, 0x43	; 67
     fd6:	0e 94 4a 19 	call	0x3294	; 0x3294 <__mulsf3>
     fda:	9b 01       	movw	r18, r22
     fdc:	ac 01       	movw	r20, r24
     fde:	60 e0       	ldi	r22, 0x00	; 0
     fe0:	74 e2       	ldi	r23, 0x24	; 36
     fe2:	84 e7       	ldi	r24, 0x74	; 116
     fe4:	9b e4       	ldi	r25, 0x4B	; 75
     fe6:	0e 94 1b 18 	call	0x3036	; 0x3036 <__divsf3>
     fea:	20 e0       	ldi	r18, 0x00	; 0
     fec:	30 e0       	ldi	r19, 0x00	; 0
     fee:	40 e8       	ldi	r20, 0x80	; 128
     ff0:	5f e3       	ldi	r21, 0x3F	; 63
     ff2:	0e 94 ae 17 	call	0x2f5c	; 0x2f5c <__subsf3>
     ff6:	0e 94 8d 18 	call	0x311a	; 0x311a <__fixunssfsi>
     ffa:	70 93 89 00 	sts	0x0089, r23	; 0x800089 <__TEXT_REGION_LENGTH__+0x7e0089>
     ffe:	60 93 88 00 	sts	0x0088, r22	; 0x800088 <__TEXT_REGION_LENGTH__+0x7e0088>
    1002:	20 91 84 00 	lds	r18, 0x0084	; 0x800084 <__TEXT_REGION_LENGTH__+0x7e0084>
    1006:	30 91 85 00 	lds	r19, 0x0085	; 0x800085 <__TEXT_REGION_LENGTH__+0x7e0085>
    100a:	80 91 88 00 	lds	r24, 0x0088	; 0x800088 <__TEXT_REGION_LENGTH__+0x7e0088>
    100e:	90 91 89 00 	lds	r25, 0x0089	; 0x800089 <__TEXT_REGION_LENGTH__+0x7e0089>
    1012:	82 17       	cp	r24, r18
    1014:	93 07       	cpc	r25, r19
    1016:	48 f4       	brcc	.+18     	; 0x102a <_ZN7Timer1_13set_hz_by_bpmEh+0x86>
    1018:	80 91 88 00 	lds	r24, 0x0088	; 0x800088 <__TEXT_REGION_LENGTH__+0x7e0088>
    101c:	90 91 89 00 	lds	r25, 0x0089	; 0x800089 <__TEXT_REGION_LENGTH__+0x7e0089>
    1020:	01 97       	sbiw	r24, 0x01	; 1
    1022:	90 93 85 00 	sts	0x0085, r25	; 0x800085 <__TEXT_REGION_LENGTH__+0x7e0085>
    1026:	80 93 84 00 	sts	0x0084, r24	; 0x800084 <__TEXT_REGION_LENGTH__+0x7e0084>
    102a:	cf bf       	out	0x3f, r28	; 63
    102c:	cf 91       	pop	r28
    102e:	08 95       	ret

00001030 <_ZN7Timer1_D1Ev>:
    1030:	08 95       	ret

00001032 <_ZN6SSNoneD1Ev.lto_priv.137>:
    1032:	08 95       	ret

00001034 <_ZN7SSInstrD1Ev.lto_priv.139>:
    1034:	08 95       	ret

00001036 <_ZN7SSIntroD1Ev.lto_priv.136>:
    1036:	08 95       	ret

00001038 <_ZN6SSMainD1Ev.lto_priv.138>:
    1038:	08 95       	ret

0000103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>:
    103a:	0c 94 0d 17 	jmp	0x2e1a	; 0x2e1a <eeprom_write_byte>

0000103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>:
    103e:	0c 94 05 17 	jmp	0x2e0a	; 0x2e0a <eeprom_read_byte>

00001042 <_ZN6EepromD1Ev>:
    1042:	08 95       	ret

00001044 <_ZN13EncoderButtonD1Ev>:
    1044:	08 95       	ret

00001046 <_ZN4lamb8Encoders6States4UIntILc8ELb0EED1Ev.lto_priv.142>:
    1046:	08 95       	ret

00001048 <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EED1Ev.lto_priv.141>:
    1048:	08 95       	ret

0000104a <_ZN7EncoderD1Ev>:
    104a:	08 95       	ret

0000104c <nothing>:
    104c:	08 95       	ret

0000104e <_ZN5Print5writeEPKhj>:
    104e:	cf 92       	push	r12
    1050:	df 92       	push	r13
    1052:	ef 92       	push	r14
    1054:	ff 92       	push	r15
    1056:	0f 93       	push	r16
    1058:	1f 93       	push	r17
    105a:	cf 93       	push	r28
    105c:	df 93       	push	r29
    105e:	6c 01       	movw	r12, r24
    1060:	7a 01       	movw	r14, r20
    1062:	8b 01       	movw	r16, r22
    1064:	c0 e0       	ldi	r28, 0x00	; 0
    1066:	d0 e0       	ldi	r29, 0x00	; 0
    1068:	ce 15       	cp	r28, r14
    106a:	df 05       	cpc	r29, r15
    106c:	81 f0       	breq	.+32     	; 0x108e <_ZN5Print5writeEPKhj+0x40>
    106e:	d8 01       	movw	r26, r16
    1070:	6d 91       	ld	r22, X+
    1072:	8d 01       	movw	r16, r26
    1074:	d6 01       	movw	r26, r12
    1076:	ed 91       	ld	r30, X+
    1078:	fc 91       	ld	r31, X
    107a:	01 90       	ld	r0, Z+
    107c:	f0 81       	ld	r31, Z
    107e:	e0 2d       	mov	r30, r0
    1080:	c6 01       	movw	r24, r12
    1082:	09 95       	icall
    1084:	89 2b       	or	r24, r25
    1086:	11 f0       	breq	.+4      	; 0x108c <_ZN5Print5writeEPKhj+0x3e>
    1088:	21 96       	adiw	r28, 0x01	; 1
    108a:	ee cf       	rjmp	.-36     	; 0x1068 <_ZN5Print5writeEPKhj+0x1a>
    108c:	7e 01       	movw	r14, r28
    108e:	c7 01       	movw	r24, r14
    1090:	df 91       	pop	r29
    1092:	cf 91       	pop	r28
    1094:	1f 91       	pop	r17
    1096:	0f 91       	pop	r16
    1098:	ff 90       	pop	r15
    109a:	ef 90       	pop	r14
    109c:	df 90       	pop	r13
    109e:	cf 90       	pop	r12
    10a0:	08 95       	ret

000010a2 <twi_stop>:
    10a2:	85 ed       	ldi	r24, 0xD5	; 213
    10a4:	80 93 bc 00 	sts	0x00BC, r24	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
    10a8:	80 91 bc 00 	lds	r24, 0x00BC	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
    10ac:	84 fd       	sbrc	r24, 4
    10ae:	fc cf       	rjmp	.-8      	; 0x10a8 <twi_stop+0x6>
    10b0:	10 92 9f 03 	sts	0x039F, r1	; 0x80039f <twi_state.lto_priv.181>
    10b4:	08 95       	ret

000010b6 <twi_transmit>:
    10b6:	40 91 e9 03 	lds	r20, 0x03E9	; 0x8003e9 <twi_txBufferLength>
    10ba:	26 2f       	mov	r18, r22
    10bc:	30 e0       	ldi	r19, 0x00	; 0
    10be:	24 0f       	add	r18, r20
    10c0:	31 1d       	adc	r19, r1
    10c2:	21 32       	cpi	r18, 0x21	; 33
    10c4:	31 05       	cpc	r19, r1
    10c6:	dc f4       	brge	.+54     	; 0x10fe <twi_transmit+0x48>
    10c8:	20 91 9f 03 	lds	r18, 0x039F	; 0x80039f <twi_state.lto_priv.181>
    10cc:	24 30       	cpi	r18, 0x04	; 4
    10ce:	c9 f4       	brne	.+50     	; 0x1102 <twi_transmit+0x4c>
    10d0:	fc 01       	movw	r30, r24
    10d2:	80 e0       	ldi	r24, 0x00	; 0
    10d4:	90 e0       	ldi	r25, 0x00	; 0
    10d6:	86 17       	cp	r24, r22
    10d8:	58 f4       	brcc	.+22     	; 0x10f0 <twi_transmit+0x3a>
    10da:	30 91 e9 03 	lds	r19, 0x03E9	; 0x8003e9 <twi_txBufferLength>
    10de:	21 91       	ld	r18, Z+
    10e0:	dc 01       	movw	r26, r24
    10e2:	a7 53       	subi	r26, 0x37	; 55
    10e4:	bc 4f       	sbci	r27, 0xFC	; 252
    10e6:	a3 0f       	add	r26, r19
    10e8:	b1 1d       	adc	r27, r1
    10ea:	2c 93       	st	X, r18
    10ec:	01 96       	adiw	r24, 0x01	; 1
    10ee:	f3 cf       	rjmp	.-26     	; 0x10d6 <twi_transmit+0x20>
    10f0:	80 91 e9 03 	lds	r24, 0x03E9	; 0x8003e9 <twi_txBufferLength>
    10f4:	68 0f       	add	r22, r24
    10f6:	60 93 e9 03 	sts	0x03E9, r22	; 0x8003e9 <twi_txBufferLength>
    10fa:	80 e0       	ldi	r24, 0x00	; 0
    10fc:	08 95       	ret
    10fe:	81 e0       	ldi	r24, 0x01	; 1
    1100:	08 95       	ret
    1102:	82 e0       	ldi	r24, 0x02	; 2
    1104:	08 95       	ret

00001106 <_ZN7TwoWire16onRequestServiceEv>:
    1106:	08 95       	ret

00001108 <_ZN7TwoWire16onReceiveServiceEPhi>:
    1108:	08 95       	ret

0000110a <_ZN4lamb8Encoders10Interfaces10NativePinsILc2ELc3EE4pollEv>:
    110a:	08 95       	ret

0000110c <_ZN7TwoWire4peekEv>:
    110c:	e0 91 97 03 	lds	r30, 0x0397	; 0x800397 <_ZN7TwoWire13rxBufferIndexE>
    1110:	80 91 96 03 	lds	r24, 0x0396	; 0x800396 <_ZN7TwoWire14rxBufferLengthE>
    1114:	e8 17       	cp	r30, r24
    1116:	30 f4       	brcc	.+12     	; 0x1124 <_ZN7TwoWire4peekEv+0x18>
    1118:	f0 e0       	ldi	r31, 0x00	; 0
    111a:	ea 58       	subi	r30, 0x8A	; 138
    111c:	fc 4f       	sbci	r31, 0xFC	; 252
    111e:	80 81       	ld	r24, Z
    1120:	90 e0       	ldi	r25, 0x00	; 0
    1122:	08 95       	ret
    1124:	8f ef       	ldi	r24, 0xFF	; 255
    1126:	9f ef       	ldi	r25, 0xFF	; 255
    1128:	08 95       	ret

0000112a <_ZN7TwoWire4readEv>:
    112a:	90 91 97 03 	lds	r25, 0x0397	; 0x800397 <_ZN7TwoWire13rxBufferIndexE>
    112e:	80 91 96 03 	lds	r24, 0x0396	; 0x800396 <_ZN7TwoWire14rxBufferLengthE>
    1132:	98 17       	cp	r25, r24
    1134:	50 f4       	brcc	.+20     	; 0x114a <_ZN7TwoWire4readEv+0x20>
    1136:	e9 2f       	mov	r30, r25
    1138:	f0 e0       	ldi	r31, 0x00	; 0
    113a:	ea 58       	subi	r30, 0x8A	; 138
    113c:	fc 4f       	sbci	r31, 0xFC	; 252
    113e:	20 81       	ld	r18, Z
    1140:	30 e0       	ldi	r19, 0x00	; 0
    1142:	9f 5f       	subi	r25, 0xFF	; 255
    1144:	90 93 97 03 	sts	0x0397, r25	; 0x800397 <_ZN7TwoWire13rxBufferIndexE>
    1148:	02 c0       	rjmp	.+4      	; 0x114e <_ZN7TwoWire4readEv+0x24>
    114a:	2f ef       	ldi	r18, 0xFF	; 255
    114c:	3f ef       	ldi	r19, 0xFF	; 255
    114e:	c9 01       	movw	r24, r18
    1150:	08 95       	ret

00001152 <_ZN7TwoWire9availableEv>:
    1152:	80 91 96 03 	lds	r24, 0x0396	; 0x800396 <_ZN7TwoWire14rxBufferLengthE>
    1156:	90 e0       	ldi	r25, 0x00	; 0
    1158:	20 91 97 03 	lds	r18, 0x0397	; 0x800397 <_ZN7TwoWire13rxBufferIndexE>
    115c:	82 1b       	sub	r24, r18
    115e:	91 09       	sbc	r25, r1
    1160:	08 95       	ret

00001162 <_ZN7TwoWire5writeEPKhj>:
    1162:	cf 92       	push	r12
    1164:	df 92       	push	r13
    1166:	ef 92       	push	r14
    1168:	ff 92       	push	r15
    116a:	0f 93       	push	r16
    116c:	1f 93       	push	r17
    116e:	cf 93       	push	r28
    1170:	df 93       	push	r29
    1172:	7c 01       	movw	r14, r24
    1174:	cb 01       	movw	r24, r22
    1176:	8a 01       	movw	r16, r20
    1178:	20 91 75 03 	lds	r18, 0x0375	; 0x800375 <_ZN7TwoWire12transmittingE>
    117c:	22 23       	and	r18, r18
    117e:	89 f0       	breq	.+34     	; 0x11a2 <_ZN7TwoWire5writeEPKhj+0x40>
    1180:	eb 01       	movw	r28, r22
    1182:	6b 01       	movw	r12, r22
    1184:	c4 0e       	add	r12, r20
    1186:	d5 1e       	adc	r13, r21
    1188:	cc 15       	cp	r28, r12
    118a:	dd 05       	cpc	r29, r13
    118c:	69 f0       	breq	.+26     	; 0x11a8 <_ZN7TwoWire5writeEPKhj+0x46>
    118e:	69 91       	ld	r22, Y+
    1190:	d7 01       	movw	r26, r14
    1192:	ed 91       	ld	r30, X+
    1194:	fc 91       	ld	r31, X
    1196:	01 90       	ld	r0, Z+
    1198:	f0 81       	ld	r31, Z
    119a:	e0 2d       	mov	r30, r0
    119c:	c7 01       	movw	r24, r14
    119e:	09 95       	icall
    11a0:	f3 cf       	rjmp	.-26     	; 0x1188 <_ZN7TwoWire5writeEPKhj+0x26>
    11a2:	64 2f       	mov	r22, r20
    11a4:	0e 94 5b 08 	call	0x10b6	; 0x10b6 <twi_transmit>
    11a8:	c8 01       	movw	r24, r16
    11aa:	df 91       	pop	r29
    11ac:	cf 91       	pop	r28
    11ae:	1f 91       	pop	r17
    11b0:	0f 91       	pop	r16
    11b2:	ff 90       	pop	r15
    11b4:	ef 90       	pop	r14
    11b6:	df 90       	pop	r13
    11b8:	cf 90       	pop	r12
    11ba:	08 95       	ret

000011bc <_ZN7TwoWire5writeEh>:
    11bc:	cf 93       	push	r28
    11be:	df 93       	push	r29
    11c0:	1f 92       	push	r1
    11c2:	cd b7       	in	r28, 0x3d	; 61
    11c4:	de b7       	in	r29, 0x3e	; 62
    11c6:	69 83       	std	Y+1, r22	; 0x01
    11c8:	20 91 75 03 	lds	r18, 0x0375	; 0x800375 <_ZN7TwoWire12transmittingE>
    11cc:	22 23       	and	r18, r18
    11ce:	d1 f0       	breq	.+52     	; 0x1204 <_ZN7TwoWire5writeEh+0x48>
    11d0:	20 91 98 03 	lds	r18, 0x0398	; 0x800398 <_ZN7TwoWire14txBufferLengthE>
    11d4:	20 32       	cpi	r18, 0x20	; 32
    11d6:	40 f0       	brcs	.+16     	; 0x11e8 <_ZN7TwoWire5writeEh+0x2c>
    11d8:	21 e0       	ldi	r18, 0x01	; 1
    11da:	30 e0       	ldi	r19, 0x00	; 0
    11dc:	fc 01       	movw	r30, r24
    11de:	33 83       	std	Z+3, r19	; 0x03
    11e0:	22 83       	std	Z+2, r18	; 0x02
    11e2:	80 e0       	ldi	r24, 0x00	; 0
    11e4:	90 e0       	ldi	r25, 0x00	; 0
    11e6:	15 c0       	rjmp	.+42     	; 0x1212 <_ZN7TwoWire5writeEh+0x56>
    11e8:	80 91 99 03 	lds	r24, 0x0399	; 0x800399 <_ZN7TwoWire13txBufferIndexE>
    11ec:	e8 2f       	mov	r30, r24
    11ee:	f0 e0       	ldi	r31, 0x00	; 0
    11f0:	eb 5a       	subi	r30, 0xAB	; 171
    11f2:	fc 4f       	sbci	r31, 0xFC	; 252
    11f4:	99 81       	ldd	r25, Y+1	; 0x01
    11f6:	90 83       	st	Z, r25
    11f8:	8f 5f       	subi	r24, 0xFF	; 255
    11fa:	80 93 99 03 	sts	0x0399, r24	; 0x800399 <_ZN7TwoWire13txBufferIndexE>
    11fe:	80 93 98 03 	sts	0x0398, r24	; 0x800398 <_ZN7TwoWire14txBufferLengthE>
    1202:	05 c0       	rjmp	.+10     	; 0x120e <_ZN7TwoWire5writeEh+0x52>
    1204:	61 e0       	ldi	r22, 0x01	; 1
    1206:	ce 01       	movw	r24, r28
    1208:	01 96       	adiw	r24, 0x01	; 1
    120a:	0e 94 5b 08 	call	0x10b6	; 0x10b6 <twi_transmit>
    120e:	81 e0       	ldi	r24, 0x01	; 1
    1210:	90 e0       	ldi	r25, 0x00	; 0
    1212:	0f 90       	pop	r0
    1214:	df 91       	pop	r29
    1216:	cf 91       	pop	r28
    1218:	08 95       	ret

0000121a <_ZN5Print5flushEv>:
    121a:	08 95       	ret

0000121c <_ZN5Print17availableForWriteEv>:
    121c:	80 e0       	ldi	r24, 0x00	; 0
    121e:	90 e0       	ldi	r25, 0x00	; 0
    1220:	08 95       	ret

00001222 <_ZN5TrackaSERKS_>:
    1222:	fb 01       	movw	r30, r22
    1224:	25 81       	ldd	r18, Z+5	; 0x05
    1226:	dc 01       	movw	r26, r24
    1228:	15 96       	adiw	r26, 0x05	; 5
    122a:	2c 93       	st	X, r18
    122c:	15 97       	sbiw	r26, 0x05	; 5
    122e:	20 85       	ldd	r18, Z+8	; 0x08
    1230:	18 96       	adiw	r26, 0x08	; 8
    1232:	2c 93       	st	X, r18
    1234:	18 97       	sbiw	r26, 0x08	; 8
    1236:	26 81       	ldd	r18, Z+6	; 0x06
    1238:	16 96       	adiw	r26, 0x06	; 6
    123a:	2c 93       	st	X, r18
    123c:	16 97       	sbiw	r26, 0x06	; 6
    123e:	26 81       	ldd	r18, Z+6	; 0x06
    1240:	17 96       	adiw	r26, 0x07	; 7
    1242:	2c 93       	st	X, r18
    1244:	08 95       	ret

00001246 <__cxa_pure_virtual>:
    1246:	0e 94 d8 1a 	call	0x35b0	; 0x35b0 <abort>

0000124a <_ZN13LiquidCrystal11pulseEnableEv>:
    124a:	cf 93       	push	r28
    124c:	df 93       	push	r29
    124e:	ec 01       	movw	r28, r24
    1250:	60 e0       	ldi	r22, 0x00	; 0
    1252:	8e 81       	ldd	r24, Y+6	; 0x06
    1254:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1258:	61 e0       	ldi	r22, 0x01	; 1
    125a:	8e 81       	ldd	r24, Y+6	; 0x06
    125c:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1260:	60 e0       	ldi	r22, 0x00	; 0
    1262:	8e 81       	ldd	r24, Y+6	; 0x06
    1264:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1268:	8b e8       	ldi	r24, 0x8B	; 139
    126a:	91 e0       	ldi	r25, 0x01	; 1
    126c:	01 97       	sbiw	r24, 0x01	; 1
    126e:	f1 f7       	brne	.-4      	; 0x126c <_ZN13LiquidCrystal11pulseEnableEv+0x22>
    1270:	df 91       	pop	r29
    1272:	cf 91       	pop	r28
    1274:	08 95       	ret

00001276 <_ZN5TrackD0Ev>:
    1276:	0c 94 4f 1a 	jmp	0x349e	; 0x349e <free>

0000127a <__vector_2>:
    127a:	1f 92       	push	r1
    127c:	0f 92       	push	r0
    127e:	0f b6       	in	r0, 0x3f	; 63
    1280:	0f 92       	push	r0
    1282:	11 24       	eor	r1, r1
    1284:	2f 93       	push	r18
    1286:	3f 93       	push	r19
    1288:	4f 93       	push	r20
    128a:	5f 93       	push	r21
    128c:	6f 93       	push	r22
    128e:	7f 93       	push	r23
    1290:	8f 93       	push	r24
    1292:	9f 93       	push	r25
    1294:	af 93       	push	r26
    1296:	bf 93       	push	r27
    1298:	ef 93       	push	r30
    129a:	ff 93       	push	r31
    129c:	e0 91 13 01 	lds	r30, 0x0113	; 0x800113 <intFunc.lto_priv.180+0x2>
    12a0:	f0 91 14 01 	lds	r31, 0x0114	; 0x800114 <intFunc.lto_priv.180+0x3>
    12a4:	09 95       	icall
    12a6:	ff 91       	pop	r31
    12a8:	ef 91       	pop	r30
    12aa:	bf 91       	pop	r27
    12ac:	af 91       	pop	r26
    12ae:	9f 91       	pop	r25
    12b0:	8f 91       	pop	r24
    12b2:	7f 91       	pop	r23
    12b4:	6f 91       	pop	r22
    12b6:	5f 91       	pop	r21
    12b8:	4f 91       	pop	r20
    12ba:	3f 91       	pop	r19
    12bc:	2f 91       	pop	r18
    12be:	0f 90       	pop	r0
    12c0:	0f be       	out	0x3f, r0	; 63
    12c2:	0f 90       	pop	r0
    12c4:	1f 90       	pop	r1
    12c6:	18 95       	reti

000012c8 <__vector_1>:
    12c8:	1f 92       	push	r1
    12ca:	0f 92       	push	r0
    12cc:	0f b6       	in	r0, 0x3f	; 63
    12ce:	0f 92       	push	r0
    12d0:	11 24       	eor	r1, r1
    12d2:	2f 93       	push	r18
    12d4:	3f 93       	push	r19
    12d6:	4f 93       	push	r20
    12d8:	5f 93       	push	r21
    12da:	6f 93       	push	r22
    12dc:	7f 93       	push	r23
    12de:	8f 93       	push	r24
    12e0:	9f 93       	push	r25
    12e2:	af 93       	push	r26
    12e4:	bf 93       	push	r27
    12e6:	ef 93       	push	r30
    12e8:	ff 93       	push	r31
    12ea:	e0 91 11 01 	lds	r30, 0x0111	; 0x800111 <intFunc.lto_priv.180>
    12ee:	f0 91 12 01 	lds	r31, 0x0112	; 0x800112 <intFunc.lto_priv.180+0x1>
    12f2:	09 95       	icall
    12f4:	ff 91       	pop	r31
    12f6:	ef 91       	pop	r30
    12f8:	bf 91       	pop	r27
    12fa:	af 91       	pop	r26
    12fc:	9f 91       	pop	r25
    12fe:	8f 91       	pop	r24
    1300:	7f 91       	pop	r23
    1302:	6f 91       	pop	r22
    1304:	5f 91       	pop	r21
    1306:	4f 91       	pop	r20
    1308:	3f 91       	pop	r19
    130a:	2f 91       	pop	r18
    130c:	0f 90       	pop	r0
    130e:	0f be       	out	0x3f, r0	; 63
    1310:	0f 90       	pop	r0
    1312:	1f 90       	pop	r1
    1314:	18 95       	reti

00001316 <__vector_24>:
    1316:	1f 92       	push	r1
    1318:	0f 92       	push	r0
    131a:	0f b6       	in	r0, 0x3f	; 63
    131c:	0f 92       	push	r0
    131e:	11 24       	eor	r1, r1
    1320:	2f 93       	push	r18
    1322:	3f 93       	push	r19
    1324:	4f 93       	push	r20
    1326:	5f 93       	push	r21
    1328:	6f 93       	push	r22
    132a:	7f 93       	push	r23
    132c:	8f 93       	push	r24
    132e:	9f 93       	push	r25
    1330:	af 93       	push	r26
    1332:	bf 93       	push	r27
    1334:	ef 93       	push	r30
    1336:	ff 93       	push	r31
    1338:	80 91 b9 00 	lds	r24, 0x00B9	; 0x8000b9 <__TEXT_REGION_LENGTH__+0x7e00b9>
    133c:	88 7f       	andi	r24, 0xF8	; 248
    133e:	80 36       	cpi	r24, 0x60	; 96
    1340:	09 f4       	brne	.+2      	; 0x1344 <__vector_24+0x2e>
    1342:	9c c0       	rjmp	.+312    	; 0x147c <__vector_24+0x166>
    1344:	68 f5       	brcc	.+90     	; 0x13a0 <__vector_24+0x8a>
    1346:	88 32       	cpi	r24, 0x28	; 40
    1348:	09 f4       	brne	.+2      	; 0x134c <__vector_24+0x36>
    134a:	5b c0       	rjmp	.+182    	; 0x1402 <__vector_24+0xec>
    134c:	90 f4       	brcc	.+36     	; 0x1372 <__vector_24+0x5c>
    134e:	80 31       	cpi	r24, 0x10	; 16
    1350:	09 f4       	brne	.+2      	; 0x1354 <__vector_24+0x3e>
    1352:	54 c0       	rjmp	.+168    	; 0x13fc <__vector_24+0xe6>
    1354:	38 f4       	brcc	.+14     	; 0x1364 <__vector_24+0x4e>
    1356:	88 23       	and	r24, r24
    1358:	09 f4       	brne	.+2      	; 0x135c <__vector_24+0x46>
    135a:	f6 c0       	rjmp	.+492    	; 0x1548 <__vector_24+0x232>
    135c:	88 30       	cpi	r24, 0x08	; 8
    135e:	09 f4       	brne	.+2      	; 0x1362 <__vector_24+0x4c>
    1360:	4d c0       	rjmp	.+154    	; 0x13fc <__vector_24+0xe6>
    1362:	f6 c0       	rjmp	.+492    	; 0x1550 <__vector_24+0x23a>
    1364:	88 31       	cpi	r24, 0x18	; 24
    1366:	09 f4       	brne	.+2      	; 0x136a <__vector_24+0x54>
    1368:	4c c0       	rjmp	.+152    	; 0x1402 <__vector_24+0xec>
    136a:	80 32       	cpi	r24, 0x20	; 32
    136c:	09 f4       	brne	.+2      	; 0x1370 <__vector_24+0x5a>
    136e:	5d c0       	rjmp	.+186    	; 0x142a <__vector_24+0x114>
    1370:	ef c0       	rjmp	.+478    	; 0x1550 <__vector_24+0x23a>
    1372:	80 34       	cpi	r24, 0x40	; 64
    1374:	09 f4       	brne	.+2      	; 0x1378 <__vector_24+0x62>
    1376:	68 c0       	rjmp	.+208    	; 0x1448 <__vector_24+0x132>
    1378:	48 f4       	brcc	.+18     	; 0x138c <__vector_24+0x76>
    137a:	80 33       	cpi	r24, 0x30	; 48
    137c:	09 f4       	brne	.+2      	; 0x1380 <__vector_24+0x6a>
    137e:	55 c0       	rjmp	.+170    	; 0x142a <__vector_24+0x114>
    1380:	88 33       	cpi	r24, 0x38	; 56
    1382:	09 f0       	breq	.+2      	; 0x1386 <__vector_24+0x70>
    1384:	e5 c0       	rjmp	.+458    	; 0x1550 <__vector_24+0x23a>
    1386:	80 93 9e 03 	sts	0x039E, r24	; 0x80039e <twi_error.lto_priv.183>
    138a:	d8 c0       	rjmp	.+432    	; 0x153c <__vector_24+0x226>
    138c:	80 35       	cpi	r24, 0x50	; 80
    138e:	09 f4       	brne	.+2      	; 0x1392 <__vector_24+0x7c>
    1390:	4f c0       	rjmp	.+158    	; 0x1430 <__vector_24+0x11a>
    1392:	88 35       	cpi	r24, 0x58	; 88
    1394:	09 f4       	brne	.+2      	; 0x1398 <__vector_24+0x82>
    1396:	5d c0       	rjmp	.+186    	; 0x1452 <__vector_24+0x13c>
    1398:	88 34       	cpi	r24, 0x48	; 72
    139a:	09 f0       	breq	.+2      	; 0x139e <__vector_24+0x88>
    139c:	d9 c0       	rjmp	.+434    	; 0x1550 <__vector_24+0x23a>
    139e:	d6 c0       	rjmp	.+428    	; 0x154c <__vector_24+0x236>
    13a0:	88 39       	cpi	r24, 0x98	; 152
    13a2:	09 f4       	brne	.+2      	; 0x13a6 <__vector_24+0x90>
    13a4:	c7 c0       	rjmp	.+398    	; 0x1534 <__vector_24+0x21e>
    13a6:	a8 f4       	brcc	.+42     	; 0x13d2 <__vector_24+0xbc>
    13a8:	88 37       	cpi	r24, 0x78	; 120
    13aa:	09 f4       	brne	.+2      	; 0x13ae <__vector_24+0x98>
    13ac:	67 c0       	rjmp	.+206    	; 0x147c <__vector_24+0x166>
    13ae:	38 f4       	brcc	.+14     	; 0x13be <__vector_24+0xa8>
    13b0:	88 36       	cpi	r24, 0x68	; 104
    13b2:	09 f4       	brne	.+2      	; 0x13b6 <__vector_24+0xa0>
    13b4:	63 c0       	rjmp	.+198    	; 0x147c <__vector_24+0x166>
    13b6:	80 37       	cpi	r24, 0x70	; 112
    13b8:	09 f4       	brne	.+2      	; 0x13bc <__vector_24+0xa6>
    13ba:	60 c0       	rjmp	.+192    	; 0x147c <__vector_24+0x166>
    13bc:	c9 c0       	rjmp	.+402    	; 0x1550 <__vector_24+0x23a>
    13be:	88 38       	cpi	r24, 0x88	; 136
    13c0:	09 f4       	brne	.+2      	; 0x13c4 <__vector_24+0xae>
    13c2:	b8 c0       	rjmp	.+368    	; 0x1534 <__vector_24+0x21e>
    13c4:	80 39       	cpi	r24, 0x90	; 144
    13c6:	09 f4       	brne	.+2      	; 0x13ca <__vector_24+0xb4>
    13c8:	5f c0       	rjmp	.+190    	; 0x1488 <__vector_24+0x172>
    13ca:	80 38       	cpi	r24, 0x80	; 128
    13cc:	09 f0       	breq	.+2      	; 0x13d0 <__vector_24+0xba>
    13ce:	c0 c0       	rjmp	.+384    	; 0x1550 <__vector_24+0x23a>
    13d0:	5b c0       	rjmp	.+182    	; 0x1488 <__vector_24+0x172>
    13d2:	80 3b       	cpi	r24, 0xB0	; 176
    13d4:	09 f4       	brne	.+2      	; 0x13d8 <__vector_24+0xc2>
    13d6:	86 c0       	rjmp	.+268    	; 0x14e4 <__vector_24+0x1ce>
    13d8:	38 f4       	brcc	.+14     	; 0x13e8 <__vector_24+0xd2>
    13da:	80 3a       	cpi	r24, 0xA0	; 160
    13dc:	09 f4       	brne	.+2      	; 0x13e0 <__vector_24+0xca>
    13de:	66 c0       	rjmp	.+204    	; 0x14ac <__vector_24+0x196>
    13e0:	88 3a       	cpi	r24, 0xA8	; 168
    13e2:	09 f4       	brne	.+2      	; 0x13e6 <__vector_24+0xd0>
    13e4:	7f c0       	rjmp	.+254    	; 0x14e4 <__vector_24+0x1ce>
    13e6:	b4 c0       	rjmp	.+360    	; 0x1550 <__vector_24+0x23a>
    13e8:	80 3c       	cpi	r24, 0xC0	; 192
    13ea:	09 f4       	brne	.+2      	; 0x13ee <__vector_24+0xd8>
    13ec:	a7 c0       	rjmp	.+334    	; 0x153c <__vector_24+0x226>
    13ee:	88 3c       	cpi	r24, 0xC8	; 200
    13f0:	09 f4       	brne	.+2      	; 0x13f4 <__vector_24+0xde>
    13f2:	a4 c0       	rjmp	.+328    	; 0x153c <__vector_24+0x226>
    13f4:	88 3b       	cpi	r24, 0xB8	; 184
    13f6:	09 f4       	brne	.+2      	; 0x13fa <__vector_24+0xe4>
    13f8:	8a c0       	rjmp	.+276    	; 0x150e <__vector_24+0x1f8>
    13fa:	aa c0       	rjmp	.+340    	; 0x1550 <__vector_24+0x23a>
    13fc:	80 91 c4 03 	lds	r24, 0x03C4	; 0x8003c4 <twi_slarw.lto_priv.187>
    1400:	10 c0       	rjmp	.+32     	; 0x1422 <__vector_24+0x10c>
    1402:	90 91 c3 03 	lds	r25, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    1406:	80 91 c2 03 	lds	r24, 0x03C2	; 0x8003c2 <twi_masterBufferLength.lto_priv.185>
    140a:	98 17       	cp	r25, r24
    140c:	70 f5       	brcc	.+92     	; 0x146a <__vector_24+0x154>
    140e:	e0 91 c3 03 	lds	r30, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    1412:	81 e0       	ldi	r24, 0x01	; 1
    1414:	8e 0f       	add	r24, r30
    1416:	80 93 c3 03 	sts	0x03C3, r24	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    141a:	f0 e0       	ldi	r31, 0x00	; 0
    141c:	ee 55       	subi	r30, 0x5E	; 94
    141e:	fc 4f       	sbci	r31, 0xFC	; 252
    1420:	80 81       	ld	r24, Z
    1422:	80 93 bb 00 	sts	0x00BB, r24	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
    1426:	85 ec       	ldi	r24, 0xC5	; 197
    1428:	86 c0       	rjmp	.+268    	; 0x1536 <__vector_24+0x220>
    142a:	80 93 9e 03 	sts	0x039E, r24	; 0x80039e <twi_error.lto_priv.183>
    142e:	8e c0       	rjmp	.+284    	; 0x154c <__vector_24+0x236>
    1430:	e0 91 c3 03 	lds	r30, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    1434:	81 e0       	ldi	r24, 0x01	; 1
    1436:	8e 0f       	add	r24, r30
    1438:	80 93 c3 03 	sts	0x03C3, r24	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    143c:	80 91 bb 00 	lds	r24, 0x00BB	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
    1440:	f0 e0       	ldi	r31, 0x00	; 0
    1442:	ee 55       	subi	r30, 0x5E	; 94
    1444:	fc 4f       	sbci	r31, 0xFC	; 252
    1446:	80 83       	st	Z, r24
    1448:	90 91 c3 03 	lds	r25, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    144c:	80 91 c2 03 	lds	r24, 0x03C2	; 0x8003c2 <twi_masterBufferLength.lto_priv.185>
    1450:	6e c0       	rjmp	.+220    	; 0x152e <__vector_24+0x218>
    1452:	e0 91 c3 03 	lds	r30, 0x03C3	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    1456:	81 e0       	ldi	r24, 0x01	; 1
    1458:	8e 0f       	add	r24, r30
    145a:	80 93 c3 03 	sts	0x03C3, r24	; 0x8003c3 <twi_masterBufferIndex.lto_priv.184>
    145e:	80 91 bb 00 	lds	r24, 0x00BB	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
    1462:	f0 e0       	ldi	r31, 0x00	; 0
    1464:	ee 55       	subi	r30, 0x5E	; 94
    1466:	fc 4f       	sbci	r31, 0xFC	; 252
    1468:	80 83       	st	Z, r24
    146a:	80 91 a1 03 	lds	r24, 0x03A1	; 0x8003a1 <twi_sendStop.lto_priv.182>
    146e:	81 11       	cpse	r24, r1
    1470:	6d c0       	rjmp	.+218    	; 0x154c <__vector_24+0x236>
    1472:	81 e0       	ldi	r24, 0x01	; 1
    1474:	80 93 a0 03 	sts	0x03A0, r24	; 0x8003a0 <twi_inRepStart.lto_priv.188>
    1478:	84 ea       	ldi	r24, 0xA4	; 164
    147a:	61 c0       	rjmp	.+194    	; 0x153e <__vector_24+0x228>
    147c:	83 e0       	ldi	r24, 0x03	; 3
    147e:	80 93 9f 03 	sts	0x039F, r24	; 0x80039f <twi_state.lto_priv.181>
    1482:	10 92 0b 04 	sts	0x040B, r1	; 0x80040b <twi_rxBufferIndex>
    1486:	cf cf       	rjmp	.-98     	; 0x1426 <__vector_24+0x110>
    1488:	80 91 0b 04 	lds	r24, 0x040B	; 0x80040b <twi_rxBufferIndex>
    148c:	80 32       	cpi	r24, 0x20	; 32
    148e:	08 f0       	brcs	.+2      	; 0x1492 <__vector_24+0x17c>
    1490:	51 c0       	rjmp	.+162    	; 0x1534 <__vector_24+0x21e>
    1492:	e0 91 0b 04 	lds	r30, 0x040B	; 0x80040b <twi_rxBufferIndex>
    1496:	81 e0       	ldi	r24, 0x01	; 1
    1498:	8e 0f       	add	r24, r30
    149a:	80 93 0b 04 	sts	0x040B, r24	; 0x80040b <twi_rxBufferIndex>
    149e:	80 91 bb 00 	lds	r24, 0x00BB	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
    14a2:	f0 e0       	ldi	r31, 0x00	; 0
    14a4:	e5 51       	subi	r30, 0x15	; 21
    14a6:	fc 4f       	sbci	r31, 0xFC	; 252
    14a8:	80 83       	st	Z, r24
    14aa:	bd cf       	rjmp	.-134    	; 0x1426 <__vector_24+0x110>
    14ac:	85 ec       	ldi	r24, 0xC5	; 197
    14ae:	80 93 bc 00 	sts	0x00BC, r24	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
    14b2:	10 92 9f 03 	sts	0x039F, r1	; 0x80039f <twi_state.lto_priv.181>
    14b6:	80 91 0b 04 	lds	r24, 0x040B	; 0x80040b <twi_rxBufferIndex>
    14ba:	80 32       	cpi	r24, 0x20	; 32
    14bc:	30 f4       	brcc	.+12     	; 0x14ca <__vector_24+0x1b4>
    14be:	e0 91 0b 04 	lds	r30, 0x040B	; 0x80040b <twi_rxBufferIndex>
    14c2:	f0 e0       	ldi	r31, 0x00	; 0
    14c4:	e5 51       	subi	r30, 0x15	; 21
    14c6:	fc 4f       	sbci	r31, 0xFC	; 252
    14c8:	10 82       	st	Z, r1
    14ca:	60 91 0b 04 	lds	r22, 0x040B	; 0x80040b <twi_rxBufferIndex>
    14ce:	70 e0       	ldi	r23, 0x00	; 0
    14d0:	e0 91 9c 03 	lds	r30, 0x039C	; 0x80039c <twi_onSlaveReceive.lto_priv.190>
    14d4:	f0 91 9d 03 	lds	r31, 0x039D	; 0x80039d <twi_onSlaveReceive.lto_priv.190+0x1>
    14d8:	8b ee       	ldi	r24, 0xEB	; 235
    14da:	93 e0       	ldi	r25, 0x03	; 3
    14dc:	09 95       	icall
    14de:	10 92 0b 04 	sts	0x040B, r1	; 0x80040b <twi_rxBufferIndex>
    14e2:	36 c0       	rjmp	.+108    	; 0x1550 <__vector_24+0x23a>
    14e4:	84 e0       	ldi	r24, 0x04	; 4
    14e6:	80 93 9f 03 	sts	0x039F, r24	; 0x80039f <twi_state.lto_priv.181>
    14ea:	10 92 ea 03 	sts	0x03EA, r1	; 0x8003ea <twi_txBufferIndex>
    14ee:	10 92 e9 03 	sts	0x03E9, r1	; 0x8003e9 <twi_txBufferLength>
    14f2:	e0 91 9a 03 	lds	r30, 0x039A	; 0x80039a <twi_onSlaveTransmit.lto_priv.189>
    14f6:	f0 91 9b 03 	lds	r31, 0x039B	; 0x80039b <twi_onSlaveTransmit.lto_priv.189+0x1>
    14fa:	09 95       	icall
    14fc:	80 91 e9 03 	lds	r24, 0x03E9	; 0x8003e9 <twi_txBufferLength>
    1500:	81 11       	cpse	r24, r1
    1502:	05 c0       	rjmp	.+10     	; 0x150e <__vector_24+0x1f8>
    1504:	81 e0       	ldi	r24, 0x01	; 1
    1506:	80 93 e9 03 	sts	0x03E9, r24	; 0x8003e9 <twi_txBufferLength>
    150a:	10 92 c9 03 	sts	0x03C9, r1	; 0x8003c9 <twi_txBuffer>
    150e:	e0 91 ea 03 	lds	r30, 0x03EA	; 0x8003ea <twi_txBufferIndex>
    1512:	81 e0       	ldi	r24, 0x01	; 1
    1514:	8e 0f       	add	r24, r30
    1516:	80 93 ea 03 	sts	0x03EA, r24	; 0x8003ea <twi_txBufferIndex>
    151a:	f0 e0       	ldi	r31, 0x00	; 0
    151c:	e7 53       	subi	r30, 0x37	; 55
    151e:	fc 4f       	sbci	r31, 0xFC	; 252
    1520:	80 81       	ld	r24, Z
    1522:	80 93 bb 00 	sts	0x00BB, r24	; 0x8000bb <__TEXT_REGION_LENGTH__+0x7e00bb>
    1526:	90 91 ea 03 	lds	r25, 0x03EA	; 0x8003ea <twi_txBufferIndex>
    152a:	80 91 e9 03 	lds	r24, 0x03E9	; 0x8003e9 <twi_txBufferLength>
    152e:	98 17       	cp	r25, r24
    1530:	08 f4       	brcc	.+2      	; 0x1534 <__vector_24+0x21e>
    1532:	79 cf       	rjmp	.-270    	; 0x1426 <__vector_24+0x110>
    1534:	85 e8       	ldi	r24, 0x85	; 133
    1536:	80 93 bc 00 	sts	0x00BC, r24	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
    153a:	0a c0       	rjmp	.+20     	; 0x1550 <__vector_24+0x23a>
    153c:	85 ec       	ldi	r24, 0xC5	; 197
    153e:	80 93 bc 00 	sts	0x00BC, r24	; 0x8000bc <__TEXT_REGION_LENGTH__+0x7e00bc>
    1542:	10 92 9f 03 	sts	0x039F, r1	; 0x80039f <twi_state.lto_priv.181>
    1546:	04 c0       	rjmp	.+8      	; 0x1550 <__vector_24+0x23a>
    1548:	10 92 9e 03 	sts	0x039E, r1	; 0x80039e <twi_error.lto_priv.183>
    154c:	0e 94 51 08 	call	0x10a2	; 0x10a2 <twi_stop>
    1550:	ff 91       	pop	r31
    1552:	ef 91       	pop	r30
    1554:	bf 91       	pop	r27
    1556:	af 91       	pop	r26
    1558:	9f 91       	pop	r25
    155a:	8f 91       	pop	r24
    155c:	7f 91       	pop	r23
    155e:	6f 91       	pop	r22
    1560:	5f 91       	pop	r21
    1562:	4f 91       	pop	r20
    1564:	3f 91       	pop	r19
    1566:	2f 91       	pop	r18
    1568:	0f 90       	pop	r0
    156a:	0f be       	out	0x3f, r0	; 63
    156c:	0f 90       	pop	r0
    156e:	1f 90       	pop	r1
    1570:	18 95       	reti

00001572 <_ZN13LiquidCrystal10write4bitsEh>:
    1572:	cf 92       	push	r12
    1574:	df 92       	push	r13
    1576:	ef 92       	push	r14
    1578:	ff 92       	push	r15
    157a:	0f 93       	push	r16
    157c:	1f 93       	push	r17
    157e:	cf 93       	push	r28
    1580:	df 93       	push	r29
    1582:	6c 01       	movw	r12, r24
    1584:	7c 01       	movw	r14, r24
    1586:	87 e0       	ldi	r24, 0x07	; 7
    1588:	e8 0e       	add	r14, r24
    158a:	f1 1c       	adc	r15, r1
    158c:	c0 e0       	ldi	r28, 0x00	; 0
    158e:	d0 e0       	ldi	r29, 0x00	; 0
    1590:	06 2f       	mov	r16, r22
    1592:	10 e0       	ldi	r17, 0x00	; 0
    1594:	b8 01       	movw	r22, r16
    1596:	0c 2e       	mov	r0, r28
    1598:	02 c0       	rjmp	.+4      	; 0x159e <_ZN13LiquidCrystal10write4bitsEh+0x2c>
    159a:	75 95       	asr	r23
    159c:	67 95       	ror	r22
    159e:	0a 94       	dec	r0
    15a0:	e2 f7       	brpl	.-8      	; 0x159a <_ZN13LiquidCrystal10write4bitsEh+0x28>
    15a2:	61 70       	andi	r22, 0x01	; 1
    15a4:	f7 01       	movw	r30, r14
    15a6:	81 91       	ld	r24, Z+
    15a8:	7f 01       	movw	r14, r30
    15aa:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    15ae:	21 96       	adiw	r28, 0x01	; 1
    15b0:	c4 30       	cpi	r28, 0x04	; 4
    15b2:	d1 05       	cpc	r29, r1
    15b4:	79 f7       	brne	.-34     	; 0x1594 <_ZN13LiquidCrystal10write4bitsEh+0x22>
    15b6:	c6 01       	movw	r24, r12
    15b8:	df 91       	pop	r29
    15ba:	cf 91       	pop	r28
    15bc:	1f 91       	pop	r17
    15be:	0f 91       	pop	r16
    15c0:	ff 90       	pop	r15
    15c2:	ef 90       	pop	r14
    15c4:	df 90       	pop	r13
    15c6:	cf 90       	pop	r12
    15c8:	0c 94 25 09 	jmp	0x124a	; 0x124a <_ZN13LiquidCrystal11pulseEnableEv>

000015cc <_ZN13LiquidCrystal4sendEhh>:
    15cc:	cf 92       	push	r12
    15ce:	df 92       	push	r13
    15d0:	ef 92       	push	r14
    15d2:	ff 92       	push	r15
    15d4:	0f 93       	push	r16
    15d6:	1f 93       	push	r17
    15d8:	cf 93       	push	r28
    15da:	df 93       	push	r29
    15dc:	ec 01       	movw	r28, r24
    15de:	f6 2e       	mov	r15, r22
    15e0:	64 2f       	mov	r22, r20
    15e2:	8c 81       	ldd	r24, Y+4	; 0x04
    15e4:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    15e8:	8d 81       	ldd	r24, Y+5	; 0x05
    15ea:	8f 3f       	cpi	r24, 0xFF	; 255
    15ec:	19 f0       	breq	.+6      	; 0x15f4 <_ZN13LiquidCrystal4sendEhh+0x28>
    15ee:	60 e0       	ldi	r22, 0x00	; 0
    15f0:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    15f4:	8f 85       	ldd	r24, Y+15	; 0x0f
    15f6:	0f 2d       	mov	r16, r15
    15f8:	10 e0       	ldi	r17, 0x00	; 0
    15fa:	84 ff       	sbrs	r24, 4
    15fc:	25 c0       	rjmp	.+74     	; 0x1648 <_ZN13LiquidCrystal4sendEhh+0x7c>
    15fe:	6e 01       	movw	r12, r28
    1600:	87 e0       	ldi	r24, 0x07	; 7
    1602:	c8 0e       	add	r12, r24
    1604:	d1 1c       	adc	r13, r1
    1606:	e1 2c       	mov	r14, r1
    1608:	f1 2c       	mov	r15, r1
    160a:	b8 01       	movw	r22, r16
    160c:	0e 2c       	mov	r0, r14
    160e:	02 c0       	rjmp	.+4      	; 0x1614 <_ZN13LiquidCrystal4sendEhh+0x48>
    1610:	75 95       	asr	r23
    1612:	67 95       	ror	r22
    1614:	0a 94       	dec	r0
    1616:	e2 f7       	brpl	.-8      	; 0x1610 <_ZN13LiquidCrystal4sendEhh+0x44>
    1618:	61 70       	andi	r22, 0x01	; 1
    161a:	f6 01       	movw	r30, r12
    161c:	81 91       	ld	r24, Z+
    161e:	6f 01       	movw	r12, r30
    1620:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1624:	ff ef       	ldi	r31, 0xFF	; 255
    1626:	ef 1a       	sub	r14, r31
    1628:	ff 0a       	sbc	r15, r31
    162a:	88 e0       	ldi	r24, 0x08	; 8
    162c:	e8 16       	cp	r14, r24
    162e:	f1 04       	cpc	r15, r1
    1630:	61 f7       	brne	.-40     	; 0x160a <_ZN13LiquidCrystal4sendEhh+0x3e>
    1632:	ce 01       	movw	r24, r28
    1634:	df 91       	pop	r29
    1636:	cf 91       	pop	r28
    1638:	1f 91       	pop	r17
    163a:	0f 91       	pop	r16
    163c:	ff 90       	pop	r15
    163e:	ef 90       	pop	r14
    1640:	df 90       	pop	r13
    1642:	cf 90       	pop	r12
    1644:	0c 94 25 09 	jmp	0x124a	; 0x124a <_ZN13LiquidCrystal11pulseEnableEv>
    1648:	b8 01       	movw	r22, r16
    164a:	84 e0       	ldi	r24, 0x04	; 4
    164c:	75 95       	asr	r23
    164e:	67 95       	ror	r22
    1650:	8a 95       	dec	r24
    1652:	e1 f7       	brne	.-8      	; 0x164c <_ZN13LiquidCrystal4sendEhh+0x80>
    1654:	ce 01       	movw	r24, r28
    1656:	0e 94 b9 0a 	call	0x1572	; 0x1572 <_ZN13LiquidCrystal10write4bitsEh>
    165a:	6f 2d       	mov	r22, r15
    165c:	ce 01       	movw	r24, r28
    165e:	df 91       	pop	r29
    1660:	cf 91       	pop	r28
    1662:	1f 91       	pop	r17
    1664:	0f 91       	pop	r16
    1666:	ff 90       	pop	r15
    1668:	ef 90       	pop	r14
    166a:	df 90       	pop	r13
    166c:	cf 90       	pop	r12
    166e:	0c 94 b9 0a 	jmp	0x1572	; 0x1572 <_ZN13LiquidCrystal10write4bitsEh>

00001672 <_ZN13LiquidCrystal5writeEh>:
    1672:	41 e0       	ldi	r20, 0x01	; 1
    1674:	0e 94 e6 0a 	call	0x15cc	; 0x15cc <_ZN13LiquidCrystal4sendEhh>
    1678:	81 e0       	ldi	r24, 0x01	; 1
    167a:	90 e0       	ldi	r25, 0x00	; 0
    167c:	08 95       	ret

0000167e <_ZN5TrackD1Ev>:
    167e:	08 95       	ret

00001680 <__vector_7>:
    1680:	1f 92       	push	r1
    1682:	0f 92       	push	r0
    1684:	0f b6       	in	r0, 0x3f	; 63
    1686:	0f 92       	push	r0
    1688:	11 24       	eor	r1, r1
    168a:	0f 93       	push	r16
    168c:	1f 93       	push	r17
    168e:	2f 93       	push	r18
    1690:	3f 93       	push	r19
    1692:	4f 93       	push	r20
    1694:	5f 93       	push	r21
    1696:	6f 93       	push	r22
    1698:	7f 93       	push	r23
    169a:	8f 93       	push	r24
    169c:	9f 93       	push	r25
    169e:	af 93       	push	r26
    16a0:	bf 93       	push	r27
    16a2:	cf 93       	push	r28
    16a4:	df 93       	push	r29
    16a6:	ef 93       	push	r30
    16a8:	ff 93       	push	r31
    16aa:	80 91 c7 03 	lds	r24, 0x03C7	; 0x8003c7 <_ZZ10__vector_7E2ix>
    16ae:	90 91 c8 03 	lds	r25, 0x03C8	; 0x8003c8 <_ZZ10__vector_7E2ix+0x1>
    16b2:	9c 01       	movw	r18, r24
    16b4:	2f 5f       	subi	r18, 0xFF	; 255
    16b6:	3f 4f       	sbci	r19, 0xFF	; 255
    16b8:	30 93 c8 03 	sts	0x03C8, r19	; 0x8003c8 <_ZZ10__vector_7E2ix+0x1>
    16bc:	20 93 c7 03 	sts	0x03C7, r18	; 0x8003c7 <_ZZ10__vector_7E2ix>
    16c0:	81 11       	cpse	r24, r1
    16c2:	59 c0       	rjmp	.+178    	; 0x1776 <__vector_7+0xf6>
    16c4:	95 b1       	in	r25, 0x05	; 5
    16c6:	80 e2       	ldi	r24, 0x20	; 32
    16c8:	89 27       	eor	r24, r25
    16ca:	85 b9       	out	0x05, r24	; 5
    16cc:	c0 91 64 04 	lds	r28, 0x0464	; 0x800464 <_ZN11Application6timer1E+0x3>
    16d0:	60 91 63 04 	lds	r22, 0x0463	; 0x800463 <_ZN11Application6timer1E+0x2>
    16d4:	2f b7       	in	r18, 0x3f	; 63
    16d6:	f8 94       	cli
    16d8:	80 91 0d 04 	lds	r24, 0x040D	; 0x80040d <timer0_millis>
    16dc:	90 91 0e 04 	lds	r25, 0x040E	; 0x80040e <timer0_millis+0x1>
    16e0:	a0 91 0f 04 	lds	r26, 0x040F	; 0x80040f <timer0_millis+0x2>
    16e4:	b0 91 10 04 	lds	r27, 0x0410	; 0x800410 <timer0_millis+0x3>
    16e8:	2f bf       	out	0x3f, r18	; 63
    16ea:	20 91 6e 04 	lds	r18, 0x046E	; 0x80046e <_ZN11Application6eepromE+0x4>
    16ee:	22 23       	and	r18, r18
    16f0:	09 f4       	brne	.+2      	; 0x16f4 <__vector_7+0x74>
    16f2:	41 c0       	rjmp	.+130    	; 0x1776 <__vector_7+0xf6>
    16f4:	00 91 6f 04 	lds	r16, 0x046F	; 0x80046f <_ZN11Application6eepromE+0x5>
    16f8:	10 91 70 04 	lds	r17, 0x0470	; 0x800470 <_ZN11Application6eepromE+0x6>
    16fc:	20 91 71 04 	lds	r18, 0x0471	; 0x800471 <_ZN11Application6eepromE+0x7>
    1700:	30 91 72 04 	lds	r19, 0x0472	; 0x800472 <_ZN11Application6eepromE+0x8>
    1704:	10 92 6e 04 	sts	0x046E, r1	; 0x80046e <_ZN11Application6eepromE+0x4>
    1708:	80 1b       	sub	r24, r16
    170a:	91 0b       	sbc	r25, r17
    170c:	a2 0b       	sbc	r26, r18
    170e:	b3 0b       	sbc	r27, r19
    1710:	88 39       	cpi	r24, 0x98	; 152
    1712:	9a 43       	sbci	r25, 0x3A	; 58
    1714:	a1 05       	cpc	r26, r1
    1716:	b1 05       	cpc	r27, r1
    1718:	20 f4       	brcc	.+8      	; 0x1722 <__vector_7+0xa2>
    171a:	81 e0       	ldi	r24, 0x01	; 1
    171c:	80 93 6e 04 	sts	0x046E, r24	; 0x80046e <_ZN11Application6eepromE+0x4>
    1720:	2a c0       	rjmp	.+84     	; 0x1776 <__vector_7+0xf6>
    1722:	83 e0       	ldi	r24, 0x03	; 3
    1724:	90 e0       	ldi	r25, 0x00	; 0
    1726:	0e 94 1d 08 	call	0x103a	; 0x103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>
    172a:	6c 2f       	mov	r22, r28
    172c:	84 e0       	ldi	r24, 0x04	; 4
    172e:	90 e0       	ldi	r25, 0x00	; 0
    1730:	0e 94 1d 08 	call	0x103a	; 0x103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>
    1734:	c3 e7       	ldi	r28, 0x73	; 115
    1736:	d4 e0       	ldi	r29, 0x04	; 4
    1738:	05 e0       	ldi	r16, 0x05	; 5
    173a:	10 e0       	ldi	r17, 0x00	; 0
    173c:	8e 81       	ldd	r24, Y+6	; 0x06
    173e:	88 23       	and	r24, r24
    1740:	a1 f0       	breq	.+40     	; 0x176a <__vector_7+0xea>
    1742:	1e 82       	std	Y+6, r1	; 0x06
    1744:	6f 81       	ldd	r22, Y+7	; 0x07
    1746:	c8 01       	movw	r24, r16
    1748:	0e 94 1d 08 	call	0x103a	; 0x103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>
    174c:	68 85       	ldd	r22, Y+8	; 0x08
    174e:	c8 01       	movw	r24, r16
    1750:	01 96       	adiw	r24, 0x01	; 1
    1752:	0e 94 1d 08 	call	0x103a	; 0x103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>
    1756:	69 85       	ldd	r22, Y+9	; 0x09
    1758:	c8 01       	movw	r24, r16
    175a:	02 96       	adiw	r24, 0x02	; 2
    175c:	0e 94 1d 08 	call	0x103a	; 0x103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>
    1760:	6a 85       	ldd	r22, Y+10	; 0x0a
    1762:	c8 01       	movw	r24, r16
    1764:	03 96       	adiw	r24, 0x03	; 3
    1766:	0e 94 1d 08 	call	0x103a	; 0x103a <_ZN11EEPROMClass5writeEih.isra.1.lto_priv.179>
    176a:	0c 5f       	subi	r16, 0xFC	; 252
    176c:	1f 4f       	sbci	r17, 0xFF	; 255
    176e:	29 96       	adiw	r28, 0x09	; 9
    1770:	01 31       	cpi	r16, 0x11	; 17
    1772:	11 05       	cpc	r17, r1
    1774:	19 f7       	brne	.-58     	; 0x173c <__vector_7+0xbc>
    1776:	82 e9       	ldi	r24, 0x92	; 146
    1778:	94 e0       	ldi	r25, 0x04	; 4
    177a:	0e 94 d7 02 	call	0x5ae	; 0x5ae <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE9impl_pollEv>
    177e:	c1 e0       	ldi	r28, 0x01	; 1
    1780:	19 e0       	ldi	r17, 0x09	; 9
    1782:	82 e9       	ldi	r24, 0x92	; 146
    1784:	94 e0       	ldi	r25, 0x04	; 4
    1786:	0e 94 cf 02 	call	0x59e	; 0x59e <_ZN17EventSourceI5EventE13dequeue_eventEv>
    178a:	d8 2f       	mov	r29, r24
    178c:	9b 01       	movw	r18, r22
    178e:	6c 30       	cpi	r22, 0x0C	; 12
    1790:	71 05       	cpc	r23, r1
    1792:	09 f4       	brne	.+2      	; 0x1796 <__vector_7+0x116>
    1794:	4e c0       	rjmp	.+156    	; 0x1832 <__vector_7+0x1b2>
    1796:	68 30       	cpi	r22, 0x08	; 8
    1798:	71 05       	cpc	r23, r1
    179a:	cc f4       	brge	.+50     	; 0x17ce <__vector_7+0x14e>
    179c:	40 91 90 04 	lds	r20, 0x0490	; 0x800490 <_ZN11Application7_tracksE+0x1d>
    17a0:	50 91 91 04 	lds	r21, 0x0491	; 0x800491 <_ZN11Application7_tracksE+0x1e>
    17a4:	14 9f       	mul	r17, r20
    17a6:	c0 01       	movw	r24, r0
    17a8:	15 9f       	mul	r17, r21
    17aa:	90 0d       	add	r25, r0
    17ac:	11 24       	eor	r1, r1
    17ae:	22 0f       	add	r18, r18
    17b0:	33 1f       	adc	r19, r19
    17b2:	f9 01       	movw	r30, r18
    17b4:	ef 5f       	subi	r30, 0xFF	; 255
    17b6:	fe 4f       	sbci	r31, 0xFE	; 254
    17b8:	01 90       	ld	r0, Z+
    17ba:	f0 81       	ld	r31, Z
    17bc:	e0 2d       	mov	r30, r0
    17be:	8b 58       	subi	r24, 0x8B	; 139
    17c0:	9b 4f       	sbci	r25, 0xFB	; 251
    17c2:	09 95       	icall
    17c4:	c0 93 4a 04 	sts	0x044A, r28	; 0x80044a <_ZN11Application7ui_dataE+0x11>
    17c8:	c0 93 4d 04 	sts	0x044D, r28	; 0x80044d <_ZN11Application7ui_dataE+0x14>
    17cc:	2d c0       	rjmp	.+90     	; 0x1828 <__vector_7+0x1a8>
    17ce:	6a 30       	cpi	r22, 0x0A	; 10
    17d0:	71 05       	cpc	r23, r1
    17d2:	79 f0       	breq	.+30     	; 0x17f2 <__vector_7+0x172>
    17d4:	6b 30       	cpi	r22, 0x0B	; 11
    17d6:	71 05       	cpc	r23, r1
    17d8:	61 f5       	brne	.+88     	; 0x1832 <__vector_7+0x1b2>
    17da:	80 91 64 04 	lds	r24, 0x0464	; 0x800464 <_ZN11Application6timer1E+0x3>
    17de:	8c 27       	eor	r24, r28
    17e0:	0e 94 48 0c 	call	0x1890	; 0x1890 <_ZN7Timer1_18set_playback_stateEb.constprop.81>
    17e4:	c0 93 50 04 	sts	0x0450, r28	; 0x800450 <_ZN11Application7ui_dataE+0x17>
    17e8:	0e 94 5e 03 	call	0x6bc	; 0x6bc <_ZN11Application16flag_main_screenEv>
    17ec:	0e 94 34 0c 	call	0x1868	; 0x1868 <_ZN6Eeprom19flag_save_requestedEv.constprop.82>
    17f0:	1b c0       	rjmp	.+54     	; 0x1828 <__vector_7+0x1a8>
    17f2:	80 93 63 04 	sts	0x0463, r24	; 0x800463 <_ZN11Application6timer1E+0x2>
    17f6:	68 2f       	mov	r22, r24
    17f8:	70 e0       	ldi	r23, 0x00	; 0
    17fa:	80 e0       	ldi	r24, 0x00	; 0
    17fc:	90 e0       	ldi	r25, 0x00	; 0
    17fe:	0e 94 be 18 	call	0x317c	; 0x317c <__floatsisf>
    1802:	20 e0       	ldi	r18, 0x00	; 0
    1804:	30 e0       	ldi	r19, 0x00	; 0
    1806:	40 e7       	ldi	r20, 0x70	; 112
    1808:	52 e4       	ldi	r21, 0x42	; 66
    180a:	0e 94 1b 18 	call	0x3036	; 0x3036 <__divsf3>
    180e:	60 93 66 04 	sts	0x0466, r22	; 0x800466 <_ZN11Application6timer1E+0x5>
    1812:	70 93 67 04 	sts	0x0467, r23	; 0x800467 <_ZN11Application6timer1E+0x6>
    1816:	80 93 68 04 	sts	0x0468, r24	; 0x800468 <_ZN11Application6timer1E+0x7>
    181a:	90 93 69 04 	sts	0x0469, r25	; 0x800469 <_ZN11Application6timer1E+0x8>
    181e:	8d 2f       	mov	r24, r29
    1820:	0e 94 d2 07 	call	0xfa4	; 0xfa4 <_ZN7Timer1_13set_hz_by_bpmEh>
    1824:	c0 93 47 04 	sts	0x0447, r28	; 0x800447 <_ZN11Application7ui_dataE+0xe>
    1828:	0e 94 5e 03 	call	0x6bc	; 0x6bc <_ZN11Application16flag_main_screenEv>
    182c:	0e 94 34 0c 	call	0x1868	; 0x1868 <_ZN6Eeprom19flag_save_requestedEv.constprop.82>
    1830:	a8 cf       	rjmp	.-176    	; 0x1782 <__vector_7+0x102>
    1832:	ff 91       	pop	r31
    1834:	ef 91       	pop	r30
    1836:	df 91       	pop	r29
    1838:	cf 91       	pop	r28
    183a:	bf 91       	pop	r27
    183c:	af 91       	pop	r26
    183e:	9f 91       	pop	r25
    1840:	8f 91       	pop	r24
    1842:	7f 91       	pop	r23
    1844:	6f 91       	pop	r22
    1846:	5f 91       	pop	r21
    1848:	4f 91       	pop	r20
    184a:	3f 91       	pop	r19
    184c:	2f 91       	pop	r18
    184e:	1f 91       	pop	r17
    1850:	0f 91       	pop	r16
    1852:	0f 90       	pop	r0
    1854:	0f be       	out	0x3f, r0	; 63
    1856:	0f 90       	pop	r0
    1858:	1f 90       	pop	r1
    185a:	18 95       	reti

0000185c <_ZN13LiquidCrystal7commandEh.constprop.63>:
    185c:	40 e0       	ldi	r20, 0x00	; 0
    185e:	68 2f       	mov	r22, r24
    1860:	8d e1       	ldi	r24, 0x1D	; 29
    1862:	94 e0       	ldi	r25, 0x04	; 4
    1864:	0c 94 e6 0a 	jmp	0x15cc	; 0x15cc <_ZN13LiquidCrystal4sendEhh>

00001868 <_ZN6Eeprom19flag_save_requestedEv.constprop.82>:
    1868:	ea e6       	ldi	r30, 0x6A	; 106
    186a:	f4 e0       	ldi	r31, 0x04	; 4
    186c:	81 e0       	ldi	r24, 0x01	; 1
    186e:	84 83       	std	Z+4, r24	; 0x04
    1870:	2f b7       	in	r18, 0x3f	; 63
    1872:	f8 94       	cli
    1874:	80 91 0d 04 	lds	r24, 0x040D	; 0x80040d <timer0_millis>
    1878:	90 91 0e 04 	lds	r25, 0x040E	; 0x80040e <timer0_millis+0x1>
    187c:	a0 91 0f 04 	lds	r26, 0x040F	; 0x80040f <timer0_millis+0x2>
    1880:	b0 91 10 04 	lds	r27, 0x0410	; 0x800410 <timer0_millis+0x3>
    1884:	2f bf       	out	0x3f, r18	; 63
    1886:	85 83       	std	Z+5, r24	; 0x05
    1888:	96 83       	std	Z+6, r25	; 0x06
    188a:	a7 83       	std	Z+7, r26	; 0x07
    188c:	b0 87       	std	Z+8, r27	; 0x08
    188e:	08 95       	ret

00001890 <_ZN7Timer1_18set_playback_stateEb.constprop.81>:
    1890:	80 93 64 04 	sts	0x0464, r24	; 0x800464 <_ZN11Application6timer1E+0x3>
    1894:	9f b7       	in	r25, 0x3f	; 63
    1896:	88 23       	and	r24, r24
    1898:	59 f0       	breq	.+22     	; 0x18b0 <_ZN7Timer1_18set_playback_stateEb.constprop.81+0x20>
    189a:	f8 94       	cli
    189c:	80 91 80 00 	lds	r24, 0x0080	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    18a0:	80 64       	ori	r24, 0x40	; 64
    18a2:	80 93 80 00 	sts	0x0080, r24	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    18a6:	10 92 85 00 	sts	0x0085, r1	; 0x800085 <__TEXT_REGION_LENGTH__+0x7e0085>
    18aa:	10 92 84 00 	sts	0x0084, r1	; 0x800084 <__TEXT_REGION_LENGTH__+0x7e0084>
    18ae:	0e c0       	rjmp	.+28     	; 0x18cc <_ZN7Timer1_18set_playback_stateEb.constprop.81+0x3c>
    18b0:	f8 94       	cli
    18b2:	20 91 80 00 	lds	r18, 0x0080	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    18b6:	80 e4       	ldi	r24, 0x40	; 64
    18b8:	82 27       	eor	r24, r18
    18ba:	80 93 80 00 	sts	0x0080, r24	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    18be:	88 b1       	in	r24, 0x08	; 8
    18c0:	80 7f       	andi	r24, 0xF0	; 240
    18c2:	88 b9       	out	0x08, r24	; 8
    18c4:	25 b1       	in	r18, 0x05	; 5
    18c6:	82 e0       	ldi	r24, 0x02	; 2
    18c8:	82 27       	eor	r24, r18
    18ca:	85 b9       	out	0x05, r24	; 5
    18cc:	9f bf       	out	0x3f, r25	; 63
    18ce:	08 95       	ret

000018d0 <_ZN13LiquidCrystal5clearEv.constprop.62>:
    18d0:	81 e0       	ldi	r24, 0x01	; 1
    18d2:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    18d6:	8b e3       	ldi	r24, 0x3B	; 59
    18d8:	9f e1       	ldi	r25, 0x1F	; 31
    18da:	01 97       	sbiw	r24, 0x01	; 1
    18dc:	f1 f7       	brne	.-4      	; 0x18da <_ZN13LiquidCrystal5clearEv.constprop.62+0xa>
    18de:	08 95       	ret

000018e0 <_ZN6ScreenI6UiDataI15TrackCollectionILj3E5TrackEEE5enterEv.constprop.61>:
    18e0:	cf 93       	push	r28
    18e2:	df 93       	push	r29
    18e4:	ec 01       	movw	r28, r24
    18e6:	8c 81       	ldd	r24, Y+4	; 0x04
    18e8:	81 11       	cpse	r24, r1
    18ea:	1c 82       	std	Y+4, r1	; 0x04
    18ec:	0e 94 68 0c 	call	0x18d0	; 0x18d0 <_ZN13LiquidCrystal5clearEv.constprop.62>
    18f0:	e8 81       	ld	r30, Y
    18f2:	f9 81       	ldd	r31, Y+1	; 0x01
    18f4:	06 80       	ldd	r0, Z+6	; 0x06
    18f6:	f7 81       	ldd	r31, Z+7	; 0x07
    18f8:	e0 2d       	mov	r30, r0
    18fa:	ce 01       	movw	r24, r28
    18fc:	df 91       	pop	r29
    18fe:	cf 91       	pop	r28
    1900:	09 94       	ijmp

00001902 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEEC2Eh.constprop.53>:
    1902:	fc 01       	movw	r30, r24
    1904:	8f ee       	ldi	r24, 0xEF	; 239
    1906:	91 e0       	ldi	r25, 0x01	; 1
    1908:	91 83       	std	Z+1, r25	; 0x01
    190a:	80 83       	st	Z, r24
    190c:	88 e0       	ldi	r24, 0x08	; 8
    190e:	84 83       	std	Z+4, r24	; 0x04
    1910:	15 82       	std	Z+5, r1	; 0x05
    1912:	16 82       	std	Z+6, r1	; 0x06
    1914:	17 82       	std	Z+7, r1	; 0x07
    1916:	8f ef       	ldi	r24, 0xFF	; 255
    1918:	80 87       	std	Z+8, r24	; 0x08
    191a:	8d ec       	ldi	r24, 0xCD	; 205
    191c:	91 e0       	ldi	r25, 0x01	; 1
    191e:	93 83       	std	Z+3, r25	; 0x03
    1920:	82 83       	std	Z+2, r24	; 0x02
    1922:	81 ee       	ldi	r24, 0xE1	; 225
    1924:	91 e0       	ldi	r25, 0x01	; 1
    1926:	92 87       	std	Z+10, r25	; 0x0a
    1928:	81 87       	std	Z+9, r24	; 0x09
    192a:	8c e0       	ldi	r24, 0x0C	; 12
    192c:	90 e0       	ldi	r25, 0x00	; 0
    192e:	94 87       	std	Z+12, r25	; 0x0c
    1930:	83 87       	std	Z+11, r24	; 0x0b
    1932:	25 e1       	ldi	r18, 0x15	; 21
    1934:	27 87       	std	Z+15, r18	; 0x0f
    1936:	21 e0       	ldi	r18, 0x01	; 1
    1938:	20 8b       	std	Z+16, r18	; 0x10
    193a:	23 ea       	ldi	r18, 0xA3	; 163
    193c:	31 e0       	ldi	r19, 0x01	; 1
    193e:	36 87       	std	Z+14, r19	; 0x0e
    1940:	25 87       	std	Z+13, r18	; 0x0d
    1942:	21 eb       	ldi	r18, 0xB1	; 177
    1944:	31 e0       	ldi	r19, 0x01	; 1
    1946:	32 8b       	std	Z+18, r19	; 0x12
    1948:	21 8b       	std	Z+17, r18	; 0x11
    194a:	94 8b       	std	Z+20, r25	; 0x14
    194c:	83 8b       	std	Z+19, r24	; 0x13
    194e:	2d e7       	ldi	r18, 0x7D	; 125
    1950:	31 e0       	ldi	r19, 0x01	; 1
    1952:	36 8b       	std	Z+22, r19	; 0x16
    1954:	25 8b       	std	Z+21, r18	; 0x15
    1956:	2d e8       	ldi	r18, 0x8D	; 141
    1958:	31 e0       	ldi	r19, 0x01	; 1
    195a:	30 8f       	std	Z+24, r19	; 0x18
    195c:	27 8b       	std	Z+23, r18	; 0x17
    195e:	64 8f       	std	Z+28, r22	; 0x1c
    1960:	92 8f       	std	Z+26, r25	; 0x1a
    1962:	81 8f       	std	Z+25, r24	; 0x19
    1964:	13 8e       	std	Z+27, r1	; 0x1b
    1966:	15 8e       	std	Z+29, r1	; 0x1d
    1968:	16 8e       	std	Z+30, r1	; 0x1e
    196a:	17 8e       	std	Z+31, r1	; 0x1f
    196c:	08 95       	ret

0000196e <_ZN13LiquidCrystal10createCharEhPh.constprop.38>:
    196e:	0f 93       	push	r16
    1970:	1f 93       	push	r17
    1972:	cf 93       	push	r28
    1974:	df 93       	push	r29
    1976:	8b 01       	movw	r16, r22
    1978:	87 70       	andi	r24, 0x07	; 7
    197a:	28 e0       	ldi	r18, 0x08	; 8
    197c:	82 9f       	mul	r24, r18
    197e:	c0 01       	movw	r24, r0
    1980:	11 24       	eor	r1, r1
    1982:	80 64       	ori	r24, 0x40	; 64
    1984:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    1988:	e8 01       	movw	r28, r16
    198a:	08 5f       	subi	r16, 0xF8	; 248
    198c:	1f 4f       	sbci	r17, 0xFF	; 255
    198e:	69 91       	ld	r22, Y+
    1990:	8d e1       	ldi	r24, 0x1D	; 29
    1992:	94 e0       	ldi	r25, 0x04	; 4
    1994:	0e 94 39 0b 	call	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>
    1998:	c0 17       	cp	r28, r16
    199a:	d1 07       	cpc	r29, r17
    199c:	c1 f7       	brne	.-16     	; 0x198e <_ZN13LiquidCrystal10createCharEhPh.constprop.38+0x20>
    199e:	df 91       	pop	r29
    19a0:	cf 91       	pop	r28
    19a2:	1f 91       	pop	r17
    19a4:	0f 91       	pop	r16
    19a6:	08 95       	ret

000019a8 <_ZN13LiquidCrystal5beginEhhh.constprop.36>:
    19a8:	cf 93       	push	r28
    19aa:	df 93       	push	r29
    19ac:	62 30       	cpi	r22, 0x02	; 2
    19ae:	28 f0       	brcs	.+10     	; 0x19ba <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x12>
    19b0:	90 91 2c 04 	lds	r25, 0x042C	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    19b4:	98 60       	ori	r25, 0x08	; 8
    19b6:	90 93 2c 04 	sts	0x042C, r25	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    19ba:	60 93 30 04 	sts	0x0430, r22	; 0x800430 <_ZN3Lcd3lcdE+0x13>
    19be:	10 92 31 04 	sts	0x0431, r1	; 0x800431 <_ZN3Lcd3lcdE+0x14>
    19c2:	90 e4       	ldi	r25, 0x40	; 64
    19c4:	90 93 32 04 	sts	0x0432, r25	; 0x800432 <_ZN3Lcd3lcdE+0x15>
    19c8:	80 93 33 04 	sts	0x0433, r24	; 0x800433 <_ZN3Lcd3lcdE+0x16>
    19cc:	90 e0       	ldi	r25, 0x00	; 0
    19ce:	80 5c       	subi	r24, 0xC0	; 192
    19d0:	9f 4f       	sbci	r25, 0xFF	; 255
    19d2:	80 93 34 04 	sts	0x0434, r24	; 0x800434 <_ZN3Lcd3lcdE+0x17>
    19d6:	61 e0       	ldi	r22, 0x01	; 1
    19d8:	80 91 21 04 	lds	r24, 0x0421	; 0x800421 <_ZN3Lcd3lcdE+0x4>
    19dc:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
    19e0:	80 91 22 04 	lds	r24, 0x0422	; 0x800422 <_ZN3Lcd3lcdE+0x5>
    19e4:	8f 3f       	cpi	r24, 0xFF	; 255
    19e6:	19 f0       	breq	.+6      	; 0x19ee <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x46>
    19e8:	61 e0       	ldi	r22, 0x01	; 1
    19ea:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
    19ee:	61 e0       	ldi	r22, 0x01	; 1
    19f0:	80 91 23 04 	lds	r24, 0x0423	; 0x800423 <_ZN3Lcd3lcdE+0x6>
    19f4:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
    19f8:	cd e1       	ldi	r28, 0x1D	; 29
    19fa:	d4 e0       	ldi	r29, 0x04	; 4
    19fc:	9e 01       	movw	r18, r28
    19fe:	2d 51       	subi	r18, 0x1D	; 29
    1a00:	34 40       	sbci	r19, 0x04	; 4
    1a02:	80 91 2c 04 	lds	r24, 0x042C	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    1a06:	84 fd       	sbrc	r24, 4
    1a08:	03 c0       	rjmp	.+6      	; 0x1a10 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x68>
    1a0a:	84 e0       	ldi	r24, 0x04	; 4
    1a0c:	90 e0       	ldi	r25, 0x00	; 0
    1a0e:	02 c0       	rjmp	.+4      	; 0x1a14 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x6c>
    1a10:	88 e0       	ldi	r24, 0x08	; 8
    1a12:	90 e0       	ldi	r25, 0x00	; 0
    1a14:	21 96       	adiw	r28, 0x01	; 1
    1a16:	28 17       	cp	r18, r24
    1a18:	39 07       	cpc	r19, r25
    1a1a:	2c f4       	brge	.+10     	; 0x1a26 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x7e>
    1a1c:	61 e0       	ldi	r22, 0x01	; 1
    1a1e:	8e 81       	ldd	r24, Y+6	; 0x06
    1a20:	0e 94 a2 10 	call	0x2144	; 0x2144 <pinMode>
    1a24:	eb cf       	rjmp	.-42     	; 0x19fc <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x54>
    1a26:	8b e3       	ldi	r24, 0x3B	; 59
    1a28:	9d e0       	ldi	r25, 0x0D	; 13
    1a2a:	01 97       	sbiw	r24, 0x01	; 1
    1a2c:	f1 f7       	brne	.-4      	; 0x1a2a <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x82>
    1a2e:	60 e0       	ldi	r22, 0x00	; 0
    1a30:	80 91 21 04 	lds	r24, 0x0421	; 0x800421 <_ZN3Lcd3lcdE+0x4>
    1a34:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1a38:	60 e0       	ldi	r22, 0x00	; 0
    1a3a:	80 91 23 04 	lds	r24, 0x0423	; 0x800423 <_ZN3Lcd3lcdE+0x6>
    1a3e:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1a42:	80 91 22 04 	lds	r24, 0x0422	; 0x800422 <_ZN3Lcd3lcdE+0x5>
    1a46:	8f 3f       	cpi	r24, 0xFF	; 255
    1a48:	19 f0       	breq	.+6      	; 0x1a50 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0xa8>
    1a4a:	60 e0       	ldi	r22, 0x00	; 0
    1a4c:	0e 94 55 10 	call	0x20aa	; 0x20aa <digitalWrite>
    1a50:	80 91 2c 04 	lds	r24, 0x042C	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    1a54:	84 fd       	sbrc	r24, 4
    1a56:	20 c0       	rjmp	.+64     	; 0x1a98 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0xf0>
    1a58:	63 e0       	ldi	r22, 0x03	; 3
    1a5a:	8d e1       	ldi	r24, 0x1D	; 29
    1a5c:	94 e0       	ldi	r25, 0x04	; 4
    1a5e:	0e 94 b9 0a 	call	0x1572	; 0x1572 <_ZN13LiquidCrystal10write4bitsEh>
    1a62:	cb e4       	ldi	r28, 0x4B	; 75
    1a64:	d6 e4       	ldi	r29, 0x46	; 70
    1a66:	ce 01       	movw	r24, r28
    1a68:	01 97       	sbiw	r24, 0x01	; 1
    1a6a:	f1 f7       	brne	.-4      	; 0x1a68 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0xc0>
    1a6c:	63 e0       	ldi	r22, 0x03	; 3
    1a6e:	8d e1       	ldi	r24, 0x1D	; 29
    1a70:	94 e0       	ldi	r25, 0x04	; 4
    1a72:	0e 94 b9 0a 	call	0x1572	; 0x1572 <_ZN13LiquidCrystal10write4bitsEh>
    1a76:	21 97       	sbiw	r28, 0x01	; 1
    1a78:	f1 f7       	brne	.-4      	; 0x1a76 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0xce>
    1a7a:	63 e0       	ldi	r22, 0x03	; 3
    1a7c:	8d e1       	ldi	r24, 0x1D	; 29
    1a7e:	94 e0       	ldi	r25, 0x04	; 4
    1a80:	0e 94 b9 0a 	call	0x1572	; 0x1572 <_ZN13LiquidCrystal10write4bitsEh>
    1a84:	83 e5       	ldi	r24, 0x53	; 83
    1a86:	92 e0       	ldi	r25, 0x02	; 2
    1a88:	01 97       	sbiw	r24, 0x01	; 1
    1a8a:	f1 f7       	brne	.-4      	; 0x1a88 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0xe0>
    1a8c:	62 e0       	ldi	r22, 0x02	; 2
    1a8e:	8d e1       	ldi	r24, 0x1D	; 29
    1a90:	94 e0       	ldi	r25, 0x04	; 4
    1a92:	0e 94 b9 0a 	call	0x1572	; 0x1572 <_ZN13LiquidCrystal10write4bitsEh>
    1a96:	15 c0       	rjmp	.+42     	; 0x1ac2 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x11a>
    1a98:	80 62       	ori	r24, 0x20	; 32
    1a9a:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    1a9e:	8b e4       	ldi	r24, 0x4B	; 75
    1aa0:	96 e4       	ldi	r25, 0x46	; 70
    1aa2:	01 97       	sbiw	r24, 0x01	; 1
    1aa4:	f1 f7       	brne	.-4      	; 0x1aa2 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0xfa>
    1aa6:	80 91 2c 04 	lds	r24, 0x042C	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    1aaa:	80 62       	ori	r24, 0x20	; 32
    1aac:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    1ab0:	83 e5       	ldi	r24, 0x53	; 83
    1ab2:	92 e0       	ldi	r25, 0x02	; 2
    1ab4:	01 97       	sbiw	r24, 0x01	; 1
    1ab6:	f1 f7       	brne	.-4      	; 0x1ab4 <_ZN13LiquidCrystal5beginEhhh.constprop.36+0x10c>
    1ab8:	80 91 2c 04 	lds	r24, 0x042C	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    1abc:	80 62       	ori	r24, 0x20	; 32
    1abe:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    1ac2:	80 91 2c 04 	lds	r24, 0x042C	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    1ac6:	80 62       	ori	r24, 0x20	; 32
    1ac8:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    1acc:	84 e0       	ldi	r24, 0x04	; 4
    1ace:	80 93 2d 04 	sts	0x042D, r24	; 0x80042d <_ZN3Lcd3lcdE+0x10>
    1ad2:	8c e0       	ldi	r24, 0x0C	; 12
    1ad4:	0e 94 2e 0c 	call	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>
    1ad8:	0e 94 68 0c 	call	0x18d0	; 0x18d0 <_ZN13LiquidCrystal5clearEv.constprop.62>
    1adc:	82 e0       	ldi	r24, 0x02	; 2
    1ade:	80 93 2e 04 	sts	0x042E, r24	; 0x80042e <_ZN3Lcd3lcdE+0x11>
    1ae2:	86 e0       	ldi	r24, 0x06	; 6
    1ae4:	df 91       	pop	r29
    1ae6:	cf 91       	pop	r28
    1ae8:	0c 94 2e 0c 	jmp	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>

00001aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>:
    1aec:	64 30       	cpi	r22, 0x04	; 4
    1aee:	08 f0       	brcs	.+2      	; 0x1af2 <_ZN13LiquidCrystal9setCursorEhh.constprop.21+0x6>
    1af0:	63 e0       	ldi	r22, 0x03	; 3
    1af2:	90 91 30 04 	lds	r25, 0x0430	; 0x800430 <_ZN3Lcd3lcdE+0x13>
    1af6:	69 17       	cp	r22, r25
    1af8:	10 f0       	brcs	.+4      	; 0x1afe <_ZN13LiquidCrystal9setCursorEhh.constprop.21+0x12>
    1afa:	6f ef       	ldi	r22, 0xFF	; 255
    1afc:	69 0f       	add	r22, r25
    1afe:	e6 2f       	mov	r30, r22
    1b00:	f0 e0       	ldi	r31, 0x00	; 0
    1b02:	e3 5e       	subi	r30, 0xE3	; 227
    1b04:	fb 4f       	sbci	r31, 0xFB	; 251
    1b06:	94 89       	ldd	r25, Z+20	; 0x14
    1b08:	89 0f       	add	r24, r25
    1b0a:	80 68       	ori	r24, 0x80	; 128
    1b0c:	0c 94 2e 0c 	jmp	0x185c	; 0x185c <_ZN13LiquidCrystal7commandEh.constprop.63>

00001b10 <_ZN5Print5writeEPKc.constprop.18>:
    1b10:	00 97       	sbiw	r24, 0x00	; 0
    1b12:	69 f0       	breq	.+26     	; 0x1b2e <_ZN5Print5writeEPKc.constprop.18+0x1e>
    1b14:	fc 01       	movw	r30, r24
    1b16:	01 90       	ld	r0, Z+
    1b18:	00 20       	and	r0, r0
    1b1a:	e9 f7       	brne	.-6      	; 0x1b16 <_ZN5Print5writeEPKc.constprop.18+0x6>
    1b1c:	31 97       	sbiw	r30, 0x01	; 1
    1b1e:	af 01       	movw	r20, r30
    1b20:	48 1b       	sub	r20, r24
    1b22:	59 0b       	sbc	r21, r25
    1b24:	bc 01       	movw	r22, r24
    1b26:	8d e1       	ldi	r24, 0x1D	; 29
    1b28:	94 e0       	ldi	r25, 0x04	; 4
    1b2a:	0c 94 27 08 	jmp	0x104e	; 0x104e <_ZN5Print5writeEPKhj>
    1b2e:	80 e0       	ldi	r24, 0x00	; 0
    1b30:	90 e0       	ldi	r25, 0x00	; 0
    1b32:	08 95       	ret

00001b34 <micros>:
    1b34:	3f b7       	in	r19, 0x3f	; 63
    1b36:	f8 94       	cli
    1b38:	80 91 cb 04 	lds	r24, 0x04CB	; 0x8004cb <timer0_overflow_count>
    1b3c:	90 91 cc 04 	lds	r25, 0x04CC	; 0x8004cc <timer0_overflow_count+0x1>
    1b40:	a0 91 cd 04 	lds	r26, 0x04CD	; 0x8004cd <timer0_overflow_count+0x2>
    1b44:	b0 91 ce 04 	lds	r27, 0x04CE	; 0x8004ce <timer0_overflow_count+0x3>
    1b48:	26 b5       	in	r18, 0x26	; 38
    1b4a:	a8 9b       	sbis	0x15, 0	; 21
    1b4c:	05 c0       	rjmp	.+10     	; 0x1b58 <micros+0x24>
    1b4e:	2f 3f       	cpi	r18, 0xFF	; 255
    1b50:	19 f0       	breq	.+6      	; 0x1b58 <micros+0x24>
    1b52:	01 96       	adiw	r24, 0x01	; 1
    1b54:	a1 1d       	adc	r26, r1
    1b56:	b1 1d       	adc	r27, r1
    1b58:	3f bf       	out	0x3f, r19	; 63
    1b5a:	ba 2f       	mov	r27, r26
    1b5c:	a9 2f       	mov	r26, r25
    1b5e:	98 2f       	mov	r25, r24
    1b60:	88 27       	eor	r24, r24
    1b62:	82 0f       	add	r24, r18
    1b64:	91 1d       	adc	r25, r1
    1b66:	a1 1d       	adc	r26, r1
    1b68:	b1 1d       	adc	r27, r1
    1b6a:	bc 01       	movw	r22, r24
    1b6c:	cd 01       	movw	r24, r26
    1b6e:	42 e0       	ldi	r20, 0x02	; 2
    1b70:	66 0f       	add	r22, r22
    1b72:	77 1f       	adc	r23, r23
    1b74:	88 1f       	adc	r24, r24
    1b76:	99 1f       	adc	r25, r25
    1b78:	4a 95       	dec	r20
    1b7a:	d1 f7       	brne	.-12     	; 0x1b70 <micros+0x3c>
    1b7c:	08 95       	ret

00001b7e <_ZN5Print11printNumberEmh.constprop.17>:
    1b7e:	8f 92       	push	r8
    1b80:	9f 92       	push	r9
    1b82:	af 92       	push	r10
    1b84:	bf 92       	push	r11
    1b86:	0f 93       	push	r16
    1b88:	1f 93       	push	r17
    1b8a:	cf 93       	push	r28
    1b8c:	df 93       	push	r29
    1b8e:	cd b7       	in	r28, 0x3d	; 61
    1b90:	de b7       	in	r29, 0x3e	; 62
    1b92:	a1 97       	sbiw	r28, 0x21	; 33
    1b94:	0f b6       	in	r0, 0x3f	; 63
    1b96:	f8 94       	cli
    1b98:	de bf       	out	0x3e, r29	; 62
    1b9a:	0f be       	out	0x3f, r0	; 63
    1b9c:	cd bf       	out	0x3d, r28	; 61
    1b9e:	19 a2       	std	Y+33, r1	; 0x21
    1ba0:	42 30       	cpi	r20, 0x02	; 2
    1ba2:	08 f4       	brcc	.+2      	; 0x1ba6 <_ZN5Print11printNumberEmh.constprop.17+0x28>
    1ba4:	4a e0       	ldi	r20, 0x0A	; 10
    1ba6:	8e 01       	movw	r16, r28
    1ba8:	0f 5d       	subi	r16, 0xDF	; 223
    1baa:	1f 4f       	sbci	r17, 0xFF	; 255
    1bac:	84 2e       	mov	r8, r20
    1bae:	91 2c       	mov	r9, r1
    1bb0:	a1 2c       	mov	r10, r1
    1bb2:	b1 2c       	mov	r11, r1
    1bb4:	a5 01       	movw	r20, r10
    1bb6:	94 01       	movw	r18, r8
    1bb8:	0e 94 72 17 	call	0x2ee4	; 0x2ee4 <__udivmodsi4>
    1bbc:	e6 2f       	mov	r30, r22
    1bbe:	b9 01       	movw	r22, r18
    1bc0:	ca 01       	movw	r24, r20
    1bc2:	01 50       	subi	r16, 0x01	; 1
    1bc4:	11 09       	sbc	r17, r1
    1bc6:	ea 30       	cpi	r30, 0x0A	; 10
    1bc8:	14 f4       	brge	.+4      	; 0x1bce <_ZN5Print11printNumberEmh.constprop.17+0x50>
    1bca:	e0 5d       	subi	r30, 0xD0	; 208
    1bcc:	01 c0       	rjmp	.+2      	; 0x1bd0 <_ZN5Print11printNumberEmh.constprop.17+0x52>
    1bce:	e9 5c       	subi	r30, 0xC9	; 201
    1bd0:	d8 01       	movw	r26, r16
    1bd2:	ec 93       	st	X, r30
    1bd4:	23 2b       	or	r18, r19
    1bd6:	24 2b       	or	r18, r20
    1bd8:	25 2b       	or	r18, r21
    1bda:	61 f7       	brne	.-40     	; 0x1bb4 <_ZN5Print11printNumberEmh.constprop.17+0x36>
    1bdc:	c8 01       	movw	r24, r16
    1bde:	0e 94 88 0d 	call	0x1b10	; 0x1b10 <_ZN5Print5writeEPKc.constprop.18>
    1be2:	a1 96       	adiw	r28, 0x21	; 33
    1be4:	0f b6       	in	r0, 0x3f	; 63
    1be6:	f8 94       	cli
    1be8:	de bf       	out	0x3e, r29	; 62
    1bea:	0f be       	out	0x3f, r0	; 63
    1bec:	cd bf       	out	0x3d, r28	; 61
    1bee:	df 91       	pop	r29
    1bf0:	cf 91       	pop	r28
    1bf2:	1f 91       	pop	r17
    1bf4:	0f 91       	pop	r16
    1bf6:	bf 90       	pop	r11
    1bf8:	af 90       	pop	r10
    1bfa:	9f 90       	pop	r9
    1bfc:	8f 90       	pop	r8
    1bfe:	08 95       	ret

00001c00 <_ZN5Print5printEPKc.constprop.5>:
    1c00:	0c 94 88 0d 	jmp	0x1b10	; 0x1b10 <_ZN5Print5writeEPKc.constprop.18>

00001c04 <_ZN6SSMain20draw_channel_numbersEv.constprop.13>:
    1c04:	cf 92       	push	r12
    1c06:	df 92       	push	r13
    1c08:	ef 92       	push	r14
    1c0a:	ff 92       	push	r15
    1c0c:	cf 93       	push	r28
    1c0e:	df 93       	push	r29
    1c10:	ec 01       	movw	r28, r24
    1c12:	c1 2c       	mov	r12, r1
    1c14:	d1 2c       	mov	r13, r1
    1c16:	76 01       	movw	r14, r12
    1c18:	c3 94       	inc	r12
    1c1a:	6c 2d       	mov	r22, r12
    1c1c:	80 e0       	ldi	r24, 0x00	; 0
    1c1e:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1c22:	4a e0       	ldi	r20, 0x0A	; 10
    1c24:	c7 01       	movw	r24, r14
    1c26:	b6 01       	movw	r22, r12
    1c28:	0e 94 bf 0d 	call	0x1b7e	; 0x1b7e <_ZN5Print11printNumberEmh.constprop.17>
    1c2c:	8f ef       	ldi	r24, 0xFF	; 255
    1c2e:	c8 1a       	sub	r12, r24
    1c30:	d8 0a       	sbc	r13, r24
    1c32:	e8 0a       	sbc	r14, r24
    1c34:	f8 0a       	sbc	r15, r24
    1c36:	84 e0       	ldi	r24, 0x04	; 4
    1c38:	c8 16       	cp	r12, r24
    1c3a:	d1 04       	cpc	r13, r1
    1c3c:	e1 04       	cpc	r14, r1
    1c3e:	f1 04       	cpc	r15, r1
    1c40:	61 f7       	brne	.-40     	; 0x1c1a <_ZN6SSMain20draw_channel_numbersEv.constprop.13+0x16>
    1c42:	ed 81       	ldd	r30, Y+5	; 0x05
    1c44:	fe 81       	ldd	r31, Y+6	; 0x06
    1c46:	02 80       	ldd	r0, Z+2	; 0x02
    1c48:	f3 81       	ldd	r31, Z+3	; 0x03
    1c4a:	e0 2d       	mov	r30, r0
    1c4c:	f5 8c       	ldd	r15, Z+29	; 0x1d
    1c4e:	f3 94       	inc	r15
    1c50:	88 e0       	ldi	r24, 0x08	; 8
    1c52:	f8 9e       	mul	r15, r24
    1c54:	b0 01       	movw	r22, r0
    1c56:	11 24       	eor	r1, r1
    1c58:	61 52       	subi	r22, 0x21	; 33
    1c5a:	7d 4f       	sbci	r23, 0xFD	; 253
    1c5c:	80 e0       	ldi	r24, 0x00	; 0
    1c5e:	0e 94 b7 0c 	call	0x196e	; 0x196e <_ZN13LiquidCrystal10createCharEhPh.constprop.38>
    1c62:	6f 2d       	mov	r22, r15
    1c64:	80 e0       	ldi	r24, 0x00	; 0
    1c66:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1c6a:	60 e0       	ldi	r22, 0x00	; 0
    1c6c:	8d e1       	ldi	r24, 0x1D	; 29
    1c6e:	94 e0       	ldi	r25, 0x04	; 4
    1c70:	df 91       	pop	r29
    1c72:	cf 91       	pop	r28
    1c74:	ff 90       	pop	r15
    1c76:	ef 90       	pop	r14
    1c78:	df 90       	pop	r13
    1c7a:	cf 90       	pop	r12
    1c7c:	0c 94 39 0b 	jmp	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>

00001c80 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12>:
    1c80:	0f 93       	push	r16
    1c82:	1f 93       	push	r17
    1c84:	cf 93       	push	r28
    1c86:	df 93       	push	r29
    1c88:	8c 01       	movw	r16, r24
    1c8a:	c0 e0       	ldi	r28, 0x00	; 0
    1c8c:	d0 e0       	ldi	r29, 0x00	; 0
    1c8e:	f8 01       	movw	r30, r16
    1c90:	ec 0f       	add	r30, r28
    1c92:	fd 1f       	adc	r31, r29
    1c94:	64 91       	lpm	r22, Z
    1c96:	66 23       	and	r22, r22
    1c98:	39 f0       	breq	.+14     	; 0x1ca8 <_ZN5Print5printEPK19__FlashStringHelper.constprop.12+0x28>
    1c9a:	41 e0       	ldi	r20, 0x01	; 1
    1c9c:	8d e1       	ldi	r24, 0x1D	; 29
    1c9e:	94 e0       	ldi	r25, 0x04	; 4
    1ca0:	0e 94 e6 0a 	call	0x15cc	; 0x15cc <_ZN13LiquidCrystal4sendEhh>
    1ca4:	21 96       	adiw	r28, 0x01	; 1
    1ca6:	f3 cf       	rjmp	.-26     	; 0x1c8e <_ZN5Print5printEPK19__FlashStringHelper.constprop.12+0xe>
    1ca8:	ce 01       	movw	r24, r28
    1caa:	df 91       	pop	r29
    1cac:	cf 91       	pop	r28
    1cae:	1f 91       	pop	r17
    1cb0:	0f 91       	pop	r16
    1cb2:	08 95       	ret

00001cb4 <_ZN6SSMain16draw_page_numberEv.constprop.6>:
    1cb4:	cf 93       	push	r28
    1cb6:	df 93       	push	r29
    1cb8:	ec 01       	movw	r28, r24
    1cba:	60 e0       	ldi	r22, 0x00	; 0
    1cbc:	82 e1       	ldi	r24, 0x12	; 18
    1cbe:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1cc2:	ed 81       	ldd	r30, Y+5	; 0x05
    1cc4:	fe 81       	ldd	r31, Y+6	; 0x06
    1cc6:	64 81       	ldd	r22, Z+4	; 0x04
    1cc8:	70 e0       	ldi	r23, 0x00	; 0
    1cca:	6f 5f       	subi	r22, 0xFF	; 255
    1ccc:	7f 4f       	sbci	r23, 0xFF	; 255
    1cce:	07 2e       	mov	r0, r23
    1cd0:	00 0c       	add	r0, r0
    1cd2:	88 0b       	sbc	r24, r24
    1cd4:	99 0b       	sbc	r25, r25
    1cd6:	4a e0       	ldi	r20, 0x0A	; 10
    1cd8:	df 91       	pop	r29
    1cda:	cf 91       	pop	r28
    1cdc:	0c 94 bf 0d 	jmp	0x1b7e	; 0x1b7e <_ZN5Print11printNumberEmh.constprop.17>

00001ce0 <_ZN6SSMain10draw_line0Eb.constprop.4>:
    1ce0:	8f 92       	push	r8
    1ce2:	9f 92       	push	r9
    1ce4:	af 92       	push	r10
    1ce6:	bf 92       	push	r11
    1ce8:	cf 92       	push	r12
    1cea:	df 92       	push	r13
    1cec:	ef 92       	push	r14
    1cee:	ff 92       	push	r15
    1cf0:	0f 93       	push	r16
    1cf2:	1f 93       	push	r17
    1cf4:	cf 93       	push	r28
    1cf6:	df 93       	push	r29
    1cf8:	cd b7       	in	r28, 0x3d	; 61
    1cfa:	de b7       	in	r29, 0x3e	; 62
    1cfc:	aa 97       	sbiw	r28, 0x2a	; 42
    1cfe:	0f b6       	in	r0, 0x3f	; 63
    1d00:	f8 94       	cli
    1d02:	de bf       	out	0x3e, r29	; 62
    1d04:	0f be       	out	0x3f, r0	; 63
    1d06:	cd bf       	out	0x3d, r28	; 61
    1d08:	7c 01       	movw	r14, r24
    1d0a:	66 23       	and	r22, r22
    1d0c:	09 f4       	brne	.+2      	; 0x1d10 <_ZN6SSMain10draw_line0Eb.constprop.4+0x30>
    1d0e:	52 c0       	rjmp	.+164    	; 0x1db4 <_ZN6SSMain10draw_line0Eb.constprop.4+0xd4>
    1d10:	60 e0       	ldi	r22, 0x00	; 0
    1d12:	80 e0       	ldi	r24, 0x00	; 0
    1d14:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1d18:	89 e1       	ldi	r24, 0x19	; 25
    1d1a:	93 e0       	ldi	r25, 0x03	; 3
    1d1c:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1d20:	60 e0       	ldi	r22, 0x00	; 0
    1d22:	80 e0       	ldi	r24, 0x00	; 0
    1d24:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1d28:	d7 01       	movw	r26, r14
    1d2a:	15 96       	adiw	r26, 0x05	; 5
    1d2c:	ed 91       	ld	r30, X+
    1d2e:	fc 91       	ld	r31, X
    1d30:	16 97       	sbiw	r26, 0x06	; 6
    1d32:	85 81       	ldd	r24, Z+5	; 0x05
    1d34:	1f 92       	push	r1
    1d36:	8f 93       	push	r24
    1d38:	8c e2       	ldi	r24, 0x2C	; 44
    1d3a:	93 e0       	ldi	r25, 0x03	; 3
    1d3c:	9f 93       	push	r25
    1d3e:	8f 93       	push	r24
    1d40:	1f 92       	push	r1
    1d42:	35 e1       	ldi	r19, 0x15	; 21
    1d44:	b3 2e       	mov	r11, r19
    1d46:	bf 92       	push	r11
    1d48:	6e 01       	movw	r12, r28
    1d4a:	b6 e1       	ldi	r27, 0x16	; 22
    1d4c:	cb 0e       	add	r12, r27
    1d4e:	d1 1c       	adc	r13, r1
    1d50:	df 92       	push	r13
    1d52:	cf 92       	push	r12
    1d54:	0e 94 dd 1a 	call	0x35ba	; 0x35ba <snprintf>
    1d58:	c6 01       	movw	r24, r12
    1d5a:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1d5e:	60 e0       	ldi	r22, 0x00	; 0
    1d60:	89 e0       	ldi	r24, 0x09	; 9
    1d62:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1d66:	d7 01       	movw	r26, r14
    1d68:	15 96       	adiw	r26, 0x05	; 5
    1d6a:	ed 91       	ld	r30, X+
    1d6c:	fc 91       	ld	r31, X
    1d6e:	16 97       	sbiw	r26, 0x06	; 6
    1d70:	66 81       	ldd	r22, Z+6	; 0x06
    1d72:	77 81       	ldd	r23, Z+7	; 0x07
    1d74:	80 85       	ldd	r24, Z+8	; 0x08
    1d76:	91 85       	ldd	r25, Z+9	; 0x09
    1d78:	9e 01       	movw	r18, r28
    1d7a:	2f 5f       	subi	r18, 0xFF	; 255
    1d7c:	3f 4f       	sbci	r19, 0xFF	; 255
    1d7e:	49 01       	movw	r8, r18
    1d80:	89 01       	movw	r16, r18
    1d82:	23 e0       	ldi	r18, 0x03	; 3
    1d84:	42 e0       	ldi	r20, 0x02	; 2
    1d86:	0e 94 b3 14 	call	0x2966	; 0x2966 <dtostrf>
    1d8a:	9f 92       	push	r9
    1d8c:	8f 92       	push	r8
    1d8e:	83 e3       	ldi	r24, 0x33	; 51
    1d90:	93 e0       	ldi	r25, 0x03	; 3
    1d92:	9f 93       	push	r25
    1d94:	8f 93       	push	r24
    1d96:	1f 92       	push	r1
    1d98:	bf 92       	push	r11
    1d9a:	df 92       	push	r13
    1d9c:	cf 92       	push	r12
    1d9e:	0e 94 dd 1a 	call	0x35ba	; 0x35ba <snprintf>
    1da2:	c6 01       	movw	r24, r12
    1da4:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1da8:	0f b6       	in	r0, 0x3f	; 63
    1daa:	f8 94       	cli
    1dac:	de bf       	out	0x3e, r29	; 62
    1dae:	0f be       	out	0x3f, r0	; 63
    1db0:	cd bf       	out	0x3d, r28	; 61
    1db2:	c9 c0       	rjmp	.+402    	; 0x1f46 <_ZN6SSMain10draw_line0Eb.constprop.4+0x266>
    1db4:	dc 01       	movw	r26, r24
    1db6:	15 96       	adiw	r26, 0x05	; 5
    1db8:	ed 91       	ld	r30, X+
    1dba:	fc 91       	ld	r31, X
    1dbc:	16 97       	sbiw	r26, 0x06	; 6
    1dbe:	84 89       	ldd	r24, Z+20	; 0x14
    1dc0:	88 23       	and	r24, r24
    1dc2:	09 f4       	brne	.+2      	; 0x1dc6 <_ZN6SSMain10draw_line0Eb.constprop.4+0xe6>
    1dc4:	c0 c0       	rjmp	.+384    	; 0x1f46 <_ZN6SSMain10draw_line0Eb.constprop.4+0x266>
    1dc6:	14 8a       	std	Z+20, r1	; 0x14
    1dc8:	c7 01       	movw	r24, r14
    1dca:	0e 94 02 0e 	call	0x1c04	; 0x1c04 <_ZN6SSMain20draw_channel_numbersEv.constprop.13>
    1dce:	60 e0       	ldi	r22, 0x00	; 0
    1dd0:	80 e0       	ldi	r24, 0x00	; 0
    1dd2:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1dd6:	89 e1       	ldi	r24, 0x19	; 25
    1dd8:	93 e0       	ldi	r25, 0x03	; 3
    1dda:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1dde:	60 e0       	ldi	r22, 0x00	; 0
    1de0:	80 e0       	ldi	r24, 0x00	; 0
    1de2:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1de6:	d7 01       	movw	r26, r14
    1de8:	15 96       	adiw	r26, 0x05	; 5
    1dea:	ed 91       	ld	r30, X+
    1dec:	fc 91       	ld	r31, X
    1dee:	16 97       	sbiw	r26, 0x06	; 6
    1df0:	02 80       	ldd	r0, Z+2	; 0x02
    1df2:	f3 81       	ldd	r31, Z+3	; 0x03
    1df4:	e0 2d       	mov	r30, r0
    1df6:	25 8d       	ldd	r18, Z+29	; 0x1d
    1df8:	36 8d       	ldd	r19, Z+30	; 0x1e
    1dfa:	89 e0       	ldi	r24, 0x09	; 9
    1dfc:	c8 2e       	mov	r12, r24
    1dfe:	c2 9e       	mul	r12, r18
    1e00:	c0 01       	movw	r24, r0
    1e02:	c3 9e       	mul	r12, r19
    1e04:	90 0d       	add	r25, r0
    1e06:	11 24       	eor	r1, r1
    1e08:	e8 0f       	add	r30, r24
    1e0a:	f9 1f       	adc	r31, r25
    1e0c:	87 81       	ldd	r24, Z+7	; 0x07
    1e0e:	1f 92       	push	r1
    1e10:	8f 93       	push	r24
    1e12:	89 e3       	ldi	r24, 0x39	; 57
    1e14:	93 e0       	ldi	r25, 0x03	; 3
    1e16:	9f 93       	push	r25
    1e18:	8f 93       	push	r24
    1e1a:	1f 92       	push	r1
    1e1c:	95 e1       	ldi	r25, 0x15	; 21
    1e1e:	d9 2e       	mov	r13, r25
    1e20:	df 92       	push	r13
    1e22:	8e 01       	movw	r16, r28
    1e24:	0a 5e       	subi	r16, 0xEA	; 234
    1e26:	1f 4f       	sbci	r17, 0xFF	; 255
    1e28:	1f 93       	push	r17
    1e2a:	0f 93       	push	r16
    1e2c:	0e 94 dd 1a 	call	0x35ba	; 0x35ba <snprintf>
    1e30:	c8 01       	movw	r24, r16
    1e32:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1e36:	60 e0       	ldi	r22, 0x00	; 0
    1e38:	85 e0       	ldi	r24, 0x05	; 5
    1e3a:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1e3e:	6f ed       	ldi	r22, 0xDF	; 223
    1e40:	8d e1       	ldi	r24, 0x1D	; 29
    1e42:	94 e0       	ldi	r25, 0x04	; 4
    1e44:	0e 94 39 0b 	call	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>
    1e48:	60 e0       	ldi	r22, 0x00	; 0
    1e4a:	86 e0       	ldi	r24, 0x06	; 6
    1e4c:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1e50:	d7 01       	movw	r26, r14
    1e52:	15 96       	adiw	r26, 0x05	; 5
    1e54:	ed 91       	ld	r30, X+
    1e56:	fc 91       	ld	r31, X
    1e58:	16 97       	sbiw	r26, 0x06	; 6
    1e5a:	02 80       	ldd	r0, Z+2	; 0x02
    1e5c:	f3 81       	ldd	r31, Z+3	; 0x03
    1e5e:	e0 2d       	mov	r30, r0
    1e60:	25 8d       	ldd	r18, Z+29	; 0x1d
    1e62:	36 8d       	ldd	r19, Z+30	; 0x1e
    1e64:	c2 9e       	mul	r12, r18
    1e66:	c0 01       	movw	r24, r0
    1e68:	c3 9e       	mul	r12, r19
    1e6a:	90 0d       	add	r25, r0
    1e6c:	11 24       	eor	r1, r1
    1e6e:	e8 0f       	add	r30, r24
    1e70:	f9 1f       	adc	r31, r25
    1e72:	82 85       	ldd	r24, Z+10	; 0x0a
    1e74:	1f 92       	push	r1
    1e76:	8f 93       	push	r24
    1e78:	20 e4       	ldi	r18, 0x40	; 64
    1e7a:	a2 2e       	mov	r10, r18
    1e7c:	23 e0       	ldi	r18, 0x03	; 3
    1e7e:	b2 2e       	mov	r11, r18
    1e80:	bf 92       	push	r11
    1e82:	af 92       	push	r10
    1e84:	1f 92       	push	r1
    1e86:	df 92       	push	r13
    1e88:	1f 93       	push	r17
    1e8a:	0f 93       	push	r16
    1e8c:	0e 94 dd 1a 	call	0x35ba	; 0x35ba <snprintf>
    1e90:	c8 01       	movw	r24, r16
    1e92:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1e96:	60 e0       	ldi	r22, 0x00	; 0
    1e98:	89 e0       	ldi	r24, 0x09	; 9
    1e9a:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1e9e:	d7 01       	movw	r26, r14
    1ea0:	15 96       	adiw	r26, 0x05	; 5
    1ea2:	ed 91       	ld	r30, X+
    1ea4:	fc 91       	ld	r31, X
    1ea6:	16 97       	sbiw	r26, 0x06	; 6
    1ea8:	02 80       	ldd	r0, Z+2	; 0x02
    1eaa:	f3 81       	ldd	r31, Z+3	; 0x03
    1eac:	e0 2d       	mov	r30, r0
    1eae:	25 8d       	ldd	r18, Z+29	; 0x1d
    1eb0:	36 8d       	ldd	r19, Z+30	; 0x1e
    1eb2:	c2 9e       	mul	r12, r18
    1eb4:	c0 01       	movw	r24, r0
    1eb6:	c3 9e       	mul	r12, r19
    1eb8:	90 0d       	add	r25, r0
    1eba:	11 24       	eor	r1, r1
    1ebc:	e8 0f       	add	r30, r24
    1ebe:	f9 1f       	adc	r31, r25
    1ec0:	80 85       	ldd	r24, Z+8	; 0x08
    1ec2:	1f 92       	push	r1
    1ec4:	8f 93       	push	r24
    1ec6:	85 e4       	ldi	r24, 0x45	; 69
    1ec8:	93 e0       	ldi	r25, 0x03	; 3
    1eca:	9f 93       	push	r25
    1ecc:	8f 93       	push	r24
    1ece:	1f 92       	push	r1
    1ed0:	df 92       	push	r13
    1ed2:	1f 93       	push	r17
    1ed4:	0f 93       	push	r16
    1ed6:	0e 94 dd 1a 	call	0x35ba	; 0x35ba <snprintf>
    1eda:	c8 01       	movw	r24, r16
    1edc:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1ee0:	60 e0       	ldi	r22, 0x00	; 0
    1ee2:	8e e0       	ldi	r24, 0x0E	; 14
    1ee4:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1ee8:	6f ed       	ldi	r22, 0xDF	; 223
    1eea:	8d e1       	ldi	r24, 0x1D	; 29
    1eec:	94 e0       	ldi	r25, 0x04	; 4
    1eee:	0e 94 39 0b 	call	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>
    1ef2:	60 e0       	ldi	r22, 0x00	; 0
    1ef4:	8f e0       	ldi	r24, 0x0F	; 15
    1ef6:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    1efa:	d7 01       	movw	r26, r14
    1efc:	15 96       	adiw	r26, 0x05	; 5
    1efe:	ed 91       	ld	r30, X+
    1f00:	fc 91       	ld	r31, X
    1f02:	16 97       	sbiw	r26, 0x06	; 6
    1f04:	02 80       	ldd	r0, Z+2	; 0x02
    1f06:	f3 81       	ldd	r31, Z+3	; 0x03
    1f08:	e0 2d       	mov	r30, r0
    1f0a:	25 8d       	ldd	r18, Z+29	; 0x1d
    1f0c:	36 8d       	ldd	r19, Z+30	; 0x1e
    1f0e:	2f 5f       	subi	r18, 0xFF	; 255
    1f10:	3f 4f       	sbci	r19, 0xFF	; 255
    1f12:	c2 9e       	mul	r12, r18
    1f14:	c0 01       	movw	r24, r0
    1f16:	c3 9e       	mul	r12, r19
    1f18:	90 0d       	add	r25, r0
    1f1a:	11 24       	eor	r1, r1
    1f1c:	e8 0f       	add	r30, r24
    1f1e:	f9 1f       	adc	r31, r25
    1f20:	80 81       	ld	r24, Z
    1f22:	1f 92       	push	r1
    1f24:	8f 93       	push	r24
    1f26:	bf 92       	push	r11
    1f28:	af 92       	push	r10
    1f2a:	1f 92       	push	r1
    1f2c:	df 92       	push	r13
    1f2e:	1f 93       	push	r17
    1f30:	0f 93       	push	r16
    1f32:	0e 94 dd 1a 	call	0x35ba	; 0x35ba <snprintf>
    1f36:	0f b6       	in	r0, 0x3f	; 63
    1f38:	f8 94       	cli
    1f3a:	de bf       	out	0x3e, r29	; 62
    1f3c:	0f be       	out	0x3f, r0	; 63
    1f3e:	cd bf       	out	0x3d, r28	; 61
    1f40:	c8 01       	movw	r24, r16
    1f42:	0e 94 00 0e 	call	0x1c00	; 0x1c00 <_ZN5Print5printEPKc.constprop.5>
    1f46:	d7 01       	movw	r26, r14
    1f48:	15 96       	adiw	r26, 0x05	; 5
    1f4a:	ed 91       	ld	r30, X+
    1f4c:	fc 91       	ld	r31, X
    1f4e:	16 97       	sbiw	r26, 0x06	; 6
    1f50:	87 89       	ldd	r24, Z+23	; 0x17
    1f52:	88 23       	and	r24, r24
    1f54:	59 f0       	breq	.+22     	; 0x1f6c <_ZN6SSMain10draw_line0Eb.constprop.4+0x28c>
    1f56:	17 8a       	std	Z+23, r1	; 0x17
    1f58:	62 85       	ldd	r22, Z+10	; 0x0a
    1f5a:	b8 e0       	ldi	r27, 0x08	; 8
    1f5c:	6b 9f       	mul	r22, r27
    1f5e:	b0 01       	movw	r22, r0
    1f60:	11 24       	eor	r1, r1
    1f62:	61 53       	subi	r22, 0x31	; 49
    1f64:	7d 4f       	sbci	r23, 0xFD	; 253
    1f66:	81 e0       	ldi	r24, 0x01	; 1
    1f68:	0e 94 b7 0c 	call	0x196e	; 0x196e <_ZN13LiquidCrystal10createCharEhPh.constprop.38>
    1f6c:	aa 96       	adiw	r28, 0x2a	; 42
    1f6e:	0f b6       	in	r0, 0x3f	; 63
    1f70:	f8 94       	cli
    1f72:	de bf       	out	0x3e, r29	; 62
    1f74:	0f be       	out	0x3f, r0	; 63
    1f76:	cd bf       	out	0x3d, r28	; 61
    1f78:	df 91       	pop	r29
    1f7a:	cf 91       	pop	r28
    1f7c:	1f 91       	pop	r17
    1f7e:	0f 91       	pop	r16
    1f80:	ff 90       	pop	r15
    1f82:	ef 90       	pop	r14
    1f84:	df 90       	pop	r13
    1f86:	cf 90       	pop	r12
    1f88:	bf 90       	pop	r11
    1f8a:	af 90       	pop	r10
    1f8c:	9f 90       	pop	r9
    1f8e:	8f 90       	pop	r8
    1f90:	08 95       	ret

00001f92 <_ZN6SSMain11draw_columnEhbb.constprop.2>:
    1f92:	7f 92       	push	r7
    1f94:	8f 92       	push	r8
    1f96:	9f 92       	push	r9
    1f98:	af 92       	push	r10
    1f9a:	bf 92       	push	r11
    1f9c:	cf 92       	push	r12
    1f9e:	df 92       	push	r13
    1fa0:	ef 92       	push	r14
    1fa2:	ff 92       	push	r15
    1fa4:	0f 93       	push	r16
    1fa6:	1f 93       	push	r17
    1fa8:	cf 93       	push	r28
    1faa:	df 93       	push	r29
    1fac:	6c 01       	movw	r12, r24
    1fae:	b6 2e       	mov	r11, r22
    1fb0:	74 2e       	mov	r7, r20
    1fb2:	c0 e0       	ldi	r28, 0x00	; 0
    1fb4:	d0 e0       	ldi	r29, 0x00	; 0
    1fb6:	89 e0       	ldi	r24, 0x09	; 9
    1fb8:	a8 2e       	mov	r10, r24
    1fba:	e6 2e       	mov	r14, r22
    1fbc:	f1 2c       	mov	r15, r1
    1fbe:	9c 2e       	mov	r9, r28
    1fc0:	93 94       	inc	r9
    1fc2:	d6 01       	movw	r26, r12
    1fc4:	15 96       	adiw	r26, 0x05	; 5
    1fc6:	ed 91       	ld	r30, X+
    1fc8:	fc 91       	ld	r31, X
    1fca:	16 97       	sbiw	r26, 0x06	; 6
    1fcc:	02 81       	ldd	r16, Z+2	; 0x02
    1fce:	13 81       	ldd	r17, Z+3	; 0x03
    1fd0:	c8 01       	movw	r24, r16
    1fd2:	0e 94 4e 03 	call	0x69c	; 0x69c <_ZNK15TrackCollectionILj3E5TrackE11max_mod_majEv>
    1fd6:	68 2f       	mov	r22, r24
    1fd8:	8b 2d       	mov	r24, r11
    1fda:	0e 94 52 17 	call	0x2ea4	; 0x2ea4 <__udivmodqi4>
    1fde:	9f 70       	andi	r25, 0x0F	; 15
    1fe0:	e9 2f       	mov	r30, r25
    1fe2:	f0 e0       	ldi	r31, 0x00	; 0
    1fe4:	e1 54       	subi	r30, 0x41	; 65
    1fe6:	fd 4f       	sbci	r31, 0xFD	; 253
    1fe8:	80 80       	ld	r8, Z
    1fea:	ac 9e       	mul	r10, r28
    1fec:	f0 01       	movw	r30, r0
    1fee:	ad 9e       	mul	r10, r29
    1ff0:	f0 0d       	add	r31, r0
    1ff2:	11 24       	eor	r1, r1
    1ff4:	e0 0f       	add	r30, r16
    1ff6:	f1 1f       	adc	r31, r17
    1ff8:	32 85       	ldd	r19, Z+10	; 0x0a
    1ffa:	27 81       	ldd	r18, Z+7	; 0x07
    1ffc:	8b 2d       	mov	r24, r11
    1ffe:	83 1b       	sub	r24, r19
    2000:	62 2f       	mov	r22, r18
    2002:	0e 94 52 17 	call	0x2ea4	; 0x2ea4 <__udivmodqi4>
    2006:	89 2f       	mov	r24, r25
    2008:	90 e0       	ldi	r25, 0x00	; 0
    200a:	21 96       	adiw	r28, 0x01	; 1
    200c:	ac 9e       	mul	r10, r28
    200e:	a0 01       	movw	r20, r0
    2010:	ad 9e       	mul	r10, r29
    2012:	50 0d       	add	r21, r0
    2014:	11 24       	eor	r1, r1
    2016:	d8 01       	movw	r26, r16
    2018:	a4 0f       	add	r26, r20
    201a:	b5 1f       	adc	r27, r21
    201c:	4c 91       	ld	r20, X
    201e:	84 1b       	sub	r24, r20
    2020:	91 09       	sbc	r25, r1
    2022:	60 85       	ldd	r22, Z+8	; 0x08
    2024:	70 e0       	ldi	r23, 0x00	; 0
    2026:	0e 94 5e 17 	call	0x2ebc	; 0x2ebc <__divmodhi4>
    202a:	89 2b       	or	r24, r25
    202c:	71 f4       	brne	.+28     	; 0x204a <_ZN6SSMain11draw_columnEhbb.constprop.2+0xb8>
    202e:	71 10       	cpse	r7, r1
    2030:	1a c0       	rjmp	.+52     	; 0x2066 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xd4>
    2032:	c7 01       	movw	r24, r14
    2034:	83 1b       	sub	r24, r19
    2036:	91 09       	sbc	r25, r1
    2038:	01 96       	adiw	r24, 0x01	; 1
    203a:	62 2f       	mov	r22, r18
    203c:	70 e0       	ldi	r23, 0x00	; 0
    203e:	0e 94 5e 17 	call	0x2ebc	; 0x2ebc <__divmodhi4>
    2042:	89 2b       	or	r24, r25
    2044:	91 f0       	breq	.+36     	; 0x206a <_ZN6SSMain11draw_columnEhbb.constprop.2+0xd8>
    2046:	12 e0       	ldi	r17, 0x02	; 2
    2048:	15 c0       	rjmp	.+42     	; 0x2074 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xe2>
    204a:	71 10       	cpse	r7, r1
    204c:	10 c0       	rjmp	.+32     	; 0x206e <_ZN6SSMain11draw_columnEhbb.constprop.2+0xdc>
    204e:	c7 01       	movw	r24, r14
    2050:	83 1b       	sub	r24, r19
    2052:	91 09       	sbc	r25, r1
    2054:	01 96       	adiw	r24, 0x01	; 1
    2056:	62 2f       	mov	r22, r18
    2058:	70 e0       	ldi	r23, 0x00	; 0
    205a:	0e 94 5e 17 	call	0x2ebc	; 0x2ebc <__divmodhi4>
    205e:	89 2b       	or	r24, r25
    2060:	41 f0       	breq	.+16     	; 0x2072 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xe0>
    2062:	14 e0       	ldi	r17, 0x04	; 4
    2064:	07 c0       	rjmp	.+14     	; 0x2074 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xe2>
    2066:	13 e0       	ldi	r17, 0x03	; 3
    2068:	05 c0       	rjmp	.+10     	; 0x2074 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xe2>
    206a:	16 e0       	ldi	r17, 0x06	; 6
    206c:	03 c0       	rjmp	.+6      	; 0x2074 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xe2>
    206e:	15 e0       	ldi	r17, 0x05	; 5
    2070:	01 c0       	rjmp	.+2      	; 0x2074 <_ZN6SSMain11draw_columnEhbb.constprop.2+0xe2>
    2072:	17 e0       	ldi	r17, 0x07	; 7
    2074:	69 2d       	mov	r22, r9
    2076:	88 2d       	mov	r24, r8
    2078:	0e 94 76 0d 	call	0x1aec	; 0x1aec <_ZN13LiquidCrystal9setCursorEhh.constprop.21>
    207c:	61 2f       	mov	r22, r17
    207e:	8d e1       	ldi	r24, 0x1D	; 29
    2080:	94 e0       	ldi	r25, 0x04	; 4
    2082:	0e 94 39 0b 	call	0x1672	; 0x1672 <_ZN13LiquidCrystal5writeEh>
    2086:	c3 30       	cpi	r28, 0x03	; 3
    2088:	d1 05       	cpc	r29, r1
    208a:	09 f0       	breq	.+2      	; 0x208e <_ZN6SSMain11draw_columnEhbb.constprop.2+0xfc>
    208c:	98 cf       	rjmp	.-208    	; 0x1fbe <_ZN6SSMain11draw_columnEhbb.constprop.2+0x2c>
    208e:	df 91       	pop	r29
    2090:	cf 91       	pop	r28
    2092:	1f 91       	pop	r17
    2094:	0f 91       	pop	r16
    2096:	ff 90       	pop	r15
    2098:	ef 90       	pop	r14
    209a:	df 90       	pop	r13
    209c:	cf 90       	pop	r12
    209e:	bf 90       	pop	r11
    20a0:	af 90       	pop	r10
    20a2:	9f 90       	pop	r9
    20a4:	8f 90       	pop	r8
    20a6:	7f 90       	pop	r7
    20a8:	08 95       	ret

000020aa <digitalWrite>:
    20aa:	90 e0       	ldi	r25, 0x00	; 0
    20ac:	fc 01       	movw	r30, r24
    20ae:	ed 53       	subi	r30, 0x3D	; 61
    20b0:	fe 4f       	sbci	r31, 0xFE	; 254
    20b2:	24 91       	lpm	r18, Z
    20b4:	fc 01       	movw	r30, r24
    20b6:	e1 55       	subi	r30, 0x51	; 81
    20b8:	fe 4f       	sbci	r31, 0xFE	; 254
    20ba:	34 91       	lpm	r19, Z
    20bc:	fc 01       	movw	r30, r24
    20be:	e5 56       	subi	r30, 0x65	; 101
    20c0:	fe 4f       	sbci	r31, 0xFE	; 254
    20c2:	e4 91       	lpm	r30, Z
    20c4:	ee 23       	and	r30, r30
    20c6:	09 f4       	brne	.+2      	; 0x20ca <digitalWrite+0x20>
    20c8:	3c c0       	rjmp	.+120    	; 0x2142 <digitalWrite+0x98>
    20ca:	22 23       	and	r18, r18
    20cc:	39 f1       	breq	.+78     	; 0x211c <digitalWrite+0x72>
    20ce:	23 30       	cpi	r18, 0x03	; 3
    20d0:	91 f0       	breq	.+36     	; 0x20f6 <digitalWrite+0x4c>
    20d2:	38 f4       	brcc	.+14     	; 0x20e2 <digitalWrite+0x38>
    20d4:	21 30       	cpi	r18, 0x01	; 1
    20d6:	a9 f0       	breq	.+42     	; 0x2102 <digitalWrite+0x58>
    20d8:	22 30       	cpi	r18, 0x02	; 2
    20da:	01 f5       	brne	.+64     	; 0x211c <digitalWrite+0x72>
    20dc:	84 b5       	in	r24, 0x24	; 36
    20de:	8f 7d       	andi	r24, 0xDF	; 223
    20e0:	12 c0       	rjmp	.+36     	; 0x2106 <digitalWrite+0x5c>
    20e2:	27 30       	cpi	r18, 0x07	; 7
    20e4:	91 f0       	breq	.+36     	; 0x210a <digitalWrite+0x60>
    20e6:	28 30       	cpi	r18, 0x08	; 8
    20e8:	a1 f0       	breq	.+40     	; 0x2112 <digitalWrite+0x68>
    20ea:	24 30       	cpi	r18, 0x04	; 4
    20ec:	b9 f4       	brne	.+46     	; 0x211c <digitalWrite+0x72>
    20ee:	80 91 80 00 	lds	r24, 0x0080	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    20f2:	8f 7d       	andi	r24, 0xDF	; 223
    20f4:	03 c0       	rjmp	.+6      	; 0x20fc <digitalWrite+0x52>
    20f6:	80 91 80 00 	lds	r24, 0x0080	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    20fa:	8f 77       	andi	r24, 0x7F	; 127
    20fc:	80 93 80 00 	sts	0x0080, r24	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    2100:	0d c0       	rjmp	.+26     	; 0x211c <digitalWrite+0x72>
    2102:	84 b5       	in	r24, 0x24	; 36
    2104:	8f 77       	andi	r24, 0x7F	; 127
    2106:	84 bd       	out	0x24, r24	; 36
    2108:	09 c0       	rjmp	.+18     	; 0x211c <digitalWrite+0x72>
    210a:	80 91 b0 00 	lds	r24, 0x00B0	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7e00b0>
    210e:	8f 77       	andi	r24, 0x7F	; 127
    2110:	03 c0       	rjmp	.+6      	; 0x2118 <digitalWrite+0x6e>
    2112:	80 91 b0 00 	lds	r24, 0x00B0	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7e00b0>
    2116:	8f 7d       	andi	r24, 0xDF	; 223
    2118:	80 93 b0 00 	sts	0x00B0, r24	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7e00b0>
    211c:	f0 e0       	ldi	r31, 0x00	; 0
    211e:	ee 0f       	add	r30, r30
    2120:	ff 1f       	adc	r31, r31
    2122:	ef 56       	subi	r30, 0x6F	; 111
    2124:	fe 4f       	sbci	r31, 0xFE	; 254
    2126:	a5 91       	lpm	r26, Z+
    2128:	b4 91       	lpm	r27, Z
    212a:	9f b7       	in	r25, 0x3f	; 63
    212c:	f8 94       	cli
    212e:	61 11       	cpse	r22, r1
    2130:	04 c0       	rjmp	.+8      	; 0x213a <digitalWrite+0x90>
    2132:	8c 91       	ld	r24, X
    2134:	30 95       	com	r19
    2136:	38 23       	and	r19, r24
    2138:	02 c0       	rjmp	.+4      	; 0x213e <digitalWrite+0x94>
    213a:	ec 91       	ld	r30, X
    213c:	3e 2b       	or	r19, r30
    213e:	3c 93       	st	X, r19
    2140:	9f bf       	out	0x3f, r25	; 63
    2142:	08 95       	ret

00002144 <pinMode>:
    2144:	cf 93       	push	r28
    2146:	df 93       	push	r29
    2148:	90 e0       	ldi	r25, 0x00	; 0
    214a:	fc 01       	movw	r30, r24
    214c:	e1 55       	subi	r30, 0x51	; 81
    214e:	fe 4f       	sbci	r31, 0xFE	; 254
    2150:	24 91       	lpm	r18, Z
    2152:	fc 01       	movw	r30, r24
    2154:	e5 56       	subi	r30, 0x65	; 101
    2156:	fe 4f       	sbci	r31, 0xFE	; 254
    2158:	84 91       	lpm	r24, Z
    215a:	88 23       	and	r24, r24
    215c:	61 f1       	breq	.+88     	; 0x21b6 <pinMode+0x72>
    215e:	90 e0       	ldi	r25, 0x00	; 0
    2160:	88 0f       	add	r24, r24
    2162:	99 1f       	adc	r25, r25
    2164:	fc 01       	movw	r30, r24
    2166:	e9 57       	subi	r30, 0x79	; 121
    2168:	fe 4f       	sbci	r31, 0xFE	; 254
    216a:	c5 91       	lpm	r28, Z+
    216c:	d4 91       	lpm	r29, Z
    216e:	fc 01       	movw	r30, r24
    2170:	ef 56       	subi	r30, 0x6F	; 111
    2172:	fe 4f       	sbci	r31, 0xFE	; 254
    2174:	a5 91       	lpm	r26, Z+
    2176:	b4 91       	lpm	r27, Z
    2178:	61 11       	cpse	r22, r1
    217a:	09 c0       	rjmp	.+18     	; 0x218e <pinMode+0x4a>
    217c:	9f b7       	in	r25, 0x3f	; 63
    217e:	f8 94       	cli
    2180:	88 81       	ld	r24, Y
    2182:	20 95       	com	r18
    2184:	82 23       	and	r24, r18
    2186:	88 83       	st	Y, r24
    2188:	ec 91       	ld	r30, X
    218a:	2e 23       	and	r18, r30
    218c:	0b c0       	rjmp	.+22     	; 0x21a4 <pinMode+0x60>
    218e:	62 30       	cpi	r22, 0x02	; 2
    2190:	61 f4       	brne	.+24     	; 0x21aa <pinMode+0x66>
    2192:	9f b7       	in	r25, 0x3f	; 63
    2194:	f8 94       	cli
    2196:	88 81       	ld	r24, Y
    2198:	32 2f       	mov	r19, r18
    219a:	30 95       	com	r19
    219c:	83 23       	and	r24, r19
    219e:	88 83       	st	Y, r24
    21a0:	ec 91       	ld	r30, X
    21a2:	2e 2b       	or	r18, r30
    21a4:	2c 93       	st	X, r18
    21a6:	9f bf       	out	0x3f, r25	; 63
    21a8:	06 c0       	rjmp	.+12     	; 0x21b6 <pinMode+0x72>
    21aa:	8f b7       	in	r24, 0x3f	; 63
    21ac:	f8 94       	cli
    21ae:	e8 81       	ld	r30, Y
    21b0:	2e 2b       	or	r18, r30
    21b2:	28 83       	st	Y, r18
    21b4:	8f bf       	out	0x3f, r24	; 63
    21b6:	df 91       	pop	r29
    21b8:	cf 91       	pop	r28
    21ba:	08 95       	ret

000021bc <delay>:
    21bc:	8f 92       	push	r8
    21be:	9f 92       	push	r9
    21c0:	af 92       	push	r10
    21c2:	bf 92       	push	r11
    21c4:	cf 92       	push	r12
    21c6:	df 92       	push	r13
    21c8:	ef 92       	push	r14
    21ca:	ff 92       	push	r15
    21cc:	6b 01       	movw	r12, r22
    21ce:	7c 01       	movw	r14, r24
    21d0:	0e 94 9a 0d 	call	0x1b34	; 0x1b34 <micros>
    21d4:	4b 01       	movw	r8, r22
    21d6:	5c 01       	movw	r10, r24
    21d8:	c1 14       	cp	r12, r1
    21da:	d1 04       	cpc	r13, r1
    21dc:	e1 04       	cpc	r14, r1
    21de:	f1 04       	cpc	r15, r1
    21e0:	f1 f0       	breq	.+60     	; 0x221e <delay+0x62>
    21e2:	0e 94 9a 0d 	call	0x1b34	; 0x1b34 <micros>
    21e6:	dc 01       	movw	r26, r24
    21e8:	cb 01       	movw	r24, r22
    21ea:	88 19       	sub	r24, r8
    21ec:	99 09       	sbc	r25, r9
    21ee:	aa 09       	sbc	r26, r10
    21f0:	bb 09       	sbc	r27, r11
    21f2:	88 3e       	cpi	r24, 0xE8	; 232
    21f4:	93 40       	sbci	r25, 0x03	; 3
    21f6:	a1 05       	cpc	r26, r1
    21f8:	b1 05       	cpc	r27, r1
    21fa:	70 f3       	brcs	.-36     	; 0x21d8 <delay+0x1c>
    21fc:	21 e0       	ldi	r18, 0x01	; 1
    21fe:	c2 1a       	sub	r12, r18
    2200:	d1 08       	sbc	r13, r1
    2202:	e1 08       	sbc	r14, r1
    2204:	f1 08       	sbc	r15, r1
    2206:	88 ee       	ldi	r24, 0xE8	; 232
    2208:	88 0e       	add	r8, r24
    220a:	83 e0       	ldi	r24, 0x03	; 3
    220c:	98 1e       	adc	r9, r24
    220e:	a1 1c       	adc	r10, r1
    2210:	b1 1c       	adc	r11, r1
    2212:	c1 14       	cp	r12, r1
    2214:	d1 04       	cpc	r13, r1
    2216:	e1 04       	cpc	r14, r1
    2218:	f1 04       	cpc	r15, r1
    221a:	19 f7       	brne	.-58     	; 0x21e2 <delay+0x26>
    221c:	dd cf       	rjmp	.-70     	; 0x21d8 <delay+0x1c>
    221e:	ff 90       	pop	r15
    2220:	ef 90       	pop	r14
    2222:	df 90       	pop	r13
    2224:	cf 90       	pop	r12
    2226:	bf 90       	pop	r11
    2228:	af 90       	pop	r10
    222a:	9f 90       	pop	r9
    222c:	8f 90       	pop	r8
    222e:	08 95       	ret

00002230 <__vector_16>:
    2230:	1f 92       	push	r1
    2232:	0f 92       	push	r0
    2234:	0f b6       	in	r0, 0x3f	; 63
    2236:	0f 92       	push	r0
    2238:	11 24       	eor	r1, r1
    223a:	2f 93       	push	r18
    223c:	3f 93       	push	r19
    223e:	8f 93       	push	r24
    2240:	9f 93       	push	r25
    2242:	af 93       	push	r26
    2244:	bf 93       	push	r27
    2246:	80 91 0d 04 	lds	r24, 0x040D	; 0x80040d <timer0_millis>
    224a:	90 91 0e 04 	lds	r25, 0x040E	; 0x80040e <timer0_millis+0x1>
    224e:	a0 91 0f 04 	lds	r26, 0x040F	; 0x80040f <timer0_millis+0x2>
    2252:	b0 91 10 04 	lds	r27, 0x0410	; 0x800410 <timer0_millis+0x3>
    2256:	30 91 ca 04 	lds	r19, 0x04CA	; 0x8004ca <timer0_fract>
    225a:	23 e0       	ldi	r18, 0x03	; 3
    225c:	23 0f       	add	r18, r19
    225e:	2d 37       	cpi	r18, 0x7D	; 125
    2260:	20 f4       	brcc	.+8      	; 0x226a <__vector_16+0x3a>
    2262:	01 96       	adiw	r24, 0x01	; 1
    2264:	a1 1d       	adc	r26, r1
    2266:	b1 1d       	adc	r27, r1
    2268:	05 c0       	rjmp	.+10     	; 0x2274 <__vector_16+0x44>
    226a:	26 e8       	ldi	r18, 0x86	; 134
    226c:	23 0f       	add	r18, r19
    226e:	02 96       	adiw	r24, 0x02	; 2
    2270:	a1 1d       	adc	r26, r1
    2272:	b1 1d       	adc	r27, r1
    2274:	20 93 ca 04 	sts	0x04CA, r18	; 0x8004ca <timer0_fract>
    2278:	80 93 0d 04 	sts	0x040D, r24	; 0x80040d <timer0_millis>
    227c:	90 93 0e 04 	sts	0x040E, r25	; 0x80040e <timer0_millis+0x1>
    2280:	a0 93 0f 04 	sts	0x040F, r26	; 0x80040f <timer0_millis+0x2>
    2284:	b0 93 10 04 	sts	0x0410, r27	; 0x800410 <timer0_millis+0x3>
    2288:	80 91 cb 04 	lds	r24, 0x04CB	; 0x8004cb <timer0_overflow_count>
    228c:	90 91 cc 04 	lds	r25, 0x04CC	; 0x8004cc <timer0_overflow_count+0x1>
    2290:	a0 91 cd 04 	lds	r26, 0x04CD	; 0x8004cd <timer0_overflow_count+0x2>
    2294:	b0 91 ce 04 	lds	r27, 0x04CE	; 0x8004ce <timer0_overflow_count+0x3>
    2298:	01 96       	adiw	r24, 0x01	; 1
    229a:	a1 1d       	adc	r26, r1
    229c:	b1 1d       	adc	r27, r1
    229e:	80 93 cb 04 	sts	0x04CB, r24	; 0x8004cb <timer0_overflow_count>
    22a2:	90 93 cc 04 	sts	0x04CC, r25	; 0x8004cc <timer0_overflow_count+0x1>
    22a6:	a0 93 cd 04 	sts	0x04CD, r26	; 0x8004cd <timer0_overflow_count+0x2>
    22aa:	b0 93 ce 04 	sts	0x04CE, r27	; 0x8004ce <timer0_overflow_count+0x3>
    22ae:	bf 91       	pop	r27
    22b0:	af 91       	pop	r26
    22b2:	9f 91       	pop	r25
    22b4:	8f 91       	pop	r24
    22b6:	3f 91       	pop	r19
    22b8:	2f 91       	pop	r18
    22ba:	0f 90       	pop	r0
    22bc:	0f be       	out	0x3f, r0	; 63
    22be:	0f 90       	pop	r0
    22c0:	1f 90       	pop	r1
    22c2:	18 95       	reti

000022c4 <_GLOBAL__sub_D__ZN11Application20control_event_sourceE>:
    22c4:	83 e7       	ldi	r24, 0x73	; 115
    22c6:	94 e0       	ldi	r25, 0x04	; 4
    22c8:	0e 94 b7 02 	call	0x56e	; 0x56e <_ZN15TrackCollectionILj3E5TrackED1Ev.lto_priv.133>
    22cc:	82 e9       	ldi	r24, 0x92	; 146
    22ce:	94 e0       	ldi	r25, 0x04	; 4
    22d0:	0c 94 59 03 	jmp	0x6b2	; 0x6b2 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEED1Ev.lto_priv.143>

000022d4 <main>:
    22d4:	cf 93       	push	r28
    22d6:	df 93       	push	r29
    22d8:	cd b7       	in	r28, 0x3d	; 61
    22da:	de b7       	in	r29, 0x3e	; 62
    22dc:	e8 97       	sbiw	r28, 0x38	; 56
    22de:	0f b6       	in	r0, 0x3f	; 63
    22e0:	f8 94       	cli
    22e2:	de bf       	out	0x3e, r29	; 62
    22e4:	0f be       	out	0x3f, r0	; 63
    22e6:	cd bf       	out	0x3d, r28	; 61
    22e8:	78 94       	sei
    22ea:	84 b5       	in	r24, 0x24	; 36
    22ec:	82 60       	ori	r24, 0x02	; 2
    22ee:	84 bd       	out	0x24, r24	; 36
    22f0:	84 b5       	in	r24, 0x24	; 36
    22f2:	81 60       	ori	r24, 0x01	; 1
    22f4:	84 bd       	out	0x24, r24	; 36
    22f6:	85 b5       	in	r24, 0x25	; 37
    22f8:	82 60       	ori	r24, 0x02	; 2
    22fa:	85 bd       	out	0x25, r24	; 37
    22fc:	85 b5       	in	r24, 0x25	; 37
    22fe:	81 60       	ori	r24, 0x01	; 1
    2300:	85 bd       	out	0x25, r24	; 37
    2302:	80 91 6e 00 	lds	r24, 0x006E	; 0x80006e <__TEXT_REGION_LENGTH__+0x7e006e>
    2306:	81 60       	ori	r24, 0x01	; 1
    2308:	80 93 6e 00 	sts	0x006E, r24	; 0x80006e <__TEXT_REGION_LENGTH__+0x7e006e>
    230c:	10 92 81 00 	sts	0x0081, r1	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    2310:	80 91 81 00 	lds	r24, 0x0081	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    2314:	82 60       	ori	r24, 0x02	; 2
    2316:	80 93 81 00 	sts	0x0081, r24	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    231a:	80 91 81 00 	lds	r24, 0x0081	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    231e:	81 60       	ori	r24, 0x01	; 1
    2320:	80 93 81 00 	sts	0x0081, r24	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    2324:	80 91 80 00 	lds	r24, 0x0080	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    2328:	81 60       	ori	r24, 0x01	; 1
    232a:	80 93 80 00 	sts	0x0080, r24	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    232e:	80 91 b1 00 	lds	r24, 0x00B1	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    2332:	84 60       	ori	r24, 0x04	; 4
    2334:	80 93 b1 00 	sts	0x00B1, r24	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    2338:	80 91 b0 00 	lds	r24, 0x00B0	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7e00b0>
    233c:	81 60       	ori	r24, 0x01	; 1
    233e:	80 93 b0 00 	sts	0x00B0, r24	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7e00b0>
    2342:	80 91 7a 00 	lds	r24, 0x007A	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    2346:	84 60       	ori	r24, 0x04	; 4
    2348:	80 93 7a 00 	sts	0x007A, r24	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    234c:	80 91 7a 00 	lds	r24, 0x007A	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    2350:	82 60       	ori	r24, 0x02	; 2
    2352:	80 93 7a 00 	sts	0x007A, r24	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    2356:	80 91 7a 00 	lds	r24, 0x007A	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    235a:	81 60       	ori	r24, 0x01	; 1
    235c:	80 93 7a 00 	sts	0x007A, r24	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    2360:	80 91 7a 00 	lds	r24, 0x007A	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    2364:	80 68       	ori	r24, 0x80	; 128
    2366:	80 93 7a 00 	sts	0x007A, r24	; 0x80007a <__TEXT_REGION_LENGTH__+0x7e007a>
    236a:	10 92 c1 00 	sts	0x00C1, r1	; 0x8000c1 <__TEXT_REGION_LENGTH__+0x7e00c1>
    236e:	64 e0       	ldi	r22, 0x04	; 4
    2370:	84 e1       	ldi	r24, 0x14	; 20
    2372:	0e 94 d4 0c 	call	0x19a8	; 0x19a8 <_ZN13LiquidCrystal5beginEhhh.constprop.36>
    2376:	2f e2       	ldi	r18, 0x2F	; 47
    2378:	e2 2e       	mov	r14, r18
    237a:	21 e0       	ldi	r18, 0x01	; 1
    237c:	f2 2e       	mov	r15, r18
    237e:	10 e0       	ldi	r17, 0x00	; 0
    2380:	b7 01       	movw	r22, r14
    2382:	81 2f       	mov	r24, r17
    2384:	0e 94 b7 0c 	call	0x196e	; 0x196e <_ZN13LiquidCrystal10createCharEhPh.constprop.38>
    2388:	1f 5f       	subi	r17, 0xFF	; 255
    238a:	88 e0       	ldi	r24, 0x08	; 8
    238c:	e8 0e       	add	r14, r24
    238e:	f1 1c       	adc	r15, r1
    2390:	18 30       	cpi	r17, 0x08	; 8
    2392:	b1 f7       	brne	.-20     	; 0x2380 <main+0xac>
    2394:	80 91 55 04 	lds	r24, 0x0455	; 0x800455 <_ZN11Application2uiE+0x4>
    2398:	90 91 56 04 	lds	r25, 0x0456	; 0x800456 <_ZN11Application2uiE+0x5>
    239c:	89 2b       	or	r24, r25
    239e:	51 f0       	breq	.+20     	; 0x23b4 <main+0xe0>
    23a0:	10 92 56 04 	sts	0x0456, r1	; 0x800456 <_ZN11Application2uiE+0x5>
    23a4:	10 92 55 04 	sts	0x0455, r1	; 0x800455 <_ZN11Application2uiE+0x4>
    23a8:	80 91 57 04 	lds	r24, 0x0457	; 0x800457 <_ZN11Application2uiE+0x6>
    23ac:	90 91 58 04 	lds	r25, 0x0458	; 0x800458 <_ZN11Application2uiE+0x7>
    23b0:	0e 94 70 0c 	call	0x18e0	; 0x18e0 <_ZN6ScreenI6UiDataI15TrackCollectionILj3E5TrackEEE5enterEv.constprop.61>
    23b4:	83 e0       	ldi	r24, 0x03	; 3
    23b6:	90 e0       	ldi	r25, 0x00	; 0
    23b8:	0e 94 1f 08 	call	0x103e	; 0x103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>
    23bc:	d8 2e       	mov	r13, r24
    23be:	84 e0       	ldi	r24, 0x04	; 4
    23c0:	90 e0       	ldi	r25, 0x00	; 0
    23c2:	0e 94 1f 08 	call	0x103e	; 0x103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>
    23c6:	bb 24       	eor	r11, r11
    23c8:	b3 94       	inc	r11
    23ca:	81 11       	cpse	r24, r1
    23cc:	01 c0       	rjmp	.+2      	; 0x23d0 <main+0xfc>
    23ce:	b1 2c       	mov	r11, r1
    23d0:	03 e7       	ldi	r16, 0x73	; 115
    23d2:	14 e0       	ldi	r17, 0x04	; 4
    23d4:	95 e0       	ldi	r25, 0x05	; 5
    23d6:	e9 2e       	mov	r14, r25
    23d8:	f1 2c       	mov	r15, r1
    23da:	aa 24       	eor	r10, r10
    23dc:	a3 94       	inc	r10
    23de:	c7 01       	movw	r24, r14
    23e0:	0e 94 1f 08 	call	0x103e	; 0x103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>
    23e4:	f8 01       	movw	r30, r16
    23e6:	87 83       	std	Z+7, r24	; 0x07
    23e8:	cc 24       	eor	r12, r12
    23ea:	c3 94       	inc	r12
    23ec:	a6 82       	std	Z+6, r10	; 0x06
    23ee:	c7 01       	movw	r24, r14
    23f0:	01 96       	adiw	r24, 0x01	; 1
    23f2:	0e 94 1f 08 	call	0x103e	; 0x103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>
    23f6:	f8 01       	movw	r30, r16
    23f8:	80 87       	std	Z+8, r24	; 0x08
    23fa:	c7 01       	movw	r24, r14
    23fc:	02 96       	adiw	r24, 0x02	; 2
    23fe:	0e 94 1f 08 	call	0x103e	; 0x103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>
    2402:	f8 01       	movw	r30, r16
    2404:	81 87       	std	Z+9, r24	; 0x09
    2406:	c7 01       	movw	r24, r14
    2408:	03 96       	adiw	r24, 0x03	; 3
    240a:	0e 94 1f 08 	call	0x103e	; 0x103e <_ZN11EEPROMClass4readEi.isra.0.lto_priv.178>
    240e:	f8 01       	movw	r30, r16
    2410:	82 87       	std	Z+10, r24	; 0x0a
    2412:	16 82       	std	Z+6, r1	; 0x06
    2414:	f4 e0       	ldi	r31, 0x04	; 4
    2416:	ef 0e       	add	r14, r31
    2418:	f1 1c       	adc	r15, r1
    241a:	07 5f       	subi	r16, 0xF7	; 247
    241c:	1f 4f       	sbci	r17, 0xFF	; 255
    241e:	81 e1       	ldi	r24, 0x11	; 17
    2420:	e8 16       	cp	r14, r24
    2422:	f1 04       	cpc	r15, r1
    2424:	e1 f6       	brne	.-72     	; 0x23de <main+0x10a>
    2426:	10 92 6e 04 	sts	0x046E, r1	; 0x80046e <_ZN11Application6eepromE+0x4>
    242a:	6d 2d       	mov	r22, r13
    242c:	ce 01       	movw	r24, r28
    242e:	01 96       	adiw	r24, 0x01	; 1
    2430:	0e 94 81 0c 	call	0x1902	; 0x1902 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEEC2Eh.constprop.53>
    2434:	8d 81       	ldd	r24, Y+5	; 0x05
    2436:	80 93 96 04 	sts	0x0496, r24	; 0x800496 <_ZN11Application20control_event_sourceE+0x4>
    243a:	8e 81       	ldd	r24, Y+6	; 0x06
    243c:	9f 81       	ldd	r25, Y+7	; 0x07
    243e:	a8 85       	ldd	r26, Y+8	; 0x08
    2440:	b9 85       	ldd	r27, Y+9	; 0x09
    2442:	80 93 97 04 	sts	0x0497, r24	; 0x800497 <_ZN11Application20control_event_sourceE+0x5>
    2446:	90 93 98 04 	sts	0x0498, r25	; 0x800498 <_ZN11Application20control_event_sourceE+0x6>
    244a:	a0 93 99 04 	sts	0x0499, r26	; 0x800499 <_ZN11Application20control_event_sourceE+0x7>
    244e:	b0 93 9a 04 	sts	0x049A, r27	; 0x80049a <_ZN11Application20control_event_sourceE+0x8>
    2452:	8c 85       	ldd	r24, Y+12	; 0x0c
    2454:	9d 85       	ldd	r25, Y+13	; 0x0d
    2456:	90 93 9e 04 	sts	0x049E, r25	; 0x80049e <_ZN11Application20control_event_sourceE+0xc>
    245a:	80 93 9d 04 	sts	0x049D, r24	; 0x80049d <_ZN11Application20control_event_sourceE+0xb>
    245e:	89 89       	ldd	r24, Y+17	; 0x11
    2460:	98 89       	ldd	r25, Y+16	; 0x10
    2462:	90 93 a1 04 	sts	0x04A1, r25	; 0x8004a1 <_ZN11Application20control_event_sourceE+0xf>
    2466:	80 93 a2 04 	sts	0x04A2, r24	; 0x8004a2 <_ZN11Application20control_event_sourceE+0x10>
    246a:	8c 89       	ldd	r24, Y+20	; 0x14
    246c:	9d 89       	ldd	r25, Y+21	; 0x15
    246e:	90 93 a6 04 	sts	0x04A6, r25	; 0x8004a6 <_ZN11Application20control_event_sourceE+0x14>
    2472:	80 93 a5 04 	sts	0x04A5, r24	; 0x8004a5 <_ZN11Application20control_event_sourceE+0x13>
    2476:	8a 8d       	ldd	r24, Y+26	; 0x1a
    2478:	9b 8d       	ldd	r25, Y+27	; 0x1b
    247a:	ac 8d       	ldd	r26, Y+28	; 0x1c
    247c:	80 93 ab 04 	sts	0x04AB, r24	; 0x8004ab <_ZN11Application20control_event_sourceE+0x19>
    2480:	90 93 ac 04 	sts	0x04AC, r25	; 0x8004ac <_ZN11Application20control_event_sourceE+0x1a>
    2484:	a0 93 ad 04 	sts	0x04AD, r26	; 0x8004ad <_ZN11Application20control_event_sourceE+0x1b>
    2488:	8d 8d       	ldd	r24, Y+29	; 0x1d
    248a:	80 93 ae 04 	sts	0x04AE, r24	; 0x8004ae <_ZN11Application20control_event_sourceE+0x1c>
    248e:	8b e1       	ldi	r24, 0x1B	; 27
    2490:	fe 01       	movw	r30, r28
    2492:	7e 96       	adiw	r30, 0x1e	; 30
    2494:	af ea       	ldi	r26, 0xAF	; 175
    2496:	b4 e0       	ldi	r27, 0x04	; 4
    2498:	01 90       	ld	r0, Z+
    249a:	0d 92       	st	X+, r0
    249c:	8a 95       	dec	r24
    249e:	e1 f7       	brne	.-8      	; 0x2498 <main+0x1c4>
    24a0:	ce 01       	movw	r24, r28
    24a2:	01 96       	adiw	r24, 0x01	; 1
    24a4:	0e 94 59 03 	call	0x6b2	; 0x6b2 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEED1Ev.lto_priv.143>
    24a8:	82 e9       	ldi	r24, 0x92	; 146
    24aa:	94 e0       	ldi	r25, 0x04	; 4
    24ac:	0e 94 7b 02 	call	0x4f6	; 0x4f6 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEE5setupEv>
    24b0:	f8 94       	cli
    24b2:	81 e6       	ldi	r24, 0x61	; 97
    24b4:	94 e0       	ldi	r25, 0x04	; 4
    24b6:	90 93 c6 03 	sts	0x03C6, r25	; 0x8003c6 <_ZN7Timer1_9_instanceE+0x1>
    24ba:	80 93 c5 03 	sts	0x03C5, r24	; 0x8003c5 <_ZN7Timer1_9_instanceE>
    24be:	87 b1       	in	r24, 0x07	; 7
    24c0:	8f 60       	ori	r24, 0x0F	; 15
    24c2:	87 b9       	out	0x07, r24	; 7
    24c4:	98 b1       	in	r25, 0x08	; 8
    24c6:	8f e0       	ldi	r24, 0x0F	; 15
    24c8:	89 27       	eor	r24, r25
    24ca:	88 b9       	out	0x08, r24	; 8
    24cc:	10 92 80 00 	sts	0x0080, r1	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    24d0:	10 92 81 00 	sts	0x0081, r1	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    24d4:	10 92 85 00 	sts	0x0085, r1	; 0x800085 <__TEXT_REGION_LENGTH__+0x7e0085>
    24d8:	10 92 84 00 	sts	0x0084, r1	; 0x800084 <__TEXT_REGION_LENGTH__+0x7e0084>
    24dc:	81 e1       	ldi	r24, 0x11	; 17
    24de:	9a e7       	ldi	r25, 0x7A	; 122
    24e0:	90 93 89 00 	sts	0x0089, r25	; 0x800089 <__TEXT_REGION_LENGTH__+0x7e0089>
    24e4:	80 93 88 00 	sts	0x0088, r24	; 0x800088 <__TEXT_REGION_LENGTH__+0x7e0088>
    24e8:	80 91 81 00 	lds	r24, 0x0081	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    24ec:	88 60       	ori	r24, 0x08	; 8
    24ee:	80 93 81 00 	sts	0x0081, r24	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    24f2:	80 91 81 00 	lds	r24, 0x0081	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    24f6:	84 60       	ori	r24, 0x04	; 4
    24f8:	80 93 81 00 	sts	0x0081, r24	; 0x800081 <__TEXT_REGION_LENGTH__+0x7e0081>
    24fc:	80 91 6f 00 	lds	r24, 0x006F	; 0x80006f <__TEXT_REGION_LENGTH__+0x7e006f>
    2500:	82 60       	ori	r24, 0x02	; 2
    2502:	80 93 6f 00 	sts	0x006F, r24	; 0x80006f <__TEXT_REGION_LENGTH__+0x7e006f>
    2506:	80 91 80 00 	lds	r24, 0x0080	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    250a:	80 64       	ori	r24, 0x40	; 64
    250c:	80 93 80 00 	sts	0x0080, r24	; 0x800080 <__TEXT_REGION_LENGTH__+0x7e0080>
    2510:	21 9a       	sbi	0x04, 1	; 4
    2512:	d0 92 63 04 	sts	0x0463, r13	; 0x800463 <_ZN11Application6timer1E+0x2>
    2516:	6d 2d       	mov	r22, r13
    2518:	70 e0       	ldi	r23, 0x00	; 0
    251a:	80 e0       	ldi	r24, 0x00	; 0
    251c:	90 e0       	ldi	r25, 0x00	; 0
    251e:	0e 94 be 18 	call	0x317c	; 0x317c <__floatsisf>
    2522:	20 e0       	ldi	r18, 0x00	; 0
    2524:	30 e0       	ldi	r19, 0x00	; 0
    2526:	40 e7       	ldi	r20, 0x70	; 112
    2528:	52 e4       	ldi	r21, 0x42	; 66
    252a:	0e 94 1b 18 	call	0x3036	; 0x3036 <__divsf3>
    252e:	60 93 66 04 	sts	0x0466, r22	; 0x800466 <_ZN11Application6timer1E+0x5>
    2532:	70 93 67 04 	sts	0x0467, r23	; 0x800467 <_ZN11Application6timer1E+0x6>
    2536:	80 93 68 04 	sts	0x0468, r24	; 0x800468 <_ZN11Application6timer1E+0x7>
    253a:	90 93 69 04 	sts	0x0469, r25	; 0x800469 <_ZN11Application6timer1E+0x8>
    253e:	8d 2d       	mov	r24, r13
    2540:	0e 94 d2 07 	call	0xfa4	; 0xfa4 <_ZN7Timer1_13set_hz_by_bpmEh>
    2544:	24 9a       	sbi	0x04, 4	; 4
    2546:	10 92 b0 00 	sts	0x00B0, r1	; 0x8000b0 <__TEXT_REGION_LENGTH__+0x7e00b0>
    254a:	10 92 b1 00 	sts	0x00B1, r1	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    254e:	10 92 b2 00 	sts	0x00B2, r1	; 0x8000b2 <__TEXT_REGION_LENGTH__+0x7e00b2>
    2552:	8f ef       	ldi	r24, 0xFF	; 255
    2554:	80 93 b3 00 	sts	0x00B3, r24	; 0x8000b3 <__TEXT_REGION_LENGTH__+0x7e00b3>
    2558:	80 91 b1 00 	lds	r24, 0x00B1	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    255c:	82 60       	ori	r24, 0x02	; 2
    255e:	80 93 b1 00 	sts	0x00B1, r24	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    2562:	80 91 b1 00 	lds	r24, 0x00B1	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    2566:	84 60       	ori	r24, 0x04	; 4
    2568:	80 93 b1 00 	sts	0x00B1, r24	; 0x8000b1 <__TEXT_REGION_LENGTH__+0x7e00b1>
    256c:	80 91 70 00 	lds	r24, 0x0070	; 0x800070 <__TEXT_REGION_LENGTH__+0x7e0070>
    2570:	82 60       	ori	r24, 0x02	; 2
    2572:	80 93 70 00 	sts	0x0070, r24	; 0x800070 <__TEXT_REGION_LENGTH__+0x7e0070>
    2576:	8b 2d       	mov	r24, r11
    2578:	0e 94 48 0c 	call	0x1890	; 0x1890 <_ZN7Timer1_18set_playback_stateEb.constprop.81>
    257c:	c0 92 50 04 	sts	0x0450, r12	; 0x800450 <_ZN11Application7ui_dataE+0x17>
    2580:	0e 94 5e 03 	call	0x6bc	; 0x6bc <_ZN11Application16flag_main_screenEv>
    2584:	0e 94 34 0c 	call	0x1868	; 0x1868 <_ZN6Eeprom19flag_save_requestedEv.constprop.82>
    2588:	10 92 6e 04 	sts	0x046E, r1	; 0x80046e <_ZN11Application6eepromE+0x4>
    258c:	83 e7       	ldi	r24, 0x73	; 115
    258e:	94 e0       	ldi	r25, 0x04	; 4
    2590:	90 93 3c 04 	sts	0x043C, r25	; 0x80043c <_ZN11Application7ui_dataE+0x3>
    2594:	80 93 3b 04 	sts	0x043B, r24	; 0x80043b <_ZN11Application7ui_dataE+0x2>
    2598:	0e 94 65 03 	call	0x6ca	; 0x6ca <_ZN11Application14update_ui_dataEv>
    259c:	80 91 5b 04 	lds	r24, 0x045B	; 0x80045b <_ZN11Application2uiE+0xa>
    25a0:	90 91 5c 04 	lds	r25, 0x045C	; 0x80045c <_ZN11Application2uiE+0xb>
    25a4:	fc 01       	movw	r30, r24
    25a6:	c4 82       	std	Z+4, r12	; 0x04
    25a8:	20 91 55 04 	lds	r18, 0x0455	; 0x800455 <_ZN11Application2uiE+0x4>
    25ac:	30 91 56 04 	lds	r19, 0x0456	; 0x800456 <_ZN11Application2uiE+0x5>
    25b0:	22 30       	cpi	r18, 0x02	; 2
    25b2:	31 05       	cpc	r19, r1
    25b4:	41 f0       	breq	.+16     	; 0x25c6 <main+0x2f2>
    25b6:	22 e0       	ldi	r18, 0x02	; 2
    25b8:	30 e0       	ldi	r19, 0x00	; 0
    25ba:	30 93 56 04 	sts	0x0456, r19	; 0x800456 <_ZN11Application2uiE+0x5>
    25be:	20 93 55 04 	sts	0x0455, r18	; 0x800455 <_ZN11Application2uiE+0x4>
    25c2:	0e 94 70 0c 	call	0x18e0	; 0x18e0 <_ZN6ScreenI6UiDataI15TrackCollectionILj3E5TrackEEE5enterEv.constprop.61>
    25c6:	78 94       	sei
    25c8:	00 e0       	ldi	r16, 0x00	; 0
    25ca:	10 e0       	ldi	r17, 0x00	; 0
    25cc:	80 91 0c 04 	lds	r24, 0x040C	; 0x80040c <_ZZN11Application4loopEvE3clk>
    25d0:	91 e0       	ldi	r25, 0x01	; 1
    25d2:	98 0f       	add	r25, r24
    25d4:	90 93 0c 04 	sts	0x040C, r25	; 0x80040c <_ZZN11Application4loopEvE3clk>
    25d8:	87 70       	andi	r24, 0x07	; 7
    25da:	11 f0       	breq	.+4      	; 0x25e0 <main+0x30c>
    25dc:	0e 94 5e 03 	call	0x6bc	; 0x6bc <_ZN11Application16flag_main_screenEv>
    25e0:	0e 94 65 03 	call	0x6ca	; 0x6ca <_ZN11Application14update_ui_dataEv>
    25e4:	e0 91 55 04 	lds	r30, 0x0455	; 0x800455 <_ZN11Application2uiE+0x4>
    25e8:	f0 91 56 04 	lds	r31, 0x0456	; 0x800456 <_ZN11Application2uiE+0x5>
    25ec:	ee 0f       	add	r30, r30
    25ee:	ff 1f       	adc	r31, r31
    25f0:	e9 5a       	subi	r30, 0xA9	; 169
    25f2:	fb 4f       	sbci	r31, 0xFB	; 251
    25f4:	a0 81       	ld	r26, Z
    25f6:	b1 81       	ldd	r27, Z+1	; 0x01
    25f8:	14 96       	adiw	r26, 0x04	; 4
    25fa:	8c 91       	ld	r24, X
    25fc:	14 97       	sbiw	r26, 0x04	; 4
    25fe:	88 23       	and	r24, r24
    2600:	59 f0       	breq	.+22     	; 0x2618 <main+0x344>
    2602:	14 96       	adiw	r26, 0x04	; 4
    2604:	1c 92       	st	X, r1
    2606:	14 97       	sbiw	r26, 0x04	; 4
    2608:	ed 91       	ld	r30, X+
    260a:	fc 91       	ld	r31, X
    260c:	11 97       	sbiw	r26, 0x01	; 1
    260e:	04 80       	ldd	r0, Z+4	; 0x04
    2610:	f5 81       	ldd	r31, Z+5	; 0x05
    2612:	e0 2d       	mov	r30, r0
    2614:	cd 01       	movw	r24, r26
    2616:	09 95       	icall
    2618:	6f e1       	ldi	r22, 0x1F	; 31
    261a:	70 e0       	ldi	r23, 0x00	; 0
    261c:	80 e0       	ldi	r24, 0x00	; 0
    261e:	90 e0       	ldi	r25, 0x00	; 0
    2620:	0e 94 de 10 	call	0x21bc	; 0x21bc <delay>
    2624:	01 15       	cp	r16, r1
    2626:	11 05       	cpc	r17, r1
    2628:	89 f2       	breq	.-94     	; 0x25cc <main+0x2f8>
    262a:	0e 94 00 00 	call	0	; 0x0 <__vectors>
    262e:	ce cf       	rjmp	.-100    	; 0x25cc <main+0x2f8>

00002630 <_GLOBAL__I_65535_0_application.cpp.o.3869>:
    2630:	8f 92       	push	r8
    2632:	9f 92       	push	r9
    2634:	af 92       	push	r10
    2636:	bf 92       	push	r11
    2638:	cf 92       	push	r12
    263a:	df 92       	push	r13
    263c:	ef 92       	push	r14
    263e:	ff 92       	push	r15
    2640:	0f 93       	push	r16
    2642:	1f 93       	push	r17
    2644:	cf 93       	push	r28
    2646:	df 93       	push	r29
    2648:	cd b7       	in	r28, 0x3d	; 61
    264a:	de b7       	in	r29, 0x3e	; 62
    264c:	29 97       	sbiw	r28, 0x09	; 9
    264e:	0f b6       	in	r0, 0x3f	; 63
    2650:	f8 94       	cli
    2652:	de bf       	out	0x3e, r29	; 62
    2654:	0f be       	out	0x3f, r0	; 63
    2656:	cd bf       	out	0x3d, r28	; 61
    2658:	10 92 14 04 	sts	0x0414, r1	; 0x800414 <Wire+0x3>
    265c:	10 92 13 04 	sts	0x0413, r1	; 0x800413 <Wire+0x2>
    2660:	88 ee       	ldi	r24, 0xE8	; 232
    2662:	93 e0       	ldi	r25, 0x03	; 3
    2664:	a0 e0       	ldi	r26, 0x00	; 0
    2666:	b0 e0       	ldi	r27, 0x00	; 0
    2668:	80 93 15 04 	sts	0x0415, r24	; 0x800415 <Wire+0x4>
    266c:	90 93 16 04 	sts	0x0416, r25	; 0x800416 <Wire+0x5>
    2670:	a0 93 17 04 	sts	0x0417, r26	; 0x800417 <Wire+0x6>
    2674:	b0 93 18 04 	sts	0x0418, r27	; 0x800418 <Wire+0x7>
    2678:	8d e0       	ldi	r24, 0x0D	; 13
    267a:	92 e0       	ldi	r25, 0x02	; 2
    267c:	90 93 12 04 	sts	0x0412, r25	; 0x800412 <Wire+0x1>
    2680:	80 93 11 04 	sts	0x0411, r24	; 0x800411 <Wire>
    2684:	10 92 20 04 	sts	0x0420, r1	; 0x800420 <_ZN3Lcd3lcdE+0x3>
    2688:	10 92 1f 04 	sts	0x041F, r1	; 0x80041f <_ZN3Lcd3lcdE+0x2>
    268c:	8f e1       	ldi	r24, 0x1F	; 31
    268e:	92 e0       	ldi	r25, 0x02	; 2
    2690:	90 93 1e 04 	sts	0x041E, r25	; 0x80041e <_ZN3Lcd3lcdE+0x1>
    2694:	80 93 1d 04 	sts	0x041D, r24	; 0x80041d <_ZN3Lcd3lcdE>
    2698:	8c e0       	ldi	r24, 0x0C	; 12
    269a:	80 93 21 04 	sts	0x0421, r24	; 0x800421 <_ZN3Lcd3lcdE+0x4>
    269e:	8f ef       	ldi	r24, 0xFF	; 255
    26a0:	80 93 22 04 	sts	0x0422, r24	; 0x800422 <_ZN3Lcd3lcdE+0x5>
    26a4:	8b e0       	ldi	r24, 0x0B	; 11
    26a6:	80 93 23 04 	sts	0x0423, r24	; 0x800423 <_ZN3Lcd3lcdE+0x6>
    26aa:	8a e0       	ldi	r24, 0x0A	; 10
    26ac:	80 93 24 04 	sts	0x0424, r24	; 0x800424 <_ZN3Lcd3lcdE+0x7>
    26b0:	88 e0       	ldi	r24, 0x08	; 8
    26b2:	80 93 25 04 	sts	0x0425, r24	; 0x800425 <_ZN3Lcd3lcdE+0x8>
    26b6:	87 e0       	ldi	r24, 0x07	; 7
    26b8:	80 93 26 04 	sts	0x0426, r24	; 0x800426 <_ZN3Lcd3lcdE+0x9>
    26bc:	84 e0       	ldi	r24, 0x04	; 4
    26be:	80 93 27 04 	sts	0x0427, r24	; 0x800427 <_ZN3Lcd3lcdE+0xa>
    26c2:	10 92 28 04 	sts	0x0428, r1	; 0x800428 <_ZN3Lcd3lcdE+0xb>
    26c6:	10 92 29 04 	sts	0x0429, r1	; 0x800429 <_ZN3Lcd3lcdE+0xc>
    26ca:	10 92 2a 04 	sts	0x042A, r1	; 0x80042a <_ZN3Lcd3lcdE+0xd>
    26ce:	10 92 2b 04 	sts	0x042B, r1	; 0x80042b <_ZN3Lcd3lcdE+0xe>
    26d2:	10 92 2c 04 	sts	0x042C, r1	; 0x80042c <_ZN3Lcd3lcdE+0xf>
    26d6:	61 e0       	ldi	r22, 0x01	; 1
    26d8:	80 e1       	ldi	r24, 0x10	; 16
    26da:	0e 94 d4 0c 	call	0x19a8	; 0x19a8 <_ZN13LiquidCrystal5beginEhhh.constprop.36>
    26de:	87 e0       	ldi	r24, 0x07	; 7
    26e0:	90 e0       	ldi	r25, 0x00	; 0
    26e2:	0e 94 b7 19 	call	0x336e	; 0x336e <malloc>
    26e6:	fc 01       	movw	r30, r24
    26e8:	13 82       	std	Z+3, r1	; 0x03
    26ea:	12 82       	std	Z+2, r1	; 0x02
    26ec:	8b e2       	ldi	r24, 0x2B	; 43
    26ee:	92 e0       	ldi	r25, 0x02	; 2
    26f0:	91 83       	std	Z+1, r25	; 0x01
    26f2:	80 83       	st	Z, r24
    26f4:	14 82       	std	Z+4, r1	; 0x04
    26f6:	16 82       	std	Z+6, r1	; 0x06
    26f8:	15 82       	std	Z+5, r1	; 0x05
    26fa:	f0 93 36 04 	sts	0x0436, r31	; 0x800436 <_ZN7Encoder8_encoderE+0x1>
    26fe:	e0 93 35 04 	sts	0x0435, r30	; 0x800435 <_ZN7Encoder8_encoderE>
    2702:	82 e0       	ldi	r24, 0x02	; 2
    2704:	90 e0       	ldi	r25, 0x00	; 0
    2706:	0e 94 b7 19 	call	0x336e	; 0x336e <malloc>
    270a:	23 e4       	ldi	r18, 0x43	; 67
    270c:	32 e0       	ldi	r19, 0x02	; 2
    270e:	dc 01       	movw	r26, r24
    2710:	2d 93       	st	X+, r18
    2712:	3c 93       	st	X, r19
    2714:	90 93 38 04 	sts	0x0438, r25	; 0x800438 <_ZN7Encoder8_encoderE+0x3>
    2718:	80 93 37 04 	sts	0x0437, r24	; 0x800437 <_ZN7Encoder8_encoderE+0x2>
    271c:	68 e7       	ldi	r22, 0x78	; 120
    271e:	82 e9       	ldi	r24, 0x92	; 146
    2720:	94 e0       	ldi	r25, 0x04	; 4
    2722:	0e 94 81 0c 	call	0x1902	; 0x1902 <_ZN13ControlSourceI17Buttonpad_PCF8754ILh63EEEC2Eh.constprop.53>
    2726:	83 eb       	ldi	r24, 0xB3	; 179
    2728:	92 e0       	ldi	r25, 0x02	; 2
    272a:	90 93 74 04 	sts	0x0474, r25	; 0x800474 <_ZN11Application7_tracksE+0x1>
    272e:	80 93 73 04 	sts	0x0473, r24	; 0x800473 <_ZN11Application7_tracksE>
    2732:	e3 e7       	ldi	r30, 0x73	; 115
    2734:	f4 e0       	ldi	r31, 0x04	; 4
    2736:	8e e8       	ldi	r24, 0x8E	; 142
    2738:	94 e0       	ldi	r25, 0x04	; 4
    273a:	69 ea       	ldi	r22, 0xA9	; 169
    273c:	72 e0       	ldi	r23, 0x02	; 2
    273e:	4f ef       	ldi	r20, 0xFF	; 255
    2740:	52 e0       	ldi	r21, 0x02	; 2
    2742:	21 e0       	ldi	r18, 0x01	; 1
    2744:	73 83       	std	Z+3, r23	; 0x03
    2746:	62 83       	std	Z+2, r22	; 0x02
    2748:	55 83       	std	Z+5, r21	; 0x05
    274a:	44 83       	std	Z+4, r20	; 0x04
    274c:	16 82       	std	Z+6, r1	; 0x06
    274e:	17 82       	std	Z+7, r1	; 0x07
    2750:	20 87       	std	Z+8, r18	; 0x08
    2752:	11 86       	std	Z+9, r1	; 0x09
    2754:	12 86       	std	Z+10, r1	; 0x0a
    2756:	39 96       	adiw	r30, 0x09	; 9
    2758:	8e 17       	cp	r24, r30
    275a:	9f 07       	cpc	r25, r31
    275c:	99 f7       	brne	.-26     	; 0x2744 <_GLOBAL__I_65535_0_application.cpp.o.3869+0x114>
    275e:	10 92 91 04 	sts	0x0491, r1	; 0x800491 <_ZN11Application7_tracksE+0x1e>
    2762:	10 92 90 04 	sts	0x0490, r1	; 0x800490 <_ZN11Application7_tracksE+0x1d>
    2766:	25 e7       	ldi	r18, 0x75	; 117
    2768:	e2 2e       	mov	r14, r18
    276a:	24 e0       	ldi	r18, 0x04	; 4
    276c:	f2 2e       	mov	r15, r18
    276e:	30 e9       	ldi	r19, 0x90	; 144
    2770:	c3 2e       	mov	r12, r19
    2772:	34 e0       	ldi	r19, 0x04	; 4
    2774:	d3 2e       	mov	r13, r19
    2776:	49 ea       	ldi	r20, 0xA9	; 169
    2778:	84 2e       	mov	r8, r20
    277a:	42 e0       	ldi	r20, 0x02	; 2
    277c:	94 2e       	mov	r9, r20
    277e:	5f ef       	ldi	r21, 0xFF	; 255
    2780:	a5 2e       	mov	r10, r21
    2782:	52 e0       	ldi	r21, 0x02	; 2
    2784:	b5 2e       	mov	r11, r21
    2786:	01 e0       	ldi	r16, 0x01	; 1
    2788:	d7 01       	movw	r26, r14
    278a:	ed 91       	ld	r30, X+
    278c:	fc 91       	ld	r31, X
    278e:	01 90       	ld	r0, Z+
    2790:	f0 81       	ld	r31, Z
    2792:	e0 2d       	mov	r30, r0
    2794:	9a 82       	std	Y+2, r9	; 0x02
    2796:	89 82       	std	Y+1, r8	; 0x01
    2798:	bc 82       	std	Y+4, r11	; 0x04
    279a:	ab 82       	std	Y+3, r10	; 0x03
    279c:	1d 82       	std	Y+5, r1	; 0x05
    279e:	1e 82       	std	Y+6, r1	; 0x06
    27a0:	11 e0       	ldi	r17, 0x01	; 1
    27a2:	0f 83       	std	Y+7, r16	; 0x07
    27a4:	18 86       	std	Y+8, r1	; 0x08
    27a6:	19 86       	std	Y+9, r1	; 0x09
    27a8:	be 01       	movw	r22, r28
    27aa:	6f 5f       	subi	r22, 0xFF	; 255
    27ac:	7f 4f       	sbci	r23, 0xFF	; 255
    27ae:	c7 01       	movw	r24, r14
    27b0:	09 95       	icall
    27b2:	b9 e0       	ldi	r27, 0x09	; 9
    27b4:	eb 0e       	add	r14, r27
    27b6:	f1 1c       	adc	r15, r1
    27b8:	ce 14       	cp	r12, r14
    27ba:	df 04       	cpc	r13, r15
    27bc:	29 f7       	brne	.-54     	; 0x2788 <_GLOBAL__I_65535_0_application.cpp.o.3869+0x158>
    27be:	8b eb       	ldi	r24, 0xBB	; 187
    27c0:	92 e0       	ldi	r25, 0x02	; 2
    27c2:	90 93 74 04 	sts	0x0474, r25	; 0x800474 <_ZN11Application7_tracksE+0x1>
    27c6:	80 93 73 04 	sts	0x0473, r24	; 0x800473 <_ZN11Application7_tracksE>
    27ca:	81 ea       	ldi	r24, 0xA1	; 161
    27cc:	92 e0       	ldi	r25, 0x02	; 2
    27ce:	90 93 6b 04 	sts	0x046B, r25	; 0x80046b <_ZN11Application6eepromE+0x1>
    27d2:	80 93 6a 04 	sts	0x046A, r24	; 0x80046a <_ZN11Application6eepromE>
    27d6:	83 e0       	ldi	r24, 0x03	; 3
    27d8:	93 e0       	ldi	r25, 0x03	; 3
    27da:	90 93 6d 04 	sts	0x046D, r25	; 0x80046d <_ZN11Application6eepromE+0x3>
    27de:	80 93 6c 04 	sts	0x046C, r24	; 0x80046c <_ZN11Application6eepromE+0x2>
    27e2:	10 92 6e 04 	sts	0x046E, r1	; 0x80046e <_ZN11Application6eepromE+0x4>
    27e6:	10 92 6f 04 	sts	0x046F, r1	; 0x80046f <_ZN11Application6eepromE+0x5>
    27ea:	10 92 70 04 	sts	0x0470, r1	; 0x800470 <_ZN11Application6eepromE+0x6>
    27ee:	10 92 71 04 	sts	0x0471, r1	; 0x800471 <_ZN11Application6eepromE+0x7>
    27f2:	10 92 72 04 	sts	0x0472, r1	; 0x800472 <_ZN11Application6eepromE+0x8>
    27f6:	89 e9       	ldi	r24, 0x99	; 153
    27f8:	92 e0       	ldi	r25, 0x02	; 2
    27fa:	90 93 62 04 	sts	0x0462, r25	; 0x800462 <_ZN11Application6timer1E+0x1>
    27fe:	80 93 61 04 	sts	0x0461, r24	; 0x800461 <_ZN11Application6timer1E>
    2802:	10 92 63 04 	sts	0x0463, r1	; 0x800463 <_ZN11Application6timer1E+0x2>
    2806:	10 93 64 04 	sts	0x0464, r17	; 0x800464 <_ZN11Application6timer1E+0x3>
    280a:	10 92 65 04 	sts	0x0465, r1	; 0x800465 <_ZN11Application6timer1E+0x4>
    280e:	10 92 66 04 	sts	0x0466, r1	; 0x800466 <_ZN11Application6timer1E+0x5>
    2812:	10 92 67 04 	sts	0x0467, r1	; 0x800467 <_ZN11Application6timer1E+0x6>
    2816:	10 92 68 04 	sts	0x0468, r1	; 0x800468 <_ZN11Application6timer1E+0x7>
    281a:	10 92 69 04 	sts	0x0469, r1	; 0x800469 <_ZN11Application6timer1E+0x8>
    281e:	81 e9       	ldi	r24, 0x91	; 145
    2820:	92 e0       	ldi	r25, 0x02	; 2
    2822:	90 93 60 04 	sts	0x0460, r25	; 0x800460 <_ZN11Application6timer2E+0x1>
    2826:	80 93 5f 04 	sts	0x045F, r24	; 0x80045f <_ZN11Application6timer2E>
    282a:	89 e8       	ldi	r24, 0x89	; 137
    282c:	92 e0       	ldi	r25, 0x02	; 2
    282e:	90 93 52 04 	sts	0x0452, r25	; 0x800452 <_ZN11Application2uiE+0x1>
    2832:	80 93 51 04 	sts	0x0451, r24	; 0x800451 <_ZN11Application2uiE>
    2836:	89 e3       	ldi	r24, 0x39	; 57
    2838:	e8 2e       	mov	r14, r24
    283a:	84 e0       	ldi	r24, 0x04	; 4
    283c:	f8 2e       	mov	r15, r24
    283e:	f0 92 54 04 	sts	0x0454, r15	; 0x800454 <_ZN11Application2uiE+0x3>
    2842:	e0 92 53 04 	sts	0x0453, r14	; 0x800453 <_ZN11Application2uiE+0x2>
    2846:	81 e0       	ldi	r24, 0x01	; 1
    2848:	90 e0       	ldi	r25, 0x00	; 0
    284a:	90 93 56 04 	sts	0x0456, r25	; 0x800456 <_ZN11Application2uiE+0x5>
    284e:	80 93 55 04 	sts	0x0455, r24	; 0x800455 <_ZN11Application2uiE+0x4>
    2852:	87 e0       	ldi	r24, 0x07	; 7
    2854:	90 e0       	ldi	r25, 0x00	; 0
    2856:	0e 94 b7 19 	call	0x336e	; 0x336e <malloc>
    285a:	fc 01       	movw	r30, r24
    285c:	96 e0       	ldi	r25, 0x06	; 6
    285e:	c9 2e       	mov	r12, r25
    2860:	93 e0       	ldi	r25, 0x03	; 3
    2862:	d9 2e       	mov	r13, r25
    2864:	d3 82       	std	Z+3, r13	; 0x03
    2866:	c2 82       	std	Z+2, r12	; 0x02
    2868:	14 83       	std	Z+4, r17	; 0x04
    286a:	f6 82       	std	Z+6, r15	; 0x06
    286c:	e5 82       	std	Z+5, r14	; 0x05
    286e:	8d e7       	ldi	r24, 0x7D	; 125
    2870:	92 e0       	ldi	r25, 0x02	; 2
    2872:	91 83       	std	Z+1, r25	; 0x01
    2874:	80 83       	st	Z, r24
    2876:	f0 93 58 04 	sts	0x0458, r31	; 0x800458 <_ZN11Application2uiE+0x7>
    287a:	e0 93 57 04 	sts	0x0457, r30	; 0x800457 <_ZN11Application2uiE+0x6>
    287e:	87 e0       	ldi	r24, 0x07	; 7
    2880:	90 e0       	ldi	r25, 0x00	; 0
    2882:	0e 94 b7 19 	call	0x336e	; 0x336e <malloc>
    2886:	fc 01       	movw	r30, r24
    2888:	d3 82       	std	Z+3, r13	; 0x03
    288a:	c2 82       	std	Z+2, r12	; 0x02
    288c:	14 83       	std	Z+4, r17	; 0x04
    288e:	f6 82       	std	Z+6, r15	; 0x06
    2890:	e5 82       	std	Z+5, r14	; 0x05
    2892:	81 e7       	ldi	r24, 0x71	; 113
    2894:	92 e0       	ldi	r25, 0x02	; 2
    2896:	91 83       	std	Z+1, r25	; 0x01
    2898:	80 83       	st	Z, r24
    289a:	f0 93 5a 04 	sts	0x045A, r31	; 0x80045a <_ZN11Application2uiE+0x9>
    289e:	e0 93 59 04 	sts	0x0459, r30	; 0x800459 <_ZN11Application2uiE+0x8>
    28a2:	8c e0       	ldi	r24, 0x0C	; 12
    28a4:	90 e0       	ldi	r25, 0x00	; 0
    28a6:	0e 94 b7 19 	call	0x336e	; 0x336e <malloc>
    28aa:	fc 01       	movw	r30, r24
    28ac:	d3 82       	std	Z+3, r13	; 0x03
    28ae:	c2 82       	std	Z+2, r12	; 0x02
    28b0:	14 83       	std	Z+4, r17	; 0x04
    28b2:	f6 82       	std	Z+6, r15	; 0x06
    28b4:	e5 82       	std	Z+5, r14	; 0x05
    28b6:	85 e6       	ldi	r24, 0x65	; 101
    28b8:	92 e0       	ldi	r25, 0x02	; 2
    28ba:	91 83       	std	Z+1, r25	; 0x01
    28bc:	80 83       	st	Z, r24
    28be:	17 82       	std	Z+7, r1	; 0x07
    28c0:	10 86       	std	Z+8, r1	; 0x08
    28c2:	11 86       	std	Z+9, r1	; 0x09
    28c4:	12 86       	std	Z+10, r1	; 0x0a
    28c6:	13 86       	std	Z+11, r1	; 0x0b
    28c8:	f0 93 5c 04 	sts	0x045C, r31	; 0x80045c <_ZN11Application2uiE+0xb>
    28cc:	e0 93 5b 04 	sts	0x045B, r30	; 0x80045b <_ZN11Application2uiE+0xa>
    28d0:	87 e0       	ldi	r24, 0x07	; 7
    28d2:	90 e0       	ldi	r25, 0x00	; 0
    28d4:	0e 94 b7 19 	call	0x336e	; 0x336e <malloc>
    28d8:	fc 01       	movw	r30, r24
    28da:	d3 82       	std	Z+3, r13	; 0x03
    28dc:	c2 82       	std	Z+2, r12	; 0x02
    28de:	14 83       	std	Z+4, r17	; 0x04
    28e0:	f6 82       	std	Z+6, r15	; 0x06
    28e2:	e5 82       	std	Z+5, r14	; 0x05
    28e4:	89 e5       	ldi	r24, 0x59	; 89
    28e6:	92 e0       	ldi	r25, 0x02	; 2
    28e8:	91 83       	std	Z+1, r25	; 0x01
    28ea:	80 83       	st	Z, r24
    28ec:	f0 93 5e 04 	sts	0x045E, r31	; 0x80045e <_ZN11Application2uiE+0xd>
    28f0:	e0 93 5d 04 	sts	0x045D, r30	; 0x80045d <_ZN11Application2uiE+0xc>
    28f4:	81 e5       	ldi	r24, 0x51	; 81
    28f6:	92 e0       	ldi	r25, 0x02	; 2
    28f8:	90 93 3a 04 	sts	0x043A, r25	; 0x80043a <_ZN11Application7ui_dataE+0x1>
    28fc:	80 93 39 04 	sts	0x0439, r24	; 0x800439 <_ZN11Application7ui_dataE>
    2900:	89 e0       	ldi	r24, 0x09	; 9
    2902:	93 e0       	ldi	r25, 0x03	; 3
    2904:	90 93 46 04 	sts	0x0446, r25	; 0x800446 <_ZN11Application7ui_dataE+0xd>
    2908:	80 93 45 04 	sts	0x0445, r24	; 0x800445 <_ZN11Application7ui_dataE+0xc>
    290c:	10 93 47 04 	sts	0x0447, r17	; 0x800447 <_ZN11Application7ui_dataE+0xe>
    2910:	8d e0       	ldi	r24, 0x0D	; 13
    2912:	93 e0       	ldi	r25, 0x03	; 3
    2914:	90 93 49 04 	sts	0x0449, r25	; 0x800449 <_ZN11Application7ui_dataE+0x10>
    2918:	80 93 48 04 	sts	0x0448, r24	; 0x800448 <_ZN11Application7ui_dataE+0xf>
    291c:	10 93 4a 04 	sts	0x044A, r17	; 0x80044a <_ZN11Application7ui_dataE+0x11>
    2920:	80 e1       	ldi	r24, 0x10	; 16
    2922:	93 e0       	ldi	r25, 0x03	; 3
    2924:	90 93 4c 04 	sts	0x044C, r25	; 0x80044c <_ZN11Application7ui_dataE+0x13>
    2928:	80 93 4b 04 	sts	0x044B, r24	; 0x80044b <_ZN11Application7ui_dataE+0x12>
    292c:	10 93 4d 04 	sts	0x044D, r17	; 0x80044d <_ZN11Application7ui_dataE+0x14>
    2930:	85 e1       	ldi	r24, 0x15	; 21
    2932:	93 e0       	ldi	r25, 0x03	; 3
    2934:	90 93 4f 04 	sts	0x044F, r25	; 0x80044f <_ZN11Application7ui_dataE+0x16>
    2938:	80 93 4e 04 	sts	0x044E, r24	; 0x80044e <_ZN11Application7ui_dataE+0x15>
    293c:	10 93 50 04 	sts	0x0450, r17	; 0x800450 <_ZN11Application7ui_dataE+0x17>
    2940:	29 96       	adiw	r28, 0x09	; 9
    2942:	0f b6       	in	r0, 0x3f	; 63
    2944:	f8 94       	cli
    2946:	de bf       	out	0x3e, r29	; 62
    2948:	0f be       	out	0x3f, r0	; 63
    294a:	cd bf       	out	0x3d, r28	; 61
    294c:	df 91       	pop	r29
    294e:	cf 91       	pop	r28
    2950:	1f 91       	pop	r17
    2952:	0f 91       	pop	r16
    2954:	ff 90       	pop	r15
    2956:	ef 90       	pop	r14
    2958:	df 90       	pop	r13
    295a:	cf 90       	pop	r12
    295c:	bf 90       	pop	r11
    295e:	af 90       	pop	r10
    2960:	9f 90       	pop	r9
    2962:	8f 90       	pop	r8
    2964:	08 95       	ret

00002966 <dtostrf>:
    2966:	ef 92       	push	r14
    2968:	0f 93       	push	r16
    296a:	1f 93       	push	r17
    296c:	cf 93       	push	r28
    296e:	df 93       	push	r29
    2970:	e8 01       	movw	r28, r16
    2972:	47 fd       	sbrc	r20, 7
    2974:	02 c0       	rjmp	.+4      	; 0x297a <dtostrf+0x14>
    2976:	34 e0       	ldi	r19, 0x04	; 4
    2978:	01 c0       	rjmp	.+2      	; 0x297c <dtostrf+0x16>
    297a:	34 e1       	ldi	r19, 0x14	; 20
    297c:	04 2e       	mov	r0, r20
    297e:	00 0c       	add	r0, r0
    2980:	55 0b       	sbc	r21, r21
    2982:	57 ff       	sbrs	r21, 7
    2984:	03 c0       	rjmp	.+6      	; 0x298c <dtostrf+0x26>
    2986:	51 95       	neg	r21
    2988:	41 95       	neg	r20
    298a:	51 09       	sbc	r21, r1
    298c:	e3 2e       	mov	r14, r19
    298e:	02 2f       	mov	r16, r18
    2990:	24 2f       	mov	r18, r20
    2992:	ae 01       	movw	r20, r28
    2994:	0e 94 d3 14 	call	0x29a6	; 0x29a6 <dtoa_prf>
    2998:	ce 01       	movw	r24, r28
    299a:	df 91       	pop	r29
    299c:	cf 91       	pop	r28
    299e:	1f 91       	pop	r17
    29a0:	0f 91       	pop	r16
    29a2:	ef 90       	pop	r14
    29a4:	08 95       	ret

000029a6 <dtoa_prf>:
    29a6:	a9 e0       	ldi	r26, 0x09	; 9
    29a8:	b0 e0       	ldi	r27, 0x00	; 0
    29aa:	e9 ed       	ldi	r30, 0xD9	; 217
    29ac:	f4 e1       	ldi	r31, 0x14	; 20
    29ae:	0c 94 21 17 	jmp	0x2e42	; 0x2e42 <__prologue_saves__+0xc>
    29b2:	6a 01       	movw	r12, r20
    29b4:	12 2f       	mov	r17, r18
    29b6:	b0 2e       	mov	r11, r16
    29b8:	2b e3       	ldi	r18, 0x3B	; 59
    29ba:	20 17       	cp	r18, r16
    29bc:	20 f0       	brcs	.+8      	; 0x29c6 <dtoa_prf+0x20>
    29be:	ff 24       	eor	r15, r15
    29c0:	f3 94       	inc	r15
    29c2:	f0 0e       	add	r15, r16
    29c4:	02 c0       	rjmp	.+4      	; 0x29ca <dtoa_prf+0x24>
    29c6:	2c e3       	ldi	r18, 0x3C	; 60
    29c8:	f2 2e       	mov	r15, r18
    29ca:	0f 2d       	mov	r16, r15
    29cc:	27 e0       	ldi	r18, 0x07	; 7
    29ce:	ae 01       	movw	r20, r28
    29d0:	4f 5f       	subi	r20, 0xFF	; 255
    29d2:	5f 4f       	sbci	r21, 0xFF	; 255
    29d4:	0e 94 2d 16 	call	0x2c5a	; 0x2c5a <__ftoa_engine>
    29d8:	bc 01       	movw	r22, r24
    29da:	49 81       	ldd	r20, Y+1	; 0x01
    29dc:	84 2f       	mov	r24, r20
    29de:	89 70       	andi	r24, 0x09	; 9
    29e0:	81 30       	cpi	r24, 0x01	; 1
    29e2:	31 f0       	breq	.+12     	; 0x29f0 <dtoa_prf+0x4a>
    29e4:	e1 fc       	sbrc	r14, 1
    29e6:	06 c0       	rjmp	.+12     	; 0x29f4 <dtoa_prf+0x4e>
    29e8:	e0 fe       	sbrs	r14, 0
    29ea:	06 c0       	rjmp	.+12     	; 0x29f8 <dtoa_prf+0x52>
    29ec:	90 e2       	ldi	r25, 0x20	; 32
    29ee:	05 c0       	rjmp	.+10     	; 0x29fa <dtoa_prf+0x54>
    29f0:	9d e2       	ldi	r25, 0x2D	; 45
    29f2:	03 c0       	rjmp	.+6      	; 0x29fa <dtoa_prf+0x54>
    29f4:	9b e2       	ldi	r25, 0x2B	; 43
    29f6:	01 c0       	rjmp	.+2      	; 0x29fa <dtoa_prf+0x54>
    29f8:	90 e0       	ldi	r25, 0x00	; 0
    29fa:	5e 2d       	mov	r21, r14
    29fc:	50 71       	andi	r21, 0x10	; 16
    29fe:	43 ff       	sbrs	r20, 3
    2a00:	3c c0       	rjmp	.+120    	; 0x2a7a <dtoa_prf+0xd4>
    2a02:	91 11       	cpse	r25, r1
    2a04:	02 c0       	rjmp	.+4      	; 0x2a0a <dtoa_prf+0x64>
    2a06:	83 e0       	ldi	r24, 0x03	; 3
    2a08:	01 c0       	rjmp	.+2      	; 0x2a0c <dtoa_prf+0x66>
    2a0a:	84 e0       	ldi	r24, 0x04	; 4
    2a0c:	81 17       	cp	r24, r17
    2a0e:	18 f4       	brcc	.+6      	; 0x2a16 <dtoa_prf+0x70>
    2a10:	21 2f       	mov	r18, r17
    2a12:	28 1b       	sub	r18, r24
    2a14:	01 c0       	rjmp	.+2      	; 0x2a18 <dtoa_prf+0x72>
    2a16:	20 e0       	ldi	r18, 0x00	; 0
    2a18:	51 11       	cpse	r21, r1
    2a1a:	0b c0       	rjmp	.+22     	; 0x2a32 <dtoa_prf+0x8c>
    2a1c:	f6 01       	movw	r30, r12
    2a1e:	82 2f       	mov	r24, r18
    2a20:	30 e2       	ldi	r19, 0x20	; 32
    2a22:	88 23       	and	r24, r24
    2a24:	19 f0       	breq	.+6      	; 0x2a2c <dtoa_prf+0x86>
    2a26:	31 93       	st	Z+, r19
    2a28:	81 50       	subi	r24, 0x01	; 1
    2a2a:	fb cf       	rjmp	.-10     	; 0x2a22 <dtoa_prf+0x7c>
    2a2c:	c2 0e       	add	r12, r18
    2a2e:	d1 1c       	adc	r13, r1
    2a30:	20 e0       	ldi	r18, 0x00	; 0
    2a32:	99 23       	and	r25, r25
    2a34:	29 f0       	breq	.+10     	; 0x2a40 <dtoa_prf+0x9a>
    2a36:	d6 01       	movw	r26, r12
    2a38:	9c 93       	st	X, r25
    2a3a:	f6 01       	movw	r30, r12
    2a3c:	31 96       	adiw	r30, 0x01	; 1
    2a3e:	6f 01       	movw	r12, r30
    2a40:	c6 01       	movw	r24, r12
    2a42:	03 96       	adiw	r24, 0x03	; 3
    2a44:	e2 fe       	sbrs	r14, 2
    2a46:	0a c0       	rjmp	.+20     	; 0x2a5c <dtoa_prf+0xb6>
    2a48:	3e e4       	ldi	r19, 0x4E	; 78
    2a4a:	d6 01       	movw	r26, r12
    2a4c:	3c 93       	st	X, r19
    2a4e:	41 e4       	ldi	r20, 0x41	; 65
    2a50:	11 96       	adiw	r26, 0x01	; 1
    2a52:	4c 93       	st	X, r20
    2a54:	11 97       	sbiw	r26, 0x01	; 1
    2a56:	12 96       	adiw	r26, 0x02	; 2
    2a58:	3c 93       	st	X, r19
    2a5a:	06 c0       	rjmp	.+12     	; 0x2a68 <dtoa_prf+0xc2>
    2a5c:	3e e6       	ldi	r19, 0x6E	; 110
    2a5e:	f6 01       	movw	r30, r12
    2a60:	30 83       	st	Z, r19
    2a62:	41 e6       	ldi	r20, 0x61	; 97
    2a64:	41 83       	std	Z+1, r20	; 0x01
    2a66:	32 83       	std	Z+2, r19	; 0x02
    2a68:	fc 01       	movw	r30, r24
    2a6a:	32 2f       	mov	r19, r18
    2a6c:	40 e2       	ldi	r20, 0x20	; 32
    2a6e:	33 23       	and	r19, r19
    2a70:	09 f4       	brne	.+2      	; 0x2a74 <dtoa_prf+0xce>
    2a72:	42 c0       	rjmp	.+132    	; 0x2af8 <dtoa_prf+0x152>
    2a74:	41 93       	st	Z+, r20
    2a76:	31 50       	subi	r19, 0x01	; 1
    2a78:	fa cf       	rjmp	.-12     	; 0x2a6e <dtoa_prf+0xc8>
    2a7a:	42 ff       	sbrs	r20, 2
    2a7c:	44 c0       	rjmp	.+136    	; 0x2b06 <dtoa_prf+0x160>
    2a7e:	91 11       	cpse	r25, r1
    2a80:	02 c0       	rjmp	.+4      	; 0x2a86 <dtoa_prf+0xe0>
    2a82:	83 e0       	ldi	r24, 0x03	; 3
    2a84:	01 c0       	rjmp	.+2      	; 0x2a88 <dtoa_prf+0xe2>
    2a86:	84 e0       	ldi	r24, 0x04	; 4
    2a88:	81 17       	cp	r24, r17
    2a8a:	18 f4       	brcc	.+6      	; 0x2a92 <dtoa_prf+0xec>
    2a8c:	21 2f       	mov	r18, r17
    2a8e:	28 1b       	sub	r18, r24
    2a90:	01 c0       	rjmp	.+2      	; 0x2a94 <dtoa_prf+0xee>
    2a92:	20 e0       	ldi	r18, 0x00	; 0
    2a94:	51 11       	cpse	r21, r1
    2a96:	0b c0       	rjmp	.+22     	; 0x2aae <dtoa_prf+0x108>
    2a98:	f6 01       	movw	r30, r12
    2a9a:	82 2f       	mov	r24, r18
    2a9c:	30 e2       	ldi	r19, 0x20	; 32
    2a9e:	88 23       	and	r24, r24
    2aa0:	19 f0       	breq	.+6      	; 0x2aa8 <dtoa_prf+0x102>
    2aa2:	31 93       	st	Z+, r19
    2aa4:	81 50       	subi	r24, 0x01	; 1
    2aa6:	fb cf       	rjmp	.-10     	; 0x2a9e <dtoa_prf+0xf8>
    2aa8:	c2 0e       	add	r12, r18
    2aaa:	d1 1c       	adc	r13, r1
    2aac:	20 e0       	ldi	r18, 0x00	; 0
    2aae:	99 23       	and	r25, r25
    2ab0:	29 f0       	breq	.+10     	; 0x2abc <dtoa_prf+0x116>
    2ab2:	d6 01       	movw	r26, r12
    2ab4:	9c 93       	st	X, r25
    2ab6:	f6 01       	movw	r30, r12
    2ab8:	31 96       	adiw	r30, 0x01	; 1
    2aba:	6f 01       	movw	r12, r30
    2abc:	c6 01       	movw	r24, r12
    2abe:	03 96       	adiw	r24, 0x03	; 3
    2ac0:	e2 fe       	sbrs	r14, 2
    2ac2:	0b c0       	rjmp	.+22     	; 0x2ada <dtoa_prf+0x134>
    2ac4:	39 e4       	ldi	r19, 0x49	; 73
    2ac6:	d6 01       	movw	r26, r12
    2ac8:	3c 93       	st	X, r19
    2aca:	3e e4       	ldi	r19, 0x4E	; 78
    2acc:	11 96       	adiw	r26, 0x01	; 1
    2ace:	3c 93       	st	X, r19
    2ad0:	11 97       	sbiw	r26, 0x01	; 1
    2ad2:	36 e4       	ldi	r19, 0x46	; 70
    2ad4:	12 96       	adiw	r26, 0x02	; 2
    2ad6:	3c 93       	st	X, r19
    2ad8:	07 c0       	rjmp	.+14     	; 0x2ae8 <dtoa_prf+0x142>
    2ada:	39 e6       	ldi	r19, 0x69	; 105
    2adc:	f6 01       	movw	r30, r12
    2ade:	30 83       	st	Z, r19
    2ae0:	3e e6       	ldi	r19, 0x6E	; 110
    2ae2:	31 83       	std	Z+1, r19	; 0x01
    2ae4:	36 e6       	ldi	r19, 0x66	; 102
    2ae6:	32 83       	std	Z+2, r19	; 0x02
    2ae8:	fc 01       	movw	r30, r24
    2aea:	32 2f       	mov	r19, r18
    2aec:	40 e2       	ldi	r20, 0x20	; 32
    2aee:	33 23       	and	r19, r19
    2af0:	19 f0       	breq	.+6      	; 0x2af8 <dtoa_prf+0x152>
    2af2:	41 93       	st	Z+, r20
    2af4:	31 50       	subi	r19, 0x01	; 1
    2af6:	fb cf       	rjmp	.-10     	; 0x2aee <dtoa_prf+0x148>
    2af8:	fc 01       	movw	r30, r24
    2afa:	e2 0f       	add	r30, r18
    2afc:	f1 1d       	adc	r31, r1
    2afe:	10 82       	st	Z, r1
    2b00:	8e ef       	ldi	r24, 0xFE	; 254
    2b02:	9f ef       	ldi	r25, 0xFF	; 255
    2b04:	a6 c0       	rjmp	.+332    	; 0x2c52 <dtoa_prf+0x2ac>
    2b06:	21 e0       	ldi	r18, 0x01	; 1
    2b08:	30 e0       	ldi	r19, 0x00	; 0
    2b0a:	91 11       	cpse	r25, r1
    2b0c:	02 c0       	rjmp	.+4      	; 0x2b12 <dtoa_prf+0x16c>
    2b0e:	20 e0       	ldi	r18, 0x00	; 0
    2b10:	30 e0       	ldi	r19, 0x00	; 0
    2b12:	16 16       	cp	r1, r22
    2b14:	17 06       	cpc	r1, r23
    2b16:	1c f4       	brge	.+6      	; 0x2b1e <dtoa_prf+0x178>
    2b18:	fb 01       	movw	r30, r22
    2b1a:	31 96       	adiw	r30, 0x01	; 1
    2b1c:	02 c0       	rjmp	.+4      	; 0x2b22 <dtoa_prf+0x17c>
    2b1e:	e1 e0       	ldi	r30, 0x01	; 1
    2b20:	f0 e0       	ldi	r31, 0x00	; 0
    2b22:	2e 0f       	add	r18, r30
    2b24:	3f 1f       	adc	r19, r31
    2b26:	bb 20       	and	r11, r11
    2b28:	21 f0       	breq	.+8      	; 0x2b32 <dtoa_prf+0x18c>
    2b2a:	eb 2d       	mov	r30, r11
    2b2c:	f0 e0       	ldi	r31, 0x00	; 0
    2b2e:	31 96       	adiw	r30, 0x01	; 1
    2b30:	02 c0       	rjmp	.+4      	; 0x2b36 <dtoa_prf+0x190>
    2b32:	e0 e0       	ldi	r30, 0x00	; 0
    2b34:	f0 e0       	ldi	r31, 0x00	; 0
    2b36:	2e 0f       	add	r18, r30
    2b38:	3f 1f       	adc	r19, r31
    2b3a:	e1 2f       	mov	r30, r17
    2b3c:	f0 e0       	ldi	r31, 0x00	; 0
    2b3e:	2e 17       	cp	r18, r30
    2b40:	3f 07       	cpc	r19, r31
    2b42:	1c f4       	brge	.+6      	; 0x2b4a <dtoa_prf+0x1a4>
    2b44:	12 1b       	sub	r17, r18
    2b46:	21 2f       	mov	r18, r17
    2b48:	01 c0       	rjmp	.+2      	; 0x2b4c <dtoa_prf+0x1a6>
    2b4a:	20 e0       	ldi	r18, 0x00	; 0
    2b4c:	8e 2d       	mov	r24, r14
    2b4e:	88 71       	andi	r24, 0x18	; 24
    2b50:	59 f4       	brne	.+22     	; 0x2b68 <dtoa_prf+0x1c2>
    2b52:	f6 01       	movw	r30, r12
    2b54:	82 2f       	mov	r24, r18
    2b56:	30 e2       	ldi	r19, 0x20	; 32
    2b58:	88 23       	and	r24, r24
    2b5a:	19 f0       	breq	.+6      	; 0x2b62 <dtoa_prf+0x1bc>
    2b5c:	31 93       	st	Z+, r19
    2b5e:	81 50       	subi	r24, 0x01	; 1
    2b60:	fb cf       	rjmp	.-10     	; 0x2b58 <dtoa_prf+0x1b2>
    2b62:	c2 0e       	add	r12, r18
    2b64:	d1 1c       	adc	r13, r1
    2b66:	20 e0       	ldi	r18, 0x00	; 0
    2b68:	99 23       	and	r25, r25
    2b6a:	29 f0       	breq	.+10     	; 0x2b76 <dtoa_prf+0x1d0>
    2b6c:	d6 01       	movw	r26, r12
    2b6e:	9c 93       	st	X, r25
    2b70:	f6 01       	movw	r30, r12
    2b72:	31 96       	adiw	r30, 0x01	; 1
    2b74:	6f 01       	movw	r12, r30
    2b76:	51 11       	cpse	r21, r1
    2b78:	0b c0       	rjmp	.+22     	; 0x2b90 <dtoa_prf+0x1ea>
    2b7a:	f6 01       	movw	r30, r12
    2b7c:	82 2f       	mov	r24, r18
    2b7e:	90 e3       	ldi	r25, 0x30	; 48
    2b80:	88 23       	and	r24, r24
    2b82:	19 f0       	breq	.+6      	; 0x2b8a <dtoa_prf+0x1e4>
    2b84:	91 93       	st	Z+, r25
    2b86:	81 50       	subi	r24, 0x01	; 1
    2b88:	fb cf       	rjmp	.-10     	; 0x2b80 <dtoa_prf+0x1da>
    2b8a:	c2 0e       	add	r12, r18
    2b8c:	d1 1c       	adc	r13, r1
    2b8e:	20 e0       	ldi	r18, 0x00	; 0
    2b90:	0f 2d       	mov	r16, r15
    2b92:	06 0f       	add	r16, r22
    2b94:	9a 81       	ldd	r25, Y+2	; 0x02
    2b96:	34 2f       	mov	r19, r20
    2b98:	30 71       	andi	r19, 0x10	; 16
    2b9a:	44 ff       	sbrs	r20, 4
    2b9c:	03 c0       	rjmp	.+6      	; 0x2ba4 <dtoa_prf+0x1fe>
    2b9e:	91 33       	cpi	r25, 0x31	; 49
    2ba0:	09 f4       	brne	.+2      	; 0x2ba4 <dtoa_prf+0x1fe>
    2ba2:	01 50       	subi	r16, 0x01	; 1
    2ba4:	10 16       	cp	r1, r16
    2ba6:	24 f4       	brge	.+8      	; 0x2bb0 <dtoa_prf+0x20a>
    2ba8:	09 30       	cpi	r16, 0x09	; 9
    2baa:	18 f0       	brcs	.+6      	; 0x2bb2 <dtoa_prf+0x20c>
    2bac:	08 e0       	ldi	r16, 0x08	; 8
    2bae:	01 c0       	rjmp	.+2      	; 0x2bb2 <dtoa_prf+0x20c>
    2bb0:	01 e0       	ldi	r16, 0x01	; 1
    2bb2:	ab 01       	movw	r20, r22
    2bb4:	77 ff       	sbrs	r23, 7
    2bb6:	02 c0       	rjmp	.+4      	; 0x2bbc <dtoa_prf+0x216>
    2bb8:	40 e0       	ldi	r20, 0x00	; 0
    2bba:	50 e0       	ldi	r21, 0x00	; 0
    2bbc:	fb 01       	movw	r30, r22
    2bbe:	e4 1b       	sub	r30, r20
    2bc0:	f5 0b       	sbc	r31, r21
    2bc2:	a1 e0       	ldi	r26, 0x01	; 1
    2bc4:	b0 e0       	ldi	r27, 0x00	; 0
    2bc6:	ac 0f       	add	r26, r28
    2bc8:	bd 1f       	adc	r27, r29
    2bca:	ea 0f       	add	r30, r26
    2bcc:	fb 1f       	adc	r31, r27
    2bce:	8e e2       	ldi	r24, 0x2E	; 46
    2bd0:	a8 2e       	mov	r10, r24
    2bd2:	4b 01       	movw	r8, r22
    2bd4:	80 1a       	sub	r8, r16
    2bd6:	91 08       	sbc	r9, r1
    2bd8:	0b 2d       	mov	r16, r11
    2bda:	10 e0       	ldi	r17, 0x00	; 0
    2bdc:	11 95       	neg	r17
    2bde:	01 95       	neg	r16
    2be0:	11 09       	sbc	r17, r1
    2be2:	4f 3f       	cpi	r20, 0xFF	; 255
    2be4:	bf ef       	ldi	r27, 0xFF	; 255
    2be6:	5b 07       	cpc	r21, r27
    2be8:	21 f4       	brne	.+8      	; 0x2bf2 <dtoa_prf+0x24c>
    2bea:	d6 01       	movw	r26, r12
    2bec:	ac 92       	st	X, r10
    2bee:	11 96       	adiw	r26, 0x01	; 1
    2bf0:	6d 01       	movw	r12, r26
    2bf2:	64 17       	cp	r22, r20
    2bf4:	75 07       	cpc	r23, r21
    2bf6:	2c f0       	brlt	.+10     	; 0x2c02 <dtoa_prf+0x25c>
    2bf8:	84 16       	cp	r8, r20
    2bfa:	95 06       	cpc	r9, r21
    2bfc:	14 f4       	brge	.+4      	; 0x2c02 <dtoa_prf+0x25c>
    2bfe:	81 81       	ldd	r24, Z+1	; 0x01
    2c00:	01 c0       	rjmp	.+2      	; 0x2c04 <dtoa_prf+0x25e>
    2c02:	80 e3       	ldi	r24, 0x30	; 48
    2c04:	41 50       	subi	r20, 0x01	; 1
    2c06:	51 09       	sbc	r21, r1
    2c08:	31 96       	adiw	r30, 0x01	; 1
    2c0a:	d6 01       	movw	r26, r12
    2c0c:	11 96       	adiw	r26, 0x01	; 1
    2c0e:	7d 01       	movw	r14, r26
    2c10:	40 17       	cp	r20, r16
    2c12:	51 07       	cpc	r21, r17
    2c14:	24 f0       	brlt	.+8      	; 0x2c1e <dtoa_prf+0x278>
    2c16:	d6 01       	movw	r26, r12
    2c18:	8c 93       	st	X, r24
    2c1a:	67 01       	movw	r12, r14
    2c1c:	e2 cf       	rjmp	.-60     	; 0x2be2 <dtoa_prf+0x23c>
    2c1e:	64 17       	cp	r22, r20
    2c20:	75 07       	cpc	r23, r21
    2c22:	39 f4       	brne	.+14     	; 0x2c32 <dtoa_prf+0x28c>
    2c24:	96 33       	cpi	r25, 0x36	; 54
    2c26:	20 f4       	brcc	.+8      	; 0x2c30 <dtoa_prf+0x28a>
    2c28:	95 33       	cpi	r25, 0x35	; 53
    2c2a:	19 f4       	brne	.+6      	; 0x2c32 <dtoa_prf+0x28c>
    2c2c:	31 11       	cpse	r19, r1
    2c2e:	01 c0       	rjmp	.+2      	; 0x2c32 <dtoa_prf+0x28c>
    2c30:	81 e3       	ldi	r24, 0x31	; 49
    2c32:	f6 01       	movw	r30, r12
    2c34:	80 83       	st	Z, r24
    2c36:	f7 01       	movw	r30, r14
    2c38:	82 2f       	mov	r24, r18
    2c3a:	90 e2       	ldi	r25, 0x20	; 32
    2c3c:	88 23       	and	r24, r24
    2c3e:	19 f0       	breq	.+6      	; 0x2c46 <dtoa_prf+0x2a0>
    2c40:	91 93       	st	Z+, r25
    2c42:	81 50       	subi	r24, 0x01	; 1
    2c44:	fb cf       	rjmp	.-10     	; 0x2c3c <dtoa_prf+0x296>
    2c46:	f7 01       	movw	r30, r14
    2c48:	e2 0f       	add	r30, r18
    2c4a:	f1 1d       	adc	r31, r1
    2c4c:	10 82       	st	Z, r1
    2c4e:	80 e0       	ldi	r24, 0x00	; 0
    2c50:	90 e0       	ldi	r25, 0x00	; 0
    2c52:	29 96       	adiw	r28, 0x09	; 9
    2c54:	ec e0       	ldi	r30, 0x0C	; 12
    2c56:	0c 94 3d 17 	jmp	0x2e7a	; 0x2e7a <__epilogue_restores__+0xc>

00002c5a <__ftoa_engine>:
    2c5a:	28 30       	cpi	r18, 0x08	; 8
    2c5c:	08 f0       	brcs	.+2      	; 0x2c60 <__ftoa_engine+0x6>
    2c5e:	27 e0       	ldi	r18, 0x07	; 7
    2c60:	33 27       	eor	r19, r19
    2c62:	da 01       	movw	r26, r20
    2c64:	99 0f       	add	r25, r25
    2c66:	31 1d       	adc	r19, r1
    2c68:	87 fd       	sbrc	r24, 7
    2c6a:	91 60       	ori	r25, 0x01	; 1
    2c6c:	00 96       	adiw	r24, 0x00	; 0
    2c6e:	61 05       	cpc	r22, r1
    2c70:	71 05       	cpc	r23, r1
    2c72:	39 f4       	brne	.+14     	; 0x2c82 <__ftoa_engine+0x28>
    2c74:	32 60       	ori	r19, 0x02	; 2
    2c76:	2e 5f       	subi	r18, 0xFE	; 254
    2c78:	3d 93       	st	X+, r19
    2c7a:	30 e3       	ldi	r19, 0x30	; 48
    2c7c:	2a 95       	dec	r18
    2c7e:	e1 f7       	brne	.-8      	; 0x2c78 <__ftoa_engine+0x1e>
    2c80:	08 95       	ret
    2c82:	9f 3f       	cpi	r25, 0xFF	; 255
    2c84:	30 f0       	brcs	.+12     	; 0x2c92 <__ftoa_engine+0x38>
    2c86:	80 38       	cpi	r24, 0x80	; 128
    2c88:	71 05       	cpc	r23, r1
    2c8a:	61 05       	cpc	r22, r1
    2c8c:	09 f0       	breq	.+2      	; 0x2c90 <__ftoa_engine+0x36>
    2c8e:	3c 5f       	subi	r19, 0xFC	; 252
    2c90:	3c 5f       	subi	r19, 0xFC	; 252
    2c92:	3d 93       	st	X+, r19
    2c94:	91 30       	cpi	r25, 0x01	; 1
    2c96:	08 f0       	brcs	.+2      	; 0x2c9a <__ftoa_engine+0x40>
    2c98:	80 68       	ori	r24, 0x80	; 128
    2c9a:	91 1d       	adc	r25, r1
    2c9c:	df 93       	push	r29
    2c9e:	cf 93       	push	r28
    2ca0:	1f 93       	push	r17
    2ca2:	0f 93       	push	r16
    2ca4:	ff 92       	push	r15
    2ca6:	ef 92       	push	r14
    2ca8:	19 2f       	mov	r17, r25
    2caa:	98 7f       	andi	r25, 0xF8	; 248
    2cac:	96 95       	lsr	r25
    2cae:	e9 2f       	mov	r30, r25
    2cb0:	96 95       	lsr	r25
    2cb2:	96 95       	lsr	r25
    2cb4:	e9 0f       	add	r30, r25
    2cb6:	ff 27       	eor	r31, r31
    2cb8:	ee 53       	subi	r30, 0x3E	; 62
    2cba:	ff 4f       	sbci	r31, 0xFF	; 255
    2cbc:	99 27       	eor	r25, r25
    2cbe:	33 27       	eor	r19, r19
    2cc0:	ee 24       	eor	r14, r14
    2cc2:	ff 24       	eor	r15, r15
    2cc4:	a7 01       	movw	r20, r14
    2cc6:	e7 01       	movw	r28, r14
    2cc8:	05 90       	lpm	r0, Z+
    2cca:	08 94       	sec
    2ccc:	07 94       	ror	r0
    2cce:	28 f4       	brcc	.+10     	; 0x2cda <__ftoa_engine+0x80>
    2cd0:	36 0f       	add	r19, r22
    2cd2:	e7 1e       	adc	r14, r23
    2cd4:	f8 1e       	adc	r15, r24
    2cd6:	49 1f       	adc	r20, r25
    2cd8:	51 1d       	adc	r21, r1
    2cda:	66 0f       	add	r22, r22
    2cdc:	77 1f       	adc	r23, r23
    2cde:	88 1f       	adc	r24, r24
    2ce0:	99 1f       	adc	r25, r25
    2ce2:	06 94       	lsr	r0
    2ce4:	a1 f7       	brne	.-24     	; 0x2cce <__ftoa_engine+0x74>
    2ce6:	05 90       	lpm	r0, Z+
    2ce8:	07 94       	ror	r0
    2cea:	28 f4       	brcc	.+10     	; 0x2cf6 <__ftoa_engine+0x9c>
    2cec:	e7 0e       	add	r14, r23
    2cee:	f8 1e       	adc	r15, r24
    2cf0:	49 1f       	adc	r20, r25
    2cf2:	56 1f       	adc	r21, r22
    2cf4:	c1 1d       	adc	r28, r1
    2cf6:	77 0f       	add	r23, r23
    2cf8:	88 1f       	adc	r24, r24
    2cfa:	99 1f       	adc	r25, r25
    2cfc:	66 1f       	adc	r22, r22
    2cfe:	06 94       	lsr	r0
    2d00:	a1 f7       	brne	.-24     	; 0x2cea <__ftoa_engine+0x90>
    2d02:	05 90       	lpm	r0, Z+
    2d04:	07 94       	ror	r0
    2d06:	28 f4       	brcc	.+10     	; 0x2d12 <__ftoa_engine+0xb8>
    2d08:	f8 0e       	add	r15, r24
    2d0a:	49 1f       	adc	r20, r25
    2d0c:	56 1f       	adc	r21, r22
    2d0e:	c7 1f       	adc	r28, r23
    2d10:	d1 1d       	adc	r29, r1
    2d12:	88 0f       	add	r24, r24
    2d14:	99 1f       	adc	r25, r25
    2d16:	66 1f       	adc	r22, r22
    2d18:	77 1f       	adc	r23, r23
    2d1a:	06 94       	lsr	r0
    2d1c:	a1 f7       	brne	.-24     	; 0x2d06 <__ftoa_engine+0xac>
    2d1e:	05 90       	lpm	r0, Z+
    2d20:	07 94       	ror	r0
    2d22:	20 f4       	brcc	.+8      	; 0x2d2c <__ftoa_engine+0xd2>
    2d24:	49 0f       	add	r20, r25
    2d26:	56 1f       	adc	r21, r22
    2d28:	c7 1f       	adc	r28, r23
    2d2a:	d8 1f       	adc	r29, r24
    2d2c:	99 0f       	add	r25, r25
    2d2e:	66 1f       	adc	r22, r22
    2d30:	77 1f       	adc	r23, r23
    2d32:	88 1f       	adc	r24, r24
    2d34:	06 94       	lsr	r0
    2d36:	a9 f7       	brne	.-22     	; 0x2d22 <__ftoa_engine+0xc8>
    2d38:	84 91       	lpm	r24, Z
    2d3a:	10 95       	com	r17
    2d3c:	17 70       	andi	r17, 0x07	; 7
    2d3e:	41 f0       	breq	.+16     	; 0x2d50 <__ftoa_engine+0xf6>
    2d40:	d6 95       	lsr	r29
    2d42:	c7 95       	ror	r28
    2d44:	57 95       	ror	r21
    2d46:	47 95       	ror	r20
    2d48:	f7 94       	ror	r15
    2d4a:	e7 94       	ror	r14
    2d4c:	1a 95       	dec	r17
    2d4e:	c1 f7       	brne	.-16     	; 0x2d40 <__ftoa_engine+0xe6>
    2d50:	e8 e6       	ldi	r30, 0x68	; 104
    2d52:	f0 e0       	ldi	r31, 0x00	; 0
    2d54:	68 94       	set
    2d56:	15 90       	lpm	r1, Z+
    2d58:	15 91       	lpm	r17, Z+
    2d5a:	35 91       	lpm	r19, Z+
    2d5c:	65 91       	lpm	r22, Z+
    2d5e:	95 91       	lpm	r25, Z+
    2d60:	05 90       	lpm	r0, Z+
    2d62:	7f e2       	ldi	r23, 0x2F	; 47
    2d64:	73 95       	inc	r23
    2d66:	e1 18       	sub	r14, r1
    2d68:	f1 0a       	sbc	r15, r17
    2d6a:	43 0b       	sbc	r20, r19
    2d6c:	56 0b       	sbc	r21, r22
    2d6e:	c9 0b       	sbc	r28, r25
    2d70:	d0 09       	sbc	r29, r0
    2d72:	c0 f7       	brcc	.-16     	; 0x2d64 <__ftoa_engine+0x10a>
    2d74:	e1 0c       	add	r14, r1
    2d76:	f1 1e       	adc	r15, r17
    2d78:	43 1f       	adc	r20, r19
    2d7a:	56 1f       	adc	r21, r22
    2d7c:	c9 1f       	adc	r28, r25
    2d7e:	d0 1d       	adc	r29, r0
    2d80:	7e f4       	brtc	.+30     	; 0x2da0 <__ftoa_engine+0x146>
    2d82:	70 33       	cpi	r23, 0x30	; 48
    2d84:	11 f4       	brne	.+4      	; 0x2d8a <__ftoa_engine+0x130>
    2d86:	8a 95       	dec	r24
    2d88:	e6 cf       	rjmp	.-52     	; 0x2d56 <__ftoa_engine+0xfc>
    2d8a:	e8 94       	clt
    2d8c:	01 50       	subi	r16, 0x01	; 1
    2d8e:	30 f0       	brcs	.+12     	; 0x2d9c <__ftoa_engine+0x142>
    2d90:	08 0f       	add	r16, r24
    2d92:	0a f4       	brpl	.+2      	; 0x2d96 <__ftoa_engine+0x13c>
    2d94:	00 27       	eor	r16, r16
    2d96:	02 17       	cp	r16, r18
    2d98:	08 f4       	brcc	.+2      	; 0x2d9c <__ftoa_engine+0x142>
    2d9a:	20 2f       	mov	r18, r16
    2d9c:	23 95       	inc	r18
    2d9e:	02 2f       	mov	r16, r18
    2da0:	7a 33       	cpi	r23, 0x3A	; 58
    2da2:	28 f0       	brcs	.+10     	; 0x2dae <__ftoa_engine+0x154>
    2da4:	79 e3       	ldi	r23, 0x39	; 57
    2da6:	7d 93       	st	X+, r23
    2da8:	2a 95       	dec	r18
    2daa:	e9 f7       	brne	.-6      	; 0x2da6 <__ftoa_engine+0x14c>
    2dac:	10 c0       	rjmp	.+32     	; 0x2dce <__ftoa_engine+0x174>
    2dae:	7d 93       	st	X+, r23
    2db0:	2a 95       	dec	r18
    2db2:	89 f6       	brne	.-94     	; 0x2d56 <__ftoa_engine+0xfc>
    2db4:	06 94       	lsr	r0
    2db6:	97 95       	ror	r25
    2db8:	67 95       	ror	r22
    2dba:	37 95       	ror	r19
    2dbc:	17 95       	ror	r17
    2dbe:	17 94       	ror	r1
    2dc0:	e1 18       	sub	r14, r1
    2dc2:	f1 0a       	sbc	r15, r17
    2dc4:	43 0b       	sbc	r20, r19
    2dc6:	56 0b       	sbc	r21, r22
    2dc8:	c9 0b       	sbc	r28, r25
    2dca:	d0 09       	sbc	r29, r0
    2dcc:	98 f0       	brcs	.+38     	; 0x2df4 <__ftoa_engine+0x19a>
    2dce:	23 95       	inc	r18
    2dd0:	7e 91       	ld	r23, -X
    2dd2:	73 95       	inc	r23
    2dd4:	7a 33       	cpi	r23, 0x3A	; 58
    2dd6:	08 f0       	brcs	.+2      	; 0x2dda <__ftoa_engine+0x180>
    2dd8:	70 e3       	ldi	r23, 0x30	; 48
    2dda:	7c 93       	st	X, r23
    2ddc:	20 13       	cpse	r18, r16
    2dde:	b8 f7       	brcc	.-18     	; 0x2dce <__ftoa_engine+0x174>
    2de0:	7e 91       	ld	r23, -X
    2de2:	70 61       	ori	r23, 0x10	; 16
    2de4:	7d 93       	st	X+, r23
    2de6:	30 f0       	brcs	.+12     	; 0x2df4 <__ftoa_engine+0x19a>
    2de8:	83 95       	inc	r24
    2dea:	71 e3       	ldi	r23, 0x31	; 49
    2dec:	7d 93       	st	X+, r23
    2dee:	70 e3       	ldi	r23, 0x30	; 48
    2df0:	2a 95       	dec	r18
    2df2:	e1 f7       	brne	.-8      	; 0x2dec <__ftoa_engine+0x192>
    2df4:	11 24       	eor	r1, r1
    2df6:	ef 90       	pop	r14
    2df8:	ff 90       	pop	r15
    2dfa:	0f 91       	pop	r16
    2dfc:	1f 91       	pop	r17
    2dfe:	cf 91       	pop	r28
    2e00:	df 91       	pop	r29
    2e02:	99 27       	eor	r25, r25
    2e04:	87 fd       	sbrc	r24, 7
    2e06:	90 95       	com	r25
    2e08:	08 95       	ret

00002e0a <eeprom_read_byte>:
    2e0a:	f9 99       	sbic	0x1f, 1	; 31
    2e0c:	fe cf       	rjmp	.-4      	; 0x2e0a <eeprom_read_byte>
    2e0e:	92 bd       	out	0x22, r25	; 34
    2e10:	81 bd       	out	0x21, r24	; 33
    2e12:	f8 9a       	sbi	0x1f, 0	; 31
    2e14:	99 27       	eor	r25, r25
    2e16:	80 b5       	in	r24, 0x20	; 32
    2e18:	08 95       	ret

00002e1a <eeprom_write_byte>:
    2e1a:	26 2f       	mov	r18, r22

00002e1c <eeprom_write_r18>:
    2e1c:	f9 99       	sbic	0x1f, 1	; 31
    2e1e:	fe cf       	rjmp	.-4      	; 0x2e1c <eeprom_write_r18>
    2e20:	1f ba       	out	0x1f, r1	; 31
    2e22:	92 bd       	out	0x22, r25	; 34
    2e24:	81 bd       	out	0x21, r24	; 33
    2e26:	20 bd       	out	0x20, r18	; 32
    2e28:	0f b6       	in	r0, 0x3f	; 63
    2e2a:	f8 94       	cli
    2e2c:	fa 9a       	sbi	0x1f, 2	; 31
    2e2e:	f9 9a       	sbi	0x1f, 1	; 31
    2e30:	0f be       	out	0x3f, r0	; 63
    2e32:	01 96       	adiw	r24, 0x01	; 1
    2e34:	08 95       	ret

00002e36 <__prologue_saves__>:
    2e36:	2f 92       	push	r2
    2e38:	3f 92       	push	r3
    2e3a:	4f 92       	push	r4
    2e3c:	5f 92       	push	r5
    2e3e:	6f 92       	push	r6
    2e40:	7f 92       	push	r7
    2e42:	8f 92       	push	r8
    2e44:	9f 92       	push	r9
    2e46:	af 92       	push	r10
    2e48:	bf 92       	push	r11
    2e4a:	cf 92       	push	r12
    2e4c:	df 92       	push	r13
    2e4e:	ef 92       	push	r14
    2e50:	ff 92       	push	r15
    2e52:	0f 93       	push	r16
    2e54:	1f 93       	push	r17
    2e56:	cf 93       	push	r28
    2e58:	df 93       	push	r29
    2e5a:	cd b7       	in	r28, 0x3d	; 61
    2e5c:	de b7       	in	r29, 0x3e	; 62
    2e5e:	ca 1b       	sub	r28, r26
    2e60:	db 0b       	sbc	r29, r27
    2e62:	0f b6       	in	r0, 0x3f	; 63
    2e64:	f8 94       	cli
    2e66:	de bf       	out	0x3e, r29	; 62
    2e68:	0f be       	out	0x3f, r0	; 63
    2e6a:	cd bf       	out	0x3d, r28	; 61
    2e6c:	09 94       	ijmp

00002e6e <__epilogue_restores__>:
    2e6e:	2a 88       	ldd	r2, Y+18	; 0x12
    2e70:	39 88       	ldd	r3, Y+17	; 0x11
    2e72:	48 88       	ldd	r4, Y+16	; 0x10
    2e74:	5f 84       	ldd	r5, Y+15	; 0x0f
    2e76:	6e 84       	ldd	r6, Y+14	; 0x0e
    2e78:	7d 84       	ldd	r7, Y+13	; 0x0d
    2e7a:	8c 84       	ldd	r8, Y+12	; 0x0c
    2e7c:	9b 84       	ldd	r9, Y+11	; 0x0b
    2e7e:	aa 84       	ldd	r10, Y+10	; 0x0a
    2e80:	b9 84       	ldd	r11, Y+9	; 0x09
    2e82:	c8 84       	ldd	r12, Y+8	; 0x08
    2e84:	df 80       	ldd	r13, Y+7	; 0x07
    2e86:	ee 80       	ldd	r14, Y+6	; 0x06
    2e88:	fd 80       	ldd	r15, Y+5	; 0x05
    2e8a:	0c 81       	ldd	r16, Y+4	; 0x04
    2e8c:	1b 81       	ldd	r17, Y+3	; 0x03
    2e8e:	aa 81       	ldd	r26, Y+2	; 0x02
    2e90:	b9 81       	ldd	r27, Y+1	; 0x01
    2e92:	ce 0f       	add	r28, r30
    2e94:	d1 1d       	adc	r29, r1
    2e96:	0f b6       	in	r0, 0x3f	; 63
    2e98:	f8 94       	cli
    2e9a:	de bf       	out	0x3e, r29	; 62
    2e9c:	0f be       	out	0x3f, r0	; 63
    2e9e:	cd bf       	out	0x3d, r28	; 61
    2ea0:	ed 01       	movw	r28, r26
    2ea2:	08 95       	ret

00002ea4 <__udivmodqi4>:
    2ea4:	99 1b       	sub	r25, r25
    2ea6:	79 e0       	ldi	r23, 0x09	; 9
    2ea8:	04 c0       	rjmp	.+8      	; 0x2eb2 <__udivmodqi4_ep>

00002eaa <__udivmodqi4_loop>:
    2eaa:	99 1f       	adc	r25, r25
    2eac:	96 17       	cp	r25, r22
    2eae:	08 f0       	brcs	.+2      	; 0x2eb2 <__udivmodqi4_ep>
    2eb0:	96 1b       	sub	r25, r22

00002eb2 <__udivmodqi4_ep>:
    2eb2:	88 1f       	adc	r24, r24
    2eb4:	7a 95       	dec	r23
    2eb6:	c9 f7       	brne	.-14     	; 0x2eaa <__udivmodqi4_loop>
    2eb8:	80 95       	com	r24
    2eba:	08 95       	ret

00002ebc <__divmodhi4>:
    2ebc:	97 fb       	bst	r25, 7
    2ebe:	07 2e       	mov	r0, r23
    2ec0:	16 f4       	brtc	.+4      	; 0x2ec6 <__divmodhi4+0xa>
    2ec2:	00 94       	com	r0
    2ec4:	07 d0       	rcall	.+14     	; 0x2ed4 <__divmodhi4_neg1>
    2ec6:	77 fd       	sbrc	r23, 7
    2ec8:	09 d0       	rcall	.+18     	; 0x2edc <__divmodhi4_neg2>
    2eca:	0e 94 94 17 	call	0x2f28	; 0x2f28 <__udivmodhi4>
    2ece:	07 fc       	sbrc	r0, 7
    2ed0:	05 d0       	rcall	.+10     	; 0x2edc <__divmodhi4_neg2>
    2ed2:	3e f4       	brtc	.+14     	; 0x2ee2 <__divmodhi4_exit>

00002ed4 <__divmodhi4_neg1>:
    2ed4:	90 95       	com	r25
    2ed6:	81 95       	neg	r24
    2ed8:	9f 4f       	sbci	r25, 0xFF	; 255
    2eda:	08 95       	ret

00002edc <__divmodhi4_neg2>:
    2edc:	70 95       	com	r23
    2ede:	61 95       	neg	r22
    2ee0:	7f 4f       	sbci	r23, 0xFF	; 255

00002ee2 <__divmodhi4_exit>:
    2ee2:	08 95       	ret

00002ee4 <__udivmodsi4>:
    2ee4:	a1 e2       	ldi	r26, 0x21	; 33
    2ee6:	1a 2e       	mov	r1, r26
    2ee8:	aa 1b       	sub	r26, r26
    2eea:	bb 1b       	sub	r27, r27
    2eec:	fd 01       	movw	r30, r26
    2eee:	0d c0       	rjmp	.+26     	; 0x2f0a <__udivmodsi4_ep>

00002ef0 <__udivmodsi4_loop>:
    2ef0:	aa 1f       	adc	r26, r26
    2ef2:	bb 1f       	adc	r27, r27
    2ef4:	ee 1f       	adc	r30, r30
    2ef6:	ff 1f       	adc	r31, r31
    2ef8:	a2 17       	cp	r26, r18
    2efa:	b3 07       	cpc	r27, r19
    2efc:	e4 07       	cpc	r30, r20
    2efe:	f5 07       	cpc	r31, r21
    2f00:	20 f0       	brcs	.+8      	; 0x2f0a <__udivmodsi4_ep>
    2f02:	a2 1b       	sub	r26, r18
    2f04:	b3 0b       	sbc	r27, r19
    2f06:	e4 0b       	sbc	r30, r20
    2f08:	f5 0b       	sbc	r31, r21

00002f0a <__udivmodsi4_ep>:
    2f0a:	66 1f       	adc	r22, r22
    2f0c:	77 1f       	adc	r23, r23
    2f0e:	88 1f       	adc	r24, r24
    2f10:	99 1f       	adc	r25, r25
    2f12:	1a 94       	dec	r1
    2f14:	69 f7       	brne	.-38     	; 0x2ef0 <__udivmodsi4_loop>
    2f16:	60 95       	com	r22
    2f18:	70 95       	com	r23
    2f1a:	80 95       	com	r24
    2f1c:	90 95       	com	r25
    2f1e:	9b 01       	movw	r18, r22
    2f20:	ac 01       	movw	r20, r24
    2f22:	bd 01       	movw	r22, r26
    2f24:	cf 01       	movw	r24, r30
    2f26:	08 95       	ret

00002f28 <__udivmodhi4>:
    2f28:	aa 1b       	sub	r26, r26
    2f2a:	bb 1b       	sub	r27, r27
    2f2c:	51 e1       	ldi	r21, 0x11	; 17
    2f2e:	07 c0       	rjmp	.+14     	; 0x2f3e <__udivmodhi4_ep>

00002f30 <__udivmodhi4_loop>:
    2f30:	aa 1f       	adc	r26, r26
    2f32:	bb 1f       	adc	r27, r27
    2f34:	a6 17       	cp	r26, r22
    2f36:	b7 07       	cpc	r27, r23
    2f38:	10 f0       	brcs	.+4      	; 0x2f3e <__udivmodhi4_ep>
    2f3a:	a6 1b       	sub	r26, r22
    2f3c:	b7 0b       	sbc	r27, r23

00002f3e <__udivmodhi4_ep>:
    2f3e:	88 1f       	adc	r24, r24
    2f40:	99 1f       	adc	r25, r25
    2f42:	5a 95       	dec	r21
    2f44:	a9 f7       	brne	.-22     	; 0x2f30 <__udivmodhi4_loop>
    2f46:	80 95       	com	r24
    2f48:	90 95       	com	r25
    2f4a:	bc 01       	movw	r22, r24
    2f4c:	cd 01       	movw	r24, r26
    2f4e:	08 95       	ret

00002f50 <__tablejump2__>:
    2f50:	ee 0f       	add	r30, r30
    2f52:	ff 1f       	adc	r31, r31
    2f54:	05 90       	lpm	r0, Z+
    2f56:	f4 91       	lpm	r31, Z
    2f58:	e0 2d       	mov	r30, r0
    2f5a:	09 94       	ijmp

00002f5c <__subsf3>:
    2f5c:	50 58       	subi	r21, 0x80	; 128

00002f5e <__addsf3>:
    2f5e:	bb 27       	eor	r27, r27
    2f60:	aa 27       	eor	r26, r26
    2f62:	0e 94 c6 17 	call	0x2f8c	; 0x2f8c <__addsf3x>
    2f66:	0c 94 10 19 	jmp	0x3220	; 0x3220 <__fp_round>
    2f6a:	0e 94 02 19 	call	0x3204	; 0x3204 <__fp_pscA>
    2f6e:	38 f0       	brcs	.+14     	; 0x2f7e <__addsf3+0x20>
    2f70:	0e 94 09 19 	call	0x3212	; 0x3212 <__fp_pscB>
    2f74:	20 f0       	brcs	.+8      	; 0x2f7e <__addsf3+0x20>
    2f76:	39 f4       	brne	.+14     	; 0x2f86 <__addsf3+0x28>
    2f78:	9f 3f       	cpi	r25, 0xFF	; 255
    2f7a:	19 f4       	brne	.+6      	; 0x2f82 <__addsf3+0x24>
    2f7c:	26 f4       	brtc	.+8      	; 0x2f86 <__addsf3+0x28>
    2f7e:	0c 94 ff 18 	jmp	0x31fe	; 0x31fe <__fp_nan>
    2f82:	0e f4       	brtc	.+2      	; 0x2f86 <__addsf3+0x28>
    2f84:	e0 95       	com	r30
    2f86:	e7 fb       	bst	r30, 7
    2f88:	0c 94 f9 18 	jmp	0x31f2	; 0x31f2 <__fp_inf>

00002f8c <__addsf3x>:
    2f8c:	e9 2f       	mov	r30, r25
    2f8e:	0e 94 21 19 	call	0x3242	; 0x3242 <__fp_split3>
    2f92:	58 f3       	brcs	.-42     	; 0x2f6a <__addsf3+0xc>
    2f94:	ba 17       	cp	r27, r26
    2f96:	62 07       	cpc	r22, r18
    2f98:	73 07       	cpc	r23, r19
    2f9a:	84 07       	cpc	r24, r20
    2f9c:	95 07       	cpc	r25, r21
    2f9e:	20 f0       	brcs	.+8      	; 0x2fa8 <__addsf3x+0x1c>
    2fa0:	79 f4       	brne	.+30     	; 0x2fc0 <__addsf3x+0x34>
    2fa2:	a6 f5       	brtc	.+104    	; 0x300c <__addsf3x+0x80>
    2fa4:	0c 94 43 19 	jmp	0x3286	; 0x3286 <__fp_zero>
    2fa8:	0e f4       	brtc	.+2      	; 0x2fac <__addsf3x+0x20>
    2faa:	e0 95       	com	r30
    2fac:	0b 2e       	mov	r0, r27
    2fae:	ba 2f       	mov	r27, r26
    2fb0:	a0 2d       	mov	r26, r0
    2fb2:	0b 01       	movw	r0, r22
    2fb4:	b9 01       	movw	r22, r18
    2fb6:	90 01       	movw	r18, r0
    2fb8:	0c 01       	movw	r0, r24
    2fba:	ca 01       	movw	r24, r20
    2fbc:	a0 01       	movw	r20, r0
    2fbe:	11 24       	eor	r1, r1
    2fc0:	ff 27       	eor	r31, r31
    2fc2:	59 1b       	sub	r21, r25
    2fc4:	99 f0       	breq	.+38     	; 0x2fec <__addsf3x+0x60>
    2fc6:	59 3f       	cpi	r21, 0xF9	; 249
    2fc8:	50 f4       	brcc	.+20     	; 0x2fde <__addsf3x+0x52>
    2fca:	50 3e       	cpi	r21, 0xE0	; 224
    2fcc:	68 f1       	brcs	.+90     	; 0x3028 <__addsf3x+0x9c>
    2fce:	1a 16       	cp	r1, r26
    2fd0:	f0 40       	sbci	r31, 0x00	; 0
    2fd2:	a2 2f       	mov	r26, r18
    2fd4:	23 2f       	mov	r18, r19
    2fd6:	34 2f       	mov	r19, r20
    2fd8:	44 27       	eor	r20, r20
    2fda:	58 5f       	subi	r21, 0xF8	; 248
    2fdc:	f3 cf       	rjmp	.-26     	; 0x2fc4 <__addsf3x+0x38>
    2fde:	46 95       	lsr	r20
    2fe0:	37 95       	ror	r19
    2fe2:	27 95       	ror	r18
    2fe4:	a7 95       	ror	r26
    2fe6:	f0 40       	sbci	r31, 0x00	; 0
    2fe8:	53 95       	inc	r21
    2fea:	c9 f7       	brne	.-14     	; 0x2fde <__addsf3x+0x52>
    2fec:	7e f4       	brtc	.+30     	; 0x300c <__addsf3x+0x80>
    2fee:	1f 16       	cp	r1, r31
    2ff0:	ba 0b       	sbc	r27, r26
    2ff2:	62 0b       	sbc	r22, r18
    2ff4:	73 0b       	sbc	r23, r19
    2ff6:	84 0b       	sbc	r24, r20
    2ff8:	ba f0       	brmi	.+46     	; 0x3028 <__addsf3x+0x9c>
    2ffa:	91 50       	subi	r25, 0x01	; 1
    2ffc:	a1 f0       	breq	.+40     	; 0x3026 <__addsf3x+0x9a>
    2ffe:	ff 0f       	add	r31, r31
    3000:	bb 1f       	adc	r27, r27
    3002:	66 1f       	adc	r22, r22
    3004:	77 1f       	adc	r23, r23
    3006:	88 1f       	adc	r24, r24
    3008:	c2 f7       	brpl	.-16     	; 0x2ffa <__addsf3x+0x6e>
    300a:	0e c0       	rjmp	.+28     	; 0x3028 <__addsf3x+0x9c>
    300c:	ba 0f       	add	r27, r26
    300e:	62 1f       	adc	r22, r18
    3010:	73 1f       	adc	r23, r19
    3012:	84 1f       	adc	r24, r20
    3014:	48 f4       	brcc	.+18     	; 0x3028 <__addsf3x+0x9c>
    3016:	87 95       	ror	r24
    3018:	77 95       	ror	r23
    301a:	67 95       	ror	r22
    301c:	b7 95       	ror	r27
    301e:	f7 95       	ror	r31
    3020:	9e 3f       	cpi	r25, 0xFE	; 254
    3022:	08 f0       	brcs	.+2      	; 0x3026 <__addsf3x+0x9a>
    3024:	b0 cf       	rjmp	.-160    	; 0x2f86 <__addsf3+0x28>
    3026:	93 95       	inc	r25
    3028:	88 0f       	add	r24, r24
    302a:	08 f0       	brcs	.+2      	; 0x302e <__addsf3x+0xa2>
    302c:	99 27       	eor	r25, r25
    302e:	ee 0f       	add	r30, r30
    3030:	97 95       	ror	r25
    3032:	87 95       	ror	r24
    3034:	08 95       	ret

00003036 <__divsf3>:
    3036:	0e 94 2f 18 	call	0x305e	; 0x305e <__divsf3x>
    303a:	0c 94 10 19 	jmp	0x3220	; 0x3220 <__fp_round>
    303e:	0e 94 09 19 	call	0x3212	; 0x3212 <__fp_pscB>
    3042:	58 f0       	brcs	.+22     	; 0x305a <__divsf3+0x24>
    3044:	0e 94 02 19 	call	0x3204	; 0x3204 <__fp_pscA>
    3048:	40 f0       	brcs	.+16     	; 0x305a <__divsf3+0x24>
    304a:	29 f4       	brne	.+10     	; 0x3056 <__divsf3+0x20>
    304c:	5f 3f       	cpi	r21, 0xFF	; 255
    304e:	29 f0       	breq	.+10     	; 0x305a <__divsf3+0x24>
    3050:	0c 94 f9 18 	jmp	0x31f2	; 0x31f2 <__fp_inf>
    3054:	51 11       	cpse	r21, r1
    3056:	0c 94 44 19 	jmp	0x3288	; 0x3288 <__fp_szero>
    305a:	0c 94 ff 18 	jmp	0x31fe	; 0x31fe <__fp_nan>

0000305e <__divsf3x>:
    305e:	0e 94 21 19 	call	0x3242	; 0x3242 <__fp_split3>
    3062:	68 f3       	brcs	.-38     	; 0x303e <__divsf3+0x8>

00003064 <__divsf3_pse>:
    3064:	99 23       	and	r25, r25
    3066:	b1 f3       	breq	.-20     	; 0x3054 <__divsf3+0x1e>
    3068:	55 23       	and	r21, r21
    306a:	91 f3       	breq	.-28     	; 0x3050 <__divsf3+0x1a>
    306c:	95 1b       	sub	r25, r21
    306e:	55 0b       	sbc	r21, r21
    3070:	bb 27       	eor	r27, r27
    3072:	aa 27       	eor	r26, r26
    3074:	62 17       	cp	r22, r18
    3076:	73 07       	cpc	r23, r19
    3078:	84 07       	cpc	r24, r20
    307a:	38 f0       	brcs	.+14     	; 0x308a <__divsf3_pse+0x26>
    307c:	9f 5f       	subi	r25, 0xFF	; 255
    307e:	5f 4f       	sbci	r21, 0xFF	; 255
    3080:	22 0f       	add	r18, r18
    3082:	33 1f       	adc	r19, r19
    3084:	44 1f       	adc	r20, r20
    3086:	aa 1f       	adc	r26, r26
    3088:	a9 f3       	breq	.-22     	; 0x3074 <__divsf3_pse+0x10>
    308a:	35 d0       	rcall	.+106    	; 0x30f6 <__divsf3_pse+0x92>
    308c:	0e 2e       	mov	r0, r30
    308e:	3a f0       	brmi	.+14     	; 0x309e <__divsf3_pse+0x3a>
    3090:	e0 e8       	ldi	r30, 0x80	; 128
    3092:	32 d0       	rcall	.+100    	; 0x30f8 <__divsf3_pse+0x94>
    3094:	91 50       	subi	r25, 0x01	; 1
    3096:	50 40       	sbci	r21, 0x00	; 0
    3098:	e6 95       	lsr	r30
    309a:	00 1c       	adc	r0, r0
    309c:	ca f7       	brpl	.-14     	; 0x3090 <__divsf3_pse+0x2c>
    309e:	2b d0       	rcall	.+86     	; 0x30f6 <__divsf3_pse+0x92>
    30a0:	fe 2f       	mov	r31, r30
    30a2:	29 d0       	rcall	.+82     	; 0x30f6 <__divsf3_pse+0x92>
    30a4:	66 0f       	add	r22, r22
    30a6:	77 1f       	adc	r23, r23
    30a8:	88 1f       	adc	r24, r24
    30aa:	bb 1f       	adc	r27, r27
    30ac:	26 17       	cp	r18, r22
    30ae:	37 07       	cpc	r19, r23
    30b0:	48 07       	cpc	r20, r24
    30b2:	ab 07       	cpc	r26, r27
    30b4:	b0 e8       	ldi	r27, 0x80	; 128
    30b6:	09 f0       	breq	.+2      	; 0x30ba <__divsf3_pse+0x56>
    30b8:	bb 0b       	sbc	r27, r27
    30ba:	80 2d       	mov	r24, r0
    30bc:	bf 01       	movw	r22, r30
    30be:	ff 27       	eor	r31, r31
    30c0:	93 58       	subi	r25, 0x83	; 131
    30c2:	5f 4f       	sbci	r21, 0xFF	; 255
    30c4:	3a f0       	brmi	.+14     	; 0x30d4 <__divsf3_pse+0x70>
    30c6:	9e 3f       	cpi	r25, 0xFE	; 254
    30c8:	51 05       	cpc	r21, r1
    30ca:	78 f0       	brcs	.+30     	; 0x30ea <__divsf3_pse+0x86>
    30cc:	0c 94 f9 18 	jmp	0x31f2	; 0x31f2 <__fp_inf>
    30d0:	0c 94 44 19 	jmp	0x3288	; 0x3288 <__fp_szero>
    30d4:	5f 3f       	cpi	r21, 0xFF	; 255
    30d6:	e4 f3       	brlt	.-8      	; 0x30d0 <__divsf3_pse+0x6c>
    30d8:	98 3e       	cpi	r25, 0xE8	; 232
    30da:	d4 f3       	brlt	.-12     	; 0x30d0 <__divsf3_pse+0x6c>
    30dc:	86 95       	lsr	r24
    30de:	77 95       	ror	r23
    30e0:	67 95       	ror	r22
    30e2:	b7 95       	ror	r27
    30e4:	f7 95       	ror	r31
    30e6:	9f 5f       	subi	r25, 0xFF	; 255
    30e8:	c9 f7       	brne	.-14     	; 0x30dc <__divsf3_pse+0x78>
    30ea:	88 0f       	add	r24, r24
    30ec:	91 1d       	adc	r25, r1
    30ee:	96 95       	lsr	r25
    30f0:	87 95       	ror	r24
    30f2:	97 f9       	bld	r25, 7
    30f4:	08 95       	ret
    30f6:	e1 e0       	ldi	r30, 0x01	; 1
    30f8:	66 0f       	add	r22, r22
    30fa:	77 1f       	adc	r23, r23
    30fc:	88 1f       	adc	r24, r24
    30fe:	bb 1f       	adc	r27, r27
    3100:	62 17       	cp	r22, r18
    3102:	73 07       	cpc	r23, r19
    3104:	84 07       	cpc	r24, r20
    3106:	ba 07       	cpc	r27, r26
    3108:	20 f0       	brcs	.+8      	; 0x3112 <__divsf3_pse+0xae>
    310a:	62 1b       	sub	r22, r18
    310c:	73 0b       	sbc	r23, r19
    310e:	84 0b       	sbc	r24, r20
    3110:	ba 0b       	sbc	r27, r26
    3112:	ee 1f       	adc	r30, r30
    3114:	88 f7       	brcc	.-30     	; 0x30f8 <__divsf3_pse+0x94>
    3116:	e0 95       	com	r30
    3118:	08 95       	ret

0000311a <__fixunssfsi>:
    311a:	0e 94 29 19 	call	0x3252	; 0x3252 <__fp_splitA>
    311e:	88 f0       	brcs	.+34     	; 0x3142 <__fixunssfsi+0x28>
    3120:	9f 57       	subi	r25, 0x7F	; 127
    3122:	98 f0       	brcs	.+38     	; 0x314a <__fixunssfsi+0x30>
    3124:	b9 2f       	mov	r27, r25
    3126:	99 27       	eor	r25, r25
    3128:	b7 51       	subi	r27, 0x17	; 23
    312a:	b0 f0       	brcs	.+44     	; 0x3158 <__fixunssfsi+0x3e>
    312c:	e1 f0       	breq	.+56     	; 0x3166 <__fixunssfsi+0x4c>
    312e:	66 0f       	add	r22, r22
    3130:	77 1f       	adc	r23, r23
    3132:	88 1f       	adc	r24, r24
    3134:	99 1f       	adc	r25, r25
    3136:	1a f0       	brmi	.+6      	; 0x313e <__fixunssfsi+0x24>
    3138:	ba 95       	dec	r27
    313a:	c9 f7       	brne	.-14     	; 0x312e <__fixunssfsi+0x14>
    313c:	14 c0       	rjmp	.+40     	; 0x3166 <__fixunssfsi+0x4c>
    313e:	b1 30       	cpi	r27, 0x01	; 1
    3140:	91 f0       	breq	.+36     	; 0x3166 <__fixunssfsi+0x4c>
    3142:	0e 94 43 19 	call	0x3286	; 0x3286 <__fp_zero>
    3146:	b1 e0       	ldi	r27, 0x01	; 1
    3148:	08 95       	ret
    314a:	0c 94 43 19 	jmp	0x3286	; 0x3286 <__fp_zero>
    314e:	67 2f       	mov	r22, r23
    3150:	78 2f       	mov	r23, r24
    3152:	88 27       	eor	r24, r24
    3154:	b8 5f       	subi	r27, 0xF8	; 248
    3156:	39 f0       	breq	.+14     	; 0x3166 <__fixunssfsi+0x4c>
    3158:	b9 3f       	cpi	r27, 0xF9	; 249
    315a:	cc f3       	brlt	.-14     	; 0x314e <__fixunssfsi+0x34>
    315c:	86 95       	lsr	r24
    315e:	77 95       	ror	r23
    3160:	67 95       	ror	r22
    3162:	b3 95       	inc	r27
    3164:	d9 f7       	brne	.-10     	; 0x315c <__fixunssfsi+0x42>
    3166:	3e f4       	brtc	.+14     	; 0x3176 <__fixunssfsi+0x5c>
    3168:	90 95       	com	r25
    316a:	80 95       	com	r24
    316c:	70 95       	com	r23
    316e:	61 95       	neg	r22
    3170:	7f 4f       	sbci	r23, 0xFF	; 255
    3172:	8f 4f       	sbci	r24, 0xFF	; 255
    3174:	9f 4f       	sbci	r25, 0xFF	; 255
    3176:	08 95       	ret

00003178 <__floatunsisf>:
    3178:	e8 94       	clt
    317a:	09 c0       	rjmp	.+18     	; 0x318e <__floatsisf+0x12>

0000317c <__floatsisf>:
    317c:	97 fb       	bst	r25, 7
    317e:	3e f4       	brtc	.+14     	; 0x318e <__floatsisf+0x12>
    3180:	90 95       	com	r25
    3182:	80 95       	com	r24
    3184:	70 95       	com	r23
    3186:	61 95       	neg	r22
    3188:	7f 4f       	sbci	r23, 0xFF	; 255
    318a:	8f 4f       	sbci	r24, 0xFF	; 255
    318c:	9f 4f       	sbci	r25, 0xFF	; 255
    318e:	99 23       	and	r25, r25
    3190:	a9 f0       	breq	.+42     	; 0x31bc <__floatsisf+0x40>
    3192:	f9 2f       	mov	r31, r25
    3194:	96 e9       	ldi	r25, 0x96	; 150
    3196:	bb 27       	eor	r27, r27
    3198:	93 95       	inc	r25
    319a:	f6 95       	lsr	r31
    319c:	87 95       	ror	r24
    319e:	77 95       	ror	r23
    31a0:	67 95       	ror	r22
    31a2:	b7 95       	ror	r27
    31a4:	f1 11       	cpse	r31, r1
    31a6:	f8 cf       	rjmp	.-16     	; 0x3198 <__floatsisf+0x1c>
    31a8:	fa f4       	brpl	.+62     	; 0x31e8 <__floatsisf+0x6c>
    31aa:	bb 0f       	add	r27, r27
    31ac:	11 f4       	brne	.+4      	; 0x31b2 <__floatsisf+0x36>
    31ae:	60 ff       	sbrs	r22, 0
    31b0:	1b c0       	rjmp	.+54     	; 0x31e8 <__floatsisf+0x6c>
    31b2:	6f 5f       	subi	r22, 0xFF	; 255
    31b4:	7f 4f       	sbci	r23, 0xFF	; 255
    31b6:	8f 4f       	sbci	r24, 0xFF	; 255
    31b8:	9f 4f       	sbci	r25, 0xFF	; 255
    31ba:	16 c0       	rjmp	.+44     	; 0x31e8 <__floatsisf+0x6c>
    31bc:	88 23       	and	r24, r24
    31be:	11 f0       	breq	.+4      	; 0x31c4 <__floatsisf+0x48>
    31c0:	96 e9       	ldi	r25, 0x96	; 150
    31c2:	11 c0       	rjmp	.+34     	; 0x31e6 <__floatsisf+0x6a>
    31c4:	77 23       	and	r23, r23
    31c6:	21 f0       	breq	.+8      	; 0x31d0 <__floatsisf+0x54>
    31c8:	9e e8       	ldi	r25, 0x8E	; 142
    31ca:	87 2f       	mov	r24, r23
    31cc:	76 2f       	mov	r23, r22
    31ce:	05 c0       	rjmp	.+10     	; 0x31da <__floatsisf+0x5e>
    31d0:	66 23       	and	r22, r22
    31d2:	71 f0       	breq	.+28     	; 0x31f0 <__floatsisf+0x74>
    31d4:	96 e8       	ldi	r25, 0x86	; 134
    31d6:	86 2f       	mov	r24, r22
    31d8:	70 e0       	ldi	r23, 0x00	; 0
    31da:	60 e0       	ldi	r22, 0x00	; 0
    31dc:	2a f0       	brmi	.+10     	; 0x31e8 <__floatsisf+0x6c>
    31de:	9a 95       	dec	r25
    31e0:	66 0f       	add	r22, r22
    31e2:	77 1f       	adc	r23, r23
    31e4:	88 1f       	adc	r24, r24
    31e6:	da f7       	brpl	.-10     	; 0x31de <__floatsisf+0x62>
    31e8:	88 0f       	add	r24, r24
    31ea:	96 95       	lsr	r25
    31ec:	87 95       	ror	r24
    31ee:	97 f9       	bld	r25, 7
    31f0:	08 95       	ret

000031f2 <__fp_inf>:
    31f2:	97 f9       	bld	r25, 7
    31f4:	9f 67       	ori	r25, 0x7F	; 127
    31f6:	80 e8       	ldi	r24, 0x80	; 128
    31f8:	70 e0       	ldi	r23, 0x00	; 0
    31fa:	60 e0       	ldi	r22, 0x00	; 0
    31fc:	08 95       	ret

000031fe <__fp_nan>:
    31fe:	9f ef       	ldi	r25, 0xFF	; 255
    3200:	80 ec       	ldi	r24, 0xC0	; 192
    3202:	08 95       	ret

00003204 <__fp_pscA>:
    3204:	00 24       	eor	r0, r0
    3206:	0a 94       	dec	r0
    3208:	16 16       	cp	r1, r22
    320a:	17 06       	cpc	r1, r23
    320c:	18 06       	cpc	r1, r24
    320e:	09 06       	cpc	r0, r25
    3210:	08 95       	ret

00003212 <__fp_pscB>:
    3212:	00 24       	eor	r0, r0
    3214:	0a 94       	dec	r0
    3216:	12 16       	cp	r1, r18
    3218:	13 06       	cpc	r1, r19
    321a:	14 06       	cpc	r1, r20
    321c:	05 06       	cpc	r0, r21
    321e:	08 95       	ret

00003220 <__fp_round>:
    3220:	09 2e       	mov	r0, r25
    3222:	03 94       	inc	r0
    3224:	00 0c       	add	r0, r0
    3226:	11 f4       	brne	.+4      	; 0x322c <__fp_round+0xc>
    3228:	88 23       	and	r24, r24
    322a:	52 f0       	brmi	.+20     	; 0x3240 <__fp_round+0x20>
    322c:	bb 0f       	add	r27, r27
    322e:	40 f4       	brcc	.+16     	; 0x3240 <__fp_round+0x20>
    3230:	bf 2b       	or	r27, r31
    3232:	11 f4       	brne	.+4      	; 0x3238 <__fp_round+0x18>
    3234:	60 ff       	sbrs	r22, 0
    3236:	04 c0       	rjmp	.+8      	; 0x3240 <__fp_round+0x20>
    3238:	6f 5f       	subi	r22, 0xFF	; 255
    323a:	7f 4f       	sbci	r23, 0xFF	; 255
    323c:	8f 4f       	sbci	r24, 0xFF	; 255
    323e:	9f 4f       	sbci	r25, 0xFF	; 255
    3240:	08 95       	ret

00003242 <__fp_split3>:
    3242:	57 fd       	sbrc	r21, 7
    3244:	90 58       	subi	r25, 0x80	; 128
    3246:	44 0f       	add	r20, r20
    3248:	55 1f       	adc	r21, r21
    324a:	59 f0       	breq	.+22     	; 0x3262 <__fp_splitA+0x10>
    324c:	5f 3f       	cpi	r21, 0xFF	; 255
    324e:	71 f0       	breq	.+28     	; 0x326c <__fp_splitA+0x1a>
    3250:	47 95       	ror	r20

00003252 <__fp_splitA>:
    3252:	88 0f       	add	r24, r24
    3254:	97 fb       	bst	r25, 7
    3256:	99 1f       	adc	r25, r25
    3258:	61 f0       	breq	.+24     	; 0x3272 <__fp_splitA+0x20>
    325a:	9f 3f       	cpi	r25, 0xFF	; 255
    325c:	79 f0       	breq	.+30     	; 0x327c <__fp_splitA+0x2a>
    325e:	87 95       	ror	r24
    3260:	08 95       	ret
    3262:	12 16       	cp	r1, r18
    3264:	13 06       	cpc	r1, r19
    3266:	14 06       	cpc	r1, r20
    3268:	55 1f       	adc	r21, r21
    326a:	f2 cf       	rjmp	.-28     	; 0x3250 <__fp_split3+0xe>
    326c:	46 95       	lsr	r20
    326e:	f1 df       	rcall	.-30     	; 0x3252 <__fp_splitA>
    3270:	08 c0       	rjmp	.+16     	; 0x3282 <__fp_splitA+0x30>
    3272:	16 16       	cp	r1, r22
    3274:	17 06       	cpc	r1, r23
    3276:	18 06       	cpc	r1, r24
    3278:	99 1f       	adc	r25, r25
    327a:	f1 cf       	rjmp	.-30     	; 0x325e <__fp_splitA+0xc>
    327c:	86 95       	lsr	r24
    327e:	71 05       	cpc	r23, r1
    3280:	61 05       	cpc	r22, r1
    3282:	08 94       	sec
    3284:	08 95       	ret

00003286 <__fp_zero>:
    3286:	e8 94       	clt

00003288 <__fp_szero>:
    3288:	bb 27       	eor	r27, r27
    328a:	66 27       	eor	r22, r22
    328c:	77 27       	eor	r23, r23
    328e:	cb 01       	movw	r24, r22
    3290:	97 f9       	bld	r25, 7
    3292:	08 95       	ret

00003294 <__mulsf3>:
    3294:	0e 94 5d 19 	call	0x32ba	; 0x32ba <__mulsf3x>
    3298:	0c 94 10 19 	jmp	0x3220	; 0x3220 <__fp_round>
    329c:	0e 94 02 19 	call	0x3204	; 0x3204 <__fp_pscA>
    32a0:	38 f0       	brcs	.+14     	; 0x32b0 <__mulsf3+0x1c>
    32a2:	0e 94 09 19 	call	0x3212	; 0x3212 <__fp_pscB>
    32a6:	20 f0       	brcs	.+8      	; 0x32b0 <__mulsf3+0x1c>
    32a8:	95 23       	and	r25, r21
    32aa:	11 f0       	breq	.+4      	; 0x32b0 <__mulsf3+0x1c>
    32ac:	0c 94 f9 18 	jmp	0x31f2	; 0x31f2 <__fp_inf>
    32b0:	0c 94 ff 18 	jmp	0x31fe	; 0x31fe <__fp_nan>
    32b4:	11 24       	eor	r1, r1
    32b6:	0c 94 44 19 	jmp	0x3288	; 0x3288 <__fp_szero>

000032ba <__mulsf3x>:
    32ba:	0e 94 21 19 	call	0x3242	; 0x3242 <__fp_split3>
    32be:	70 f3       	brcs	.-36     	; 0x329c <__mulsf3+0x8>

000032c0 <__mulsf3_pse>:
    32c0:	95 9f       	mul	r25, r21
    32c2:	c1 f3       	breq	.-16     	; 0x32b4 <__mulsf3+0x20>
    32c4:	95 0f       	add	r25, r21
    32c6:	50 e0       	ldi	r21, 0x00	; 0
    32c8:	55 1f       	adc	r21, r21
    32ca:	62 9f       	mul	r22, r18
    32cc:	f0 01       	movw	r30, r0
    32ce:	72 9f       	mul	r23, r18
    32d0:	bb 27       	eor	r27, r27
    32d2:	f0 0d       	add	r31, r0
    32d4:	b1 1d       	adc	r27, r1
    32d6:	63 9f       	mul	r22, r19
    32d8:	aa 27       	eor	r26, r26
    32da:	f0 0d       	add	r31, r0
    32dc:	b1 1d       	adc	r27, r1
    32de:	aa 1f       	adc	r26, r26
    32e0:	64 9f       	mul	r22, r20
    32e2:	66 27       	eor	r22, r22
    32e4:	b0 0d       	add	r27, r0
    32e6:	a1 1d       	adc	r26, r1
    32e8:	66 1f       	adc	r22, r22
    32ea:	82 9f       	mul	r24, r18
    32ec:	22 27       	eor	r18, r18
    32ee:	b0 0d       	add	r27, r0
    32f0:	a1 1d       	adc	r26, r1
    32f2:	62 1f       	adc	r22, r18
    32f4:	73 9f       	mul	r23, r19
    32f6:	b0 0d       	add	r27, r0
    32f8:	a1 1d       	adc	r26, r1
    32fa:	62 1f       	adc	r22, r18
    32fc:	83 9f       	mul	r24, r19
    32fe:	a0 0d       	add	r26, r0
    3300:	61 1d       	adc	r22, r1
    3302:	22 1f       	adc	r18, r18
    3304:	74 9f       	mul	r23, r20
    3306:	33 27       	eor	r19, r19
    3308:	a0 0d       	add	r26, r0
    330a:	61 1d       	adc	r22, r1
    330c:	23 1f       	adc	r18, r19
    330e:	84 9f       	mul	r24, r20
    3310:	60 0d       	add	r22, r0
    3312:	21 1d       	adc	r18, r1
    3314:	82 2f       	mov	r24, r18
    3316:	76 2f       	mov	r23, r22
    3318:	6a 2f       	mov	r22, r26
    331a:	11 24       	eor	r1, r1
    331c:	9f 57       	subi	r25, 0x7F	; 127
    331e:	50 40       	sbci	r21, 0x00	; 0
    3320:	9a f0       	brmi	.+38     	; 0x3348 <__mulsf3_pse+0x88>
    3322:	f1 f0       	breq	.+60     	; 0x3360 <__mulsf3_pse+0xa0>
    3324:	88 23       	and	r24, r24
    3326:	4a f0       	brmi	.+18     	; 0x333a <__mulsf3_pse+0x7a>
    3328:	ee 0f       	add	r30, r30
    332a:	ff 1f       	adc	r31, r31
    332c:	bb 1f       	adc	r27, r27
    332e:	66 1f       	adc	r22, r22
    3330:	77 1f       	adc	r23, r23
    3332:	88 1f       	adc	r24, r24
    3334:	91 50       	subi	r25, 0x01	; 1
    3336:	50 40       	sbci	r21, 0x00	; 0
    3338:	a9 f7       	brne	.-22     	; 0x3324 <__mulsf3_pse+0x64>
    333a:	9e 3f       	cpi	r25, 0xFE	; 254
    333c:	51 05       	cpc	r21, r1
    333e:	80 f0       	brcs	.+32     	; 0x3360 <__mulsf3_pse+0xa0>
    3340:	0c 94 f9 18 	jmp	0x31f2	; 0x31f2 <__fp_inf>
    3344:	0c 94 44 19 	jmp	0x3288	; 0x3288 <__fp_szero>
    3348:	5f 3f       	cpi	r21, 0xFF	; 255
    334a:	e4 f3       	brlt	.-8      	; 0x3344 <__mulsf3_pse+0x84>
    334c:	98 3e       	cpi	r25, 0xE8	; 232
    334e:	d4 f3       	brlt	.-12     	; 0x3344 <__mulsf3_pse+0x84>
    3350:	86 95       	lsr	r24
    3352:	77 95       	ror	r23
    3354:	67 95       	ror	r22
    3356:	b7 95       	ror	r27
    3358:	f7 95       	ror	r31
    335a:	e7 95       	ror	r30
    335c:	9f 5f       	subi	r25, 0xFF	; 255
    335e:	c1 f7       	brne	.-16     	; 0x3350 <__mulsf3_pse+0x90>
    3360:	fe 2b       	or	r31, r30
    3362:	88 0f       	add	r24, r24
    3364:	91 1d       	adc	r25, r1
    3366:	96 95       	lsr	r25
    3368:	87 95       	ror	r24
    336a:	97 f9       	bld	r25, 7
    336c:	08 95       	ret

0000336e <malloc>:
    336e:	0f 93       	push	r16
    3370:	1f 93       	push	r17
    3372:	cf 93       	push	r28
    3374:	df 93       	push	r29
    3376:	82 30       	cpi	r24, 0x02	; 2
    3378:	91 05       	cpc	r25, r1
    337a:	10 f4       	brcc	.+4      	; 0x3380 <malloc+0x12>
    337c:	82 e0       	ldi	r24, 0x02	; 2
    337e:	90 e0       	ldi	r25, 0x00	; 0
    3380:	e0 91 d1 04 	lds	r30, 0x04D1	; 0x8004d1 <__flp>
    3384:	f0 91 d2 04 	lds	r31, 0x04D2	; 0x8004d2 <__flp+0x1>
    3388:	20 e0       	ldi	r18, 0x00	; 0
    338a:	30 e0       	ldi	r19, 0x00	; 0
    338c:	a0 e0       	ldi	r26, 0x00	; 0
    338e:	b0 e0       	ldi	r27, 0x00	; 0
    3390:	30 97       	sbiw	r30, 0x00	; 0
    3392:	19 f1       	breq	.+70     	; 0x33da <malloc+0x6c>
    3394:	40 81       	ld	r20, Z
    3396:	51 81       	ldd	r21, Z+1	; 0x01
    3398:	02 81       	ldd	r16, Z+2	; 0x02
    339a:	13 81       	ldd	r17, Z+3	; 0x03
    339c:	48 17       	cp	r20, r24
    339e:	59 07       	cpc	r21, r25
    33a0:	c8 f0       	brcs	.+50     	; 0x33d4 <malloc+0x66>
    33a2:	84 17       	cp	r24, r20
    33a4:	95 07       	cpc	r25, r21
    33a6:	69 f4       	brne	.+26     	; 0x33c2 <malloc+0x54>
    33a8:	10 97       	sbiw	r26, 0x00	; 0
    33aa:	31 f0       	breq	.+12     	; 0x33b8 <malloc+0x4a>
    33ac:	12 96       	adiw	r26, 0x02	; 2
    33ae:	0c 93       	st	X, r16
    33b0:	12 97       	sbiw	r26, 0x02	; 2
    33b2:	13 96       	adiw	r26, 0x03	; 3
    33b4:	1c 93       	st	X, r17
    33b6:	27 c0       	rjmp	.+78     	; 0x3406 <malloc+0x98>
    33b8:	00 93 d1 04 	sts	0x04D1, r16	; 0x8004d1 <__flp>
    33bc:	10 93 d2 04 	sts	0x04D2, r17	; 0x8004d2 <__flp+0x1>
    33c0:	22 c0       	rjmp	.+68     	; 0x3406 <malloc+0x98>
    33c2:	21 15       	cp	r18, r1
    33c4:	31 05       	cpc	r19, r1
    33c6:	19 f0       	breq	.+6      	; 0x33ce <malloc+0x60>
    33c8:	42 17       	cp	r20, r18
    33ca:	53 07       	cpc	r21, r19
    33cc:	18 f4       	brcc	.+6      	; 0x33d4 <malloc+0x66>
    33ce:	9a 01       	movw	r18, r20
    33d0:	bd 01       	movw	r22, r26
    33d2:	ef 01       	movw	r28, r30
    33d4:	df 01       	movw	r26, r30
    33d6:	f8 01       	movw	r30, r16
    33d8:	db cf       	rjmp	.-74     	; 0x3390 <malloc+0x22>
    33da:	21 15       	cp	r18, r1
    33dc:	31 05       	cpc	r19, r1
    33de:	f9 f0       	breq	.+62     	; 0x341e <malloc+0xb0>
    33e0:	28 1b       	sub	r18, r24
    33e2:	39 0b       	sbc	r19, r25
    33e4:	24 30       	cpi	r18, 0x04	; 4
    33e6:	31 05       	cpc	r19, r1
    33e8:	80 f4       	brcc	.+32     	; 0x340a <malloc+0x9c>
    33ea:	8a 81       	ldd	r24, Y+2	; 0x02
    33ec:	9b 81       	ldd	r25, Y+3	; 0x03
    33ee:	61 15       	cp	r22, r1
    33f0:	71 05       	cpc	r23, r1
    33f2:	21 f0       	breq	.+8      	; 0x33fc <malloc+0x8e>
    33f4:	fb 01       	movw	r30, r22
    33f6:	93 83       	std	Z+3, r25	; 0x03
    33f8:	82 83       	std	Z+2, r24	; 0x02
    33fa:	04 c0       	rjmp	.+8      	; 0x3404 <malloc+0x96>
    33fc:	90 93 d2 04 	sts	0x04D2, r25	; 0x8004d2 <__flp+0x1>
    3400:	80 93 d1 04 	sts	0x04D1, r24	; 0x8004d1 <__flp>
    3404:	fe 01       	movw	r30, r28
    3406:	32 96       	adiw	r30, 0x02	; 2
    3408:	44 c0       	rjmp	.+136    	; 0x3492 <malloc+0x124>
    340a:	fe 01       	movw	r30, r28
    340c:	e2 0f       	add	r30, r18
    340e:	f3 1f       	adc	r31, r19
    3410:	81 93       	st	Z+, r24
    3412:	91 93       	st	Z+, r25
    3414:	22 50       	subi	r18, 0x02	; 2
    3416:	31 09       	sbc	r19, r1
    3418:	39 83       	std	Y+1, r19	; 0x01
    341a:	28 83       	st	Y, r18
    341c:	3a c0       	rjmp	.+116    	; 0x3492 <malloc+0x124>
    341e:	20 91 cf 04 	lds	r18, 0x04CF	; 0x8004cf <__brkval>
    3422:	30 91 d0 04 	lds	r19, 0x04D0	; 0x8004d0 <__brkval+0x1>
    3426:	23 2b       	or	r18, r19
    3428:	41 f4       	brne	.+16     	; 0x343a <malloc+0xcc>
    342a:	20 91 17 01 	lds	r18, 0x0117	; 0x800117 <__malloc_heap_start>
    342e:	30 91 18 01 	lds	r19, 0x0118	; 0x800118 <__malloc_heap_start+0x1>
    3432:	30 93 d0 04 	sts	0x04D0, r19	; 0x8004d0 <__brkval+0x1>
    3436:	20 93 cf 04 	sts	0x04CF, r18	; 0x8004cf <__brkval>
    343a:	20 91 15 01 	lds	r18, 0x0115	; 0x800115 <__malloc_heap_end>
    343e:	30 91 16 01 	lds	r19, 0x0116	; 0x800116 <__malloc_heap_end+0x1>
    3442:	21 15       	cp	r18, r1
    3444:	31 05       	cpc	r19, r1
    3446:	41 f4       	brne	.+16     	; 0x3458 <malloc+0xea>
    3448:	2d b7       	in	r18, 0x3d	; 61
    344a:	3e b7       	in	r19, 0x3e	; 62
    344c:	40 91 19 01 	lds	r20, 0x0119	; 0x800119 <__malloc_margin>
    3450:	50 91 1a 01 	lds	r21, 0x011A	; 0x80011a <__malloc_margin+0x1>
    3454:	24 1b       	sub	r18, r20
    3456:	35 0b       	sbc	r19, r21
    3458:	e0 91 cf 04 	lds	r30, 0x04CF	; 0x8004cf <__brkval>
    345c:	f0 91 d0 04 	lds	r31, 0x04D0	; 0x8004d0 <__brkval+0x1>
    3460:	e2 17       	cp	r30, r18
    3462:	f3 07       	cpc	r31, r19
    3464:	a0 f4       	brcc	.+40     	; 0x348e <malloc+0x120>
    3466:	2e 1b       	sub	r18, r30
    3468:	3f 0b       	sbc	r19, r31
    346a:	28 17       	cp	r18, r24
    346c:	39 07       	cpc	r19, r25
    346e:	78 f0       	brcs	.+30     	; 0x348e <malloc+0x120>
    3470:	ac 01       	movw	r20, r24
    3472:	4e 5f       	subi	r20, 0xFE	; 254
    3474:	5f 4f       	sbci	r21, 0xFF	; 255
    3476:	24 17       	cp	r18, r20
    3478:	35 07       	cpc	r19, r21
    347a:	48 f0       	brcs	.+18     	; 0x348e <malloc+0x120>
    347c:	4e 0f       	add	r20, r30
    347e:	5f 1f       	adc	r21, r31
    3480:	50 93 d0 04 	sts	0x04D0, r21	; 0x8004d0 <__brkval+0x1>
    3484:	40 93 cf 04 	sts	0x04CF, r20	; 0x8004cf <__brkval>
    3488:	81 93       	st	Z+, r24
    348a:	91 93       	st	Z+, r25
    348c:	02 c0       	rjmp	.+4      	; 0x3492 <malloc+0x124>
    348e:	e0 e0       	ldi	r30, 0x00	; 0
    3490:	f0 e0       	ldi	r31, 0x00	; 0
    3492:	cf 01       	movw	r24, r30
    3494:	df 91       	pop	r29
    3496:	cf 91       	pop	r28
    3498:	1f 91       	pop	r17
    349a:	0f 91       	pop	r16
    349c:	08 95       	ret

0000349e <free>:
    349e:	cf 93       	push	r28
    34a0:	df 93       	push	r29
    34a2:	00 97       	sbiw	r24, 0x00	; 0
    34a4:	09 f4       	brne	.+2      	; 0x34a8 <free+0xa>
    34a6:	81 c0       	rjmp	.+258    	; 0x35aa <free+0x10c>
    34a8:	fc 01       	movw	r30, r24
    34aa:	32 97       	sbiw	r30, 0x02	; 2
    34ac:	13 82       	std	Z+3, r1	; 0x03
    34ae:	12 82       	std	Z+2, r1	; 0x02
    34b0:	a0 91 d1 04 	lds	r26, 0x04D1	; 0x8004d1 <__flp>
    34b4:	b0 91 d2 04 	lds	r27, 0x04D2	; 0x8004d2 <__flp+0x1>
    34b8:	10 97       	sbiw	r26, 0x00	; 0
    34ba:	81 f4       	brne	.+32     	; 0x34dc <free+0x3e>
    34bc:	20 81       	ld	r18, Z
    34be:	31 81       	ldd	r19, Z+1	; 0x01
    34c0:	82 0f       	add	r24, r18
    34c2:	93 1f       	adc	r25, r19
    34c4:	20 91 cf 04 	lds	r18, 0x04CF	; 0x8004cf <__brkval>
    34c8:	30 91 d0 04 	lds	r19, 0x04D0	; 0x8004d0 <__brkval+0x1>
    34cc:	28 17       	cp	r18, r24
    34ce:	39 07       	cpc	r19, r25
    34d0:	51 f5       	brne	.+84     	; 0x3526 <free+0x88>
    34d2:	f0 93 d0 04 	sts	0x04D0, r31	; 0x8004d0 <__brkval+0x1>
    34d6:	e0 93 cf 04 	sts	0x04CF, r30	; 0x8004cf <__brkval>
    34da:	67 c0       	rjmp	.+206    	; 0x35aa <free+0x10c>
    34dc:	ed 01       	movw	r28, r26
    34de:	20 e0       	ldi	r18, 0x00	; 0
    34e0:	30 e0       	ldi	r19, 0x00	; 0
    34e2:	ce 17       	cp	r28, r30
    34e4:	df 07       	cpc	r29, r31
    34e6:	40 f4       	brcc	.+16     	; 0x34f8 <free+0x5a>
    34e8:	4a 81       	ldd	r20, Y+2	; 0x02
    34ea:	5b 81       	ldd	r21, Y+3	; 0x03
    34ec:	9e 01       	movw	r18, r28
    34ee:	41 15       	cp	r20, r1
    34f0:	51 05       	cpc	r21, r1
    34f2:	f1 f0       	breq	.+60     	; 0x3530 <free+0x92>
    34f4:	ea 01       	movw	r28, r20
    34f6:	f5 cf       	rjmp	.-22     	; 0x34e2 <free+0x44>
    34f8:	d3 83       	std	Z+3, r29	; 0x03
    34fa:	c2 83       	std	Z+2, r28	; 0x02
    34fc:	40 81       	ld	r20, Z
    34fe:	51 81       	ldd	r21, Z+1	; 0x01
    3500:	84 0f       	add	r24, r20
    3502:	95 1f       	adc	r25, r21
    3504:	c8 17       	cp	r28, r24
    3506:	d9 07       	cpc	r29, r25
    3508:	59 f4       	brne	.+22     	; 0x3520 <free+0x82>
    350a:	88 81       	ld	r24, Y
    350c:	99 81       	ldd	r25, Y+1	; 0x01
    350e:	84 0f       	add	r24, r20
    3510:	95 1f       	adc	r25, r21
    3512:	02 96       	adiw	r24, 0x02	; 2
    3514:	91 83       	std	Z+1, r25	; 0x01
    3516:	80 83       	st	Z, r24
    3518:	8a 81       	ldd	r24, Y+2	; 0x02
    351a:	9b 81       	ldd	r25, Y+3	; 0x03
    351c:	93 83       	std	Z+3, r25	; 0x03
    351e:	82 83       	std	Z+2, r24	; 0x02
    3520:	21 15       	cp	r18, r1
    3522:	31 05       	cpc	r19, r1
    3524:	29 f4       	brne	.+10     	; 0x3530 <free+0x92>
    3526:	f0 93 d2 04 	sts	0x04D2, r31	; 0x8004d2 <__flp+0x1>
    352a:	e0 93 d1 04 	sts	0x04D1, r30	; 0x8004d1 <__flp>
    352e:	3d c0       	rjmp	.+122    	; 0x35aa <free+0x10c>
    3530:	e9 01       	movw	r28, r18
    3532:	fb 83       	std	Y+3, r31	; 0x03
    3534:	ea 83       	std	Y+2, r30	; 0x02
    3536:	49 91       	ld	r20, Y+
    3538:	59 91       	ld	r21, Y+
    353a:	c4 0f       	add	r28, r20
    353c:	d5 1f       	adc	r29, r21
    353e:	ec 17       	cp	r30, r28
    3540:	fd 07       	cpc	r31, r29
    3542:	61 f4       	brne	.+24     	; 0x355c <free+0xbe>
    3544:	80 81       	ld	r24, Z
    3546:	91 81       	ldd	r25, Z+1	; 0x01
    3548:	84 0f       	add	r24, r20
    354a:	95 1f       	adc	r25, r21
    354c:	02 96       	adiw	r24, 0x02	; 2
    354e:	e9 01       	movw	r28, r18
    3550:	99 83       	std	Y+1, r25	; 0x01
    3552:	88 83       	st	Y, r24
    3554:	82 81       	ldd	r24, Z+2	; 0x02
    3556:	93 81       	ldd	r25, Z+3	; 0x03
    3558:	9b 83       	std	Y+3, r25	; 0x03
    355a:	8a 83       	std	Y+2, r24	; 0x02
    355c:	e0 e0       	ldi	r30, 0x00	; 0
    355e:	f0 e0       	ldi	r31, 0x00	; 0
    3560:	12 96       	adiw	r26, 0x02	; 2
    3562:	8d 91       	ld	r24, X+
    3564:	9c 91       	ld	r25, X
    3566:	13 97       	sbiw	r26, 0x03	; 3
    3568:	00 97       	sbiw	r24, 0x00	; 0
    356a:	19 f0       	breq	.+6      	; 0x3572 <free+0xd4>
    356c:	fd 01       	movw	r30, r26
    356e:	dc 01       	movw	r26, r24
    3570:	f7 cf       	rjmp	.-18     	; 0x3560 <free+0xc2>
    3572:	8d 91       	ld	r24, X+
    3574:	9c 91       	ld	r25, X
    3576:	11 97       	sbiw	r26, 0x01	; 1
    3578:	9d 01       	movw	r18, r26
    357a:	2e 5f       	subi	r18, 0xFE	; 254
    357c:	3f 4f       	sbci	r19, 0xFF	; 255
    357e:	82 0f       	add	r24, r18
    3580:	93 1f       	adc	r25, r19
    3582:	20 91 cf 04 	lds	r18, 0x04CF	; 0x8004cf <__brkval>
    3586:	30 91 d0 04 	lds	r19, 0x04D0	; 0x8004d0 <__brkval+0x1>
    358a:	28 17       	cp	r18, r24
    358c:	39 07       	cpc	r19, r25
    358e:	69 f4       	brne	.+26     	; 0x35aa <free+0x10c>
    3590:	30 97       	sbiw	r30, 0x00	; 0
    3592:	29 f4       	brne	.+10     	; 0x359e <free+0x100>
    3594:	10 92 d2 04 	sts	0x04D2, r1	; 0x8004d2 <__flp+0x1>
    3598:	10 92 d1 04 	sts	0x04D1, r1	; 0x8004d1 <__flp>
    359c:	02 c0       	rjmp	.+4      	; 0x35a2 <free+0x104>
    359e:	13 82       	std	Z+3, r1	; 0x03
    35a0:	12 82       	std	Z+2, r1	; 0x02
    35a2:	b0 93 d0 04 	sts	0x04D0, r27	; 0x8004d0 <__brkval+0x1>
    35a6:	a0 93 cf 04 	sts	0x04CF, r26	; 0x8004cf <__brkval>
    35aa:	df 91       	pop	r29
    35ac:	cf 91       	pop	r28
    35ae:	08 95       	ret

000035b0 <abort>:
    35b0:	81 e0       	ldi	r24, 0x01	; 1
    35b2:	90 e0       	ldi	r25, 0x00	; 0
    35b4:	f8 94       	cli
    35b6:	0c 94 9e 1d 	jmp	0x3b3c	; 0x3b3c <__do_global_dtors>

000035ba <snprintf>:
    35ba:	ae e0       	ldi	r26, 0x0E	; 14
    35bc:	b0 e0       	ldi	r27, 0x00	; 0
    35be:	e3 ee       	ldi	r30, 0xE3	; 227
    35c0:	fa e1       	ldi	r31, 0x1A	; 26
    35c2:	0c 94 29 17 	jmp	0x2e52	; 0x2e52 <__prologue_saves__+0x1c>
    35c6:	0d 89       	ldd	r16, Y+21	; 0x15
    35c8:	1e 89       	ldd	r17, Y+22	; 0x16
    35ca:	8f 89       	ldd	r24, Y+23	; 0x17
    35cc:	98 8d       	ldd	r25, Y+24	; 0x18
    35ce:	26 e0       	ldi	r18, 0x06	; 6
    35d0:	2c 83       	std	Y+4, r18	; 0x04
    35d2:	1a 83       	std	Y+2, r17	; 0x02
    35d4:	09 83       	std	Y+1, r16	; 0x01
    35d6:	97 ff       	sbrs	r25, 7
    35d8:	02 c0       	rjmp	.+4      	; 0x35de <snprintf+0x24>
    35da:	80 e0       	ldi	r24, 0x00	; 0
    35dc:	90 e8       	ldi	r25, 0x80	; 128
    35de:	01 97       	sbiw	r24, 0x01	; 1
    35e0:	9e 83       	std	Y+6, r25	; 0x06
    35e2:	8d 83       	std	Y+5, r24	; 0x05
    35e4:	ae 01       	movw	r20, r28
    35e6:	45 5e       	subi	r20, 0xE5	; 229
    35e8:	5f 4f       	sbci	r21, 0xFF	; 255
    35ea:	69 8d       	ldd	r22, Y+25	; 0x19
    35ec:	7a 8d       	ldd	r23, Y+26	; 0x1a
    35ee:	ce 01       	movw	r24, r28
    35f0:	01 96       	adiw	r24, 0x01	; 1
    35f2:	0e 94 0d 1b 	call	0x361a	; 0x361a <vfprintf>
    35f6:	4d 81       	ldd	r20, Y+5	; 0x05
    35f8:	5e 81       	ldd	r21, Y+6	; 0x06
    35fa:	57 fd       	sbrc	r21, 7
    35fc:	0a c0       	rjmp	.+20     	; 0x3612 <snprintf+0x58>
    35fe:	2f 81       	ldd	r18, Y+7	; 0x07
    3600:	38 85       	ldd	r19, Y+8	; 0x08
    3602:	42 17       	cp	r20, r18
    3604:	53 07       	cpc	r21, r19
    3606:	0c f4       	brge	.+2      	; 0x360a <snprintf+0x50>
    3608:	9a 01       	movw	r18, r20
    360a:	f8 01       	movw	r30, r16
    360c:	e2 0f       	add	r30, r18
    360e:	f3 1f       	adc	r31, r19
    3610:	10 82       	st	Z, r1
    3612:	2e 96       	adiw	r28, 0x0e	; 14
    3614:	e4 e0       	ldi	r30, 0x04	; 4
    3616:	0c 94 45 17 	jmp	0x2e8a	; 0x2e8a <__epilogue_restores__+0x1c>

0000361a <vfprintf>:
    361a:	ab e0       	ldi	r26, 0x0B	; 11
    361c:	b0 e0       	ldi	r27, 0x00	; 0
    361e:	e3 e1       	ldi	r30, 0x13	; 19
    3620:	fb e1       	ldi	r31, 0x1B	; 27
    3622:	0c 94 1b 17 	jmp	0x2e36	; 0x2e36 <__prologue_saves__>
    3626:	6c 01       	movw	r12, r24
    3628:	7b 01       	movw	r14, r22
    362a:	8a 01       	movw	r16, r20
    362c:	fc 01       	movw	r30, r24
    362e:	17 82       	std	Z+7, r1	; 0x07
    3630:	16 82       	std	Z+6, r1	; 0x06
    3632:	83 81       	ldd	r24, Z+3	; 0x03
    3634:	81 ff       	sbrs	r24, 1
    3636:	cc c1       	rjmp	.+920    	; 0x39d0 <vfprintf+0x3b6>
    3638:	ce 01       	movw	r24, r28
    363a:	01 96       	adiw	r24, 0x01	; 1
    363c:	3c 01       	movw	r6, r24
    363e:	f6 01       	movw	r30, r12
    3640:	93 81       	ldd	r25, Z+3	; 0x03
    3642:	f7 01       	movw	r30, r14
    3644:	93 fd       	sbrc	r25, 3
    3646:	85 91       	lpm	r24, Z+
    3648:	93 ff       	sbrs	r25, 3
    364a:	81 91       	ld	r24, Z+
    364c:	7f 01       	movw	r14, r30
    364e:	88 23       	and	r24, r24
    3650:	09 f4       	brne	.+2      	; 0x3654 <vfprintf+0x3a>
    3652:	ba c1       	rjmp	.+884    	; 0x39c8 <vfprintf+0x3ae>
    3654:	85 32       	cpi	r24, 0x25	; 37
    3656:	39 f4       	brne	.+14     	; 0x3666 <vfprintf+0x4c>
    3658:	93 fd       	sbrc	r25, 3
    365a:	85 91       	lpm	r24, Z+
    365c:	93 ff       	sbrs	r25, 3
    365e:	81 91       	ld	r24, Z+
    3660:	7f 01       	movw	r14, r30
    3662:	85 32       	cpi	r24, 0x25	; 37
    3664:	29 f4       	brne	.+10     	; 0x3670 <vfprintf+0x56>
    3666:	b6 01       	movw	r22, r12
    3668:	90 e0       	ldi	r25, 0x00	; 0
    366a:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    366e:	e7 cf       	rjmp	.-50     	; 0x363e <vfprintf+0x24>
    3670:	91 2c       	mov	r9, r1
    3672:	21 2c       	mov	r2, r1
    3674:	31 2c       	mov	r3, r1
    3676:	ff e1       	ldi	r31, 0x1F	; 31
    3678:	f3 15       	cp	r31, r3
    367a:	d8 f0       	brcs	.+54     	; 0x36b2 <vfprintf+0x98>
    367c:	8b 32       	cpi	r24, 0x2B	; 43
    367e:	79 f0       	breq	.+30     	; 0x369e <vfprintf+0x84>
    3680:	38 f4       	brcc	.+14     	; 0x3690 <vfprintf+0x76>
    3682:	80 32       	cpi	r24, 0x20	; 32
    3684:	79 f0       	breq	.+30     	; 0x36a4 <vfprintf+0x8a>
    3686:	83 32       	cpi	r24, 0x23	; 35
    3688:	a1 f4       	brne	.+40     	; 0x36b2 <vfprintf+0x98>
    368a:	23 2d       	mov	r18, r3
    368c:	20 61       	ori	r18, 0x10	; 16
    368e:	1d c0       	rjmp	.+58     	; 0x36ca <vfprintf+0xb0>
    3690:	8d 32       	cpi	r24, 0x2D	; 45
    3692:	61 f0       	breq	.+24     	; 0x36ac <vfprintf+0x92>
    3694:	80 33       	cpi	r24, 0x30	; 48
    3696:	69 f4       	brne	.+26     	; 0x36b2 <vfprintf+0x98>
    3698:	23 2d       	mov	r18, r3
    369a:	21 60       	ori	r18, 0x01	; 1
    369c:	16 c0       	rjmp	.+44     	; 0x36ca <vfprintf+0xb0>
    369e:	83 2d       	mov	r24, r3
    36a0:	82 60       	ori	r24, 0x02	; 2
    36a2:	38 2e       	mov	r3, r24
    36a4:	e3 2d       	mov	r30, r3
    36a6:	e4 60       	ori	r30, 0x04	; 4
    36a8:	3e 2e       	mov	r3, r30
    36aa:	2a c0       	rjmp	.+84     	; 0x3700 <vfprintf+0xe6>
    36ac:	f3 2d       	mov	r31, r3
    36ae:	f8 60       	ori	r31, 0x08	; 8
    36b0:	1d c0       	rjmp	.+58     	; 0x36ec <vfprintf+0xd2>
    36b2:	37 fc       	sbrc	r3, 7
    36b4:	2d c0       	rjmp	.+90     	; 0x3710 <vfprintf+0xf6>
    36b6:	20 ed       	ldi	r18, 0xD0	; 208
    36b8:	28 0f       	add	r18, r24
    36ba:	2a 30       	cpi	r18, 0x0A	; 10
    36bc:	40 f0       	brcs	.+16     	; 0x36ce <vfprintf+0xb4>
    36be:	8e 32       	cpi	r24, 0x2E	; 46
    36c0:	b9 f4       	brne	.+46     	; 0x36f0 <vfprintf+0xd6>
    36c2:	36 fc       	sbrc	r3, 6
    36c4:	81 c1       	rjmp	.+770    	; 0x39c8 <vfprintf+0x3ae>
    36c6:	23 2d       	mov	r18, r3
    36c8:	20 64       	ori	r18, 0x40	; 64
    36ca:	32 2e       	mov	r3, r18
    36cc:	19 c0       	rjmp	.+50     	; 0x3700 <vfprintf+0xe6>
    36ce:	36 fe       	sbrs	r3, 6
    36d0:	06 c0       	rjmp	.+12     	; 0x36de <vfprintf+0xc4>
    36d2:	8a e0       	ldi	r24, 0x0A	; 10
    36d4:	98 9e       	mul	r9, r24
    36d6:	20 0d       	add	r18, r0
    36d8:	11 24       	eor	r1, r1
    36da:	92 2e       	mov	r9, r18
    36dc:	11 c0       	rjmp	.+34     	; 0x3700 <vfprintf+0xe6>
    36de:	ea e0       	ldi	r30, 0x0A	; 10
    36e0:	2e 9e       	mul	r2, r30
    36e2:	20 0d       	add	r18, r0
    36e4:	11 24       	eor	r1, r1
    36e6:	22 2e       	mov	r2, r18
    36e8:	f3 2d       	mov	r31, r3
    36ea:	f0 62       	ori	r31, 0x20	; 32
    36ec:	3f 2e       	mov	r3, r31
    36ee:	08 c0       	rjmp	.+16     	; 0x3700 <vfprintf+0xe6>
    36f0:	8c 36       	cpi	r24, 0x6C	; 108
    36f2:	21 f4       	brne	.+8      	; 0x36fc <vfprintf+0xe2>
    36f4:	83 2d       	mov	r24, r3
    36f6:	80 68       	ori	r24, 0x80	; 128
    36f8:	38 2e       	mov	r3, r24
    36fa:	02 c0       	rjmp	.+4      	; 0x3700 <vfprintf+0xe6>
    36fc:	88 36       	cpi	r24, 0x68	; 104
    36fe:	41 f4       	brne	.+16     	; 0x3710 <vfprintf+0xf6>
    3700:	f7 01       	movw	r30, r14
    3702:	93 fd       	sbrc	r25, 3
    3704:	85 91       	lpm	r24, Z+
    3706:	93 ff       	sbrs	r25, 3
    3708:	81 91       	ld	r24, Z+
    370a:	7f 01       	movw	r14, r30
    370c:	81 11       	cpse	r24, r1
    370e:	b3 cf       	rjmp	.-154    	; 0x3676 <vfprintf+0x5c>
    3710:	98 2f       	mov	r25, r24
    3712:	9f 7d       	andi	r25, 0xDF	; 223
    3714:	95 54       	subi	r25, 0x45	; 69
    3716:	93 30       	cpi	r25, 0x03	; 3
    3718:	28 f4       	brcc	.+10     	; 0x3724 <vfprintf+0x10a>
    371a:	0c 5f       	subi	r16, 0xFC	; 252
    371c:	1f 4f       	sbci	r17, 0xFF	; 255
    371e:	9f e3       	ldi	r25, 0x3F	; 63
    3720:	99 83       	std	Y+1, r25	; 0x01
    3722:	0d c0       	rjmp	.+26     	; 0x373e <vfprintf+0x124>
    3724:	83 36       	cpi	r24, 0x63	; 99
    3726:	31 f0       	breq	.+12     	; 0x3734 <vfprintf+0x11a>
    3728:	83 37       	cpi	r24, 0x73	; 115
    372a:	71 f0       	breq	.+28     	; 0x3748 <vfprintf+0x12e>
    372c:	83 35       	cpi	r24, 0x53	; 83
    372e:	09 f0       	breq	.+2      	; 0x3732 <vfprintf+0x118>
    3730:	59 c0       	rjmp	.+178    	; 0x37e4 <vfprintf+0x1ca>
    3732:	21 c0       	rjmp	.+66     	; 0x3776 <vfprintf+0x15c>
    3734:	f8 01       	movw	r30, r16
    3736:	80 81       	ld	r24, Z
    3738:	89 83       	std	Y+1, r24	; 0x01
    373a:	0e 5f       	subi	r16, 0xFE	; 254
    373c:	1f 4f       	sbci	r17, 0xFF	; 255
    373e:	88 24       	eor	r8, r8
    3740:	83 94       	inc	r8
    3742:	91 2c       	mov	r9, r1
    3744:	53 01       	movw	r10, r6
    3746:	13 c0       	rjmp	.+38     	; 0x376e <vfprintf+0x154>
    3748:	28 01       	movw	r4, r16
    374a:	f2 e0       	ldi	r31, 0x02	; 2
    374c:	4f 0e       	add	r4, r31
    374e:	51 1c       	adc	r5, r1
    3750:	f8 01       	movw	r30, r16
    3752:	a0 80       	ld	r10, Z
    3754:	b1 80       	ldd	r11, Z+1	; 0x01
    3756:	36 fe       	sbrs	r3, 6
    3758:	03 c0       	rjmp	.+6      	; 0x3760 <vfprintf+0x146>
    375a:	69 2d       	mov	r22, r9
    375c:	70 e0       	ldi	r23, 0x00	; 0
    375e:	02 c0       	rjmp	.+4      	; 0x3764 <vfprintf+0x14a>
    3760:	6f ef       	ldi	r22, 0xFF	; 255
    3762:	7f ef       	ldi	r23, 0xFF	; 255
    3764:	c5 01       	movw	r24, r10
    3766:	0e 94 f9 1c 	call	0x39f2	; 0x39f2 <strnlen>
    376a:	4c 01       	movw	r8, r24
    376c:	82 01       	movw	r16, r4
    376e:	f3 2d       	mov	r31, r3
    3770:	ff 77       	andi	r31, 0x7F	; 127
    3772:	3f 2e       	mov	r3, r31
    3774:	16 c0       	rjmp	.+44     	; 0x37a2 <vfprintf+0x188>
    3776:	28 01       	movw	r4, r16
    3778:	22 e0       	ldi	r18, 0x02	; 2
    377a:	42 0e       	add	r4, r18
    377c:	51 1c       	adc	r5, r1
    377e:	f8 01       	movw	r30, r16
    3780:	a0 80       	ld	r10, Z
    3782:	b1 80       	ldd	r11, Z+1	; 0x01
    3784:	36 fe       	sbrs	r3, 6
    3786:	03 c0       	rjmp	.+6      	; 0x378e <vfprintf+0x174>
    3788:	69 2d       	mov	r22, r9
    378a:	70 e0       	ldi	r23, 0x00	; 0
    378c:	02 c0       	rjmp	.+4      	; 0x3792 <vfprintf+0x178>
    378e:	6f ef       	ldi	r22, 0xFF	; 255
    3790:	7f ef       	ldi	r23, 0xFF	; 255
    3792:	c5 01       	movw	r24, r10
    3794:	0e 94 ee 1c 	call	0x39dc	; 0x39dc <strnlen_P>
    3798:	4c 01       	movw	r8, r24
    379a:	f3 2d       	mov	r31, r3
    379c:	f0 68       	ori	r31, 0x80	; 128
    379e:	3f 2e       	mov	r3, r31
    37a0:	82 01       	movw	r16, r4
    37a2:	33 fc       	sbrc	r3, 3
    37a4:	1b c0       	rjmp	.+54     	; 0x37dc <vfprintf+0x1c2>
    37a6:	82 2d       	mov	r24, r2
    37a8:	90 e0       	ldi	r25, 0x00	; 0
    37aa:	88 16       	cp	r8, r24
    37ac:	99 06       	cpc	r9, r25
    37ae:	b0 f4       	brcc	.+44     	; 0x37dc <vfprintf+0x1c2>
    37b0:	b6 01       	movw	r22, r12
    37b2:	80 e2       	ldi	r24, 0x20	; 32
    37b4:	90 e0       	ldi	r25, 0x00	; 0
    37b6:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    37ba:	2a 94       	dec	r2
    37bc:	f4 cf       	rjmp	.-24     	; 0x37a6 <vfprintf+0x18c>
    37be:	f5 01       	movw	r30, r10
    37c0:	37 fc       	sbrc	r3, 7
    37c2:	85 91       	lpm	r24, Z+
    37c4:	37 fe       	sbrs	r3, 7
    37c6:	81 91       	ld	r24, Z+
    37c8:	5f 01       	movw	r10, r30
    37ca:	b6 01       	movw	r22, r12
    37cc:	90 e0       	ldi	r25, 0x00	; 0
    37ce:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    37d2:	21 10       	cpse	r2, r1
    37d4:	2a 94       	dec	r2
    37d6:	21 e0       	ldi	r18, 0x01	; 1
    37d8:	82 1a       	sub	r8, r18
    37da:	91 08       	sbc	r9, r1
    37dc:	81 14       	cp	r8, r1
    37de:	91 04       	cpc	r9, r1
    37e0:	71 f7       	brne	.-36     	; 0x37be <vfprintf+0x1a4>
    37e2:	e8 c0       	rjmp	.+464    	; 0x39b4 <vfprintf+0x39a>
    37e4:	84 36       	cpi	r24, 0x64	; 100
    37e6:	11 f0       	breq	.+4      	; 0x37ec <vfprintf+0x1d2>
    37e8:	89 36       	cpi	r24, 0x69	; 105
    37ea:	41 f5       	brne	.+80     	; 0x383c <vfprintf+0x222>
    37ec:	f8 01       	movw	r30, r16
    37ee:	37 fe       	sbrs	r3, 7
    37f0:	07 c0       	rjmp	.+14     	; 0x3800 <vfprintf+0x1e6>
    37f2:	60 81       	ld	r22, Z
    37f4:	71 81       	ldd	r23, Z+1	; 0x01
    37f6:	82 81       	ldd	r24, Z+2	; 0x02
    37f8:	93 81       	ldd	r25, Z+3	; 0x03
    37fa:	0c 5f       	subi	r16, 0xFC	; 252
    37fc:	1f 4f       	sbci	r17, 0xFF	; 255
    37fe:	08 c0       	rjmp	.+16     	; 0x3810 <vfprintf+0x1f6>
    3800:	60 81       	ld	r22, Z
    3802:	71 81       	ldd	r23, Z+1	; 0x01
    3804:	07 2e       	mov	r0, r23
    3806:	00 0c       	add	r0, r0
    3808:	88 0b       	sbc	r24, r24
    380a:	99 0b       	sbc	r25, r25
    380c:	0e 5f       	subi	r16, 0xFE	; 254
    380e:	1f 4f       	sbci	r17, 0xFF	; 255
    3810:	f3 2d       	mov	r31, r3
    3812:	ff 76       	andi	r31, 0x6F	; 111
    3814:	3f 2e       	mov	r3, r31
    3816:	97 ff       	sbrs	r25, 7
    3818:	09 c0       	rjmp	.+18     	; 0x382c <vfprintf+0x212>
    381a:	90 95       	com	r25
    381c:	80 95       	com	r24
    381e:	70 95       	com	r23
    3820:	61 95       	neg	r22
    3822:	7f 4f       	sbci	r23, 0xFF	; 255
    3824:	8f 4f       	sbci	r24, 0xFF	; 255
    3826:	9f 4f       	sbci	r25, 0xFF	; 255
    3828:	f0 68       	ori	r31, 0x80	; 128
    382a:	3f 2e       	mov	r3, r31
    382c:	2a e0       	ldi	r18, 0x0A	; 10
    382e:	30 e0       	ldi	r19, 0x00	; 0
    3830:	a3 01       	movw	r20, r6
    3832:	0e 94 40 1d 	call	0x3a80	; 0x3a80 <__ultoa_invert>
    3836:	88 2e       	mov	r8, r24
    3838:	86 18       	sub	r8, r6
    383a:	45 c0       	rjmp	.+138    	; 0x38c6 <vfprintf+0x2ac>
    383c:	85 37       	cpi	r24, 0x75	; 117
    383e:	31 f4       	brne	.+12     	; 0x384c <vfprintf+0x232>
    3840:	23 2d       	mov	r18, r3
    3842:	2f 7e       	andi	r18, 0xEF	; 239
    3844:	b2 2e       	mov	r11, r18
    3846:	2a e0       	ldi	r18, 0x0A	; 10
    3848:	30 e0       	ldi	r19, 0x00	; 0
    384a:	25 c0       	rjmp	.+74     	; 0x3896 <vfprintf+0x27c>
    384c:	93 2d       	mov	r25, r3
    384e:	99 7f       	andi	r25, 0xF9	; 249
    3850:	b9 2e       	mov	r11, r25
    3852:	8f 36       	cpi	r24, 0x6F	; 111
    3854:	c1 f0       	breq	.+48     	; 0x3886 <vfprintf+0x26c>
    3856:	18 f4       	brcc	.+6      	; 0x385e <vfprintf+0x244>
    3858:	88 35       	cpi	r24, 0x58	; 88
    385a:	79 f0       	breq	.+30     	; 0x387a <vfprintf+0x260>
    385c:	b5 c0       	rjmp	.+362    	; 0x39c8 <vfprintf+0x3ae>
    385e:	80 37       	cpi	r24, 0x70	; 112
    3860:	19 f0       	breq	.+6      	; 0x3868 <vfprintf+0x24e>
    3862:	88 37       	cpi	r24, 0x78	; 120
    3864:	21 f0       	breq	.+8      	; 0x386e <vfprintf+0x254>
    3866:	b0 c0       	rjmp	.+352    	; 0x39c8 <vfprintf+0x3ae>
    3868:	e9 2f       	mov	r30, r25
    386a:	e0 61       	ori	r30, 0x10	; 16
    386c:	be 2e       	mov	r11, r30
    386e:	b4 fe       	sbrs	r11, 4
    3870:	0d c0       	rjmp	.+26     	; 0x388c <vfprintf+0x272>
    3872:	fb 2d       	mov	r31, r11
    3874:	f4 60       	ori	r31, 0x04	; 4
    3876:	bf 2e       	mov	r11, r31
    3878:	09 c0       	rjmp	.+18     	; 0x388c <vfprintf+0x272>
    387a:	34 fe       	sbrs	r3, 4
    387c:	0a c0       	rjmp	.+20     	; 0x3892 <vfprintf+0x278>
    387e:	29 2f       	mov	r18, r25
    3880:	26 60       	ori	r18, 0x06	; 6
    3882:	b2 2e       	mov	r11, r18
    3884:	06 c0       	rjmp	.+12     	; 0x3892 <vfprintf+0x278>
    3886:	28 e0       	ldi	r18, 0x08	; 8
    3888:	30 e0       	ldi	r19, 0x00	; 0
    388a:	05 c0       	rjmp	.+10     	; 0x3896 <vfprintf+0x27c>
    388c:	20 e1       	ldi	r18, 0x10	; 16
    388e:	30 e0       	ldi	r19, 0x00	; 0
    3890:	02 c0       	rjmp	.+4      	; 0x3896 <vfprintf+0x27c>
    3892:	20 e1       	ldi	r18, 0x10	; 16
    3894:	32 e0       	ldi	r19, 0x02	; 2
    3896:	f8 01       	movw	r30, r16
    3898:	b7 fe       	sbrs	r11, 7
    389a:	07 c0       	rjmp	.+14     	; 0x38aa <vfprintf+0x290>
    389c:	60 81       	ld	r22, Z
    389e:	71 81       	ldd	r23, Z+1	; 0x01
    38a0:	82 81       	ldd	r24, Z+2	; 0x02
    38a2:	93 81       	ldd	r25, Z+3	; 0x03
    38a4:	0c 5f       	subi	r16, 0xFC	; 252
    38a6:	1f 4f       	sbci	r17, 0xFF	; 255
    38a8:	06 c0       	rjmp	.+12     	; 0x38b6 <vfprintf+0x29c>
    38aa:	60 81       	ld	r22, Z
    38ac:	71 81       	ldd	r23, Z+1	; 0x01
    38ae:	80 e0       	ldi	r24, 0x00	; 0
    38b0:	90 e0       	ldi	r25, 0x00	; 0
    38b2:	0e 5f       	subi	r16, 0xFE	; 254
    38b4:	1f 4f       	sbci	r17, 0xFF	; 255
    38b6:	a3 01       	movw	r20, r6
    38b8:	0e 94 40 1d 	call	0x3a80	; 0x3a80 <__ultoa_invert>
    38bc:	88 2e       	mov	r8, r24
    38be:	86 18       	sub	r8, r6
    38c0:	fb 2d       	mov	r31, r11
    38c2:	ff 77       	andi	r31, 0x7F	; 127
    38c4:	3f 2e       	mov	r3, r31
    38c6:	36 fe       	sbrs	r3, 6
    38c8:	0d c0       	rjmp	.+26     	; 0x38e4 <vfprintf+0x2ca>
    38ca:	23 2d       	mov	r18, r3
    38cc:	2e 7f       	andi	r18, 0xFE	; 254
    38ce:	a2 2e       	mov	r10, r18
    38d0:	89 14       	cp	r8, r9
    38d2:	58 f4       	brcc	.+22     	; 0x38ea <vfprintf+0x2d0>
    38d4:	34 fe       	sbrs	r3, 4
    38d6:	0b c0       	rjmp	.+22     	; 0x38ee <vfprintf+0x2d4>
    38d8:	32 fc       	sbrc	r3, 2
    38da:	09 c0       	rjmp	.+18     	; 0x38ee <vfprintf+0x2d4>
    38dc:	83 2d       	mov	r24, r3
    38de:	8e 7e       	andi	r24, 0xEE	; 238
    38e0:	a8 2e       	mov	r10, r24
    38e2:	05 c0       	rjmp	.+10     	; 0x38ee <vfprintf+0x2d4>
    38e4:	b8 2c       	mov	r11, r8
    38e6:	a3 2c       	mov	r10, r3
    38e8:	03 c0       	rjmp	.+6      	; 0x38f0 <vfprintf+0x2d6>
    38ea:	b8 2c       	mov	r11, r8
    38ec:	01 c0       	rjmp	.+2      	; 0x38f0 <vfprintf+0x2d6>
    38ee:	b9 2c       	mov	r11, r9
    38f0:	a4 fe       	sbrs	r10, 4
    38f2:	0f c0       	rjmp	.+30     	; 0x3912 <vfprintf+0x2f8>
    38f4:	fe 01       	movw	r30, r28
    38f6:	e8 0d       	add	r30, r8
    38f8:	f1 1d       	adc	r31, r1
    38fa:	80 81       	ld	r24, Z
    38fc:	80 33       	cpi	r24, 0x30	; 48
    38fe:	21 f4       	brne	.+8      	; 0x3908 <vfprintf+0x2ee>
    3900:	9a 2d       	mov	r25, r10
    3902:	99 7e       	andi	r25, 0xE9	; 233
    3904:	a9 2e       	mov	r10, r25
    3906:	09 c0       	rjmp	.+18     	; 0x391a <vfprintf+0x300>
    3908:	a2 fe       	sbrs	r10, 2
    390a:	06 c0       	rjmp	.+12     	; 0x3918 <vfprintf+0x2fe>
    390c:	b3 94       	inc	r11
    390e:	b3 94       	inc	r11
    3910:	04 c0       	rjmp	.+8      	; 0x391a <vfprintf+0x300>
    3912:	8a 2d       	mov	r24, r10
    3914:	86 78       	andi	r24, 0x86	; 134
    3916:	09 f0       	breq	.+2      	; 0x391a <vfprintf+0x300>
    3918:	b3 94       	inc	r11
    391a:	a3 fc       	sbrc	r10, 3
    391c:	11 c0       	rjmp	.+34     	; 0x3940 <vfprintf+0x326>
    391e:	a0 fe       	sbrs	r10, 0
    3920:	06 c0       	rjmp	.+12     	; 0x392e <vfprintf+0x314>
    3922:	b2 14       	cp	r11, r2
    3924:	88 f4       	brcc	.+34     	; 0x3948 <vfprintf+0x32e>
    3926:	28 0c       	add	r2, r8
    3928:	92 2c       	mov	r9, r2
    392a:	9b 18       	sub	r9, r11
    392c:	0e c0       	rjmp	.+28     	; 0x394a <vfprintf+0x330>
    392e:	b2 14       	cp	r11, r2
    3930:	60 f4       	brcc	.+24     	; 0x394a <vfprintf+0x330>
    3932:	b6 01       	movw	r22, r12
    3934:	80 e2       	ldi	r24, 0x20	; 32
    3936:	90 e0       	ldi	r25, 0x00	; 0
    3938:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    393c:	b3 94       	inc	r11
    393e:	f7 cf       	rjmp	.-18     	; 0x392e <vfprintf+0x314>
    3940:	b2 14       	cp	r11, r2
    3942:	18 f4       	brcc	.+6      	; 0x394a <vfprintf+0x330>
    3944:	2b 18       	sub	r2, r11
    3946:	02 c0       	rjmp	.+4      	; 0x394c <vfprintf+0x332>
    3948:	98 2c       	mov	r9, r8
    394a:	21 2c       	mov	r2, r1
    394c:	a4 fe       	sbrs	r10, 4
    394e:	10 c0       	rjmp	.+32     	; 0x3970 <vfprintf+0x356>
    3950:	b6 01       	movw	r22, r12
    3952:	80 e3       	ldi	r24, 0x30	; 48
    3954:	90 e0       	ldi	r25, 0x00	; 0
    3956:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    395a:	a2 fe       	sbrs	r10, 2
    395c:	17 c0       	rjmp	.+46     	; 0x398c <vfprintf+0x372>
    395e:	a1 fc       	sbrc	r10, 1
    3960:	03 c0       	rjmp	.+6      	; 0x3968 <vfprintf+0x34e>
    3962:	88 e7       	ldi	r24, 0x78	; 120
    3964:	90 e0       	ldi	r25, 0x00	; 0
    3966:	02 c0       	rjmp	.+4      	; 0x396c <vfprintf+0x352>
    3968:	88 e5       	ldi	r24, 0x58	; 88
    396a:	90 e0       	ldi	r25, 0x00	; 0
    396c:	b6 01       	movw	r22, r12
    396e:	0c c0       	rjmp	.+24     	; 0x3988 <vfprintf+0x36e>
    3970:	8a 2d       	mov	r24, r10
    3972:	86 78       	andi	r24, 0x86	; 134
    3974:	59 f0       	breq	.+22     	; 0x398c <vfprintf+0x372>
    3976:	a1 fe       	sbrs	r10, 1
    3978:	02 c0       	rjmp	.+4      	; 0x397e <vfprintf+0x364>
    397a:	8b e2       	ldi	r24, 0x2B	; 43
    397c:	01 c0       	rjmp	.+2      	; 0x3980 <vfprintf+0x366>
    397e:	80 e2       	ldi	r24, 0x20	; 32
    3980:	a7 fc       	sbrc	r10, 7
    3982:	8d e2       	ldi	r24, 0x2D	; 45
    3984:	b6 01       	movw	r22, r12
    3986:	90 e0       	ldi	r25, 0x00	; 0
    3988:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    398c:	89 14       	cp	r8, r9
    398e:	38 f4       	brcc	.+14     	; 0x399e <vfprintf+0x384>
    3990:	b6 01       	movw	r22, r12
    3992:	80 e3       	ldi	r24, 0x30	; 48
    3994:	90 e0       	ldi	r25, 0x00	; 0
    3996:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    399a:	9a 94       	dec	r9
    399c:	f7 cf       	rjmp	.-18     	; 0x398c <vfprintf+0x372>
    399e:	8a 94       	dec	r8
    39a0:	f3 01       	movw	r30, r6
    39a2:	e8 0d       	add	r30, r8
    39a4:	f1 1d       	adc	r31, r1
    39a6:	80 81       	ld	r24, Z
    39a8:	b6 01       	movw	r22, r12
    39aa:	90 e0       	ldi	r25, 0x00	; 0
    39ac:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    39b0:	81 10       	cpse	r8, r1
    39b2:	f5 cf       	rjmp	.-22     	; 0x399e <vfprintf+0x384>
    39b4:	22 20       	and	r2, r2
    39b6:	09 f4       	brne	.+2      	; 0x39ba <vfprintf+0x3a0>
    39b8:	42 ce       	rjmp	.-892    	; 0x363e <vfprintf+0x24>
    39ba:	b6 01       	movw	r22, r12
    39bc:	80 e2       	ldi	r24, 0x20	; 32
    39be:	90 e0       	ldi	r25, 0x00	; 0
    39c0:	0e 94 04 1d 	call	0x3a08	; 0x3a08 <fputc>
    39c4:	2a 94       	dec	r2
    39c6:	f6 cf       	rjmp	.-20     	; 0x39b4 <vfprintf+0x39a>
    39c8:	f6 01       	movw	r30, r12
    39ca:	86 81       	ldd	r24, Z+6	; 0x06
    39cc:	97 81       	ldd	r25, Z+7	; 0x07
    39ce:	02 c0       	rjmp	.+4      	; 0x39d4 <vfprintf+0x3ba>
    39d0:	8f ef       	ldi	r24, 0xFF	; 255
    39d2:	9f ef       	ldi	r25, 0xFF	; 255
    39d4:	2b 96       	adiw	r28, 0x0b	; 11
    39d6:	e2 e1       	ldi	r30, 0x12	; 18
    39d8:	0c 94 37 17 	jmp	0x2e6e	; 0x2e6e <__epilogue_restores__>

000039dc <strnlen_P>:
    39dc:	fc 01       	movw	r30, r24
    39de:	05 90       	lpm	r0, Z+
    39e0:	61 50       	subi	r22, 0x01	; 1
    39e2:	70 40       	sbci	r23, 0x00	; 0
    39e4:	01 10       	cpse	r0, r1
    39e6:	d8 f7       	brcc	.-10     	; 0x39de <strnlen_P+0x2>
    39e8:	80 95       	com	r24
    39ea:	90 95       	com	r25
    39ec:	8e 0f       	add	r24, r30
    39ee:	9f 1f       	adc	r25, r31
    39f0:	08 95       	ret

000039f2 <strnlen>:
    39f2:	fc 01       	movw	r30, r24
    39f4:	61 50       	subi	r22, 0x01	; 1
    39f6:	70 40       	sbci	r23, 0x00	; 0
    39f8:	01 90       	ld	r0, Z+
    39fa:	01 10       	cpse	r0, r1
    39fc:	d8 f7       	brcc	.-10     	; 0x39f4 <strnlen+0x2>
    39fe:	80 95       	com	r24
    3a00:	90 95       	com	r25
    3a02:	8e 0f       	add	r24, r30
    3a04:	9f 1f       	adc	r25, r31
    3a06:	08 95       	ret

00003a08 <fputc>:
    3a08:	0f 93       	push	r16
    3a0a:	1f 93       	push	r17
    3a0c:	cf 93       	push	r28
    3a0e:	df 93       	push	r29
    3a10:	fb 01       	movw	r30, r22
    3a12:	23 81       	ldd	r18, Z+3	; 0x03
    3a14:	21 fd       	sbrc	r18, 1
    3a16:	03 c0       	rjmp	.+6      	; 0x3a1e <fputc+0x16>
    3a18:	8f ef       	ldi	r24, 0xFF	; 255
    3a1a:	9f ef       	ldi	r25, 0xFF	; 255
    3a1c:	2c c0       	rjmp	.+88     	; 0x3a76 <fputc+0x6e>
    3a1e:	22 ff       	sbrs	r18, 2
    3a20:	16 c0       	rjmp	.+44     	; 0x3a4e <fputc+0x46>
    3a22:	46 81       	ldd	r20, Z+6	; 0x06
    3a24:	57 81       	ldd	r21, Z+7	; 0x07
    3a26:	24 81       	ldd	r18, Z+4	; 0x04
    3a28:	35 81       	ldd	r19, Z+5	; 0x05
    3a2a:	42 17       	cp	r20, r18
    3a2c:	53 07       	cpc	r21, r19
    3a2e:	44 f4       	brge	.+16     	; 0x3a40 <fputc+0x38>
    3a30:	a0 81       	ld	r26, Z
    3a32:	b1 81       	ldd	r27, Z+1	; 0x01
    3a34:	9d 01       	movw	r18, r26
    3a36:	2f 5f       	subi	r18, 0xFF	; 255
    3a38:	3f 4f       	sbci	r19, 0xFF	; 255
    3a3a:	31 83       	std	Z+1, r19	; 0x01
    3a3c:	20 83       	st	Z, r18
    3a3e:	8c 93       	st	X, r24
    3a40:	26 81       	ldd	r18, Z+6	; 0x06
    3a42:	37 81       	ldd	r19, Z+7	; 0x07
    3a44:	2f 5f       	subi	r18, 0xFF	; 255
    3a46:	3f 4f       	sbci	r19, 0xFF	; 255
    3a48:	37 83       	std	Z+7, r19	; 0x07
    3a4a:	26 83       	std	Z+6, r18	; 0x06
    3a4c:	14 c0       	rjmp	.+40     	; 0x3a76 <fputc+0x6e>
    3a4e:	8b 01       	movw	r16, r22
    3a50:	ec 01       	movw	r28, r24
    3a52:	fb 01       	movw	r30, r22
    3a54:	00 84       	ldd	r0, Z+8	; 0x08
    3a56:	f1 85       	ldd	r31, Z+9	; 0x09
    3a58:	e0 2d       	mov	r30, r0
    3a5a:	09 95       	icall
    3a5c:	89 2b       	or	r24, r25
    3a5e:	e1 f6       	brne	.-72     	; 0x3a18 <fputc+0x10>
    3a60:	d8 01       	movw	r26, r16
    3a62:	16 96       	adiw	r26, 0x06	; 6
    3a64:	8d 91       	ld	r24, X+
    3a66:	9c 91       	ld	r25, X
    3a68:	17 97       	sbiw	r26, 0x07	; 7
    3a6a:	01 96       	adiw	r24, 0x01	; 1
    3a6c:	17 96       	adiw	r26, 0x07	; 7
    3a6e:	9c 93       	st	X, r25
    3a70:	8e 93       	st	-X, r24
    3a72:	16 97       	sbiw	r26, 0x06	; 6
    3a74:	ce 01       	movw	r24, r28
    3a76:	df 91       	pop	r29
    3a78:	cf 91       	pop	r28
    3a7a:	1f 91       	pop	r17
    3a7c:	0f 91       	pop	r16
    3a7e:	08 95       	ret

00003a80 <__ultoa_invert>:
    3a80:	fa 01       	movw	r30, r20
    3a82:	aa 27       	eor	r26, r26
    3a84:	28 30       	cpi	r18, 0x08	; 8
    3a86:	51 f1       	breq	.+84     	; 0x3adc <__ultoa_invert+0x5c>
    3a88:	20 31       	cpi	r18, 0x10	; 16
    3a8a:	81 f1       	breq	.+96     	; 0x3aec <__ultoa_invert+0x6c>
    3a8c:	e8 94       	clt
    3a8e:	6f 93       	push	r22
    3a90:	6e 7f       	andi	r22, 0xFE	; 254
    3a92:	6e 5f       	subi	r22, 0xFE	; 254
    3a94:	7f 4f       	sbci	r23, 0xFF	; 255
    3a96:	8f 4f       	sbci	r24, 0xFF	; 255
    3a98:	9f 4f       	sbci	r25, 0xFF	; 255
    3a9a:	af 4f       	sbci	r26, 0xFF	; 255
    3a9c:	b1 e0       	ldi	r27, 0x01	; 1
    3a9e:	3e d0       	rcall	.+124    	; 0x3b1c <__ultoa_invert+0x9c>
    3aa0:	b4 e0       	ldi	r27, 0x04	; 4
    3aa2:	3c d0       	rcall	.+120    	; 0x3b1c <__ultoa_invert+0x9c>
    3aa4:	67 0f       	add	r22, r23
    3aa6:	78 1f       	adc	r23, r24
    3aa8:	89 1f       	adc	r24, r25
    3aaa:	9a 1f       	adc	r25, r26
    3aac:	a1 1d       	adc	r26, r1
    3aae:	68 0f       	add	r22, r24
    3ab0:	79 1f       	adc	r23, r25
    3ab2:	8a 1f       	adc	r24, r26
    3ab4:	91 1d       	adc	r25, r1
    3ab6:	a1 1d       	adc	r26, r1
    3ab8:	6a 0f       	add	r22, r26
    3aba:	71 1d       	adc	r23, r1
    3abc:	81 1d       	adc	r24, r1
    3abe:	91 1d       	adc	r25, r1
    3ac0:	a1 1d       	adc	r26, r1
    3ac2:	20 d0       	rcall	.+64     	; 0x3b04 <__ultoa_invert+0x84>
    3ac4:	09 f4       	brne	.+2      	; 0x3ac8 <__ultoa_invert+0x48>
    3ac6:	68 94       	set
    3ac8:	3f 91       	pop	r19
    3aca:	2a e0       	ldi	r18, 0x0A	; 10
    3acc:	26 9f       	mul	r18, r22
    3ace:	11 24       	eor	r1, r1
    3ad0:	30 19       	sub	r19, r0
    3ad2:	30 5d       	subi	r19, 0xD0	; 208
    3ad4:	31 93       	st	Z+, r19
    3ad6:	de f6       	brtc	.-74     	; 0x3a8e <__ultoa_invert+0xe>
    3ad8:	cf 01       	movw	r24, r30
    3ada:	08 95       	ret
    3adc:	46 2f       	mov	r20, r22
    3ade:	47 70       	andi	r20, 0x07	; 7
    3ae0:	40 5d       	subi	r20, 0xD0	; 208
    3ae2:	41 93       	st	Z+, r20
    3ae4:	b3 e0       	ldi	r27, 0x03	; 3
    3ae6:	0f d0       	rcall	.+30     	; 0x3b06 <__ultoa_invert+0x86>
    3ae8:	c9 f7       	brne	.-14     	; 0x3adc <__ultoa_invert+0x5c>
    3aea:	f6 cf       	rjmp	.-20     	; 0x3ad8 <__ultoa_invert+0x58>
    3aec:	46 2f       	mov	r20, r22
    3aee:	4f 70       	andi	r20, 0x0F	; 15
    3af0:	40 5d       	subi	r20, 0xD0	; 208
    3af2:	4a 33       	cpi	r20, 0x3A	; 58
    3af4:	18 f0       	brcs	.+6      	; 0x3afc <__ultoa_invert+0x7c>
    3af6:	49 5d       	subi	r20, 0xD9	; 217
    3af8:	31 fd       	sbrc	r19, 1
    3afa:	40 52       	subi	r20, 0x20	; 32
    3afc:	41 93       	st	Z+, r20
    3afe:	02 d0       	rcall	.+4      	; 0x3b04 <__ultoa_invert+0x84>
    3b00:	a9 f7       	brne	.-22     	; 0x3aec <__ultoa_invert+0x6c>
    3b02:	ea cf       	rjmp	.-44     	; 0x3ad8 <__ultoa_invert+0x58>
    3b04:	b4 e0       	ldi	r27, 0x04	; 4
    3b06:	a6 95       	lsr	r26
    3b08:	97 95       	ror	r25
    3b0a:	87 95       	ror	r24
    3b0c:	77 95       	ror	r23
    3b0e:	67 95       	ror	r22
    3b10:	ba 95       	dec	r27
    3b12:	c9 f7       	brne	.-14     	; 0x3b06 <__ultoa_invert+0x86>
    3b14:	00 97       	sbiw	r24, 0x00	; 0
    3b16:	61 05       	cpc	r22, r1
    3b18:	71 05       	cpc	r23, r1
    3b1a:	08 95       	ret
    3b1c:	9b 01       	movw	r18, r22
    3b1e:	ac 01       	movw	r20, r24
    3b20:	0a 2e       	mov	r0, r26
    3b22:	06 94       	lsr	r0
    3b24:	57 95       	ror	r21
    3b26:	47 95       	ror	r20
    3b28:	37 95       	ror	r19
    3b2a:	27 95       	ror	r18
    3b2c:	ba 95       	dec	r27
    3b2e:	c9 f7       	brne	.-14     	; 0x3b22 <__ultoa_invert+0xa2>
    3b30:	62 0f       	add	r22, r18
    3b32:	73 1f       	adc	r23, r19
    3b34:	84 1f       	adc	r24, r20
    3b36:	95 1f       	adc	r25, r21
    3b38:	a0 1d       	adc	r26, r0
    3b3a:	08 95       	ret

00003b3c <__do_global_dtors>:
    3b3c:	10 e0       	ldi	r17, 0x00	; 0
    3b3e:	cd ee       	ldi	r28, 0xED	; 237
    3b40:	d0 e0       	ldi	r29, 0x00	; 0
    3b42:	04 c0       	rjmp	.+8      	; 0x3b4c <__do_global_dtors+0x10>
    3b44:	fe 01       	movw	r30, r28
    3b46:	0e 94 a8 17 	call	0x2f50	; 0x2f50 <__tablejump2__>
    3b4a:	21 96       	adiw	r28, 0x01	; 1
    3b4c:	ce 3e       	cpi	r28, 0xEE	; 238
    3b4e:	d1 07       	cpc	r29, r17
    3b50:	c9 f7       	brne	.-14     	; 0x3b44 <__do_global_dtors+0x8>
    3b52:	f8 94       	cli

00003b54 <__stop_program>:
    3b54:	ff cf       	rjmp	.-2      	; 0x3b54 <__stop_program>
