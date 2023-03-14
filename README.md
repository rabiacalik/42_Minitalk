# 42_Minitalk
# BitWase
C dilindeki bitwisw operatörleri, verilen iki sayının bitlerinin tek tek işleme sokulmasıyla çalışan operatörlerdir. 

& (ve):
    iki bitin de 1 olması durumunda sonuç 1 olur
    0110
    1010    
    --------------> 0010

| (veya):
   en az bir bitin 1 olması durumunda sonuş 1 olur
   0110
   1010
   -------------> 1110

^ (xor):
   iki bit farklı olduğunda sonuç 1 olur
   0110
   1010
   -------------> 1100

~ (değil):
    bitlerin tersini çevirir
    0110
    ------------> 1001

<< (sola kaydırma)
   verilen sayının bitlerini belirtilen sayı kadar sola kaydırır
   0001 << 2 = 0100

>> (sağa kaydır)
   verilen sayının bitlerini belirtilen sayı kadar sağa kaydırır
   0100 >> 2 = 0001

bir sayının bit degerini hesaplama:
örneğin: 0010 1011 degeri için
128  64  32  16    8  4  2  1
0       0    1    0      1  0  1  1
    1 olanların değerleri toplanır 32+8+2+1= 43  

