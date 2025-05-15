import cv2
import numpy as np

# ------------------------------
# Dictionar cu intervale HSV pentru toate cele 6 culori
intervale_culori = {
    'O': (np.array([10, 100, 100]),  np.array([20, 255, 255])),   # Portocaliu
    'W': (np.array([0, 0, 190]),     np.array([180, 50, 255])),   # Alb
    'Y': (np.array([20, 100, 100]),  np.array([40, 255, 255])),   # Galben
    'R1':(np.array([0, 100, 100]),   np.array([10, 255, 255])),   # Roșu (zona 1)
    'R2':(np.array([170, 100, 100]), np.array([180, 255, 255])),  # Roșu (zona 2)
    'G': (np.array([40, 100, 100]),  np.array([85, 255, 255])),   # Verde
    'B': (np.array([90, 100, 100]),  np.array([130, 255, 255]))  # Albastru
    
}

# ------------------------------
# Functie: proceseaza zonele și returnează secvența de caractere
def proceseaza_zone_cu_masti(img, zone_de_interes):
    hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    secventa = []

    for (x, y, w, h) in zone_de_interes:
        roi = hsv_img[y:y+h, x:x+w]
        litera = '?'

        # Verificăm fiecare culoare în ordine
        for culoare, (lower, upper) in intervale_culori.items():
            mask = cv2.inRange(roi, lower, upper)
            pixeli = cv2.countNonZero(mask)

            if pixeli > 0:
                if culoare == 'R1' or culoare == 'R2':
                    litera = 'R'
                else:
                    litera = culoare
                break  # am găsit o culoare, ieșim din buclă

        secventa.append(litera)

        # (opțional) desenăm pe imagine
        cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
        cv2.putText(img, litera, (x + 10, y + 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    return secventa

# ------------------------------
# Program principal
if __name__ == "__main__":
    img = cv2.imread('/home/pit77olt/Desktop/Rubiks/Poze/testrubik.jpg')  # schimbă cu poza ta

    # Zonele de interes predefinite (3x3 față Rubik)
    zone_de_interes = [
        (100, 100, 50, 50),
        (160, 100, 50, 50),
        (220, 100, 50, 50),
        (1850, 500, 200, 200),
        (2120, 570, 100, 100),
        (220, 160, 50, 50),
        (1830, 780, 120, 120),
        (2050, 780, 150, 150),
        (220, 220, 50, 50)
    ]

    rezultat = proceseaza_zone_cu_masti(img, zone_de_interes)


    print("Secventa detectata:", "".join(rezultat))

    cv2.waitKey(0)
    cv2.destroyAllWindows()
