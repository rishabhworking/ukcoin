 #!/usr/bin/env bash

 # Execute this file to install the ukcoin cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Ukcoin-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Ukcoin-Qt.app/Contents/MacOS/ukcoind /usr/local/bin/ukcoind
 sudo ln -s ${LOCATION}/Ukcoin-Qt.app/Contents/MacOS/ukcoin-cli /usr/local/bin/ukcoin-cli
