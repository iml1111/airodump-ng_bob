#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>

#define PROBE_RESPONSE 0x50
#define PROBE_REQUEST 0x40
#define BEACON_FRAME 0x80
#define DATA_FRAME 0x08 //????

#define clear() printf("\033[H\033[J")

struct beacon {				

	char essid[256];
	u_int8_t eslen;
	u_int8_t bssid[6];
	u_int8_t pwr;
	int beacons;
	int data;
	u_int8_t channel;
	// Encryption?

} __attribute__((__packed__));

struct probe {	
	
	u_int8_t bssid[6];
	u_int8_t station[6];
	u_int8_t pwr;
	int frames;
	// Probe??
	
} __attribute__((__packed__));



struct ieee80211_radiotap_header {                      /*(24bytes)*/

        u_int8_t        version;     
        u_int8_t        pad;
        u_int16_t       len;       		  /* entire length */
        u_int32_t       present1;     
        u_int32_t       present2;    
        u_int8_t        flags;
        u_int8_t        data_rate;
        u_int16_t       ch;		/*channel freq*/
        u_int16_t 	ch_flags;
        u_int8_t 	signal;
        u_int8_t    reserved;
        u_int16_t 	rx_flags;
        u_int8_t 	signal2;
        u_int8_t 	antenna;

} __attribute__((__packed__));

struct ieee80211_header {	                      /*(24bytes)*/

	u_int8_t 	type;
                           u_int8_t       control;
	u_int16_t 	duration;
	u_int8_t 	mac1[6];		
	u_int8_t	mac2[6];		
	u_int8_t	mac3[6];
	u_int16_t 	fs_number;	

} __attribute__((__packed__));

struct tkip_parameters {		/*data frame only*/

	u_int8_t	 tkip[8];

} __attribute__((__packed__));

struct fixed_paprmeters {		/*probe response, beacon frame only  (12bytes)*/

	u_int8_t 	timestamp[8];
	u_int16_t	b_interval;
	u_int16_t	c_info;

} __attribute__((__packed__));
