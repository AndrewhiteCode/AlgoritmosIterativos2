import pandas as pd
import matplotlib.pyplot as plt
import os
import glob
import sys

base_dir = os.path.dirname(os.path.abspath(__file__))
db_dir = os.path.join(base_dir, "..", "build", "db")
results_dir = os.path.join(base_dir, "..", "docs", "results")
os.makedirs(results_dir, exist_ok=True)

csv_files = glob.glob(os.path.join(db_dir, "*_experiment.csv"))

if not csv_files:
    print("No experiment CSV files found.")
    sys.exit(0)

# Dictionary mapping column names to colors
color_map = {
    'Swap Sort': 'tab:blue',
    'Insertion Sort': 'tab:orange',
    'Selection Sort': 'tab:green',
    'Cocktail Shaker Sort': 'tab:red',
    'Merge Sort Classic': 'tab:purple',
    'Merge Sort Opt(16)': 'tab:brown',
    'Merge Sort Opt(50)': 'tab:pink',
    'Quick Sort (Last)': 'tab:gray',
    'Quick Sort (Random)': 'tab:olive',
    'Quick Sort (Median)': 'tab:cyan'
}

for filepath in csv_files:
    base_name = os.path.basename(filepath)
    name_no_ext = os.path.splitext(base_name)[0]
    try:
        df = pd.read_csv(filepath)
    except FileNotFoundError:
        print(f"Error: {filepath} no existe.")
        continue

    plt.figure(figsize=(10, 7))

    for col in df.columns[1:]:
        c = color_map.get(col, None)
        plt.plot(df['N'], df[col], marker='o', label=col, color=c)

    plt.title(f"Comparacion de Algoritmos - {name_no_ext}")
    plt.xlabel('N')
    plt.ylabel('Tiempo (s)')
    # Escala lineal solicitada
    plt.grid(True)
    plt.legend()
    plt.tight_layout()

    out_img = os.path.join(results_dir, f"{name_no_ext}_graph.png")
    plt.savefig(out_img, dpi=300)
    print(f"Generated {out_img}")
    plt.close()

print("Plotting complete.")
