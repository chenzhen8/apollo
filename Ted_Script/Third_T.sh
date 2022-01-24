#!/bin/sh
cd /home/$USER
mkdir T
cd T
git clone https://github.com/ApolloAuto/apollo.git
#unzip apollo-master.zip -d /home/$USER/T
cd /home/$USER/T/apollo/
bash docker/scripts/dev_start.sh
bash docker/scripts/dev_into.sh


