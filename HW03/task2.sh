#!/usr/bin/env bash
#SBATCH --job-name=Task2
#SBATCH -p shortgpu
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output=task2_res.txt

cd $SLURM_SUBMIT_DIR

./task2
