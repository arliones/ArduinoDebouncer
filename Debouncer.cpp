/*
 * Debouncer.cpp - Library for debouncing signals/pins.
 * Created by Arliones Hoeller Jr., November 23rd, 2021.
 * Released under the MIT License.
 */
#include "Arduino.h"
#include "Debouncer.h"

Debouncer::Debouncer(unsigned long dt)
  : _dt(dt), _last(0)
{}

bool Debouncer::debounce()
{
    unsigned long now = millis();
    unsigned long dt = now - _last;
    _last = now;
    if(dt >= _dt)
        return true;
    return false;
}
