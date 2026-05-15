import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import os
import glob

base_dir = os.path.dirname(os.path.abspath(__file__))
db_dir = os.path.join(base_dir, "..", "build", "db")
results_dir = os.path.join(base_dir, "..", "docs", "results")
os.makedirs(results_dir, exist_ok=True)

csv_files = glob.glob(os.path.join(db_dir, "*.csv"))
csv_files = [f for f in csv_files if f.endswith("experiment.csv")]

if not csv_files:
    print("No experiment CSV files found.")
    exit(0)

# Colors and configuration omitted for brevity, let's keep the existing logic but wrap in a function.
