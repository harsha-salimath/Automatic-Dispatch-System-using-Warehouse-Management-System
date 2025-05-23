# Python Code to log RFID UID into CSV (dispatch_logger.py)
import serial
import csv
from datetime import datetime

PORT = 'COM4'  # Replace with your Arduino COM port
BAUDRATE = 9600
CSV_FILE = 'dispatch_log.csv'
    
# Initialize Serial Port
ser = serial.Serial(PORT, BAUDRATE, timeout=1)
# Create CSV file with headers if not exists
try:
    with open(CSV_FILE, 'x', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['Timestamp', 'RFID_UID', 'Status'])
except FileExistsError:
    pass
print("Listening for RFID data...")

while True:
    if ser.in_waiting:
        uid = ser.readline().decode('utf-8').strip()
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

        with open(CSV_FILE, 'a', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([timestamp, uid, 'Dispatched'])
        print(f"Dispatched: {uid} at {timestamp}")
