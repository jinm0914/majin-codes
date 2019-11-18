#!/usr/bin/env python
# Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
# Copyright (C) 2009-2019 German Aerospace Center (DLR) and others.
# This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v2.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v20.html
# SPDX-License-Identifier: EPL-2.0

# @file    runner.py
# @author  Lena Kalleske
# @author  Daniel Krajzewicz
# @author  Michael Behrisch
# @author  Jakob Erdmann
# @date    2009-03-26
# @version $Id$

from __future__ import absolute_import
from __future__ import print_function

import os
import sys
import optparse
import random


import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation

import threading
from queue import LifoQueue
import time
# we need to import python modules from the $SUMO_HOME/tools directory
if 'SUMO_HOME' in os.environ:
    tools = os.path.join(os.environ['SUMO_HOME'], 'tools')
    sys.path.append(tools)
else:
    sys.exit("please declare environment variable 'SUMO_HOME'")

from sumolib import checkBinary  # noqa
import traci  # noqa
import traci.constants as tc

def generate_routefile():
    random.seed(42)  # make tests reproducible
    N = 3600  # number of time steps
    # demand per second from different directions
    pWE = 1. / 10
    pEW = 1. / 11
    pNS = 1. / 30
    with open("data/cross.rou.xml", "w") as routes:
        print("""<routes>
        <vType id="typeWE" accel="0.8" decel="4.5" sigma="0.5" length="5" minGap="2.5" maxSpeed="16.67" \
guiShape="passenger"/>
        <vType id="typeNS" accel="0.8" decel="4.5" sigma="0.5" length="7" minGap="3" maxSpeed="25" guiShape="bus"/>

        <route id="right" edges="51o 1i 2o 52i" />
        <route id="left" edges="52o 2i 1o 51i" />
        <route id="down" edges="54o 4i 3o 53i" />""", file=routes)
        vehNr = 0
        for i in range(N):
            if random.uniform(0, 1) < pWE:
                print('    <vehicle id="right_%i" type="typeWE" route="right" depart="%i" />' % (
                    vehNr, i), file=routes)
                vehNr += 1
            if random.uniform(0, 1) < pEW:
                print('    <vehicle id="left_%i" type="typeWE" route="left" depart="%i" />' % (
                    vehNr, i), file=routes)
                vehNr += 1
            if random.uniform(0, 1) < pNS:
                print('    <vehicle id="down_%i" type="typeNS" route="down" depart="%i" color="1,0,0"/>' % (
                    vehNr, i), file=routes)
                vehNr += 1
        print("</routes>", file=routes)

# The program looks like this
#    <tlLogic id="0" type="static" programID="0" offset="0">
# the locations of the tls are      NESW
#        <phase duration="31" state="GrGr"/>
#        <phase duration="6"  state="yryr"/>
#        <phase duration="31" state="rGrG"/>
#        <phase duration="6"  state="ryry"/>
#    </tlLogic>


def thread_job(q):
    print('This is a thread of %s' % threading.current_thread())
    plt.ion() #开启interactive mode 成功的关键函数   
    fig, ax = plt.subplots()                 
    while True:
        if q.empty() :
            continue
        s_t = time.time()
        n_t = q.get(False)
        print(2,s_t)
        print("majin  thread_job ",s_t-n_t[0],s_t,n_t[0]) 
        
        #plt.xlim(n_t[1][0]-10,n_t[1][0]+10)
        #plt.ylim(n_t[1][1]-5, n_t[1][1]+5)
       

        plt.plot(n_t[1][0],n_t[1][1],'+')
        plt.pause(0.001)
        #plt.imshow(x)
        # save the animation as an mp4.  This requires ffmpeg or mencoder to be
        # installed.  The extra_args ensure that the x264 codec is used, so that
        # the video can be embedded in html5.  You may need to adjust this for
        # your system: for more information, see
        # http://matplotlib.sourceforge.net/api/animation_api.html
        # anim.save('basic_animation.mp4', fps=30, extra_args=['-vcodec', 'libx264'])
      
    #fig.savefig('scatter.eps',dpi=600,format='eps')
              
def run():
    """execute the TraCI control loop"""
    step = 0
    q = LifoQueue(3)
    t = threading.Thread(target=thread_job, args=(q,), name= "sss" )
    t.start()
      
    # we start with phase 2 where EW has green
    traci.vehicle.subscribe("veh0", (tc.VAR_ROAD_ID, tc.VAR_POSITION)) 
    print(traci.vehicle.getSubscriptionResults("veh0"))
    while traci.simulation.getMinExpectedNumber() > 0:
        traci.simulationStep()
        subs=traci.vehicle.getSubscriptionResults("veh0")
        #plt.clf()
        pos=subs.get(tc.VAR_POSITION, None)
        print(q.qsize())
        s_t = time.time()
        if q.full():
            q.queue.clear() 
        q.put_nowait([s_t,pos])  
        #print(1,s_t)
        #print("majin  run ",subs.get(tc.VAR_POSITION, None))   
        #x.append(subs.get(tc.VAR_POSITION, None)[0])#模拟数据增量流入，保存历史数据
        #y.append(subs.get(tc.VAR_POSITION, None)[1])#模拟数据增量流入，保存历史数据
        step += 1
    traci.close()
    sys.stdout.flush()


def get_options():
    optParser = optparse.OptionParser()
    optParser.add_option("--nogui", action="store_true",
                         default=False, help="run the commandline version of sumo")
    options, args = optParser.parse_args()
    return options


# this is the main entry point of this script
if __name__ == "__main__":
    options = get_options()

    # this script has been called from the command line. It will start sumo as a
    # server, then connect and run
    if options.nogui:
        sumoBinary = checkBinary('sumo')
    else:
        sumoBinary = checkBinary('sumo-gui')

    # first, generate the route file for this simulation
    ##generate_routefile()
    

    
    # this is the normal way of using traci. sumo is started as a
    # subprocess and then the python script connects and runs
    traci.start([sumoBinary, "-c", "data/cross.sumocfg",
                             "--tripinfo-output", "tripinfo.xml"])
    run()
