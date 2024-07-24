echo " _____                    _  _                 ";
echo "/__   \ ___   _ __  __ _ | |(_) ____ ___  _ __ ";
echo "  / /\// _ \ | '__|/ _\` || || ||_  // _ \| '__|";
echo " / /  | (_) || |  | (_| || || | / /|  __/| |   ";
echo " \/    \___/ |_|   \__,_||_||_|/___|\___||_|   ";
echo "                                               ";
echo "Copyright (C) 2024, Debjeet Banerjee";
echo "                                               ";
chmod +x uninstall.sh
chmod +x update.sh
sleep .5
echo "[!] Preparing for installation"

if [ -f "/usr/bin/curl" ]; then
    echo ""
else
    echo "[!] Install curl using your package manager after installation"
    echo "[!] The update feature will not work if curl is not installed"
fi

sleep 1

if [ -d "~/.local/toralizer"  ];then
    cp VERSION ~/.local/toralizer
else
    mkdir ~/.local/toralizer
    cp VERSION ~/.local/toralizer
fi

sleep .5

make all

echo "creating ~/.toralizer"
mkdir ~/.toralizer

echo "creating uninstaller at ~/.toralizer"
cp uninstall.sh ~/.toralizer

for file in *; do
    if [ -f "$file" ]; then
        cp $file ~/.toralizer
        echo "[+] copying $file to ~/.toralizer"
        sleep .3
    elif [ -d "$file" ]; then
        cp -r $file ~/.toralizer
        echo "[+] copying ./$file to ~/.toralizer"
    else
        echo "[-] unexpected error caused while installation!"
        exit 1
    fi
done

sleep .75

if [ -f "/usr/bin/toralize" ]; then
    echo "toralize already present at /usr/bin"
    read -p "do you want to proceed with over-riding the file [Y/n]: " choice
    choice=${choice,,}
    if [[ $choice == "" || $choice == "y" || $choice == "yes" || $choice == "ye" ]]; then
        echo "pushing new over-ride code to toralize"
        sudo cp toralize /usr/bin/toralize
        sudo chmod +x /usr/bin/toralize

    elif [[ $choice == "n" || $choice == "no" ]]; then
        echo "Aborting over-ride ..."
        echo "You need to add manually in that case"
    else
        echo "invalid choice"
    fi
else
    echo "creating toralize at /usr/bin"
    sudo cp toralize /usr/bin/toralize
    sudo chmod +x /usr/bin/toralize
fi



sleep .75

echo ""
echo "installation completed"
echo "to uninstall, go to ~/.toralizer and run sudo uninstall.sh"
echo "follow me on https://www.github.com/mintRaven-05 for more projects"
