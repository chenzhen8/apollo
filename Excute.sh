#!/bin/sh
sudo apt-get update
sudo apt-get upgrade
curl https://get.docker.com | sh
sudo systemctl start docker && sudo systemctl enable docker
#sudo groupadd docker
sudo usermod -aG docker $USER
#newgrp docker
docker run hello-world
docker –v
cd /home/$USER
mkdir T
cd T
git clone https://github.com/ApolloAuto/apollo.git
#unzip apollo-master.zip -d /home/$USER/T
cd /home/$USER/T/apollo/
echo "export APOLLO_ROOT_DIR=$(pwd)" >> ~/.bashrc && source ~/.bashrc
bash docker/scripts/dev_start.sh
bash docker/scripts/dev_into.sh
#sh /home/$USER/Desktop/Ted_Script/First_T.sh
#sh /home/$USER/Desktop/Ted_Script/Second_T.sh
#sh /home/$USER/Desktop/Ted_Script/Third_T.sh


