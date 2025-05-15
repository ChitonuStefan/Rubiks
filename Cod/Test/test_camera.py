import cv2
import numpy as np


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
# Încarcă imaginea
img = cv2.imread('/home/pit77olt/Desktop/Rubiks/Poze/Poze_procesat/poza1.jpg')

frame_cla = aplica_clahe(img)
frame_clahe=boost_hsv(frame_cla)

# ROI: zona de interes (x, y, lățime, înălțime)
x, y, w, h = 750, 325, 200, 200
roi = frame_clahe[y:y+h, x:x+w]

# Conversie în HSV
hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)

# Interval HSV pentru galben (îl poți ajusta)
lower_red1=np.array([0, 100, 100])
upper_red1=np.array([3, 255, 255])
lower_red2=np.array([177, 20, 120])
upper_red2=np.array([180, 255, 255])
    
lower_yellow = np.array([25, 60, 60])
upper_yellow = np.array([40, 255, 255])

lower_orange= np.array([6, 80, 80])
upper_orange= np.array([20, 255, 255])

lower_white= np.array([0, 0, 90])
upper_white= np.array([180, 80, 255])

lower_green=np.array([40, 80, 45])
upper_green=np.array([85, 255, 255])

lower_blue=np.array([90, 80, 40])
upper_blue=np.array([130, 255, 255])

# Creează mască pentru x_culoare
mask1= cv2.inRange(hsv, lower_red1, upper_red1)
mask2= cv2.inRange(hsv, lower_red2, upper_red2)

mask3=cv2.inRange(hsv,lower_white,upper_white)
red_mask = cv2.bitwise_or(mask1, mask2)

numar_pixeli_rosu = cv2.countNonZero(mask3)

if numar_pixeli_rosu > 1000:
    print("✅ Zona conține rosu!")
else:
    print("Zona NU conține rosu.")

# (opțional) Arată ROI și mască
cv2.imshow('Zona', roi)
cv2.imshow('Masca verde', mask3)
cv2.waitKey(0)
cv2.destroyAllWindows()



