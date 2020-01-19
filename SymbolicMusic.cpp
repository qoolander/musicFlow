//
// Created by Sam on 18/01/2020.
//

#include <math.h>
#include "SymbolicMusic.h"
#include <string>
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace SymbolicMusic;

int NoteEvent::getFreq() const {
    return freq;
}

void NoteEvent::setFreq(int freq) {
    NoteEvent::freq = freq;
}

int NoteEvent::getDelta() const {
    return delta;
}

void NoteEvent::setDelta(int delta) {
    NoteEvent::delta = delta;
}

std::string NoteEvent::getNoteName(int *midiCentDiff) {
    int a = 440; //frequency of A (common value is 440Hz)
    float midic = (12 * std::log2(freq / a)) + 69; //A4 is midi 69
    *midiCentDiff = roundf((-roundf(midic)+midic)*100);
    int midi = truncf(midic);
    int octave = (midi / 12) - 1;
    return std::string(Notes[midi%12]) + SSTR(octave);
}

NoteEvent::NoteEvent(int delta, int freq) : freq(freq), delta(delta) {}
