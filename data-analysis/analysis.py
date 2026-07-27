"""Chapter 10 example: repair outliers, gaps, and noise, then downsample and plot.

Install dependencies first: pip install pandas matplotlib
"""
import pandas as pd
import matplotlib.pyplot as plt

# 1. Load Data
# We index the data by 'timestamp' to enable time-based operations
df = pd.read_csv('sensor_data.csv', parse_dates=['timestamp'], index_col='timestamp')

# 2. Remove Outliers
# Discard impossible readings (a room does not jump 10 degrees in one minute)
median = df['temperature'].median()
df.loc[(df['temperature'] - median).abs() > 10, 'temperature'] = None

# 3. Fill Missing Values (Imputation)
# Repair the gaps we just created (and any network dropouts) by interpolation
df['temperature'] = df['temperature'].interpolate()

# 4. Resample (Downsampling)
# Convert high-frequency data into 1-hour averages to reduce volume
hourly_data = df.resample('1h').mean()

# 5. Rolling Mean (Smoothing)
# Calculate the average of the last 10 readings to remove noise spikes
df['smooth_temp'] = df['temperature'].rolling(window=10).mean()

# 6. Plotting
plt.plot(df.index, df['temperature'], label='Raw')
plt.plot(df.index, df['smooth_temp'], label='Smoothed')
plt.legend()
plt.show()
