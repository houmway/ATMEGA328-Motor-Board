/**
 * ATMEGA328-Motor-Board Firmware
 * Copyright (C) 2016 AntonioMR [https://github.com/AntonioMR/ATMEGA328-Motor-Board]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <Arduino.h>
#include "configuration.h"
#include "pca9685.h"

#if defined(Encoder1) || defined(Encoder2)
  #include "encoder.h"
#endif

Pca9685 Pwm_Driver = Pca9685();

void setup(void){

  #ifdef Encoder1
    pinMode(4, INPUT);
    attachInterrupt(0, Encoder1_ISR, RISING);
  #endif

  #ifdef Encoder2
    pinMode(5, INPUT);
    attachInterrupt(1, Encoder2_ISR, RISING);
  #endif
}

void loop(void){
  Pwm_Driver.Send(MOTOR1_A,0x10);
  delay(1000);
}
