#!/bin/bash
#Define colors
RESET='\e[0m'
BOLD='\e[1m'
UNDERLINE='\e[4m'

# Text colors
RED='\e[31m'
GREEN='\e[32m'
YELLOW='\e[33m'
BLUE='\e[34m'
MAGENTA='\e[35m'
CYAN='\e[36m'
WHITE='\e[37m'h
NC="\033[0m"  # No color (reset)

EXECUTABLE="./Cub3D"  # Path to executable

EXPECTED_EXIT_CODE=1
#Directory
INV_DIR="maps/invalid/"
VAL_DIR="maps/valid/"

ERRCOUNT=0
VALERRCOUNT=0

VALGRIND="valgrind --leak-check=full --error-exitcode=2"
# list of map files
VAL_INPUT_FILES=(
	"holes.cub"
	"map_1_valid.cub"
	"map_valid_newline_end.cub"
	"subject.cub"
	"whitespaces.cub"
	)

INV_INPUT_FILES=(
		"colors_arg_missing.cub"
		"empty.cub"
		"map_middle.cub"
		"player_missing.cub"
		"textures_no_permission.cub"
		"wall_hole_north.cub"
		"colors_missing.cub"
		"extension_none"
		"map_missing.cub"
		"textures_duplicate.cub"
		"textures_none.cub"
		"wall_hole_south.cub"
		"colors_none.cub"
		"extension_wrong.club"
		"player_duplicate.cub"
		"textures_invalid.cub"
		"textures_wrong_format.cub"
		"wall_hole_west.cub"
		"colors_wrong_RGB_range.cub"
		"map_invalid_newline.cub"
		"map_first.cub"
		"player_edge.cub"
		"textures_missing.cub"
		"wall_hole_east.cub"
		"wall_none.cub"
		".cub"
		"map_1_invalid.cub"
		"map_2_invalid.cub"
		"map_3_invalid.cub"
		"map_4_invalid.cub"
		"map_5_invalid.cub"
		"map_6_invalid.cub"
		"map_7_invalid.cub"
		"map_8_invalid.cub"
		"map_9_invalid.cub"
		"map_10_invalid.cub"
		"map_11_invalid.cub"
		"map_12_invalid.cub"
)

make
clear
                                                                                                                                                                                                                                                                 
