import cv2
import numpy as np
import subprocess
import time
import os


zone_de_interes = [
    (375, 625, 175, 175),
    (700, 300, 250, 250),
    (1300, 250, 250, 250),
    (1200, 900, 250, 250),
    (1250, 2100, 225, 225),
    (600, 2000, 250, 250),
    (350, 2000, 150, 150),
    (1700, 250, 350, 350),
    (2400, 400, 150, 150),
    (2700, 600, 200, 200),
    (1700, 1150, 200, 200),
    (1700, 2100, 350, 350),
    (2450, 2050, 150, 150),
    (2800, 2050, 150, 150)
]

intervale_culori = {
    'G': (np.array([40, 80, 60]), np.array([85, 255, 255])),   # Verde
    'R': [(np.array([0, 80, 60]), np.array([4, 255, 255])), (np.array([177, 80, 60]), np.array([180, 255, 255]))],  # Rosu
    'W': (np.array([0, 0, 80]), np.array([180, 80, 255])),    # Alb
    'Y': (np.array([25, 60, 60]), np.array([40, 255, 255])),   # Galben
    'O': (np.array([6, 50, 70]), np.array([20, 255, 255])),    # Portocaliu
    'B': (np.array([90, 80, 80]), np.array([130, 255, 255]))   # Albastru
}

# === Functie pentru capturare poza cu libcamera-still ===
def captureaza_poza(destinatie):
    print("📸 Capturăm poza...")
    subprocess.run(["libcamera-still", "-o", destinatie, "-n", "-t", "1000"])
    time.sleep(0.5)  # Asigurare că poza e salvată

# === Functie pentru detectare culoare bazată pe pixeli ===
def detecteaza_culoare_dupa_pixeli(roi):
    nr_pixeli = {}

    for culoare, interval in intervale_culori.items():
        if culoare == 'R':
            # Pentru roșu (2 intervale)
            mask1 = cv2.inRange(roi, interval[0][0], interval[0][1])
            mask2 = cv2.inRange(roi, interval[1][0], interval[1][1])
            mask = cv2.bitwise_or(mask1, mask2)
        else:
            lower, upper = interval
            mask = cv2.inRange(roi, lower, upper)

        numar = cv2.countNonZero(mask)
        nr_pixeli[culoare] = numar

    # Alegem culoarea cu cei mai mulți pixeli
    culoare_detectata = max(nr_pixeli, key=nr_pixeli.get)

    prag_minim = 100  # Exemplu: minim 100 pixeli să fie validă culoarea

    if nr_pixeli[culoare_detectata] > prag_minim:
        return culoare_detectata
    else:
        return 'X'

# === MAIN ===
def main():
    poza_path = "/home/pit77olt/Desktop/Rubiks/Poze/Poze_procesat/poza1.jpg"

    # Capturează poza
    
    #captureaza_poza(poza_path)

    # Încarcă poza
    if not os.path.exists(poza_path):
        print("Eroare: poza nu a fost salvata corect.")
        return

    frame = cv2.imread(poza_path)
    if frame is None:
        print("Eroare: nu am putut încarca poza.")
        return

    # Conversie la HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Inițializează șir de culori
    sir_culori = ""

    # Parcurgem fiecare zonă de interes
    for (x, y, w, h) in zone_de_interes:
        roi = hsv[y:y+h, x:x+w]
        litera_culoare = detecteaza_culoare_dupa_pixeli(roi)
        sir_culori += litera_culoare

    # Afișăm rezultatul final
    print(f"🔠 Șirul de culori detectate: {sir_culori}")

if __name__ == "__main__":
    main()
