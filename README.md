attiny-trng
===========

ATTiny85 proof of concept implementation of a True Random Number Generator (TRNG).

**WARNING: THIS PROJECT IS NOT TO BE USED FOR ACTUAL CRYPTOGRAPHICAL PURPOSES.**

How it should work and why it doesn't
-------------------------------------

Using two unconnected analog input pins, these floating pins can be used as a
source of random data. However, this raw data can't be immediately used. The data
has to be mixed (RFC 4086 section 5). I wanted to collect an array of read values
and compute a hash from this data. But the MD5 hash library I found is not
compatible with the ATTiny85. At which point I stopped working on this project.

Solutions
---------

Because of its processing limitations, it's not possible (at least, for me) to implement
a complete TRNG on an ATTiny85. Instead, the processing of the raw data from the ATTiny85's
ADC will have to happen on a host computer using a driver which reads the raw data from
the ATTiny85 via a serial interface.

Other notes
-----------

- Once there there is a (somewhat) working proof of concept, `ent` can be used to measure
    how random the output actually is.

Resources
---------

```
RFC 4086 Randomness Requirements for Security
https://tools.ietf.org/html/rfc4086

NeuG, a True Random Number Generator Implementation
https://www.gniibe.org/memo/development/gnuk/rng/neug.html

ArduinoMD5, an implementation of the MD5 hash for Arduino
https://github.com/tzikis/ArduinoMD5/

ENT: A Pseudorandom Number Sequence Test Program
https://www.fourmilab.ch/random/
```

License
-------

```
Copyright (c) 2017 Martijn

attiny-trng is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

attiny-trng is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with attiny-trng.  If not, see <http://www.gnu.org/licenses/>.
```
