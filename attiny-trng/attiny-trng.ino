/*
 * attiny-trng.ino
 * This file is part of attiny-trng.
 *
 * Copyright (c) 2017 Martijn
 *
 * attiny-trng is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * attiny-trng is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with attiny-trng.  If not, see <http://www.gnu.org/licenses/>.*
 */

#include <SoftwareSerial.h>
#include <EEPROM.h>

#define rx_pin 0
#define tx_pin 1
#define ai0 A3 // analog input
#define ai1 A2

SoftwareSerial serial(rx_pin, tx_pin);

void setup() {
    pinMode(rx_pin, INPUT);
    pinMode(tx_pin, OUTPUT);
    serial.begin(9600);
    serial.println("Starting attiny-trng");

    pinMode(ai0, INPUT);
    pinMode(ai1, INPUT);
}

void loop() {
    unsigned long v = 0;
    for (int i = 0; i < 2; i++) {
        serial.println("read");
        int raw0 = analogRead(ai0);
        int raw1 = analogRead(ai1);
        int x = 0;
        x = raw0 ^ raw1; // bitwise xor

        /* The 10-bit ADC gives us only 10 random bits per read, move
        * these to be the most significant
        */
        x = x << 10;
        serial.println(x, BIN);
        v = (v + x) << 10;
        serial.println(v, BIN);
        delay(250);
    }
    serial.println(v, BIN);
    serial.println(v, DEC);
    serial.println("New round");
    v = 0;
}
