## Node UDP Listener Script

This script starts an node server with open
UDP port. If an messages is incoming the state
of the Arduino will changed.

# Installation

First you need the 
(Jenkins Notification Plugin)[https://wiki.jenkins-ci.org/display/JENKINS/Notification+Plugin]
on your project with the hostname and udp port.

This plugin sends jsons messages on every build queue change.

The script uses the node-serial lib. but there is an issue
on the raspberry. So this is the installation guide, if you
do not compile node on your own.

    apt-get install nodejs
    apt-get install npm

    ln -s /usr/bin/nodejs /usr/local/bin/nodejs 
    ln -s /usr/bin/nodejs /usr/local/bin/node

    npm install serialport@1.0.6 # needed if you have node v0.6.19 or earlier
    npm install -g node-gyp

    cd node_modules/serialport/
    node-gyp configure
    node-gyp build


