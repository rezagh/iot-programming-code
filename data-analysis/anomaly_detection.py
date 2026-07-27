"""Chapter 10 example: find anomalies with the mean + 3-sigma rule.

Run against the RAW sensor_data.csv (before outlier removal) to see it
pinpoint the glitch spikes planted in the dataset.
"""
import pandas as pd

df = pd.read_csv('sensor_data.csv', parse_dates=['timestamp'], index_col='timestamp')

mean = df['temperature'].mean()
std = df['temperature'].std()
print(df[(df['temperature'] - mean).abs() > 3 * std])