echo ""
echo -e "${YELLOW}________/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\________/\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\___/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\____ ${RESET}"
echo -e "${YELLOW} _____/\\\\\\\\\////////__\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\/////////\\\\\\\\\___/\\\\\\\\\///////\\\\\\\\\_\\\/\\\\\\\\\////////\\\\\\\\\__ ${RESET}"
echo -e "${YELLOW}  ___/\\\\\\\\\/___________\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\_______\\\/\\\\\\\\\__\\\///______/\\\\\\\\\__\\\/\\\\\\\\\______\\\//\\\\\\\\\_ ${RESET}"
echo -e "${YELLOW}   __/\\\\\\\\\_____________\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__________/\\\\\\\\\//___\\\/\\\\\\\\\_______\\\/\\\\\\\\\_${RESET}"
echo -e "${YELLOW}    _\\\/\\\\\\\\\_____________\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\/////////\\\\\\\\\________\\\////\\\\\\\\\__\\\/\\\\\\\\\_______\\\/\\\\\\\\\_ ${RESET}"
echo -e "${YELLOW}     _\\\//\\\\\\\\\____________\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\_______\\\/\\\\\\\\\___________\\\//\\\\\\\\\_\\\/\\\\\\\\\_______\\\/\\\\\\\\\_ ${RESET}"
echo -e "${YELLOW}      __\\\///\\\\\\\\\__________\\\//\\\\\\\\\______/\\\\\\\\\__\\\/\\\\\\\\\_______\\\/\\\\\\\\\__/\\\\\\\\\______/\\\\\\\\\__\\\/\\\\\\\\\_______/\\\\\\\\\__ ${RESET}"
echo -e "${YELLOW}       ____\\\////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__\\\///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/__\\\///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___ ${RESET}"
echo -e "${YELLOW}        _______\\\/////////_____\\\/////////_____\\\/////////////______\\\/////////_____\\\////////////_____ ${RESET}"
echo ""

 #echo ""
 #echo -e "${MAGENTA}________/\\\\\\\\\__/\\\________/\\\__/\\\\\\\\\\\\\_______/\\\\\\\\\\___/\\\\\\\\\\\\____${RESET}"
 #echo -e "${MAGENTA} _____/\\\////////__\/\\\_______\/\\\_\/\\\/////////\\\___/\\\///////\\\_\/\\\////////\\\__${RESET}"
 #echo -e "${MAGENTA}  ___/\\\/___________\/\\\_______\/\\\_\/\\\_______\/\\\__\///______/\\\__\/\\\______\//\\\_${RESET}"
 #echo -e "${MAGENTA}   __/\\\_____________\/\\\_______\/\\\_\/\\\\\\\\\\\\\\__________/\\\//___\/\\\_______\/\\\_${RESET}"
 #echo -e "${MAGENTA}    _\/\\\_____________\/\\\_______\/\\\_\/\\\/////////\\\________\////\\\__\/\\\_______\/\\\_${RESET}"
 #echo -e "${MAGENTA}     _\//\\\____________\/\\\_______\/\\\_\/\\\_______\/\\\___________\//\\\_\/\\\_______\/\\\_${RESET}"
 #echo -e "${MAGENTA}      __\///\\\__________\//\\\______/\\\__\/\\\_______\/\\\__/\\\______/\\\__\/\\\_______/\\\__${RESET}"
 #echo -e "${MAGENTA}       ____\////\\\\\\\\\__\///\\\\\\\\\/___\/\\\\\\\\\\\\\/__\///\\\\\\\\\/___\/\\\\\\\\\\\\/___${RESET}"
 #echo -e "${MAGENTA}        _______\/////////_____\/////////_____\/////////////______\/////////_____\////////////_____${RESET}"
 #echo ""
 #echo -e "\t${YELLOW}INVALID MAPS\033[0m"
 #echo ""
for FILE in "${INV_INPUT_FILES[@]}"; do
    echo "Map: $FILE"
    $EXECUTABLE "$INV_DIR$FILE"
    EXIT_CODE=$?
    # Check the result and print a message
    if [ $EXIT_CODE -eq $EXPECTED_EXIT_CODE ]; then
		echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
		ERRCOUNT=$((ERRCOUNT + 1))
    fi
    $VALGRIND $EXECUTABLE "$INV_DIR$FILE" > valgrindout.txt 2>&1
    VEXIT_CODE=$?
    # Check the result and print a message
    if [ $VEXIT_CODE -eq 2 ]; then
        echo -e "${RED}MKO${NC}"
		cat valgrindout.txt
		VALERRCOUNT=$((VALERRCOUNT + 1))
    else
		echo -e "${GREEN}MOK${NC}"
    fi
	if  [ $VEXIT_CODE -eq 2 ] || [ $EXIT_CODE -ne $EXPECTED_EXIT_CODE ]; then
		echo $FILE >> kos 
	fi
	rm -f valgrindout.txt
    echo "---------------------------"
done

echo "---------------------------"
echo -e "${UNDERLINE}${MAGENTA}\tSummary:${NC}"
if [ $ERRCOUNT -eq 0 ]; then
    echo -e "${GREEN}No Errors${NC}"
else
	echo -e "${RED}$ERRCOUNT${NC} KO's"
fi
if [ $VALERRCOUNT -eq 0 ]; then
    echo -e "${GREEN}No memory leaks${NC}"
else
	echo -e "${RED}$VALERRCOUNT${NC} leak(s)"
fi
if [ $ERRCOUNT -ne 0 ] || [ $VALERRCOUNT -ne 0 ]; then
	echo -e "${UNDERLINE}${RED}\tKO'ed files:${NC}"
	cat kos 
fi
rm -f kos
echo "---------------------------"
echo "---------------------------"

while true; do
	read -p "Go to next test? (y/n): " answer
	if [ "$answer" == "y" ]; then
		break
	elif [ "$answer" == "n" ]; then
		exit 0
	else
		echo "Invalid input. Please enter 'y' or 'n'."
	fi
