import cv2
import numpy as np

# Încarcă imaginea originală
image = cv2.imread("/home/pit77olt/Desktop/Rubiks/Poze/Poze_procesat/poza2.jpg")  # înlocuiește cu calea ta

# Funcție de redimensionare
def resize(img, width=640):
    h, w = img.shape[:2]
    ratio = width / w
    return cv2.resize(img, (width, int(h * ratio)))

def aplica_clahe(image):
    lab = cv2.cvtColor(image, cv2.COLOR_BGR2LAB)
    l, a, b = cv2.split(lab)
    clahe = cv2.createCLAHE(clipLimit=1.0, tileGridSize=(16, 16))
    cl = clahe.apply(l)
    lab_clahe = cv2.merge((cl, a, b))
    return cv2.cvtColor(lab_clahe, cv2.COLOR_LAB2BGR)

# ------------ VARIANTA 1: Originală redimensionată ------------
image_resized = resize(image)

# ------------ VARIANTA 2: CLAHE pe canalul L din LAB ------------
image_clahe=aplica_clahe(image)
# ------------ VARIANTA 3: CLAHE + HSV boost fără filtrare ------------
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
h, s, v = cv2.split(hsv)

# Creștere proporțională
s = np.clip(s.astype(np.float32) * 1.3, 0, 255).astype(np.uint8)
v = np.clip(v.astype(np.float32) * 1.2, 0, 255).astype(np.uint8)

# Recombinare și convertire înapoi în BGR
hsv_boosted = cv2.merge([h, s, v])
image_boosted = cv2.cvtColor(hsv_boosted, cv2.COLOR_HSV2BGR)
image_boosted_resized = resize(image_boosted)

# ------------ Afișare ------------
cv2.imshow("Original (redimensionat)", image_resized)
#cv2.imshow("Dupa CLAHE (LAB)", image_clahe_resized)
cv2.imshow("Dupa CLAHE + HSV Boost", image_boosted_resized)

cv2.waitKey(0)
cv2.destroyAllWindows()
