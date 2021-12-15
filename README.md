# mem_leaker

Emul  
memory leaks on c  
./lik  <>  
<-a> sawtoothed (neutral)  
<-b> serrated grow  
 
gcc: 
gcc -Wall -x c -static -o lik main.c -lpthread 
 
./ss.sh <$1> <$2>  
script to analyze memory usage  
<$1> name or pid  
<$2> the scanning delay time (in sec) of memory usage  
rasul:  
Program <prog_name> has/hasn't memory leak  
when there is a memory leak  
outputs the difference of the change parameters after the delay  

example:  
![til](./assets/GIF2.gif)  