done


EXPECTED_EXIT_CODE=0
ERRCOUNT=0
VALERRCOUNT=0
clear
echo ""
echo -e "${GREEN}________/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\________/\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\___/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\____ ${RESET}"
echo -e "${GREEN} _____/\\\\\\\\\////////__\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\/////////\\\\\\\\\___/\\\\\\\\\///////\\\\\\\\\_\\\/\\\\\\\\\////////\\\\\\\\\__ ${RESET}"
echo -e "${GREEN}  ___/\\\\\\\\\/___________\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\_______\\\/\\\\\\\\\__\\\///______/\\\\\\\\\__\\\/\\\\\\\\\______\\\//\\\\\\\\\_ ${RESET}"
echo -e "${GREEN}   __/\\\\\\\\\_____________\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__________/\\\\\\\\\//___\\\/\\\\\\\\\_______\\\/\\\\\\\\\_${RESET}"
echo -e "${GREEN}    _\\\/\\\\\\\\\_____________\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\/////////\\\\\\\\\________\\\////\\\\\\\\\__\\\/\\\\\\\\\_______\\\/\\\\\\\\\_ ${RESET}"
echo -e "${GREEN}     _\\\//\\\\\\\\\____________\\\/\\\\\\\\\_______\\\/\\\\\\\\\_\\\/\\\\\\\\\_______\\\/\\\\\\\\\___________\\\//\\\\\\\\\_\\\/\\\\\\\\\_______\\\/\\\\\\\\\_ ${RESET}"
echo -e "${GREEN}      __\\\///\\\\\\\\\__________\\\//\\\\\\\\\______/\\\\\\\\\__\\\/\\\\\\\\\_______\\\/\\\\\\\\\__/\\\\\\\\\______/\\\\\\\\\__\\\/\\\\\\\\\_______/\\\\\\\\\__ ${RESET}"
echo -e "${GREEN}       ____\\\////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__\\\///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/__\\\///\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___ ${RESET}"
echo -e "${GREEN}        _______\\\/////////_____\\\/////////_____\\\/////////////______\\\/////////_____\\\////////////_____ ${RESET}"
echo ""
echo -e "\t${YELLOW}VALID MAPS\033[0m"
echo ""
for FILE in "${VAL_INPUT_FILES[@]}"; do
    echo "Map: $FILE"
    $EXECUTABLE "$VAL_DIR$FILE"
    EXIT_CODE=$?
    # Check the result and print a message
    if [ $EXIT_CODE -eq $EXPECTED_EXIT_CODE ]; then
		echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
		ERRCOUNT=$((ERRCOUNT + 1))
    fi
    $VALGRIND $EXECUTABLE "$VAL_DIR$FILE" > valgrindout.txt 2>&1
    VEXIT_CODE=$?
    # Check the result and print a message
    if [ $VEXIT_CODE -eq 2 ]; then
        echo -e "${RED}MKO${NC}"
		cat valgrindout.txt
		VALERRCOUNT=$((VALERRCOUNT + 1))
    else
		echo -e "${GREEN}MOK${NC}"
    fi
	if  [ $VEXIT_CODE -eq 2 ] || [ $EXIT_CODE -ne $EXPECTED_EXIT_CODE ]; then
		echo $FILE >> kos 
	fi
	rm -f valgrindout.txt
    echo "---------------------------"
done

echo "---------------------------"
echo -e "${UNDERLINE}${MAGENTA}\tSummary:${NC}"
if [ $ERRCOUNT -eq 0 ]; then
    echo -e "${GREEN}No Errors${NC}"
else
	echo -e "${RED}$ERRCOUNT${NC} KO's"
fi
if [ $VALERRCOUNT -eq 0 ]; then
    echo -e "${GREEN}No memory leaks${NC}"
else
	echo -e "${RED}$VALERRCOUNT${NC} leak(s)"
fi
if [ $ERRCOUNT -ne 0 ] || [ $VALERRCOUNT -ne 0 ]; then
	echo -e "${UNDERLINE}${RED}\tKO'ed files:${NC}"
	cat kos 
fi
rm -f kos
echo "---------------------------"
echo "---------------------------"
