import subprocess
import time
import os

# Căi către toate executabilele/scripturile
script_fotografiere = "/home/pit77olt/Desktop/Rubiks/Cod/Photo_taker/photo_taker.py"
script_procesare = "/home/pit77olt/Desktop/Rubiks/Cod/Initial_config_reader/config_reader.py"
cpp_executabil = "/home/pit77olt/Desktop/Rubiks/Cod/Solution_Generator/sol"
fisier_solutie = "/home/pit77olt/Desktop/Rubiks/Cod/Solution_Generator/solutie_gen.txt"
python_script_motoare = "/home/pit77olt/Desktop/Rubiks/Cod/Motor_control/control_motoare.py"

# --- PASUL 0: Capturez toate fetele ---
print("Capturez fetele cubului...")
subprocess.run(["python3", script_fotografiere])

# --- PASUL 0.5: Procesez pozele si generez configuratia ---
print("Procesare poze si formare configuratie initiala...")
subprocess.run(["python3", script_procesare])

# --- PASUL 1: Rulez generatorul de solutie ---
print("Rulez generatorul de solutie...")
result = subprocess.run(["./sol"], cwd="/home/pit77olt/Desktop/Rubiks/Cod/Solution_Generator")

# --- PASUL 2: Verific dacă fisierul de solutie a fost creat ---
if not os.path.exists(fisier_solutie):
    print("Eroare: solutie_gen.txt nu a fost generat!")
    exit()

print("Solutie generata")

# --- PASUL 3: Execut miscările motoarelor ---
print("Execut solutia pe motoare...")
subprocess.run(["python3", python_script_motoare])
 