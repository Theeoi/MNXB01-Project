#!/bin/bash

#######################
# Take me to the moon #
#######################
# Execute this script to get everything

cd "$(dirname "$0")" # setting cwd as the dirrectory where the scrip is running.

chmod +x $(pwd)/datasets/moon\ data\ prep/master_script.sh
$(pwd)/datasets/moon\ data\ prep/master_script.sh # Executing the master datahandling script

Rscript $(pwd)/code/Take_me_to_the_moon/moon_fit.r # Executing the Rscript for producing plots and getting output