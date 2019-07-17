#!/usr/bin/env bash
#SBATCH --job-name=Problem1
#SBATCH -p shortgpu
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output=problem1_res.txt

cd $SLURM_SUBMIT_DIR

./problem1 1048576