//
//  projector_link.hpp
//  pjlink_ctl
//
//  Created by Guillaume Arseneault on 18-04-18.
//
//

#ifndef projector_link_hpp
#define projector_link_hpp

#include "ofMain.h"
#include "ofxPJControl.h"
#include "ofxOsc.h"
#include "ofxGui.h"

class Projector_link
{
public:
    ofParameter <std::string> projector_ip;
    
    ofxGuiGroup gui;
    
    void setup(int pj_id);
    void parse_osc(ofxOscMessage m);
    ofxPJControl projector;
    
    ofParameter <std::string> name;
    ofParameter <int> mode;
    ofParameter <bool> power;
    ofParameter <bool> shutter;
    
    void shutter_changed(bool &b);
    void power_changed(bool &b);
    
    std::string projector_id;
    
    
    
    
    
};


#endif /* projector_link_hpp */
