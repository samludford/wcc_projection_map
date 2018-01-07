#pragma once

#include "ofMain.h"
#include "FboSource.h"

class ParticlesSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        float time;
    
        float vel_max {1.0};
        float c_min {0};
        float c_max {255};
    
        int part_count {100};
        float part_size {10.0};
        vector<ofPoint> positions;
        vector<ofPoint> vels;
        vector<ofPoint> accs;
    
        void draw_particle_squiggle_1();
        void draw_particle_squiggle_2();
        void draw_particle_squiggle_3();
        void draw_particle_lines_1();
        void draw_particle_lines_2();
        void draw_particle_lines_3();
        void draw_particle_balls();
        void draw_particle_mesh();
        void draw_corner_flares();
        void draw_corner_web();
        void trigger_edge_run();
    
        void draw_grid_web();
        void draw_grid_flares();
        void draw_grid_flares_pulse();
    
        bool bounce {true};
    
    
};
