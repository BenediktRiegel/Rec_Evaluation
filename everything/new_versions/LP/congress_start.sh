#!/bin/bash

#SBATCH -J Congress_LP
#SBATCH -c 16
#SBATCH -n 1
#SBATCH -t 2-00:00:00
#SBATCH --mem=16GB
#SBATCH --mail-type=ALL
#SBATCH --mail-user=Benedikt.Riegel@stud-mail.uni-wuerzburg.de

#export OMP_NUM_THREADS=${SLURM_CPUS_PER_TASK}

DATA_PATH=/home/fkt41jv/Benedikt/Twitter/Data/Congress/

srun LP_Algo $DATA_PATH
