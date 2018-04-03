/*
 * attiny-trng.ino
 * This file is part of attiny-trng.
 *
 * Copyright (c) 2017, 2018 Martijn
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

/*
 * Unconnected (floating) analog input pins
 */
#define ai0 A3
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
    int raw0, raw1;
    byte b0, b1, x;

    raw0 = analogRead(ai0);
    raw1 = analogRead(ai1);

    // Ignore the 0 padding and the first two bits of the analog reading
    b0 = lowByte(raw0);
    b1 = lowByte(raw1);

    // bitwise xor
    x = b0 ^ b1;

    serial.print("raw0\t");
    serial.println(raw0, BIN);
    serial.print("b0\t");
    serial.println(b0, BIN);
    serial.print("raw1\t");
    serial.println(raw1, BIN);
    serial.print("b1\t");
    serial.println(b1, BIN);
}
