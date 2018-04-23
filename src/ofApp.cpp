#include "ofApp.h"
#include "projector_link.hpp"
#include "ofxOsc.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    settings_panel.setup("settings", "settings.json", 5, 5 );
    settings_panel.add(osc_input.set("osc_input",8502,8000,9000));
    settings_panel.add(osc_output_ip.set("osc_output_ip","localhost"));
    settings_panel.add(osc_output.set("osc_output",8501,8000,9000));
    settings_panel.add(config_name.set("cfg_name", "projectors"));
    settings_panel.add(projector_count.set("projector_count",1,1,1));
    
    ofSetWindowTitle("OSC Projo Ctl");
    settings_panel.loadFromFile("settings.json");
    
    
    load_projector_config();
    ofSetFrameRate(60);
    ofSetBackgroundColor(ofColor::lightGrey);
}

//--------------------------------------------------------------
void ofApp::update()
{
    sync.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    settings_panel.draw();
    pj_panel.draw();
}
//--------------------------------------------------------------

void ofApp::load_projector_config()
{
    
    std::string config_json = config_name;
    config_json+=".json";
    
    pj_panel.setup(config_name,config_json, 5, 130);
    
    projector_link.setup(1);
    
    pj_panel.add(&projector_link.gui);
    
    pj_panel.loadFromFile(config_json);
    
    sync.setup((ofParameterGroup&)pj_panel.getParameter(), osc_input, osc_output_ip, osc_output);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
