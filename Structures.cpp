//
// Created by Sam on 17/01/2020.
//

#include "Structures.h"
using namespace ScreenSystem;


Piece::Piece() : screen() {}

std::string Piece::generateCSV() {
    std::vector<ParticleEvent> notes;
    std::vector<ParticleEvent> notesTemp;
    int currentD = 0;

    for(auto item : sections){
        notesTemp = item.generateEventList(currentD);
        currentD += item.getSectionDelta();
        notes.reserve(notes.size()+notesTemp.size());
        notes.insert(notes.end(),notesTemp.begin(), notesTemp.end());
        notesTemp.clear();
    }

    std::stringstream CsvStream;
    CsvStream << "delta,freq,noteName,CentsToET,Intensity,Purity" << std::endl;
    int centDiff;
    for(auto pE : notes){
        CsvStream << pE.getDelta() << "," << pE.getFreq() << "," << pE.getNoteName(&centDiff) << "," << centDiff << "," << pE.getIntensity() << "," << pE.getPurity() << std::endl;
    }

    return CsvStream.str();
}

void Piece::configureSections() {
    sections.push_back(Section());
}

const float Screen::getDensity(int x, int y, int z) {
    return 0; //TODO: Implement
}

void Screen::updateVectorField() {

}

Moment::Moment(Screen *screen) : screen(screen) {}

std::vector<ParticleEvent> &Moment::generateEventList() {
    for(int i = 0; i<numInstants; i++){
        //updateVectorField
        //calculateEvents(PASS IN current Delta)
        //add events to list
    }
    return eventList;
}

void Moment::configureVectorField() {

}

int Moment::getNumInstants() const {
    return numInstants;
}

float ParticleEvent::getIntensity() const {
    return intensity;
}

void ParticleEvent::setIntensity(float intensity) {
    ParticleEvent::intensity = intensity;
}

float ParticleEvent::getPurity() const {
    return purity;
}

void ParticleEvent::setPurity(float purity) {
    ParticleEvent::purity = purity;
}

ParticleEvent::ParticleEvent(int delta, int freq, float purity, float intensity) : NoteEvent(delta, freq),
                                                                                   purity(purity),
                                                                                   intensity(intensity) {}

int Section::getSectionDelta() {
    int ret = 0;
    for(auto mom : moments){
        ret += mom.getNumInstants();
    }
    return ret;
}

std::vector<ParticleEvent> Section::generateEventList(int startDelta) {
    auto ret = std::vector<ParticleEvent>();

    ret.push_back(ParticleEvent(startDelta, 440, 0.5f, 0.8f));

    return ret;
}

Section::Section() {}
