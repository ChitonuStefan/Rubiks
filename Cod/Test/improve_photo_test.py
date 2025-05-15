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
    (2400, 2050, 150, 150),
    (2800, 2050, 150, 150)
]

intervale_culori = {
    'G': (np.array([40, 80, 60]), np.array([85, 255, 255])),   # Verde
    'R': [(np.array([0, 80, 60]), np.array([4, 255, 255])), (np.array([172, 80, 60]), np.array([180, 255, 255]))],  # Rosu
    'W': (np.array([0, 0, 80]), np.array([180, 80, 255])),    # Alb
    'Y': (np.array([25, 60, 60]), np.array([40, 255, 255])),   # Galben
    'O': (np.array([6, 80, 80]), np.array([20, 255, 255])),    # Portocaliu
    'B': (np.array([90, 80, 80]), np.array([130, 255, 255]))   # Albastru
}

def captureaza_poza(destinatie):
    print("📸 Capturăm poza...")
    subprocess.run(["libcamera-still", "-o", destinatie, "-n", "-t", "1000"])
    time.sleep(0.5)

def detecteaza_culoare_dupa_pixeli(roi):
    nr_pixeli = {}

    for culoare, interval in intervale_culori.items():
        if culoare == 'R':
            mask1 = cv2.inRange(roi, interval[0][0], interval[0][1])
            mask2 = cv2.inRange(roi, interval[1][0], interval[1][1])
            mask = cv2.bitwise_or(mask1, mask2)
        else:
            lower, upper = interval
            mask = cv2.inRange(roi, lower, upper)

        numar = cv2.countNonZero(mask)
        nr_pixeli[culoare] = numar

    culoare_detectata = max(nr_pixeli, key=nr_pixeli.get)
    return culoare_detectata if nr_pixeli[culoare_detectata] > 100 else 'X'

def aplica_clahe(imagine_bgr):
    lab = cv2.cvtColor(imagine_bgr, cv2.COLOR_BGR2LAB)
    l, a, b = cv2.split(lab)
    clahe = cv2.createCLAHE(clipLimit=1.0, tileGridSize=(16, 16))
    l_clahe = clahe.apply(l)
    lab_clahe = cv2.merge((l_clahe, a, b))
    return cv2.cvtColor(lab_clahe, cv2.COLOR_LAB2BGR)

def main():
    poza_path = "/home/pit77olt/Desktop/Rubiks/Poze/Poze_procesat/poza0.jpg"
    #captureaza_poza(poza_path)

    if not os.path.exists(poza_path):
        print("Eroare: poza nu a fost salvata corect.")
        return

    frame = cv2.imread(poza_path)
    if frame is None:
        print("Eroare: nu am putut încarca poza.")
        return

    # Aplică CLAHE pentru uniformizare iluminare
    frame_clahe = aplica_clahe(frame)

    # Conversie la HSV pentru detecția culorilor
    hsv = cv2.cvtColor(frame_clahe, cv2.COLOR_BGR2HSV)

    sir_culori = ""
    for (x, y, w, h) in zone_de_interes:
        roi = hsv[y:y+h, x:x+w]
        litera_culoare = detecteaza_culoare_dupa_pixeli(roi)
        sir_culori += litera_culoare

    print(f"🔠 Șirul de culori detectate: {sir_culori}")

if __name__ == "__main__":
    main()
