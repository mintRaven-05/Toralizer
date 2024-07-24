echo " _____                    _  _                 ";
echo "/__   \ ___   _ __  __ _ | |(_) ____ ___  _ __ ";
echo "  / /\// _ \ | '__|/ _\` || || ||_  // _ \| '__|";
echo " / /  | (_) || |  | (_| || || | / /|  __/| |   ";
echo " \/    \___/ |_|   \__,_||_||_|/___|\___||_|   ";
echo "                                               ";
echo "Copyright (C) 2024, Debjeet Banerjee";
echo "                                               ";

sleep .5

if [ -d "$HOME/.toralizer" ]; then
  echo "[-] removing  $HOME/.toralizer"
  rm -rf $HOME/.toralizer  
else
  echo "[!] could not locate ~/.toralizer"
fi

if [ -f "/usr/bin/toralize" ]; then
  echo "[-] removing /usr/bin/toralize"
  sudo rm /usr/bin/toralize
else
  echo "[!] could not locate /usr/bin/toralize"
fi

if [ -d "$HOME/.local/toralizer"  ]; then
  echo "[-] removing $HOME/.local/toralizer"
  rm -rf $HOME/.local/toralizer
else
  echo "[!] could not locate $HOME/.local/toralizer"
fi

sleep 1
echo ""
echo "Thank you for trying out Toralizer."
echo "If you have any suggestions or found out any bugs, you can report it"
echo "over the issues page."
echo "Visit & follow https://www.github.com/mintRaven-05/ for more projects."
