#pragma once

#include "ofMain.h"
#include "projector_link.hpp"
#include "ofxGui.h"
#include "ofxOscParameterSync.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    Projector_link projector_link;
    
    ofxPanel settings_panel;
    ofxPanel pj_panel;
	
    ofParameter <int> osc_input;
    ofParameter <int> osc_output;
    ofParameter <std::string> osc_output_ip;
    ofParameter <std::string> config_name;
    ofParameter <int> projector_count;
    
    ofxOscParameterSync sync;
    
    void load_projector_config();
    
};
