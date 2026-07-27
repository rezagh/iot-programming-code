"""Generates a sample sensor_data.csv for the Chapter 10 analysis example.

Simulates 24 hours of temperature readings (one per minute) with a daily
cycle, sensor noise, and a few glitch spikes to clean up.
Uses only the Python standard library.
"""
import csv
import math
import random
from datetime import datetime, timedelta

random.seed(42)
start = datetime(2026, 1, 1)
n = 24 * 60  # one reading per minute for 24 hours
glitches = set(random.sample(range(n), 5))

rows = []
for i in range(n):
    t = start + timedelta(minutes=i)
    temp = 22 + 4 * math.sin(2 * math.pi * i / n) + random.gauss(0, 0.4)
    if i in glitches:
        temp += random.choice([-15, 15])  # sensor glitch / outlier
    rows.append((t.strftime("%Y-%m-%d %H:%M:%S"), round(temp, 2)))

with open("sensor_data.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["timestamp", "temperature"])
    writer.writerows(rows)

print(f"Wrote {len(rows)} rows to sensor_data.csv")
