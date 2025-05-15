import cv2
import numpy as np
import subprocess
import time
import os
import RPi.GPIO as GPIO

# === Setup Motoare ===

EN_DOWN = 18   # WHITE
EN_TOP = 23    # YELLOW
EN_LEFT = 24   # RED
EN_FRONT = 25  # GREEN
EN_RIGHT = 12  # ORANGE
EN_BACK = 16   # BLUE

STEP_DOWN = 4   # WHITE
STEP_TOP = 17   # YELLOW
STEP_LEFT = 27  # RED
STEP_FRONT = 22 # GREEN
STEP_RIGHT = 5  # ORANGE
STEP_BACK = 6   # BLUE

DIR = 21  # DIR comun

steps_per_rev = 400
steps_for_90 = steps_per_rev // 4
viteza_microsec = 500
delay_intre_miscari = 0  # în secunde

# Inițializare GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

all_pins = [
    EN_DOWN, EN_TOP, EN_LEFT, EN_FRONT, EN_RIGHT, EN_BACK,
    STEP_DOWN, STEP_TOP, STEP_LEFT, STEP_FRONT, STEP_RIGHT, STEP_BACK, DIR
]

for pin in all_pins:
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

# Dezactivează motoarele inițial
for en in [EN_DOWN, EN_TOP, EN_LEFT, EN_FRONT, EN_RIGHT, EN_BACK]:
    GPIO.output(en, GPIO.HIGH)

# === Functii pentru control ===

def rotate_90(stepPin, enPin, direction):
    GPIO.output(enPin, GPIO.LOW)
    GPIO.output(DIR, direction)
    
    for _ in range(steps_for_90):
        GPIO.output(stepPin, GPIO.HIGH)
        time.sleep(viteza_microsec / 1_000_000.0)
        GPIO.output(stepPin, GPIO.LOW)
        time.sleep(viteza_microsec / 1_000_000.0)

    GPIO.output(enPin, GPIO.HIGH)

def executa_miscari(solutie):
    for move in solutie:
        if move == 'R':
            rotate_90(STEP_RIGHT, EN_RIGHT, False)
        elif move == '6':
            rotate_90(STEP_RIGHT, EN_RIGHT, True)
        elif move == 'L':
            rotate_90(STEP_LEFT, EN_LEFT, False)
        elif move == '4':
            rotate_90(STEP_LEFT, EN_LEFT, True)
        elif move == 'U':
            rotate_90(STEP_TOP, EN_TOP, False)
        elif move == '8':
            rotate_90(STEP_TOP, EN_TOP, True)
        elif move == 'D':
            rotate_90(STEP_DOWN, EN_DOWN, False)
        elif move == '2':
            rotate_90(STEP_DOWN, EN_DOWN, True)
        elif move == 'F':
            rotate_90(STEP_FRONT, EN_FRONT, False)
        elif move == '5':
            rotate_90(STEP_FRONT, EN_FRONT, True)
        elif move == 'B':
            rotate_90(STEP_BACK, EN_BACK, False)
        elif move == '7':
            rotate_90(STEP_BACK, EN_BACK, True)
        
        time.sleep(delay_intre_miscari)

def captureaza_poza(nume_fisier):
    subprocess.run(["libcamera-still", "-o", nume_fisier, "-n", "-t", "1000"])
    time.sleep(1)  # Asigurăm salvarea completă

# === Planul de miscari===


miscari_intre_poze = [
    ("", ""),                 # poza1 -> nimic
    ("UU22", "DD88"),          # poza2
    ("8FL", "45U"),              # poza3
    ("7L", "4B"),              # poza4
    ("F6ULL", "448R5"),            # poza5
    ("2LF", "54D"),        # poza6
    ("L5B8", "U7F4"),              # poza7
    ("UU55L", "4FF88"),       # poza8
]

# === MAIN ===
def main():
    try:
        for idx, (miscare, revenire) in enumerate(miscari_intre_poze, start=0):
            nume_fisier = f"/home/pit77olt/Desktop/Rubiks/Poze/Poze_procesat/poza{idx}.jpg"
            
            

            if miscare:
                print(f"Executam miscari: {miscare}")
                executa_miscari(miscare)
            time.sleep(0.1) #pauza pt stabilizare
            print(f"Capturam {nume_fisier}...")
            captureaza_poza(nume_fisier)
            

            if revenire:
                print(f"Revenim cu miscari: {revenire}")
                executa_miscari(revenire)

            print(f"✅ Poza {idx} gata!\n")
            time.sleep(1)  # Mic delay intre etape

    finally:
        print("🧹 Curatam pinii GPIO...")
        GPIO.cleanup()

if __name__ == "__main__":
    main()
