ll: airodump-ng_bob

airodump-ng_bob: airodump-ng_iml.c
	gcc -lpcap -o airodump-ng_bob airodump-ng_iml.c

clean:
	rm airodump-ng_bob
