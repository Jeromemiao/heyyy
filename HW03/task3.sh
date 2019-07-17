#!/usr/bin/env bash
#SBATCH --job-name=Task3
srun -p slurm_shortgpu --pty -u gdb task3
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --time=0-00:00:10
#SBATCH --output=task3_res.txt

cd $SLURM_SUBMIT_DIR

./task3

