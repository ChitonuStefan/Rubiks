import cv2
import numpy as np
import os


zone_de_interes = [
    (375, 625, 175, 175),
    (750, 325, 200, 200),
    (1300, 250, 250, 250),
    (1200, 900, 250, 250),
    (1250, 2100, 225, 225),
    (600, 2000, 250, 250),
    (350, 2000, 150, 150),
    (1700, 250, 350, 350),
    (2400, 400, 150, 150),
    (2700, 600, 75, 75),
    (1700, 1150, 200, 200),
    (1700, 2100, 350, 350),
    (2400, 2050, 150, 150),
    (2800, 2050, 150, 150)
]

intervale_culori = {
    'G': (np.array([40, 80, 60]), np.array([85, 255, 255])),   # Verde
    'R': [(np.array([0, 80, 45]), np.array([4, 255, 255])), (np.array([172, 80, 45]), np.array([180, 255, 255]))],  # Rosu
    'W': (np.array([0, 0, 80]), np.array([180, 80, 255])),    # Alb
    'Y': (np.array([25, 60, 60]), np.array([40, 255, 255])),   # Galben
    'O': (np.array([6, 80, 80]), np.array([20, 255, 255])),    # Portocaliu
    'B': (np.array([90, 80, 40]), np.array([130, 255, 255]))   # Albastru
}

mapare_poze = {
    0: {  # poza0
        0: 18, 1: 19, 2: 20, 3: 23, 4: 26, 5: 25, 6: 24, 7: 27, 8: 28, 9: 29, 10: 30, 11: 33, 12: 34, 13: 35
    },
    1: {  # poza1
        0: 36, 1: 37, 2: 38, 4: 44, 5: 43, 6: 42, 7: 45, 8: 46, 9: 47, 11: 51, 12: 52, 13: 53
    },
    2: {  # poza2
        4: 0, 5: 1, 6: 2, 7: 11, 10: 10
    },
    3: {  # poza3
        0: 8, 1: 7, 2: 6, 10: 12, 11: 15
    },
    4: {  # poza4
        12: 32, 8: 41, 10: 50
    },
    5: {  # poza5
        1: 21, 9: 9, 3: 5
    },
    6: {  # poza6
        1: 48, 3: 16, 9: 17
    },
    7: {  # poza7
        10: 14, 5: 39
    }
}

#Functie detectare culoare din roi ===
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
    prag_minim = 100
    if nr_pixeli[culoare_detectata] > prag_minim:
        return culoare_detectata
    else:
        return 'X'
    
def completeaza_culoare_lipsa(configurare):
    culori = {'W': 0, 'Y': 0, 'R': 0, 'G': 0, 'O': 0, 'B': 0}

    for litera in configurare:
        if litera in culori:
            culori[litera] += 1

    # Vedem ce culoare are mai puțin de 9 apariții
    culoare_lipsa = None
    for culoare, count in culori.items():
        if count < 9:
            culoare_lipsa = culoare
            break

    if culoare_lipsa is None:
        print("Nu există culoare lipsă sau configurare deja completă.")
        return configurare

    configurare_lista = list(configurare)
    for idx, val in enumerate(configurare_lista):
        if val == 'X':
            configurare_lista[idx] = culoare_lipsa
            break

    configurare_finala = ''.join(configurare_lista)
    return configurare_finala

def aplica_clahe(imagine_bgr):
    lab = cv2.cvtColor(imagine_bgr, cv2.COLOR_BGR2LAB)
    l, a, b = cv2.split(lab)
    clahe = cv2.createCLAHE(clipLimit=1.0, tileGridSize=(16, 16))
    l_clahe = clahe.apply(l)
    lab_clahe = cv2.merge((l_clahe, a, b))
    return cv2.cvtColor(lab_clahe, cv2.COLOR_LAB2BGR)

def boost_hsv(image, s_gain=1.2, v_gain=1.1):
    
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    h, s, v = cv2.split(hsv)

    s = np.clip(s.astype(np.float32) * s_gain, 0, 255).astype(np.uint8)
    v = np.clip(v.astype(np.float32) * v_gain, 0, 255).astype(np.uint8)

    hsv_boosted = cv2.merge([h, s, v])
    return cv2.cvtColor(hsv_boosted, cv2.COLOR_HSV2BGR)



# === MAIN ===
def main():
    configurare = ['X'] * 54

    # setare centre 
    configurare[4] = 'W'
    configurare[13] = 'Y'
    configurare[22] = 'R'
    configurare[31] = 'G'
    configurare[40] = 'O'
    configurare[49] = 'B'

    # Procere poze
    for idx_poză in range(8):  # 0...7
        poza_path = f"/home/pit77olt/Desktop/Rubiks/Poze/Poze_procesat/poza{idx_poză}.jpg"
        
        if not os.path.exists(poza_path):
            print(f"Eroare: poza {idx_poză} nu a fost gasita.")
            continue

        frame = cv2.imread(poza_path)
        frame_clahe = aplica_clahe(frame)
        frame_bun=boost_hsv(frame_clahe)
        if frame is None:
            print(f"Eroare: poza {idx_poză} nu a putut fi încărcată.")
            continue

        hsv = cv2.cvtColor(frame_clahe, cv2.COLOR_BGR2HSV)

        # Trecem prin zonele definite pentru poza curenta
        for roi_idx, configurare_idx in mapare_poze.get(idx_poză, {}).items():
            if roi_idx >= len(zone_de_interes):
                print(f"ROI index {roi_idx} invalid pentru poza {idx_poză}.")
                continue  # evitam crash

            x, y, w, h = zone_de_interes[roi_idx]

            roi = hsv[y:y+h, x:x+w]
            culoare_detectata = detecteaza_culoare_dupa_pixeli(roi)

            # Adaugam protecție la configurare
            if configurare_idx >= len(configurare):
                print(f"Configurare index {configurare_idx} invalid!")
                continue

            configurare[configurare_idx] = culoare_detectata

            #print(f"[Poza {idx_poză}] ROI {roi_idx} -> Configurare[{configurare_idx}] = {culoare_detectata}")

    configurare_completa=completeaza_culoare_lipsa(configurare)

    print(f"\n Configurare completa: {configurare_completa}")
    
    #salvare fisier text
    with open("/home/pit77olt/Desktop/Rubiks/Cod/Initial_config_reader/initial_config.txt", "w") as f:
        f.write(configurare_completa)

if __name__ == "__main__":
    main()
