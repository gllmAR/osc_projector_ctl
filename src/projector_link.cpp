//
//  projector_link.cpp
//  pjlink_ctl
//
//  Created by Guillaume Arseneault on 18-04-18.
//
//

#include "projector_link.hpp"

void Projector_link::setup(int pj_id)
{
    projector_id = "projector_";
    projector_id += ofToString(pj_id);
    gui.setup(projector_id);
    gui.add(name.set("name","click_to_set_me"));
    gui.add(projector_ip.set("ip", "192.168.0.254"));
    gui.add(power.set("power",1));
    gui.add(shutter.set("shutter",0));
    
    projector.setup();
    projector.setProjectorIP(projector_ip);
    
    power.addListener(this, &Projector_link::power_changed);
    shutter.addListener(this, &Projector_link::shutter_changed);

}

void Projector_link::shutter_changed(bool &b)
{
    if(shutter)
    {
        projector.mute_on();
    }else{
        projector.mute_off();
    }
}


void Projector_link::power_changed(bool &b)
{
 
    if(power)
    {
        projector.On();
    }else{
        projector.Off();
    }
}




void Projector_link::parse_osc(ofxOscMessage m)
{
    if(m.getAddress() == "/projector/get_status")
    {
        //not implemented yet....
    }
    else if (m.getAddress() == "/projector/get_status")
    {
            
    }
    
}


