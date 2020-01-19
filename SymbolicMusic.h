//
// Created by Sam on 18/01/2020.
//

#ifndef MUSICFLOW_SYMBOLICMUSIC_H
#define MUSICFLOW_SYMBOLICMUSIC_H


#include <string>

namespace SymbolicMusic {
    class NoteEvent{
    public:
        NoteEvent(int delta, int freq);

        int getFreq() const;

        void setFreq(int freq);

        int getDelta() const;

        void setDelta(int delta);

        std::string getNoteName(int *midiCentDiff);

    protected:
        int freq;
        int delta;
    };

    const char Notes[12][3] = { "C", "C#", "D", "Eb", "E", "F", "F#", "G", "Ab", "A", "Bb", "B" };
}



#endif //MUSICFLOW_SYMBOLICMUSIC_H
