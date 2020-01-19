//
// Created by Sam on 17/01/2020.
//

#ifndef MUSICFLOW_STRUCTURES_H
#define MUSICFLOW_STRUCTURES_H

#include "SymbolicMusic.h"

#include <string>
#include <vector>
#include "Eigen/Dense"

namespace ScreenSystem {
    class ParticleEvent : public SymbolicMusic::NoteEvent{
    public:
        ParticleEvent(int freq, int delta, float purity, float intensity);

        float getIntensity() const;
        void setIntensity(float intensity);

        float getPurity() const;
        void setPurity(float purity);
    protected:
        float purity;
        float intensity;
    };

    class Screen{

    public:
        const float getDensity(int x, int y, int z);
        void updateVectorField();
    private:
        std::vector<float> densityField;
        std::vector<Eigen::Vector3f> vectorField;
    };

    class Moment{
    public:
        Moment(Screen *screen);

        std::vector<ParticleEvent> &generateEventList();

        int getNumInstants() const;

        void configureVectorField();
    private:
        Screen *screen;
        int numInstants;

        std::vector<ParticleEvent> eventList;
    };

    class Section {
    public:
        Section();

        std::vector<ParticleEvent> generateEventList(int _startDelta);

        int getSectionDelta();

    private:
        std::vector<Moment> moments;
    };

    class Piece {
    public:
        Piece();
        void configureSections();
        std::string generateCSV();
    private:
        std::vector<Section> sections;
        Screen screen;
    };
}


#endif //MUSICFLOW_STRUCTURES_H
