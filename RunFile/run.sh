#!/bin/sh
selfpath=$(cd "$(dirname "$0")"; pwd)
echo $selfpath
export HOME=$selfpath
echo $HOME
#export PATH=$LD_LIBRARY_PATH
#echo $LD_LIBRARY_PATH
#echo $PATH
export LD_LIBRARY_PATH=$HOME:$LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
./MongoDBTest

