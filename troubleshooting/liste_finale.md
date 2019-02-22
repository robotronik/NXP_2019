---
geometry: margin=2cm
header-includes:
	\usepackage{graphicx}
	\usepackage{fancyhdr}
	\pagestyle{fancy}
	\setlength\headheight{65pt}
	\fancyhead[L]{\includegraphics[scale=0.4]{logo_phelma.jpg}}
	\fancyhead[R]{\includegraphics[scale=0.35]{logoclub.jpg}}
---

# Troubleshooting documentation ROBOTRONIK-PHELMA

We wanted to elaborate a little more the problems we displayed in the mail. So we ordered this hardware documentation in different sections.


## The boards :
### FRDM-KL25Z :
* One of these boards doesn't work because of an unknown issue
* Furthermore, as we can illustrate in picture shown bellow, there are small tin projection. 
<!-- \includegraphics[scale=0.5]{tin.jpg} -->
* Finally, the female jumper connector casing is damaged on the corners (picture bellow).

### The middle control board (the one that control the servomotor) :
* Loose connections between the different board
* The switch aren't functional on two board (no control over the current state)
* One board suffer of a supply problem.

### Bottom card (the one for the motors and the power electronic) :
* The battery cable is either damaged or missing
* The pins for motors were missing in one kit
* As is was mentioned before, the switches are dysfunctional on some kits.

## Camera :
* Connection strip damaged in one kit
* A diode is missing on one camera and cause a inability to use it (cf. picture bellow)

## Motors & Servomotors :
### Motors :
* One motor is out of alignment
* On every kits, the connectors weren't included

### Servomotors :
* The connectors aren't adapted to the middle board

## Frame
* The ankle on the front left wheel is damaged (cf. photo bellow)
