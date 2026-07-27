"""Chapter 10 example: load, downsample, smooth, and plot sensor data.

Install dependencies first: pip install pandas matplotlib
"""
import pandas as pd
import matplotlib.pyplot as plt

# 1. Load Data
# We index the data by 'timestamp' to enable time-based operations
df = pd.read_csv('sensor_data.csv', parse_dates=['timestamp'], index_col='timestamp')

# 2. Resample (Downsampling)
# Convert high-frequency data into 1-hour averages to reduce volume
hourly_data = df.resample('1h').mean()

# 3. Rolling Mean (Smoothing)
# Calculate the average of the last 10 readings to remove noise spikes
df['smooth_temp'] = df['temperature'].rolling(window=10).mean()

# 4. Plotting
plt.plot(df.index, df['temperature'], label='Raw')
plt.plot(df.index, df['smooth_temp'], label='Smoothed')
plt.legend()
plt.show()
