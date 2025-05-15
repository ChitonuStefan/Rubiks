import RPi.GPIO as GPIO
import time

# Pini
STEP_PIN = 4       # GPIO4 (PIN 7)
EN_PIN = 18        # GPIO18 (PIN 12)

# Parametri motor
STEPS_FOR_90 = 100             # pași pentru 90°
STEP_DELAY_MICROSEC = 500      # delay între pași (viteză)
PAUZA_SECUNDE = 3              # pauza între mișcări

# Configurare GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(STEP_PIN, GPIO.OUT)
GPIO.setup(EN_PIN, GPIO.OUT)

try:
    while True:
        print("Pornesc mișcarea de 90°...")

        GPIO.output(EN_PIN, GPIO.LOW)  # Activează motorul
        for _ in range(STEPS_FOR_90):
            GPIO.output(STEP_PIN, GPIO.HIGH)
            time.sleep(STEP_DELAY_MICROSEC / 1_000_000.0)
            GPIO.output(STEP_PIN, GPIO.LOW)
            time.sleep(STEP_DELAY_MICROSEC / 1_000_000.0)

        GPIO.output(EN_PIN, GPIO.HIGH)  # Dezactivează motorul
        print("Mișcare completă. Pauză 3 secunde.")
        time.sleep(PAUZA_SECUNDE)

except KeyboardInterrupt:
    print("Oprit manual.")

finally:
    GPIO.cleanup()
