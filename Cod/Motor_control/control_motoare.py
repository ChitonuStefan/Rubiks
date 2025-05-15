import RPi.GPIO as GPIO
import time

# Setare pini (BCM)
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

DIR = 21  # DIR comun (alege un GPIO liber)

steps_per_rev = 400
steps_for_90 = steps_per_rev // 4
viteza_microsec = 500
delay_intre_miscari = 0 # în secunde

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

# Dezactivează motoarele
for en in [EN_DOWN, EN_TOP, EN_LEFT, EN_FRONT, EN_RIGHT, EN_BACK]:
    GPIO.output(en, GPIO.HIGH)

# Funcție pentru rotire
def rotate_90(stepPin, enPin, direction):
    GPIO.output(enPin, GPIO.LOW)
    GPIO.output(DIR, direction)
    
    for _ in range(steps_for_90):
        GPIO.output(stepPin, GPIO.HIGH)
        time.sleep(viteza_microsec / 1_000_000.0)
        GPIO.output(stepPin, GPIO.LOW)
        time.sleep(viteza_microsec / 1_000_000.0)

    GPIO.output(enPin, GPIO.HIGH)


def comenzi():
    try:
        with open("/home/pit77olt/Desktop/Rubiks/Cod/Solution_Generator/solutie_gen.txt", "r") as f:
            solutie = f.read().strip()
    except FileNotFoundError:
        print("fisier solutie nu a fost gasit!")
        return

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


# Rulează programul
try:
    comenzi()
finally:
    GPIO.cleanup()
