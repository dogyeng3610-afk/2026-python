# pip install pandas
# pip install matplotlib
# sudo apt-get update
# sudo apt-get install -y libxcb-xinerama0 libqt5gui5 libxcb-icccm4 libxcb-image0 libxcb-keysyms1 libxcb-randr0 libxcb-render-util0 libxcb-shape0 libxcb-xfixes0 libxkbcommon-x11-0


import pandas as pd
import matplotlib.pyplot as pit
from pathlib import Path

def main():
    csv_path = Path(r"/home/dog0/2026/2026-python/python_example/data")
    df = pd.read_csv(csv_path / "ta_20260527093808.csv")
    df.info()
    # pit.figure(figsize=(12,6))
    pit.plot(df['timestamp'], df['average'])
    pit.show()

if __name__ == "__main__":
    main()