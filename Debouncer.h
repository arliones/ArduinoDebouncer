/*
 * Debouncer.h - Library for debouncing signals/pins.
 * Created by Arliones Hoeller Jr., November 23rd, 2021.
 * Released under the MIT License.
 */
#ifndef DEBOUNCER_H__
#define DEBOUNCER_H__

#include "Arduino.h"

class Debouncer
{
    public:
        Debouncer(unsigned long dt);
        bool debounce();

    private:
        unsigned long _dt, _last;
};

#endif //DEBOUNCER_H__
