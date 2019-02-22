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

Finally there are more problems than mentionned in the mail. They will be precised in the following document.

## The boards :
### The middle control board (the one that controls the servomotor) :
* Loose connections between the different boards.
* The switches are not functional on two boards (no control over On/Off state).
* One board suffers of a power supply problem, which means the power supply is connected but there is no feedback on the board (e.g. LED).

### Bottom card (the one for the motors and the power electronic) :
* The battery cable is either damaged or missing.
* The connectors for the motors were missing in one kit.
* As already mentioned, the switches are dysfunctional on two kits.

### FRDM-KL25Z :
* One of these boards does not work because of an unknown issue, neither connection to the power supply nor to a computer does work.
* There are small tin projection, as illustrated in the picture bellow. 
<!-- \includegraphics[scale=0.5]{tin.jpg} -->
* The female jumper casing is damaged on the corners (picture bellow).

## Camera :
* Connection strip damaged in one kit.
* A diode is missing on one camera and causes an inability to use it (cf. picture bellow).

## Motors & Servomotors :
### Motors :
* One motor is out of alignment.
* The connectors were not included in any kit.

### Servomotors :
* The connectors are not adapted to the middle board, which means the cables from the middle board touch the upper board and risk to be broken.

## Frame
* The ankle on the front left wheel is damaged (cf. photo bellow).
